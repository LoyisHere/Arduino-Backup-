#include "FastLED.h"
#include <Adafruit_NeoPixel.h>
#define NUM_LEDS 150
#define DATA_PIN 7

CRGB leds[NUM_LEDS];

void setup() {
    
    delay(100);

     FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
 

     FastLED.setBrightness(CRGB(200,200,200));
}

void loop() {
    leds[6] = CRGB(0,0,0);
//leds is the default name for LEDS no need to declare
//appears to behave like an array that we must declare the length for

int r,g,b;
r = 100;
g = 100;
b = 100;

singleLaser(r,g,b);
    
}



void singleLaser(int r, int g, int b){


      for(int x = 0; x < 10; x++){//big loop
          for(int y = 0; y < NUM_LEDS ; y = y +10){
           leds[x+y] = CRGB(r,g,b);
          }

          
       FastLED.show();
/*          leds[x-10]=CRGB(255,0,0);
          delay(20);
*/          
         }

  
}
