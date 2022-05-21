#include <Wire.h>
#include <dht.h>
#include <LiquidCrystal_I2C.h>
#include <AFMotor.h>

//defining pins and variables
#define lefts A0
#define rights A2
#define dhtpin A3

//defining DHT11
dht DHT;

//defining LCD

LiquidCrystal_I2C lcd(0x27, 16, 2);

//defining motors
 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);

void setup() {
  //Setting the motor speed
  motor2.setSpeed(100);
  motor3.setSpeed(100);

  //Declaring PIN input types
  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);
  //Begin serial communication
  Serial.begin(9600);
  
  lcd.begin();
  lcd.backlight();
  lcd.clear();
}

void loop(){
  
  //Printing values of the sensors to the serial monitor
  Serial.print(lefts);
  Serial.print("    ");
  Serial.println(rights); 
  DHT.read11(dhtpin);
  
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);

  lcd.setCursor(0,1);
  lcd.print("Humid: ");
  lcd.print(DHT.humidity);

  //line detected by both
  if(analogRead(lefts)<=350 && analogRead(rights)<=350){
    //Forward
   
    motor2.run(FORWARD);
    motor3.run(FORWARD);
   
  }
  //line detected by left sensor
  else if(analogRead(lefts)<=350 && !analogRead(rights)<=350){
    //turn left

    motor2.run(FORWARD);
    motor3.run(BACKWARD);

    
  }
  //line detected by right sensor
  else if(!analogRead(lefts)<=350 && analogRead(rights)<=350){
    //turn right

    motor2.run(BACKWARD);
    motor3.run(FORWARD);

   
  }
  //line detected by none
  else if(!analogRead(lefts)<=350 && !analogRead(rights)<=350){
    //stop
    motor2.run(RELEASE);
    motor3.run(RELEASE);
  }
  
}
