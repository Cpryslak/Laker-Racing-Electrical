#include <Arduino.h>

// NOTE: should use enum for states, not #defines, 
//       no difference after compiled
//define states used for switch case
#define NEUTRAL     1
#define UP_SHIFT    2
#define DOWN_SHIFT  3

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

//button struct contains PIN num and current state
struct Button {
  const uint8_t PIN;
  uint32_t numberKeyPresses;
  bool pressed;
};

// The following declares the buttons used for shifting
Button UP_Button = {UP_SHIFT_BTN, 0, false};
Button DOWN_Button = {DWN_SHIFT_BTN, 0, false};

void IRAM_ATTR isr1() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println("Button_Pressed_UP");
}

void IRAM_ATTR isr2() {
  digitalWrite(13, LOW);   // turn the LED on (HIGH is the voltage level)
  Serial.println("Button_Pressed_DOWN");
}

// IDEA: make all global variables into struct to emulate a namespace
int UP_Flag = 0;
int DOWN_Flag = 0;

int state;

// Neutral = 0
// Gears 1-5 = 1-5
int gear = 0;


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
  
  // NOTE: why is this line here?
  digitalWrite(13, LOW);
}

// the loop function runs TO INFINITY AND BEYOND
void loop() {

  // NOTE: states should be a status not what we are currently doing
  switch (state) {
    case NEUTRAL:
      //do some shit
      break;

    case UP_SHIFT:
      //do some shit
      break;

    case DOWN_SHIFT:
      //do some shit
      break;

    default:
      break;
  }

  // NOTE: shouldn't flags be set in irq handler?
  //       Where is the irq handler???
  UP_Flag = digitalRead(UP_Button.PIN);
  DOWN_Flag = digitalRead(DOWN_Button.PIN);
}

void startup() {

}
