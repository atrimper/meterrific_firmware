# meterrific_firmware
_Repository for Meterrific firmware artifacts._

## Directory Structure
Directory structure is special to allow use of Arduino IDE
file named "main.ino" must be in the folder named "main"
any libaries used in "main.ino" must be somewhere under the "main/src" folder
#includes in "main.ino" follow -> "src\<path_to_your_file>"

## Flashing Procedure
You must flash the WiFi module and then flash the Arduino to run both codes simultaneously.

1. Follow the Flashing Procedure in `WiFi/README.md`
2. Follow the Flashing Procedure in `main/README.md`