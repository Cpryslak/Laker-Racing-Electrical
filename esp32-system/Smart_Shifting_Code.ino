#include <Arduino.h>

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
#define UP_SHIFT_BTN (22)
#define DWN_SHIFT_BTN (23)

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


int Shift_Cut = 18;   //assuming wired direct to ECU?
int Launch = 19;      //assuming wired direct to ECU?

int UP_Flag = 0;
int DOWN_Flag = 0;

int state;

int gear = 0;
// Neutral = 0
// Gears 1-5 = 1-5

void setup() {
  Serial.begin(115200);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
  pinMode(LED_N, OUTPUT);
  pinMode(LED_LC, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(Shift_Cut, OUTPUT);   //Where is this going?
  pinMode(Launch, OUTPUT);      //Where is this going?

  pinMode(UP_Button.PIN, INPUT_PULLUP);
  attachInterrupt(UP_Button.PIN, isr1, FALLING);
  pinMode(DOWN_Button.PIN, INPUT_PULLUP);
  attachInterrupt(DOWN_Button.PIN, isr2, FALLING);
  
  digitalWrite(13, LOW);
}

// the loop function runs TO INFINITY AND BEYOND
void loop() {

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

  UP_Flag = digitalRead(UP_Button.PIN);
  DOWN_Flag = digitalRead(DOWN_Button.PIN);
}

void startup() {

}
