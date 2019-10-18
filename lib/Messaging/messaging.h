#ifndef MESSAGING_H
#define MESSAGING_H

#include <PubSubClient.h>

#include "wifi.h"

class Bus
{
private:
  PubSubClient client;
  const char *username;
  const char *password;

  void callback(char *topic, byte *payload, size_t lenght);
  void reconnect();

public:
  Bus(const Wifi &, const char *username, const char *password);
  void publish() const;
};

#endif
