#include "Dx11GameObject.h"
#include "../Scene/Dx11Scene.h"
#include "../Scene/Dx11layer.h"
#include "../Component/Dx11Transform.h"

DX11_USING

CDx11GameObject::CDx11GameObject()	:
	m_pTransform(NULL)
{
	SetTypeName<CDx11GameObject>();
}

CDx11GameObject::~CDx11GameObject()
{
	SAFE_RELEASE(m_pTransform);
	Safe_Release_VecList(m_ComponentList);
}

void CDx11GameObject::SetScene(CDx11Scene * pScene)
{
	m_pScene = pScene;

	list<CDx11Component*>::iterator	iter;
	list<CDx11Component*>::iterator	iterEnd = m_ComponentList.end();

	for (iter = m_ComponentList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->SetScene(pScene);
	}
}

void CDx11GameObject::SetLayer(CDx11Layer * pLayer)
{
	m_pLayer = pLayer;

	list<CDx11Component*>::iterator	iter;
	list<CDx11Component*>::iterator	iterEnd = m_ComponentList.end();

	for (iter = m_ComponentList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->SetLayer(pLayer);
	}
}

CDx11Transform * CDx11GameObject::GetTransform()
{
	m_pTransform->AddRef();

	return m_pTransform;
}

bool CDx11GameObject::Init()
{
	// Transform을 생성한다.
	m_pTransform = AddComponent<CDx11Transform>("Transform");

	return true;
}

int CDx11GameObject::Update(float fTime)
{
	return 0;
}

int CDx11GameObject::LateUpdate(float fTime)
{
	return 0;
}

void CDx11GameObject::Render(float fTime)
{
}

CDx11Component * CDx11GameObject::FindComponentFromTag(const string & strTag)
{
	list<CDx11Component*>::iterator	iter;
	list<CDx11Component*>::iterator	iterEnd = m_ComponentList.end();

	for (iter = m_ComponentList.begin(); iter != iterEnd; ++iter)
	{
		if ((*iter)->GetTag() == strTag)
		{
			(*iter)->AddRef();
			return *iter;
		}
	}

	return NULL;
}

CDx11Component * CDx11GameObject::FindComponentFromTypeName(const string & strTypeName)
{
	list<CDx11Component*>::iterator	iter;
	list<CDx11Component*>::iterator	iterEnd = m_ComponentList.end();

	for (iter = m_ComponentList.begin(); iter != iterEnd; ++iter)
	{
		if ((*iter)->GetTypeName() == strTypeName)
		{
			(*iter)->AddRef();
			return *iter;
		}
	}

	return NULL;
}

list<CDx11Component*>* CDx11GameObject::FindComponentsFromTag(const string & strTag)
{
	list<CDx11Component*>::iterator	iter;
	list<CDx11Component*>::iterator	iterEnd = m_FindList.end();

	for (iter = m_FindList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Release();
	}

	m_FindList.clear();

	iterEnd = m_ComponentList.end();

	for (iter = m_ComponentList.begin(); iter != iterEnd; ++iter)
	{
		if ((*iter)->GetTag() == strTag)
		{
			(*iter)->AddRef();
			m_FindList.push_back(*iter);
		}
	}

	return &m_FindList;
}

list<CDx11Component*>* CDx11GameObject::FindComponentsFromTypeName(const string & strTypeName)
{
	list<CDx11Component*>::iterator	iter;
	list<CDx11Component*>::iterator	iterEnd = m_FindList.end();

	for (iter = m_FindList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Release();
	}

	m_FindList.clear();

	iterEnd = m_ComponentList.end();

	for (iter = m_ComponentList.begin(); iter != iterEnd; ++iter)
	{
		if ((*iter)->GetTypeName() == strTypeName)
		{
			(*iter)->AddRef();
			m_FindList.push_back(*iter);
		}
	}

	return &m_FindList;
}

void CDx11GameObject::AddComponent(CDx11Component * pComponent)
{
	pComponent->AddRef();
	pComponent->SetScene(m_pScene);
	pComponent->SetLayer(m_pLayer);
	pComponent->SetGameObject(this);
	m_ComponentList.push_back(pComponent);
}
