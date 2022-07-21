#include "CarData.h"

/* -------------------------------------------------------------------------	*/
/* 関数名		： CarPosition				              	    				*/
/* 機能名		： コンストラクタ                                  				*/
/* 機能概要		： 座標と向きの初期化                          					*/
/* 引数			： なし															*/
/* 戻り値		： なし                                     					*/
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成					*/
/* 作成日		： 2022/07/16		 山田　龍之介	:新規作成					*/
/* -------------------------------------------------------------------------	*/
CarData::CarData( )
{
	angle = 0.0f;

	position.x = 0 * 0.3527 * 2;
	position.y = 0 * 0.3527 * 2;
}

CarData::~CarData( ) {}
/* -------------------------------------------------------------------------	*/
/* 関数名		： update									    				*/
/* 機能名		： 更新       													*/
/* 機能概要		： 自己位置を更新する                   						*/
/* 引数			： なし															*/
/* 戻り値		： int8				:0				:正常終了					*/
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成					*/
/* 作成日		： 2022/07/16		 山田　龍之介	:新規作成					*/
/* -------------------------------------------------------------------------	*/
int8 CarData::update( )
{
	//frLog &msg = frLog::GetInstance( );
	int8 retChk = SYS_NG;
	Steering &steering = Steering::getInstance( );
	MOTOR_ANGLE preAngle;
	MOTOR_ANGLE nowAngle;
	WheelDist wheelDist;

	memset( &preAngle, 0, sizeof( MOTOR_ANGLE ) );
	memset( &nowAngle, 0, sizeof( MOTOR_ANGLE ) );
	memset( &wheelDist, 0, sizeof( WheelDist ) );

	/* モータの角度差異取得 -------------------------------------------- */

	// 前回モータ角度取得
	preAngle = steering.getMotorAngle( );
	
	// モータ角度更新
	retChk = steering.update( );
	if ( retChk != SYS_OK ) {
		//msg.LOG( LOG_ID_ERR, "CarPos::update updateAngle err\n" );
		return retChk;
	}

	// 最新モータ角度取得
	nowAngle = steering.getMotorAngle( );

	wheelDist.left = (float)(nowAngle.left - preAngle.left);
	wheelDist.right = (float)(nowAngle.right - preAngle.right);

	wheelDist.left *= DIST;
	wheelDist.right *= DIST;

	/* 計算し更新 */
	retChk = calcOdometry( &wheelDist );
	if ( retChk != SYS_OK ) {
		//msg.LOG( LOG_ID_ERR, "CarPos::update calcOdometry err\n" );
		return retChk;
	}
	
	if ( angle >= 600 || angle <= -600 ) {
		//msg.LOG( LOG_ID_ERR, "車体角度が異常のため強制終了\n" );
		
		act_tsk( END_TASK );
		return SYS_NG;
	}
	return SYS_OK;
}

