void startShow(int i)
{
    switch (i)
    {
        case 0:
            FadeInOut(0, 0, 0, 0); // Black/off
            break;
        case 1:
            RGBLoop();
            break;
        case 2:
            FadeInOut(R, G, B, 3);
            break;
        case 3:
            Strobe(R, G, B, 10, 50, 0);
            break;
        case 4:
            CylonBounce(R, G, B, 4, 10, 50);
            break;
        case 5:
            NewKITT(R, G, B, 8, 10, 50);
            break;
        case 6:
            Twinkle(R, G, B, 15, 100, false);
            break;
        case 7:
            TwinkleRandom(15, 10, false);
            break;
        case 8:
            SnowSparkle(R, G, B, 20, random(100, 1000));
            break;
        case 9:
            RunningLights(R, G, B, 50);
            break;
        case 10:
            colorWipe(R, G, B, 50);
            break;
        case 11:
            rainbowCycle(20);
            break;
        case 12:
            theaterChaseRainbow(50);
            break;
        case 13:
            theaterChase(R, G, B, 50);
            break;
        case 14:
            meteorRain(R, G, B, 10, 64, true, 30);
            break;
    }
}
