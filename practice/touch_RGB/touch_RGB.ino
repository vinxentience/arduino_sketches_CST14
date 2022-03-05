#include <dht.h>

dht DHT;
int sensor_pin = 2;
int red = 5;
int green = 4;
int blue = 3;
int counter = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:
   int ctsValue = digitalRead(sensor_pin); 

   if (counter == 0){
    
   }
      if (ctsValue == HIGH)
        {  
           setColor(255, 0, 0);
           
           Serial.println("TOUCHED ");
           Serial.print(counter);
           }  
     else
        {    
            setColor(255, 0, 255);
             Serial.println("not touched"); 
          }  
       counter = counter + 1;
      delay(1);  
}

void setColor(int redVal, int greenVal, int blueVal){
  analogWrite(red, redVal);
  analogWrite(green, greenVal);
  analogWrite(blue, blueVal);
}
