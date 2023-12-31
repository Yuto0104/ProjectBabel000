//=============================================================================
//
// 3D��`�̏Փ˔���N���X(collision_rectangle3D.cpp)
// Author : �������l
// �T�v : 3D��`�̏Փ˔��萶�����s��
//
//=============================================================================

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include <assert.h>
#include <vector>

#include "collision_rectangle3D.h"
#include "application.h"
#include "renderer.h"
#include "object.h"
#include "line.h"

//=============================================================================
// �C���X�^���X����
// Author : �������l
// �T�v : ���[�V�����L�����N�^�[3D�𐶐�����
//=============================================================================
CCollision_Rectangle3D * CCollision_Rectangle3D::Create()
{
	// �I�u�W�F�N�g�C���X�^���X
	CCollision_Rectangle3D *pCollisionRectangle3D = nullptr;

	// �������̉��
	pCollisionRectangle3D = new CCollision_Rectangle3D;

	// �������̊m�ۂ��ł��Ȃ�����
	assert(pCollisionRectangle3D != nullptr);

	// ���l�̏�����
	pCollisionRectangle3D->Init();

	// �C���X�^���X��Ԃ�
	return pCollisionRectangle3D;
}

//=============================================================================
// �R���X�g���N�^
// Author : �������l
// �T�v : �C���X�^���X�������ɍs������
//=============================================================================
CCollision_Rectangle3D::CCollision_Rectangle3D()
{
#ifdef _DEBUG
	m_pLine = nullptr;								// ���C�����
	lineCol = D3DXCOLOR(1.0f,0.0f,0.0f,1.0f);		// ���C���̐F
#endif // _DEBUG

	m_state = STATE_NONE;					// ���������ꏊ
	m_bPlusMinus = true;					// �����̔���
}

//=============================================================================
// �f�X�g���N�^
// Author : �������l
// �T�v : �C���X�^���X�I�����ɍs������
//=============================================================================
CCollision_Rectangle3D::~CCollision_Rectangle3D()
{

}

