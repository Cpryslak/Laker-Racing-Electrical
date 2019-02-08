#include <Arduino.h>

//define pins that gear LEDs are on
#define LED_1 10
#define LED_2 11
#define LED_3 12
#define LED_4 13
#define LED_5 14

//define pins that other LEDs are on
#define LED_N  16
#define LED_LC 17

// Define pins for shifting buttons
#define UP_SHIFT_BTN  (22)
#define DWN_SHIFT_BTN (23)

#define SHIFT_CUT (18)
#define LAUNCH    (19)

enum states{
  first,
  second,
  third,
  fourth,
  fifth,
  neutral
};

//button struct contains PIN num and current state
struct Button {
  const uint8_t PIN;
  uint32_t numberKeyPresses;
  bool pressed;
};

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
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
  digitalWrite(LED_5, LOW);
  digitalWrite(LED_N, LOW);
  digitalWrite(LED_LC, LOW);
  digitalWrite(SHIFT_CUT, LOW);
  digitalWrite(LAUNCH, LOW);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
  pinMode(LED_N, OUTPUT);
  pinMode(LED_LC, OUTPUT);
  pinMode(Shift_Cut, OUTPUT);   //Where is this going?
  pinMode(Launch, OUTPUT);      //Where is this going?

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

void updateLeds() {

  // NOTE: use fall through switch-case to turn on 
  //    LED's for current gear and all lower gear LED's?
  switch(currentState)
  {
    case neutral:
      
      break;

    case first:

      break;

    case second:

      break;

    case third:

      break;

    case fourth:

      break;

    case fifth:

      break;
  
    default:
      break;
  }
}