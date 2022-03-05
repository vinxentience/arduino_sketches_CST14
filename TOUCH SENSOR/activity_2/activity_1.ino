#include <dht.h>
#define dhtpin A0
dht DHT;
int red = 3;
int green = 2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(A0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = analogRead(A0);
  Serial.println(a);

  if(a <= 2){
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
  } else {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
  }
  }
  
