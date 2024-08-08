//pins of ultrasonic sensor
#define echo 3
#define trig 2

//variables definitions
long timeInMicro;
int distanceInCm;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  digitalWrite (trig , LOW);
  delayMicroseconds (2);
  digitalWrite (trig , HIGH);
  delayMicroseconds (10);
  digitalWrite (trig , LOW);
  
  timeInMicro = pulseIn(echo , HIGH);
  
  /* speed of sound = 340 m/s = 29 microseconds/cm
     distance in cm = microseconds /29 /2 */
  
  distanceInCm = timeInMicro / 29 /2 ; 
 
  //condition to print 0 cm. if the reading is out of the range
  if (distanceInCm >= 331 )
   Serial.println ("0 cm.");
  
  else{
  Serial.print("Object detected at ");
  Serial.print(distanceInCm);
  Serial.println(" cm.");
  }
}