#include "Arduino.h"

#include "wifi.h"
#include "led.h"
#include "ota.h"
#include "soil-sensor.h"
#include "clock.h"

const Wifi wifi("<ssid>", "<password>");
const OTA ota;
const LED led;

const SoilSensor soil = SoilSensor(300);

const uint BAUD_RATE = 115200;

void setup()
{
  Serial.begin(BAUD_RATE);
  wifi.ensureConnected();
  led.turnOn();
  ota.setup();
}

void loop()
{
  const Clock clck = Clock();
  ota.handle();

  delay(1000);
  led.turnOff();

  led.set(!soil.isWet());
  Serial.printf("%s: Soil is %s\n", clck.cnow(), soil.isWet() ? "wet" : "dry");
}