//=============================================================================
// ������
// Author : �������l
// �T�v : ���_�o�b�t�@�𐶐����A�����o�ϐ��̏����l��ݒ�
//=============================================================================
HRESULT CCollision_Rectangle3D::Init()
{
	// �����蔻��̎擾
	SetType(TYPE_RECTANGLE3D);

	// �ʒu�̎擾
	SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// �T�C�Y�̎擾
	SetSize(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// �Փ˂����I�u�W�F�N�g�̏�����
	GetCollidedObj().clear();

#ifdef _DEBUG
	// ���C�����
	m_pLine = new CLine*[12];

	for (int nCntLine = 0; nCntLine < 12; nCntLine++)
	{
		m_pLine[nCntLine] = CLine::Create();
	}
#endif // _DEBUG

	return S_OK;
}

//=============================================================================
// �I��
// Author : �������l
// �T�v : �e�N�X�`���̃|�C���^�ƒ��_�o�b�t�@�̉��
//=============================================================================
void CCollision_Rectangle3D::Uninit()
{
#ifdef _DEBUG
	if (m_pLine != nullptr)
	{
		for (int nCntLine = 0; nCntLine < 12; nCntLine++)
		{
			m_pLine[nCntLine]->Uninit();
			m_pLine[nCntLine] = nullptr;
		}

		delete[] m_pLine;
		m_pLine = nullptr;
	}
#endif // _DEBUG

	// �X�R�A�̉��
	Release();
}

//=============================================================================
// �X�V
// Author : �������l
// �T�v : �X�V���s��
//=============================================================================
void CCollision_Rectangle3D::Update()
{

}

//=============================================================================
// �`��
// Author : �������l
// �T�v : �`����s��
//=============================================================================
void CCollision_Rectangle3D::Draw()
{
#ifdef _DEBUG
	if (!GetUseFlag())
	{
		lineCol = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
	}

	// ���C���̍X�V
	SetLine();

#endif // _DEBUG
}

//=============================================================================
// �����蔻��
// Author : �������l
// �T�v : �����蔻��
//=============================================================================
bool CCollision_Rectangle3D::Collision(CObject::EObjectType objType, bool bExtrude)
{
#ifdef _DEBUG
	lineCol = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
#endif // _DEBUG

	// �Փ˂����I�u�W�F�N�g�̏�����
	std::vector<CObject*> pCollided = GetCollidedObj();
	pCollided.clear();

	// �Փ˂����I�u�W�F�N�g�̃J�E���g
	int nCntCollided = 0;

	// �擪�C���X�^���X�̎擾
	CCollision *pCollision = CCollision::GetTop();
	bool bCollision = false;

	if (pCollision != nullptr)
	{
		while (pCollision)
		{// ���݂̃I�u�W�F�N�g�̎��̃I�u�W�F�N�g��ۊ�
			CCollision *pCollisionNext = pCollision->GetNext();
			CObject::EObjectType myObjeType = pCollision->GetParent()->GetObjType();

			if ((myObjeType == objType
				|| CObject::OBJTYPE_NONE == objType)
				&& pCollision != this
				&& pCollision->GetUseFlag()
				&& !pCollision->GetDeathFlag())
			{
				switch (pCollision->GetType())
				{
				case CCollision::TYPE_RECTANGLE3D:
				case CCollision::TYPE_SPHERE:
					bCollision = ToRectangle(pCollision, bExtrude);
					break;

				default:
					assert(false);
					break;
				}
			}

			if (bCollision)
			{// ���������I�u�W�F�N�g�̐ݒ�
				pCollided.push_back(pCollision->GetParent());
				nCntCollided++;
			}

			// ���݂̃I�u�W�F�N�g�̎��̃I�u�W�F�N�g���X�V
			pCollision = pCollisionNext;
		}

		// �Փ˂����I�u�W�F�N�g�̃Z�b�g
		SetCollidedObj(pCollided);
	}

	return bCollision;
}

//=============================================================================
// ��`�Ƃ̓����蔻��
// Author : �������l
// �T�v : ��`�Ƃ̓����蔻��
//=============================================================================
bool CCollision_Rectangle3D::ToRectangle(CCollision *pTarget, bool bExtrude)
{
	// �Ԃ�l�p�̕ϐ�
	bool bColision = false;
	m_bPlusMinus = true;

	// �����̏����擾����
	D3DXVECTOR3 pos = GetParent()->GetPos() + GetPos();
	D3DXVECTOR3 posOld = GetParent()->GetPosOld() + GetPos();
	D3DXVECTOR3 size = GetSize() / 2.0f;

	// �ڕW�̏��擾
	D3DXVECTOR3 posTarget = pTarget->GetParent()->GetPos() + pTarget->GetPos();
	D3DXVECTOR3 sizeTarget = pTarget->GetSize() / 2.0f;
	m_state = STATE_NONE;

	if ((pos.z - size.z) < (posTarget.z + sizeTarget.z)
		&& (pos.z + size.z) > (posTarget.z - sizeTarget.z)
		&& (pos.x - size.x) < (posTarget.x + sizeTarget.x)
		&& (pos.x + size.x) > (posTarget.x - sizeTarget.x)
		&& (pos.y - size.y) < (posTarget.y + sizeTarget.y)
		&& (pos.y + size.y) > (posTarget.y - sizeTarget.y))
	{
		bColision = true;
	}

	if ((pos.z - size.z) < (posTarget.z + sizeTarget.z)
		&& (pos.z + size.z) > (posTarget.z - sizeTarget.z)
		&& (pos.x - size.x) < (posTarget.x + sizeTarget.x)
		&& (pos.x + size.x) > (posTarget.x - sizeTarget.x))
	{// ���f�����ɂ���(XZ��)
		if ((posOld.y + size.y) <= (posTarget.y - sizeTarget.y)
			&& (pos.y + size.y) > (posTarget.y - sizeTarget.y))
		{
			m_state = STATE_Y;

			if (bExtrude)
			{
				m_bPlusMinus = false;
				pos.y = posTarget.y - sizeTarget.y - size.y;
			}
		}
		if ((posOld.y - size.y) >= (posTarget.y + sizeTarget.y)
			&& (pos.y - size.y) < (posTarget.y + sizeTarget.y))
		{
			m_state = STATE_Y;

			if (bExtrude)
			{
				pos.y = posTarget.y + sizeTarget.y + size.y;
			}
		}
	}
	if ((pos.y - size.y) < (posTarget.y + sizeTarget.y)
		&& (pos.y + size.y) > (posTarget.y - sizeTarget.y))
	{// ���f�����ɂ���(Y��)
		if ((pos.z - size.z) < (posTarget.z + sizeTarget.z)
			&& (pos.z + size.z) > (posTarget.z - sizeTarget.z))
		{
			if ((posOld.x + size.x) <= (posTarget.x - sizeTarget.x)
				&& (pos.x + size.x) > (posTarget.x - sizeTarget.x))
			{// ���f�����ɂ���(Z��)
				m_state = STATE_Z;
				if (bExtrude)
				{
					m_bPlusMinus = false;
					pos.x = posTarget.x - sizeTarget.x - size.x;
				}
			}
			if ((posOld.x - size.x) >= (posTarget.x + sizeTarget.x)
				&& (pos.x - size.x) < (posTarget.x + sizeTarget.x))
			{// ���f�����ɂ���(Z��)
				m_state = STATE_Z;
				if (bExtrude)
				{
					pos.x = posTarget.x + sizeTarget.x + size.x;
				}
			}
		}
		if ((pos.x - size.x) < (posTarget.x + sizeTarget.x)
			&& (pos.x + size.x) > (posTarget.x - sizeTarget.x))
		{
			if ((posOld.z + size.z) <= (posTarget.z - sizeTarget.z)
				&& (pos.z + size.z) > (posTarget.z - sizeTarget.z))
			{// ���f�����ɂ���(X��)
				m_state = STATE_X;
				if (bExtrude)
				{
					m_bPlusMinus = false;
					pos.z = posTarget.z - sizeTarget.z - size.z;
				}
			}
			if ((posOld.z - size.z) >= (posTarget.z + sizeTarget.z)
				&& (pos.z - size.z) < (posTarget.z + sizeTarget.z))
			{// ���f�����ɂ���(X��)
				m_state = STATE_Z;
				if (bExtrude)
				{
					pos.z = posTarget.z + sizeTarget.z + size.z;
				}
			}
		}
	}

	if (bColision)
	{// �ʒu�̐ݒ�
		CObject *pParent = GetParent();
		pParent->SetPos(pos - GetPos());
#ifdef _DEBUG
		lineCol = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
#endif // DEBUG
	}
	
	return bColision;
}

#ifdef _DEBUG
//=============================================================================
// ���C���̐ݒu
// Author : �������l
// �T�v : ���C������`��ɐݒu
//=============================================================================
void CCollision_Rectangle3D::SetLine()
{
	// �ϐ��錾
	CObject *pObject = GetParent();
	D3DXVECTOR3 pos = pObject->GetPos() + GetPos();
	const D3DXVECTOR3 rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	const D3DXVECTOR3 size = GetSize() / 2.0f;
	const D3DXCOLOR col = lineCol;

	// ���C���̐ݒ�
	m_pLine[0]->SetLine(pos, rot, D3DXVECTOR3(-size.x, -size.y, size.z), D3DXVECTOR3(size.x, -size.y, size.z), col);
	m_pLine[1]->SetLine(pos, rot, D3DXVECTOR3(-size.x, -size.y, -size.z), D3DXVECTOR3(-size.x, -size.y, size.z), col);
	m_pLine[2]->SetLine(pos, rot, D3DXVECTOR3(-size.x, -size.y, -size.z), D3DXVECTOR3(size.x, -size.y, -size.z), col);
	m_pLine[3]->SetLine(pos, rot, D3DXVECTOR3(size.x, -size.y, -size.z), D3DXVECTOR3(size.x, -size.y, size.z), col);
	m_pLine[4]->SetLine(pos, rot, D3DXVECTOR3(-size.x, size.y, size.z), D3DXVECTOR3(size.x, size.y, size.z), col);
	m_pLine[5]->SetLine(pos, rot, D3DXVECTOR3(-size.x, size.y, -size.z), D3DXVECTOR3(-size.x, size.y, size.z), col);
	m_pLine[6]->SetLine(pos, rot, D3DXVECTOR3(-size.x, size.y, -size.z), D3DXVECTOR3(size.x, size.y, -size.z), col);
	m_pLine[7]->SetLine(pos, rot, D3DXVECTOR3(size.x, size.y, -size.z), D3DXVECTOR3(size.x, size.y, size.z), col);
	m_pLine[8]->SetLine(pos, rot, D3DXVECTOR3(-size.x, -size.y, size.z), D3DXVECTOR3(-size.x, size.y, size.z), col);
	m_pLine[9]->SetLine(pos, rot, D3DXVECTOR3(-size.x, -size.y, -size.z), D3DXVECTOR3(-size.x, size.y, -size.z), col);
	m_pLine[10]->SetLine(pos, rot, D3DXVECTOR3(size.x, -size.y, -size.z), D3DXVECTOR3(size.x, size.y, -size.z), col);
	m_pLine[11]->SetLine(pos, rot, D3DXVECTOR3(size.x, -size.y, size.z), D3DXVECTOR3(size.x, size.y, size.z), col);
}
#endif // DEBUG

