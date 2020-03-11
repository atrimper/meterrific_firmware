# meterrific_firmware/WiFi
_Referred to as "wrapper"._

## About
This wrapper brings together multiple libraries to smoothly develop firmware for an ESP8266 WiFi module with Arduino.

## Prerequisites
You will need access to the following to use this wrapper.

* Arduino IDE
* Arduino
* ESP8266 WiFi Module

## Compatibility
Tested on [Arduino Uno](https://store.arduino.cc/usa/arduino-uno-rev3) and [SparkFun ESP8266 Breakout](https://www.sparkfun.com/products/13678) using [Arduino IDE 1.8.12](https://www.arduino.cc/en/main/software).

## Hardware Setup
The following table describe the necessary pin layout to flash and run firmware on the WiFi module.

| WiFi Module | Arduino | Reset Pushbutton | Flash Pushbutton |
| ---| --- | --- | --- |
| 3v3, EN | 3.3 V | | |
| RST | | Pin 1 | |
| TX | TX | | |
| RX | RX | | |
| IO1 | | | Pin 1 |
| IO2 | Digital Output | | |
| GND | GND | Pin 2 | Pin 2 |

## Software Setup
Before compiling and uploading, you must change your board to `Generic ESP8266 Module` to properly flash the WiFi module.

To do this,
1. Download this repository to your preferred directory (e.g. `Desktop`)
2. In `Arduino IDE` > `Preferences`, change `Sketchbook Location` to `path-to-repository/WiFi/Arduino` (e.g. `~/Desktop/meterrific_firmware/WiFi/Arduino`) and click `OK` to apply changes
3. In `Tools` > `Board: `, you should find `Generic ESP8266 Module`

## Flashing Procedure
1. Setup hardware and software as detailed above
2. Compile code
3. Attempt to upload code
4. When you see `Connecting...` printing, press the reset and flash pushbuttons at the same time
5. Release the reset pushbutton
6. When you see upload percentages printing, release the flash pushbutton