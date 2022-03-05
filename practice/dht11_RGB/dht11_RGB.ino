#include <dht.h>

dht DHT;
int sensor_pin = 7;
int red = 2;
int green = 3;
int blue = 4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int chk = DHT.read11(sensor_pin);
  double temp = DHT.temperature;
  double humid = DHT.humidity;
  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.println();
  
  Serial.print("Humidity = ");
  Serial.print(humid);
  Serial.println();
  Serial.println();

  if(humid >= 60){
    setColor(255, 0, 0);
  } else{
    setColor(0, 0, 255);
  }
  delay(500);
}

void setColor(int redVal, int greenVal, int blueVal){
  analogWrite(red, redVal);
  analogWrite(green, greenVal);
  analogWrite(blue, blueVal);
}
