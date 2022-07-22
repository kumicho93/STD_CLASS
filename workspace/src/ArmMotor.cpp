#include "../include/system.h"
#include "../include/ArmMotor.h"
#include "../include/Motor.h"

ArmMotor::ArmMotor()
{
    portNum = EV3_PORT_C;
	ev3_motor_config( static_cast<motor_port_t>(portNum), LARGE_MOTOR );
}

ArmMotor::~ArmMotor()
{
}