#include <SoftwareSerial_Class.h> //Import this from https://github.com/MakersTeam/Galileo/tree/master/Arduino-Examples/SoftwareSerial
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  // put your setup code here, to run once:
  // set up the LCD's number of columns and rows:

  lcd.begin(16, 2);

  // Print a message to the LCD.

  lcd.print("hello, world!");
  
//Not sure we need what's below
  
  
  
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);

  Serial.println("Initializing...");
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 1);

  updateSerial();


  delay(20);                    // considered best practice in a simple sketch.

}

void updateSerial()
{
  //Here we may need lcd in place of Serial
    Serial.println("♥  A HeartBeat Happened ! ");
  delay(500);


  
}
