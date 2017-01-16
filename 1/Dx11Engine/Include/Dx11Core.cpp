#include "Dx11Core.h"
#include "Dx11Window.h"

DX11_USING

CDx11Core* CDx11Core::m_pInst = NULL;

CDx11Core::CDx11Core()	:
	m_pWindow(NULL)
{
}

CDx11Core::~CDx11Core()
{
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
	RESOLUTION_TYPE eRT)
{
	// 윈도우 창을 생성한다.
	m_pWindow = new CDx11Window;

	if (!m_pWindow->Init(pTitle, pClass, hInst, iIconID, iSmallIconID,
		eRT, NULL))
		return false;

	return true;
}
