//#include <SoftwareSerial.h>

//const int rxPin = 2;
//const int txPin = 3;
char c;

//SoftwareSerial mySerial(rxPin, txPin);

void setup() {
 //mySerial.begin(9600);
 Serial.begin(9600);

}

void loop() {
  if (Serial.available()){
    c = Serial.read();
    Serial.print(c);
  }
Serial.write("hello");  
delay (500); 
}
