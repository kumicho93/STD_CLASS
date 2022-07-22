#pragma once
#include "Driver.h"
#include "system.h"
#include "moter_test.h"


class arm_action_test
{
public:
	arm_action_test( );
	~arm_action_test( );
	int8 run( int32 );
	int8 destroy( );
	

private:
	Motor* armMotor;
};

arm_action_test::arm_action_test( )
{
}

arm_action_test::~arm_action_test( )
{
}