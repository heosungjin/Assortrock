#pragma once
#include "../Dx11Object.h"

DX11_BEGIN

class DX11_DLL CDx11Scene :
	public CDx11Object
{
private:
	friend class CDx11SceneManager;

private:
	CDx11Scene();
	~CDx11Scene();

private:
	vector<class CDx11Layer*>	m_vecLayer;

public:
	bool Init();
	void Input(float fTime);
	int Update(float fTime);
	int LateUpdate(float fTime);
	void Collision(float fTime);
	void Render(float fTime);

public:
	class CDx11Layer* CreateLayer(const string& strTag = "Layer");
	class CDx11Layer* FindLayer(const string& strTag);
};

DX11_END
