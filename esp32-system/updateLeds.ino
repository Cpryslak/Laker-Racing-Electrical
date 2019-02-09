/**
 * Turns LED's to show what the current gear is. When in a gear, all 
 * lower gear's lights will be set to be on along with current gear.
 * 
 * param gearState: gear to have the LED's set to indecate.
 */
void updateLeds(enum states gearState) {

  // Turn all LED's off
  digitalWrite(LED_N, LOW);
  digitalWrite(LED_5, LOW);
  digitalWrite(LED_4, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_1, LOW);

  // Fall through switch to turn on LED's for current 
  // gear and all lower gears
  switch(gearState) {
    case neutral:
      digitalWrite(LED_N, HIGH);
      break;

    case fifth:
      digitalWrite(LED_5, HIGH);

    case fourth:
      digitalWrite(LED_4, HIGH);
      

    case third:
      digitalWrite(LED_3, HIGH);
      

    case second:
      digitalWrite(LED_2, HIGH);
      

    case first:
      digitalWrite(LED_1, HIGH);
      break;
  
    default:
      break;
  }
}