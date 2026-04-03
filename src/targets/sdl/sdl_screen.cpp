#include "sdl_screen.h"
#include <SDL2/SDL_image.h>

#include "platforms/megaprocessor/common/cpp/memory.h"


SDL_MegaprocessorScreen::SDL_MegaprocessorScreen(int scale) : m_Scale(scale), m_UnitWidth(8), m_Offset(ScreenPoint(0,0)), m_bLoaded(false), m_Gap(0) {
    // nop
    // 32x64 LEDs
    // On CYD, we have 5x5 LEDs producing
    // 160x320 coverage
    // with 80 px on RHS (or 40px on L&R) to put buttons
}


void
SDL_MegaprocessorScreen::loadTextures(SDL_Renderer* renderer) {
    if (!m_bLoaded) {
        SDL_Surface* surface  = IMG_Load("res/on.dat.png");
        m_pImageOn = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        surface  = IMG_Load("res/off.dat.png");
        m_pImageOff = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        m_bLoaded = true;
    }
}


int
SDL_MegaprocessorScreen::getWidth() const {
    return 32 * m_Scale * m_UnitWidth + m_Gap;
}


int
SDL_MegaprocessorScreen::getHeight() const {
    return 64 * m_Scale * m_UnitWidth;
}


void
SDL_MegaprocessorScreen::setOffset(const ScreenPoint& pt) {
    m_Offset = pt;
}


void SDL_MegaprocessorScreen::draw(SDL_Renderer* renderer) {
    if (!m_bLoaded) {
        loadTextures(renderer);
    }
    //
    int startAddress = 0xA000; // i.e. 40960
    int unitActualSize =  m_Scale * m_UnitWidth;

    for(int y=0;y<64;++y) {
        for(int x=0;x<32;++x) {
            int addr = startAddress + x/8 + y*4;
            uint8_t byte = read8(addr);
            uint8_t mask = 1 << (x&7);
            int sx = m_Offset.x + x * unitActualSize;
            int sy = m_Offset.y + y * unitActualSize;

            SDL_Rect texr = { sx, sy, unitActualSize, unitActualSize};
            SDL_RenderCopy(renderer, byte & mask ? m_pImageOn : m_pImageOff, nullptr, &texr);
        }
    }
}

