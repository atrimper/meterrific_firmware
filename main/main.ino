#include "src\Lidar.h"

double measurement;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Lidar lidar;
  while(true)
  {
      measurement = lidar.getDistance(Lidar::METER);
      Serial.print("Measured Distance: ");
      Serial.println(measurement);
  }
}
