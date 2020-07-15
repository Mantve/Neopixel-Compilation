void Reading()
{ 
    bool readingFUNC = digitalRead(BUTTON_PIN);
    if (readingFUNC != lastButtonStateFUNC)
    {
        lastDebounceTimeFUNC = millis();
    }

    if ((millis() - lastDebounceTimeFUNC) > debounceDelayFUNC)
    {
        if (readingFUNC != buttonStateFUNC)
        {
            buttonStateFUNC = readingFUNC;
            if (buttonStateFUNC == HIGH)
            {
                Mode++;
                if (Mode > 3)
                    Mode = 0;
                Animacija(Mode);
            }
        }
    }
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
    switch (Mode)
    {
        case 0:
            ModeSelect();
            break;
        case 1:
            ColorSelect();
            break;
        case 2:
            BrightnessSelect();
            break;
        case 3:
            SaturationSelect();
            break;
    }
}
