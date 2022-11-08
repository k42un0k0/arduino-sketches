// YWROBOT
// Compatible with the Arduino IDE 1.0
// Library version:1.1
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1)
      delay(10);
  }

  if (!rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  lcd.init(); // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Hello, world!");
}

void loop() {
  DateTime now = rtc.now();
  char buffer[16];
  sprintf(buffer, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());

  lcd.setCursor(8, 1);
  lcd.print(buffer);
  delay(1000);
}
