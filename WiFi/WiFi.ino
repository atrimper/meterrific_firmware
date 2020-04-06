#include "AEF.h"

#define FIREBASE_HOST "meterrific-4202b.firebaseio.com"
#define FIREBASE_KEY "NfEahxyZp3F4ayCjkQsLSlFzdIpcji3kjMgQDQte"
#define WIFI_SSID "ssid"
#define WIFI_PASSWORD "password"
#define AVAILABILITY_ID "meters/-M1hhRnEIXo3TUlF3MIe/availability"

AEF* aef;

void setup() {
    // Class initialization
    AEF* aef = new AEF(FIREBASE_HOST, FIREBASE_KEY, WIFI_SSID, WIFI_PASSWORD);

    // Read availability from Arduino
    pinMode(2, INPUT);
}

void loop() {
    // Update availability in Firebase
    bool success = false;
    while (!success) {
        success = aef->setFirebase(AVAILABILITY_ID, digitalRead(2));
        delay(500);
    }
}