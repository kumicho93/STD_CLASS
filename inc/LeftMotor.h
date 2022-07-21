#pragma once
#include"System.h"
#include"Motor.h"

class LeftMotor:public Motor
{
private:
    /* data */
    //motor_port_t left_motor;

    LeftMotor();
    ~LeftMotor();
    LeftMotor( const LeftMotor &x );
	LeftMotor&operator=( const LeftMotor & ) { return *this; };
public:

    static LeftMotor &getInstance( )
	{
		static LeftMotor LeftMotor_;
		return LeftMotor_;
	}
};