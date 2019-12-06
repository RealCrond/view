#pragma once

#include "UIlib.h"
using namespace DuiLib;

class CTipWnd : public CWindowWnd, public INotifyUI
{
public:
	CTipWnd();
	~CTipWnd();

	void Init();


	virtual void Notify(TNotifyUI& msg);

	virtual LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);


protected:
	virtual LPCTSTR GetWindowClassName() const { return _T("MainWnd"); };

private:
	CPaintManagerUI m_pm;

	CButtonUI*		m_pCloseBtn;
	//CGifAnimUI*		m_pGifCtrl;
};