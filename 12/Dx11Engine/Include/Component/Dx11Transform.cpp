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
	// Local 초기화
	m_vLocalScale = Vec3One;
	m_vLocalRot = Vec3Zero;
	m_vLocalPos = Vec3Zero;
	m_vLocalAxis[AXIS_X] = Vec3X;
	m_vLocalAxis[AXIS_Y] = Vec3Y;
	m_vLocalAxis[AXIS_Z] = Vec3Z;

	m_matLocalScale = XMMatrixIdentity();
	m_matLocalRotX = XMMatrixIdentity();
	m_matLocalRotY = XMMatrixIdentity();
	m_matLocalRotZ = XMMatrixIdentity();
	m_matLocalRot = XMMatrixIdentity();
	m_matLocalTranslate = XMMatrixIdentity();
	m_matLocalParent = XMMatrixIdentity();
	m_matLocal = XMMatrixIdentity();

	// World 초기화
	m_vWorldScale = Vec3One;
	m_vWorldRot = Vec3Zero;
	m_vWorldPos = Vec3Zero;
	m_vWorldAxis[AXIS_X] = Vec3X;
	m_vWorldAxis[AXIS_Y] = Vec3Y;
	m_vWorldAxis[AXIS_Z] = Vec3Z;

	m_matWorldScale = XMMatrixIdentity();
	m_matWorldRotX = XMMatrixIdentity();
	m_matWorldRotY = XMMatrixIdentity();
	m_matWorldRotZ = XMMatrixIdentity();
	m_matWorldRot = XMMatrixIdentity();
	m_matWorldTranslate = XMMatrixIdentity();
	m_matWorldParent = XMMatrixIdentity();
	m_matWorld = XMMatrixIdentity();

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

Vec3 CDx11Transform::GetLocalScale()
{
	return m_vLocalScale;
}

Vec3 CDx11Transform::GetLocalRot()
{
	return m_vLocalRot;
}

float CDx11Transform::GetLocalRotX()
{
	return m_vLocalRot.x;
}

float CDx11Transform::GetLocalRotY()
{
	return m_vLocalRot.y;
}

float CDx11Transform::GetLocalRotZ()
{
	return m_vLocalRot.z;
}

Vec3 CDx11Transform::GetLocalPos()
{
	return m_vLocalPos;
}

const Vec3 * CDx11Transform::GetLocalAxis()
{
	return m_vLocalAxis;
}

Vec3 CDx11Transform::GetLocalAxis(AXIS axis)
{
	return m_vLocalAxis[axis];
}

Matrix CDx11Transform::GetLocalMatrix()
{
	return m_matLocal;
}

Matrix CDx11Transform::GetLocalParent()
{
	return m_matLocalParent;
}

void CDx11Transform::SetLocalScale(const Vec3 & vScale)
{
	m_vLocalScale = vScale;
}

void CDx11Transform::SetLocalScale(float x, float y, float z)
{
	m_vLocalScale.x = x;
	m_vLocalScale.y = y;
	m_vLocalScale.z = z;
}

void CDx11Transform::SetLocalRot(const Vec3 & vRot)
{
	m_vLocalRot = vRot;
}

void CDx11Transform::SetLocalRot(float x, float y, float z)
{
	m_vLocalRot.x = x;
	m_vLocalRot.y = y;
	m_vLocalRot.z = z;
}

void CDx11Transform::SetLocalRotX(float x)
{
	m_vLocalRot.x = x;
}

void CDx11Transform::SetLocalRotY(float y)
{
	m_vLocalRot.y = y;
}

void CDx11Transform::SetLocalRotZ(float z)
{
	m_vLocalRot.z = z;
}

void CDx11Transform::SetLocalPos(const Vec3 & vPos)
{
	m_vLocalPos = vPos;
}

void CDx11Transform::SetLocalPos(float x, float y, float z)
{
	m_vLocalPos.x = x;
	m_vLocalPos.y = y;
	m_vLocalPos.z = z;
}

Vec3 CDx11Transform::GetWorldScale()
{
	return m_vWorldScale;
}

Vec3 CDx11Transform::GetWorldRot()
{
	return m_vWorldRot;
}

float CDx11Transform::GetWorldRotX()
{
	return m_vWorldRot.x;
}

float CDx11Transform::GetWorldRotY()
{
	return m_vWorldRot.y;
}

float CDx11Transform::GetWorldRotZ()
{
	return m_vWorldRot.z;
}

Vec3 CDx11Transform::GetWorldPos()
{
	return m_vWorldPos;
}

const Vec3 * CDx11Transform::GetWorldAxis()
{
	return m_vWorldAxis;
}

Vec3 CDx11Transform::GetWorldAxis(AXIS axis)
{
	return m_vWorldAxis[axis];
}

Matrix CDx11Transform::GetWorldMatrix()
{
	return m_matWorld;
}

Matrix CDx11Transform::GetWorldParent()
{
	return m_matWorldParent;
}

void CDx11Transform::SetWorldScale(const Vec3 & vScale)
{
	m_vWorldScale = vScale;
}

void CDx11Transform::SetWorldScale(float x, float y, float z)
{
	m_vWorldScale.x = x;
	m_vWorldScale.y = y;
	m_vWorldScale.z = z;
}

void CDx11Transform::SetWorldRot(const Vec3 & vRot)
{
	m_vWorldRot = vRot;
}

void CDx11Transform::SetWorldRot(float x, float y, float z)
{
	m_vWorldRot.x = x;
	m_vWorldRot.y = y;
	m_vWorldRot.z = z;
}

void CDx11Transform::SetWorldRotX(float x)
{
	m_vWorldRot.x = x;
}

void CDx11Transform::SetWorldRotY(float y)
{
	m_vWorldRot.y = y;
}

void CDx11Transform::SetWorldRotZ(float z)
{
	m_vWorldRot.z = z;
}

void CDx11Transform::SetWorldPos(const Vec3 & vPos)
{
	m_vWorldPos = vPos;
}

void CDx11Transform::SetWorldPos(float x, float y, float z)
{
	m_vWorldPos.x = x;
	m_vWorldPos.y = y;
	m_vWorldPos.z = z;
}
