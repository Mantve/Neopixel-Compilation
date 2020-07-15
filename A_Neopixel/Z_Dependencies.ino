void showStrip()
{
#ifdef ADAFRUIT_NEOPIXEL_H
    // NeoPixel
    strip.show();
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
    // FastLED
    FastLED.show();
#endif
}

void setPixel(int Pixel, byte red, byte green, byte blue)
{
#ifdef ADAFRUIT_NEOPIXEL_H
    // NeoPixel
    strip.setPixelColor(Pixel, strip.Color(red, green, blue));
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
    // FastLED
    leds[Pixel].r = red;
    leds[Pixel].g = green;
    leds[Pixel].b = blue;
#endif
}

void setAll(byte red, byte green, byte blue)
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        setPixel(i, red, green, blue);
    }
    showStrip();
}

byte* Wheel(byte WheelPos)
{
    static byte c[3];

    if (WheelPos < 85)
    {
        c[0] = WheelPos * 3;
        c[1] = 255 - WheelPos * 3;
        c[2] = 0;
    }
    else if (WheelPos < 170)
    {
        WheelPos -= 85;
        c[0] = 255 - WheelPos * 3;
        c[1] = 0;
        c[2] = WheelPos * 3;
    }
    else
    {
        WheelPos -= 170;
        c[0] = 0;
        c[1] = WheelPos * 3;
        c[2] = 255 - WheelPos * 3;
    }

    return c;
}


byte Wheel2(byte WheelPos, byte Brightness, byte Saturation, char position)
{
    WheelPos = 255 - WheelPos;
    byte r, g, b;
    if (WheelPos < 85)
    {
        r = (Brightness / 255.0) * (255 - WheelPos * 3);
        g = 0 + (255 - Saturation) * (Brightness / 255.0);
        b = (Brightness / 255.0) * (WheelPos * 3);
        if (r > b)
            b += (r - b) * (255 - Saturation) / 255;
        else
            r += (b - r) * (255 - Saturation) / 255;
    }
    else if (WheelPos < 170)
    {
        WheelPos -= 85;

        r = 0 + (255 - Saturation) * (Brightness / 255.0);
        g = (Brightness / 255.0) * (WheelPos * 3);
        b = (Brightness / 255.0) * (255 - WheelPos * 3);
        if (g > b)
            b += (g - b) * (255 - Saturation) / 255;
        else
            g += (b - g) * (255 - Saturation) / 255;
    }
    else
    {
        WheelPos -= 170;
        r = (Brightness / 255.0) * (WheelPos * 3);
        g = (Brightness / 255.0) * (255 - WheelPos * 3);
        b = 0 + (255 - Saturation) * (Brightness / 255.0);
        if (r > g)
            g += (r - g) * (255 - Saturation) / 255;
        else
            r += (g - r) * (255 - Saturation) / 255;
    }
    switch (position)
    {
        case 'R':
            return r;
        case 'G':
            return g;
        default:
            return b;
    }
}
