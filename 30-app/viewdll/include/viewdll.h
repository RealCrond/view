#pragma once

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
note:
params:
*****************************************/
extern "C" VIEWDLL_API void DLL_GetVersion(char* achVersion);