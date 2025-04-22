#pragma once

#include "Arduino.h"

class PhotoSensor
{
public:
	PhotoSensor(void);

	int readLeft(void) { return analogRead(PIN_LEFT); }
	int readMiddle(void) { return analogRead(PIN_MIDDLE); }
	int readRight(void) { return analogRead(PIN_RIGHT); }

	void print(void);

private:
	const int PIN_LEFT = A2;
	const int PIN_MIDDLE = A1;
	const int PIN_RIGHT = A0;
};
