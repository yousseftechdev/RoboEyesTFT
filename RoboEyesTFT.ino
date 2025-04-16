#include <TFT_eSPI.h>
#include "RoboEyesTFT_eSPI.h"

TFT_eSPI tft = TFT_eSPI();  // Create TFT instance
// Create a RoboEyes instance (true = portrait, false = landscape)
TFT_RoboEyes roboEyes(tft, false, 3);

bool closed = false;

void setup() {
  tft.init();
  roboEyes.begin(100); // 50 FPS
  // Optionally customize colors:
  roboEyes.setColors(TFT_WHITE, TFT_BLACK);
  // Set modes (e.g., auto blink, idle)
  roboEyes.setAutoblinker(true, 2, 1);
  roboEyes.setIdleMode(true, 4, 0);
  // roboEyes.setPosition(DEFAULT);
  roboEyes.setWidth(64, 64);
  roboEyes.setHeight(64, 64);
  roboEyes.setBorderradius(10, 10);
  roboEyes.setSpacebetween(36);
  // etc.
  pinMode(0, INPUT);
  pinMode(35, INPUT);
}

void loop() {
  roboEyes.update();
  // your other code
  if (digitalRead(0) == LOW) {
    roboEyes.setColors(TFT_GREEN, TFT_BLACK);
    roboEyes.setMood(HAPPY);
  }
  else if (digitalRead(35) == LOW) {
    roboEyes.setColors(TFT_RED, TFT_BLACK);
    roboEyes.setMood(ANGRY);
  }
  else {
    roboEyes.setColors(TFT_WHITE, TFT_BLACK);
    roboEyes.setMood(DEFAULT);
  }
}
