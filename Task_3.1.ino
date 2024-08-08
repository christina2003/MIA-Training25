// library of servo motor
#include <Servo.h>

Servo servo;

void setup()
{
// pin of servo motor  
servo.attach(3);
}

void loop()
{
//servo motor make a 60 degree angle for 2 seconds and return to 0.   
servo.write (60);
delay (2000);
servo.write (0);  
delay (2000);  
}