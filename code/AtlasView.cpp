// AtlasView.cpp : implementation of the CAtlasView class
//

#include "stdafx.h"
#include "Atlas.h"

#include "DataTransDlg.h"
#include "LayerCtrlDlg.h"
#include "AtlasDoc.h"
#include "AtlasView.h"

#include <math.h>
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAtlasView

IMPLEMENT_DYNCREATE(CAtlasView, CView)

BEGIN_MESSAGE_MAP(CAtlasView, CView)
	ON_WM_CONTEXTMENU()
	//{{AFX_MSG_MAP(CAtlasView)
	ON_COMMAND(ID_MENU_DATATRANS, OnDataTransDlg)
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEWHEEL()
	ON_COMMAND(ID_MENU_FULLMAP, OnMenuFullmap)
	ON_COMMAND(ID_MENU_ZOOMOUT, OnMenuZoomout)
	ON_COMMAND(ID_MENU_ZOOMIN, OnMenuZoomin)
	ON_COMMAND(ID_MENU_PAN, OnMenuPan)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_MENU_ZOOMIN_BYRECT, OnMenuZoominByrect)
	ON_WM_LBUTTONUP()
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_MENU_DISTANCE, OnMenuDistance)
	ON_COMMAND(ID_MENU_AREA, OnMenuArea)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_MENU_LAYERMANAGE, OnMenuLayermanage)
	ON_COMMAND(ID_MENU_ANNO, OnMenuAnno)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAtlasView construction/destruction

CAtlasView::CAtlasView()
{
	// TODO: add construction code here
	m_bIsLoadMap = FALSE;
	m_bFirstPoint=TRUE;
	m_fScaleCtrl=1.0;
	m_lCurMess=0;
	pts.RemoveAll();
}

CAtlasView::~CAtlasView()
{
}

BOOL CAtlasView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAtlasView drawing

void CAtlasView::OnDraw(CDC* pDC)
{
	CAtlasDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	
	if (m_bIsLoadMap!=FALSE)
	{
// 		if(pDoc->pMap->GetLayerNum()!= 0)
// 		{
// 			for(int i = 0; i < pDoc->pMap->GetLayerNum(); i++)
// 			{
// 				pDoc->pMap->GetLayer(i)->Draw(pDC,pDoc,i);
// 			}
// 		}	
		pDoc->pMap->DrawMap(pDC,pDoc);
	}		
}

/////////////////////////////////////////////////////////////////////////////
// CAtlasView printing

BOOL CAtlasView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAtlasView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAtlasView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAtlasView diagnostics

#ifdef _DEBUG
void CAtlasView::AssertValid() const
{
	CView::AssertValid();
}

void CAtlasView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAtlasDoc* CAtlasView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAtlasDoc)));
	return (CAtlasDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAtlasView message handlers

void CAtlasView::OnDataTransDlg() 
{
	// TODO: Add your command handler code here
	DataTransDlg m_DataTranDlg;
	m_DataTranDlg.DoModal();
}

void CAtlasView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_bIsLoadMap)
	{
		//������Ļ���η�Χ
		RECT scrRect;
		//�õ���Ļ���ڿͻ�����Χ��С
		GetClientRect(&scrRect);
		//����ӳ��ģʽ
		pDC->SetMapMode(MM_ISOTROPIC);
		
		//�����ͼ��Χ�Ǻ����
		if( m_rCurWinScope.top < m_rCurWinScope.bottom )
		{
			//���㵱ǰ��ͼ��Χ����Ļ�任��ˮƽ�ʹ�ֱ����ϵ��
			float R0,R1;
			R0 = (float)(m_rCurWinScope.right - m_rCurWinScope.left)/(float)labs(scrRect.right-scrRect.left-4);
			R1 = (float)(m_rCurWinScope.bottom - m_rCurWinScope.top)/(float)labs(scrRect.bottom-scrRect.top-4);
			
			//�����ӿ�ԭ��
			pDC->SetViewportOrg((scrRect.left+scrRect.right)/2,(scrRect.bottom+scrRect.top)/2); 
			//���ô���ԭ��
			pDC->SetWindowOrg((m_rCurWinScope.left+m_rCurWinScope.right)/2,(m_rCurWinScope.bottom+m_rCurWinScope.top)/2);
			
			//���㵱ǰ��ͼ��Χ�ĳ��ȺͿ��
			long dx = labs(m_rCurWinScope.right-m_rCurWinScope.left);
			long dy = labs(m_rCurWinScope.top-m_rCurWinScope.bottom);
			
			//���ô��ڷ�Χ
			pDC->SetWindowExt(dx,dy);
			//�����ӿڷ�Χ
			pDC->SetViewportExt( (scrRect.right-scrRect.left-4),(scrRect.top-scrRect.bottom+4));//ʸ��	
		}
	}
	else
	{
		CView::OnPrepareDC(pDC, pInfo);
	}
}

