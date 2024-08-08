//Right Motor pins
#define MotorRA 5
#define MotorRB 6

//Left Motor pins
#define MotorLA 9
#define MotorLB 10

void setup()
{
  pinMode(MotorRA, OUTPUT);
  pinMode(MotorRB, OUTPUT);
  pinMode(MotorLA, OUTPUT);
  pinMode(MotorLB, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
//YAW RIGHT
 Serial.println("Robot is moving to the Right"); 
 digitalWrite (MotorRA, LOW);  
 digitalWrite (MotorRB, HIGH); 
 digitalWrite (MotorLA, LOW);  
 digitalWrite (MotorLB, HIGH); 
 delay (1000);
   
  
  
 //YAW LEFT
 Serial.println("Robot is moving to the Left");  
 digitalWrite (MotorRA, HIGH);  
 digitalWrite (MotorRB, LOW); 
 digitalWrite (MotorLA, HIGH);  
 digitalWrite (MotorLB, LOW); 
 delay (1000);
 
  
 //FORWARD
 Serial.println("Robot is moving Forward"); 
 digitalWrite (MotorRA, HIGH);  
 digitalWrite (MotorRB, LOW); 
 digitalWrite (MotorLA, LOW);  
 digitalWrite (MotorLB, HIGH);   
 delay (1000); 
  
 //BACKWARD
 Serial.println("Robot is moving Backward");   
 digitalWrite (MotorRA, LOW);  
 digitalWrite (MotorRB, HIGH);
 digitalWrite (MotorLA, HIGH);  
 digitalWrite (MotorLB, LOW);  
 delay (1000);
 
  
}

