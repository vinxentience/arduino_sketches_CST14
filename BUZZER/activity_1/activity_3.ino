int buzz = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(buzz, 150);
  delay(1000);
  noTone(buzz);
  delay(500);

  tone(buzz, 150);
  delay(1000);
  noTone(buzz);
  delay(500);
  
  tone(buzz, 150);
  delay(1000);
  noTone(buzz);
  delay(2000);
}
