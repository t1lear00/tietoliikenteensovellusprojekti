#include "messaging.h"
#include "accelerator.h"
#include <arduino.h>



Messaging::Messaging()
{
  Serial.println("messaging created!");
  pmanager = new RHReliableDatagram(driver, TRANSMITTER_ADDRESS);
 
  if (!pmanager->init())
    Serial.println("Radiohead manager init failed");

}

Messaging::~Messaging()
{
  Serial.println("Messaging deleted!");
  delete pmanager;
}
void Messaging::createMessage(Measurement m)
{
  
   messageLength = 6;
   short x = m.x;
   short y = m.y;
   short z = m.z;
  data[0] = x >> 8;
  data[1] = x & 255;
  data[2] = y >> 8;
  data[3] = y & 255;
  data[4] = z >>8;
  data[5] = z & 255;
  

}
bool Messaging::sendMessage(uint8_t id, uint8_t flags)
{
     unsigned long start = millis(); 
     unsigned long timeout = millis()-start;
     while(timeout<500)
     {
      timeout = millis()-start; 
     }
     driver.setModeTx();
     uint8_t to = 254; //Receiver_ADDRESS
     uint8_t from = 62 ;//TRANSMITTER_ADDRESS
     
     pmanager->setHeaderTo(to);
     pmanager->setHeaderFrom(from);
     pmanager->setHeaderId(id);
     pmanager->setHeaderFlags(flags);
     
     bool returnValue = false;
  
     if (pmanager->sendto(data, messageLength, RECEIVER_ADDRESS))
     {
        returnValue = true;
     }
     pmanager->waitPacketSent();   
     return returnValue;

}
bool Messaging::receiveACK()
{
    driver.setModeRx();
    unsigned long start = millis(); 
    unsigned long timeout = millis()-start;
    bool receiverResult = false;
    uint8_t to;
    uint8_t from;
    uint8_t len;
    uint8_t id;
    uint8_t flags;
    while((timeout<1500) && (!pmanager->available()))
    {
      timeout = millis()-start;       
    }

    // Jos while luupista päästään, niin on saatu ACK tai on kulunut 1s
    receiverResult = pmanager->recvfrom(buf,&len,&from,&to,&id,&flags);
    if(receiverResult)
    {
      Serial.println("ACK received");
      Serial.println((char *)buf);
      Serial.print("Lähetettiin osoitteesta = ");
      Serial.println(from);
      Serial.print("ID = ");
      Serial.println(id);
      Serial.print("flags = ");
      Serial.println(flags);
      return true;
    }
    else
    {
      Serial.println("ACK not received, retransmit");
      return false;
    }

}
