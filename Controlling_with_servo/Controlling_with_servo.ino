#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create PWM driver instance
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Pulse width range for standard servos
#define SERVOMIN  150   // Pulse for 0 degrees
#define SERVOMAX  600   // Pulse for 180 degrees

// Main 4 servos (channels 0–3)
const int servos[] = {0, 1, 2, 3};
const int numServos = sizeof(servos) / sizeof(servos[0]);

// 5th servo on channel 4
const int fifthServo = 4;

// Track 5th servo position state
bool isFifthAt90 = true;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);  // 50Hz frequency for servos
  delay(10);

  // Set all 4 main servos to 0°
  int startAngle = 0;
  int pulse = map(startAngle, 0, 180, SERVOMIN, SERVOMAX);
  for (int i = 0; i < numServos; i++) {
    pwm.setPWM(servos[i], 0, pulse);
    Serial.print("Servo ");
    Serial.print(servos[i]);
    Serial.println(" set to 0°");
  }

  // Set 5th servo to 90°
  int fifthPulse = map(90, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(fifthServo, 0, fifthPulse);
  Serial.println("Fifth servo (channel 4) set to 90°");

  delay(4000);  // Wait before loop starts
}

void loop() {
  // --- Update 5th servo first (so it feels synced) ---
  if (isFifthAt90) {
    int fifthPulse = map(0, 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(fifthServo, 0, fifthPulse);
    Serial.println("Fifth servo set to 0°");
    isFifthAt90 = false;
  } else {
    int fifthPulse = map(90, 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(fifthServo, 0, fifthPulse);
    Serial.println("Fifth servo set to 90°");
    isFifthAt90 = true;
  }

  // --- Now move servos 0–3 to 180° ---
  int angle = 180;
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  for (int i = 0; i < numServos; i++) {
    pwm.setPWM(servos[i], 0, pulse);
    Serial.print("Servo ");
    Serial.print(servos[i]);
    Serial.println(" set to 180°");
  }

  delay(4000);

  // --- Move all servos back to 0° ---
  angle = 0;
  pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  for (int i = 0; i < numServos; i++) {
    pwm.setPWM(servos[i], 0, pulse);
    Serial.print("Servo ");
    Serial.print(servos[i]);
    Serial.println(" set to 0°");
  }

  // Note: 5th servo will toggle again in the next loop()

  delay(4000);
}
