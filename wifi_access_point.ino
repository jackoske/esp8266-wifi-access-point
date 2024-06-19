#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>

ESP8266WebServer server(80);

void listSPIFFSContents() {
  Dir dir = SPIFFS.openDir("/");
  while (dir.next()) {
    Serial.print(dir.fileName());
    Serial.print(" - ");
    File f = dir.openFile("r");
    Serial.println(f.size());
    f.close();
  }
}

// Event handler for Wi-Fi station connected
void onWiFiStationConnected(const WiFiEventSoftAPModeStationConnected& evt) {
  Serial.print("Station connected: ");
  Serial.print("MAC: ");
  Serial.print(evt.mac[0], HEX); Serial.print(":");
  Serial.print(evt.mac[1], HEX); Serial.print(":");
  Serial.print(evt.mac[2], HEX); Serial.print(":");
  Serial.print(evt.mac[3], HEX); Serial.print(":");
  Serial.print(evt.mac[4], HEX); Serial.print(":");
  Serial.println(evt.mac[5], HEX);
}

// Event handler for Wi-Fi station disconnected
void onWiFiStationDisconnected(const WiFiEventSoftAPModeStationDisconnected& evt) {
  Serial.print("Station disconnected: ");
  Serial.print("MAC: ");
  Serial.print(evt.mac[0], HEX); Serial.print(":");
  Serial.print(evt.mac[1], HEX); Serial.print(":");
  Serial.print(evt.mac[2], HEX); Serial.print(":");
  Serial.print(evt.mac[3], HEX); Serial.print(":");
  Serial.print(evt.mac[4], HEX); Serial.print(":");
  Serial.println(evt.mac[5], HEX);
}

void setup() {
  Serial.begin(115200);
  WiFi.softAP("ESP_AP", "password");  // Set your AP credentials
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  if (SPIFFS.begin()) {
    Serial.println("SPIFFS started.");
    listSPIFFSContents();
  } else {
    Serial.println("SPIFFS failed to start.");
    return;
  }

  // Register event handlers
  WiFi.onSoftAPModeStationConnected(&onWiFiStationConnected);
  WiFi.onSoftAPModeStationDisconnected(&onWiFiStationDisconnected);

  server.on("/", HTTP_GET, []() {
    Serial.println("HTTP GET /");
    if (SPIFFS.exists("/index.html")) {
      File file = SPIFFS.open("/index.html", "r");
      server.streamFile(file, "text/html");
      file.close();
    } else {
      server.send(404, "text/plain", "File not found");
    }
  });

  server.on("/css/styles.css", HTTP_GET, []() {
    Serial.println("HTTP GET /css/styles.css");
    if (SPIFFS.exists("/css/styles.css")) {
      File file = SPIFFS.open("/css/styles.css", "r");
      server.streamFile(file, "text/css");
      file.close();
    } else {
      server.send(404, "text/plain", "CSS File not found");
    }
  });

  server.on("/js/script.js", HTTP_GET, []() {
    Serial.println("HTTP GET /js/script.js");
    if (SPIFFS.exists("/js/script.js")) {
      File file = SPIFFS.open("/js/script.js", "r");
      server.streamFile(file, "application/javascript");
      file.close();
    } else {
      server.send(404, "text/plain", "JS File not found");
    }
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
