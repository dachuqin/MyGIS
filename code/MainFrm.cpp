// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Atlas.h"

#include "MainFrm.h"
#include "Splash.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	if (!m_wndViewToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE |CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndViewToolBar.LoadToolBar(IDR_TOOLBAR_VIEW))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	/*if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);*/

	m_wndViewToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndViewToolBar);
	m_wndViewToolBar.SetWindowText(" ”¥∞π§æﬂ¿∏");
	/*CImageList il; 
    CBitmap bmp; */
	
   CBitmap bmp2;
   CBitmap bmp3;
   CBitmap bmp4;
   CBitmap bmp5;
   CBitmap bmp6;
	
	
	
	/*CBitmap bm[4];
	for(int i = IDB_BITMAP1; i < IDB_BITMAP1 + 4; i++)
	{
		
		il.Create(58, 23, ILC_COLORDDB|ILC_MASK, 0,4); 
		 bm[i-IDB_BITMAP1].LoadBitmap(i); 
		 il.Add(&bm[i-IDB_BITMAP1],  RGB(192,  192, 192)); 
		 m_wndViewToolBar.SendMessage(TB_SETIMAGELIST,  0,  (LPARAM)il.m_hImageList); 
		 il.Detach(); 
       bmp.Detach();
	   }*/

	il.Create(58, 23, ILC_COLORDDB|ILC_MASK, 0,4); 
	bmp.LoadBitmap(IDB_BITMAP1); 
	bmp2.LoadBitmap(IDB_BITMAP2);
	bmp3.LoadBitmap(IDB_BITMAP3);
	bmp4.LoadBitmap(IDB_BITMAP4);
    bmp5.LoadBitmap(IDB_BITMAP5);
	il.Add(&bmp,  RGB(192,  192, 192)); 
	il.Add(&bmp2,  RGB(192,  192, 192)); 
	il.Add(&bmp3,  RGB(192,  192, 192)); 
	il.Add(&bmp4,  RGB(192,  192, 192)); 
    il.Add(&bmp5,  RGB(192,  192, 192)); 
	
	m_wndViewToolBar.SendMessage(TB_SETIMAGELIST,  0,  (LPARAM)il.m_hImageList); 
	il.Detach(); 
      

	   

	   /*il.Create(58, 23, ILC_COLORDDB|ILC_MASK, 0,4); 
	   bmp2.LoadBitmap(IDB_BITMAP2); 
	   il.Add(&bmp2,  RGB(192,  192, 192)); 
	   m_wndViewToolBar.SendMessage(TB_SETIMAGELIST,  0,  (LPARAM)il.m_hImageList); 
	   il.Detach(); 
       bmp2.Detach();*/


  
	   
	 
	// CG: The following line was added by the Splash Screen component.
	CSplashWnd::ShowSplashScreen(this);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
 {
 	if( !CFrameWnd::PreCreateWindow(cs) )
 		return FALSE;
 	// TODO: Modify the Window class or styles here by modifying
 	//  the CREATESTRUCT cs
 
 	return TRUE;
 }

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


//DEL void CMainFrame::OnToolFullmap() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 
//DEL }


//DEL void CMainFrame::OnHide()
//DEL {
//DEL 	if(m_wndToolBar.IsWindowVisible())
//DEL         m_wndToolBar.ModifyStyle(WS_VISIBLE,0);
//DEL     SendMessage(WM_SIZE);
//DEL 
//DEL 
//DEL 
//DEL }

//DEL void CMainFrame::OnContextMenu(CWnd*, CPoint point)
//DEL {
//DEL 
//DEL 	// CG: This block was added by the Pop-up Menu component
//DEL 	{
//DEL 		if (point.x == -1 && point.y == -1)
//DEL 		{
//DEL 			//keystroke invocation
//DEL 			CRect rect;
//DEL 			GetClientRect(rect);
//DEL 			ClientToScreen(rect);
//DEL 
//DEL 			point = rect.TopLeft();
//DEL 			point.Offset(5, 5);
//DEL 		}
//DEL 
//DEL 
//DEL 		CMenu menu;
//DEL 		VERIFY(menu.LoadMenu(CG_IDR_POPUP_MAIN_FRAME));
//DEL 
//DEL 		CMenu* pPopup = menu.GetSubMenu(0);
//DEL 		ASSERT(pPopup != NULL);
//DEL 		CWnd* pWndPopupOwner = this;
//DEL 
//DEL 		while (pWndPopupOwner->GetStyle() & WS_CHILD)
//DEL 			pWndPopupOwner = pWndPopupOwner->GetParent();
//DEL 
//DEL 		pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y,
//DEL 			pWndPopupOwner);
//DEL 	}
//DEL }

//DEL void CMainFrame::OnAppAboutchm() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	ShellExecute(NULL,"open","Atlas Help.chm",NULL,NULL,SW_SHOW);
//DEL 	
//DEL }
