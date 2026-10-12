void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int leitura = analogRead(A0);
  Serial.print("Leitura: ");
  Serial.print(leitura);
  Serial.println();
  delay(300);
}