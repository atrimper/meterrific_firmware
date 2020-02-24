/*
Author: Meterrific

Description:
	This file holds the implementation for the Lidar class
*/
#include "Lidar.h"

Lidar::Lidar() : lidar()
{
    // Starts the opertation of the lidar object
    lidar.begin();
}

double Lidar::getDistance(Lidar::Unit unit)
{
    // Get the raw distance measurement in millimeters
    VL53L0X_RangingMeasurementData_t measurement;
    lidar.getSingleRangingMeasurement(&measurement, false);
    double mmMeasurement = measurement.RangeMilliMeter;

    // Limit the distance measurement to the max for the sensor
    if (mmMeasurement > 1000)
    {
        mmMeasurement = 1000;
    }

    // Make unit conversion according to given unit
    double retVal = 0;
    switch (unit)
    {
        case(FOOT):
            retVal = mmMeasurement * MM_TO_FOOT;
            break;
        case(INCH):
            retVal = mmMeasurement * MM_TO_INCH;
            break;
        case(METER):
            retVal = mmMeasurement * MM_TO_METER;
            break;
        case(MILLIMETER):
            retVal = mmMeasurement;
            break;
    }
    return retVal;
}
