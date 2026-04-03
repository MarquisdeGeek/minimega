#ifndef EMF_PLATFORMS_MEGAPROCESSOR_COMMON_KEYPAD_CPP_H
#define EMF_PLATFORMS_MEGAPROCESSOR_COMMON_KEYPAD_CPP_H 1

#include "emf/emf.h"


class MegaKeypad {
public:

  MegaKeypad();

  void start();

  void onKeyDown(uint8_t key);
  void onKeyUp(uint8_t);

  uint16_t getInputData() const;

protected:
  uint16_t m_ioInputData;

};


void mega_keypad_onDown(uint8_t key);
void mega_keypad_onUp(uint8_t key);



#endif // EMF_PLATFORMS_MEGAPROCESSOR_COMMON_KEYPAD_CPP_H
