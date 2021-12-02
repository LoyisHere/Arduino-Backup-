#include <Adafruit_NeoPixel.h>
//#define PIN 7//what arduino pin are you using
int lednum = 150;

#define NUM_LEDS      150 // Actual number of LEDs in NeoPixel strip
#define CIRCUMFERENCE 150 // Shoe circumference, in pixels, may be > NUM_LEDS
#define FPS           50 // Animation frames per second
#define LED_DATA_PIN   7 // NeoPixels are connected here
#define MOTION_PIN     0

extern const uint8_t gamma[]; 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(lednum, PIN, NEO_GRB + NEO_KHZ800);

 
struct {//wave code stolen
  uint8_t center;    // Center point of wave in fixed-point space (0 - 255)
  int8_t  speed;     // Distance to move between frames (-128 - +127)
  uint8_t width;     // Width from peak to bottom of triangle wave (0 - 128)
  uint8_t hue;       // Current wave hue (color) see comments later
  uint8_t hueTarget; // Final hue we're aiming for
  uint8_t r, g, b;   // LED RGB color calculated from hue
} wave[] = {
  { 0,  3, 60 },     // Gemma can animate 3 of these on 40 LEDs at 50 FPS
  { 0, -5, 45 },     // More LEDs and/or more waves will need lower FPS
  { 0,  7, 30 }
};













void setup() {
  strip.begin();
  strip.show();
}
void loop() {
  // put your main code here, to run repeatedly:
 strip.fill(strip.Color(0,0,200),0,25);
strip.show();
test(strip.Color(0,0,200),10);

//strip.show();

  


}

void test(uint32_t c, uint8_t wait){

for(int x = 0; x <strip.numPixels(); x = x + 20){  
  for(int y = x + 5; y < x ; y = y + 10){

  strip.fill(c,y,x);
}
}
strip.show();

}






const uint8_t gamma[] PROGMEM = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };
