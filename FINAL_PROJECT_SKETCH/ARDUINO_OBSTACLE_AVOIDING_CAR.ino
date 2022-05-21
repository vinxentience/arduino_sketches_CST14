#include <Wire.h>
#include <dht.h>
#include <LiquidCrystal_I2C.h>
#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h> 

#define ECHO_PIN A0
#define TRIG_PIN A2
#define MAX_DISTANCE 200 
#define MAX_SPEED 110 // sets speed of DC  motors
#define MAX_SPEED_OFFSET 5
#define dhtpin A3

dht DHT;
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
LiquidCrystal_I2C lcd(0x27, 16, 2);

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 


Servo myservo;    
boolean goesForward=false;
int distance = 100;
int speedSet = 0;


void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  myservo.attach(9);  
  myservo.write(100); 
  motor2.setSpeed(MAX_SPEED + MAX_SPEED_OFFSET);
  motor3.setSpeed(MAX_SPEED);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
 int distanceR = 0;
 int distanceL =  0;

 DHT.read11(dhtpin);
  
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);

  lcd.setCursor(0,1);
  lcd.print("Humid: ");
  lcd.print(DHT.humidity);
  
 delay(40);
  
 if(distance <= 20)
 {
  
  moveStop();
  delay(500);
  moveBackward();
  delay(700);
  moveStop();
  delay(500);
  distanceR = lookRight();
  delay(500);
  distanceL = lookLeft();
  delay(500);
  
  if(distanceR>=distanceL)
  {
    turnRight();
    delay(500);
    moveStop();
  }else
  {
    turnLeft();
    delay(500);
    moveStop();
  }
 }else
 {
  moveForward();
 }
 distance = readPing();
 Serial.println(distance);
}

int lookRight()
{
    myservo.write(0); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(100); 
    return distance;
}

int lookLeft()
{
    myservo.write(180); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(100); 
    return distance;
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  Serial.println(cm);
  return cm;
}

void moveStop() {
  motor2.run(RELEASE);
  motor3.run(RELEASE);
} 
  
void moveForward() {
  Serial.println("Move Forward");
 if(!goesForward)
  {
    goesForward=true;
     
//   for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
//   {
//   
//    motor2.setSpeed(speedSet);
//    motor3.setSpeed(speedSet);
//   
//    delay(5);
//   }
    motor2.setSpeed(MAX_SPEED + MAX_SPEED_OFFSET);
    motor3.setSpeed(MAX_SPEED);
    motor2.run(FORWARD);
    motor3.run(FORWARD); 

  }
}

void moveBackward() {
  Serial.println("Move Backward");
    goesForward=false;
    motor2.setSpeed(MAX_SPEED + MAX_SPEED_OFFSET);
    motor3.setSpeed(MAX_SPEED);
    
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
   
//  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
//  {
//    motor2.setSpeed(speedSet);
//    motor3.setSpeed(speedSet);
//    delay(5);
//  }
}  

void turnRight() {
  Serial.println("Move Right");
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  delay(400);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
} 
 
void turnLeft() {
  Serial.println("Move Left");
  motor2.run(BACKWARD);  
  motor3.run(FORWARD);
  delay(400);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
}
