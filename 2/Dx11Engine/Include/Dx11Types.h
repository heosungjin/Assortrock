#pragma once

#include <Windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <list>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

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

