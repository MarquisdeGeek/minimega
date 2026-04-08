#include "emf/emf.h"

#include "platforms/megaprocessor/common/cpp/memory.h"

#include "esp_screen.h"

#include <TFT_eSPI.h>

extern TFT_eSPI tft;
const bool prettyLED5 = true;


// 1. Renderer class wraps ESP
ESP_Render::ESP_Render() {
    // nop
}

// TODO: Find out why I get "Guru Meditation Error" when using this abstraction
void
ESP_Render::fillRect(int x, int y, int w, int h, uint32_t col) {
    tft.fillRect(x, y, w, h, col);
}


void
ESP_Render::clearScreen(uint32_t col) {
    tft.fillRect(
        0,0,
        240,320,
        col
    );
}



// 2. Our chess- and ESP-specific
ESP_MegaScreen::ESP_MegaScreen(int scale, bool showComparison) : CommonScreen(scale, showComparison) {
    m_ifaceWidth = m_Scale * m_fontWidth * 10; // 10=8 board + 2 edge
    m_ifaceHeight = m_Scale * m_fontHeight * 11; // 11=8 board + 1 ABC notation + 2 edge

    m_gapX = m_gapY = 0;
}

/*
Order is:

0 1
2 3
4 5
6 7

 8
9 10
 11

 But note that the RHS of the screen is X=0, so they're flipped horizontally
*/
void 
ESP_MegaScreen::getButtonPosition(ScreenRect* pRect, int idx) const {
    // First 8 are in pairs
    int x = 32 * 5;
    int y = 20;
    int w = 32;
    int h = 32;

    if (idx < 8) {
        // 2nd column
        x += 40 * (idx & 1);
        // std spacing
        x += 12/2;

        // and down
        y += 40 * (idx / 2);
        y += 8;
    } else if (idx < 12) {
        // the dpad
        // first X's
        switch(idx) {
            case 8: // up
            case 11: // down
            x += 40 - w/2;
            break;

            case 9: // left
            case 10: // right
            x += 12/2;
            x += 40 * (idx & 1);
            break;
        }
        // then Y's
        switch(idx) {
            case 8: // up
            y += 40*5;
            break;

            case 10: // right
            case 9: // left
            y += 40*6;
            break;

            case 11: // down
            y += 40 * 7;
            break;
        }
        y -= 20;
    }

    pRect->x = x;
    pRect->y = y;
    pRect->w = w;
    pRect->h = h;
}


void
ESP_MegaScreen::drawButton(int idx, bool state) {
    ScreenRect rc;
    //
    getButtonPosition(&rc, idx);
    //
    uint32_t col = state ? TFT_BLUE : TFT_PINK;

    tft.fillRect(
        rc.x, rc.y,
        rc.w, rc.h,
        col
    ); 
}


void
ESP_MegaScreen::drawUI() {
    for(int i=0;i<ESP_MegaScreen::buttonCount;++i) {
        drawButton(i, false);
    }
}


void
ESP_MegaScreen::drawMemoryAddress(ScreenPoint* pOffset, uint16_t addr, uint8_t data) const {
    const uint16_t startAddress = 0xA000; // i.e. 40960
    const uint16_t offset = addr - startAddress;
    const int y = offset / 4;
    const int xStart = offset % 4;

    int sx = xStart * 8 * m_Scale;
    int sy = y * m_Scale;

    for(int i=0;i<8;++i, sx+=m_Scale) {
        uint8_t mask = 1 << i;
        uint32_t col = data & mask ? 0xf000 : 0x3333;

        if (prettyLED5) {
            tft.fillRect(sx+2, sy+0, 1, 1, col);
            tft.fillRect(sx+1, sy+1, 3, 1, col);
            tft.fillRect(sx+0, sy+2, 5, 1, col);
            tft.fillRect(sx+1, sy+3, 3, 1, col);
            tft.fillRect(sx+2, sy+4, 1, 1, col);
        } else {
            tft.fillRect(sx, sy, m_Scale-1, m_Scale-1, col);
        }
    }
}


void
ESP_MegaScreen::drawMemoryBoard(ScreenPoint* pOffset) const {
    const int startAddress = 0xA000; // i.e. 40960

    for(int y=0;y<64;++y) {
        for(int x=0;x<4;++x) {
            uint16_t addr = startAddress + y*4 + x;
            uint8_t byte = read8(addr);

            drawMemoryAddress(pOffset, addr, byte);
        }
    }

}
