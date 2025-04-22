#include "Motor.hpp"
#include "Arduino.h"

/**
 * @brief Constructor for the Motor class.
 *
 * This constructor initializes the motor control pins and sets them
 * to OUTPUT mode. It also prints an initialization message to the
 * serial monitor for debugging purposes.
 */
Motor::Motor(void)
{
	Serial.println("Initializing Motors");
	pinMode(PIN_Motor_PWMA, OUTPUT);
	pinMode(PIN_Motor_PWMB, OUTPUT);
	pinMode(PIN_Motor_AIN_1, OUTPUT);
	pinMode(PIN_Motor_BIN_1, OUTPUT);
	pinMode(PIN_Motor_STBY, OUTPUT);
}

/**
 * @brief Drives the motor by setting the speeds for the right and left motors.
 *
 * This function validates the input speeds, logs the operation to the serial monitor,
 * and adjusts the motor control pins accordingly. If both speeds are zero, the motors
 * are put into standby mode. Otherwise, the motors are activated, and the specified
 * speeds are applied.
 *
 * @param speedRight The speed for the right motors (range: -MAX_SPEED to MAX_SPEED).
 * @param speedLeft The speed for the left motors (range: -MAX_SPEED to MAX_SPEED).
 */
void Motor::Drive(const int speedRight, const int speedLeft)
{
	// Validate speeds
	if (speedRight > MAX_SPEED || speedRight < -MAX_SPEED || speedLeft > MAX_SPEED || speedLeft < -MAX_SPEED) {
		Serial.print("Invalid speeds - Right: ");
		Serial.print(speedRight);
		Serial.print(", Left: ");
		Serial.println(speedLeft);
		return;
	}

	Serial.print("Setting speeds - Right: ");
	Serial.print(speedRight);
	Serial.print(", Left: ");
	Serial.println(speedLeft);

	// Handle zero-speed case
	if (speedRight == 0 && speedLeft == 0) {
		digitalWrite(PIN_Motor_STBY, LOW);
		analogWrite(PIN_Motor_PWMA, 0);
		analogWrite(PIN_Motor_PWMB, 0);
		return;
	}

	// Take motors out of standby and set speeds
	digitalWrite(PIN_Motor_STBY, HIGH);
	setSpeedRight(speedRight);
	setSpeedLeft(speedLeft);
}

/**
 * @brief Sets the speed and direction of the right motors.
 *
 * @param speed The speed of the motor (positive for forward, negative for reverse).
 */
void Motor::setSpeedRight(const int speed)
{
	bool direction = speed > 0;
	digitalWrite(PIN_Motor_AIN_1, direction ? HIGH : LOW);
	analogWrite(PIN_Motor_PWMA, static_cast<uint8_t>(abs(speed)));
}

/**
 * @brief Sets the speed and direction of the left motors.
 *
 * @param speed The speed of the motor (positive for forward, negative for reverse).
 */
void Motor::setSpeedLeft(const int speed)
{
	bool direction = speed > 0;
	digitalWrite(PIN_Motor_BIN_1, direction ? HIGH : LOW);
	analogWrite(PIN_Motor_PWMB, static_cast<uint8_t>(abs(speed)));
}
