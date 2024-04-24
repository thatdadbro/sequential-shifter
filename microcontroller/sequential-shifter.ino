#include <Gamepad.h>

Gamepad gp;

int shiftUpPrev, shiftDownPrev;

void setup() {
  pinMode(0,  INPUT_PULLUP); // Shift Up
  pinMode(1,  INPUT_PULLUP); // Shift Down

  shiftUpPrev = digitalRead(0);
  shiftDownPrev = digitalRead(1);
}

void loop() {
  int shiftUp, shiftDown;

  shiftUp = digitalRead(0);
  shiftDown = digitalRead(1);

  if(shiftUp == LOW && shiftUpPrev == HIGH) {
    gp.setButtonState(1, true);
  }
  else {
    gp.setButtonState(1, false);  
  }

  if(shiftDown == LOW && shiftDownPrev == HIGH) {
    gp.setButtonState(0, true);
  }
  else {
    gp.setButtonState(0, false);
  }

  shiftUpPrev = digitalRead(0);
  shiftDownPrev = digitalRead(1);

  delay(50);
}
