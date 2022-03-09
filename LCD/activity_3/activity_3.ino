#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>
#define dhtpin A0
dht DHT;
double temp, humid;
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
  DHT.read11(dhtpin);
  temp = DHT.temperature;
  humid = DHT.humidity;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp);

  lcd.setCursor(0,1);
  lcd.print("Humid: ");
  lcd.print(humid);

  Serial.print("Humid: ");
  Serial.println(humid);
  Serial.print("Temp: ");
  Serial.println(temp);
  delay(1000);
}
