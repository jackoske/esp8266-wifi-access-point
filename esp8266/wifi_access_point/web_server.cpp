// In web_server.cpp
#include "web_server.h"
#include "server_utils.h"

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
    String htmlContent;
    while (file.available()) {
      htmlContent += (char)file.read();
    }
    Serial.print(htmlContent);
    server.send(200, "text/html", htmlContent);
    file.close();
  } else {
    server.send(404, "text/plain", "HTML File not found");
    Serial.println("HTML File not found");
  }
}

void handleCss() {
  Serial.println("HTTP GET /css/styles.css");
  if (LittleFS.exists("/css/styles.css")) {
    File file = LittleFS.open("/css/styles.css", "r");
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
  server.on("/css/styles.css", HTTP_GET, handleCss);
  server.on("/js/script.js", HTTP_GET, handleJs);
  server.on("/list", HTTP_GET, handleList);
  server.onNotFound([]() {
    handleRoot();
  });
  // Add this line to handle the /generate_204 route
  // fakes internet connectivity for some devices
  server.on("/generate_204", HTTP_GET, []() {
    server.send(204, "text/html", "");
  });

  server.begin();
  Serial.println("HTTP server started");
}
