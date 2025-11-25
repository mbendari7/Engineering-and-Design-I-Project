int mot1 = A1;
int mot2 = A2;
// int line = 0; // Not needed for a simple time-based task
bool movingForward = true; // Use this to track if the direction has been set

void setup() {
  // pinMode(A0, INPUT); // Not needed
  pinMode(mot1, OUTPUT);
  pinMode(mot2, OUTPUT);
  Serial.begin(9600);
  
  // Start motor FORWARD immediately in setup
  analogWrite(mot1, 200);
  analogWrite(mot2, 0);
  Serial.println("Moving Forward...");
}

void loop() {
  // We only want to execute the reversal logic ONCE
  if (movingForward == true) { 
    // 1. Wait for 2 seconds while the motor is already running forward (from setup)
    delay(3000); 

    // 2. Set motor to REVERSE
    analogWrite(mot1, 0);
    analogWrite(mot2, 200);
    
    // 3. Update the state so this code block never runs again
    movingForward = false; 
    Serial.println("Reversing...");
  }
  
  // If movingForward is false, the loop does nothing, and the motor remains in reverse.
}



#include <Servo.h>

int mot1 = A1;
int mot2 = A2;

Servo myServo;

void setup() {
  pinMode(mot1, OUTPUT);
  pinMode(mot2, OUTPUT);
  Serial.begin(9600);

  myServo.attach(9);     // Servo on pin 9
  myServo.write(0);      // Start at 0 degrees

  // Move forward
  analogWrite(mot1, 200);
  analogWrite(mot2, 0);

  delay(1750);           // Drive forward 1.25 seconds

  // Stop motors
  analogWrite(mot1, 0);
  analogWrite(mot2, 0); 

  // Turn servo to 180 degrees
  myServo.write(180);
  delay(1000);
  myServo.write(0);
}

void loop() {
  // Nothing needed here
}

