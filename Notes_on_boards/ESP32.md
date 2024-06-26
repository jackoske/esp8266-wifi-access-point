### **DEVICE in android IDE is: ESP32 Dev module**

![[Pasted image 20240625210007.png]]
Boards may differ check all pins
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
The SPIFFS filesystem is initialized in the setup function, and its contents are printed to the serial monitor.
Files are added to SPIFFS storage using the ESP32 Sketch Data Upload tool in the Arduino IDE.
I used this tool to upload

https://github.com/me-no-dev/arduino-esp32fs-plugin/releases/

#To install
- Unpack the tool into the tools directory
   (the path will look something like `$HOME/Arduino/tools/ESP32FS/tool/esp32fs.jar`).
- Restart Arduino IDE.
