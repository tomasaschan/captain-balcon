#include "Arduino.h"
#include "analog.h"

AnalogPin::AnalogPin()
{
  pinMode(A0, INPUT);
}

int AnalogPin::read() const
{
  int signal = analogRead(A0);
  return signal;
}

void AnalogPin::print() const
{
  int signal = Analog.read();
  Serial.printf("Analog signal: %i\n", signal);
}
