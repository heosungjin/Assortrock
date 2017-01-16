#pragma once
#include "Dx11Component.h"

DX11_BEGIN

class DX11_DLL CDx11Transform :
	public CDx11Component
{
private:
	friend class CDx11GameObject;

private:
	CDx11Transform();
	~CDx11Transform();

public:
	virtual bool Init();
	virtual int Update(float fTime);
	virtual int LateUpdate(float fTime);
	virtual void Render(float fTime);

private:	// Local
	Vec3		m_vLocalScale;
	Vec3		m_vLocalRot;
	Vec3		m_vLocalPos;
	Vec3		m_vLocalAxis[AXIS_MAX];

	Matrix		m_matLocalScale;
	Matrix		m_matLocalRotX;
	Matrix		m_matLocalRotY;
	Matrix		m_matLocalRotZ;
	Matrix		m_matLocalRot;
	Matrix		m_matLocalTranslate;
	Matrix		m_matLocalParent;
	Matrix		m_matLocal;

public:
	Vec3 GetLocalScale();
	Vec3 GetLocalRot();
	float GetLocalRotX();
	float GetLocalRotY();
	float GetLocalRotZ();
	Vec3 GetLocalPos();
	const Vec3* GetLocalAxis();
	Vec3 GetLocalAxis(AXIS axis);
	Matrix GetLocalMatrix();
	Matrix GetLocalParent();

public:
	void SetLocalScale(const Vec3& vScale);
	void SetLocalScale(float x, float y, float z);
	void SetLocalRot(const Vec3& vRot);
	void SetLocalRot(float x, float y, float z);
	void SetLocalRotX(float x);
	void SetLocalRotY(float y);
	void SetLocalRotZ(float z);
	void SetLocalPos(const Vec3& vPos);
	void SetLocalPos(float x, float y, float z);

private:	// World
	Vec3		m_vWorldScale;
	Vec3		m_vWorldRot;
	Vec3		m_vWorldPos;
	Vec3		m_vWorldAxis[AXIS_MAX];

	Matrix		m_matWorldScale;
	Matrix		m_matWorldRotX;
	Matrix		m_matWorldRotY;
	Matrix		m_matWorldRotZ;
	Matrix		m_matWorldRot;
	Matrix		m_matWorldTranslate;
	Matrix		m_matWorldParent;
	Matrix		m_matWorld;

public:
	Vec3 GetWorldScale();
	Vec3 GetWorldRot();
	float GetWorldRotX();
	float GetWorldRotY();
	float GetWorldRotZ();
	Vec3 GetWorldPos();
	const Vec3* GetWorldAxis();
	Vec3 GetWorldAxis(AXIS axis);
	Matrix GetWorldMatrix();
	Matrix GetWorldParent();

public:
	void SetWorldScale(const Vec3& vScale);
	void SetWorldScale(float x, float y, float z);
	void SetWorldRot(const Vec3& vRot);
	void SetWorldRot(float x, float y, float z);
	void SetWorldRotX(float x);
	void SetWorldRotY(float y);
	void SetWorldRotZ(float z);
	void SetWorldPos(const Vec3& vPos);
	void SetWorldPos(float x, float y, float z);
};

DX11_END