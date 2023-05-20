/////////////////////Import zone

#include <SoftwareSerial.h>
#include <Arduino.h>
#include <LiquidCrystal.h> 


/////////////////////Variables zone
//Create software serial object to communicate with A6
SoftwareSerial mySerial(3, 2); //A6 Tx & Rx is connected to Arduino #3 & #2
const int pinInput = A0;
const int pinOut= 2;
const int tension=420;
int nrbatai=0;
bool val=false;
int data=0;
int timpAnt=0;


/////////////Setup











/////////////Loop











///////////////Functions


void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
