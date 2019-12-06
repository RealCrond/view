

#include <iostream>
#include <Windows.h>
#include "mainwnd.h"
#include "resourcehandle.h"
//#define WIN32_LEAN_AND_MEAN    
//#define _CRT_SECURE_NO_DEPRECATE

//#include <windows.h>
//#include <objbase.h>

CResourceHandle s_ResHandle;
#define RESOURCE_HANDLE s_ResHandle.GetHandle()

// 程序入口及Duilib初始化部分
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	//Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	//ULONG_PTR           gdiplusToken;
	//// 初始化函数中
	////初始化GDI+.
	//GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	CPaintManagerUI::SetInstance(hInstance);
	CDuiString strPath = CPaintManagerUI::GetInstancePath();
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());
	CPaintManagerUI::SetResourceDll(RESOURCE_HANDLE);

	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr)) return 0;

	CMainWnd* pFrame = new CMainWnd();
	if (pFrame == NULL) return 0;
	pFrame->Create(NULL, _T("测试"), UI_WNDSTYLE_DIALOG, WS_EX_WINDOWEDGE);
	pFrame->ShowWindow(true);
	pFrame->CenterWindow();


	CPaintManagerUI::MessageLoop();
	CPaintManagerUI::Term();

	::CoUninitialize();

	
	return 0;
}