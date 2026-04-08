#ifndef TARGETS_ESP_SCREEN_H
#define TARGETS_ESP_SCREEN_H 1


#include "emf/emf.h"
#include "targets/common/cpp/screen.h"


class ESP_Render : public BaseRender {
public:
    ESP_Render();

    virtual void fillRect(int x, int y, int w, int h, uint32_t col);
    virtual void clearScreen(uint32_t col);
};



class ESP_MegaScreen : public CommonScreen {
    public:
        const static int buttonCount = 12;

        ESP_MegaScreen(int scale, bool showComparison);

        // void clearBackground();
        void drawUI();
        void drawButton(int idx, bool state);
        void getButtonPosition(ScreenRect* pOffset, int idx) const;
        
        void drawMemoryBoard(ScreenPoint* pOffset) const;
        void drawMemoryAddress(ScreenPoint* pOffset, uint16_t addr, uint8_t data) const;

};

#endif // TARGETS_ESP_SCREEN_H
