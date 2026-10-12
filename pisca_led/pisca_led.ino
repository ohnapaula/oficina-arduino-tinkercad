/*
 * Projeto: Pisca LED
 * Oficina: Arduino + Tinkercad
 * Descrição: Alterna o estado do LED digital a cada 1000ms.
 */

// Definição dos pinos
const int LED = 7;

void setup()
{
  pinMode(LED, OUTPUT);   // Configura o pino do LED como saída
}

void loop()
{
  digitalWrite(LED, HIGH); // Liga o LED
  delay(1000);             // Aguarda 1 segundo
  digitalWrite(LED, LOW);  // Desliga o LED
  delay(1000);             // Aguarda 1 segundo
}