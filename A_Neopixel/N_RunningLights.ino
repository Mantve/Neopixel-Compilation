/*This effect makes multiple groups of LEDs chase each other. Kind-a like the running lights you’d
use to see in stores during the holidays.

It takes 4 parameters, of which the first 3 define the color (roughly).
The last parameter indicates how much delay is put in the loop, the higher the number, the slower it
will go*/

void RunningLights(byte red, byte green, byte blue, int WaveDelay)
{
    int Position = 0;

    for (int i = 0; i < NUM_LEDS * 2; i++)
    {
        Position++; // = 0; //Position + Rate;
        for (int i = 0; i < NUM_LEDS; i++)
        {
            // sine wave, 3 offset waves make a rainbow!
            // float level = sin(i+Position) * 127 + 128;
            // setPixel(i,level,0,0);
            // float level = sin(i+Position) * 127 + 128;
            setPixel(i, ((sin(i + Position) * 127 + 128) / 255) * red,
                ((sin(i + Position) * 127 + 128) / 255) * green,
                ((sin(i + Position) * 127 + 128) / 255) * blue);
        }
        Reading();
        if (StopIt)
            return;

        showStrip();
        delay(WaveDelay);
    }
}
