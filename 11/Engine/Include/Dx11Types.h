#pragma once

#include <Windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <list>
#include <vector>
#include <unordered_map>
#include <string>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <crtdbg.h>
#include <conio.h>

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

#pragma comment(lib, "d3d11")
#pragma comment(lib, "d3dcompiler")

// 사용자 정의 헤더파일
#include "Dx11Macro.h"
#include "Dx11Flag.h"

// Resolution
typedef struct _tagResolution
{
	UINT	iWidth;
	UINT	iHeight;

	_tagResolution() :
		iWidth(0),
		iHeight(0)
	{
	}

	_tagResolution(UINT iW, UINT iH) :
		iWidth(iW),
		iHeight(iH)
	{
	}
}RESOLUTION, *PRESOLUTION;

const RESOLUTION	g_tRS[RT_MAX]	=
{
	RESOLUTION(800, 600),
	RESOLUTION(1280, 720),
	RESOLUTION(1920, 1080)
};

typedef struct _tagVector2 :
	public XMFLOAT2
{
	_tagVector2()
	{
		x = 0.f;
		y = 0.f;
	}

	_tagVector2(float _x, float _y)
	{
		x = _x;
		y = _y;
	}

	_tagVector2 operator +(const _tagVector2& v)	const
	{
		_tagVector2	v1;
		v1.x = x + v.x;
		v1.y = y + v.y;
		return v1;
	}

	_tagVector2 operator +(float fValue)	const
	{
		_tagVector2	v1;
		v1.x = x + fValue;
		v1.y = y + fValue;
		return v1;
	}

	// 함수 뒤에 const를 붙여주게 되면 이 함수에서는 멤버변수의
	// 값을 변경할 수 없다.
	_tagVector2 operator +(int iValue)	const
	{
		_tagVector2	v1;
		v1.x = x + (float)iValue;
		v1.y = y + (float)iValue;
		return v1;
	}

	void operator +=(const _tagVector2& v)
	{
		x += v.x;
		y += v.y;
	}

	void operator +=(float fValue)
	{
		x += fValue;
		y += fValue;
	}

	void operator +=(int iValue)
	{
		x += (float)iValue;
		y += (float)iValue;
	}

	_tagVector2 operator -(const _tagVector2& v)	const
	{
		_tagVector2	v1;
		v1.x = x - v.x;
		v1.y = y - v.y;
		return v1;
	}

	_tagVector2 operator -(float fValue)	const
	{
		_tagVector2	v1;
		v1.x = x - fValue;
		v1.y = y - fValue;
		return v1;
	}

	// 함수 뒤에 const를 붙여주게 되면 이 함수에서는 멤버변수의
	// 값을 변경할 수 없다.
	_tagVector2 operator -(int iValue)	const
	{
		_tagVector2	v1;
		v1.x = x - (float)iValue;
		v1.y = y - (float)iValue;
		return v1;
	}

	void operator -=(const _tagVector2& v)
	{
		x -= v.x;
		y -= v.y;
	}

	void operator -=(float fValue)
	{
		x -= fValue;
		y -= fValue;
	}

	void operator -=(int iValue)
	{
		x -= (float)iValue;
		y -= (float)iValue;
	}

	_tagVector2 operator *(const _tagVector2& v)	const
	{
		_tagVector2	v1;
		v1.x = x * v.x;
		v1.y = y * v.y;
		return v1;
	}

	_tagVector2 operator *(float fValue)	const
	{
		_tagVector2	v1;
		v1.x = x * fValue;
		v1.y = y * fValue;
		return v1;
	}

	// 함수 뒤에 const를 붙여주게 되면 이 함수에서는 멤버변수의
	// 값을 변경할 수 없다.
	_tagVector2 operator *(int iValue)	const
	{
		_tagVector2	v1;
		v1.x = x * (float)iValue;
		v1.y = y * (float)iValue;
		return v1;
	}

	void operator *=(const _tagVector2& v)
	{
		x *= v.x;
		y *= v.y;
	}

	void operator *=(float fValue)
	{
		x *= fValue;
		y *= fValue;
	}

	void operator *=(int iValue)
	{
		x *= (float)iValue;
		y *= (float)iValue;
	}

	_tagVector2 operator /(const _tagVector2& v)	const
	{
		_tagVector2	v1;
		v1.x = x / v.x;
		v1.y = y / v.y;
		return v1;
	}

	_tagVector2 operator /(float fValue)	const
	{
		_tagVector2	v1;
		v1.x = x / fValue;
		v1.y = y / fValue;
		return v1;
	}

	// 함수 뒤에 const를 붙여주게 되면 이 함수에서는 멤버변수의
	// 값을 변경할 수 없다.
	_tagVector2 operator /(int iValue)	const
	{
		_tagVector2	v1;
		v1.x = x / (float)iValue;
		v1.y = y / (float)iValue;
		return v1;
	}

	void operator /=(const _tagVector2& v)
	{
		x /= v.x;
		y /= v.y;
	}

	void operator /=(float fValue)
	{
		x /= fValue;
		y /= fValue;
	}

	void operator /=(int iValue)
	{
		x /= (float)iValue;
		y /= (float)iValue;
	}

	float Length()	const
	{
		return sqrtf(x * x + y * y);
	}

	_tagVector2 Normalize()	const
	{
		_tagVector2	v;
		float	fLength = Length();
		v.x = x / fLength;
		v.y = y / fLength;
		return v;
	}

	float Dot(const _tagVector2& v)	const
	{
		return x * v.x + y * v.y;
	}
}VECTOR2, *PVECTOR2;

