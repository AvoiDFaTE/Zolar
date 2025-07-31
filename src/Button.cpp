#include "Button.h"

Button2 Button;

void setupButton() {
  Button.begin(PinButton);
}

void buttonLoop() {
  Button.loop();  
}