#include "Lcd.h"

Lcd::Lcd(uint8_t RX, uint8_t TX, uint8_t rst) {
    // Begin LCD UART communication
    LcdSerial = new SoftwareSerial(RX, TX);
    LcdSerial->begin(9600);

    // Set reset
    rst = rst;
    pinMode(rst, OUTPUT);
    digitalWrite(rst, LOW);
    digitalWrite(rst, HIGH);
    delay(3000);

    // Clear screen
    clear();
}

void Lcd::clear() {
    // Enter clear command
    LcdSerial->write((0xFFD7 >> 8) & 0xFF);
    LcdSerial->write(0xFFD7 & 0xFF);
    delay(24);
}

void Lcd::print(char* text, int size) {
    // Enter text color command
    LcdSerial->write((0xFF7F >> 8) & 0xFF);
    LcdSerial->write(0xFF7F & 0xFF);

    // Set white text color
    LcdSerial->write((0xFFFF >> 8) & 0xFF);
    LcdSerial->write(0xFFFF & 0xFF);
    delay(24);

    // Enter text command
    LcdSerial->write((0x0006 >> 8) & 0xFF);
    LcdSerial->write(0x0006 & 0xFF);

    // Print text
    for (int i = 0; i < size; i++) {
        LcdSerial->write(text[i]);
    }
    delay(24);
}

void Lcd::print(int text) {
    // Enter text color command
    LcdSerial->write((0xFF7F >> 8) & 0xFF);
    LcdSerial->write(0xFF7F & 0xFF);

    // Set white text color
    LcdSerial->write((0xFFFF >> 8) & 0xFF);
    LcdSerial->write(0xFFFF & 0xFF);
    delay(24);

    // Enter text command
    LcdSerial->write((0x0006 >> 8) & 0xFF);
    LcdSerial->write(0x0006 & 0xFF);

    // Print text
    LcdSerial->write(text);
    LcdSerial->write('\0');
    delay(24);
}