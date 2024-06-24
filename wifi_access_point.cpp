#include "wifi_access_point.h"

String listFSContents(FS &fs, const String &path) {
  Dir dir = fs.openDir(path); // Open the specified directory
  String content = "";        // String to accumulate file listing

  while (dir.next()) {
    String fileName = dir.fileName();
    String fullPath = path + (path.endsWith("/") ? "" : "/") + fileName; // Construct full path

    if (dir.isDirectory()) {
      // Handle directories (recursive call)
      content += listFSContents(fs, fullPath); // Recursive call with subdirectory path
    } else {
      // Handle files
      File f = dir.openFile("r");
      if (f) {
        content += fullPath + " - Size: " + String(f.size()) + " bytes\n";
        f.close();
      } else {
        content += fullPath + " - Error opening file\n";
      }
    }
  }

  return content; // Return the accumulated file listing
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
