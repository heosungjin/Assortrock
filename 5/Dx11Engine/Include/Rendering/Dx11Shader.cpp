#include "Dx11Shader.h"
#include "../Core/Dx11Device.h"

DX11_USING

CDx11Shader::CDx11Shader()	:
	m_pElement(NULL),
	m_iElementCount(0),
	m_iElementOffset(0),
	m_iElementCountMax(0)
{
}

CDx11Shader::~CDx11Shader()
{
	SAFE_DELETE_ARRAY(m_pElement);
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
	//if(FAILED(DX11_DEVICE->CreateInputLayout(m_pElement, m_iElementCount,)))

	return true;
}
