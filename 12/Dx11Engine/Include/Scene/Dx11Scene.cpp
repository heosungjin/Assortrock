#include "Dx11Scene.h"
#include "Dx11Layer.h"
#include "../Component/Dx11Script.h"

DX11_USING

CDx11Scene::CDx11Scene()
{
	SetTypeName<CDx11Scene>();
}

CDx11Scene::~CDx11Scene()
{
	Safe_Release_VecList(m_vecScript);
	Safe_Release_VecList(m_vecLayer);
}

bool CDx11Scene::Init()
{
	CDx11Layer*	pLayer = CreateLayer("DefaultLayer");

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
	vector<CDx11Script*>::iterator	iter1;
	vector<CDx11Script*>::iterator	iter1End = m_vecScript.end();

	for (iter1 = m_vecScript.begin(); iter1 != iter1End;)
	{
		if (!(*iter1)->GetEnable())
		{
			++iter1;
			continue;
		}

		(*iter1)->Update(fTime);

		if (!(*iter1)->GetAlive())
		{
			SAFE_RELEASE((*iter1));
			iter1 = m_vecScript.erase(iter1);
			continue;
		}

		else
			++iter1;
	}

	vector<CDx11Layer*>::iterator	iter;
	vector<CDx11Layer*>::iterator	iterEnd = m_vecLayer.end();

	for (iter = m_vecLayer.begin(); iter != iterEnd;)
	{
		if (!(*iter)->GetEnable())
		{
			++iter;
			continue;
		}

		(*iter)->Update(fTime);

		if (!(*iter)->GetAlive())
		{
			SAFE_RELEASE((*iter));
			iter = m_vecLayer.erase(iter);
			continue;
		}

		else
			++iter;
	}

	return 0;
}

int CDx11Scene::LateUpdate(float fTime)
{
	vector<CDx11Script*>::iterator	iter1;
	vector<CDx11Script*>::iterator	iter1End = m_vecScript.end();

	for (iter1 = m_vecScript.begin(); iter1 != iter1End;)
	{
		if (!(*iter1)->GetEnable())
		{
			++iter1;
			continue;
		}

		(*iter1)->LateUpdate(fTime);

		if (!(*iter1)->GetAlive())
		{
			SAFE_RELEASE((*iter1));
			iter1 = m_vecScript.erase(iter1);
			continue;
		}

		else
			++iter1;
	}

	vector<CDx11Layer*>::iterator	iter;
	vector<CDx11Layer*>::iterator	iterEnd = m_vecLayer.end();

	for (iter = m_vecLayer.begin(); iter != iterEnd;)
	{
		if (!(*iter)->GetEnable())
		{
			++iter;
			continue;
		}

		(*iter)->LateUpdate(fTime);

		if (!(*iter)->GetAlive())
		{
			SAFE_RELEASE((*iter));
			iter = m_vecLayer.erase(iter);
			continue;
		}

		else
			++iter;
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
	vector<CDx11Script*>::iterator	iter1;
	vector<CDx11Script*>::iterator	iter1End = m_vecScript.end();

	for (iter1 = m_vecScript.begin(); iter1 != iter1End;)
	{
		if (!(*iter1)->GetEnable())
		{
			++iter1;
			continue;
		}

		(*iter1)->Render(fTime);

		if (!(*iter1)->GetAlive())
		{
			SAFE_RELEASE((*iter1));
			iter1 = m_vecScript.erase(iter1);
			continue;
		}

		else
			++iter1;
	}

	vector<CDx11Layer*>::iterator	iter;
	vector<CDx11Layer*>::iterator	iterEnd = m_vecLayer.end();

	for (iter = m_vecLayer.begin(); iter != iterEnd;)
	{
		if (!(*iter)->GetEnable())
		{
			++iter;
			continue;
		}

		(*iter)->Render(fTime);

		if (!(*iter)->GetAlive())
		{
			SAFE_RELEASE((*iter));
			iter = m_vecLayer.erase(iter);
			continue;
		}

		else
			++iter;
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
