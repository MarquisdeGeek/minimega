/*  Rui Santos & Sara Santos - Random Nerd Tutorials
    THIS EXAMPLE WAS TESTED WITH THE FOLLOWING HARDWARE:
    1) ESP32-2432S028R 2.8 inch 240×320 also known as the Cheap Yellow Display (CYD): https://makeradvisor.com/tools/cyd-cheap-yellow-display-esp32-2432s028r/
      SET UP INSTRUCTIONS: https://RandomNerdTutorials.com/cyd/
    2) REGULAR ESP32 Dev Board + 2.8 inch 240x320 TFT Display: https://makeradvisor.com/tools/2-8-inch-ili9341-tft-240x320/ and https://makeradvisor.com/tools/esp32-dev-board-wi-fi-bluetooth/
      SET UP INSTRUCTIONS: https://RandomNerdTutorials.com/esp32-tft/
    Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files.
    The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*/

#include <SPI.h>

/*  Install the "TFT_eSPI" library by Bodmer to interface with the TFT Display - https://github.com/Bodmer/TFT_eSPI
    *** IMPORTANT: User_Setup.h available on the internet will probably NOT work with the examples available at Random Nerd Tutorials ***
    *** YOU MUST USE THE User_Setup.h FILE PROVIDED IN THE LINK BELOW IN ORDER TO USE THE EXAMPLES FROM RANDOM NERD TUTORIALS ***
    FULL INSTRUCTIONS AVAILABLE ON HOW CONFIGURE THE LIBRARY: https://RandomNerdTutorials.com/cyd/ or https://RandomNerdTutorials.com/esp32-tft/   */
#include <TFT_eSPI.h>

// Install the "XPT2046_Touchscreen" library by Paul Stoffregen to use the Touchscreen - https://github.com/PaulStoffregen/XPT2046_Touchscreen
// Note: this library doesn't require further configuration
#include <XPT2046_Touchscreen.h>

#include "targets/esp/esp_screen.h"

#include "platforms/megaprocessor/common/cpp/mega_update.h"
#include "platforms/megaprocessor/common/cpp/keypad.h"
#include "platforms/megaprocessor/common/cpp/keycodes.h"


TFT_eSPI tft = TFT_eSPI();

// Touchscreen pins
#define XPT2046_IRQ 36   // T_IRQ
#define XPT2046_MOSI 32  // T_DIN
#define XPT2046_MISO 39  // T_OUT
#define XPT2046_CLK 25   // T_CLK
#define XPT2046_CS 33    // T_CS

SPIClass touchscreenSPI = SPIClass(VSPI);
XPT2046_Touchscreen touchscreen(XPT2046_CS, XPT2046_IRQ);

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

// Megaprocessor
void mega_interfaceUp();
void mega_interfaceDown(int x, int y);

const int scale = 5;
const int speedMultiplier = 10;
ESP_MegaScreen mega_screen(scale, false);

ScreenPoint ptOffset;
//
int counter = 0;
bool gUpdateScreen = true;
//
const int fakeKeyCountdownStart = 20;
int fakeKeyCountdown = 0;
//

void setup() {
  Serial.begin(115200);

  // Start the SPI for the touchscreen and init the touchscreen
  touchscreenSPI.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
  touchscreen.begin(touchscreenSPI);
  // Set the Touchscreen rotation in landscape mode
  // Note: in some displays, the touchscreen might be upside down, so you might need to set the rotation to 3: touchscreen.setRotation(3);
  touchscreen.setRotation(0);

  tft.init();
  tft.setRotation(0);
  tft.invertDisplay(true);

  // Our code starts
  ESP_Render renderer;
  renderer.clearScreen(TFT_BLACK);

  mega_start();

  mega_screen.drawUI();
}

const int fps = 60;
const unsigned long frameTime = 1000000 / fps; // ~16666 µs
unsigned long lastFrame = 0;


void loop() {
    unsigned long now = micros();

    if (now - lastFrame >= frameTime) {
        lastFrame += frameTime;
        
        // Update
        if (touchscreen.tirqTouched() && touchscreen.touched()) {
          // Get Touchscreen points
          TS_Point p = touchscreen.getPoint();

          // Calibrate Touchscreen points with map function to the correct width and height
          int x = map(p.x, 200, 3700, 1, SCREEN_HEIGHT);
          int y = map(p.y, 240, 3800, 1, SCREEN_WIDTH);

          mega_interfaceDown(x, y);
        } else {
          mega_interfaceUp();
        }

        // More update
        mega_update(fps);


        // Draw, if any changes made memory
        // (for megaprocessor, this only happens once, as we now have an optimised version)
        if (gUpdateScreen) {
          mega_screen.drawMemoryBoard(&ptOffset);
          gUpdateScreen = false;
        }
    }
}


// Essentially global callbacks...
void memory_trap8cpp(uint16_t addr, uint8_t data) {
  // Optimized routine, suitable for ESP32, since we don't need to
  // wait for the double buffering opportunity
  if (addr >= 0xA000 && addr < 0xA100) {
      mega_screen.drawMemoryAddress(&ptOffset, addr, data);
  }
}


int currentButton = -1;

// REM: They're slipped horizontally
const int buttonKeyMap[] = {
  SDLK_z, SDLK_a,
  SDLK_s, SDLK_w,
  SDLK_d, SDLK_e,
  SDLK_f, SDLK_r,
     SDLK_UP,
SDLK_RIGHT, SDLK_LEFT, 
     SDLK_DOWN
};


void mega_interfaceDown(int x, int y) {
    ScreenRect rc;
    //
    for(int i=0;i<ESP_MegaScreen::buttonCount;++i) {
      mega_screen.getButtonPosition(&rc, i);

      if (x >= rc.x && y >= rc.y && x < rc.x+rc.w && y < rc.y+rc.h) {
        mega_interfaceUp();
        //
        currentButton = i;
        mega_screen.drawButton(currentButton, true);
        mega_keypad_onDown(buttonKeyMap[currentButton]);
      }
    }
}


void mega_interfaceUp() {
  if (currentButton != -1) {
    mega_keypad_onUp(buttonKeyMap[currentButton]);
    mega_screen.drawButton(currentButton, false);
    currentButton = -1;
  }
}


