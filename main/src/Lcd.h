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
         * @brief Print character array.
         *
         * Print desired characters on screen.
         *
         * @param text characters
         * @param size length of array
         */
        void print(char*, int);

        /**
         * @brief Print characters via ASCII.
         *
         * Print desired ASCII values on screen.
         *
         * @param text ASCII values
         */
        void print(int);

    private:
        uint8_t rst;
        SoftwareSerial* LcdSerial;
};

#endif /* LCD_H */