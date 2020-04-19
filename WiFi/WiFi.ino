#include "AEF.h"

// Meter Properties
#define FIREBASE_HOST "meterrific-4202b.firebaseio.com"
#define FIREBASE_KEY "NfEahxyZp3F4ayCjkQsLSlFzdIpcji3kjMgQDQte"
#define WIFI_SSID "ssid"
#define WIFI_PASSWORD "password"
#define TIME_REMAINING_ID "meters/-M4tl72ppJpQcdsJnCPB/timeRemaining"

// Global
AEF* aef;

void setup() {
    // Initialization Firebase communication
    aef = new AEF(FIREBASE_HOST, FIREBASE_KEY, WIFI_SSID, WIFI_PASSWORD);

    // Begin communication with Arduino
    Serial.begin(9600);
}

void loop() {
    // Get time remaining from Firebase and transmit to Arduino
    int timeRemaining = aef->getFirebase(TIME_REMAINING_ID);
    Serial.print(timeRemaining, DEC);

    // Rest delay
    delay(5000);
}
