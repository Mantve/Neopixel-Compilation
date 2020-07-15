/*
This is a variation on the Twinkle() effect.
The only difference is that the colors are now randomly generated, and therefor the first 3 color
parameters are no longer of use and have been removed.

So we use only 3 parameters:

The first parameter (Count) determines how many pixels will be done in one run, where as the second
parameter determines how much time will be paused between individual pixels (speed).

The last parameter (OnlyOne) should be true if you want to see only one LED at a time.
If it’s set to false then all “Count” number of LEDs will be visible (added one at a time)
*/

void TwinkleRandom(int Count, int SpeedDelay, boolean OnlyOne)
{
    setAll(0, 0, 0);

    for (int i = 0; i < Count; i++)
    {
        setPixel(random(NUM_LEDS), random(0, 255), random(0, 255), random(0, 255));
        Reading();
        if (StopIt)
            return;

        showStrip();
        delay(SpeedDelay);
        if (OnlyOne)
        {
            setAll(0, 0, 0);
        }
    }

    delay(SpeedDelay);
}
