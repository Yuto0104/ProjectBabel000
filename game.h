//=============================================================================
//
// �Q�[���N���X(game.h)
// Author : �������l
// �T�v : �Q�[���N���X�̊Ǘ����s��
//
//=============================================================================
#ifndef _GAME_H_		// ���̃}�N����`������ĂȂ�������
#define _GAME_H_		// ��d�C���N���[�h�h�~�̃}�N����`

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "scene_mode.h"

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CPlayer;
class CMesh3D;

//=============================================================================
// �Q�[���N���X
// Author : �������l
// �T�v : �Q�[���������s���N���X
//=============================================================================
class CGame : public CSceneMode
{
public:
	//--------------------------------------------------------------------
	// �ÓI�����o�֐�
	//--------------------------------------------------------------------
	static CPlayer *GetPlayer() { return m_pPlayer; }				// �v���C���[
	static void SetGame(const bool bGame) { m_bGame = bGame; }		// �Q�[���̏󋵂̐ݒ�

	//--------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//--------------------------------------------------------------------
	CGame();
	~CGame() override;

	//--------------------------------------------------------------------
	// �ÓI�����o�ϐ�
	//--------------------------------------------------------------------
	static CPlayer *m_pPlayer;						// �v���C���[�N���X
	static D3DXCOLOR fogColor;						// �t�H�O�J���[
	static float fFogStartPos;						// �t�H�O�̊J�n�_
	static float fFogEndPos;						// �t�H�O�̏I���_
	static float fFogDensity;						// �t�H�O�̖��x
	static bool m_bGame;							// �Q�[���̏�

	//--------------------------------------------------------------------
	// �����o�֐�
	//--------------------------------------------------------------------
	HRESULT Init() override;					// ������
	void Uninit() override;						// �I��
	void Update() override;						// �X�V
	void Draw() override;						// �`��
};

#endif



