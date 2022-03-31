int sound = A0;
void setup() {
  // put your setup code here, to run once:
  pinMode(sound, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(sound));
  delay(100);
}
