#ifndef LED_H
#define LED_H

#include "Arduino.h"

class LED
{
public:
  LED();
  void turnOn() const;
  void turnOff() const;
  void set(bool on) const;
};

#endif
