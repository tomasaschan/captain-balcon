//#include "Arduino.h"

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
#include <map>

#include "ota.h"

const std::map<ota_error_t, const String> error_messages = {
    {OTA_AUTH_ERROR, "Auth Failed"},
    {OTA_BEGIN_ERROR, "Begin Failed"},
    {OTA_CONNECT_ERROR, "Connect Failed"},
    {OTA_RECEIVE_ERROR, "Receive Failed"},
    {OTA_END_ERROR, "End Failed"}};

OTA::OTA(const String wifi_ssid, const String wifi_pass) : wifi_ssid(wifi_ssid), wifi_pass(wifi_pass){};

void OTA::setup() const
{
  Serial.println("Initializing OTA updates...");

  WiFi.mode(WIFI_STA);
  WiFi.begin(wifi_ssid, wifi_pass);

  while (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    Serial.println("Connection failed! Rebooting...");
    delay(2000);
    ESP.restart();
  }

  ArduinoOTA.setPort(8266);
  ArduinoOTA.setHostname("captain-balcon");

  ArduinoOTA.onStart([]() {
    String type = ArduinoOTA.getCommand() == U_FLASH
                      ? "sketch"
                      : "filesystem";
    Serial.println("Start updating " + type);
  });

  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });

  ArduinoOTA.onProgress([](uint progress, uint total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });

  ArduinoOTA.onError([](ota_error_t error) {
    const String error_message = error_messages.at(error);
    Serial.printf("Error[%u]: %s", error, error_message.c_str());
  });

  ArduinoOTA.begin();

  Serial.printf("Ready to accept OTA updates. IP address: %s\n", WiFi.localIP().toString().c_str());
}

void OTA::handle() const
{
  ArduinoOTA.handle();
}
