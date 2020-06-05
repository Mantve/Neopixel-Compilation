// This is a demonstration on how to use an input device to trigger changes on your neo pixels.
// You should wire a momentary push button to connect from ground to a digital IO pin.  When you
// press the button it will change to a new pixel animation.  Note that you need to press the
// button once to start the first animation!

#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>
#define BUTTON_PIN   8    // Digital IO pin connected to the button.  This will be
                          // driven with a pull-up resistor so the switch should
                          // pull the pin to ground momentarily.  On a high -> low
                          // transition the button press logic will execute.
#define UP_Pin  9    // the pin that the Up pushbutton is attached to
#define DOWN_Pin  12   // the pin that the Down pushbutton is attached to
#define PIXEL_PIN   11    // Digital IO pin connected to the NeoPixels.

#define NUM_LEDS 48

// Parameter 1 = number of pixels in strip,  neopixel stick has 8
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream, correct for neopixel stick
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip), correct for neopixel stick
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

byte showType = 0;
byte Mode=0;
byte Brightness=255;
byte Saturation=255;
// Variables will change:

//UpMode
bool buttonStateUP;             // the current reading from the input pin
bool lastButtonStateUP = LOW;   // the previous reading from the input pin
// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTimeUP = 0;  // the last time the output pin was toggled
unsigned long debounceDelayUP = 50;    // the debounce time; increase if the output flickers
//DownMode
bool buttonStateDOWN;             // the current reading from the input pin
bool lastButtonStateDOWN = LOW;   // the previous reading from the input pin
// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTimeDOWN = 0;  // the last time the output pin was toggled
unsigned long debounceDelayDOWN = 50;    // the debounce time; increase if the output flickers
//FuncMode
bool buttonStateFUNC;             // the current reading from the input pin
bool lastButtonStateFUNC = LOW;   // the previous reading from the input pin
// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTimeFUNC = 0;  // the last time the output pin was toggled
unsigned long debounceDelayFUNC = 50;    // the debounce time; increase if the output flickers
int color=0;
unsigned long RandomTime=0;
byte R,G,B;
int a;
//unsigned long DEBUG=0;
bool StopIt = false;
byte ShowAdress = 0;
byte ModeAdress = 1;
byte SaturationAdress = 2;
byte ColorAdress = 3;
byte BrightnessAdress = 4;
