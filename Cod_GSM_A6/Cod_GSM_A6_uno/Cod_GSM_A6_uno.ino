//Once the wiring is completed, you can start programming.
//
//
//How  to work with AT commands.?


//#include <SoftwareSerial.h> 
//
//SoftwareSerial  A6MODULE(2,3);
//
//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(9600);
//delay(1000);
//  A6MODULE.begin(9600);
//delay(1000);
//}
//
//void  loop() {
// 
// while(A6MODULE.available()){
//  Serial.write(A6MODULE.read());
//  }
//
//  
// while(Serial.available()){
//  A6MODULE.write(Serial.read());
//  }
//
//}
//
//After Uploading codes, run the serial monitor.
//
//Now type  AT and press enter. If all the things are in order, Serial monitor will say “OK”
//
//HOW  TO CALL?
//ATD command is used for dial a phone call.
//
//Eg: Type ATD+123456789  then enter (your phone number)  ATD+40729364858
//
// HOW TO SEND SMS?
//Type AT+CMGF = 1  then  enter “ Answer should be OK”
//
//Then Type AT+CMGS = “+123456786” then enter  (your phone number) 
//
//AT+CMGF = 1
//AT+CMGS ="+40729364858"
//
#include <SoftwareSerial.h>

//Create software serial object to communicate with A6
SoftwareSerial mySerial(3, 2); //A6 Tx & Rx is connected to Arduino #3 & #2

void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  //Begin serial communication with Arduino and A6
  mySerial.begin(9600);
  
  Serial.println("shark");
  Serial.println("Initializing..."); 
  delay(1000);
  
  Serial.println("e ok");
  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  mySerial.println("AT+CSQ"); //Signal quality test, value range is 0-31 , 31 is the best
  updateSerial();
  mySerial.println("AT+CCID"); //Read SIM information to confirm whether the SIM is plugged
  updateSerial();
  mySerial.println("AT+CREG?"); //Check whether it has registered in the network
  updateSerial();
//  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
//  updateSerial();
//  mySerial.println("AT+CMGS=\"+40729364858\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
//  updateSerial();
//  mySerial.print("Last Minute Engineers | lastminuteengineers.com"); //text content
//  updateSerial();
//  mySerial.write(26);
//mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
//  updateSerial();
//  mySerial.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
//  updateSerial();
  
}

void loop()
{
}

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
