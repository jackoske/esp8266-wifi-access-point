#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>
#include <LittleFS.h>
#include "wifi_access_point.h"

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.softAP("JACKS_AP", "password");  // Set your AP credentials
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  // Attempt to initialize LittleFS
  if (LittleFS.begin()) {
    Serial.println("LittleFS started.");
    listFSContents(LittleFS); // Print the contents of LittleFS at startup
  } else {
    Serial.println("Failed to start LittleFS.");
    return;
  }

  // Register event handlers
  WiFi.onSoftAPModeStationConnected(&printWiFiStationConnected);
  WiFi.onSoftAPModeStationDisconnected(&printWiFiStationDisconnected);

  // Serve index.html
  server.on("/", HTTP_GET, []() {
    Serial.println("HTTP GET /");
    if (LittleFS.exists("/index.html")) {
      File file = LittleFS.open("/index.html", "r");
      if(!file){
        Serial.println("Failed to open html file for reading");
        return;
      }
      Serial.println("File Content:");
      while(file.available()){
        Serial.write(file.read());
      }
      server.streamFile(file, "text/html");
      file.close();
    } else {
      server.send(404, "text/plain", "HTML File not found");
    }
  });

  // Serve CSS file
  server.on("/css/style.css", HTTP_GET, []() {
    Serial.println("HTTP GET /css/style.css");
    if (LittleFS.exists("/css/style.css")) {
      File file = LittleFS.open("/css/style.css", "r");
      server.streamFile(file, "text/css");
      file.close();
    } else {
      server.send(404, "text/plain", "CSS File not found");
    }
  });

  // Serve JavaScript file
  server.on("/js/script.js", HTTP_GET, []() {
    Serial.println("HTTP GET /js/script.js");
    if (LittleFS.exists("/js/script.js")) {
      File file = LittleFS.open("/js/script.js", "r");
      server.streamFile(file, "application/javascript");
      file.close();
    } else {
      server.send(404, "text/plain", "JS File not found");
    }
  });

  // Serve LittleFS contents
  server.on("/list", HTTP_GET, []() {
    Serial.println("HTTP GET /list");
    server.send(200, "text/plain", "Listing LittleFS contents...");
    listFSContents(LittleFS);
  });

  server.begin();
  Serial.println("HTTP server started");
}


void loop() {
  server.handleClient();
}
