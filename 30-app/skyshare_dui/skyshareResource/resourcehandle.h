// 资源导出类
#pragma once
#include "resource.h"
#include <windows.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <assert.h>

#ifdef SKYSHARERESOURCE_EXPORTS
	#define SKYSHARE_RESOURCE_API __declspec(dllexport)
#else
	#define SKYSHARE_RESOURCE_API __declspec(dllimport)
#endif

class SKYSHARE_RESOURCE_API CResourceHandle
{
public:
	CResourceHandle(void)
	{
		//#ifdef _DEBUG
		m_hInstance = ::LoadLibraryEx(_T("skyshareResource.dll"), NULL, DONT_RESOLVE_DLL_REFERENCES);
		//#else
		//		m_hInstance = ::LoadLibraryEx( _T("pcmtresource.dll"), NULL, DONT_RESOLVE_DLL_REFERENCES);
		//#endif
		assert(m_hInstance);
	}
	virtual ~CResourceHandle()
	{
		::FreeLibrary(m_hInstance);
		m_hInstance = NULL;
	}
	HINSTANCE GetHandle() const { return m_hInstance; }
private:
	HINSTANCE m_hInstance;
};