#include "Arduino.h"

#include "led.h"
#include "ota.h"

const OTA ota = OTA("<ssid>", "<password>");
const LED led = LED();

const uint BAUD_RATE = 115200;

void setup()
{
  Serial.begin(BAUD_RATE);

  led.turnOn();
  ota.setup();
}

void loop()
{
  ota.handle();

  delay(1000);
  led.turnOff();
}
