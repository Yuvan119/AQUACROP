#define RELAY_PIN 8

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  digitalWrite(RELAY_PIN, LOW);   // Pump ON
  delay(3000);
  digitalWrite(RELAY_PIN, HIGH);  // Pump OFF
  delay(3000);
}
