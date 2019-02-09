#include "shifting.h"

struct globals gVars;

// Up shift button interrupt handler
void IRAM_ATTR isr1() {
  gVars.upFlag = true;
}

// Down shift button interrupt handler
void IRAM_ATTR isr2() {
  gVrs.dwnFlag = true;
}

void setup() {
  Serial.begin(115200);

  // Setup global variables to default value
  gVars.upBtn = {UP_SHIFT_BTN, 0, false};
  gVars.dwnBtn = {DWN_SHIFT_BTN, 0, false};
  gVars.upFlag = false;
  gVars.dwnFlag = false;

  // Init pins to output LOW
  init();

  // Attach shift pins to interrupt
  pinMode(gVars.upBtn.pin, INPUT_PULLUP);
  attachInterrupt(gVars.upBtn.pin, isr1, FALLING);
  pinMode(gVars.dwnBtn.pin, INPUT_PULLUP);
  attachInterrupt(gVars.dwnBtn.pin, isr2, FALLING);
}

// the loop function runs TO INFINITY AND BEYOND
void loop() {

  // Handle state actions and changes if there was a button pressed
  if(upFlag || downFlag) {
    switch (currentState) {
      case neutral:
        //do some shit
        break;

      case first:
        //do some shit
        break;

      case second:
        //do some shit
        break;

      case third:

        break;

      case fourth:

        break;

      case fifth:

        break;

      default:
        // Error recovory
        break;
    }

    updateLeds();

    gVars.upFlag = false;
    gVars.dwnFlag = false;
  }
}

void startup() {

}
