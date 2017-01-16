#pragma once
#include "../Dx11Object.h"

DX11_BEGIN

class DX11_DLL CDx11ShaderManager :
	public CDx11Object
{
	DX11_DECLARE_SINGLE(CDx11ShaderManager)

private:
	unordered_map<string, class CDx11Shader*>	m_mapShader;

public:
	bool Init();
};

DX11_END