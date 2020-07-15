void setup()
{
    // EEPROM.write(ShowAdress,showType);
    showType = EEPROM.read(ShowAdress);

    // Mode = EEPROM.read(ModeAdress) ;
    // Saturation = EEPROM.read(SaturationAdress) ;
    // Color = EEPROM.read(ColorAdress) ;
    //  Brightness = EEPROM.read(BrightnessAdress) ;

    randomSeed(analogRead(0));
    a = random(1, 15);
    pinMode(BUTTON_PIN, INPUT);
    pinMode(UP_Pin, INPUT);
    pinMode(DOWN_Pin, INPUT);
    // Serial.begin(9600);
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
    R = Wheel2(color, Brightness, Saturation, 'R');
    G = Wheel2(color, Brightness, Saturation, 'G');
    B = Wheel2(color, Brightness, Saturation, 'B');
}
