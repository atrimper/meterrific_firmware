/**
 * @file Lcd.h
 * @brief Lcd function prototypes.
 */

#ifndef LCD_H
#define LCD_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class Lcd {
    public:
        /**
         * @brief Initialize Lcd object.
         *
         * @param RX RX pin
         * @param TX TX pin
         * @param rst reset pin
         */
        Lcd(uint8_t, uint8_t, uint8_t);

        /**
         * @brief Clear.
         *
         * Clear screen.
         */
        void clear();

        /**
         * @brief Print characters.
         *
         * Print desired characters on screen.
         *
         * @param text characters
         */
        void print(char*, int);

        /**
         * @brief Print integers.
         *
         * Print desired integers on screen.
         *
         * @param text integers
         */
        void print(int);

    private:
        uint8_t rst;
        SoftwareSerial* LcdSerial;
};

#endif /* LCD_H */