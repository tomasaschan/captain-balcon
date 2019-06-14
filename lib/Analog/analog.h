#ifndef ANALOG_H
#define ANALOG_H

class AnalogPin
{
public:
  AnalogPin();
  int read() const;
  void print() const;
};

const AnalogPin Analog = AnalogPin();

#endif
