// skyshare.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "skyshare.h"
#include "360SafeWnd.h"
#include "baseWnd.h"

#ifdef _DEBUG
	#pragma comment(lib,"DuiLib_d.lib")
#else
	#pragma comment(lib,"DuiLib.lib")
#endif


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{

	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skin"));
	CPaintManagerUI::SetResourceZip(_T("360SafeRes.zip"));

	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr)) return 0;

	C360SafeFrameWnd* pFrame = new C360SafeFrameWnd();
	if (pFrame == NULL) return 0;
	pFrame->Create(NULL, _T("360安全卫士"), UI_WNDSTYLE_FRAME, 0L, 0, 0, 800, 572);
	pFrame->CenterWindow();
	::ShowWindow(*pFrame, SW_SHOW);

	CPaintManagerUI::MessageLoop();

	::CoUninitialize();
	return 0;
}
