//=============================================================================
//
// チュートリアルクラス(tutorial.cpp)
// Author : 唐﨑結斗
// 概要 : チュートリアルクラスの管理を行う
//
//=============================================================================

//*****************************************************************************
// インクルード
//*****************************************************************************
#include <assert.h>

#include "tutorial.h"
#include "calculation.h"
#include "keyboard.h"
#include "mouse.h"
#include "application.h"
#include "camera.h"
#include "renderer.h"
#include "object.h"
#include "object3D.h"
#include "player.h"
#include "motion_model3D.h"
#include "model3D.h"
#include "mesh.h"
#include "sphere.h"
#include "bg.h"
#include "model_obj.h"
#include "debug_proc.h"
#include "sound.h"
#include "object2D.h"

//*****************************************************************************
// 静的メンバ変数宣言
//*****************************************************************************

//=============================================================================
// コンストラクタ
// Author : 唐﨑結斗
// 概要 : インスタンス生成時に行う処理
//=============================================================================
CTutorial::CTutorial()
{

}

//=============================================================================
// デストラクタ
// Author : 唐﨑結斗
// 概要 : インスタンス終了時に行う処理
//=============================================================================
CTutorial::~CTutorial()
{

}

//=============================================================================
// 初期化
// Author : 唐﨑結斗
// 概要 : 頂点バッファを生成し、メンバ変数の初期値を設定
//=============================================================================
HRESULT CTutorial::Init()
{// マウスの取得
	CMouse *pMouse = CApplication::GetMouse();

	// サウンド情報の取得
	CSound *pSound = CApplication::GetSound();
	pSound->PlaySound(CSound::SOUND_LABEL_BGM003);

	// 重力の値を設定
	CCalculation::SetGravity(0.2f);

	// カメラの追従設定(目標 : プレイヤー)
	CCamera *pCamera = CApplication::GetCamera();
	pCamera->SetPosVOffset(D3DXVECTOR3(0.0f, 50.0f, -200.0f));
	pCamera->SetPosROffset(D3DXVECTOR3(0.0f, 0.0f, 100.0f));
	pCamera->SetRot(D3DXVECTOR3(0.0f, D3DX_PI, 0.0f));
	pCamera->SetUseRoll(true, true);

	// マウスカーソルを消す
	pMouse->SetShowCursor(false);

	//// デバイスの取得
	//LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//// フォグの数値設定
	//fogColor = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);		// フォグカラー
	//fFogStartPos = 1.0f;								// フォグの開始点
	//fFogEndPos = 100000.0f;								// フォグの終了点
	//fFogDensity = 0.00001f;								// フォグの密度

	//// フォグの有効設定
	//pDevice->SetRenderState(D3DRS_FOGENABLE, TRUE);

	//// フォグカラーの設定
	//pDevice->SetRenderState(D3DRS_FOGCOLOR, fogColor);

	//// フォグの範囲設定
	//pDevice->SetRenderState(D3DRS_FOGTABLEMODE, D3DFOG_LINEAR);
	//pDevice->SetRenderState(D3DRS_FOGSTART, *(DWORD*)(&fFogStartPos));
	//pDevice->SetRenderState(D3DRS_FOGEND, *(DWORD*)(&fFogEndPos));

	//// フォグの密度の設定
	//pDevice->SetRenderState(D3DRS_FOGDENSITY, *(DWORD*)(&fFogDensity));

	return S_OK;
}

//=============================================================================
// 終了
// Author : 唐﨑結斗
// 概要 : テクスチャのポインタと頂点バッファの解放
//=============================================================================
void CTutorial::Uninit()
{// マウスの取得
	CMouse *pMouse = CApplication::GetMouse();

	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	// サウンド情報の取得
	CSound *pSound = CApplication::GetSound();

	// サウンド終了
	pSound->StopSound();

	// フォグの有効設定
	pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);

	// マウスカーソルを出す
	pMouse->SetShowCursor(true);

	// カメラの追従設定
	CCamera *pCamera = CApplication::GetCamera();
	pCamera->SetFollowTarget(false);
	pCamera->SetTargetPosR(false);

	// カメラの追従設定
	pCamera = CApplication::GetMapCamera();
	pCamera->SetFollowTarget(false);
	pCamera->SetTargetPosR(false);

	// スコアの解放
	Release();
}

//=============================================================================
// 更新
// Author : 唐﨑結斗
// 概要 : 更新を行う
//=============================================================================
void CTutorial::Update()
{
	// カメラの追従設定
	CCamera *pCamera = nullptr;

	// キーボードの取得
	CKeyboard *pKeyboard = CApplication::GetKeyboard();

#ifdef _DEBUG

	// カメラの追従設定
	pCamera = CApplication::GetCamera();

	if (pKeyboard->GetTrigger(DIK_F10))
	{
		pCamera->Shake(60, 50.0f);
	}

	if (pKeyboard->GetPress(DIK_LSHIFT))
	{
		pCamera->Zoom();
	}

#endif // _DEBUG

	if (pKeyboard->GetTrigger(DIK_F3))
	{
		CApplication::SetNextMode(CApplication::MODE_TITLE);
	}
}

//=============================================================================
// 描画
// Author : 唐﨑結斗
// 概要 : 描画を行う
//=============================================================================
void CTutorial::Draw()
{

}
