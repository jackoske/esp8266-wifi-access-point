#ifndef WIFI_ACCESS_POINT_H
#define WIFI_ACCESS_POINT_H

#include <FS.h>
#include <LittleFS.h>
#include <ESP8266WiFi.h> // Include ESP8266WiFi.h for WiFiEventSoftAPModeStationConnected and WiFiEventSoftAPModeStationDisconnected

void listFSContents(fs::FS &fs) {
  Dir dir = fs.openDir("/");
  while (dir.next()) {
    Serial.print(dir.fileName());
    Serial.print(" - ");
    File f = dir.openFile("r");
    Serial.println(f.size());
    f.close();
  }
}

void printWiFiStationConnected(const WiFiEventSoftAPModeStationConnected& evt) {
  Serial.print("Station connected: ");
  Serial.print("MAC: ");
  Serial.print(evt.mac[0], HEX); Serial.print(":");
  Serial.print(evt.mac[1], HEX); Serial.print(":");
  Serial.print(evt.mac[2], HEX); Serial.print(":");
  Serial.print(evt.mac[3], HEX); Serial.print(":");
  Serial.print(evt.mac[4], HEX); Serial.print(":");
  Serial.println(evt.mac[5], HEX);
}

void printWiFiStationDisconnected(const WiFiEventSoftAPModeStationDisconnected& evt) {
  Serial.print("Station disconnected: ");
  Serial.print("MAC: ");
  Serial.print(evt.mac[0], HEX); Serial.print(":");
  Serial.print(evt.mac[1], HEX); Serial.print(":");
  Serial.print(evt.mac[2], HEX); Serial.print(":");
  Serial.print(evt.mac[3], HEX); Serial.print(":");
  Serial.print(evt.mac[4], HEX); Serial.print(":");
  Serial.println(evt.mac[5], HEX);
}

#endif // WIFI_ACCESS_POINT_H
