#include <Wire.h>
//#include <SoftwareSerial.h>
//const int rxPin = 2;
//const int txPin = 3;
char c;
char b;

//SoftwareSerial mySerial(rxPin, txPin);

void setup() {
 Wire.begin();
 Serial.begin(9600);

}

void loop() {
  Wire.requestFrom (8,5);

  while (Wire.available()){
    c = Wire.read();
    Serial.print(c);
  }
Serial.println("");
  
  if (Serial.available()){
  	b = Serial.read();
 }  
 Wire.beginTransmission(8);
 Wire.write(b);
 Wire.endTransmission();
 
delay (500);

}
