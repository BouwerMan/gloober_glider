#pragma once

class Motor
{
public:
	Motor(void);
	void Drive(const int speedRight, const int speedLeft);

private:
	const int PIN_Motor_PWMA = 5;
	const int PIN_Motor_PWMB = 6;
	const int PIN_Motor_BIN_1 = 8;
	const int PIN_Motor_AIN_1 = 7;
	const int PIN_Motor_STBY = 3;
	const int MAX_SPEED = 255;

	void setSpeedRight(const int speed);
	void setSpeedLeft(const int speed);
};
