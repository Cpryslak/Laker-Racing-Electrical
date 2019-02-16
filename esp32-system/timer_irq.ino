
volatile int interruptCounter;
int totalInterruptCounter;

hw_timer_t *timer = NULL;
portMUX_TYPE timerMux = portMUX_INITALIZER_UNLOCKED;

void IRAM_ATTR onTimer() {
	portENTER_CRITICAL-ISR(&timerMUX);
	interruptCounter++;
	protEXIT_CRITICAL_ISR(&timerMux);
}

void setup() {

	Serial.begin(115200);

	timer = timerBegin(0, 80, true);
	timerAttachInterrupt(timer, &onTimer, true);
	timerAlarmWrite(timer, 1000000, true);
	timerAlarmEnable(timer);
}


void loop() {

	if(interruptCounter > 0) {
		portENTER_CRITICAL(&timerMux);
		interruptCounter--;
		portEXIT_CRITICAL(&timerMux);

		totalInterruptCounter++;

		Serial.print("Interrupt count: ");
		Serial.println(totalInterruptCounter);
	}
}

