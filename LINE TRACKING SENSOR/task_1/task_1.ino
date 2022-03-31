#define lineSensor 8
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lineSensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(digitalRead(lineSensor)); // Line Tracking sensor is connected with pin 8 of the Arduino
  delay(500);
}
