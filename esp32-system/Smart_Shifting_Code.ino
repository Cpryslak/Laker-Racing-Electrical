#include "shifting.h"

// The following declares the buttons used for shifting
Button UP_Button = {UP_SHIFT_BTN, 0, false};
Button DOWN_Button = {DWN_SHIFT_BTN, 0, false};

// Up shift button interrupt handler
void IRAM_ATTR isr1() {
  upFlag = true;
}

// Down shift button interrupt handler
void IRAM_ATTR isr2() {
  downFlag = true;
}

// NOTE: make all global variables into struct to emulate a namespace
bool upFlag = 0;
bool downFlag = 0;

enum states currentState;
enum states lastState;


void setup() {
  Serial.begin(115200);

  // Init pins to output LOW
  init();

  // Attach shift pins to interrupt
  pinMode(UP_Button.PIN, INPUT_PULLUP);
  attachInterrupt(UP_Button.PIN, isr1, FALLING);
  pinMode(DOWN_Button.PIN, INPUT_PULLUP);
  attachInterrupt(DOWN_Button.PIN, isr2, FALLING);
  
  // Set starting state
  currentState = neutral;
  lastState = neutral;
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
  }
}

void startup() {

}
