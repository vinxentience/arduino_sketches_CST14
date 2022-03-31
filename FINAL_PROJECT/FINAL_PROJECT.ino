#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
dht DHT;
const int trigPin = 9;
const int echoPin = 10;
int sensor_pin = 5;
int buzzer = 6;
int red = 2;
int green = 3;
int blue = 4;
long duration;
int distance;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin();
  pinMode(buzzer, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //ULTRASONIC
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  //DHT
  int chk = DHT.read11(sensor_pin);
  double temp = DHT.temperature;
  double humid = DHT.humidity;
  
  if(temp > 33){
    lcd.setCursor(0, 0);
    lcd.print("Hot temp");
    setColor(255, 0, 0);
  }else if(temp < 25){
    lcd.setCursor(0, 0);
    lcd.print("Cold temp");
    setColor(0, 0, 255);
  }else{
    lcd.setCursor(0, 0);
    lcd.print("Normal temp");
    setColor(0, 255, 0);
  }

  changeLightFromDistance(distance);
  
  if(distance < 15){
    lcd.setCursor(0, 1);
    lcd.print("Obstacle");
    tone(buzzer, 700, 3000);
  }else{
    lcd.setCursor(0, 1);
    lcd.print("");
    noTone(buzzer);
  }
  
  delay(500);


  if(humid >= 60){
    
  } else{
    setColor(0, 0, 255);
  }
  delay(500);
  lcd.clear();
}

void setColor(int redVal, int greenVal, int blueVal){
  analogWrite(red, redVal);
  analogWrite(green, greenVal);
  analogWrite(blue, blueVal);
}

void lightBlue() {
  setColor(0, 0, 255);
}

void lightRed() {
  setColor(255, 0,0);
}

void lightGreen() {
  setColor(0, 255, 0);
}

void changeLightFromDistance(int distance) {
    if (distance < 15) {
      lightRed();
    } else {
      lightGreen();
    }

}
