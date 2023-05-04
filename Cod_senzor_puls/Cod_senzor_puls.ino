#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <Arduino.h>
#include <LiquidCrystal.h> 
int Contrast=75;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0

const int pinInput = A0;
const int pinOut= 2;
const int tension=420;
int nrbatai=0;
bool val=false;
int data=0;

int timpAnt=0;
void setup() {
  analogWrite(6,Contrast);
     lcd.begin(16, 2);

  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  Serial.begin(115200);//baud rate este de 115200
  pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);   
  data=analogRead(pinInput); // data ia valoarea(intre 0 si 500 cred) de la A0
  Serial.println(data);
  SendPulse(data);
  
}
//Functia care printeaza pulsul(va trebui sa punem valoarea la LCD)
void SendPulse(int data){
  static int nrtimp=0;
  nrtimp=millis();//nrtimp ia valoarea din millis
  if(tension>data && val==true){
    val=false;
    nrbatai++;
    //Serial.println(nrbatai);
    //Serial.println(nrtimp);
  }
  if((tension<=data && val==false)){
    val=true;
    nrbatai++;
  }
  if(nrtimp-timpAnt>=10000){//se verifica daca a trecut 1 secunda(trebuie sa punem pt 60 secunde cand nu testam)
    //calc nr batai=nrbatai/nr secunde
    lcd.println((float)(nrbatai)/10);
    Serial.println((float)(nrbatai)/10);
    timpAnt=nrtimp;
    nrbatai=0;
  }
  
}
