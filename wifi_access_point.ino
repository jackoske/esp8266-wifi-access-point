// In wifi_access_point.ino
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <LittleFS.h>
#include "wifi_access_point.h"
#include "web_server.h"

void setup() {
  Serial.begin(115200);

  // Set up SoftAP
  WiFi.softAP("JACKS_AP", "password");

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  // Attempt to initialize LittleFS
  if (LittleFS.begin()) {
    Serial.println("LittleFS started.");
  } else {
    Serial.println("Failed to start LittleFS.");
    return;
  }

  setupWebServer(); // Start the web server
}

void loop() {
  server.handleClient();
}
