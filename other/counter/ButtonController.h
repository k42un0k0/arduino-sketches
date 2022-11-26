#include <Arduino.h>

class ButtonController {
private:
  int _counter = 0;
  int _resetPin;
  int _plusPin;
  int _prevPlusValue = HIGH;
  int _prevResetValue = HIGH;

public:
  ButtonController(int resetPin, int plusPin);
  void analyze();
  int counter();
};