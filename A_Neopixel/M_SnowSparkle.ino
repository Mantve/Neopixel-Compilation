/*This variant of Sparkle is intended to look like snow with to occasional sparkle.

Having snow in mind, the first 3 parameters (the background color) should be a more dim white and that’s why I choose 10 10 10 – but feel free to pick your own color.

The 4th parameter, SparkleDelay, indicates how long a “sparkle” will be visible. Do not set it too short, otherwise you’d barely notice anything happening.

The last parameter indicates how much time should be waited after a sparkle has been made visible and has been removed.
*/

void SnowSparkle(byte red, byte green, byte blue, int SparkleDelay, int SpeedDelay) {
  setAll(red,green,blue);
  
  int Pixel = random(NUM_LEDS);
  setPixel(Pixel,0xff,0xff,0xff);
  Reading(); if(StopIt) return;
  showStrip();
  delay(SparkleDelay);
  setPixel(Pixel,red,green,blue);
  Reading();      if(StopIt) return;

  showStrip();
  delay(SpeedDelay);
}
