#include "shifting.h"

/**
 * Sets all pins needed to output low.
 */
void init() {
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
  pinMode(SHIFT_CUT, OUTPUT);
  pinMode(Launch, OUTPUT);
}
