/**
 * @file AEF.h
 * @brief AEF function prototypes.
 */

#ifndef AEF_H
#define AEF_H

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>

class AEF {
    public:
        /**
         * @brief Initialize AEF object.
         *
         * @param FirebaseHost Firebase host address
         * @param FirebaseKey Firebase secret key
         * @param WiFiSsid WiFi name
         * @param WiFiPassword WiFi password
         */
        AEF(char*, char*, char*, char*);

        /**
         * @brief Get Firebase data.
         *
         * Get data of variable from Firebase.
         *
         * @param id path to variable
         *
         * @return data
         */
        int getFirebase(char*);

        /**
         * @brief Set Firebase data.
         *
         * Set data of variable in Firebase.
         *
         * @param id path to variable
         * @param data data
         *
         * @return success
         */
        bool setFirebase(char*, int);

    private:
        char* FirebaseHost;
        char* FirebaseAuth;
        char* WiFiSsid;
        char* WiFiPassword;
};

#endif /* AEF_H */