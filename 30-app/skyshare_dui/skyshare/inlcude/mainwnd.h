#pragma once

#include "UIlib.h"

using namespace DuiLib;

#pragma comment(lib,"DuiLib.lib")
#pragma comment(lib,"skyshareResource.lib")

class CMainWnd : public CWindowWnd, public INotifyUI
{
public:
	CMainWnd();
	~CMainWnd();
	void Init();


	virtual void Notify(TNotifyUI& msg);

	virtual LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

protected:
	virtual LPCTSTR GetWindowClassName() const { return _T("MainWnd"); };

private:
	CPaintManagerUI m_pm;

	CButtonUI*		m_pMinBtn;
	CButtonUI*		m_pSettingBtn;
	CButtonUI*		m_pCloseBtn;
	CEditUI*			m_pEdit;
	CWebBrowserUI*	m_pWebMtcPage;

};
