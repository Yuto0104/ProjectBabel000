//=============================================================================
//
// �����_���[�N���X(renderer.h)
// Author : �������l
// �T�v : �`����s���N���X
//
//=============================================================================
#ifndef _RENDERER_H_		// ���̃}�N����`������ĂȂ�������
#define _RENDERER_H_		// ��d�C���N���[�h�h�~�̃}�N����`

//*****************************************************************************
// ���C�u�����[�����N
//*****************************************************************************
#pragma comment(lib,"d3d9.lib")			// �`�揈���ɕK�v
#pragma comment(lib,"d3dx9.lib")		// [d3d9.lib]�̊g�����C�u����
#pragma comment(lib,"dxguid.lib")		// DirectX�̃R���|�l�[�g(���i)�̎g�p�ɕK�v

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "d3dx9.h"							// �`�揈���ɕK�v

//=============================================================================
// �����_���[�N���X(renderer.h)
// Author : �������l
// �T�v : �`����s���N���X
//=============================================================================
class CRenderer
{
public:
	//*****************************************************************************
	// �萔��`
	//*****************************************************************************
	static const int SCREEN_WIDTH = 1280;			// �X�N���[���̕�
	static const int SCREEN_HEIGHT = 720;			// �X�N���[���̍���

	//--------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//--------------------------------------------------------------------
	CRenderer();
	~CRenderer();

	//--------------------------------------------------------------------
	// �����o�֐�
	//--------------------------------------------------------------------
	HRESULT Init(HWND hWnd, bool bWindow);
	void Uninit();
	void Update();
	void Draw();
	void SetStencil(const int nStencilTest, D3DCMPFUNC EStencilFunc);
	void SetStencilMask(const int nStencilTest, D3DCMPFUNC EStencilFunc);
	LPDIRECT3DDEVICE9 GetDevice() { return m_pD3DDevice; }
	LPDIRECT3DTEXTURE9 GetRenderTexture() { return m_pRenderTexture; }

private:
	//--------------------------------------------------------------------
	// �����o�֐�
	//--------------------------------------------------------------------
#ifdef _DEBUG
	void DrawFPS();
#endif // _DEBUG

	//--------------------------------------------------------------------
	// �����o�ϐ�
	//--------------------------------------------------------------------
	LPDIRECT3D9						m_pD3D;						// Direct3D�I�u�W�F�N�g
	LPDIRECT3DDEVICE9				m_pD3DDevice;				// Device�I�u�W�F�N�g
	LPDIRECT3DTEXTURE9				m_pRenderTexture;			// �����_�[�e�N�X�`���p�̃|�C���^
	IDirect3DSurface9				*m_pDrowSurface;			// �`��p�T�[�t�F�C�X�̃|�C���^
	IDirect3DSurface9				*m_pZBufferSurface;			// Z�o�b�t�@�p�T�[�t�F�C�X�̃|�C���^
	IDirect3DSurface9				*m_pOrgSurface;				// ���̕`��p�T�[�t�F�C�X�̃|�C���^
	IDirect3DSurface9				*m_pOrgZBuffeSurface;		// ����Z�o�b�t�@�p�T�[�t�F�C�X�̃|�C���^

#ifdef _DEBUG
	// �t�H���g
	LPD3DXFONT	m_pFont;
#endif // _DEBUG
};

#endif
