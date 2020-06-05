void Reading()
{  // read the state of the switch into a local variable:

    bool readingFUNC = digitalRead(BUTTON_PIN);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (readingFUNC != lastButtonStateFUNC) {
    // reset the debouncing timer
    lastDebounceTimeFUNC = millis();
  }

  if ((millis() - lastDebounceTimeFUNC) > debounceDelayFUNC) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (readingFUNC != buttonStateFUNC) {
      buttonStateFUNC = readingFUNC;

      // only toggle the LED if the new button state is HIGH
      if (buttonStateFUNC == HIGH) {
        
      Mode++;
          

      if (Mode > 3)
        Mode=0;
      Animacija(Mode);
      }
    }
  }

  // set the LED:

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonStateFUNC = readingFUNC;
 /*Serial.println("Mode");
   Serial.println(Mode);
   Serial.println("Show");
   Serial.println(showType);
   Serial.println("Delay");
   Serial.println(millis()-DEBUG);
   DEBUG=millis();
    Serial.println("Brightness");
   Serial.println(Brightness);
   Serial.println("Saturation");
   Serial.println(Saturation);
*/
switch(Mode){
    case 0: ModeSelect(); 
            break;
    case 1: ColorSelect();
            break;
    case 2: BrightnessSelect();
            break;
    case 3: SaturationSelect();
            break;
            }  
  
}
