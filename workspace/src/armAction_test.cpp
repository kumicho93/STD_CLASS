#include "armAction_test.h"
/* -------------------------------------------------------------------------	*/
/* �֐���		�F run									    					*/
/* �@�\��		�F ���[�^����       											*/
/* �@�\�T�v		�F ���[�^�𐧌䂷��             								*/
/* ����			�F int32            :pwm			:���[�^�ւ̏o�͒l			*/
/* �߂�l		�F int8				:0				:����I��					*/
/* �쐬��		�F 2022/07/16		 �R�c�@���V��	:�V�K�쐬					*/
/* -------------------------------------------------------------------------	*/
int8 arm_action_test::run( int32 pwm ) 
{
	//frLog &msg = frLog::GetInstance( );
	/* �����`�F�b�N */
	if ( pwm < -100 || pwm > 100  )
	{
		//msg.LOG( LOG_ID_ERR, "Steering::rotateWheel �����G���[\n" );
		return SYS_PARAM;
	}

	/* �ϐ��錾 */
	int8 retChk = SYS_NG;

	/* �A�[�����[�^�[�@PWMset */
	retChk = armMotor->setPWM( pwm );
	if ( retChk != SYS_OK ) {
		//msg.LOG( LOG_ID_ERR, "Steering::rotateWheel setPWM right err\n" );
		return retChk;
	}
	

	return SYS_OK;
}
/* -------------------------------------------------------------------------	*/
/* �֐���		�F destroy     								    				*/
/* �@�\��		�F        			                							*/
/* �@�\�T�v		�F �����o�[�ϐ��̉��           								*/
/* ����			�F �Ȃ�															*/
/* �߂�l		�F �Ȃ�                                     					*/
/* �쐬��		�F 2022/07/16		 �R�c�@���V��	:�V�K�쐬					*/
/* -------------------------------------------------------------------------	*/
int8 arm_action_test::destroy( ) {
	delete (armMotor);

	return SYS_OK;
}