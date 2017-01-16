#include "Dx11Core.h"
#include "Core/Dx11Window.h"
#include "Core\Dx11Device.h"

DX11_USING

CDx11Core* CDx11Core::m_pInst = NULL;
bool CDx11Core::m_bLoop = true;

CDx11Core::CDx11Core()	:
	m_pWindow(NULL)
{
}

CDx11Core::~CDx11Core()
{
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
	// ������ â�� �����Ѵ�.
	m_pWindow = new CDx11Window;

	if (!pProc)
		pProc = CDx11Core::WndProc;

	if (!m_pWindow->Init(pTitle, pClass, hInst, iIconID, iSmallIconID,
		eRT, pProc))
		return false;

	// ����̽��� �ʱ�ȭ�Ѵ�.
	if (!DX11_GET_SINGLE(CDx11Device)->Init(eRT, true, m_pWindow->GetWindowHandle()))
		return false;

	return true;
}

int CDx11Core::Run()
{
	MSG msg;

	// �⺻ �޽��� �����Դϴ�.
	while (m_bLoop)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		else
		{
			DX11_GET_SINGLE(CDx11Device)->ClearTarget();
			DX11_GET_SINGLE(CDx11Device)->Present();
		}
	}

	return (int)msg.wParam;
}

LRESULT CDx11Core::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�.
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
