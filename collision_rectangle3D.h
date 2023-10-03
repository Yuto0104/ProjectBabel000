//=============================================================================
//
// 3D��`�̏Փ˔���N���X(collision_rectangle3D.h)
// Author : �������l
// �T�v : 3D��`�̏Փ˔��萶�����s��
//
//=============================================================================
#ifndef _COLLISION_RECTANGLE3D_H_		// ���̃}�N����`������ĂȂ�������
#define _COLLISION_RECTANGLE3D_H_		// ��d�C���N���[�h�h�~�̃}�N����`

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "collision.h"

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CLine;

//=============================================================================
// �Փ˔���N���X
// Author : �������l
// �T�v : �Փ˔���N���X�������s��
//=============================================================================
class CCollision_Rectangle3D : public CCollision
{
public:
	//--------------------------------------------------------------------
	// ���������ꏊ�̗񋓌^
	//--------------------------------------------------------------------
	enum EState
	{
		STATE_NONE = 0,		// ����
		STATE_X,			// X
		STATE_Y,			// Y
		STATE_Z,			// Z
	};

	//--------------------------------------------------------------------
	// �ÓI�����o�֐�
	//--------------------------------------------------------------------
	static CCollision_Rectangle3D *Create();			// �C���X�^���X�̐���

	//--------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//--------------------------------------------------------------------
	explicit CCollision_Rectangle3D();
	virtual ~CCollision_Rectangle3D();

	//--------------------------------------------------------------------
	// �������z�֐�
	//--------------------------------------------------------------------
	HRESULT Init() override;													// ������
	void Uninit() override;														// �I��
	void Update() override;														// �X�V
	void Draw() override;														// �`��
	bool Collision(CObject::EObjectType objType, bool bExtrude) override;		// �����蔻��	
	bool ToRectangle(CCollision *pTarget, bool bExtrude);						// ��`�Ƃ̓����蔻��
	EState GetState() { return m_state; }										// ���������ꏊ�̎擾
	bool GetPlusMinus() { return m_bPlusMinus; }								// ��������̎擾

#ifdef _DEBUG
	void SetLine();					// ���C���̐ݒ�
#endif // _DEBUG

private:
	//--------------------------------------------------------------------
	// �����o�ϐ�
	//--------------------------------------------------------------------
#ifdef _DEBUG
	CLine **m_pLine;		// ���C�����
	D3DXCOLOR lineCol;		// ���C���̐F
#endif // _DEBUG
	EState m_state;			// ���������ꏊ
	bool m_bPlusMinus;		// �����̔���
};

#endif


