void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = analogRead(A0);
  Serial.println(a);
  if(a <= 689){
    digitalWrite(9, HIGH);
    delay(300);    
  } else {
    digitalWrite(9, LOW);
    tone(10, 500);
    delay(300); 
    noTone(10);
    delay(300);
  }
}
