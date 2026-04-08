#ifndef TARGETS_COMMON_SCREEN_H
#define TARGETS_COMMON_SCREEN_H 1

#include "emf/emf.h"


class BaseRender {
public:
    virtual void fillRect(int x, int y, int w, int h, uint32_t col) = 0;
    virtual void clearScreen(uint32_t col) = 0;
};


class ScreenPoint {
public:
    int x, y;

    ScreenPoint(): x(0), y(0) {}
    ScreenPoint(int x_, int y_) : x(x_), y(y_) {}
};


class ScreenRect {
public:
    int x, y;
    int w, h;
};



class CommonScreen {
public:
    const uint32_t colLight = 0xddaa7700;
    const uint32_t colDark  = 0xaa2200ff;


    CommonScreen(int scale, bool showComparison);

    virtual void setRenderer(BaseRender* pRenderer);

    virtual int getWidth() const;
    virtual int getHeight() const;

    virtual void getOffset(ScreenPoint* pOffset, int position) const;

    virtual void clearBackground(ScreenPoint* pOffset);

protected:
    BaseRender* m_pRenderer;

    int  m_Scale;
    bool m_bShowComparison;
    int  m_ifaceWidth; // size of total interactive area
    int  m_ifaceHeight; // size of total interactive area
    int  m_gapX; // space around each display
    int  m_gapY; // space around each display

    const int m_fontWidth = 8;
    const int m_fontHeight = 8;


};


#endif // TARGETS_COMMON_SCREEN_H
