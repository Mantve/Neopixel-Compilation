void ModeSelect()
{
    bool readingUP = digitalRead(UP_Pin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (readingUP != lastButtonStateUP) {
    // reset the debouncing timer
    lastDebounceTimeUP = millis();
  }

  if ((millis() - lastDebounceTimeUP) > debounceDelayUP) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (readingUP != buttonStateUP) {
      buttonStateUP = readingUP;

      // only toggle the LED if the new button state is HIGH
      if (buttonStateUP == HIGH) {
        
      showType++;
      if (showType > 15)
        showType=0;
        EEPROM.write(ShowAdress, showType) ;
        lastButtonStateUP = readingUP;
        StopIt=true;
        
       setAll(0,0,0);
            showStrip();

        return;
      }
    }
  }

  // set the LED:

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonStateUP = readingUP;
  





   bool readingDOWN = digitalRead(DOWN_Pin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (readingDOWN != lastButtonStateDOWN) {
    // reset the debouncing timer
    lastDebounceTimeDOWN = millis();
  }

  if ((millis() - lastDebounceTimeDOWN) > debounceDelayDOWN) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (readingDOWN != buttonStateDOWN) {
      buttonStateDOWN = readingDOWN;

      // only toggle the LED if the new button state is HIGH
      if (buttonStateDOWN == HIGH) {
        
      showType--;
      if (showType < 0)
        showType=15;
        EEPROM.write(ShowAdress, showType) ;
 lastButtonStateUP = readingUP;
        StopIt=true;
        
       setAll(0,0,0);
            showStrip();

        return;
      }
    }
  }

  // set the LED:

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonStateDOWN = readingDOWN;
  
}
