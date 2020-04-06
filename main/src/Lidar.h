/*
Author: Meterrific

Description:
	This file holds the structure for the Lidar class
*/

#ifndef LIDAR_H
#define LIDAR_H

#define MM_TO_INCH 0.0393701
#define MM_TO_FOOT 0.00328084
#define MM_TO_METER 0.001

#include "VL53L0X/src/Adafruit_VL53L0X.h"

/*
Purpose:
    This class functions as a wrapper for lidar measurement operations
    and is designed to function with an arduino-like processor
*/
class Lidar
{
public:
	/*
	<description>
		Constructor for a lidar sensor
	*/
    Lidar();

	/*
	<description>
        Enum holding labels for unit types used in measurement
	*/
    enum Unit
    {
        FOOT,
        INCH,
        METER,
        MILLIMETER
    };

	/*
	<description>
        Function for returning the distance measured by the lidar
        sensor in an arbitrary unit
    <input> unit, a member of Unit enum representing the desired unit
    <return> the distance measured in the given unit
	*/
    double getDistance(Unit unit);

private:
    Adafruit_VL53L0X lidar;
};

#endif
