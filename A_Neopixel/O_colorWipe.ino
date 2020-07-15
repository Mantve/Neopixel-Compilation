// It sets one LED after the other to a give color. The result being a full strip in a given color
// if you’d run it only once.
void colorWipe(byte red, byte green, byte blue, int SpeedDelay)
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        setPixel(i, red, green, blue);
        Reading();
        if (StopIt)
            return;

        showStrip();
        delay(SpeedDelay);
    }
}
