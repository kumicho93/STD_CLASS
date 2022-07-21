#include "System.h"
#include "Motor.h"

Motor::Motor( )
{
	//ev3_motor_config( static_cast<motor_port_t>(port), type );
}

Motor::~Motor( )
{
}

/* -------------------------------------------------------------------------	*/
/* �֐���		�F setPWM				                	    				*/
/* �@�\��		�F                                     							*/
/* �@�\�T�v		�F �w�肵���o�͒l�Ń��[�^�𓮂���           					*/
/* ����			�F int8_t           :motorPower     :�o�͒l						*/
/* �߂�l		�F int8_t			:0				:����I��					*/
/* �쐬��		�F 2021/07/23		 ��R�@�E�l		:�V�K�쐬					*/
/* �X�V��		�F 2022/07/16		 �R�c�@���V��	:���p						*/
/* -------------------------------------------------------------------------	*/
int8_t Motor::setPWM(int8_t motorPower)
{
	//frLog &msg = frLog::GetInstance( );

	if ( motorPower < -100 || motorPower > 100 )
	{
		//msg.LOG( LOG_ID_ERR, "Motor.setPWM �����G���[\n" );
		return SYS_PARAM;
	}

	//ev3_motor_set_power( static_cast<motor_port_t>(portNum), motorPower );

	return SYS_OK;
}

/* -------------------------------------------------------------------------	*/
/* �֐���		�F getCounts				            		    			*/
/* �@�\��		�F ���[�^�p�x�̎擾                  							*/
/* �@�\�T�v		�F ���[�^�p�x�̎擾                 							*/
/* ����			�F none															*/
/* �߂�l		�F int32            :motorAngle		:��]�p�x					*/
/* �쐬��		�F 2021/07/23		 ��R�@�E�l		:�V�K�쐬					*/
/* �X�V��		�F 2022/07/16		 �R�c�@���V��	:���p						*/
/* -------------------------------------------------------------------------	*/
float Motor::getCounts(void)
{
	//frLog &msg = frLog::GetInstance( );
	float motorAngle = 0.0f;

	//motorAngle = ev3_motor_get_counts( static_cast<motor_port_t>(portNum) );

	return motorAngle;
}
