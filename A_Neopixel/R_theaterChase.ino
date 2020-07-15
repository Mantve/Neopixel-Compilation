void theaterChase(byte red, byte green, byte blue, int SpeedDelay)
{
    for (int j = 0; j < 10; j++) // do 10 cycles of chasing
    { 
        for (int q = 0; q < 3; q++)
        {
            for (int i = 0; i < NUM_LEDS; i = i + 3)
            {
                setPixel(i + q, red, green, blue); // turn every third pixel on
            }
            Reading();
            if (StopIt)
                return;

            showStrip();

            delay(SpeedDelay);

            for (int i = 0; i < NUM_LEDS; i = i + 3)
            {
                setPixel(i + q, 0, 0, 0); // turn every third pixel off
            }
        }
    }
}
