#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.print("Arduino");
  delay(3000);

  lcd.setCursor(2,1);
  lcd.print("LCD with Arduino");
  delay(3000);

  lcd.clear();
}
