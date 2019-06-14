#include <ESP8266WiFi.h>
#include <time.h>

#include "clock.h"

const int timezone = 1;
const int dst = 1;

Clock::Clock()
{
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
  }
  configTime(timezone * 3600, dst * 3600, "sth1.ntp.se", "sth2.ntp.se");
  while (!time(nullptr))
  {
    delay(1000);
  }
}

time_t Clock::now() const
{
  return time(nullptr);
}

char *Clock::cnow() const
{
  time_t t = time(nullptr);

  return strtok(ctime(&t), "\n");
}
