void updateLeds() {

  // Turn all LED's off
  digitalWrite(LED_N, LOW);
  digitalWrite(LED_5, LOW);
  digitalWrite(LED_4, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_1, LOW);

  // Fall through switch to turn on LED's for current 
  // gear and all lower gears
  switch(currentState)
  {
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