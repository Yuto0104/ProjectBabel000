//=============================================================================
//
// �`���[�g���A���N���X(tutorial.cpp)
// Author : �������l
// �T�v : �`���[�g���A���N���X�̊Ǘ����s��
//
//=============================================================================

//*****************************************************************************
// �C���N���[�h
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
// �ÓI�����o�ϐ��錾
//*****************************************************************************

//=============================================================================
// �R���X�g���N�^
// Author : �������l
// �T�v : �C���X�^���X�������ɍs������
//=============================================================================
CTutorial::CTutorial()
{

}

//=============================================================================
// �f�X�g���N�^
// Author : �������l
// �T�v : �C���X�^���X�I�����ɍs������
//=============================================================================
CTutorial::~CTutorial()
{

}

//=============================================================================
// ������
// Author : �������l
// �T�v : ���_�o�b�t�@�𐶐����A�����o�ϐ��̏����l��ݒ�
//=============================================================================
HRESULT CTutorial::Init()
{// �}�E�X�̎擾
	CMouse *pMouse = CApplication::GetMouse();

	// �T�E���h���̎擾
	CSound *pSound = CApplication::GetSound();
	pSound->PlaySound(CSound::SOUND_LABEL_BGM003);

	// �d�͂̒l��ݒ�
	CCalculation::SetGravity(0.2f);

	// �J�����̒Ǐ]�ݒ�(�ڕW : �v���C���[)
	CCamera *pCamera = CApplication::GetCamera();
	pCamera->SetPosVOffset(D3DXVECTOR3(0.0f, 50.0f, -200.0f));
	pCamera->SetPosROffset(D3DXVECTOR3(0.0f, 0.0f, 100.0f));
	pCamera->SetRot(D3DXVECTOR3(0.0f, D3DX_PI, 0.0f));
	pCamera->SetUseRoll(true, true);

	// �}�E�X�J�[�\��������
	pMouse->SetShowCursor(false);

	//// �f�o�C�X�̎擾
	//LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//// �t�H�O�̐��l�ݒ�
	//fogColor = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);		// �t�H�O�J���[
	//fFogStartPos = 1.0f;								// �t�H�O�̊J�n�_
	//fFogEndPos = 100000.0f;								// �t�H�O�̏I���_
	//fFogDensity = 0.00001f;								// �t�H�O�̖��x

	//// �t�H�O�̗L���ݒ�
	//pDevice->SetRenderState(D3DRS_FOGENABLE, TRUE);

	//// �t�H�O�J���[�̐ݒ�
	//pDevice->SetRenderState(D3DRS_FOGCOLOR, fogColor);

	//// �t�H�O�͈̔͐ݒ�
	//pDevice->SetRenderState(D3DRS_FOGTABLEMODE, D3DFOG_LINEAR);
	//pDevice->SetRenderState(D3DRS_FOGSTART, *(DWORD*)(&fFogStartPos));
	//pDevice->SetRenderState(D3DRS_FOGEND, *(DWORD*)(&fFogEndPos));

	//// �t�H�O�̖��x�̐ݒ�
	//pDevice->SetRenderState(D3DRS_FOGDENSITY, *(DWORD*)(&fFogDensity));

	return S_OK;
}

//=============================================================================
// �I��
// Author : �������l
// �T�v : �e�N�X�`���̃|�C���^�ƒ��_�o�b�t�@�̉��
//=============================================================================
void CTutorial::Uninit()
{// �}�E�X�̎擾
	CMouse *pMouse = CApplication::GetMouse();

	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	// �T�E���h���̎擾
	CSound *pSound = CApplication::GetSound();

	// �T�E���h�I��
	pSound->StopSound();

	// �t�H�O�̗L���ݒ�
	pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);

	// �}�E�X�J�[�\�����o��
	pMouse->SetShowCursor(true);

	// �J�����̒Ǐ]�ݒ�
	CCamera *pCamera = CApplication::GetCamera();
	pCamera->SetFollowTarget(false);
	pCamera->SetTargetPosR(false);

	// �J�����̒Ǐ]�ݒ�
	pCamera = CApplication::GetMapCamera();
	pCamera->SetFollowTarget(false);
	pCamera->SetTargetPosR(false);

	// �X�R�A�̉��
	Release();
}

//=============================================================================
// �X�V
// Author : �������l
// �T�v : �X�V���s��
//=============================================================================
void CTutorial::Update()
{
	// �J�����̒Ǐ]�ݒ�
	CCamera *pCamera = nullptr;

	// �L�[�{�[�h�̎擾
	CKeyboard *pKeyboard = CApplication::GetKeyboard();

#ifdef _DEBUG

	// �J�����̒Ǐ]�ݒ�
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
// �`��
// Author : �������l
// �T�v : �`����s��
//=============================================================================
void CTutorial::Draw()
{

}
