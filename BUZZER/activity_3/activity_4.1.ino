int buzz = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  for (int i = 1; i <= 30; i++) {
    tone(buzz, 500);
    delay(100);
    noTone(buzz);
    delay(1000);
  }
    tone(buzz, 200);
    delay(5000);
    noTone(buzz);
    delay(500);
}
