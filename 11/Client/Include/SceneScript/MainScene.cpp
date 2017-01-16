#include "MainScene.h"
#include "GameObject/Dx11GameObject.h"
#include "Component/Dx11Transform.h"
#include "Component/Dx11Renderer.h"
#include "Scene/Dx11Scene.h"
#include "Scene/Dx11Layer.h"

CMainScene::CMainScene()
{
}

CMainScene::~CMainScene()
{
}

bool CMainScene::Init()
{
	CDx11Layer*	pLayer = m_pScene->FindLayer("DefaultLayer");

	if (!pLayer)
		return false;

	CDx11GameObject*	pPlayer = CDx11GameObject::Create("PlayerObject");

	// 렌더러를 생성한다.
	CDx11Renderer*	pRenderer = pPlayer->AddComponent<CDx11Renderer>("Renderer");

	pRenderer->SetMesh(TRIANGLE_MESH);
	pRenderer->SetShader(DEFAULT_SHADER);

	SAFE_RELEASE(pRenderer);

	pLayer->AddObject(pPlayer);

	SAFE_RELEASE(pPlayer);

	SAFE_RELEASE(pLayer);

	return true;
}

int CMainScene::Update(float fTime)
{
	return 0;
}

int CMainScene::LateUpdate(float fTime)
{
	return 0;
}

void CMainScene::Render(float fTime)
{
}
