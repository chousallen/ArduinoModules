/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo;  // create Servo object to control a servo
// twelve Servo objects can be created on most boards

int pulse = 0;    // variable to store the pulse in microseconds in the period of 20ms

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the Servo object
  Serial.begin(115200);
}

void loop() {
  if(Serial.available())
  {
    int tmp = Serial.parseInt(SKIP_ALL, '\n');
    if(tmp >= 700 && tmp <= 2300)
      pulse = tmp;
  }
  myservo.writeMicroseconds(pulse);
}
