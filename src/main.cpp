#include "Arduino.h"

#include "Motor.hpp"
#include "PhotoSensor.hpp"

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

#define S2 2 // pin number of S2 on hat

const int TEST_SPEED = 64;
const int DRIVE_SPEED = 32;
const int BLK_THRES = 1000;

Motor motors;
PhotoSensor ps;
uint8_t speed = 0;

void setup()
{
	// initialize LED digital pin as an output.
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(S2, INPUT);
	Serial.begin(9600);

	if (TEST_SPEED != 0) {
		// Testing drive functionality
		Serial.println("Testing drive functionality");
		motors.Drive(TEST_SPEED, 0);
		delay(1000);
		motors.Drive(0, TEST_SPEED);
		delay(1000);
		motors.Drive(TEST_SPEED, TEST_SPEED);
		delay(1000);
		motors.Drive(-TEST_SPEED, 0);
		delay(1000);
		motors.Drive(0, -TEST_SPEED);
		delay(1000);
		motors.Drive(-TEST_SPEED, -TEST_SPEED);
		delay(1000);
		motors.Drive(0, 0);
		Serial.println("Drive testing complete");
	}
}

void loop()
{
	if (digitalRead(S2) == 0) {
		Serial.println("Halting");
		motors.Drive(0, 0);
		while (1)
			;
	}
	ps.print();
	if (ps.readLeft() > BLK_THRES) {
		motors.Drive(DRIVE_SPEED, 0);
	} else if (ps.readRight() > BLK_THRES) {
		motors.Drive(0, DRIVE_SPEED);
	} else if (ps.readMiddle() > BLK_THRES) {
		motors.Drive(DRIVE_SPEED, DRIVE_SPEED);
	}
	delay(100);
}
