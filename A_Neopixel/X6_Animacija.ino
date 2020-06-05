void Animacija (byte a)
{
    switch(a){
    case 0: 
    for(int i=0; i<NUM_LEDS; i++)
      {
        setAll(0,0,0);
        setPixel(i,255,255,255);
         showStrip();
        delay(2);
      }
      for(int i=NUM_LEDS; i>0; i--)
      {
        setAll(0,0,0);
        setPixel(i,255,255,255);
         showStrip();
        delay(2);
      }
            break;
    case 1: 
    
     for(int i=0; i<256; i+=2)
      {
        setAll(Wheel2(i,255,255,'R'),Wheel2(i,255,255,'G'),Wheel2(i,255,255,'B'));
        delay(1);
      }

            break;
    case 2: 
       for(int i=0; i<256; i+=2)
      {
        setAll(Wheel2(color,i,255,'R'),Wheel2(color,i,255,'G'),Wheel2(color,i,255,'B'));
        delay(1);
      }
       for(int i=255; i>=0; i-=2)
      {
        setAll(Wheel2(color,i,255,'R'),Wheel2(color,i,255,'G'),Wheel2(color,i,255,'B'));
        delay(1);
      }
            break;
    case 3: 
    for(int i=0; i<256; i+=2)
      {
        setAll(Wheel2(color,255,i,'R'),Wheel2(color,255,i,'G'),Wheel2(color,255,i,'B'));
        delay(1);
      }
        for(int i=255; i>=0; i-=2)
      {
        setAll(Wheel2(color,255,i,'R'),Wheel2(color,255,i,'G'),Wheel2(color,255,i,'B'));
        delay(1);
      }
            break;
        }  

}

