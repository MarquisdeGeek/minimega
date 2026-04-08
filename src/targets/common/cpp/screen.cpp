
#include "emf/emf.h"

#include "screen.h"


CommonScreen::CommonScreen(int scale, bool showComparison) : m_Scale(scale), m_bShowComparison(showComparison) {

    m_ifaceWidth = m_Scale * m_fontWidth * 32;
    m_ifaceHeight = m_Scale * m_fontHeight * 24;

    m_gapX = m_Scale * m_fontWidth;
    m_gapY = m_Scale * m_fontHeight;
}


void
CommonScreen::setRenderer(BaseRender* pRenderer) {
    m_pRenderer = pRenderer;
}


int
CommonScreen::getWidth() const {

    if (m_bShowComparison) {
        return m_gapX + m_ifaceWidth + m_gapX*2 + m_ifaceWidth + m_gapX;
    }

    return m_gapX + m_ifaceWidth + m_gapX;
}


int
CommonScreen::getHeight() const {

    return m_gapY + m_ifaceHeight + m_gapY;
}


void
CommonScreen::getOffset(ScreenPoint* pOffset, int position) const {
    pOffset->x = m_gapX;
    pOffset->y = m_gapY;

    if (position) {
        pOffset->x += m_ifaceWidth + m_gapX*2;
    }
}



void
CommonScreen::clearBackground(ScreenPoint* _) {
    const uint32_t col = colLight;
    m_pRenderer->clearScreen(col);
}

