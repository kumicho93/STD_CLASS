#include "armAction_test.h"
/* -------------------------------------------------------------------------	*/
/* 関数名		： run									    					*/
/* 機能名		： モータ制御       											*/
/* 機能概要		： モータを制御する             								*/
/* 引数			： int32            :pwm			:モータへの出力値			*/
/* 戻り値		： int8				:0				:正常終了					*/
/* 作成日		： 2022/07/16		 山田　龍之介	:新規作成					*/
/* -------------------------------------------------------------------------	*/
int8 arm_action_test::run( int32 pwm ) 
{
	//frLog &msg = frLog::GetInstance( );
	/* 引数チェック */
	if ( pwm < -100 || pwm > 100  )
	{
		//msg.LOG( LOG_ID_ERR, "Steering::rotateWheel 引数エラー\n" );
		return SYS_PARAM;
	}

	/* 変数宣言 */
	int8 retChk = SYS_NG;

	/* アームモーター　PWMset */
	retChk = armMotor->setPWM( pwm );
	if ( retChk != SYS_OK ) {
		//msg.LOG( LOG_ID_ERR, "Steering::rotateWheel setPWM right err\n" );
		return retChk;
	}
	

	return SYS_OK;
}
/* -------------------------------------------------------------------------	*/
/* 関数名		： destroy     								    				*/
/* 機能名		：        			                							*/
/* 機能概要		： メンバー変数の解放           								*/
/* 引数			： なし															*/
/* 戻り値		： なし                                     					*/
/* 作成日		： 2022/07/16		 山田　龍之介	:新規作成					*/
/* -------------------------------------------------------------------------	*/
int8 arm_action_test::destroy( ) {
	delete (armMotor);

	return SYS_OK;
}