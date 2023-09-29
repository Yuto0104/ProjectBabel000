//=============================================================================
//
// テクスチャアニメーション処理(tex_anim.h)
// Author : 唐�ｱ結斗
// 概要 : テクスチャーアニメーションを計算する
//
//=============================================================================

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "tex_anim.h"

//=============================================================================
// コンストラクタ
// Author : 唐�ｱ結斗
// 概要 : インスタンス生成時に行う処理
//=============================================================================
CTexAnim::CTexAnim()
{
	m_patternAnim.x = 0;							// アニメーションのパターン(X座標)
	m_patternAnim.y = 0;							// アニメーションのパターン(Y座標)
	m_numAnim.x = 0;								// アニメーションのパターンNo.(X座標)
	m_numAnim.y = 0;								// アニメーションのパターンNo.(y座標)
	m_addTex = D3DXVECTOR2(0.0f, 0.0f);				// テクスチャ座標の増加量
	m_nMaxCntAnim = 0;								// アニメーションの切り替え
	m_nCntAnim = 0;									// アニメーションカウント
	m_bLoop = false;								// ループの使用状況
}

//=============================================================================
// デストラクタ
// Author : 唐�ｱ結斗
// 概要 : インスタンス終了時に行う処理
//=============================================================================
CTexAnim::~CTexAnim()
{

}

//=============================================================================
// アニメーション構造体の設定
// Author : 唐�ｱ結斗
// 概要 : アニメーション構造体の設定を行い数値を返す
//=============================================================================
void CTexAnim::SetAnim(int nPatternAnimX, int nPatternAnimY, int nLife, bool bLoop)
{
	// アニメーションのパターン
	m_patternAnim.x = nPatternAnimX;
	m_patternAnim.y = nPatternAnimY;

	// アニメーションのパターンNo.
	m_numAnim.x = 0;	// アニメーションのパターンNo.(X座標)
	m_numAnim.y = 0;	// アニメーションのパターンNo.(y座標)

	// ループを使用するか
	m_bLoop = bLoop;

	if (!m_bLoop)
	{// ループを使用しない
		// アニメーションパターンのコピー
		TEX_PATTERN patternAnimCopy = m_patternAnim;

		if (patternAnimCopy.x <= 1)
		{// 1.0f以下なら0.0ｆを代入
			patternAnimCopy.x = 0;
		}
		if (patternAnimCopy.y <= 1)
		{// 1.0f以下なら0.0ｆを代入
			patternAnimCopy.y = 0;
		}

		// アニメーションの切り替え
		m_nMaxCntAnim = nLife / (int)(patternAnimCopy.x + patternAnimCopy.y);
	}
	else
	{// アニメーションの切り替え
		m_nMaxCntAnim = nLife;
	}

	// アニメーションカウント
	m_nCntAnim = 0;

	// テクスチャ座標の増加量の算出
	m_addTex = D3DXVECTOR2(1.0f / m_patternAnim.x, 1.0f / m_patternAnim.y);
}

//=============================================================================
// アニメーションの再生
// Author : 唐�ｱ結斗
// 概要 : アニメーションの再生を行う
//=============================================================================
void CTexAnim::PlayAnim()
{
	// アニメーションカウントのインクリメント
	m_nCntAnim++;

	if (m_nCntAnim % m_nMaxCntAnim == 0)
	{// カウントが特異点に達した場合
	 // パターンカウントの更新(X軸)
		m_numAnim.x += 1;

		if (m_numAnim.x >= m_patternAnim.x)
		{// カウントがX軸のパターン数を上回った
			m_numAnim.x = 0;

			// パターンカウントの更新(Y軸)
			m_numAnim.y += 1;

			if (m_numAnim.y >= m_patternAnim.y)
			{// カウントがY軸のパターン数を上回った
				m_numAnim.y = 0;
			}
		}
	}
}
