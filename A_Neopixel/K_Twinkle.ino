/*This effect will blink one or more LEDs in a given color.
The function takes the usual color parameters, which you can determine with the Color Picker.

The 4th parameter (Count) determines how many pixels will be done in one run, where as the 5th parameter determines how much time will be paused between individual pixels (speed).

The 6th parameter (OnlyOne) should be true if you want to see only one LED at a time.
If it’s set to false then all “Count” number of LEDs will be visible (added one at a time).
*/


void Twinkle(byte red, byte green, byte blue, int Count, int SpeedDelay, boolean OnlyOne) {
  setAll(0,0,0);
  
  for (int i=0; i<Count; i++) {
     setPixel(random(NUM_LEDS),red,green,blue);
     Reading();
           if(StopIt) return;

     showStrip();
     delay(SpeedDelay);
     if(OnlyOne) { 
       setAll(0,0,0); 
     }
   }
  
  delay(SpeedDelay);
}
