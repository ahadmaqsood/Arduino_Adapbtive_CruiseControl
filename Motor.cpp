#include <UCMotor.h>

#define TRIG_PIN A2
#define ECHO_PIN A3
#define TRIG_PIN A4
#define ECHO_PIN A5
#define TRIG_PIN A9
#define ECHO_PIN A11
const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin2 = 11;
const int echoPin2 = 9;
const int trigPin3 = 12;
const int echoPin3 = 10;


float duration_front, distance_front;
float duration_right, distance_right;
float duration_back, distance_back;
float duration_left, distance_left;

UC_DCMotor leftMotor1(3, MOTOR34_64KHZ);
UC_DCMotor rightMotor1(4, MOTOR34_64KHZ);
UC_DCMotor leftMotor2(1, MOTOR34_64KHZ);
UC_DCMotor rightMotor2(2, MOTOR34_64KHZ);
void setup() {
  // put your setup code here, to run once:
  pinMode(ECHO_PIN, INPUT); //Set the connection pin output mode Echo pin
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  //Forward
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration_front = pulseIn(ECHO_PIN, HIGH);
  distance_front = (duration_front*.0343)/2;

  pinMode(trigPin1, OUTPUT);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration_right = pulseIn(echoPin1, HIGH);
  distance_right = (duration_right*.0343)/2;

  pinMode(trigPin2, OUTPUT);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration_back = pulseIn(echoPin1, HIGH);
  distance_back = (duration_right*.0343)/2;
  

  Serial.print("Distance: front    ");
  Serial.print(distance_front);
  Serial.print("   Distance: right    ");
  Serial.println(distance_right);
  delay(1);
  if(distance_front>20){
      leftMotor1.run(0x01); rightMotor1.run(0x01);
      leftMotor2.run(0x01); rightMotor2.run(0x01);
      leftMotor1.setSpeed(100); rightMotor1.setSpeed(100);
      leftMotor2.setSpeed(100); rightMotor2.setSpeed(100);
      delay(2);
  }
  else if(distance_front <= 20){
        leftMotor1.run(0x01); rightMotor1.run(0x01);
        leftMotor2.run(0x01); rightMotor2.run(0x01);
        leftMotor1.setSpeed(0); rightMotor1.setSpeed(0);
        leftMotor2.setSpeed(0); rightMotor2.setSpeed(0);
        delay(2);
  }

  if(distance_right <=15){
    if(distance_front>20){
      leftMotor1.run(0x01); rightMotor1.run(0x01);
      leftMotor2.run(0x01); rightMotor2.run(0x01);
      leftMotor1.setSpeed(200); rightMotor1.setSpeed(50);
      leftMotor2.setSpeed(200); rightMotor2.setSpeed(50);
      delay(2);
  
  if(distance_left <=15){
      if(distance_front>20){
        leftMotor1.run(0x01); rightMotor1.run(0x01);
        leftMotor2.run(0x01); rightMotor2.run(0x01);
        leftMotor1.setSpeed(50); rightMotor1.setSpeed(200);
        leftMotor2.setSpeed(50); rightMotor2.setSpeed(200);
        delay(2);
  
     if(distance_back <=15){
       if(distance_front>20){
        leftMotor1.run(0x01); rightMotor1.run(0x01);
        leftMotor2.run(0x01); rightMotor2.run(0x01);
        leftMotor1.setSpeed(200); rightMotor1.setSpeed(200);
        leftMotor2.setSpeed(200); rightMotor2.setSpeed(200);
        delay(2);


  }
}
}
