#include "emf/emf.h"
class megaprocessor_clock_timer {
public:
uint32_t cycles;
float period;
uint32_t timecum;
uint32_t uptimeTotal;
megaprocessor_clock_timer(hashmap &bus, hashmap &options) {
  setRate(60);
reset();
}
void reset() {
timecum = 0;
uptimeTotal = 0;
}
uint32_t getUptime() {
return uptimeTotal;
}
void tick(uint32_t t) {
  timecum += t;
  uptimeTotal += t;
  while (timecum >= period) {
machine.bus.pulseLow('timer60')
    timecum -= period;
  }
}
// Clock device : 
// timer
void setRate(uint32_t hz) {
  cycles = hz;
  period = 1/hz;
}
uint32_t getFrequency() {
return cycles;
}
return {
  reset,
  tick,
  setRate,
  getFrequency,
  getUptime,
};
};
