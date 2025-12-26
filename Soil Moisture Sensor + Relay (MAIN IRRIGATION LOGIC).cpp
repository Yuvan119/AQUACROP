#define SOIL_SENSOR A0
#define RELAY_PIN 8

int moistureValue;
int threshold = 500;   // Adjust based on soil

void setup() {
  Serial.begin(9600);
  pinMode(SOIL_SENSOR, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Pump OFF initially
}

void loop() {
  moistureValue = analogRead(SOIL_SENSOR);
  Serial.print("Soil Moisture: ");
  Serial.println(moistureValue);

  if (moistureValue > threshold) {
    digitalWrite(RELAY_PIN, LOW);   // Pump ON
    Serial.println("Soil Dry → Irrigation ON");
  } else {
    digitalWrite(RELAY_PIN, HIGH);  // Pump OFF
    Serial.println("Soil Wet → Irrigation OFF");
  }

  delay(1000);
}
