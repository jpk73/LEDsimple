
/*

LEDsimple.h - simple library for LEDs
inspired on LEDEffect by Harrison H. Jones https://github.com/harrisonhjones/LEDEffect

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
    void blink(int ledDelay);
    void blinkOnce(int ledDelay);
  private:
    int _pin;
    unsigned char _state;
    unsigned char _state_old;
    unsigned char _state_flag;
    unsigned char _ledState;  // 1 = off, 2 = on, 3 = blink, 4 = blinkOnce
    int _ledDelay;            // in ms
    unsigned long _time;
};

#endif
