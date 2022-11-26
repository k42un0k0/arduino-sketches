#include "ButtonController.h"

ButtonController::ButtonController(int resetPin, int plusPin) {
  _resetPin = resetPin;
  _plusPin = plusPin;
};
void ButtonController::analyze() {
  int resetValue = digitalRead(_resetPin);
  if (resetValue == LOW && resetValue != _prevResetValue) {
    Serial.println("Reset!");
    _counter = 0;
  }
  _prevResetValue = resetValue;
  int plusValue = digitalRead(_plusPin);
  if (plusValue == LOW && plusValue != _prevPlusValue) {
    Serial.println("Plus!");
    _counter++;
  }
  _prevPlusValue = plusValue;
}
int ButtonController::counter() { return _counter; }