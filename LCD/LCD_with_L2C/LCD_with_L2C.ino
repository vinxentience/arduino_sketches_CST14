#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  Serial.println("\n I2C Scanner");
}

void loop() {
  // put your main code here, to run repeatedly:
   byte error, address;
   int Devices;
   Serial.println("Scanning...");
   for(address = 1; address < 127; address++){
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if(error == 0){
      Serial.print("I2C device found at address 0x");
      if(address < 16)
      Serial.print("0");
      Serial.println(address, HEX);  
      } 
    }
    if(Devices == 0)
    Serial.println("No I2C devices found \n");
    else
    Serial.println("done \n");
    delay(5000);
}
