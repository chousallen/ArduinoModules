#define ADDR 0x27

#include <Wire.h>

void setup() {
  Serial.begin(115200);
  
  Wire.begin(ADDR);
  
  
}

uint8_t val = 0;
char str[4];

void loop() {
  if(Serial.read() > 0)
  {
    Wire.beginTransmission(ADDR);
    Wire.write(val);
    Wire.endTransmission();
    sprintf(str, "%02x", val);
    Serial.println(str);
    val = (val+1)|0x08;
  }
}
