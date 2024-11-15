//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello");
  lcd.setCursor(0, 1);
  lcd.print("I am a counter!");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Counter: ");
}

char str[16];

void loop()
{
  lcd.setCursor(0, 1);
  sprintf(str, "Count: %5d", millis()/1000);
  lcd.print(str);
  delay(50);
}
