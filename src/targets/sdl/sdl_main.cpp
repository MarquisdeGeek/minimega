#include <SDL.h>
#include "emf/emf.h"

// common
#include "sdl_screen.h"
#include "sdl_joypad.h"

#include "platforms/megaprocessor/common/cpp/keypad.h"
#include "platforms/megaprocessor/common/cpp/mega_update.h"


void onKeyDown(int keycode);
void onKeyUp(int keycode);

const int fps = 60;
bool gUpdateScreen = true;
// ClickInterface clicker;


// On timer
Uint32 update(Uint32 interval, void *param) {
    mega_update(fps);
    return interval;
}

// Keyboard mapping
int sdlKeyRemap(int keycode) {
    return keycode > 90 ? keycode - 32 : keycode;
}


// Timer to handle fake keypresses, from mouse
Uint32 fakeKeys(Uint32 interval, void *param) {
    // if (clicker.pumpKeypresses()) {
    //     return interval;
    // }
    return 0;
}




int main(int argc, char* argv[])
{
    const int scale = 1;
    bool bFullScreen = false;
    bool bOnSecondDisplay = false;

    SDL_MegaprocessorScreen megascreen(scale);
    SDL_MegaprocessorJoypad joypad;

    int width = megascreen.getWidth();
    int height = megascreen.getHeight();

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    SDL_Window* window = SDL_CreateWindow("Megaprocessor", 
        bOnSecondDisplay ? SDL_WINDOWPOS_CENTERED_DISPLAY(1) : SDL_WINDOWPOS_UNDEFINED, 
        bOnSecondDisplay ? SDL_WINDOWPOS_CENTERED_DISPLAY(1) : SDL_WINDOWPOS_UNDEFINED, 
        width, height, (bFullScreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0) | SDL_WINDOW_SHOWN);
    // SDL_Surface* screen = SDL_GetWindowSurface(window);
    SDL_Renderer *renderer  =  SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_Surface* pixels = SDL_CreateRGBSurfaceWithFormat(0, width, height,32, SDL_PIXELFORMAT_RGBX8888);

    if (bFullScreen) {
        int w, h;
        SDL_GetWindowSize(window, &w, &h);

        megascreen.setOffset(ScreenPoint((w-width)/2,(h-height)/2));
    }

    SDL_JoystickOpen(0);
    SDL_JoystickEventState(SDL_ENABLE);

    mega_start();

    SDL_AddTimer(1000/fps, update, pixels);

    bool running = true;
    
    while(running)
    {
        SDL_Event ev;
        while (SDL_PollEvent(&ev))
        {
             switch (ev.type) {

                case SDL_QUIT:
                    running = false;
                    mega_end();
                    return 0;

                case SDL_KEYDOWN:
                    if (!ev.key.repeat) {
                        onKeyDown(ev.key.keysym.sym);
                    }
                    break;

                case SDL_KEYUP:
                    onKeyUp(ev.key.keysym.sym);
                    break;

                case SDL_JOYAXISMOTION:
                    joypad.onAxis(ev.jaxis.axis, ev.jaxis.value);
                    break;
                case SDL_JOYBUTTONDOWN:
                    joypad.onDown(ev.jbutton.button);
                    break;
                case SDL_JOYBUTTONUP:
                    joypad.onUp(ev.jbutton.button);
                    break;


                case SDL_MOUSEBUTTONDOWN:
                    if(ev.button.button == SDL_BUTTON_LEFT){
                        int mouseX, mouseY;
                        SDL_GetMouseState(&mouseX, &mouseY);

                        // if (clicker.clickAt(zxscreen, mouseX, mouseY)) {
                        //     SDL_AddTimer(20, fakeKeys, nullptr);
                        // }
                    }
                    break;

                default:
                    break;
            }
        }

 
        if (gUpdateScreen) {
            gUpdateScreen = false;

            megascreen.draw(renderer);
            //
            SDL_RenderPresent(renderer);
        }
    }
}


// Essentially global callbacks...

void memory_trap8cpp(uint16_t addr, uint8_t data) {
    if (addr >= 0xA000 && addr < 0xA100) {
        gUpdateScreen = true;
    }
}


void onKeyDown(int keycode) {
    mega_keypad_onDown(keycode);
}


void onKeyUp(int keycode) {
    mega_keypad_onUp(keycode);
}

