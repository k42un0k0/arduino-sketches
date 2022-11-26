#include "ButtonController.h"
#include <MsTimer2.h>
// pin
int RESET = 3;
int PLUS = 2;

ButtonController bc(RESET, PLUS);

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
  Serial.println(bc.counter());
  delay(1000);
}

// implements
void analyzeButtonState() { bc.analyze(); };