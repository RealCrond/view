#pragma once

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
note:
params:
*****************************************/
extern "C" VIEWDLL_API void DLL_GetVersion(char* achVersion);