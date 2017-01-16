#include "Dx11Renderer.h"
#include "../Resources/Dx11Mesh.h"
#include "../Rendering/Dx11Shader.h"
#include "../Resources/Dx11ResourcesManager.h"
#include "../Rendering/Dx11ShaderManager.h"

DX11_USING

CDx11Renderer::CDx11Renderer()	:
	m_pMesh(NULL),
	m_pShader(NULL)
{
	m_eComType = CT_RENDERER;
}

CDx11Renderer::~CDx11Renderer()
{
	SAFE_RELEASE(m_pMesh);
	SAFE_RELEASE(m_pShader);
}

bool CDx11Renderer::Init()
{
	return true;
}

int CDx11Renderer::Update(float fTime)
{
	return 0;
}

int CDx11Renderer::LateUpdate(float fTime)
{
	return 0;
}

void CDx11Renderer::Render(float fTime)
{
	m_pShader->SetShader();
	m_pMesh->Render();
}

void CDx11Renderer::SetMesh(const string & strKey)
{
	SAFE_RELEASE(m_pMesh);
	m_pMesh = DX11_GET_SINGLE(CDx11ResourcesManager)->FindMesh(strKey);
}

void CDx11Renderer::SetShader(const string & strKey)
{
	SAFE_RELEASE(m_pShader);
	m_pShader = DX11_GET_SINGLE(CDx11ShaderManager)->FindShader(strKey);
}
