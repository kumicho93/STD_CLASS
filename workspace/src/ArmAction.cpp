#include "../include/ArmAction.h"

int8_t ArmAction::ArmAction( int32 pwm ) 
{
	
	/* 引数チェック */
	if ( pwm < -100 || pwm > 100  )
	{
		return SYS_PARAM;
	}

	/* 変数宣言 */
	int8 retChk = SYS_NG;

	/* アームモーター　PWMset */
	retChk = armMotor.setPWM( pwm );
	if ( retChk != SYS_OK ) {
		return retChk;
	}	

	return SYS_OK;
}

int8_t ArmAction::destroy( ) {
	delete (armMotor);

	return SYS_OK;
}