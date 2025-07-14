#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150
#define SERVOMAX  600

const int servos[] = {0, 1, 2, 3};
const int fifthServo = 4;

const int sensorPin = A1;

// Thresholds (adjust as needed)
const int upperThreshold = 300;  // Arm closed
const int lowerThreshold = 200;  // Arm open (hysteresis)

// Tracking state
bool armClosed = false;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);

  moveArm(false); // Start in open position
}

void loop() {
  int avgEMG = readAverageEMG(10);  // Smooth EMG input
  Serial.print("EMG avg: ");
  Serial.println(avgEMG);

  if (!armClosed && avgEMG > upperThreshold) {
    moveArm(true); // Close arm
    armClosed = true;
  } 
  else if (armClosed && avgEMG < lowerThreshold) {
    moveArm(false); // Open arm
    armClosed = false;
  }

  delay(100);  // Adjust for response rate
}

int readAverageEMG(int samples) {
  long total = 0;
  for (int i = 0; i < samples; i++) {
    total += analogRead(sensorPin);
    delay(5);
  }
  return total / samples;
}

void moveArm(bool close) {
  int angle = close ? 180 : 0;
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);

  for (int i = 0; i < 4; i++) {
    pwm.setPWM(servos[i], 0, pulse);
    Serial.print("Servo ");
    Serial.print(servos[i]);
    Serial.println(close ? " closed" : " opened");
  }

  int fifthAngle = close ? 0 : 90;
  int fifthPulse = map(fifthAngle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(fifthServo, 0, fifthPulse);
  Serial.println(close ? "Fifth servo closed" : "Fifth servo opened");
}