BOOL CAtlasView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	COLORREF BACKCOLOR = RGB(120,120,120);
	CBrush brush(BACKCOLOR);
	CBrush *pOldBrush=pDC->SelectObject(&brush);
	
	CRect rc;
	pDC->GetClipBox(&rc);
	pDC->PatBlt(rc.left,rc.top,rc.Width(),rc.Height(),PATCOPY);
	pDC->SelectObject(pOldBrush); 
	return FALSE;			
	//return CView::OnEraseBkgnd(pDC);
}

BOOL CAtlasView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bIsLoadMap)
	{
		if(zDelta==120)
			ScopeChange(1.25,m_rCurWinScope.CenterPoint());
		else	if(zDelta==-120)
			ScopeChange(0.8,m_rCurWinScope.CenterPoint());
	}
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}

void CAtlasView::ScopeChange(float scale, CPoint pt)
{
	m_fScaleCtrl = (float)m_rtMapRange.Width()/(float)m_rCurWinScope.Width() *scale ;
	
	if( m_fScaleCtrl<=10000 && m_fScaleCtrl>=0.0001 )
	{
		CRect result;
		
		result.left=pt.x-(float)m_rtMapRange.Width()/m_fScaleCtrl/2;
		result.right=pt.x+(float)m_rtMapRange.Width()/m_fScaleCtrl/2;
		result.bottom=pt.y+(float)m_rtMapRange.Height()/m_fScaleCtrl/2;
		result.top=pt.y-(float)m_rtMapRange.Height()/m_fScaleCtrl/2;
		
		m_rCurWinScope=result;
	}
	else
	{
		AfxMessageBox("�������ű�����Χ�ڣ�");
		OnMenuFullmap();
		m_fScaleCtrl=1;
		return;
	}
	Invalidate();
}

void CAtlasView::OnMenuFullmap() 
{
	// TODO: Add your command handler code here
	m_rCurWinScope=m_rtMapRange;
	m_lCurMess=ID_MENU_FULLMAP;
	Invalidate();
}

void CAtlasView::OnMenuZoomout() 
{
	// TODO: Add your command handler code here
	m_lCurMess=ID_MENU_ZOOMOUT;
}

void CAtlasView::OnMenuZoomin() 
{
	// TODO: Add your command handler code here
	m_lCurMess=ID_MENU_ZOOMIN;
}

void CAtlasView::OnMenuPan() 
{
	// TODO: Add your command handler code here
	m_lCurMess=ID_MENU_PAN;
}

