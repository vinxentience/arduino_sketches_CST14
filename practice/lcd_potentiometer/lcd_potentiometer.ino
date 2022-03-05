#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  lcd.clear();
  lcd.setCursor(0,0);
  Serial.println(sensorValue);
  lcd.print(sensorValue);

  if(sensorValue > 512){
    lcd.setCursor(0,1);
    lcd.print("Brighter...");
  } else {
    lcd.setCursor(0,1);
    lcd.print("Dimmer...");
  }

  sensorValue = map(sensorValue, 1, 1024, 1, 255);
  analogWrite(3, sensorValue);
  
  delay(70);
//  lcd.clear();
//  lcd.setCursor(0,1);
//  lcd.print("There...");
//  delay(2000);
//  lcd.clear();
  
}
