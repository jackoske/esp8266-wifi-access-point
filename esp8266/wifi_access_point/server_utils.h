#ifndef SERVER_UTILS_H
#define SERVER_UTILS_H

#include <FS.h>
#include <LittleFS.h>
#include <ESP8266WiFi.h>

String listFSContents(fs::FS &fs, const String &path = "/");
void printWiFiStationConnected(const WiFiEventSoftAPModeStationConnected& evt);
void printWiFiStationDisconnected(const WiFiEventSoftAPModeStationDisconnected& evt);

#endif // SERVER_UTILS_H