int led = 8;
int buzz = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzz, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  tone(buzz, 500);
  digitalWrite(led, HIGH);
  delay(400);
  noTone(buzz);
  digitalWrite(led, LOW);
  delay(500);

  tone(buzz, 500);
  digitalWrite(led, HIGH);
  delay(400);
  noTone(buzz);
  digitalWrite(led, LOW);
  delay(500);

  tone(buzz, 500);
  digitalWrite(led, HIGH);
  delay(1500);
  noTone(buzz);
  digitalWrite(led, LOW);
  delay(1000);
}
