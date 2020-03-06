#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>

// TODO: enter sleep mode to save power
// TODO: check connection stability in case WiFi drops out

class AEF {
	public:
		AEF(char*, char*, char*, char*);
		int receiveData(char*);
		bool transmitData(char*);

	private:
		char* FirebaseHost;
		char* FirebaseAuth;
		char* WiFiSSID;
		char* WiFiPassword;
};
