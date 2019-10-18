#include <ESP8266WiFi.h>

#include "wifi.h"

Wifi::Wifi(const char *ssid, const char *password) : client()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
};

void Wifi::ensureConnected() const
{
  while (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    Serial.println("Connection failed! Rebooting...");
    delay(2000);
    ESP.restart();
  }
}

const WiFiClient Wifi::getClient() const
{
  ensureConnected();
  return client;
}
