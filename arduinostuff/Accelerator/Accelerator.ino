/*
  Tulosta Kiihtyvyys anturin raaka dataa serial plotterille
*/
#include "messaging.h"
#include "accelerator.h"

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


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //sensori pinnit
  pinMode(vccpin, OUTPUT);
  pinMode(GNDpin, OUTPUT);
  //jännite 5v ja gnd 0v
  digitalWrite(vccpin, HIGH);
  delayMicroseconds(2);
  digitalWrite(GNDpin, LOW);
  delayMicroseconds(2);
  Serial.println("give number of measurements: ");
 
}

void loop() {
Accelerator Aobject;
Messaging Mobject;

 int  nom = 0;
 while(nom <= 0)
 {
  if(Serial.available()>0)
  {
   nom = Serial.parseInt();
  }
 }
 for (int i = 0; nom>i; i++){
  
  Aobject.makeMeasurement();
  Measurement m = Aobject.getMeasurement();
  uint8_t id = i;
  uint8_t flags = 0xff;
  Mobject.createMessage(m);
  if(Mobject.sendMessage(5,flags)) //id,flags
  {
    Serial.println("transmit ok");
  }
  else
  {
    Serial.println("transmit niet problem normal katastrof");
  }
  if(Mobject.receiveACK())
  {
    Serial.println("Receiver got message");
  }
  else
  {
    Serial.println("receiver did not get message");
    i--;
  }
  Serial.print(m.x);
  Serial.print(" ");
  Serial.print(m.y);
  Serial.print(" ");
  Serial.println(m.z);
  delay(200);
 }

  
}
