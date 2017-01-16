#pragma once
#include "../Dx11Object.h"

DX11_BEGIN

class DX11_DLL  CDx11Layer:
	public CDx11Object
{
private:
	friend class CDx11Scene;

private:
	CDx11Layer();
	~CDx11Layer();

public:
	bool Init();
	void Input(float fTime);
	int Update(float fTime);
	int LateUpdate(float fTime);
	void Collision(float fTime);
	void Render(float fTime);
};

DX11_END
