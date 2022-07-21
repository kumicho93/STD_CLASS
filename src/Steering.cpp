#include"Steering.h"

/* -------------------------------------------------------------------------	*/
/* 関数名		： steering														*/
/* 機能名		： コンストラクタ												*/
/* 機能概要		： メンバー変数の初期化									        */
/* 引数			： なし															*/
/* 戻り値		： なし                                     					*/
/* 作成日		： 2021/07/23		 崎山　勇人		:新規作成					*/
/* 更新日		： 2022/07/16		 山田　龍之介	:流用						*/
/* -------------------------------------------------------------------------	*/
Steering::Steering( )
{
	motor_angle.left = 0;
	motor_angle.right = 0;
}

Steering::~Steering( ) {}

/* -------------------------------------------------------------------------	*/
/* 関数名		： run									    					*/
/* 機能名		： モータ制御       											*/
/* 機能概要		： モータを制御する             								*/
/* 引数			： int32            :motor_power    :モータへの出力値			*/
/* 戻り値		： int8				:0				:正常終了					*/
/* 作成日		： 2021/07/23		 崎山　勇人		:新規作成					*/
/* 更新日		： 2022/07/16		 山田　龍之介	:流用						*/
/* -------------------------------------------------------------------------	*/
int8 Steering::run( MOTOR_POWER motor_power )
{
	//frLog &msg = frLog::GetInstance( );
	/* 引数チェック */
	if ( motor_power.left < -100 || motor_power.left > 100 ||
		motor_power.right < -100 || motor_power.right > 100 )
	{
		//msg.LOG( LOG_ID_ERR, "Steering::rotateWheel 引数エラー\n" );
		return SYS_PARAM;
	}

	/* 変数宣言 */
	int8 retChk = SYS_NG;

	/* 右モータ　PWMset */
	retChk = rightMotor.setPWM( motor_power.right );
	if ( retChk != SYS_OK ) {
		//msg.LOG( LOG_ID_ERR, "Steering::rotateWheel setPWM right err\n" );
		return retChk;
	}
	/* 左モータ　PWMset */
	retChk = leftMotor.setPWM( motor_power.left );
	if ( retChk != SYS_OK ) {
		//msg.LOG( LOG_ID_ERR, "Steering::rotateWheel setPWM left err\n" );
		return retChk;
	}

	return SYS_OK;
}

/* -------------------------------------------------------------------------	*/
/* 関数名		： getMotorAngle								    			*/
/* 機能名		： モータ角度取得       										*/
/* 機能概要		： モータ角度を取得する           								*/
/* 引数			： none															*/
/* 戻り値		： MotorAngle       :motor_angle        :角度格納用				*/
/* 作成日		： 2021/07/23		 崎山　勇人		:新規作成					*/
/* 更新日		： 2022/07/16		 山田　龍之介	:流用						*/
/* -------------------------------------------------------------------------	*/
MOTOR_ANGLE Steering::getMotorAngle( void )
{
	//frLog &msg = frLog::GetInstance( );
	return motor_angle;
}

/* -------------------------------------------------------------------------	*/
/* 関数名		： update		  								    			*/
/* 機能名		： モータ角度更新       										*/
/* 機能概要		： モータ角度を更新する           								*/
/* 引数			： なし															*/
/* 戻り値		： int8				:0				:正常終了					*/
/* 作成日		： 2021/07/23		 崎山　勇人		:新規作成					*/
/* 更新日		： 2022/07/16		 山田　龍之介	:更新						*/
/* -------------------------------------------------------------------------	*/
int8 Steering::update( )
{
	//frLog &msg = frLog::GetInstance( );
	int8 retChk = SYS_NG;                       /* エラーフラグ                    */

	/* 左モータ回転角get */
	motor_angle.left = leftMotor.getCounts( );

	/* 右モータ回転角get */
	motor_angle.right = rightMotor.getCounts( );
	
	/* 小さな誤差は真っ直ぐに進んでいる判定にする  */
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
/* 関数名		： deletePort     								    			*/
/* 機能名		：        			                							*/
/* 機能概要		： メンバー変数の解放           								*/
/* 引数			： なし															*/
/* 戻り値		： なし                                     					*/
/* 作成日		： 2021/07/23		 崎山　勇人		:新規作成					*/
/* 更新日		： 2022/07/16		 山田　龍之介	:流用						*/
/* -------------------------------------------------------------------------	*/
int8 Steering::deletePort( ) {
	//delete (&leftMotor);
	//delete (&rightMotor);
	return SYS_OK;
}


