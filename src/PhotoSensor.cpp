#include "PhotoSensor.hpp"

/**
 * @brief Constructor for the PhotoSensor class.
 *
 * This constructor initializes the pins for the left, middle, and right photo sensors
 * and sets them to INPUT mode to prepare for reading sensor values.
 */
PhotoSensor::PhotoSensor(void)
{
	pinMode(PIN_LEFT, INPUT);
	pinMode(PIN_MIDDLE, INPUT);
	pinMode(PIN_RIGHT, INPUT);
}

/**
 * @brief Prints the sensor readings to the serial monitor.
 */
void PhotoSensor::print(void)
{
	int left = readLeft();
	int middle = readMiddle();
	int right = readRight();
	Serial.print("L: " + String(left) + ", M: " + String(middle) + ", R: " + String(right) + "\n");
}
