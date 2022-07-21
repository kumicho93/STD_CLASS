#pragma once
#include"System.h"
#include"Motor.h"

class RightMotor:public Motor
{
private:
    /* data */
    //motor_port_t right_motor;

    RightMotor();
    ~RightMotor();
    RightMotor( const RightMotor &x );
	RightMotor&operator=( const RightMotor & ) { return *this; };
public:
    

    static RightMotor &getInstance( )
	{
		static RightMotor RightMotor_;
		return RightMotor_;
	}
};


