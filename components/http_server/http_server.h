#pragma once

#include "esphome.h"
#include <ESPAsyncWebServer.h>
#include "SD.h"

class HttpServer : public Component {
 public:
  HttpServer() : server(8080) {}

  void setup() override;
  void loop() override {}

 private:
  AsyncWebServer server;
};
