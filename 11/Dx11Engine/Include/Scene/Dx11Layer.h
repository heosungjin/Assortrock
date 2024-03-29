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

private:
	list<class CDx11GameObject*>	m_ObjList;
	class CDx11Scene*				m_pScene;

public:
	void SetScene(CDx11Scene* pScene);
	void AddObject(CDx11GameObject* pObj);

public:
	bool Init();
	void Input(float fTime);
	int Update(float fTime);
	int LateUpdate(float fTime);
	void Collision(float fTime);
	void Render(float fTime);
};

DX11_END
