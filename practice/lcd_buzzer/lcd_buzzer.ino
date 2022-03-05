#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();

//  lcd.setCursor(1, 0);
//  lcd.print("Hello...");
//  lcd.setCursor(2, 1);
//  lcd.print("I'm Vincent :)");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hello...");
  lcd.blink();
  delay(2000);
  lcd.clear();
  
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("There...");
  delay(2000);
  lcd.clear();
  
}
