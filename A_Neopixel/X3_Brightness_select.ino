void BrightnessSelect()
{
    while (digitalRead(UP_Pin) == 1)
    {

        if (Brightness > 254)
            Brightness = 255;
        else
            Brightness++;
        R = Wheel2(color, Brightness, Saturation, 'R');
        G = Wheel2(color, Brightness, Saturation, 'G');
        B = Wheel2(color, Brightness, Saturation, 'B');
        setAll(R, G, B);
        delay(15);
    }
    while (digitalRead(DOWN_Pin) == 1)
    {

        if (Brightness < 1)
            Brightness = 0;
        else
            Brightness--;
        R = Wheel2(color, Brightness, Saturation, 'R');
        G = Wheel2(color, Brightness, Saturation, 'G');
        B = Wheel2(color, Brightness, Saturation, 'B');
        setAll(R, G, B);
        delay(15);
    }
}
