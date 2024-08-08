#include <Wire.h>
void setup() {
Serial.begin(9600);  
Wire.begin (8);
Wire.onRequest(requestEvent);
Wire.onReceive (receiveEvent);  
}

void loop() {
  delay (1000);

}

void requestEvent(){
  Wire.write ("HELLO");
}

void receiveEvent(){
  while(Wire.available()){
  	char a = Wire.read();
    Serial.print(a);
  }
  Serial.println("");
}