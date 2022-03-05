const int ledPin = 9;
const int buzzPin = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = analogRead(A0);
  Serial.println(a);

  if(a >= 20){
    digitalWrite(ledPin, LOW);
    delay(300);
    noTone(buzzPin);
  } else{
    digitalWrite(ledPin, HIGH);
    tone(buzzPin, 100);
    delay(300); 
  }
}