void CAtlasView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CAtlasDoc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);

	if (m_bIsLoadMap)
	{
		CClientDC dc(this);
		dc.SetROP2(R2_NOTXORPEN);
		OnPrepareDC(&dc);
		
		
		CPoint pt=point;
		dc.DPtoLP(&pt);

		if(m_lCurMess==ID_MENU_AREA)
		{
			SetCapture();     //���Ժ�����������Ϣ���͵�������
			CRect rect;
			GetClientRect(&rect);  //�õ���ǰ�ͻ����Ĵ�С��λ�ã���������rect�ṹ����
			ClientToScreen(&rect); //�����������������ӵ�ǰ����ת������Ļ����
			//ClipCursor(&rect);  //�޶���귶Χ,��겻�ܵ�����޶�����֮��
			
			if(m_bFirstPoint)
			{
				Invalidate();
				m_ptStart=pt;
				m_ptOld=pt;
				pts.RemoveAll();
				pts.Add(pt);
				m_bFirstPoint=false;
			}
			else
			{
				dc.SetROP2(R2_COPYPEN);
				pts.Add(pt);
				dc.MoveTo(pts[0]);
				for(int i=1;i<pts.GetSize();i++)
					dc.LineTo(pts[i]);
			}
		}
		
		
		//�������
		if(m_lCurMess==ID_MENU_DISTANCE)
		{
			SetCapture();     //���Ժ�����������Ϣ���͵�������
			CRect rect;
			GetClientRect(&rect);  //�õ���ǰ�ͻ����Ĵ�С��λ�ã���������rect�ṹ����
			ClientToScreen(&rect); //�����������������ӵ�ǰ����ת������Ļ����
			ClipCursor(&rect);  //�޶���귶Χ,��겻�ܵ�����޶�����֮��
			
			if(m_bFirstPoint)
			{
				Invalidate();
				m_ptStart=pt;
				m_ptOld=pt;
				pts.RemoveAll();
				pts.Add(pt);
				m_bFirstPoint=false;
			}
			else
			{
				dc.SetROP2(R2_COPYPEN);
				pts.Add(pt);
				dc.MoveTo(pts[0]);
				for(int i=1;i<pts.GetSize();i++)
					dc.LineTo(pts[i]);
			}
		}

		//�Ŵ�
		if(m_lCurMess==ID_MENU_ZOOMIN)
		{
			ScopeChange(2.0,pt);			
		}
		
		//��С
		if(m_lCurMess==ID_MENU_ZOOMOUT)
		{
			ScopeChange(0.5,pt);
		}
		
		//����
		if(m_lCurMess==ID_MENU_PAN)
		{
			m_rtZoom.left=pt.x;
			m_rtZoom.top=pt.y;
			
			//�������
			::SetCapture(this->GetSafeHwnd( ));
		}

		//����
		if(m_lCurMess==ID_MENU_ZOOMIN_BYRECT)
		{
			m_rtZoom.right=m_rtZoom.left=pt.x;
			m_rtZoom.bottom=m_rtZoom.top=pt.y;
			
			//�����������
			dc.Rectangle(m_rtZoom.left,m_rtZoom.top,m_rtZoom.right,m_rtZoom.bottom);
			//�������
			::SetCapture(this->GetSafeHwnd( ));		
		}
	}
	CView::OnLButtonDown(nFlags, point);
}

void CAtlasView::OnMenuZoominByrect() 
{
	// TODO: Add your command handler code here
	m_lCurMess=ID_MENU_ZOOMIN_BYRECT;
}

void CAtlasView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bIsLoadMap)
	{
		CClientDC dc(this);
		dc.SetROP2(R2_NOTXORPEN);
		OnPrepareDC(&dc);
		
		CPoint pt=point;
		dc.DPtoLP(&pt);

		//ƽ��
		if(m_lCurMess==ID_MENU_PAN)
		{
			m_rtZoom.right=pt.x;
			m_rtZoom.bottom=pt.y;
			
			m_rCurWinScope.left-=m_rtZoom.Width();
			m_rCurWinScope.right-=m_rtZoom.Width();
			m_rCurWinScope.bottom-=m_rtZoom.Height();
			m_rCurWinScope.top-=m_rtZoom.Height();
			
			Invalidate();
			
			//�ͷ���겶��״̬
			::ReleaseCapture();		
		}

		//����
		if(m_lCurMess==ID_MENU_ZOOMIN_BYRECT)
		{		
			//���
			dc.Rectangle(m_rtZoom.left,m_rtZoom.top,m_rtZoom.right,m_rtZoom.bottom);
			
			//��¼������
			m_rtZoom.right = pt.x;
			m_rtZoom.bottom = pt.y;
			
			//���»���
			dc.Rectangle(m_rtZoom.left,m_rtZoom.top,m_rtZoom.right,m_rtZoom.bottom);
			
			m_rCurWinScope=m_rtZoom;
			if(m_rtZoom.left>m_rtZoom.right)
			{
				m_rCurWinScope.left=m_rtZoom.right;
				m_rCurWinScope.right=m_rtZoom.left;
			}
			if(m_rtZoom.bottom<m_rtZoom.top)
			{
				m_rCurWinScope.bottom=m_rtZoom.top;
				m_rCurWinScope.top=m_rtZoom.bottom;
			}			
			
			Invalidate();
			
			//�ͷ���겶��״̬
			::ReleaseCapture();
			
		}
	}
	CView::OnLButtonUp(nFlags, point);
}

