#pragma once
#include "../Dx11Object.h"

DX11_BEGIN

class DX11_DLL CDx11Shader :
	public CDx11Object
{
private:
	friend class CDx11ShaderManager;

private:
	CDx11Shader();
	~CDx11Shader();

private:
	D3D11_INPUT_ELEMENT_DESC*	m_pElement;
	UINT						m_iElementCount;
	UINT						m_iElementCountMax;
	UINT						m_iElementOffset;

public:
	void AddInputLayout(char* pSemanticName, UINT iSemanticIdx,
		DXGI_FORMAT eFmt, UINT iInputSlot, UINT iSize,
		D3D11_INPUT_CLASSIFICATION eInputClass,
		UINT iInstanceData);
	bool CreateInputLayout();
};

DX11_END