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
//  mySerial.println("AT");//Once the handshake test is successful, it will back to OK
//  updateSerial();
//  delay(1000);
//  mySerial.println("AT+QRST=1");
//  updateSerial();
//  delay(1000);
    mySerial.println("AT+CFUN=1.1");
    updateSerial();
//  mySerial.println("AT+QBAND=7");
//  updateSerial();
//  delay(1000);
//  mySerial.println("AT+CSQ"); //Signal quality test, value range is 0-31 , 31 is the best
//  updateSerial();
//  mySerial.println("AT+CCID"); //Read SIM information to confirm whether the SIM is plugged
//  updateSerial();
//  mySerial.println("AT+CREG?"); //Check whether it has registered in the network
//  updateSerial();
//  
//  mySerial.println("ATI"); // GET the module and revision
//  updateSerial();
//  mySerial.println("AT+COPS?"); // check which network you are connectted to
//  updateSerial();
//  delay(1000);
//  mySerial.println("AT+COPS=?"); // return the list of operators present in the network
//  updateSerial();
  delay(1000);  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  delay(1000);

  mySerial.println("AT+CMGS=\"+40763892629\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  delay(1000);
  mySerial.println("Merge Gabiiiiiiiii"); //text content
  updateSerial();
  delay(1000);

//  mySerial.println("AT+CFUN=1.1");
//  updateSerial();
//  mySerial.println("ATD+40787673020"); //  change ZZ with country code and xxxxxxxxxxx with phone number to dial
//  updateSerial();
//  delay(10000); // wait for 20 seconds...
//  mySerial.println("ATH"); //hang up
//  updateSerial();
  
  mySerial.write(26);
//mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
//  updateSerial();
//  mySerial.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
//  updateSerial();
  
}

void loop()
{
//    //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
//  Serial.begin(9600);
//  //Begin serial communication with Arduino and A6
//  mySerial.begin(9600);
//  
//  Serial.println("shark");
//  Serial.println("Initializing..."); 
//  delay(1000);
//  
//  Serial.println("e ok");
//  mySerial.println("AT");
//  delay(1000);//Once the handshake test is successful, it will back to OK
//  updateSerial();
//  mySerial.println("AT+QRST=1");
//  delay(1000);
//  updateSerial();
//  //mySerial.println("AT+CFUN=1.1");
// // updateSerial();
//  mySerial.println("AT+QBAND=7");
//  delay(1000);
//  updateSerial();
////  mySerial.println("AT+CSQ"); //Signal quality test, value range is 0-31 , 31 is the best
////  updateSerial();
////  mySerial.println("AT+CCID"); //Read SIM information to confirm whether the SIM is plugged
////  updateSerial();
////  mySerial.println("AT+CREG?"); //Check whether it has registered in the network
////  updateSerial();
////  
////  mySerial.println("ATI"); // GET the module and revision
////  updateSerial();
//  mySerial.println("AT+COPS?"); // check which network you are connectted to
//  updateSerial();
//  mySerial.println("AT+COPS=?"); // return the list of operators present in the network
//  updateSerial();
//  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
//  updateSerial();
//  mySerial.println("AT+CMGS=\"+40729364858\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
//  updateSerial();
//  mySerial.println("Alo Marian"); //text content
//  updateSerial();
//  mySerial.write(26);
////mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
////  updateSerial();
////  mySerial.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
////  updateSerial();
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
