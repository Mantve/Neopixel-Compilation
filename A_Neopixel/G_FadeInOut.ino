//Now fading in and out only red, green and blue is nice, but what about fade in and out your own color?



void FadeInOut(byte red, byte green, byte blue, int del){
  float r, g, b;
      
  for(int k = 0; k < 256; k=k+1) { 
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
        Reading();
              if(StopIt) return;

    showStrip();
    delay(del);
  }
     
  for(int k = 255; k >= 0; k=k-2) {
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    Reading();
          if(StopIt) return;

    showStrip();
    delay(del);
  }
}