BOOL CAtlasView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if ((m_bIsLoadMap) && nHitTest==HTCLIENT)
	{
		switch (m_lCurMess)
		{
		case ID_MENU_ZOOMIN_BYRECT:
			  {
				SetCursor(AfxGetApp()->LoadCursor(IDC_ZOOMIN_BYRECT));
				return TRUE;
			  }
		case ID_MENU_ZOOMOUT:
			{
				SetCursor(AfxGetApp()->LoadCursor(IDC_ZOOMOUT));
				return TRUE;
			}
		case ID_MENU_ZOOMIN:
			{
				SetCursor(AfxGetApp()->LoadCursor(IDC_ZOOMIN));
				return TRUE;
			}
		case ID_MENU_PAN:
			{
				SetCursor(AfxGetApp()->LoadCursor(IDC_PAN));
				return TRUE;
			}
		case ID_MENU_FULLMAP:
			{
				SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
				return TRUE;
			}
		}
	}
	return CView::OnSetCursor(pWnd, nHitTest, message);
}

void CAtlasView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bIsLoadMap)
	{
		
		CClientDC dc(this);
		dc.SetROP2(R2_NOTXORPEN);
		OnPrepareDC(&dc);
		
		CPoint pt=point;
		dc.DPtoLP(&pt);

		if(GetCapture()==this)
		{
			if(m_lCurMess == ID_MENU_ZOOMIN_BYRECT)
			{
				//�����ǰ�ľ���
				dc.Rectangle(m_rtZoom.left,m_rtZoom.top,m_rtZoom.right,m_rtZoom.bottom);
				
				m_rtZoom.right = pt.x;
				m_rtZoom.bottom = pt.y;
				
				//�����¾���
				dc.Rectangle(m_rtZoom.left,m_rtZoom.top,m_rtZoom.right,m_rtZoom.bottom);
			}

			//�������
			if(m_lCurMess==ID_MENU_AREA)
			{	
				dc.SetROP2(R2_COPYPEN);				
				dc.MoveTo(pts[0]);
				for(int i=1;i<pts.GetSize();i++)
				{	dc.LineTo(pts[i]);
				
				dc.SetROP2(R2_NOT); 
				dc.MoveTo(pts[i-1]);
				dc.LineTo(m_ptOld);
				
				dc.MoveTo(pts[i-1]);
				dc.LineTo(pt);
				m_ptOld=pt;	
				}
			}
			
			//�������
			if(m_lCurMess==ID_MENU_DISTANCE)
			{		
				dc.SetROP2(R2_COPYPEN);				
				dc.MoveTo(pts[0]);
				for(int i=1;i<pts.GetSize();i++)
				{	dc.LineTo(pts[i]);
				
				dc.SetROP2(R2_NOT); 
				dc.MoveTo(pts[i-1]);
				dc.LineTo(m_ptOld);
				
				dc.MoveTo(pts[i-1]);
				dc.LineTo(pt);
				m_ptOld=pt;	
				}}
		}
	}
	CView::OnMouseMove(nFlags, point);
}

void CAtlasView::OnMenuDistance() 
{
	// TODO: Add your command handler code here
	m_lCurMess=ID_MENU_DISTANCE;
}

void CAtlasView::OnMenuArea() 
{
	// TODO: Add your command handler code here
	m_lCurMess=ID_MENU_AREA;
}

void CAtlasView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//�������
	if(m_bIsLoadMap)
	{
		CClientDC dc(this);
		dc.SetROP2(R2_NOTXORPEN);
		OnPrepareDC(&dc);
		
		
		CPoint pt=point;
		dc.DPtoLP(&pt);
		if(m_lCurMess==ID_MENU_AREA)
		{
			ReleaseCapture();
			ClipCursor(NULL);
			
			
			dc.SetROP2(R2_COPYPEN);	
			pts.Add(pts[0]);
			dc.MoveTo(pts[0]);
			for(int i=1;i<pts.GetSize();i++)
				dc.LineTo(pts[i]);
			ShowArea();
			
			
			m_bFirstPoint=true;
		}
		
		//�������
		if(m_lCurMess==ID_MENU_DISTANCE)
		{
			ShowDistance(pt);
			ReleaseCapture();
			ClipCursor(NULL);
			
			pts.RemoveAll();
			m_bFirstPoint=true;
			
		}
	}
	CView::OnLButtonDblClk(nFlags, point);
}

