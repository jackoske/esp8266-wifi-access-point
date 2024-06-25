#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>
#include <LittleFS.h>
#include "server_utils.h"

extern ESP8266WebServer server;

void handleRoot();
void handleCss();
void handleJs();
void handleList();
void setupWebServer();

#endif // WEB_SERVER_H