void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  int a = analogRead(A0);
  Serial.println(a);
  if(a <= 20){
    digitalWrite(9, LOW);
  } else {
    tone(8, 500);
    delay(3000);
    noTone(8);
    delay(50);
    digitalWrite(9, HIGH); 
    delay(3000);
  }
}
