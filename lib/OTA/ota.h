#ifndef OTA_H
#define OTA_H

#include "Arduino.h"

class OTA
{
private:
  const String wifi_ssid;
  const String wifi_pass;

public:
  OTA(const String wifi_ssid, const String wifi_pass);

  void setup() const;
  void handle() const;
};

#endif
