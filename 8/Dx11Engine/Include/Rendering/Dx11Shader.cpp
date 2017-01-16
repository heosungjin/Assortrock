#include "Dx11Shader.h"
#include "../Core/Dx11Device.h"
#include "../Core/Dx11FilePathManager.h"

DX11_USING

CDx11Shader::CDx11Shader()	:
	m_pElement(NULL),
	m_pVSBlob(NULL),
	m_pVS(NULL),
	m_pPSBlob(NULL),
	m_pPS(NULL),
	m_pInputLayout(NULL),
	m_iElementCount(0),
	m_iElementOffset(0),
	m_iElementCountMax(0)
{
}

CDx11Shader::~CDx11Shader()
{
	SAFE_RELEASE(m_pInputLayout);
	SAFE_RELEASE(m_pVSBlob);
	SAFE_RELEASE(m_pVS);
	SAFE_RELEASE(m_pPSBlob);
	SAFE_RELEASE(m_pPS);
	SAFE_DELETE_ARRAY(m_pElement);
}

bool CDx11Shader::LoadShader(TCHAR * pFileName, char * pEntry[ST_MAX], int iHighV,
	int iLowV, const string & strPathKey)
{
	// ¹öÅØ½º ¼ÎÀÌ´õ ·Îµù
	if (!LoadVertexShader(pFileName, pEntry[ST_VERTEX], iHighV, iLowV, strPathKey))
		return false;

	// ÇÈ¼¿ ¼ÎÀÌ´õ ·Îµù
	if (!LoadPixelShader(pFileName, pEntry[ST_PIXEL], iHighV, iLowV, strPathKey))
		return false;

	return true;
}

void CDx11Shader::AddInputLayout(char * pSemanticName, UINT iSemanticIdx,
	DXGI_FORMAT eFmt, UINT iInputSlot, UINT iSize, 
	D3D11_INPUT_CLASSIFICATION eInputClass, UINT iInstanceData)
{
	if (!m_pElement)
	{
		m_iElementCountMax = 2;
		m_pElement = new D3D11_INPUT_ELEMENT_DESC[m_iElementCountMax];
		memset(m_pElement, 0, sizeof(D3D11_INPUT_ELEMENT_DESC) * m_iElementCountMax);
	}

	else if (m_iElementCount == m_iElementCountMax)
	{
		m_iElementCountMax *= 2;

		D3D11_INPUT_ELEMENT_DESC*	pElement = NULL;
		pElement	= new D3D11_INPUT_ELEMENT_DESC[m_iElementCountMax];

		memcpy(pElement, m_pElement, sizeof(D3D11_INPUT_ELEMENT_DESC) * m_iElementCount);
		SAFE_DELETE_ARRAY(m_pElement);

		m_pElement = pElement;
	}
	
	m_pElement[m_iElementCount].SemanticName = pSemanticName;
	m_pElement[m_iElementCount].SemanticIndex = iSemanticIdx;
	m_pElement[m_iElementCount].InputSlot = iInputSlot;
	m_pElement[m_iElementCount].Format = eFmt;
	m_pElement[m_iElementCount].AlignedByteOffset = m_iElementOffset;
	m_pElement[m_iElementCount].InputSlotClass = eInputClass;
	m_pElement[m_iElementCount].InstanceDataStepRate = iInstanceData;

	++m_iElementCount;
	m_iElementOffset += iSize;
}

bool CDx11Shader::CreateInputLayout()
{
	if (FAILED(DX11_DEVICE->CreateInputLayout(m_pElement, m_iElementCount,
		m_pVSBlob->GetBufferPointer(), m_pVSBlob->GetBufferSize(),
		&m_pInputLayout)))
		return false;

	return true;
}

void CDx11Shader::SetShader()
{
	DX11_CONTEXT->IASetInputLayout(m_pInputLayout);
	DX11_CONTEXT->VSSetShader(m_pVS, NULL, 0);
	DX11_CONTEXT->PSSetShader(m_pPS, NULL, 0);
}

bool CDx11Shader::LoadVertexShader(TCHAR * pFileName, char * pEntry, 
	int iHighV, int iLowV, const string & strPathKey)
{
	SAFE_RELEASE(m_pVSBlob);
	SAFE_RELEASE(m_pVS);

	DWORD	dwFlag = 0;

#if defined(_DEBUG) | defined(DEBUG)
	dwFlag = D3DCOMPILE_DEBUG;
#endif // defined(_DEBUG) | defined(DEBUG)

	wstring	strPath = DX11_GET_SINGLE(CDx11FilePathManager)->FindPath(strPathKey);
	strPath += pFileName;

	char	strVersion[32] = {};
	sprintf_s(strVersion, "vs_%d_%d", iHighV, iLowV);

	ID3DBlob*	pErr = NULL;
	if (FAILED(D3DCompileFromFile(strPath.c_str(), NULL, NULL, pEntry,
		strVersion, dwFlag, 0, &m_pVSBlob, &pErr)))
	{
		MessageBoxA(NULL, (char*)pErr->GetBufferPointer(), "Error", MB_OK);
		SAFE_RELEASE(pErr);
		return false;
	}

	if (FAILED(DX11_DEVICE->CreateVertexShader(m_pVSBlob->GetBufferPointer(),
		m_pVSBlob->GetBufferSize(), NULL, &m_pVS)))
		return false;

	return true;
}

bool CDx11Shader::LoadPixelShader(TCHAR * pFileName, char * pEntry, int iHighV, int iLowV, const string & strPathKey)
{
	SAFE_RELEASE(m_pPSBlob);
	SAFE_RELEASE(m_pPS);

	DWORD	dwFlag = 0;

#if defined(_DEBUG) | defined(DEBUG)
	dwFlag = D3DCOMPILE_DEBUG;
#endif // defined(_DEBUG) | defined(DEBUG)

	wstring	strPath = DX11_GET_SINGLE(CDx11FilePathManager)->FindPath(strPathKey);
	strPath += pFileName;

	char	strVersion[32] = {};
	sprintf_s(strVersion, "ps_%d_%d", iHighV, iLowV);

	ID3DBlob*	pErr = NULL;
	if (FAILED(D3DCompileFromFile(strPath.c_str(), NULL, NULL, pEntry,
		strVersion, dwFlag, 0, &m_pPSBlob, &pErr)))
	{
		MessageBoxA(NULL, (char*)pErr->GetBufferPointer(), "Error", MB_OK);
		SAFE_RELEASE(pErr);
		return false;
	}

	if (FAILED(DX11_DEVICE->CreatePixelShader(m_pPSBlob->GetBufferPointer(),
		m_pPSBlob->GetBufferSize(), NULL, &m_pPS)))
		return false;

	return true;
}
