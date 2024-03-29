// Anyhow, here an effect that simulates the moving “eye” of a Cylon: A red “eye” moves from left to
// right and back, over and over again. Kind-a ike a bouncy ball haha.

void CylonBounce(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay)
{

    for (int i = 0; i < NUM_LEDS - EyeSize - 2; i++)
    {
        setAll(0, 0, 0);
        setPixel(i, red / 10, green / 10, blue / 10);
        for (int j = 1; j <= EyeSize; j++)
        {
            setPixel(i + j, red, green, blue);
        }
        setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);
        Reading();
        if (StopIt)
            return;

        showStrip();
        delay(SpeedDelay);
    }

    delay(ReturnDelay);

    for (int i = NUM_LEDS - EyeSize - 2; i > 0; i--)
    {
        setAll(0, 0, 0);
        setPixel(i, red / 10, green / 10, blue / 10);
        for (int j = 1; j <= EyeSize; j++)
        {
            setPixel(i + j, red, green, blue);
        }
        setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);
        Reading();
        if (StopIt)
            return;

        showStrip();
        delay(SpeedDelay);
    }

    delay(ReturnDelay);
}
