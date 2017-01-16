#include "Dx11Core.h"
#include "Core/Dx11Window.h"
#include "Core\Dx11Device.h"
#include "Resources\Dx11ResourcesManager.h"
#include "Rendering\Dx11ShaderManager.h"

DX11_USING

CDx11Core* CDx11Core::m_pInst = NULL;
bool CDx11Core::m_bLoop = true;

CDx11Core::CDx11Core()	:
	m_pWindow(NULL)
{
}

CDx11Core::~CDx11Core()
{
	DX11_DESTROY_SINGLE(CDx11ResourcesManager);
	DX11_DESTROY_SINGLE(CDx11ShaderManager);
	DX11_DESTROY_SINGLE(CDx11Device);
	SAFE_RELEASE(m_pWindow);
}

CDx11Core * CDx11Core::GetInst()
{
	if (!m_pInst)
		m_pInst = new CDx11Core;

	return m_pInst;
}

void CDx11Core::DestroyInst()
{
	SAFE_DELETE(m_pInst);
}

bool CDx11Core::Init(TCHAR * pTitle, TCHAR * pClass,
	HINSTANCE hInst, int iIconID, int iSmallIconID, 
	RESOLUTION_TYPE eRT, WNDPROC pProc)
{
	// 윈도우 창을 생성한다.
	m_pWindow = new CDx11Window;

	if (!pProc)
		pProc = CDx11Core::WndProc;

	if (!m_pWindow->Init(pTitle, pClass, hInst, iIconID, iSmallIconID,
		eRT, pProc))
		return false;

	// 디바이스를 초기화한다.
	if (!DX11_GET_SINGLE(CDx11Device)->Init(eRT, true, m_pWindow->GetWindowHandle()))
		return false;

	// 리소스 관리자를 초기화한다.
	if (!DX11_GET_SINGLE(CDx11ResourcesManager)->Init())
		return false;

	// Shader 관리자를 초기화한다.
	if (!DX11_GET_SINGLE(CDx11ShaderManager)->Init())
		return false;

	return true;
}

int CDx11Core::Run()
{
	MSG msg;

	// 메시지 루프입니다.
	while (m_bLoop)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		else
		{
			Logic();
		}
	}

	return (int)msg.wParam;
}

void CDx11Core::Logic()
{
	Input(0.f);
	Update(0.f);
	LateUpdate(0.f);
	Collision(0.f);
	Render(0.f);
}

void CDx11Core::Input(float fTime)
{
}

int CDx11Core::Update(float fTime)
{
	return 0;
}

int CDx11Core::LateUpdate(float fTime)
{
	return 0;
}

void CDx11Core::Collision(float fTime)
{
}

void CDx11Core::Render(float fTime)
{
	DX11_GET_SINGLE(CDx11Device)->ClearTarget();

	DX11_GET_SINGLE(CDx11Device)->Present();
}

LRESULT CDx11Core::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다.
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		m_bLoop = false;
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
