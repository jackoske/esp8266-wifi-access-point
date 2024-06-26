# Starter Web Captive Portal / Server for ESP32 and ESP8266

Welcome to the Starter Web Captive Portal/Server project for ESP32 and ESP8266 boards! This repository contains all the necessary files and documentation to set up a web captive portal/server using the Arduino IDE. This includes working with respective flash filesystems that are compatible with these boards.

## File Structure

The project is organized as follows:

```
── esp32
│   └── wifi_access_point
│       ├── data
│       │   ├── css
│       │   │   └── styles.css
│       │   ├── index.html
│       │   └── js
│       │       └── script.js
│       ├── README.md
│       ├── server_utils.cpp
│       ├── server_utils.h
│       ├── web_server.cpp
│       ├── web_server.h
│       └── wifi_access_point.ino
├── esp8266
│   └── wifi_access_point
│       ├── data
│       │   ├── css
│       │   │   └── styles.css
│       │   ├── index.html
│       │   └── js
│       │       └── script.js
│       ├── README.md
│       ├── server_utils.cpp
│       ├── server_utils.h
│       ├── web_server.cpp
│       ├── web_server.h
│       └── wifi_access_point.ino
├── Notes_on_boards
│   ├── ESP32 Audio Breakout board.md
│   ├── ESP32.md
│   ├── ESP8266.md
│   └── SERIAL COMMUNICATION.md
└── README.md
```

## Getting Started

### Prerequisites

Before you begin, ensure you have the following:

- Arduino IDE installed
- ESP32 or ESP8266 board
- Required libraries installed in Arduino IDE (ESP32/ESP8266 core, ESPAsyncWebServer, etc.)
- see respective notes for instilation and flashing directions!

### Notes on Boards

I have included detailed notes on the following boards in the `Notes_on_boards` directory:
- [ESP32](Notes_on_boards/ESP32.md)
- [ESP8266](Notes_on_boards/ESP8266.md)
- [ESP32 Audio Breakout board](Notes_on_boards/ESP32%20Audio%20Breakout%20board.md)
- [Serial Communication](Notes_on_boards/SERIAL%20COMMUNICATION.md)

### Usage

After successfully uploading the sketch and filesystem, your ESP32/ESP8266 will create a Wi-Fi access point. Connect to this access point and open a web browser. You should see the captive portal or web server hosted by your device.

## Contributing

If you encounter any issues or have suggestions for improvements, please feel free to open an issue or, even better, contribute with a pull request. Your contributions are highly appreciated! ❤️

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

Thank you for using this starter project for your ESP32 and ESP8266 web captive portal/server needs. Happy coding!
