#pragma once
#include"System.h"
#include"Driver.h"
class Motor
{
public:
	Motor( );
	~Motor( );
	int8_t setPWM( int8_t );
	float getCounts();

private:
	MotorPort portNum;
};