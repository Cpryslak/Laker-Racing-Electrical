
/** Defines */

#ifndef LED_N
#define LED_N (16)
#endif

#ifndef LED_1
#define LED_1 (10)
#endif

#ifndef LED_2
#define LED_2 (11)
#endif

#ifndef LED_3
#define LED_3 (12)
#endif

#ifndef LED_4
#define LED_4 (13)
#endif

#ifndef LED_5
#define LED_5 (14)
#endif

#ifndef LED_LC
#define LED_LC (17)
#endif

#ifndef UP_SHIFT_BTN
#define UP_SHIFT_BTN (22)
#endif

#ifndef DWN_SHIFT_BTN
#define DWN_SHIFT_BTN (23)
#endif

#ifndef SHIFT_CUT
#define SHIFT_CUT (18)
#endif

#ifndef LAUNCH
#define LAUNCH (19)
#endif

/** Structs and Enum Definitions */
enum states{
  first,
  second,
  third,
  fourth,
  fifth,
  neutral
};

/** Header Funcion Definitions */
#ifndef INIT
#define INIT
    void init();
#endif

#ifndef UPDATE_LEDS
#define UPDATE_LEDS
    void updateLeds();
#endif
