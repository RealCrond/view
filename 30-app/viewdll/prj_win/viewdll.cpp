// viewdll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "viewdll.h"

VIEWDLLCALLBACK g_spCB = NULL;

bool DLL_RegisterCallBackFunc(VIEWDLLCALLBACK CallBackFunc)
{
	g_spCB = CallBackFunc;
	return TRUE;
}

void DLL_GetVersion(char* achVersion)
{
	strcpy_s(achVersion, 6,"1.0.0");
}



