#define SOIL_SENSOR A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(SOIL_SENSOR);
  Serial.print("Moisture Value: ");
  Serial.println(value);
  delay(1000);
}
