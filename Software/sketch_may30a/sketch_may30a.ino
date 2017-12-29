#include <AFMotor.h>
#include <NewTone.h>




AF_DCMotor leftMotor(1, MOTOR12_64KHZ);
AF_DCMotor rightMotor(2, MOTOR12_64KHZ);

int leftSensorPin = A0;
int rightSensorPin = A1;
int buzzerPin = A2;
int ledPin = A3;
bool isObstacle = HIGH;

void detectObstacle()
{
  int left = digitalRead(leftSensorPin);
  
  int right = digitalRead(rightSensorPin);
  

  if( left == LOW || right == LOW )
  {
    Serial.println("S-a detectat obstacol!!!");
    isObstacle = LOW;
  }
  else
    isObstacle = HIGH;

}

void motorStop()
{
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);
}
void motorRun()
{
  
  delay(10);
  leftMotor.run(FORWARD);
  rightMotor.run(FORWARD);
  
}

void showAvertizare()
{
  Serial.println("Initiez rutina de avertizare!!!");
  
  
  digitalWrite(ledPin,HIGH);
  delay(200);
  NewTone(buzzerPin,3000);
  digitalWrite(ledPin,LOW);
  delay(200);
  noNewTone(buzzerPin);
  digitalWrite(ledPin,HIGH);
  delay(200);
  NewTone(buzzerPin,3000);
  digitalWrite(ledPin,LOW);
  delay(200);
  noNewTone(buzzerPin);
  
}


void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.println("Mini-robot cu detectie obstacole");
  delay(500);
  Serial.println("Licenta 2017");
  delay(500);
  Serial.println("Ioan-Marian Manta");
  delay(500);

  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);

  pinMode(ledPin,OUTPUT);
  
  NewTone(buzzerPin,3000);
  digitalWrite(ledPin,HIGH);
  delay(500);
  digitalWrite(ledPin,LOW);
  noNewTone(buzzerPin);
  delay(500);
  digitalWrite(ledPin,HIGH);
  NewTone(buzzerPin,3000);
  delay(500);
  digitalWrite(ledPin,LOW);
  noNewTone(buzzerPin);
  delay(500);
  digitalWrite(ledPin,HIGH);
  NewTone(buzzerPin,3000);
  delay(500);
  digitalWrite(ledPin,LOW);
  noNewTone(buzzerPin);
  delay(500);

  
  pinMode(leftSensorPin,INPUT);
  pinMode(rightSensorPin,INPUT);

  pinMode(buzzerPin,OUTPUT);
  delay(50);
}

void loop() {
  Serial.println("INCEP SA MA PLIMB");
  motorRun();
  delay(10);
  detectObstacle();
  delay(10);
  if( isObstacle == LOW )
  {
    motorStop();
    showAvertizare();
  }
 
}
