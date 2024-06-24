// In web_server.cpp
#include "web_server.h"
#include "wifi_access_point.h"

ESP8266WebServer server(80);

void handleRoot() {
  Serial.println("HTTP GET /");
  if (LittleFS.exists("/index.html")) {
    File file = LittleFS.open("/index.html", "r");
    if (!file) {
      Serial.println("Failed to open html file for reading");
      return;
    }
    Serial.println("File Content:");
    while (file.available()) {
      Serial.write(file.read());
    }
    server.streamFile(file, "text/html");
    file.close();
  } else {
    server.send(404, "text/plain", "HTML File not found");
    Serial.println("HTML File not found");
  }
}

void handleCss() {
  Serial.println("HTTP GET /css/style.css");
  if (LittleFS.exists("/css/style.css")) {
    File file = LittleFS.open("/css/style.css", "r");
    server.streamFile(file, "text/css");
    file.close();
  } else {
    server.send(404, "text/plain", "CSS File not found");
    Serial.println("CSS File not found");
  }
}

void handleJs() {
  Serial.println("HTTP GET /js/script.js");
  if (LittleFS.exists("/js/script.js")) {
    File file = LittleFS.open("/js/script.js", "r");
    server.streamFile(file, "application/javascript");
    file.close();
  } else {
    server.send(404, "text/plain", "JS File not found");
    Serial.println("JS File not found");
  }
}

void handleList() {
  Serial.println("HTTP GET /list");
  String content = listFSContents(LittleFS); // Get listing string from the function
  server.send(200, "text/plain", "LittleFsContents\n" + content);
}

void setupWebServer() {
  // Register handlers for root, CSS, JS, and listing
  server.on("/", HTTP_GET, handleRoot);
  server.on("/css/style.css", HTTP_GET, handleCss);
  server.on("/js/script.js", HTTP_GET, handleJs);
  server.on("/list", HTTP_GET, handleList);

  server.begin();
  Serial.println("HTTP server started");
}
