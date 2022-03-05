#include <dht.h>
#define dhtpin A0
dht DHT;
int green = 2;
int red = 3;
double temp_1;
double temp_2 = 33.0;
double humid;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.println("DHT11 Humidity and Temperature Sensor \n \n");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  DHT.read11(dhtpin);
  temp_1 = DHT.temperature;
  humid = DHT.humidity;
  if(temp_1 > temp_2){
    digitalWrite(green, LOW);
    delay(100);
    digitalWrite(red, HIGH);
    delay(100);
  } else if (temp_1 < temp_2){
    digitalWrite(green, HIGH);
    delay(100);
    digitalWrite(red, LOW);
    delay(100);
  } else if (temp_1 == temp_2){
 
  }
    temp_2 = temp_1;
    Serial.print("Current Humidity = ");
    Serial.print(humid);
    Serial.print("% ");
    Serial.print(temp_1);
    Serial.println("C ");
    delay(2000);
  }
  
