# ESP8266-WebServer/ captive portal / keeps growing
=================

## Work in progress

This project uses the ESP8266WebServer library to serve a webpage from the ESP8266. It also uses the LittleFS filesystem to store the webpage files.

The server is set up to serve three types of files: HTML, CSS, and JavaScript. If a requested file is not found, it will return a 404 error.

The ESP8266 is set up as a soft AP, and it prints the IP address it is using to the serial monitor. It also prints a message to the serial monitor when a Wi-Fi station connects or disconnects, including the MAC address of the station.

The LittleFS filesystem is initialized in the setup function, and its contents are printed to the serial monitor.

[arduino-littlefs-upload](https://github.com/earlephilhower/arduino-littlefs-upload)

/home/jskehan/Arduino/tools/ESP8266LittleFS/tool/esp8266littlefs.jar

#To install
Unpack the tool into the tools directory (the path will look something like `$HOME/Arduino/tools/ESP32FS/tool/esp32fs.jar`).

Restart Arduino IDE.


To Do:

- [x] fix webpage not being served
    - [X] fix css and js


- [x] Try to print the spiffs file system to the serial monitor
    - [X] done with littfs 

- [ ] mac addresses not being printed, (meh dunno if I need maybe later I will fix!)

- [x] Add a way to turn off password protection (fix dns redirection first)
```
WiFi.softAP("YourNetworkName", ""); (no password)

```

  - [x] Implement DNS server to always redirect to the ESP8266 IP (192.168.4.1)
  issue of IP not working when connected to the network and no wifi see below (setup captive portal)
  Now works as a login but still doesnt redirect https requests!
    (something like below)
    ```
    #include <DNSServer.h>

    const byte DNS_PORT = 53;
    DNSServer dnsServer;

    void setup() {
      // ... your existing setup code ...

      // Start the DNS server
      dnsServer.start(DNS_PORT, "*", WiFi.softAPIP());
    }

    void loop() {
      // ... your existing loop code ...

      // Process DNS requests
      dnsServer.processNextRequest();
    }

    ```


    ```
    When you connect your phone to the WiFi network created by the ESP8266, your phone is likely still using its mobile data for internet access because the WiFi network does not have internet access. This is a feature called "Smart Network Switch" or "Auto Network Switch" on some phones, designed to maintain a stable internet connection.

    When you try to access the ESP8266's IP address while your phone's mobile data is on, your phone tries to access that IP address over the internet, not over the WiFi network, and fails because that IP address does not exist on the internet.

    When you turn off your phone's mobile data, your phone has no choice but to use the WiFi network for all requests, including accessing the ESP8266's IP address. That's why it works when mobile data is off.

    To fix this, you can:

    1. Turn off "Smart Network Switch" or "Auto Network Switch" on your phone.
    2. Implement a captive portal on the ESP8266, as mentioned earlier. A captive portal can force a device to use the WiFi network for all requests, even if the device has other internet connections available.
    ```
- [ ] SSL support for https request redirection?? 

- [ ] Refactor more!
