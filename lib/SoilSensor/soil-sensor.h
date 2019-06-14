#ifndef SOIL_SENSOR_H
#define SOIL_SENSOR_H

#include "analog.h"

class SoilSensor
{
private:
  int threshold;
  AnalogPin sensor;

public:
  SoilSensor(int);
  bool isWet() const;
};

#endif
