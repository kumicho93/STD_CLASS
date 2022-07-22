#pragma once
#include"system.h"
#include"Motor.h"

class ArmMotor:public Motor
{
private:
    /* data */
    //motor_port_t left_motor;
    ArmMotor();
    ~ArmMotor();
    ArmMotor( const ArmMotor &x );
	ArmMotor&operator=( const ArmMotor & ) { return *this; };
public:
    

    static ArmMotor &getInstance( )
	{
		static ArmMotor ArmMotor_;
		return ArmMotor_;
	}
};

