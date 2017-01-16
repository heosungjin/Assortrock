#include "Dx11ResourcesManager.h"
#include "Dx11Mesh.h"

DX11_USING

DX11_DEFINITION_SINGLE(CDx11ResourcesManager)

CDx11ResourcesManager::CDx11ResourcesManager()
{
	SetTypeName<CDx11ResourcesManager>();
}

CDx11ResourcesManager::~CDx11ResourcesManager()
{
	Safe_Release_Map(m_mapMesh);
}

bool CDx11ResourcesManager::Init()
{
	COLORVERTEX	tColorVtx[3] = 
	{
		{ Vec3(0.f, 0.5f, 0.f), Vec4(1.f, 0.f, 0.f, 1.f) },
		{ Vec3(0.5f, -0.5f, 0.f), Vec4(0.f, 1.f, 0.f, 1.f) },
		{ Vec3(-0.5f, -0.5f, 0.f), Vec4(0.f, 0.f, 1.f, 1.f) }
	};

	UINT	iIndex[3] = { 0, 1, 2 };

	CDx11Mesh*	pMesh = CreateMesh(TRIANGLE_MESH, sizeof(COLORVERTEX),
		3, tColorVtx, sizeof(UINT), 3, iIndex,
		DXGI_FORMAT_R32_UINT);

	SAFE_RELEASE(pMesh);

	return true;
}

CDx11Mesh * CDx11ResourcesManager::CreateMesh(const string & strKey, 
	UINT iVtxSize, UINT iVtxCount, void * pVertices,
	UINT iIdxSize, UINT iIdxCount, void * pIndices, 
	DXGI_FORMAT eIdxFmt,
	D3D11_PRIMITIVE_TOPOLOGY eTopology)
{
	CDx11Mesh*	pMesh = FindMesh(strKey);

	if (pMesh)
		return pMesh;

	pMesh = new CDx11Mesh;

	if (!pMesh->CreateMesh(iVtxSize, iVtxCount, pVertices,
		iIdxSize, iIdxCount, pIndices, eIdxFmt, eTopology))
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
