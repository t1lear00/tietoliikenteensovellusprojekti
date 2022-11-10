#include "accelerator.h"
#include <arduino.h>

const int xpin = A1;
const int ypin = A2;
const int zpin = A3;

Accelerator::Accelerator()
{
   //Serial.println("Accelerator created!");
}


Accelerator::~Accelerator()
{
   //Serial.println("Accelerator deleted!");
}

void Accelerator::makeMeasurement()
{
  //Serial.print("give nom: ");  

  
    m.x = analogRead(xpin);  // sensori arvot 0-1023
    m.y = analogRead(ypin);
    m.z = analogRead(zpin);
  
    
  

}
Measurement Accelerator::getMeasurement()
{
 return m;
}

void Accelerator::printMeasurement()
{
  Serial.print(m.x);
  Serial.print(" ");
  Serial.print(m.y);
  Serial.print(" ");
  Serial.println(m.z);
}