void CAtlasView::ShowArea()
{
	float s=0;
	
	for(int i=0;i<pts.GetSize()-1;i++)
	{
		s+=(pts[i].y+pts[i+1].y)*(pts[i+1].x-pts[i].x);
	}
	s=(float)fabs(s)/2.0;
	
	CClientDC dc(this);
	dc.SetROP2(R2_NOTXORPEN);
	OnPrepareDC(&dc);
	
	CBrush *pBrush=new CBrush(RGB(4,245,120));
	CBrush *pOldBrush=dc.SelectObject(pBrush);
	
	int num=pts.GetSize();
	CPoint points[2000];
	for(int i=0;i<num;i++)
		{points[i]=pts[i];
	dc.Polygon(points,num);
	dc.SelectObject(pOldBrush);
	}
	char str[120];
	memset(str,0x00,sizeof(char)*120);
	sprintf(str,"��ѡ���������%.2f ƽ������",s*1e-6);
	AfxMessageBox(str);
// 	CStatusBar *pDistance=(CStatusBar*)AfxGetApp()->m_pMainWnd->GetDescendantWindow(ID_VIEW_STATUS_BAR);
// 	pDistance->SetPaneText(2,str);
	
	delete pBrush;
	pBrush=NULL;
	//	Invalidate();
	pts.RemoveAll();
}

extern float PPDistance(CPoint p1,CPoint p2);
void CAtlasView::ShowDistance(CPoint pt)
{
 	int num=pts.GetSize();
// 	float d=PPDistance(pts[num-1],pt);
 	float total=0.0;
	for(int i=1;i<num;i++)
		total+=PPDistance(pts[i-1],pts[i]);
	
	char str[120];
	memset(str,0x00,sizeof(char)*120);
	sprintf(str,"�ܾ��룺%.1f ����",total*1e-6);	
	AfxMessageBox(str);
// 	CStatusBar *pDistance=(CStatusBar*)AfxGetApp()->m_pMainWnd->GetDescendantWindow(ID_VIEW_STATUS_BAR);
// 	pDistance->SetPaneText(2,str);
}

void CAtlasView::OnContextMenu(CWnd*, CPoint point)
{

	// CG: This block was added by the Pop-up Menu component
	{
		if (point.x == -1 && point.y == -1){
			//keystroke invocation
			CRect rect;
			GetClientRect(rect);
			ClientToScreen(rect);

			point = rect.TopLeft();
			point.Offset(5, 5);
		}

		CMenu menu;
		VERIFY(menu.LoadMenu(CG_IDR_POPUP_MAIN_FRAME));

		CMenu* pPopup = menu.GetSubMenu(0);
		ASSERT(pPopup != NULL);
		CWnd* pWndPopupOwner = this;

		while (pWndPopupOwner->GetStyle() & WS_CHILD)
			pWndPopupOwner = pWndPopupOwner->GetParent();

		pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y,
			pWndPopupOwner);


	}
}

extern CLayerCtrlDlg *pLayerCtrlDlg;
void CAtlasView::OnMenuLayermanage() 
{
	// TODO: Add your command handler code here
	if(m_bIsLoadMap)
	{
		CLayerCtrlDlg dlg;
		pLayerCtrlDlg=&dlg;
		dlg.DoModal();
		pLayerCtrlDlg=NULL;
		//	Invalidate();
		
		//	b_Condition=!b_Condition;
		
		CAtlasDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if(NULL!=pDoc->pMap->m_EditableLayer)
			pLayer=pDoc->pMap->m_EditableLayer;
		/*m_lCurMess=ID_NO_OPERATION;*/
		Invalidate();
	}
	else
		AfxMessageBox("ͼ��������ڲ���ʹ�ã����ȴ򿪵�ͼ�����½���ͼ!");
}
	


//DEL void CAtlasView::OnAppAboutchm() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 
//DEL 	ShellExecute(NULL,"open","Mappo�����ļ�.chm",NULL,NULL,SW_SHOW);
//DEL }

void CAtlasView::OnMenuAnno() 
{
	// TODO: Add your command handler code here
	m_lCurMess=ID_MENU_ANNO;
	m_uSelectedTool=5;
	
	if(NULL!=pLayer)
	{
		if(pLayer->m_uLayerType==-1||pLayer->m_uLayerType==4)
			pLayer->Initiate(4,"ע�ǲ�");	
		else
			pLayer->Initiate(5,"����ͼ��");
		m_bFirstPoint=true;
	}
	
}
