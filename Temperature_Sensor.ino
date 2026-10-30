#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // RS, E, D4, D5, D6, D7

void setup() {
  pinMode(8, OUTPUT);       // LED on D8
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(A0);
  float voltage = reading * 5.0 / 1024.0;
  float temp = (voltage - 0.5) * 100.0;

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp, 1);
  lcd.print(" C   ");

  lcd.setCursor(0, 1);
  if (temp > 25) {
    digitalWrite(8, HIGH);
    lcd.print("Status: HIGH!   ");
  } else {
    digitalWrite(8, LOW);
    lcd.print("Status: Normal  ");
  }

  Serial.println(temp);
  delay(500);
}