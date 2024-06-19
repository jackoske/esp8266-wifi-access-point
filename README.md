# ESP8266-WebServer
=================

## Work in progress

This project uses the ESP8266WebServer library to serve a webpage from the ESP8266. It also uses the SPIFFS filesystem to store the webpage files.

The server is set up to serve three types of files: HTML, CSS, and JavaScript. If a requested file is not found, it will return a 404 error.

The ESP8266 is set up as a soft AP, and it prints the IP address it is using to the serial monitor. It also prints a message to the serial monitor when a Wi-Fi station connects or disconnects, including the MAC address of the station.

The SPIFFS filesystem is initialized in the setup function, and its contents are printed to the serial monitor.
Files are added to SPIFFS storage using the script available at [ESP Sketch Data Upload](https://github.com/jackoske/ESP-Sketch-Data-Upload).

To Do:

- [ ] fix webpage not being served

- [ ] Add a way to turn off password protection

- [ ] Try to print the spiffs file system to the serial monitor

- [ ] mac addresses not being printed

