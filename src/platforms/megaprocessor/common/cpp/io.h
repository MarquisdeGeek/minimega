#ifndef EMF_PLATFORMS_MEGAPROCESSOR_CPP_IO_H
#define EMF_PLATFORMS_MEGAPROCESSOR_CPP_IO_H 1

void mega_io_start();
void mega_io_update();


uint8_t mega_io_read8(uint16_t addr, uint8_t data);
void mega_io_write8(uint16_t addr, uint8_t data);



const int PERIPHERALS_BASE = 0x8000;

const int TIMER_BASE       = PERIPHERALS_BASE + 0x00;
const int UART_BASE        = PERIPHERALS_BASE + 0x10;
const int INTERRUPT_BASE   = PERIPHERALS_BASE + 0x20;
const int GEN_IO_BASE      = PERIPHERALS_BASE + 0x30;


const int GEN_IO_OUTPUT       = GEN_IO_BASE + 0;
const int GEN_IO_INPUT        = GEN_IO_BASE + 2;
const int GEN_IO_CTR          = GEN_IO_BASE + 4;


const int TIME_BLK_COUNTER     = TIMER_BASE + 0;
const int TIME_BLK_TIMER       = TIMER_BASE + 2;
const int TIME_BLK_TIMER_CTRL  = TIMER_BASE + 4;

const int TIME_BLK_TIMER_CTRL_EN_TIMER = 0x01;
const int TIME_BLK_TIMER_CTRL_CLR_COUNT = 0x02;
const int TIME_BLK_TIMER_CTRL_CLR_TIMER = 0x04;

#endif // EMF_PLATFORMS_MEGAPROCESSOR_CPP_IO_H
