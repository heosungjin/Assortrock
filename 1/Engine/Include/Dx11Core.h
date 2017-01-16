#pragma once
#include "Dx11Object.h"

DX11_BEGIN

class DX11_DLL CDx11Core :
	public CDx11Object
{
private:
	CDx11Core();
	~CDx11Core();

private:	
	static CDx11Core*	m_pInst;

public:
	static CDx11Core* GetInst();
	static void DestroyInst();

private:
	// CDx11Window��� Ŭ������ �����ϱ� �����͸� �����صֶ�.
	class CDx11Window*	m_pWindow;

public:
	bool Init(TCHAR* pTitle, TCHAR* pClass, HINSTANCE hInst,
		int iIconID, int iSmallIconID, RESOLUTION_TYPE eRT);
};

DX11_END