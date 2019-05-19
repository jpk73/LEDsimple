
/*

  LEDsimple.h - simple library for LEDs
  inspired by LEDEffect by Harrison H. Jones https://github.com/harrisonhjones/LEDEffect

*/

#include <LEDsimple.h>

LEDsimple led1(55);
LEDsimple led2(56);

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
      led1.blink(200, 3);    // blink with counter; if counter set to zero blink until off()
      led2.blink(150, 8);
      state = 2;
    }
    else if (state == 2) {
      led1.off();
      led2.off();
      state = 3;
    }
    else {
      led1.blink(80);
      led2.on();
      state = 0;
    }
  }
  led1.update();
  led2.update();
}
