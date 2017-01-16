#pragma once
#include "Dx11Component.h"

DX11_BEGIN

class DX11_DLL CDx11Renderer :
	public CDx11Component
{
private:
	friend class CDx11GameObject;

private:
	CDx11Renderer();
	~CDx11Renderer();

private:
	class CDx11Mesh*	m_pMesh;
	class CDx11Shader*	m_pShader;

public:
	virtual bool Init();
	virtual int Update(float fTime);
	virtual int LateUpdate(float fTime);
	virtual void Render(float fTime);

public:
	void SetMesh(const string& strKey);
	void SetShader(const string& strKey);
};

DX11_END