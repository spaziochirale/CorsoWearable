
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6

#define NUMPIXELS     3


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 1000; 

void setup() {
 pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  
pixels.setPixelColor(0, pixels.Color(0,150,0)); 
 //pixels.setPixelColor(3, pixels.Color(0,0,255)); 
   //pixels.setPixelColor(7, pixels.Color(255,0,0)); 
   pixels.setPixelColor(1, pixels.Color(0,150,0)); 
 pixels.setPixelColor(2, pixels.Color(0,0,255)); 
   //pixels.setPixelColor(5, pixels.Color(255,0,0)); 
 //pixels.setPixelColor(6, pixels.Color(0,150,0)); 
 //pixels.setPixelColor(4, pixels.Color(0,120,125)); 
  
 pixels.show();



 
}
