void ColorSelect()
{
 while ( digitalRead(UP_Pin) == 1) {
        
      color++;
      if (color == 255)
        color=0;
  R=Wheel2(color, Brightness,Saturation,'R');
  G=Wheel2(color,Brightness,Saturation,'G');
  B=Wheel2(color,Brightness,Saturation,'B');
          setAll(R,G,B);
delay(15);
   }
   while ( digitalRead(DOWN_Pin) == 1) {
        
      color--;
      if (color ==0)
        color=255;
  R=Wheel2(color, Brightness,Saturation,'R');
  G=Wheel2(color,Brightness,Saturation,'G');
  B=Wheel2(color,Brightness,Saturation,'B');
      
          setAll(R,G,B);
          delay(15);

   }  
}
