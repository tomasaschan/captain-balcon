#include <PubSubClient.h>

#include "messaging.h"
#include "led.h"
#include "wifi.h"

Bus::Bus(const Wifi &wifi, const char *username, const char *password)
    : client(PubSubClient(wifi.getClient())), username(username), password(password)
{
  wifi.ensureConnected();
}

void Bus::callback(char *topic, byte *payload, uint lenght)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (uint i = 0; i < lenght; ++i)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  LED led;
  if ((char)payload[0] == '1')
  {
    led.turnOn();
  }
  else
  {
    led.turnOff();
  }
}

void Bus::reconnect()
{
  while (!client.connected())
  {
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str(), username, password))
    {
      client.publish("outTopic", "hello world");
    }
    else
    {
      delay(1000);
    }
  }
}

void Bus::publish() const
{
}
