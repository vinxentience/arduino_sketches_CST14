#include <dht.h>
#define dhtpin A0
dht DHT;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT11 Humidity and Temperature Sensor \n \n");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  DHT.read11(dhtpin);
  Serial.print("Current Humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("% ");
  Serial.print(DHT.temperature);
  Serial.println("C ");

  delay(5000);
}
