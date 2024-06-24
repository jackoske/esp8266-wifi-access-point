#ifndef WIFI_ACCESS_POINT_H
#define WIFI_ACCESS_POINT_H

#include <FS.h>
#include <LittleFS.h>
#include <ESP8266WiFi.h>

String listFSContents(fs::FS &fs, const String &path = "/");
void printWiFiStationConnected(const WiFiEventSoftAPModeStationConnected& evt);
void printWiFiStationDisconnected(const WiFiEventSoftAPModeStationDisconnected& evt);

#endif // WIFI_ACCESS_POINT_H
