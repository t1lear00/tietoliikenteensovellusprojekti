/*
Tulosta Kiihtyvyys anturin raaka dataa serial plotterille
*/
const int vccpin = A0;
const int xpin = A1;
const int ypin = A2;
const int zpin = A3;
const int GNDpin = A4;
//alustetaan muutujat
int x = 0;
int y = 0;
int z = 0;
int numberOfMeasurements = 0;


void setup()
{
  Serial.begin(9600); // sarjaportin nopeus
  //sensori pinnit
  pinMode(vccpin, OUTPUT);
  pinMode(GNDpin, OUTPUT);
  //jännite 5v ja gnd 0v
   digitalWrite(vccpin, HIGH);
   delayMicroseconds(2); 
   digitalWrite(GNDpin, LOW); 
   delayMicroseconds(2);
}

int number = 0;

void loop()
{
  
  
  numberOfMeasurements = Serial.parseInt();
  for(int i = 0; i < numberOfMeasurements; i++) //
  {
    x = analogRead(xpin);  // sensori arvot 0-1023
    y = analogRead(ypin);
    z = analogRead(zpin);
    Serial.println("X, Y, Z  ");
    Serial.print(x);
    Serial.print(" "); 
    Serial.print(y);
    Serial.print(" ");    
    Serial.println(z);
    delay(200);
  }

 /* x = x;
  y = y;
  z = z; 
  Serial.println("X, Y, Z  ");
  Serial.print(x);
  Serial.print(" "); 
  Serial.print(y);
  Serial.print(" ");    
  Serial.println(z);
     

  delay(1000);  */
  
}
