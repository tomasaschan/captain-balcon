#include "led.h"

const uint ON = LOW;
const uint OFF = HIGH;

LED::LED()
{
  pinMode(LED_BUILTIN, OUTPUT);
};

void LED::turnOn() const { digitalWrite(LED_BUILTIN, ON); };

void LED::turnOff() const { digitalWrite(LED_BUILTIN, OFF); };
