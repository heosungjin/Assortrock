#include "Dx11Scene.h"
#include "Dx11Layer.h"

DX11_USING

CDx11Scene::CDx11Scene()
{
	SetTypeName<CDx11Scene>();
}

CDx11Scene::~CDx11Scene()
{
	Safe_Release_VecList(m_vecLayer);
}

bool CDx11Scene::Init()
{
	CDx11Layer*	pLayer = CreateLayer("Default");

	SAFE_RELEASE(pLayer);

	return true;
}

void CDx11Scene::Input(float fTime)
{
	vector<CDx11Layer*>::iterator	iter;
	vector<CDx11Layer*>::iterator	iterEnd = m_vecLayer.end();

	for (iter = m_vecLayer.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Input(fTime);
	}
}

int CDx11Scene::Update(float fTime)
{
	vector<CDx11Layer*>::iterator	iter;
	vector<CDx11Layer*>::iterator	iterEnd = m_vecLayer.end();

	for (iter = m_vecLayer.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Update(fTime);
	}

	return 0;
}

int CDx11Scene::LateUpdate(float fTime)
{
	vector<CDx11Layer*>::iterator	iter;
	vector<CDx11Layer*>::iterator	iterEnd = m_vecLayer.end();

	for (iter = m_vecLayer.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->LateUpdate(fTime);
	}

	return 0;
}

void CDx11Scene::Collision(float fTime)
{
	vector<CDx11Layer*>::iterator	iter;
	vector<CDx11Layer*>::iterator	iterEnd = m_vecLayer.end();

	for (iter = m_vecLayer.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Collision(fTime);
	}
}

void CDx11Scene::Render(float fTime)
{
	vector<CDx11Layer*>::iterator	iter;
	vector<CDx11Layer*>::iterator	iterEnd = m_vecLayer.end();

	for (iter = m_vecLayer.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Render(fTime);
	}
}

CDx11Layer * CDx11Scene::CreateLayer(const string & strTag)
{
	CDx11Layer*	pLayer = new CDx11Layer;

	if (!pLayer->Init())
	{
		SAFE_RELEASE(pLayer);
		return NULL;
	}

	pLayer->SetTag(strTag);
	pLayer->SetScene(this);

	pLayer->AddRef();
	m_vecLayer.push_back(pLayer);

	return pLayer;
}

CDx11Layer * CDx11Scene::FindLayer(const string & strTag)
{
	vector<CDx11Layer*>::iterator	iter;
	vector<CDx11Layer*>::iterator	iterEnd = m_vecLayer.end();

	for (iter = m_vecLayer.begin(); iter != iterEnd; ++iter)
	{
		if ((*iter)->GetTag() == strTag)
		{
			(*iter)->AddRef();
			return *iter;
		}
	}

	return NULL;
}
