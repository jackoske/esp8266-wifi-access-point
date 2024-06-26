Documentation for pins
[ESP32 A1S V2.3 Specification](https://docs.ai-thinker.com/_media/esp32-a1s_v2.3_specification.pdf)

### **DEVICE in android IDE is: ESP32 Dev module**

![[Pasted image 20240619160148.png]]

## Summary

| Function Description                             | Details                                                                                                    |
| ------------------------------------------------ | ---------------------------------------------------------------------------------------------------------- |
| Earphone Port (Earphone)                         | Insert the 3.5mm headphone jack to support left and right channel output.                                  |
| Left Channel of Speaker/Right Channel of Speaker | Support the maximum output of 4Ω3W speaker output, while supporting dual-channel output.                   |
| SD Card                                          | Maximum support 64G SD card read and write.                                                                |
| Key (KEY)                                        | Support 6-channel key input, default access method below the factory:                                      |
|                                                  | - **NAME**: **IO**                                                                                         |
|                                                  | - **KEY1**: IO36                                                                                           |
|                                                  | - **KEY2**: IO13                                                                                           |
|                                                  | - **KEY3**: IO19                                                                                           |
|                                                  | - **KEY4**: IO23                                                                                           |
|                                                  | - **KEY5**: IO18                                                                                           |
|                                                  | - **KEY6**: IO5                                                                                            |
|                                                  | You can modify the circuit button AD input.                                                                |
| Microphone                                       | Two analog microphones, each as audio input.                                                               |
| Headset Input (LINEIN)                           | Support headset microphone input.                                                                          |
| Lithium Battery (Battery)                        | Support 3.7V lithium battery input.                                                                        |
| Power Input (POWER)                              | Maximum support 5V2A power input, supports simultaneous lithium battery charging.                          |
| Serial Port (UART)                               | Support micro USB serial port input and output, maximum support 921600 baud rate.                          |
| Download Button (BOOT)                           | Please pull down when downloading. Since IO0 provides the codec clock, do not press when running normally. |
| Reset Button (EN)                                | Press this button to reset the system.                                                                     |
| Power Supply Mode                                | 1. Micro USB port 5V/2A                                                                                    |
|                                                  | 2. Lithium battery powered                                                                                 |

## Installation

- **Install ESP32 Board Package**:
  - Open Arduino IDE.
  - Go to `Tools > Board > Board Manager`.
  - Search for and install `esp32`.
- **Install Audio Tools Library**:
  - Go to `Sketch > Include Library > Manage Libraries`.
  - Add the [Arduino Audio Driver Library](https://github.com/pschatzmann/arduino-audio-driver/tree/main) by Peter Schatzmann.
  - you have to download the zip btw
- **Connect ESP32 to Computer**:
  - Use a USB cable to connect your ESP32 to the computer.
- **Select Board and Port**:
  - Go to `Tools > Board` and select your ESP32 board (e.g., "ESP32 Dev Module").
  - Go to `Tools > Port` and select the appropriate COM port (this might be automatic).
- **Write and Upload Sketch**:
  - Write your sketch in the Arduino IDE.
  - Click the upload button to transfer the sketch to the ESP32.
- **Open Serial Monitor**:
  - Go to `Tools > Serial Monitor`.
  - Set baud rate to `115200` (or the baud rate specified in your sketch).
  - The Serial Monitor will display messages from your ESP32, including IP addresses and debug information.



## Uploading files to serve (In flash memory)
(Still figuring o)
Uploading files to the ESP8266 module, such as HTML, CSS, JavaScript, and other resources, involves using a feature called SPIFFS (SPI Flash File System) or LittleFS. These filesystems allow you to store and serve files directly from the module's Flash memory, eliminating the need for an external SD card. 
Here's a step-by-step guide on how to upload files to ESP8266 using the Arduino IDE:

### ARDUINO IDE 1.x
https://github.com/earlephilhower/arduino-esp8266littlefs-plugin?tab=readme-ov-file

### ARDUINO IDE 2.x
https://github.com/earlephilhower/arduino-littlefs-upload

1. **Prepare Your Files**:
   - Create or gather the files (e.g., `index.html`, `style.css`, `script.js`) you want to upload to ESP8266.
   - These files should be organized in a folder structure that mirrors how they will be accessed in your code (e.g., `/index.html`, `/css/style.css`, `/js/script.js`).

2. **Convert Files to Binary**:
   - Before uploading, these files need to be converted to binary format and stored in a special folder within your Arduino sketch directory.
   - Create a folder named `data` in your Arduino sketch folder (where your `.ino` file is located). If the `data` folder doesn't exist, create it manually.



### Notes:
- **File Size Limitations**: Individual file sizes should be within the limits of your ESP8266's Flash memory. Avoid very large files as they may consume too much space or cause performance issues.
- **SPIFFS vs. LittleFS**: Choose the filesystem based on your ESP8266 board and requirements. LittleFS generally offers better performance and efficiency for larger filesystems.

By following these steps, you can effectively manage and serve web content directly from your ESP8266 module's Flash memory without the need for external storage devices. This approach is convenient for applications where simplicity and integration are key considerations.




# Audio quick guide to get up and running
Add the [Arduino Audio Driver Library](https://github.com/pschatzmann/arduino-audio-driver/tree/main) by Peter Schatzmann.

**Note:**
This library is based on the older version [Arduino Audio Kit](https://github.com/pschatzmann/arduino-audiokit) by Peter Schatzmann, which is used in some cool projects that no longer work. 
You can help make them work with the new library that is more compatible with all devices, such as [ESP32 Multitrack Looper](https://github.com/marcel-licence/esp32_multitrack_looper).

Example Code:
```
#include "AudioTools.h" // install https://github.com/pschatzmann/arduino-audio-tools
#include "AudioLibs/I2SCodecStream.h"

#define KEY1 36  // SENSOR_VP
#define KEY2 13  // TOUCH4, RTC_GPIO14
#define KEY3 19  // VSPIQ, U0CTS, EMAC_TXD0
#define KEY4 23  // HS1_STROBE, VSPID
#define KEY5 18  // HS1_DATA7, VSPICLK
#define KEY6 5   // HS1_DATA6, VSPICS0, EMAC_RX_CLK

AudioInfo info(44100, 2, 16);
SineWaveGenerator<int16_t> sineWave(32000);
GeneratedSoundStream<int16_t> sound(sineWave);
I2SCodecStream out(AudioKitEs8388V1);
StreamCopy copier(out, sound);

const int numKeys = 6;
const int keyPins[numKeys] = {KEY1, KEY2, KEY3, KEY4, KEY5, KEY6};

const int frequencies[numKeys] = { 
  2616, // C4 (example)
  2937, // D4 (example)
  3296, // E4 (example)
  3492, // F4 (example)
  3920, // G4 (example)
  4400  // A4 (example)
};

void setup() {
  // Setup logging
  Serial.begin(115200);
  AudioLogger::instance().begin(Serial, AudioLogger::Warning);
  LOGLEVEL_AUDIODRIVER = AudioDriverWarning;

  // start I2S & codec with i2c and i2s configured above
  Serial.println("starting I2S...");
  auto config = out.defaultConfig();
  config.copyFrom(info);
  out.begin(config);

  // Setup sine wave
  sineWave.begin(info, N_B4);
  for (int i = 0; i < numKeys; i++) {
    pinMode(keyPins[i], INPUT_PULLUP); // Enable internal pull-up resistors
  }
}

// Arduino loop - copy sound to out
void loop() {
  for (int i = 0; i < numKeys; i++) {
    int keyState = digitalRead(keyPins[i]);
    Serial.print("Key ");
    Serial.print(i + 1);
    Serial.print(" (Pin ");
    Serial.print(keyPins[i]);
    Serial.print("): ");
    Serial.println(keyState == LOW ? "Pressed" : "Released");

    if (keyState == LOW) { // Check if key is pressed (LOW indicates press)
      sineWave.setFrequency(frequencies[i]);
      break;
    }
  }
  copier.copy();
}
```