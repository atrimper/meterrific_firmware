#include "AEF.h"

AEF::AEF(char* FirebaseHost, char* FirebaseKey, char* WiFiSsid, char* WiFiPassword) {
    // Set variables
    FirebaseHost = FirebaseHost;
    FirebaseKey = FirebaseKey;
    WiFiSsid = WiFiSsid;
    WiFiPassword = WiFiPassword;

    // Connect to the Internet
    WiFi.begin(WiFiSsid, WiFiPassword);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    // Connect to Firebase
    Firebase.begin(FirebaseHost, FirebaseKey);
}

int AEF::getFirebase(char* id) {
    return Firebase.getInt(id);
}

bool AEF::setFirebase(char* id, int data) {
    Firebase.set(id, data);
    delay(500);
    if (Firebase.failed()) {
        return false;
    } else {
        return true;
    }
}