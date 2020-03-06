#include "AEF.h"

AEF* aef;

void setup() {
  // Initialization
  char* FirebaseHost = "meterrific-4202b.firebaseio.com";
  char* FirebaseAuth = "NfEahxyZp3F4ayCjkQsLSlFzdIpcji3kjMgQDQte";
  char* WiFiSSID = "redacted";
  char* WiFiPassword = "redacted";
  AEF* aef = new AEF(FirebaseHost, FirebaseAuth, WiFiSSID, WiFiPassword);
}

void loop() {
  // Firebase data
  char* availability = "meters/-M1hhRnEIXo3TUlF3MIe/availability";
  char* purchased = "meters/-M1hhRnEIXo3TUlF3MIe/purchased";
  char* timeRemaining = "meters/-M1hhRnEIXo3TUlF3MIe/timeRemaining";
  char* globalTime = "globalTime";
  
  // Update Spot Availability in Firebase
  bool success = false;
  while (!success) {
    success = aef->transmitData(availability);
    delay(500);
  }

  // Pull Spot Purchase Status from Firebase
  // int data = -1;
  // while (data == -1) {
  //   data = aef->receiveData(purchaseStatus);
  // }
  // TODO: send large data to Arduino without pin because pin can only handle 0 and 1
}
