/////////////////////Import zone

#include <Arduino.h>
#include <LiquidCrystal.h> 


/////////////////////Variables zone
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int pinInput = A0;
const int pinOut= A2;
const int tension=420;//Jumatate din intervalul de valori posibile de la senzor [290,550]
int nrbatai=0;
bool val=false;
int data=0;
int timpAnt=0;
bool possibleDanger=0;
bool warning=0;

/////////////Setup

void setup() {
    lcd.begin(16, 2);
    pinMode(A0,INPUT);
    Serial.begin(115200);//baud rate este de 115200
    pinMode(pinOut,OUTPUT);//Folosim pinul A2 pentru a transmite la Uno inceperea transmiterii mesajului prin GSM 

}

/////////////Loop
void loop() {
  if(!warning){
  lcd.setCursor(0, 0);   
  data=analogRead(pinInput); // data ia valoarea(intre 280 si 560) de la A0
  //Serial.println(data);//Asa aflam valorile venite de la senzor
  SendPulse(data);
  }
  else{
    analogWrite(2,255);//8 biti
  }
}
///////////////Functions
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
  if(nrtimp-timpAnt>=1000){//se verifica daca a trecut 1 secunda(senzorul aproximeaza automat 60 batai intr-o secunda)
    //calc nr batai=nrbatai/nr secunde
    lcd.println((float)(nrbatai));
    if(nrbatai>190 || nrbatai<40)
      possibleDanger++;
    if(possibleDanger)
      warning++;
    //Serial.println((float)(nrbatai));//Testare
    timpAnt=nrtimp;
    nrbatai=0;
  }
}
