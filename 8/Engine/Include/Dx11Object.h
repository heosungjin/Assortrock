#pragma once

#include "Dx11Engine.h"

DX11_BEGIN

class DX11_DLL CDx11Object
{
protected:
	CDx11Object();
	virtual ~CDx11Object() = 0;

private:
	string	m_strTag;
	int		m_iRefCount;

public:
	string GetTag();

public:
	void SetTag(const string& strTag);
	int AddRef();
	int Release();
};

DX11_END