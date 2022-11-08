#include "accelerator.h"
#include <arduino.h>

Accelerator::Accelerator()
{
   Serial.println("Accelerator created!");
}


Accelerator::~Accelerator()
{
   Serial.println("Accelerator deleted!");
}

void Accelerator::makeMeasurement()
{
 nom = Serial.parseInt();
 for(int i = 0; i < nom; i++) //number of meaasurements
  {
    m.x = analogRead(xpin);  // sensori arvot 0-1023
    m.y = analogRead(ypin);
    m.z = analogRead(zpin);
    Serial.println(" xpin", m.x)
  } 
}
Measurement Accelerator::getMeasurement()
{
 return m
}
