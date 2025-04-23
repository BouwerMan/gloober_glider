#pragma once

#include "Arduino.h"

class PhotoSensor
{
public:
	PhotoSensor(void);

	bool left(void) { return readLeft() > LEFT_THRES; }
	bool middle(void) { return readMiddle() > MIDDLE_THRES; }
	bool right(void) { return readRight() > RIGHT_THRES; }

	int readLeft(void) { return analogRead(PIN_LEFT); }
	int readMiddle(void) { return analogRead(PIN_MIDDLE); }
	int readRight(void) { return analogRead(PIN_RIGHT); }

	void print(void);

private:
	const static int PIN_LEFT = A2;
	const static int PIN_MIDDLE = A1;
	const static int PIN_RIGHT = A0;

	/// Calculations for various black level thresholds

	/// Each floor is taken from the robot sitting above a white page of paper. This is used as a "0" value
	const static int LEFT_FLOOR = 400;
	const static int MIDDLE_FLOOR = 45;
	const static int RIGHT_FLOOR = 45;

	/// How much higher than floor should the threshold be
	constexpr static double THRES_MULT = 1.5;

	/// Black thresholds for each sensor
	constexpr static int LEFT_THRES = LEFT_FLOOR * THRES_MULT;
	constexpr static int MIDDLE_THRES = MIDDLE_FLOOR * THRES_MULT;
	constexpr static int RIGHT_THRES = RIGHT_FLOOR * THRES_MULT;
};
