//With this effect, we use fixed colors for all LEDs, in sequence: Red, Green and Blue.
//We will slowly increase brightness and when the maximum brightness has been reached, we will start decreasing the brightness again until the LEDs are OFF.
void RGBLoop(){
  for(int j = 0; j < 3; j++ ) { 
    // Fade IN
    for(int k = 0; k < 256; k++) { 
      switch(j) { 
        case 0: setAll(k,0,0); break;
        case 1: setAll(0,k,0); break;
        case 2: setAll(0,0,k); break;
      }
      Reading();
            if(StopIt) return;

      showStrip();
      delay(3);
    }
    // Fade OUT
    for(int k = 255; k >= 0; k--) { 
      switch(j) { 
        case 0: setAll(k,0,0); break;
        case 1: setAll(0,k,0); break;
        case 2: setAll(0,0,k); break;
      }
      Reading();
      if(StopIt) return;
      showStrip();
      delay(3);
    }
  }
}
