
#include <Arduino.h>
#include "LEDsimple.h"

LEDsimple::LEDsimple(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
  _time = millis();
  _state = 0;
  _state_old = 0;
  _state_flag = 0;
  _ledState = 0; // 1 = off, 2 = on, 3 = blink, 4 = blinkOnce
  _ledDelay = 0; // in ms
}

void LEDsimple::update() {
  if ((millis() - _time) > _ledDelay) {
    _time = millis();
    if (_ledState == 1) {_state = 0;}
    else if (_ledState == 2) {_state = 1;}
    else if (_ledState == 3) {_state = !_state;}
    else if (_ledState == 4) {
      if (_state == 1 && _state_flag == 1) {_state = 0; _state_flag = 2;}
      else if (_state == 0 && _state_flag >= 1) {_state = 1; _state_flag = 3;}
      else if (_state == 1 && _state_flag == 3) {_state = 0; _state_flag = 0; _ledDelay = 1000;}
    }
    if (_state != _state_old) {
      digitalWrite(_pin, _state);
      _state_old = _state;
    }
  }
}

void LEDsimple::off() {
  _ledState = 1;
  _ledDelay = 1000;
  _time = 0;
}

void LEDsimple::on() {
  _ledState = 2;
  _ledDelay = 1000;
  _time = 0;
}

void LEDsimple::blink(int ledDelay) {
  _ledState = 3;
  _ledDelay = ledDelay;
  _time = ledDelay;
}

void LEDsimple::blinkOnce(int ledDelay) {
  _ledState = 4;
  _state_flag = 1;
  _ledDelay = ledDelay;
  _time = ledDelay;
}
