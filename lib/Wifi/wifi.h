#ifndef WIFI_H
#define WIFI_H

class Wifi
{
private:
  bool initialized;

public:
  Wifi();
  void initialize(char *, char *) const;
};

#endif
