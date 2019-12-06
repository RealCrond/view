
#include "tipwnd.h"
#include "resource.h"


enum EM_TIMEOUT_EVENT {
	em_Close = 0,
	em_Connect,
};

#define TIMEOUT_CLOSE 8000   //定时自动关闭窗口


CTipWnd::CTipWnd()
{

}

CTipWnd::~CTipWnd()
{

}



void CTipWnd::Init()
{
	m_pCloseBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("BtnClose")));
	//m_pGifCtrl = static_cast<CGifAnimUI*>(m_pm.FindControl(_T("gifCtrl")));
	//m_pGifCtrl->SetBkColor(0xFFFF0000);
	SetTimer(this->GetHWND(), em_Close, TIMEOUT_CLOSE, NULL);
}


void CTipWnd::Notify(TNotifyUI& msg)
{
	if ( msg.sType == _T("click") )
	{
		if (msg.pSender->GetName() == _T("BtnClose"))
		{
			Close();
		}
	}
}

LRESULT CTipWnd::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	LONG styleValue = ::GetWindowLong(*this, GWL_STYLE);
	styleValue &= ~WS_CAPTION;	//取消标题框
	styleValue &= ~WS_SIZEBOX;	//取消自动调整边框的风格,可以放置贴边自动最大化
	::SetWindowLong(*this, GWL_STYLE, styleValue | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);

	m_pm.Init(m_hWnd);
	CDialogBuilder builder;
	CControlUI* pRoot = builder.Create(IDR_XML_TIPS_WND, _T("xml"), NULL, &m_pm);
	ASSERT(pRoot && "Failed to parse XML");
	m_pm.AttachDialog(pRoot);
	m_pm.AddNotifier(this);

	Init();
	return 0;
}
LRESULT CTipWnd::OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	POINT pt; pt.x = GET_X_LPARAM(lParam); pt.y = GET_Y_LPARAM(lParam);
	::ScreenToClient(*this, &pt);

	RECT rcClient;
	::GetClientRect(*this, &rcClient);

	//if( !::IsZoomed(*this) ) {
	//	RECT rcSizeBox = m_pm.GetSizeBox();
	//	if( pt.y < rcClient.top + rcSizeBox.top ) {
	//		if( pt.x < rcClient.left + rcSizeBox.left ) return HTTOPLEFT;
	//		if( pt.x > rcClient.right - rcSizeBox.right ) return HTTOPRIGHT;
	//		return HTTOP;
	//	}
	//	else if( pt.y > rcClient.bottom - rcSizeBox.bottom ) {
	//		if( pt.x < rcClient.left + rcSizeBox.left ) return HTBOTTOMLEFT;
	//		if( pt.x > rcClient.right - rcSizeBox.right ) return HTBOTTOMRIGHT;
	//		return HTBOTTOM;
	//	}
	//	if( pt.x < rcClient.left + rcSizeBox.left ) return HTLEFT;
	//	if( pt.x > rcClient.right - rcSizeBox.right ) return HTRIGHT;
	//}

	RECT rcCaption = m_pm.GetCaptionRect();
	if (pt.x >= rcClient.left + rcCaption.left && pt.x < rcClient.right - rcCaption.right \
		&& pt.y >= rcCaption.top && pt.y < rcCaption.bottom) {
		CControlUI* pControl = static_cast<CControlUI*>(m_pm.FindControl(pt));
		if (pControl && _tcscmp(pControl->GetClass(), DUI_CTR_BUTTON) != 0 &&
			_tcscmp(pControl->GetClass(), DUI_CTR_OPTION) != 0 &&
			_tcscmp(pControl->GetClass(), DUI_CTR_TEXT) != 0)
			return HTCAPTION;
	}

	return HTCLIENT;
}

LRESULT CTipWnd::OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if (wParam == em_Close)
	{
		Close();
	}
	return 0;
}

LRESULT CTipWnd::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT lRes = 0;
	BOOL bHandled = TRUE;
	switch (uMsg) {
	case WM_CREATE:        lRes = OnCreate(uMsg, wParam, lParam, bHandled); break;
		//case WM_CLOSE:         lRes = OnClose(uMsg, wParam, lParam, bHandled); break;
		//case WM_DESTROY:       lRes = OnDestroy(uMsg, wParam, lParam, bHandled); break;
		//case WM_NCACTIVATE:    lRes = OnNcActivate(uMsg, wParam, lParam, bHandled); break;
		//case WM_NCCALCSIZE:    lRes = OnNcCalcSize(uMsg, wParam, lParam, bHandled); break;
		//case WM_NCPAINT:       lRes = OnNcPaint(uMsg, wParam, lParam, bHandled); break;
	case WM_NCHITTEST:     lRes = OnNcHitTest(uMsg, wParam, lParam, bHandled); break;
		//case WM_SIZE:          lRes = OnSize(uMsg, wParam, lParam, bHandled); break;
		//case WM_GETMINMAXINFO: lRes = OnGetMinMaxInfo(uMsg, wParam, lParam, bHandled); break;
		//case WM_SYSCOMMAND:    lRes = OnSysCommand(uMsg, wParam, lParam, bHandled); break;
	case WM_TIMER:		lRes = OnTimer(uMsg, wParam, lParam, bHandled); break;
	default:
		bHandled = FALSE;
	}
	if (bHandled) return lRes;
	if (m_pm.MessageHandler(uMsg, wParam, lParam, lRes)) return lRes;
	return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
}