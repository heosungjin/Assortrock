#include "Dx11Object.h"

DX11_USING

CDx11Object::CDx11Object()	:
	m_iRefCount(1)
{
}

CDx11Object::~CDx11Object()
{
}

void CDx11Object::SetTag(const string & strTag)
{
	m_strTag = strTag;
}

int CDx11Object::AddRef()
{
	++m_iRefCount;

	return m_iRefCount;
}

int CDx11Object::Release()
{
	--m_iRefCount;

	if (m_iRefCount == 0)
	{
		delete	this;
		return 0;
	}

	return m_iRefCount;
}
