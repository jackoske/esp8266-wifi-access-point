// In wifi_access_point.ino
#include <Arduino.h>
#include <WiFi.h>
#include <LittleFS.h>
#include <DNSServer.h>
#include "server_utils.h"
#include "web_server.h"

// Init System Settings
const byte DNS_PORT = 53;
IPAddress myIP(172, 0, 0, 1);  // Gateway

DNSServer dnsServer;

void setup() {
  Serial.begin(115200);

  // Set up SoftAP
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(myIP, myIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP("COOL SHIT");
  // Start the DNS server
  dnsServer.start(DNS_PORT, "*", myIP);
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
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  dnsServer.processNextRequest();
  server.handleClient();
}
