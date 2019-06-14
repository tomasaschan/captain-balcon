#include <ESP8266WiFi.h>

#include "wifi.h"

Wifi::Wifi() : initialized(false){};

void Wifi::initialize(char *ssid, char *password) const
{
  if (!initialized)
  {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
      Serial.println("Connection failed! Rebooting...");
      delay(2000);
      ESP.restart();
    }
  }
};
