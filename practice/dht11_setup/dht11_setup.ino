#include <dht.h>

dht DHT;
int sensor_pin = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int chk = DHT.read11(sensor_pin);
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.println();
  
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  Serial.println();
  Serial.println();
  delay(100);
}