/* -------------------------------------------------------------------------	*/
/* 関数名		： calcOdometry								    				*/
/* 機能名		： オドメトリ計算 												*/
/* 機能概要		： オドメトリ計算を行う                   	   					*/
/* 引数			： WheelDist*       :wheel_dist     :両モータの差分				*/
/* 戻り値		： int8				:0				:正常終了					*/
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成					*/
/* 作成日		： 2022/07/16		 山田　龍之介	:新規作成					*/
/* -------------------------------------------------------------------------	*/
int8 CarData::calcOdometry( WheelDist* wheel_dist )
{
	//frLog &msg = frLog::GetInstance( );
	if ( wheel_dist == NULL ) {
		//msg.LOG( LOG_ID_ERR, "CarPosition::calcOdometry 引数エラー\n" );
		return SYS_PARAM;
	}
	float  angle = 0.0f;
	double dist = 0.0f;
	double rad = 0.0f;
	double addRad = 0.0f;
	CORDINATE addPos;

	memset( &addPos, 0, sizeof( CORDINATE ) );

	/* 座標計算 */
	dist = (double)(wheel_dist->right + wheel_dist->left) / 2.0;
	angle = (360.0f / (2.0f * PI * CAR_WIDTH)) * (wheel_dist->left - wheel_dist->right);

	/* 角度をラジアン変換 */
	addRad = ((double)(angle)) * (PI / 180.0f);
	rad = ((double)(angle)) * (PI / 180.0f);

	/* /2.0fいるかわかんない */
	addPos.x = (float)-(dist * std::sin( rad + addRad / 2.0f ));
	addPos.y = (float)(dist * std::cos( rad + addRad / 2.0f ));

	/* 座標更新 */
	position.x += addPos.x;
	position.y += addPos.y;

	/* 角度更新 */
	angle += angle;

	return SYS_OK;
}
/* -------------------------------------------------------------------------	*/
/* 関数名		： getPos							    	    				*/
/* 機能名		： 自己位置座標を取得 											*/
/* 機能概要		： 自己位置座標を返す                   	   		   			*/
/* 引数			： PositionData*    :car_pos        :座標格納用					*/
/* 戻り値		： int8				:0				:正常終了					*/
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成					*/
/* 作成日		： 2022/07/16		 山田　龍之介	:新規作成					*/
/* -------------------------------------------------------------------------	*/
CORDINATE CarData::getPos( void )
{
	*car_pos = position;

	return SYS_OK;
}
/* -------------------------------------------------------------------------	*/
/* 関数名		： setPos							    	    				*/
/* 機能名		： 自己位置座標(x,y)を上書き 									*/
/* 機能概要		： 自己位置座標(x,y)を上書きする                   				*/
/* 引数			： PositionData     :set_pos        :座標						*/
/* 戻り値		： int8				:0				:正常終了					*/
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成					*/
/* 作成日		： 2022/07/16		 山田　龍之介	:新規作成					*/
/* -------------------------------------------------------------------------	*/
int8 CarData::setPos( CORDINATE set_pos )
{
	//frLog &msg = frLog::GetInstance();
	position = set_pos;

	return SYS_OK;
}

/* -------------------------------------------------------------------------	*/
/* 関数名		： getAngle							    	    				*/
/* 機能名		： 自己位置角度を取得		            	    				*/
/* 機能概要		： 自己位置角度を取得する                                       */
/* 引数			： float*           :car_dir        :角度格納用					*/
/* 戻り値		： int8				:0				:正常終了					*/
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成					*/
/* 作成日		： 2022/07/16		 山田　龍之介	:新規作成					*/
/* -------------------------------------------------------------------------	*/
int8 CarData::getAngle( float* car_dir )
{
	//frLog &msg = frLog::GetInstance( );
	/* 引数チェック */
	if ( car_dir == NULL ) {
		//msg.LOG( LOG_ID_ERR, "CarPosition::getDir 引数エラー\n" );
		return SYS_PARAM;
	}

	*car_dir = angle;

	return SYS_OK;
}
/* -------------------------------------------------------------------------	*/
/* 関数名		： setAngle							    	    				*/
/* 機能名		： 自己位置角度を上書き		            	    				*/
/* 機能概要		： 自己位置角度を上書きする                                     */
/* 引数			： float            :angle          :角度						*/
/* 戻り値		： int8				:0				:正常終了					*/
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成					*/
/* 作成日		： 2022/07/16		 山田　龍之介	:新規作成					*/
/* -------------------------------------------------------------------------	*/
int8 CarData::setAngle( float angle )
{
	
	//frLog &msg = frLog::GetInstance();

	/* 引数チェック */
	/* 範囲で引数チェックが必要
		return SYS_NG;
	*/

	/*※　範囲がわからないため引数チェックができない 
	0~-179? or 0~360?　追記　山田	*/

	angle = angle;

	return SYS_OK;
}
