const int ledPin_1 = 9;
const int ledPin_2 = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = analogRead(A0);
  Serial.println(a);

  if(a >= 10){
    digitalWrite(ledPin_1, LOW);
    digitalWrite(ledPin_2, LOW);
    delay(300);
  } else{
    digitalWrite(ledPin_1, HIGH);
    digitalWrite(ledPin_2, HIGH);
    delay(300);
    digitalWrite(ledPin_1, LOW);
    digitalWrite(ledPin_2, LOW);
    delay(300);
    digitalWrite(ledPin_1, HIGH);
    digitalWrite(ledPin_2, HIGH);
    delay(300);
    digitalWrite(ledPin_1, LOW);
    digitalWrite(ledPin_2, LOW);
    delay(300);
    digitalWrite(ledPin_1, HIGH);
    digitalWrite(ledPin_2, HIGH);
    delay(300);
    digitalWrite(ledPin_1, LOW);
    digitalWrite(ledPin_2, LOW);
    delay(300);
    digitalWrite(ledPin_1, HIGH);
    digitalWrite(ledPin_2, HIGH);
    delay(8000);
  }
}
