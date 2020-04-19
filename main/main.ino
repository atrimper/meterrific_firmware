#include "src/Lcd.h"
#include <math.h>
#include <string.h>

// Globals
Lcd* lcd;
SoftwareSerial* WiFiSerial;

void setup() {
    // Initialize WiFi communication
    WiFiSerial = new SoftwareSerial(6, 7);
    WiFiSerial->begin(9600);

    // Initialize LCD communication
    lcd = new Lcd(3, 4, 5);

    // Receive only from WiFi module
    WiFiSerial->listen();
 
    // Catch-up delay
    delay(3000);
}

void loop() {
    // Receive time remaining from WiFi module and print on LCD
    if (WiFiSerial->available() > 0) {
        lcd->clear();
        int buffer[5];
        int len = 0;
        while (WiFiSerial->available() > 0) {
            buffer[len] = WiFiSerial->read();
            len = len + 1;
        }
        if (buffer[0] == 45 || buffer[0] == 48) {
            lcd->print("\n\n\n\nPAY ELECTRONICALLY\n  WITH METERRIFIC\n\n\n\n OR PAY PHYSICALLY\nWITH PARKING METER", 84);
        } else {
            lcd->print("\n\n\n\n\n  TIME REMAINING\n   ", 26);
            int timeRemaining = 0;
            for (int i = 0; i < len; i = i + 1) {
                timeRemaining = timeRemaining + (buffer[i] - 48)*pow(10, len-1)/pow(10, i);
            }
            timeRemaining = (int)(timeRemaining/60);
            char timeRemaining_str[4];
            itoa(timeRemaining, timeRemaining_str, 10);
            len = floor(log10(abs(timeRemaining))) + 1;
            lcd->print(timeRemaining_str, len+1);
            lcd->print(" MINUTES", 9);
        }
    } else {
        lcd->clear();
        lcd->print("\n\n\n\n\n\n  PAY PHYSICALLY\nWITH PARKING METER", 42);
    }

    // Rest delay
    delay(5000);
}
