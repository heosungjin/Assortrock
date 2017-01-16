#pragma once
#include "../Dx11Object.h"

DX11_BEGIN

class DX11_DLL CDx11GameObject :
	public CDx11Object
{
private:
	CDx11GameObject();
	~CDx11GameObject();

private:
	class CDx11Scene*	m_pScene;
	class CDx11Layer*	m_pLayer;

public:
	void SetScene(CDx11Scene* pScene);
	void SetLayer(CDx11Layer* pLayer);

private:
	list<class CDx11Component*>		m_ComponentList;
	class CDx11Transform*					m_pTransform;
	list<class CDx11Component*>		m_FindList;

public:
	class CDx11Transform* GetTransform();

public:
	bool Init();
	int Update(float fTime);
	int LateUpdate(float fTime);
	void Render(float fTime);

public:
	CDx11Component* FindComponentFromTag(const string& strTag);
	CDx11Component* FindComponentFromTypeName(const string& strTypeName);
	list<CDx11Component*>* FindComponentsFromTag(const string& strTag);
	list<CDx11Component*>* FindComponentsFromTypeName(const string& strTypeName);

public:
	void AddComponent(CDx11Component* pComponent);
	template <typename T>
	T* AddComponent(const string& strTag = "Component")
	{
		T*	pComponent = new T;

		pComponent->SetScene(m_pScene);
		pComponent->SetLayer(m_pLayer);
		pComponent->SetGameObject(this);

		if (!pComponent->Init())
		{
			SAFE_RELEASE(pComponent);
			return NULL;
		}

		pComponent->AddRef();
		m_ComponentList.push_back(pComponent);

		return pComponent;
	}
};

DX11_END