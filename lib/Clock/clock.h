#ifndef CLOCK_H
#define CLOCK_H

#include <time.h>

class Clock
{
public:
  Clock();
  time_t now() const;
  char *cnow() const;
};

#endif
