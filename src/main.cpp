#include "Arduino.h"

#include "Motor.hpp"
#include "PhotoSensor.hpp"

#ifndef NDEBUG
#define NDEBUG
#endif

#define S2 2 // pin number of S2 on hat

const static int DRIVE_SPEED = 64;
const static int TURN_SPEED = -DRIVE_SPEED + (DRIVE_SPEED / 4);

Motor motors;
PhotoSensor ps;

void setup()
{
	pinMode(S2, INPUT);
	Serial.begin(9600);
}

void loop()
{
	// If S2 on the shield is pressed, stop the robot and halt infinitely
	if (digitalRead(S2) == 0) {
#ifndef NDEBUG
		Serial.println("Halting");
#endif
		motors.Drive(0, 0);
		while (1)
			;
	}
	if (ps.left()) {
		motors.Drive(TURN_SPEED, DRIVE_SPEED);
#ifndef NDEBUG
		Serial.print("Turning Left: ");
		ps.print();
#endif
	} else if (ps.right()) {
		motors.Drive(DRIVE_SPEED, TURN_SPEED);
#ifndef NDEBUG
		Serial.print("Turning Right: ");
		ps.print();
#endif
	} else if (ps.middle()) {
		motors.Drive(DRIVE_SPEED, DRIVE_SPEED);
	}
	// Short delay to avoid responding quicker than the hardware and mechanics can react
	delay(33);
}
