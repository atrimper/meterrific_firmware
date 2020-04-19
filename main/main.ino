// #include "src/Lidar.h"
#include "src/Lcd.h"

// Meter Properties
// #define SPOT_DISTANCE 0.8 // TODO: set reasonable edge to parking spot

// Globals
// Lidar lidar; // TODO: see if this still works as global instead of re-initializing everytime in loop()
Lcd* lcd;
SoftwareSerial* WiFiSerial;

void setup() {
    // Communicate availability to WiFi module
    pinMode(2, INPUT); // TODO: comment if using LIDAR

    // Test without LIDAR using serial monitor
    // Serial.begin(9600);

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
    // Test without LIDAR using serial monitor
    // if (Serial.available() > 0) {
    //     int availability = Serial.read();
    //     if (availability == '0') {
    //         digitalWrite(2, LOW);
    //     } else if (availability == '1') {
    //         digitalWrite(2, HIGH);
    //     }
    // }

    // Transmit availability to WiFi module
    int availability = digitalRead(2); // TODO: replace with lidar.getDistance(Lidar::METER) < SPOT_DISTANCE;
    WiFiSerial->write(availability);

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
            for(int i = 0; i < len; i = i + 1) {
                timeRemaining = timeRemaining + buffer[i]*pow(10, len-1)/pow(10, i);
            }
            lcd->print(timeRemaining);
            lcd->print(" MINUTES", 9);
        }
    } else {
        lcd->clear();
        lcd->print("\n\n\n\n\n\n  PAY PHYSICALLY\nWITH PARKING METER", 42);
    }

    // Rest delay
    delay(5000);
}
