#include "Dx11Mesh.h"
#include "../Core/Dx11Device.h"

DX11_USING

CDx11Mesh::CDx11Mesh()	:
	m_pVB(NULL),
	m_pIB(NULL)
{
}

CDx11Mesh::~CDx11Mesh()
{
	SAFE_RELEASE(m_pVB);
	SAFE_RELEASE(m_pIB);
}

bool CDx11Mesh::CreateMesh(UINT iVtxSize, UINT iVtxCount, 
	void * pVertices, UINT iIdxSize, UINT iIdxCount, 
	void * pIndices, DXGI_FORMAT eIdxFmt)
{
	m_iVtxSize = iVtxSize;
	m_iVtxCount = iVtxCount;
	m_iIdxSize = iIdxSize;
	m_iIdxCount = iIdxCount;
	m_eIdxFmt = eIdxFmt;

	if (!CreateVertexBuffer(iVtxSize, iVtxCount, pVertices))
		return false;
	
	if (!CreateIndexBuffer(iIdxSize, iIdxCount, pIndices, eIdxFmt))
		return false;

	return true;
}

bool CDx11Mesh::CreateVertexBuffer(UINT iVtxSize, UINT iVtxCount,
	void * pVertices)
{
	D3D11_BUFFER_DESC	tDesc = {};

	tDesc.ByteWidth = iVtxSize * iVtxCount;
	tDesc.Usage = D3D11_USAGE_DEFAULT;
	tDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA	tData = {};
	tData.pSysMem = pVertices;

	if (FAILED(DX11_DEVICE->CreateBuffer(&tDesc, &tData,
		&m_pVB)))
	{
		SAFE_RELEASE(m_pVB);
		return false;
	}

	return true;
}

bool CDx11Mesh::CreateIndexBuffer(UINT iIdxSize, UINT iIdxCount,
	void * pIndices, DXGI_FORMAT eIdxFmt)
{
	D3D11_BUFFER_DESC	tDesc = {};

	tDesc.ByteWidth = iIdxSize * iIdxCount;
	tDesc.Usage = D3D11_USAGE_DEFAULT;
	tDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;

	D3D11_SUBRESOURCE_DATA	tData = {};
	tData.pSysMem = pIndices;

	if (FAILED(DX11_DEVICE->CreateBuffer(&tDesc, &tData,
		&m_pIB)))
	{
		SAFE_RELEASE(m_pIB);
		return false;
	}

	return true;
}
