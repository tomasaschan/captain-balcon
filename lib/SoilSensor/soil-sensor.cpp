#include "soil-sensor.h"
#include "analog.h"

SoilSensor::SoilSensor(int threshold) : threshold(threshold), sensor(AnalogPin()){};

bool SoilSensor::isWet() const { return sensor.read() > threshold; }
