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
/* 関数名		： setPWM				                	    				*/
/* 機能名		：                                     							*/
/* 機能概要		： 指定した出力値でモータを動かす           					*/
/* 引数			： int8_t           :motorPower     :出力値						*/
/* 戻り値		： int8_t			:0				:正常終了					*/
/* 作成日		： 2021/07/23		 崎山　勇人		:新規作成					*/
/* 更新日		： 2022/07/16		 山田　龍之介	:流用						*/
/* -------------------------------------------------------------------------	*/
int8_t Motor::setPWM(int8_t motorPower)
{
	//frLog &msg = frLog::GetInstance( );

	if ( motorPower < -100 || motorPower > 100 )
	{
		//msg.LOG( LOG_ID_ERR, "Motor.setPWM 引数エラー\n" );
		return SYS_PARAM;
	}

	//ev3_motor_set_power( static_cast<motor_port_t>(portNum), motorPower );

	return SYS_OK;
}

/* -------------------------------------------------------------------------	*/
/* 関数名		： getCounts				            		    			*/
/* 機能名		： モータ角度の取得                  							*/
/* 機能概要		： モータ角度の取得                 							*/
/* 引数			： none															*/
/* 戻り値		： int32            :motorAngle		:回転角度					*/
/* 作成日		： 2021/07/23		 崎山　勇人		:新規作成					*/
/* 更新日		： 2022/07/16		 山田　龍之介	:流用						*/
/* -------------------------------------------------------------------------	*/
float Motor::getCounts(void)
{
	//frLog &msg = frLog::GetInstance( );
	float motorAngle = 0.0f;

	//motorAngle = ev3_motor_get_counts( static_cast<motor_port_t>(portNum) );

	return motorAngle;
}
