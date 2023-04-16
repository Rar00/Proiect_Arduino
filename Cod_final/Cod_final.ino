#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <Arduino.h>

#include <SoftwareSerial_Class.h> //Import this from https://github.com/MakersTeam/Galileo/tree/master/Arduino-Examples/SoftwareSerial
#include <LiquidCrystal.h>


////////////////////////////////
//Create software serial object to communicate with A6
//To change the numbers below!!!!!!!!!!!!!!!!!!!!!!!!
SoftwareSerial mySerial(1, 0); //A6 Tx & Rx is connected to Arduino #1 & #0




//////////////////////////
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


////////////////////
//Variables
const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int pinInput = A0;
const int pinOut= 2;
const int tension=400;
int nrbatai=0;
bool val=false;
int data=0;

int timpAnt=0;


void setup()
{
  // set up the LCD's number of columns and rows:

  lcd.begin(16, 2);

  // Print a message to the LCD.

  lcd.print("hello, world!");
  delay(10000);
  //Begin serial communication with Arduino and A6
  mySerial.begin(115200);//115200 or 9600?

  // put your setup code here, to run once:
  pinMode(A0,INPUT);
//  Serial.begin(115200);//baud rate este de 115200
  pinMode(2,OUTPUT);

  
}

void loop()
{
  // set the cursor to column 0, line 1

  // (note: line 1 is the second row, since counting begins with 0):

  lcd.setCursor(0, 1);

  data=analogRead(pinInput); // data ia valoarea(intre 0 si 500 cred) de la A0
  SendPulse(data);
  
  delay(20);                    // considered best practice in a simple sketch.

}

void SendPulse(int data){
  static int nrtimp=0;
  nrtimp=millis();//nrtimp ia valoarea din millis
  if((tension<data && val==false)||(tension>=data && val==true)){
    val=~val;
    nrbatai++;
    //Serial.println(nrbatai);
    //Serial.println(nrtimp);
  }
  if(nrtimp-timpAnt>=60000){//se verifica daca au trecut 60 secunde(trebuie sa punem pt 1 secunde cand testam)
    lcd.print("Urgenta!!!");
    if(nrbatai<40 || nrbatai>100){
      mySerial.println("AT"); //Once the handshake test is successful, i t will back to OK
      mySerial.println("ATD+ZZxxxxxxxxxx"); //  change ZZ with country code and xxxxxxxxxxx with phone number to dial
      delay(20000); // wait for 20 seconds...
      mySerial.println("ATH"); //hang up
    }
    timpAnt=nrtimp;
    nrbatai=0;
  }
}
