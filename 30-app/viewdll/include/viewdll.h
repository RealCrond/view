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
* @brief   ע��ص�����
*
* @param    [in]	CallBackFunc       �ص�����ָ��
* @return   bool    false��ע��ʧ��  true��ע��ɹ�
*
* @note 
*****************************************/
extern "C" VIEWDLL_API bool DLL_RegisterCallBackFunc(VIEWDLLCALLBACK CallBackFunc);

/****************************************
* DLL_GetVersion
*
* @brief   ��ȡ�汾��
*
* @param    [in]	achVersion       �汾��
* @return   void		
*
* @note
*****************************************/
extern "C" VIEWDLL_API void DLL_GetVersion(char* achVersion);