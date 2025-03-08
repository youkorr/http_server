#include "http_server.h"

void HttpServer::setup() {
  if (!SD.begin()) {
    ESP_LOGE("SD", "Échec d'initialisation de la carte SD");
    return;
  }
  
  ESP_LOGI("HTTP", "Serveur HTTP démarré sur le port 8080");

  // Route pour servir un fichier audio
  server.on("/test.flac", HTTP_GET, [](AsyncWebServerRequest *request) {
    File file = SD.open("/test.flac");
    if (!file) {
      request->send(404, "text/plain", "Fichier non trouvé");
      return;
    }

    request->send(file, "audio/flac");
    file.close();
  });

  server.begin();
}

