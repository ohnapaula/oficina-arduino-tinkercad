// Estação Meteorológica
// Autor(a): Ana Paula Pereira Silva

const int PINO_TEMPERATURA = A0;
const int PINO_UMIDADE = A1;
const int PINO_PRESSAO = A2;
const int PINO_AR = A3;
const int PINO_CHUVA_ANALOGICA = A4;
const int PINO_LDR = A5;
const int PINO_CHUVA_DIGITAL = 2;
const int PINO_LED_ALERTA = 8;
const int PINO_BUZZER = 9;

const float TENSAO_REFERENCIA = 5.0;
const float LIMIAR_TEMPERATURA_C = 35.0;
const int LIMIAR_INDICE_AR = 70;
const unsigned long INTERVALO_ENTRE_BIPS_MS = 700;
const unsigned int FREQUENCIA_BIP_HZ = 1200;
const unsigned long DURACAO_BIP_MS = 180;
const unsigned long INTERVALO_SERIAL_MS = 1000;

unsigned long ultimoBip = 0;
unsigned long ultimaImpressao = 0;

void atualizarBuzzer(bool alarmeAtivo);
void exibirDados(float temperaturaC, int umidade, int pressao, 
                 int indiceAr, int sinalChuvaAnalogicoADC, bool chuvaDetectada, 
                 int leituraLuzADC, bool alertaTemperatura, bool alertaAr);

void setup() {
  pinMode(PINO_CHUVA_DIGITAL, INPUT_PULLUP);
  pinMode(PINO_LED_ALERTA, OUTPUT);
  pinMode(PINO_BUZZER, OUTPUT);
  
  digitalWrite(PINO_LED_ALERTA, LOW);
  noTone(PINO_BUZZER);
  
  Serial.begin(9600);
  Serial.println("Estacao meteorologica iniciada.");
}

void loop() {
  // 1. Leitura dos sensores
  int adcTemperatura = analogRead(PINO_TEMPERATURA);
  int adcUmidade     = analogRead(PINO_UMIDADE);
  int adcPressao     = analogRead(PINO_PRESSAO);
  int adcAr          = analogRead(PINO_AR);
  int adcChuva       = analogRead(PINO_CHUVA_ANALOGICA);
  int adcLuz         = analogRead(PINO_LDR);
  bool chuvaDetectada = (digitalRead(PINO_CHUVA_DIGITAL) == LOW);

  // 2. Conversão da temperatura (Sensor TMP36: 500 mV a 0 °C, 10 mV/°C)
  float tensaoTemperatura = adcTemperatura * (TENSAO_REFERENCIA / 1023.0);
  float temperaturaC = (tensaoTemperatura - 0.5) * 100.0;

  // 3. Conversão de escalas dos sensores
  int umidade = map(adcUmidade, 0, 1023, 0, 100);
  int pressao = map(adcPressao, 0, 1023, 900, 1050);
  int indiceAr = map(adcAr, 0, 1023, 0, 100);
  int sinalChuvaAnalogicoADC = adcChuva;

  // 4. Avaliação das condições de alerta
  bool alertaTemperatura = (temperaturaC >= LIMIAR_TEMPERATURA_C);
  bool alertaAr = (indiceAr >= LIMIAR_INDICE_AR);
  bool alarmeAtivo = chuvaDetectada || alertaTemperatura || alertaAr;

  // 5. Acionamento dos alarmes visual e sonoro
  digitalWrite(PINO_LED_ALERTA, alarmeAtivo ? HIGH : LOW);
  atualizarBuzzer(alarmeAtivo);

  // 6. Transmissão de dados via comunicação Serial (1s)
  unsigned long agora = millis();
  if (agora - ultimaImpressao > INTERVALO_SERIAL_MS) {
    ultimaImpressao = agora;
    exibirDados(temperaturaC,
                umidade,
                pressao,
                indiceAr,
                sinalChuvaAnalogicoADC,
                chuvaDetectada,
                adcLuz,
                alertaTemperatura,
                alertaAr);
  }
}

void atualizarBuzzer(bool alarmeAtivo) {
  if (!alarmeAtivo) {
    noTone(PINO_BUZZER);
    ultimoBip = millis();
    return;
  }
  
  unsigned long agora = millis();
  if (agora - ultimoBip > INTERVALO_ENTRE_BIPS_MS) {
    tone(PINO_BUZZER, FREQUENCIA_BIP_HZ, DURACAO_BIP_MS);
    ultimoBip = agora;
  }
}

void exibirDados(float temperaturaC,
                 int umidade,
                 int pressao,
                 int indiceAr,
                 int sinalChuvaAnalogicoADC,
                 bool chuvaDetectada,
                 int leituraLuzADC,
                 bool alertaTemperatura,
                 bool alertaAr) {
  Serial.println("----------------------------------------");
  Serial.print("Temperatura: ");
  Serial.print(temperaturaC, 1);
  Serial.println(" C");

  Serial.print("Umidade Relativa: ");
  Serial.print(umidade);
  Serial.println(" %");

  Serial.print("Pressao Atmosferica: ");
  Serial.print(pressao);
  Serial.println(" hPa");

  Serial.print("Indice de Qualidade do Ar: ");
  Serial.print(indiceAr);
  Serial.println(" / 100");

  Serial.print("Sinal Analogico de Chuva (ADC): ");
  Serial.println(sinalChuvaAnalogicoADC);

  Serial.print("Chuva Detectada: ");
  Serial.println(chuvaDetectada ? "SIM" : "NAO");

  Serial.print("Luminosidade (ADC): ");
  Serial.println(leituraLuzADC);

  Serial.print("Motivo(s) do alerta: ");
  bool algumMotivo = false;
  if (chuvaDetectada) {
    Serial.print("CHUVA detectada; ");
    algumMotivo = true;
  }
  if (alertaTemperatura) {
    Serial.print("TEMPERATURA elevada; ");
    algumMotivo = true;
  }
  if (alertaAr) {
    Serial.print("QUALIDADE DO AR critica; ");
    algumMotivo = true;
  }
  if (!algumMotivo) {
    Serial.print("nenhum");
  }
  Serial.println();
}