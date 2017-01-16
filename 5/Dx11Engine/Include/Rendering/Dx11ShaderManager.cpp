#include "Dx11ShaderManager.h"
#include "Dx11Shader.h"

DX11_USING

DX11_DEFINITION_SINGLE(CDx11ShaderManager)

CDx11ShaderManager::CDx11ShaderManager()
{
}

CDx11ShaderManager::~CDx11ShaderManager()
{
	Safe_Release_Map(m_mapShader);
}

bool CDx11ShaderManager::Init()
{
	return true;
}
