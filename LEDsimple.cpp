
#include <Arduino.h>
#include "LEDsimple.h"

LEDsimple::LEDsimple(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
  _time = 0;
  _state = 0;
  _state_old = 0;
  _counter = 0;
  _mode = 0;         // 1 = off, 2 = on, 3 = blink, 4 = blink with counter
  _stopwatch = 1000; // in ms
}

void LEDsimple::update() {
  if (_time > _stopwatch) {
    _time = 0;
    if (_mode == 1) {_state = 0;}
    else if (_mode == 2) {_state = 1;}
    else if (_mode == 3) {_state = !_state;}
    else if (_mode == 4) {
      if (_counter > 0) {_counter--; _state = !_state;}
      else {if (_state) {_state = 0;} _stopwatch = 1000;}
    }
    else if (_mode == 5) {
      if (_counter > 0) {_counter--; _state = !_state;}
    }
    if (_state != _state_old) {
#if defined (__arm__) && defined (CORE_TEENSY) // digitalWriteFast on teensy
      digitalWriteFast(_pin, _state);
#else
      digitalWrite(_pin, _state);
#endif
      _state_old = _state;
    }
  }
}

void LEDsimple::off() {
  _mode = 1;
  _stopwatch = 1000;
  _time = _stopwatch;
}

void LEDsimple::off(int stopwatch) {
  _mode = 1;
  _stopwatch = stopwatch;
  _time = 0;
}

void LEDsimple::on() {
  _mode = 2;
  _stopwatch = 1000;
  _time = _stopwatch;
}

void LEDsimple::blink(int stopwatch) {
  _mode = 3;
  _stopwatch = stopwatch;
  _time = _stopwatch;
}

void LEDsimple::blink(int stopwatch, int counter) {
  if (counter == 0) {_mode = 3;}
  else {_mode = 4; _counter = counter * 2;}
  _stopwatch = stopwatch;
  _time = _stopwatch;
}

void LEDsimple::pulse(int stopwatch, int counter) {
  if (counter != 0) {
  _mode = 5; _counter = counter * 2;
  _stopwatch = stopwatch;
  _time = _stopwatch;
  }
}
