#pragma once

#include "Component/Dx11Script.h"

DX11_USING

class CMainScene	:
	public CDx11Script
{
public:
	CMainScene();
	~CMainScene();

public:
	virtual bool Init();
	virtual int Update(float fTime);
	virtual int LateUpdate(float fTime);
	virtual void Render(float fTime);
};

