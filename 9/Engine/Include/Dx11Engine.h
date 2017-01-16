
#pragma once

#include "Dx11Types.h"

#define	CRTDBG_MAP_ALLOC
#define	new	new(_CLIENT_BLOCK, __FILE__, __LINE__)

#define	DX11_BEGIN	namespace DX11 {
#define	DX11_END	}
#define	DX11_USING	using namespace DX11;

#ifdef DX11_IMPORT
#define	DX11_DLL	__declspec(dllimport)
#else
#define	DX11_DLL	__declspec(dllexport)
#endif // DX11_IMPORT

// File Path Key
#define	ROOT_PATH		"RootPath"
#define	SHADER_PATH		"ShaderPath"

// Shader Key
#define	DEFAULT_SHADER	"DefaultShader"


// Default Resource Key
#define	TRIANGLE_MESH	"TriangleMesh"


template <typename T>
void Safe_Delete_Map(T& p)
{
	T::iterator	iter = p.begin();

	while (iter != p.end())
	{
		SAFE_DELETE(iter->second);
		++iter;
	}

	p.clear();
}

template <typename T>
void Safe_Release_Map(T& p)
{
	T::iterator	iter = p.begin();

	while (iter != p.end())
	{
		SAFE_RELEASE(iter->second);
		++iter;
	}

	p.clear();
}


template <typename T>
void Safe_Delete_VecList(T& p)
{
	T::iterator	iter = p.begin();

	while (iter != p.end())
	{
		SAFE_DELETE((*iter));
		++iter;
	}

	p.clear();
}

template <typename T>
void Safe_Release_VecList(T& p)
{
	T::iterator	iter = p.begin();

	while (iter != p.end())
	{
		SAFE_RELEASE((*iter));
		++iter;
	}

	p.clear();
}

