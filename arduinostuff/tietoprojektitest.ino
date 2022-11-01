/*
Tulosta numeroita ikiloopissa sarjaporttiin
*/
void setup()
{
  Serial.begin(9600); // sarjaportin nopeus
}

int number = 0;

void loop()
{
  Serial.print("Numero on ");
  Serial.println(number);    // tulosta numero

  delay(500); // 0.5 s viive
  number++; 
}
