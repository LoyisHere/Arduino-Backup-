#include <Adafruit_NeoPixel.h>
#define PIN 7//what arduino pin are you using
int BUTTON = 2;
int counter = 0;
int state = 0;
int potVal = 0;
int potVal2 = 0;
int potVal3 = 0;
int potLocR = A0;
int potLocG = A1;
int potLocB = A2;
int red = 0;
int blue = 0;
int green= 0;
//The speed the LEDs fade to black if not relit
float fade_scale = 1.2;
int timer = 30;
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//Just some tippers for you on how to run this 
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(150, PIN, NEO_GRB + NEO_KHZ800);



//setPixelColor(p, c);
//setPixelColor(p, r, g, b);
//Parameters
//p [uint8_t]: The pixel to set, 0 to 9.
//c [uint32_t]: 24-bit RGB color value, 0xRRGGBB.
//r [uint8_t]: 8-bit red value, 0 to 255.
//g [uint8_t]: 8-bit green value, 0 to 255.
//b [uint8_t]: 8-bit blue value, 0 to 255.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(450, PIN, NEO_GRB + NEO_KHZ800);
//150 

void setup() {
  pinMode(BUTTON,INPUT);
  Serial.begin(9600); strip.setBrightness(255);
  strip.begin();//initializes strip
//  strip.setBrightness(10);//Optional but the LEDs will be maxed out
 //commented out for potentiometer 
  strip.show(); // Initialize all pixels to 'off'// basically resets the strip
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {
  // Some example procedures showing how to display to the pixels:
  //functionname(stripname.Color( Red,Green,Blue),Persistance) 0-255, keep below 200 to limit intensity also
 /*
  colorWipe(strip.Color(100, 0, 0), 100); // Red
  colorWipe(strip.Color(0, 100, 0), 50); // Green
  colorWipe(strip.Color(0, 0, 100), 10); // Blue
  //c [uint32_t]: 24-bit RGB color value, 0xRRGGBB.
*/

/*
 potVal = analogRead(potLoc);
 SUN = map(potVal,0,1023, 0,255);
 strip.setBrightness(potVal);//Optional but the LEDs will be maxed out

timer = 15;
*/

 potVal = analogRead(potLocR);
 red = map(potVal,0,1023, 0,255);
 strip.setBrightness(potVal);//Optional but the LEDs will be maxed out
 potVal2 = analogRead(potLocG);
 green = map(potVal2,0,1023, 0,255);
  potVal3 = analogRead(potLocB);
 blue = map(potVal3,0,1023, 0,255);


theaterChase(strip.Color(red, green, blue), 96); // Red

/*
state = digitalRead(BUTTON);
if(state == 1){
  
  delay(100);
  counter++;
  if(counter > 11){counter = 0;}

}
  
 */   
//Serial.println(counter);

Serial.println(red);
Serial.println(green);
Serial.println(blue);

switch(counter){
   case 0:
   theaterChase(strip.Color(red, green, blue), timer); // Red
   break;
   
   case 1:
      colorWipe(strip.Color(red, green, blue), timer); // Red
   break;

   case 2:
   rainbow(timer);
   break;

   case 3:
   rainbowCycle(timer);
   break;

   case 4:
   theaterChaseRainbow(timer);
   break;
}
}//end of loop


// Uint# variants just stand for unsigned ints, the size corresponds to 
// the max size limit, not to worry to moch
// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    //delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    
    //delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    //delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  
    for (int q=0; q < 10; q++) {//for every 10 
      for (uint16_t i=0; i < strip.numPixels(); i=i+10) { //cycles through the whole strip
        strip.setPixelColor(i+q, c);//
        //turn every 5th pixel on
        strip.setPixelColor(i+q+2, c);   
      }
      strip.show();
      //delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      //delay(1);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
