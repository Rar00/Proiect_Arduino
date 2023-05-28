#include <Arduino.h>
#include <LiquidCrystal.h> 

/////////////////////Variables zone
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

static int nrtimp=0;
const int pinInput = A0;
const int pinOut= A2;
const int tension=520;//Jumatate din intervalul de valori posibile de la senzor [290,550]
int nrbatai=0;
bool val=false;
int data=0;
int timpAnt=0;
static int possibleDanger=0;
bool warning=0;
static int contorTimp = 0;

/////////////Setup

void setup() {
    lcd.begin(16, 2);
    pinMode(7,OUTPUT);//led albastru
    pinMode(8,OUTPUT);//led rosu
    pinMode(A0,INPUT);
    digitalWrite(7,HIGH);//led albastru
    digitalWrite(8,LOW);//led rosu
    Serial.begin(9600);//baud rate este de 115200
    pinMode(pinOut,OUTPUT);//Folosim pinul A2 pentru a transmite la Uno inceperea transmiterii mesajului prin GSM 
}

/////////////Loop
void loop() {
  if(!warning){
  digitalWrite(7,HIGH);//led albastru
  digitalWrite(8,LOW);//led rosu
  lcd.setCursor(0, 0);   
  data=analogRead(pinInput); // data ia valoarea(intre 280 si 560) de la A0
  Serial.println(data);//Asa aflam valorile venite de la senzor
  SendPulse(data);
  lcd.setCursor(8, 0);
  lcd.print("bpm");
  }
  else{
    analogWrite(pinOut,255);//8 biti
    digitalWrite(7,LOW);//led albastru
    digitalWrite(8,HIGH);//led rosu
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Warning!");
    delay(3000);
    lcd.clear();
    delay(1000);
    warning=0;
    contorTimp = 0;
  }
}

///////////////Functions
//Functia care printeaza pulsul(va trebui sa punem valoarea la LCD)
void SendPulse(int data){
  nrtimp=millis();//nrtimp ia valoarea din millis
  if(tension>data && val==true && data>514){
    val=false;
    nrbatai++;
  }
  if((tension<=data && val==false)){
    val=true;
  }
  if(nrtimp-timpAnt>=5000){//se verifica daca a trecut 1 secunda(senzorul aproximeaza automat 60 batai intr-o secunda)
    //calc nr batai=(nrbatai/2.9) am calibrat folosind un ceas inteligent
    // eroare maxima de 11%
    
    lcd.print((float)(nrbatai)*12);
    
    lcd.setCursor(0,1);
    contorTimp++;
    lcd.print("t="); 
    lcd.print(contorTimp*5);
    lcd.print("sec");
    lcd.setCursor(13,1);
    lcd.print("->");
    lcd.setCursor(15,1);
    
    if((nrbatai*12)>150 || (nrbatai*12)<40){
      possibleDanger++;
      lcd.print(possibleDanger);
      }
     else{
      possibleDanger = 0;
      lcd.print(possibleDanger);
      }
    if(possibleDanger==3){
      delay(1500);
      possibleDanger = 0;
      warning=1;
      contorTimp = 0;
      }

    timpAnt=nrtimp;
    nrbatai=0;
  }
}
