#pragma once
#include "system.h"
#include "Motor.h"
#include "../include/ArmMotor.h"

class ArmAction
{
public:
	ArmAction( );
	~ArmAction( );
	int8_t run( int32 pwm );
	int8_t destroy( void );

private:
	ArmMotor& armMotor = ArmMotor::getInstance();
};