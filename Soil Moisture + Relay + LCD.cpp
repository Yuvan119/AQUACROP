#include <LiquidCrystal.h>

#define SOIL_SENSOR A0
#define RELAY_PIN 8

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int moisture;
int threshold = 500;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);

  lcd.begin(16, 2);
  lcd.print("Auto Irrigation");
}

void loop() {
  moisture = analogRead(SOIL_SENSOR);

  lcd.setCursor(0, 1);
  lcd.print("Moisture: ");
  lcd.print(moisture);

  if (moisture > threshold) {
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Pump ON");
  } else {
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Pump OFF");
  }

  delay(1000);
}
