void SaturationSelect()
{
     while ( digitalRead(UP_Pin) == 1) {
        
      
      if (Saturation > 254)
        Saturation=255;
        else Saturation++;
    R=Wheel2(color, Brightness,Saturation,'R');
  G=Wheel2(color,Brightness,Saturation,'G');
  B=Wheel2(color,Brightness,Saturation,'B');
          setAll(R,G,B);
delay(15);
   }
   while ( digitalRead(DOWN_Pin) == 1) {
        
      
      if (Saturation < 1)
        Saturation=0;
        else Saturation--;
   R=Wheel2(color, Brightness,Saturation,'R');
  G=Wheel2(color,Brightness,Saturation,'G');
  B=Wheel2(color,Brightness,Saturation,'B');
      
          setAll(R,G,B);
          delay(15);

   } 
}

