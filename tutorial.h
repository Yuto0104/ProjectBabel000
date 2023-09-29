//=============================================================================
//
// チュートリアルクラス(tutorial.h)
// Author : 唐�ｱ結斗
// 概要 : チュートリアルクラスの管理を行う
//
//=============================================================================
#ifndef _TUTORIAL_H_		// このマクロ定義がされてなかったら
#define _TUTORIAL_H_		// 二重インクルード防止のマクロ定義

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "scene_mode.h"

//*****************************************************************************
// 前方宣言
//*****************************************************************************
class CPlayer;
class CMesh3D;
class CScore;
class CObject2D;

//=============================================================================
// ゲームクラス
// Author : 唐�ｱ結斗
// 概要 : ゲーム生成を行うクラス
//=============================================================================
class CTutorial : public CSceneMode
{
public:
	//--------------------------------------------------------------------
	// 静的メンバ関数
	//--------------------------------------------------------------------

	//--------------------------------------------------------------------
	// コンストラクタとデストラクタ
	//--------------------------------------------------------------------
	CTutorial();
	~CTutorial() override;

	//--------------------------------------------------------------------
	// 静的メンバ変数
	//--------------------------------------------------------------------

	//--------------------------------------------------------------------
	// メンバ関数
	//--------------------------------------------------------------------
	HRESULT Init() override;												// 初期化
	void Uninit() override;													// 終了
	void Update() override;													// 更新
	void Draw() override;													// 描画

private:
	//--------------------------------------------------------------------
	// メンバ変数
	//--------------------------------------------------------------------		
};

#endif




