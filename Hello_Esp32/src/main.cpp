#include <Arduino.h>

#define LED  27

void setup() {
  pinMode(LED, OUTPUT);
 // Serial.begin(115200);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(3000);
  digitalWrite(LED, LOW);
  delay(3000);
 // Serial.print("OI");
}