//=============================================================================
//
// プレイヤークラス(player.cpp)
// Author : 唐�ｱ結斗
// 概要 : プレイヤー生成を行う
//
//=============================================================================

//*****************************************************************************
// インクルード
//*****************************************************************************
#include <assert.h>

#include "player.h"
#include "game.h"
#include "mesh.h"
#include "motion.h"
#include "renderer.h"
#include "application.h"
#include "camera.h"
#include "keyboard.h"
#include "mouse.h"
#include "calculation.h"
#include "move.h"
#include "collision_rectangle3D.h"
#include "debug_proc.h"
#include "parts.h"
#include "sound.h"
#include "scene_mode.h"

//--------------------------------------------------------------------
// 静的メンバ変数の定義
//--------------------------------------------------------------------
const float CPlayer::fSPEED = 1.0f;

//=============================================================================
// インスタンス生成
// Author : 唐�ｱ結斗
// 概要 : モーションキャラクター3Dを生成する
//=============================================================================
CPlayer * CPlayer::Create()
{
	// オブジェクトインスタンス
	CPlayer *pPlayer = nullptr;

	// メモリの解放
	pPlayer = new CPlayer;

	// メモリの確保ができなかった
	assert(pPlayer != nullptr);

	// 数値の初期化
	pPlayer->Init();

	// インスタンスを返す
	return pPlayer;
}

//=============================================================================
// コンストラクタ
// Author : 唐�ｱ結斗
// 概要 : インスタンス生成時に行う処理
//=============================================================================
CPlayer::CPlayer() : m_pMove(nullptr),
m_pCollision(nullptr),
m_EAction(NEUTRAL_ACTION),
m_rotDest(D3DXVECTOR3(0.0f,0.0f,0.0f)),
m_fSpeed(0.0f),
m_fGravity(0.0f),
m_nNumMotion(0)
{

}

//=============================================================================
// デストラクタ
// Author : 唐�ｱ結斗
// 概要 : インスタンス終了時に行う処理
//=============================================================================
CPlayer::~CPlayer()
{

}

//=============================================================================
// 初期化
// Author : 唐�ｱ結斗
// 概要 : 頂点バッファを生成し、メンバ変数の初期値を設定
//=============================================================================
HRESULT CPlayer::Init()
{
	// 初期化
	CMotionModel3D::Init();

	// オブジェクトタイプの設定
	SetObjType(OBJETYPE_PLAYER);

	// 移動クラスのメモリ確保
	m_pMove = new CMove;
	assert(m_pMove != nullptr);
	m_pMove->SetMoving(fSPEED, 1000.0f, 0.5f, 0.1f);

	// 3D矩形の当たり判定の設定
	m_pCollision = CCollision_Rectangle3D::Create();
	m_pCollision->SetParent(this);
	m_pCollision->SetPos(D3DXVECTOR3(0.0f, 25.0f, 0.0f));
	m_pCollision->SetSize(D3DXVECTOR3(30.0f, 50.0f, 20.0f));

	return E_NOTIMPL;
}

//=============================================================================
// 終了
// Author : 唐�ｱ結斗
// 概要 : テクスチャのポインタと頂点バッファの解放
//=============================================================================
void CPlayer::Uninit()
{
	// カメラの追従設定(目標 : プレイヤー)
	CCamera *pCamera = CApplication::GetCamera();
	pCamera->SetFollowTarget(false);
	pCamera->SetTargetPosR(false);

	if (m_pMove != nullptr)
	{// メモリの解放
		delete m_pMove;
		m_pMove = nullptr;
	}

	if (m_pCollision != nullptr)
	{// 終了処理
		m_pCollision->Uninit();
		m_pCollision = nullptr;
	}

	// 終了
	CMotionModel3D::Uninit();

	// ゲーム終了
	CGame::SetGame(false);
}

//=============================================================================
// 更新
// Author : 唐�ｱ結斗
// 概要 : 2D更新を行う
//=============================================================================
void CPlayer::Update()
{
	// モーション情報の取得
	CMotion *pMotion = CMotionModel3D::GetMotion();

	// 位置の取得
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 rot = GetRot();

	// 過去位置の更新
	SetPosOld(pos);

	// 重力の設定
	m_fGravity -= CCalculation::Gravity();

	// 移動
	pos.y += m_fGravity;
	pos += Move();

	// 位置の設定
	SetPos(pos);

	// 回転
	Rotate();

	if (pMotion != nullptr
		&& !pMotion->GetMotion())
	{// ニュートラルモーションの設定
		m_EAction = NEUTRAL_ACTION;
		pMotion->SetNumMotion(m_EAction);
	}

	// 更新
	CMotionModel3D::Update();

	// 位置の設定
	SetPos(pos);

	// メッシュの当たり判定
	CMesh3D::CollisonMesh(this);

	m_pCollision->Collision(CObject::OBJTYPE_3DMODEL, true);

	// 位置の取得
	pos = GetPos();

	SetPos(pos);
	
	// 位置の取得
	pos = GetPos();
	
	// デバック表示
	CDebugProc::Print("プレイヤーの位置 | X : %.3f | Y : %.3f | Z : %.3f |\n", pos.x, pos.y, pos.z);
}

