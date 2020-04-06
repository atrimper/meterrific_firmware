#include "src/Lidar.h"

#define SPOT_DISTANCE ? // TODO: set reasonable edge to parking spot

Lidar lidar; // TODO: see if this still works if global instead of re-initializing everytime in loop()

void setup() {
    // Communicate availability to WiFi module
    pinMode(2, OUTPUT); // TODO: from PCB, which Arduino pin is connected to WiFi module IO2

    // Test without LIDAR
    // Serial.begin(9600);
}

void loop() {
    // Transmit availability to WiFi module
    digitalWrite(?, lidar.getDistance(Lidar::METER) < SPOT_DISTANCE);  // TODO: from PCB, which Arduino pin is connected to WiFi module IO2

    // Test without LIDAR
    // if (Serial.available() > 0) {
    //     int availability = Serial.read();
    //     if (availability == '0') {
    //         digitalWrite(2, LOW);
    //     } else if (availability == '1') {
    //         digitalWrite(2, HIGH);
    //     }
    // }
}
