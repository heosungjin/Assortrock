
#pragma once

#include "Dx11Types.h"

#define	DX11_BEGIN	namespace DX11 {
#define	DX11_END	}
#define	DX11_USING	using namespace DX11;

#ifdef DX11_IMPORT
#define	DX11_DLL	__declspec(dllimport)
#else
#define	DX11_DLL	__declspec(dllexport)
#endif // DX11_IMPORT

