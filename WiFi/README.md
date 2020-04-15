# meterrific_firmware/WiFi
_Referred to as "WiFi code"._

## About
This WiFi code brings together multiple libraries to interact with Firebase variables.

## Prerequisites
You will need access to the following to use this WiFi code.

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
Before compiling and uploading, you must (1) make sure your Arduino is clean and (2) change your board to `Generic ESP8266 Module` to properly flash the WiFi module.

To do this,
**Part 1**
1. Connect your Arduino to your computer
2. Open a new sketch
3. In `Tools` > `Board: `, you should click on your Arduino board
4. Compile empty code
5. Upload empty code

**Part 2**
1. Download this repository to your preferred directory (e.g. `Desktop`)
2. In `Arduino IDE` > `Preferences`, change `Sketchbook Location` to `path-to-repository/WiFi/Arduino` (e.g. `~/Desktop/meterrific_firmware/WiFi/Arduino`) and click `OK` to apply changes
3. In `Tools` > `Board: `, you should click on `Generic ESP8266 Module`

## Flashing Procedure
1. Setup hardware and software as detailed above
2. Compile WiFi code
3. Attempt to upload WiFi code
4. When you see `Connecting...` printing, press the reset and flash pushbuttons at the same time
5. Release the reset pushbutton
6. When you see upload percentages printing, release the flash pushbutton