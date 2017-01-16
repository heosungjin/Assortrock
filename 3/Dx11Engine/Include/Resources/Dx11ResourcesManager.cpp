#include "Dx11ResourcesManager.h"
#include "Dx11Mesh.h"

DX11_USING

DX11_DEFINITION_SINGLE(CDx11ResourcesManager)

CDx11ResourcesManager::CDx11ResourcesManager()
{
}

CDx11ResourcesManager::~CDx11ResourcesManager()
{
	Safe_Release_Map(m_mapMesh);
}

bool CDx11ResourcesManager::Init()
{
	return true;
}

CDx11Mesh * CDx11ResourcesManager::CreateMesh(const string & strKey, 
	UINT iVtxSize, UINT iVtxCount, void * pVertices,
	UINT iIdxSize, UINT iIdxCount, void * pIndices, 
	DXGI_FORMAT eIdxFmt)
{
	CDx11Mesh*	pMesh = FindMesh(strKey);

	if (pMesh)
		return pMesh;

	pMesh = new CDx11Mesh;

	if (!pMesh->CreateMesh(iVtxSize, iVtxCount, pVertices,
		iIdxSize, iIdxCount, pIndices, eIdxFmt))
	{
		SAFE_RELEASE(pMesh);
		return NULL;
	}

	pMesh->AddRef();
	m_mapMesh.insert(make_pair(strKey, pMesh));

	return pMesh;
}

CDx11Mesh * CDx11ResourcesManager::FindMesh(const string & strKey)
{
	unordered_map<string, class CDx11Mesh*>::iterator	iter = m_mapMesh.find(strKey);

	if (iter == m_mapMesh.end())
		return NULL;

	iter->second->AddRef();

	return iter->second;
}
