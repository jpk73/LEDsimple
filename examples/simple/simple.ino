
/*

  LEDsimple.h - simple library for LEDs
  inspired by LEDEffect by Harrison H. Jones https://github.com/harrisonhjones/LEDEffect

*/

#include <LEDsimple.h>

LEDsimple led1(33);
LEDsimple led2(35);

int state;
int stopwatch;

void setup() {}

void loop()  {
  if (millis() > stopwatch + 2000) {
    stopwatch = millis();
    if (state == 0) {
      led1.on();
      led2.off();
      state = 1;
    }
    else if (state == 1) {
      led1.pulse(200, 2);    // pulse with counter: remembers initial state
      led2.blink(150, 8);    // blink with counter: goes off when completed
      state = 2;
    }
    else if (state == 2) {
      led1.off();
      led2.on();
      state = 3;
    }
    else {
      led1.blink(80);
      led2.off(1000);        // off after delay
      state = 0;
    }
  }
  led1.update();
  led2.update();
}
