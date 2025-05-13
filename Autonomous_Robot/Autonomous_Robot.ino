#include <Servo.h>

// Updated Pin Configuration (Your Setup)
const int trigPin = 4;     // HC-SR04 Trig -> D4
const int echoPin = 2;     // HC-SR04 Echo -> D2
const int servoPin = 3;    // Servo signal (yellow) -> D3

// L298N Motor Driver (Your Setup)
const int enAPin = 9;      // Left motor PWM (ENA)
const int in1Pin = 8;      // Left motor direction 1
const int in2Pin = 7;      // Left motor direction 2
const int in3Pin = 6;      // Right motor direction 1
const int in4Pin = 5;      // Right motor direction 2
const int enBPin = 10;     // Right motor PWM (ENB)

// Constants
#define NUMANGLES 7
#define SAFE_DISTANCE 300  // 300mm = 30cm

Servo servo;
enum Motor { LEFT, RIGHT };
unsigned char sensorAngle[NUMANGLES] = {60,70,80,90,100,110,120};
unsigned int distance[NUMANGLES];

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);

  // Motor control pins
  pinMode(enAPin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  pinMode(enBPin, OUTPUT);

  servo.attach(servoPin);
  servo.write(90);  // Center servo
  
  // Initial motor test
  testMotors();
  
  // Initial environment scan
  servo.write(sensorAngle[0]);
  delay(200);
  for (unsigned char i = 0; i < NUMANGLES; i++) {
    readNextDistance();
    delay(200);
  }
}

void loop() {
  readNextDistance();
  
  // Obstacle detection
  unsigned char tooClose = 0;
  for (unsigned char i = 0; i < NUMANGLES; i++) {
    if (distance[i] < SAFE_DISTANCE) {
      tooClose = 1;
      break;
    }
  }

  if (tooClose) {
    // Avoidance maneuver: Backup and turn left
    go(LEFT, -180);
    go(RIGHT, -80);
  } else {
    // Clear path: Full speed ahead
    go(LEFT, 255);
    go(RIGHT, 255);
  }
  delay(50);
}

// Motor control function
void go(enum Motor m, int speed) {
  if (m == LEFT) {
    digitalWrite(in1Pin, speed > 0 ? HIGH : LOW);
    digitalWrite(in2Pin, speed <= 0 ? HIGH : LOW);
    analogWrite(enAPin, abs(speed));
  } else {
    digitalWrite(in3Pin, speed > 0 ? HIGH : LOW);
    digitalWrite(in4Pin, speed <= 0 ? HIGH : LOW);
    analogWrite(enBPin, abs(speed));
  }
}

// Motor test sequence
void testMotors() {
  static int speed[8] = {128,255,128,0,-128,-255,-128,0};
  
  // Left motor test
  for (unsigned char i = 0; i < 8; i++) {
    go(LEFT, speed[i]);
    delay(200);
  }
  
  // Right motor test
  for (unsigned char i = 0; i < 8; i++) {
    go(RIGHT, speed[i]);
    delay(200);
  }
}

// Ultrasonic sensor functions
unsigned int readDistance() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  unsigned long period = pulseIn(echoPin, HIGH);
  return period * 343 / 2000;  // Return distance in mm
}

void readNextDistance() {
  static unsigned char angleIndex = 0;
  static signed char step = 1;
  
  distance[angleIndex] = readDistance();
  angleIndex += step;
  
  if (angleIndex == NUMANGLES-1) step = -1;
  else if (angleIndex == 0) step = 1;
  
  servo.write(sensorAngle[angleIndex]);
}