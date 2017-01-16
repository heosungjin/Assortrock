#include "Dx11Transform.h"

DX11_USING

CDx11Transform::CDx11Transform()
{
	m_eComType = CT_TRANSFORM;
	SetTypeName<CDx11Transform>();
}

CDx11Transform::~CDx11Transform()
{
}

bool CDx11Transform::Init()
{
	return true;
}

int CDx11Transform::Update(float fTime)
{
	return 0;
}

int CDx11Transform::LateUpdate(float fTime)
{
	return 0;
}

void CDx11Transform::Render(float fTime)
{
}
