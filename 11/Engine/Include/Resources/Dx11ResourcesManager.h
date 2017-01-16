#pragma once
#include "../Dx11Object.h"

DX11_BEGIN

class DX11_DLL CDx11ResourcesManager :
	public CDx11Object
{
	DX11_DECLARE_SINGLE(CDx11ResourcesManager)

private:
	unordered_map<string, class CDx11Mesh*>	m_mapMesh;

public:
	bool Init();
	class CDx11Mesh* CreateMesh(const string& strKey, UINT iVtxSize,
		UINT iVtxCount, void* pVertices, UINT iIdxSize,
		UINT iIdxCount, void* pIndices, DXGI_FORMAT	eIdxFmt,
		D3D11_PRIMITIVE_TOPOLOGY eTopology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	class CDx11Mesh* FindMesh(const string& strKey);
};

DX11_END