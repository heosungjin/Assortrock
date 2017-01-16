
#include "Dx11Core.h"
#include "Client.h"

DX11_USING

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	if (!DX11_GET_SINGLE(CDx11Core)->Init(L"Dx11", L"Dx11",
		hInstance, IDI_ICON1, IDI_ICON1, RT_HD, true))
	{
		DX11_DESTROY_SINGLE(CDx11Core);
		return 0;
	}

	int	iRet = DX11_GET_SINGLE(CDx11Core)->Run();

	DX11_DESTROY_SINGLE(CDx11Core);

	return iRet;
}