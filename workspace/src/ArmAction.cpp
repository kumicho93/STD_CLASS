#include "../include/ArmAction.h"

int8_t ArmAction::ArmAction( int32 pwm ) 
{
	
	/* �����`�F�b�N */
	if ( pwm < -100 || pwm > 100  )
	{
		return SYS_PARAM;
	}

	/* �ϐ��錾 */
	int8 retChk = SYS_NG;

	/* �A�[�����[�^�[�@PWMset */
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