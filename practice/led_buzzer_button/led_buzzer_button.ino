const int ledPin = 9;
const int btnPin = 4;
const int buzzPin = 10;
int btnState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(btnPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  btnState = digitalRead(btnPin);
  if(btnState == HIGH){
    digitalWrite(ledPin, HIGH);
    Serial.println("LED IS ON");
    tone(buzzPin, 600);   
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("LED IS OFF"); 
    noTone(buzzPin);
  }
  
}
