int led = 6;
int clap = 0;
long detection_range_start = 0;
long detection_range = 0;
boolean status_lights = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int status_sensor = digitalRead(A0);
  Serial.print(status_sensor);
  if (status_sensor == 0)
  {
    if (clap == 0)
    {
    detection_range_start = detection_range = millis();
    clap++;
    }
    else if (clap > 0 && millis()-detection_range >= 50)
    {
    detection_range = millis();
    clap++;
    }
  }
  if (millis()-detection_range_start >= 400)
  {
    if (clap == 2)
    {
      if (!status_lights)
      {
      status_lights = true;
      digitalWrite(led, HIGH);
      }
      else if (status_lights)
      {
      status_lights = false;
      digitalWrite(led, LOW);
      }
    }
  clap = 0;
  }
}
