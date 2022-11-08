#include <MsTimer2.h>
// pin
int RESET = 3;
int PLUS = 2;

// global values
int counter = 0;

// for controlling button
int prevPlusValue = HIGH;
int prevResetValue = HIGH;
void analyzeButtonState();

// arduino functions
void setup() {
  Serial.begin(9600);
  Serial.println("Counter Start!");
  pinMode(RESET, INPUT_PULLUP);
  pinMode(PLUS, INPUT_PULLUP);
  MsTimer2::set(50, analyzeButtonState);
  MsTimer2::start();
}
void loop() {
  Serial.println(counter);
  delay(1000);
}

// implements
void analyzeButtonState() {
  int resetValue = digitalRead(RESET);
  if (resetValue == LOW && resetValue != prevResetValue) {
    Serial.println("Reset!");
    counter = 0;
  }
  prevResetValue = resetValue;
  int plusValue = digitalRead(PLUS);
  if (plusValue == LOW && plusValue != prevPlusValue) {
    Serial.println("Plus!");
    counter++;
  }
  prevPlusValue = plusValue;
};