#include "AEF.h"

AEF::AEF(char* FirebaseHost, char* FirebaseAuth, char* WiFiSSID, char* WiFiPassword) {
  // Set variables
	FirebaseHost = FirebaseHost;
	FirebaseAuth = FirebaseAuth;
	WiFiSSID = WiFiSSID;
	WiFiPassword = WiFiPassword;

  // WiFi Debug LED
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);

  // Connect to the Internet
  WiFi.begin(WiFiSSID, WiFiPassword);
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(2, HIGH);
    delay(500);
  }
  digitalWrite(2, LOW);

  // Connect to Firebase
  Firebase.begin(FirebaseHost, FirebaseAuth);
}

int AEF::receiveData(char* receiveID) {
  int data = Firebase.getInt(receiveID);
  if (Firebase.failed()) {
    return -1;
  } else {
    return data;
  }
}

bool AEF::transmitData(char* transmitID) {
  pinMode(2, INPUT);
  Firebase.set(transmitID, digitalRead(2));
  if (Firebase.failed()) {
    return false;
  } else {
    return true;
  }
}
