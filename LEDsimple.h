
/*

LEDsimple.h - simple library for LEDs
inspired by LEDEffect by Harrison H. Jones https://github.com/harrisonhjones/LEDEffect

*/

#include <Arduino.h>
#ifndef LEDsimple_h
#define LEDsimple_h
#include "elapsedMillis.h"

class LEDsimple {
  public:
    LEDsimple(int pin);
    void update();
    void off();
    void off(int stopwatch);
    void on();
    void blink(int stopwatch);
    void blink(int stopwatch, int counter);
  private:
    int _pin;
    int _state;
    int _state_old;
    int _counter;
    int _mode;        // 1 = off, 2 = on, 3 = blink, 4 = blink with counter
    int _stopwatch;  // in ms
    elapsedMillis _time;
};

#endif
