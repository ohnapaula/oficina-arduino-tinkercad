const int BOTAO = 2;
const int LED = 7;

void setup()
{
  pinMode(BOTAO, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop()
{
  int estado = digitalRead(BOTAO);
  digitalWrite(LED, estado == LOW ? HIGH : LOW);
}