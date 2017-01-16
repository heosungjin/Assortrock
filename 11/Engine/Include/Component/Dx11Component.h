#pragma once
#include "../Dx11Object.h"

DX11_BEGIN

class DX11_DLL CDx11Component :
	public CDx11Object
{
protected:
	CDx11Component();
	virtual ~CDx11Component() = 0;

protected:
	class CDx11Scene*		m_pScene;
	class CDx11Layer*		m_pLayer;
	class CDx11GameObject*	m_pGameObject;
	COMPONENT_TYPE			m_eComType;

public:
	void SetScene(CDx11Scene* pScene);
	void SetLayer(CDx11Layer* pLayer);
	void SetGameObject(CDx11GameObject* pGameObject);

public:
	CDx11GameObject* GetGameObject();
	COMPONENT_TYPE GetComponentType();

public:
	virtual bool Init();
	virtual int Update(float fTime);
	virtual int LateUpdate(float fTime);
	virtual void Render(float fTime);
};

DX11_END
