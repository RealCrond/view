

#include "mainwnd.h"
#include "resource.h"
#include "tipwnd.h"

CMainWnd::CMainWnd()
{
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
}

CMainWnd::~CMainWnd()
{
	
}

void CMainWnd::Init() {

	m_pMinBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("BtnMin")));
	m_pSettingBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("BtnSetting")));
	m_pCloseBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("BtnClose")));
	m_pEdit = static_cast<CEditUI*>(m_pm.FindControl(_T("domain")));
	m_pWebMtcPage = static_cast<CWebBrowserUI*>(m_pm.FindControl(_T("WebMainPage")));
}


void CMainWnd::Notify(TNotifyUI& msg)
{
	if ( msg.sType == _T("click") ) {
		if ( msg.pSender->GetName() == _T("go") ) {
			m_pWebMtcPage->NavigateUrl(m_pEdit->GetText());
		}
		else if (msg.pSender->GetName() == _T("BtnSetting"))
		{
			CTipWnd* pFrame = new CTipWnd();
			if (pFrame == NULL) return;
			pFrame->Create(this->GetHWND(), _T("Tips"), UI_WNDSTYLE_DIALOG, WS_EX_WINDOWEDGE);
			//pFrame->ShowWindow(true);
			pFrame->CenterWindow();
			pFrame->ShowModal();
		}
		else if ( msg.pSender->GetName() == _T("BtnClose") )
		{
			Close();
			::PostQuitMessage(0);
		}
		else if ( msg.pSender->GetName() == _T("BtnMin") )
		{
			SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
			return;
		}

	}
}

LRESULT CMainWnd::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	LONG styleValue = ::GetWindowLong(*this, GWL_STYLE);
	styleValue &= ~WS_CAPTION;	//取消标题框
	styleValue &= ~WS_SIZEBOX;	//取消自动调整边框的风格,可以放置贴边自动最大化
	::SetWindowLong(*this, GWL_STYLE, styleValue | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);

	m_pm.Init(m_hWnd);
	CDialogBuilder builder;
	CControlUI* pRoot = builder.Create(IDR_XML_MAINFRAME_WND, _T("xml"), NULL, &m_pm);
	ASSERT(pRoot && "Failed to parse XML");
	m_pm.AttachDialog(pRoot);
	m_pm.AddNotifier(this);

	SetIcon(IDI_ICON_LOGO);

	Init();

	return 0;
}

LRESULT CMainWnd::OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
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

LRESULT CMainWnd::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
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
	default:
		bHandled = FALSE;
	}
	if (bHandled) return lRes;
	if (m_pm.MessageHandler(uMsg, wParam, lParam, lRes)) return lRes;
	return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
}