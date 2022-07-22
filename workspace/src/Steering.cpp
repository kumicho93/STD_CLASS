#include"../inc/Steering.h"

/* -------------------------------------------------------------------------	*/
/* �֐���		�F steering														*/
/* �@�\��		�F �R���X�g���N�^												*/
/* �@�\�T�v		�F �����o�[�ϐ��̏�����									        */
/* ����			�F �Ȃ�															*/
/* �߂�l		�F �Ȃ�                                     					*/
/* �쐬��		�F 2021/07/23		 ��R�@�E�l		:�V�K�쐬					*/
/* �X�V��		�F 2022/07/16		 �R�c�@���V��	:���p						*/
/* -------------------------------------------------------------------------	*/
Steering::Steering( )
{
	motor_angle.left = 0;
	motor_angle.right = 0;
}

Steering::~Steering( ) {}

/* -------------------------------------------------------------------------	*/
/* �֐���		�F run									    					*/
/* �@�\��		�F ���[�^����       											*/
/* �@�\�T�v		�F ���[�^�𐧌䂷��             								*/
/* ����			�F int32            :motor_power    :���[�^�ւ̏o�͒l			*/
/* �߂�l		�F int8				:0				:����I��					*/
/* �쐬��		�F 2021/07/23		 ��R�@�E�l		:�V�K�쐬					*/
/* �X�V��		�F 2022/07/16		 �R�c�@���V��	:���p						*/
/* -------------------------------------------------------------------------	*/
int8 Steering::run( MOTOR_POWER motor_power )
{
	//frLog &msg = frLog::GetInstance( );
	/* �����`�F�b�N */
	if ( motor_power.left < -100 || motor_power.left > 100 ||
		motor_power.right < -100 || motor_power.right > 100 )
	{
		//msg.LOG( LOG_ID_ERR, "Steering::rotateWheel �����G���[\n" );
		return SYS_PARAM;
	}

	/* �ϐ��錾 */
	int8 retChk = SYS_NG;

	/* �E���[�^�@PWMset */
	retChk = rightMotor.setPWM( motor_power.right );
	if ( retChk != SYS_OK ) {
		//msg.LOG( LOG_ID_ERR, "Steering::rotateWheel setPWM right err\n" );
		return retChk;
	}
	/* �����[�^�@PWMset */
	retChk = leftMotor.setPWM( motor_power.left );
	if ( retChk != SYS_OK ) {
		//msg.LOG( LOG_ID_ERR, "Steering::rotateWheel setPWM left err\n" );
		return retChk;
	}

	return SYS_OK;
}

/* -------------------------------------------------------------------------	*/
/* �֐���		�F getMotorAngle								    			*/
/* �@�\��		�F ���[�^�p�x�擾       										*/
/* �@�\�T�v		�F ���[�^�p�x���擾����           								*/
/* ����			�F none															*/
/* �߂�l		�F MotorAngle       :motor_angle        :�p�x�i�[�p				*/
/* �쐬��		�F 2021/07/23		 ��R�@�E�l		:�V�K�쐬					*/
/* �X�V��		�F 2022/07/16		 �R�c�@���V��	:���p						*/
/* -------------------------------------------------------------------------	*/
MOTOR_ANGLE Steering::getMotorAngle( void )
{
	//frLog &msg = frLog::GetInstance( );
	return motor_angle;
}

/* -------------------------------------------------------------------------	*/
/* �֐���		�F update		  								    			*/
/* �@�\��		�F ���[�^�p�x�X�V       										*/
/* �@�\�T�v		�F ���[�^�p�x���X�V����           								*/
/* ����			�F �Ȃ�															*/
/* �߂�l		�F int8				:0				:����I��					*/
/* �쐬��		�F 2021/07/23		 ��R�@�E�l		:�V�K�쐬					*/
/* �X�V��		�F 2022/07/16		 �R�c�@���V��	:�X�V						*/
/* -------------------------------------------------------------------------	*/
int8 Steering::update( )
{
	//frLog &msg = frLog::GetInstance( );
	int8 retChk = SYS_NG;                       /* �G���[�t���O                    */

	/* �����[�^��]�pget */
	motor_angle.left = leftMotor.getCounts( );

	/* �E���[�^��]�pget */
	motor_angle.right = rightMotor.getCounts( );
	
	/* �����Ȍ덷�͐^�������ɐi��ł��锻��ɂ���  */
	if ( motor_angle.right - motor_angle.left < 3 &&
		motor_angle.right - motor_angle.left>0 ) {

		motor_angle.left = motor_angle.right;
	}
	else if ( motor_angle.left - motor_angle.right < 3 &&
		motor_angle.left - motor_angle.right>0 ) {

		motor_angle.right = motor_angle.left;
	}

	return SYS_OK;
}
/* -------------------------------------------------------------------------	*/
/* �֐���		�F deletePort     								    			*/
/* �@�\��		�F        			                							*/
/* �@�\�T�v		�F �����o�[�ϐ��̉��           								*/
/* ����			�F �Ȃ�															*/
/* �߂�l		�F �Ȃ�                                     					*/
/* �쐬��		�F 2021/07/23		 ��R�@�E�l		:�V�K�쐬					*/
/* �X�V��		�F 2022/07/16		 �R�c�@���V��	:���p						*/
/* -------------------------------------------------------------------------	*/
int8 Steering::deletePort( ) {
	//delete (&leftMotor);
	//delete (&rightMotor);
	return SYS_OK;
}


