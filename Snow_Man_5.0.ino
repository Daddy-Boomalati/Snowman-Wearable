#include <Adafruit_NeoPixel.h>
// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN 1

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 4

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

int brightness;
int redVal=0;
unsigned long previousMillis=0;
unsigned long currentMillis;
unsigned long currentTimer;
unsigned long previousTimer;
unsigned long currentPause;
unsigned long previousPause;
int delayTimer;

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

}

void loop() {

currentMillis=millis();
previousMillis=currentMillis;  
currentTimer=millis();
previousTimer=currentTimer;
//currentPause=millis();
//previousPause=currentPause;
//redVal=0;
delayTimer=0;

while (delayTimer<=1600) {  
  currentMillis=millis();
  currentPause=millis();
 
  if (currentPause-previousPause<1000){
  strip.setPixelColor(0,0,0,0);
  }
  
  if (currentPause-previousPause>=1000&&currentMillis-previousMillis>10){
  redVal++;
  previousMillis=currentMillis;
  }

  if (currentPause-previousPause>=1000){
  strip.setPixelColor(0, redVal, 0, 0);
  }
    
  if (redVal>150){
  redVal=0;
  previousPause=currentPause;
  }
  
  currentTimer=millis();
  delayTimer=currentTimer-previousTimer;
  //Set One
  if (delayTimer<400){
  strip.setPixelColor(3, 0, 0, 10); // blue
  strip.setPixelColor(2, 0, 10, 0); // green
  strip.setPixelColor(1, 10, 10, 10); // white
  strip.show();
  }
  
  //Set Two
  if (delayTimer>=400&&delayTimer<800){
  strip.setPixelColor(3, 0, 10, 0); // green
  strip.setPixelColor(2, 10, 10, 10); // white
  strip.setPixelColor(1, 10, 0, 0); // red
  strip.show(); 
  }
  
  //Set Three
  if (delayTimer>=800&&delayTimer<1200){
  strip.setPixelColor(3, 10, 10, 10); // white
  strip.setPixelColor(2, 10, 0, 0); // red
  strip.setPixelColor(1, 0, 0, 10); // blue
  strip.show();
  }
  
  //Set Four
  if (delayTimer>=1200&&delayTimer<=1600){
  strip.setPixelColor(3, 10, 0, 0); // red
  strip.setPixelColor(2, 0, 0, 10); // blue
  strip.setPixelColor(1, 0, 10, 0); // green
  strip.show();
  }
  
} 
}