typedef struct _tagVector3 :
	public XMFLOAT3
{
	_tagVector3()
	{
		x = 0.f;
		y = 0.f;
		z = 0.f;
	}

	_tagVector3(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	_tagVector3 operator +(const _tagVector3& v)	const
	{
		_tagVector3	v1;
		v1.x = x + v.x;
		v1.y = y + v.y;
		v1.z = z + v.z;
		return v1;
	}

	_tagVector3 operator +(float fValue)	const
	{
		_tagVector3	v1;
		v1.x = x + fValue;
		v1.y = y + fValue;
		v1.z = z + fValue;
		return v1;
	}

	// 함수 뒤에 const를 붙여주게 되면 이 함수에서는 멤버변수의
	// 값을 변경할 수 없다.
	_tagVector3 operator +(int iValue)	const
	{
		_tagVector3	v1;
		v1.x = x + (float)iValue;
		v1.y = y + (float)iValue;
		v1.z = z + (float)iValue;
		return v1;
	}

	void operator +=(const _tagVector3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}

	void operator +=(float fValue)
	{
		x += fValue;
		y += fValue;
		z += fValue;
	}

	void operator +=(int iValue)
	{
		x += (float)iValue;
		y += (float)iValue;
		z += (float)iValue;
	}

	_tagVector3 operator -(const _tagVector3& v)	const
	{
		_tagVector3	v1;
		v1.x = x - v.x;
		v1.y = y - v.y;
		v1.z = z - v.z;
		return v1;
	}

	_tagVector3 operator -(float fValue)	const
	{
		_tagVector3	v1;
		v1.x = x - fValue;
		v1.y = y - fValue;
		v1.z = z - fValue;
		return v1;
	}

	// 함수 뒤에 const를 붙여주게 되면 이 함수에서는 멤버변수의
	// 값을 변경할 수 없다.
	_tagVector3 operator -(int iValue)	const
	{
		_tagVector3	v1;
		v1.x = x - (float)iValue;
		v1.y = y - (float)iValue;
		v1.z = z - (float)iValue;
		return v1;
	}

	void operator -=(const _tagVector3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	void operator -=(float fValue)
	{
		x -= fValue;
		y -= fValue;
		z -= fValue;
	}

	void operator -=(int iValue)
	{
		x -= (float)iValue;
		y -= (float)iValue;
		z -= (float)iValue;
	}

	_tagVector3 operator *(const _tagVector3& v)	const
	{
		_tagVector3	v1;
		v1.x = x * v.x;
		v1.y = y * v.y;
		v1.z = z * v.z;
		return v1;
	}

	_tagVector3 operator *(float fValue)	const
	{
		_tagVector3	v1;
		v1.x = x * fValue;
		v1.y = y * fValue;
		v1.z = z * fValue;
		return v1;
	}

	// 함수 뒤에 const를 붙여주게 되면 이 함수에서는 멤버변수의
	// 값을 변경할 수 없다.
	_tagVector3 operator *(int iValue)	const
	{
		_tagVector3	v1;
		v1.x = x * (float)iValue;
		v1.y = y * (float)iValue;
		v1.z = z * (float)iValue;
		return v1;
	}

	void operator *=(const _tagVector3& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
	}

	void operator *=(float fValue)
	{
		x *= fValue;
		y *= fValue;
		z *= fValue;
	}

	void operator *=(int iValue)
	{
		x *= (float)iValue;
		y *= (float)iValue;
		z *= (float)iValue;
	}

	_tagVector3 operator /(const _tagVector3& v)	const
	{
		_tagVector3	v1;
		v1.x = x / v.x;
		v1.y = y / v.y;
		v1.z = z / v.z;
		return v1;
	}

	_tagVector3 operator /(float fValue)	const
	{
		_tagVector3	v1;
		v1.x = x / fValue;
		v1.y = y / fValue;
		v1.z = z / fValue;
		return v1;
	}

	// 함수 뒤에 const를 붙여주게 되면 이 함수에서는 멤버변수의
	// 값을 변경할 수 없다.
	_tagVector3 operator /(int iValue)	const
	{
		_tagVector3	v1;
		v1.x = x / (float)iValue;
		v1.y = y / (float)iValue;
		v1.z = z / (float)iValue;
		return v1;
	}

	void operator /=(const _tagVector3& v)
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;
	}

	void operator /=(float fValue)
	{
		x /= fValue;
		y /= fValue;
		z /= fValue;
	}

	void operator /=(int iValue)
	{
		x /= (float)iValue;
		y /= (float)iValue;
		z /= (float)iValue;
	}

	float Length()	const
	{
		return sqrtf(x * x + y * y + z * z);
	}

	_tagVector3 Normalize()	const
	{
		_tagVector3	v;
		float	fLength = Length();
		v.x = x / fLength;
		v.y = y / fLength;
		v.z = z / fLength;
		return v;
	}

	float Dot(const _tagVector3& v)	const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	_tagVector3 Cross(const _tagVector3& v)
	{
		return _tagVector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
	}
}VECTOR3, *PVECTOR3;

typedef struct _tagVector4 :
	public XMFLOAT4
{
	_tagVector4()
	{
		x = 0.f;
		y = 0.f;
		z = 0.f;
		w = 0.f;
	}

	_tagVector4(float _x, float _y, float _z, float _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	_tagVector4 operator +(const _tagVector4& v)	const
	{
		_tagVector4	v1;
		v1.x = x + v.x;
		v1.y = y + v.y;
		v1.z = z + v.z;
		v1.w = w + v.w;
		return v1;
	}

	_tagVector4 operator +(float fValue)	const
	{
		_tagVector4	v1;
		v1.x = x + fValue;
		v1.y = y + fValue;
		v1.z = z + fValue;
		v1.w = w + fValue;
		return v1;
	}

	// 함수 뒤에 const를 붙여주게 되면 이 함수에서는 멤버변수의
	// 값을 변경할 수 없다.
	_tagVector4 operator +(int iValue)	const
	{
		_tagVector4	v1;
		v1.x = x + (float)iValue;
		v1.y = y + (float)iValue;
		v1.z = z + (float)iValue;
		v1.w = w + (float)iValue;
		return v1;
	}

	void operator +=(const _tagVector4& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
	}

	void operator +=(float fValue)
	{
		x += fValue;
		y += fValue;
		z += fValue;
		w += fValue;
	}

	void operator +=(int iValue)
	{
		x += (float)iValue;
		y += (float)iValue;
		z += (float)iValue;
		w += (float)iValue;
	}

	_tagVector4 operator -(const _tagVector4& v)	const
	{
		_tagVector4	v1;
		v1.x = x - v.x;
		v1.y = y - v.y;
		v1.z = z - v.z;
		v1.w = w - v.w;
		return v1;
	}

	_tagVector4 operator -(float fValue)	const
	{
		_tagVector4	v1;
		v1.x = x - fValue;
		v1.y = y - fValue;
		v1.z = z - fValue;
		v1.w = w - fValue;
		return v1;
	}

	// 함수 뒤에 const를 붙여주게 되면 이 함수에서는 멤버변수의
	// 값을 변경할 수 없다.
	_tagVector4 operator -(int iValue)	const
	{
		_tagVector4	v1;
		v1.x = x - (float)iValue;
		v1.y = y - (float)iValue;
		v1.z = z - (float)iValue;
		v1.w = w - (float)iValue;
		return v1;
	}

	void operator -=(const _tagVector4& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
	}

	void operator -=(float fValue)
	{
		x -= fValue;
		y -= fValue;
		z -= fValue;
		w -= fValue;
	}

	void operator -=(int iValue)
	{
		x -= (float)iValue;
		y -= (float)iValue;
		z -= (float)iValue;
		w -= (float)iValue;
	}

	_tagVector4 operator *(const _tagVector4& v)	const
	{
		_tagVector4	v1;
		v1.x = x * v.x;
		v1.y = y * v.y;
		v1.z = z * v.z;
		v1.w = w * v.w;
		return v1;
	}

	_tagVector4 operator *(float fValue)	const
	{
		_tagVector4	v1;
		v1.x = x * fValue;
		v1.y = y * fValue;
		v1.z = z * fValue;
		v1.w = w * fValue;
		return v1;
	}

	// 함수 뒤에 const를 붙여주게 되면 이 함수에서는 멤버변수의
	// 값을 변경할 수 없다.
	_tagVector4 operator *(int iValue)	const
	{
		_tagVector4	v1;
		v1.x = x * (float)iValue;
		v1.y = y * (float)iValue;
		v1.z = z * (float)iValue;
		v1.w = w * (float)iValue;
		return v1;
	}

	void operator *=(const _tagVector4& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		w *= v.w;
	}

	void operator *=(float fValue)
	{
		x *= fValue;
		y *= fValue;
		z *= fValue;
		w *= fValue;
	}

	void operator *=(int iValue)
	{
		x *= (float)iValue;
		y *= (float)iValue;
		z *= (float)iValue;
		w *= (float)iValue;
	}

	_tagVector4 operator /(const _tagVector4& v)	const
	{
		_tagVector4	v1;
		v1.x = x / v.x;
		v1.y = y / v.y;
		v1.z = z / v.z;
		v1.w = w / v.w;
		return v1;
	}

	_tagVector4 operator /(float fValue)	const
	{
		_tagVector4	v1;
		v1.x = x / fValue;
		v1.y = y / fValue;
		v1.z = z / fValue;
		v1.w = w / fValue;
		return v1;
	}

	// 함수 뒤에 const를 붙여주게 되면 이 함수에서는 멤버변수의
	// 값을 변경할 수 없다.
	_tagVector4 operator /(int iValue)	const
	{
		_tagVector4	v1;
		v1.x = x / (float)iValue;
		v1.y = y / (float)iValue;
		v1.z = z / (float)iValue;
		v1.w = w / (float)iValue;
		return v1;
	}

	void operator /=(const _tagVector4& v)
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;
		w /= v.w;
	}

	void operator /=(float fValue)
	{
		x /= fValue;
		y /= fValue;
		z /= fValue;
		w /= fValue;
	}

	void operator /=(int iValue)
	{
		x /= (float)iValue;
		y /= (float)iValue;
		z /= (float)iValue;
		w /= iValue;
	}

	float Length()	const
	{
		return sqrtf(x * x + y * y + z * z);
	}

	_tagVector4 Normalize()	const
	{
		_tagVector4	v;
		float	fLength = Length();
		v.x = x / fLength;
		v.y = y / fLength;
		v.z = z / fLength;
		v.w = w / fLength;
		return v;
	}

	float Dot(const _tagVector4& v)	const
	{
		return x * v.x + y * v.y + z * v.z + w * v.w;
	}
}VECTOR4, *PVECTOR4;

typedef VECTOR2		Vec2;
typedef VECTOR2*	PVec2;
typedef VECTOR3		Vec3;
typedef VECTOR3*	PVec3;
typedef VECTOR4		Vec4;
typedef VECTOR4*	PVec4;
typedef XMMATRIX	Matrix;

// Color Vertex
typedef struct _tagColorVertex
{
	Vec3		vPos;
	Vec4		vColor;
}COLORVERTEX, *PCOLORVERTEX;


