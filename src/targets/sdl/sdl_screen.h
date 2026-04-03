#ifndef SDL_MEGA_SCREEN_H
#define SDL_MEGA_SCREEN_H 1

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "emf/emf.h"
#include "targets/common/cpp/screen.h"


class SDL_MegaprocessorScreen {
public:
    SDL_MegaprocessorScreen(int scale);

    virtual int getWidth() const;
    virtual int getHeight() const;

    void setOffset(const ScreenPoint& pt);

    void draw(SDL_Renderer* pSurface);
    
protected:
    int             m_UnitWidth;    // unit = 1 LED, so size of each bit on display memory
    int             m_Scale;        // multiplier for each unit
    ScreenPoint     m_Offset;       // x,y of top left
    bool            m_bLoaded;
    int             m_Gap;
    SDL_Texture*    m_pImageOn;
    SDL_Texture*    m_pImageOff;

    void loadTextures(SDL_Renderer* renderer);
};


#endif // SDL_MEGA_SCREEN_H
