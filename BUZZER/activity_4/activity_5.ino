int amy = 3;
int ron = 4;
int led1 = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(amy, OUTPUT);
  pinMode(ron, OUTPUT);
  pinMode(led1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(amy, HIGH);
  digitalWrite(ron, HIGH);
  digitalWrite(led1, HIGH);
  delay(500);
  digitalWrite(amy, LOW);
  delay(500);
  digitalWrite(ron, LOW);
  delay(500);
  digitalWrite(led1, LOW);
  delay(1000);
}
