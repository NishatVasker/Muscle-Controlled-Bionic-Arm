const int emgPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(emgPin);
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert ADC reading to voltage
  Serial.print(sensorValue);
  Serial.print("  |  ");
  Serial.print(voltage, 3);
  Serial.println(" V");
  delay(100);  // 10 readings per second
}
