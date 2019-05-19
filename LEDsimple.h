
/*

LEDsimple.h - simple library for LEDs
inspired by LEDEffect by Harrison H. Jones https://github.com/harrisonhjones/LEDEffect

*/

#include <Arduino.h>
#ifndef LEDsimple_h
#define LEDsimple_h

class LEDsimple {
  public:
    LEDsimple(int pin);
    void update();
    void off();
    void on();
    void blink(uint16_t stopwatch);
    void blink(uint16_t stopwatch, uint16_t counter);
  private:
    int _pin;
    uint8_t _state;
    uint8_t _state_old;
    uint16_t _counter;
    uint8_t _mode;        // 1 = off, 2 = on, 3 = blink, 4 = blink with counter
    uint16_t _stopwatch;  // in ms
    uint64_t _time;
};

#endif
