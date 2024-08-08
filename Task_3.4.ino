#include <Servo.h>

// Pin definitions
const int trigFront = 2;
const int echoFront = 3;
const int trigRight = 4;
const int echoRight = 5;
const int trigBack = 6;
const int echoBack = 7;
const int trigLeft = 8;
const int echoLeft = 9;
const int photoresistorPin = A0;
const int buzzerPin = 10;
const int servoPin = 11;
const int motorR1 = 12;
const int motorR2 = 13;
const int motorL1 = A1;
const int motorL2 = A2;

// Servo motor
Servo defuseServo;

// Movement control variables
const int obstacleThreshold = 120; // Distance threshold to detect obstacles
const int lightThreshold = 500; // Light level threshold for bomb detection

void setup() {
  Serial.begin(9600);

  // Initialize ultrasonic sensors
  pinMode(trigFront, OUTPUT);
  pinMode(echoFront, INPUT);
  pinMode(trigRight, OUTPUT);
  pinMode(echoRight, INPUT);
  pinMode(trigBack, OUTPUT);
  pinMode(echoBack, INPUT);
  pinMode(trigLeft, OUTPUT);
  pinMode(echoLeft, INPUT);

  // Initialize photoresistor sensor and buzzer
  pinMode(photoresistorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  // Initialize motor driver
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);

  // Initialize servo motor
  defuseServo.attach(servoPin);
  defuseServo.write(0); // Initial position
}

void loop() {
  // Read sensor data
  int distance1 = readUltrasonic(trigFront, echoFront);
  int distance2 = readUltrasonic(trigRight,echoRight);
  int distance3 = readUltrasonic(trigBack, echoBack);
  int distance4 = readUltrasonic(trigLeft, echoLeft);
  int lightLevel = analogRead(photoresistorPin);

  // Bomb detection
  if (lightLevel > lightThreshold) {
    digitalWrite(buzzerPin, HIGH);
    defuseServo.write(60); // Move servo to defuse bomb
    delay(2000); // Defuse time
    defuseServo.write(0); // Reset servo
    delay (1000);
    digitalWrite(buzzerPin, LOW);
  }

  // Obstacle avoidance
  if (distance1 < obstacleThreshold ) {
    stop();
    moveRight(); // Function to handle obstacle avoidance
  } else {
    moveForward();
  }

  if (distance4 < obstacleThreshold ){
    stop();
    moveForward();
  }
  else{
    moveLeft();
  }

}

int readUltrasonic(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.0344 / 2;

  return distance;
}

void moveForward() {
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
}

void stop() {
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, LOW);
}

void moveRight(){
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW); 

}

void moveLeft(){
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH); 

}
