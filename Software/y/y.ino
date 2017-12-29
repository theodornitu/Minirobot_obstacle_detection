#include <AFMotor.h>
AF_DCMotor leftMotor(1, MOTOR12_64KHZ);
AF_DCMotor rightMotor(2, MOTOR12_64KHZ);

void setup() {
  // put your setup code here, to run once:
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);
}

void loop() {
  // put your main code here, to run repeatedly:

 leftMotor.run(FORWARD);
 rightMotor.run(FORWARD);
}

// leftMotor.run(BACKWARD);
 // leftMotor.run(FORWARD);
 // leftMotor.run(RELEASE);
 // rightMotor.run(BACKWARD);
 // rightMotor.run(RELEASE);
 // rightMotor.run(FORWARD);
