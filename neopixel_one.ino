#include <Adafruit_NeoPixel.h>


#ifdef __AVR__
  #include <avr/power.h>
#endif


#define PIN            6
#define NUMPIXELS      1


int delayval = 500;


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
pixels.begin();  
}

void loop() {
  
    pixels.setPixelColor(0, pixels.Color(0,150,0));
    pixels.show();
    delay(delayval);
    pixels.setPixelColor(0, pixels.Color(150,0,0));
    pixels.show();
    delay(delayval);
  }
   
