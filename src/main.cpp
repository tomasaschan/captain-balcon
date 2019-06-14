#include "Arduino.h"

#include "led.h"
#include "ota.h"
#include "analog.h"
#include "wifi.h"

const Wifi wifi = Wifi();
const OTA ota = OTA();
const LED led = LED();

const uint BAUD_RATE = 115200;

void setup()
{
  Serial.begin(BAUD_RATE);
  wifi.initialize("<ssid>", "<password>");
  led.turnOn();
  ota.setup();
}

void loop()
{
  ota.handle();

  delay(1000);
  led.turnOff();
}