//=============================================================================
// 描画
// Author : 唐�ｱ結斗
// 概要 : 2D描画を行う
//=============================================================================
void CPlayer::Draw()
{
	// 描画
	CMotionModel3D::Draw();
}

//=============================================================================
// 移動
// Author : 唐�ｱ結斗
// 概要 : キー入力で方向を決めて、移動ベクトルを算出する
//=============================================================================
D3DXVECTOR3 CPlayer::Move()
{
	// 変数宣言
	D3DXVECTOR3 move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// キーボードの取得
	CKeyboard *pKeyboard = CApplication::GetKeyboard();

	// モーション情報の取得
	CMotion *pMotion = CMotionModel3D::GetMotion();

	if ((pKeyboard->GetPress(DIK_W)
		|| pKeyboard->GetPress(DIK_A)
		|| pKeyboard->GetPress(DIK_D)
		|| pKeyboard->GetPress(DIK_S)))
	{// 移動キーが押された
		if (pKeyboard->GetPress(DIK_W))
		{// [W]キーが押された時
			if (pKeyboard->GetPress(DIK_A))
			{// [A]キーが押された時
			 // 移動方向の更新
				m_rotDest.y = D3DX_PI * -0.25f;
			}
			else if (pKeyboard->GetPress(DIK_D))
			{// [D]キーが押された時
			 // 移動方向の更新
				m_rotDest.y = D3DX_PI * 0.25f;
			}
			else
			{// 移動方向の更新
				m_rotDest.y = D3DX_PI * 0.0f;
			}
		}
		else if (pKeyboard->GetPress(DIK_S))
		{// [S]キーが押された時
			if (pKeyboard->GetPress(DIK_A))
			{// [A]キーが押された時
			 // 移動方向の更新
				m_rotDest.y = D3DX_PI * -0.75f;
			}
			else if (pKeyboard->GetPress(DIK_D))
			{// [D]キーが押された時
			 // 移動方向の更新
				m_rotDest.y = D3DX_PI * 0.75f;
			}
			else
			{// 移動方向の更新q
				m_rotDest.y = D3DX_PI;
			}
		}
		else if (pKeyboard->GetPress(DIK_A))
		{// [A]キーが押された時
		 // 移動方向の更新
			m_rotDest.y = D3DX_PI * -0.5f;
		}
		else if (pKeyboard->GetPress(DIK_D))
		{// [D]キーが押された時
		 // 移動方向の更新
			m_rotDest.y = D3DX_PI * 0.5f;
		}

		// カメラ情報の取得
		CCamera *pCamera = CApplication::GetCamera();

		// 移動方向の算出
		m_rotDest.y += pCamera->GetRot().y;

		// 移動方向の正規化
		m_rotDest.y = CCalculation::RotNormalization(m_rotDest.y);

		// 移動量の計算
		move = D3DXVECTOR3(sinf(m_rotDest.y), 0.0f, cosf(m_rotDest.y));

		// 角度の正規化
		m_rotDest.y -= D3DX_PI;

		// 移動方向の正規化
		m_rotDest.y = CCalculation::RotNormalization(m_rotDest.y);

		if (m_EAction == NEUTRAL_ACTION)
		{// 移動
			m_EAction = MOVE_ACTION;
		
			if (pMotion != nullptr)
			{
				pMotion->SetNumMotion(m_EAction);
			}
		}
	}

	// 移動情報の計算
 	m_pMove->Moving(move);

	// 移動情報の取得
	D3DXVECTOR3 moveing = m_pMove->GetMove();

	if (sqrtf((moveing.x * moveing.x) + (moveing.z * moveing.z)) <= 0.0f
		&& pMotion != nullptr
		&& m_EAction == MOVE_ACTION)
	{
		m_EAction = NEUTRAL_ACTION;
		pMotion->SetNumMotion(m_EAction);
	}

	// デバック表示
	CDebugProc::Print("移動ベクトル : %.3f\n", m_pMove->GetMoveLength());

	// 向きの取得
	D3DXVECTOR3 rot = GetRot();

	// 目的の向きの補正
	if (m_rotDest.y - rot.y >= D3DX_PI)
	{// 移動方向の正規化
		m_rotDest.y -= D3DX_PI * 2;
	}
	else if (m_rotDest.y - rot.y <= -D3DX_PI)
	{// 移動方向の正規化
		m_rotDest.y += D3DX_PI * 2;
	}

	return moveing;
}

//=============================================================================
// 回転
// Author : 唐�ｱ結斗
// 概要 : 目的の向きまで回転する
//=============================================================================
void CPlayer::Rotate()
{
	// 向きの取得
	D3DXVECTOR3 rot = GetRot();
	float fFriction = 0.5f;

	// 向きの更新
	rot.y += (m_rotDest.y - rot.y) * fFriction;

	// 向きの正規化
	rot.y = CCalculation::RotNormalization(rot.y);

	// 向きの設定
	SetRot(rot);
}


