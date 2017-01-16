
#pragma once

#define	SAFE_DELETE(p)	if(p)	{ delete p; p = NULL; }
#define	SAFE_RELEASE(p)	if(p)	{p->Release(); p = NULL;}


#define	DX11_GET_SINGLE(Type)	DX11::Type::GetInst()
#define	DX11_DESTROY_SINGLE(Type)	DX11::Type::DestroyInst()