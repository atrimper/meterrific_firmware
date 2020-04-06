#include "src/Lidar.h"

#define SPOT_DISTANCE ? // TODO: set reasonable edge to parking spot

Lidar lidar; // TODO: see if this still works if global instead of re-initializing everytime in loop()

void setup() {
    // Communicate availability to WiFi module
    pinMode(?, OUTPUT); // TODO: from PCB, which Arduino pin is connected to WiFi module IO2
}

void loop() {
    // Transmit availability to WiFi module
    digitalWrite(?, lidar.getDistance(Lidar::METER) < SPOT_DISTANCE);  // TODO: from PCB, which Arduino pin is connected to WiFi module IO2
}