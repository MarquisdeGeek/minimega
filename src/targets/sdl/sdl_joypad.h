#ifndef SDL_MEGA_JOYPAD_H
#define SDL_MEGA_JOYPAD_H 1

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_joystick.h>



class SDL_MegaprocessorJoypad {
public:
    SDL_MegaprocessorJoypad();

    void onDown(uint8_t button);
    void onUp(uint8_t button);
    void onAxis(uint8_t axis, int value);

protected:
    const static int MAX_BUTTONS = 32; // to mirror JOY_NUM_BUTTONS

    int getJoypadKeyMap(int button);

    bool m_ButtonState[MAX_BUTTONS];    // used to prevent auto-repeat on the buttons (for weird devices that do it)
};


#endif // SDL_MEGA_JOYPAD_H
