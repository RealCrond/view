#pragma once

#ifdef VIEWDLL_EXPORTS
#define VIEWDLL_API __declspec(dllexport)
#else
#define VIEWDLL_API __declspec(dllimport)
#endif // VIEWDLL_EXPORTS

typedef void(__stdcall *VIEWDLLCALLBACK)(UINT nEventID, WPARAM wParam, LPARAM lParam);

/****************************************
* DLL_RegisterCallBackFunc
*
* @brief   注册回调函数
*
* @param    [in]	CallBackFunc       回调函数指针
* @return   bool    false：注册失败  true：注册成功
*
* @note 
*****************************************/
extern "C" VIEWDLL_API bool DLL_RegisterCallBackFunc(VIEWDLLCALLBACK CallBackFunc);

/****************************************
* DLL_GetVersion
*
* @brief   获取版本号
*
* @param    [in]	achVersion       版本号
* @return   void		
*
* @note
*****************************************/
extern "C" VIEWDLL_API void DLL_GetVersion(char* achVersion);