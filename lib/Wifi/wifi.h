#ifndef WIFI_H
#define WIFI_H

#include "ESP8266WiFi.h"

class Wifi
{
private:
  WiFiClient client;

public:
  Wifi(const char *, const char *);
  void ensureConnected() const;
  const WiFiClient getClient() const;
};

#endif
