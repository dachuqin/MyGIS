// LayerCtrlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Atlas.h"
#include "LayerCtrlDlg.h"
#include "LayerAttri.h"
#include "GeoLayer.h"
#include "MainFrm.h"
#include "AtlasDoc.h"
#include "AtlasView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLayerCtrlDlg dialog


CLayerCtrlDlg::CLayerCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLayerCtrlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLayerCtrlDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLayerCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLayerCtrlDlg)
	DDX_Control(pDX, IDC_UP_Layer, m_UpButton);
	DDX_Control(pDX, IDC_DOWN_Layer, m_DownButton);
	DDX_Control(pDX, IDC_Layer_LIST, m_LayerList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLayerCtrlDlg, CDialog)
	//{{AFX_MSG_MAP(CLayerCtrlDlg)
	ON_BN_CLICKED(IDC_UP_Layer, OnUPLayer)
	ON_BN_CLICKED(IDC_LAYER_INFO, OnLayerInfo)
	ON_BN_CLICKED(IDC_ADD_LAYER, OnAddLayer)
	ON_BN_CLICKED(IDC_Edit, OnEdit)
	ON_BN_CLICKED(IDC_DOWN_Layer, OnDOWNLayer)
	ON_BN_CLICKED(IDC_DELETE_LAYER, OnDeleteLayer)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_LBN_SELCHANGE(IDC_Layer_LIST, OnSelchangeLayerLIST)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLayerCtrlDlg message handlers

void CLayerCtrlDlg::ChangeLayerOrder(int m, int n)   //更改图层顺序
{
	CString str1,str2;
	m_LayerList.GetText(m,str1);
	m_LayerList.GetText(n,str2);
	
	CAtlasDoc *pDoc=(CAtlasDoc *)( ((CMainFrame*)AfxGetMainWnd())->GetActiveDocument() );
	pDoc->pMap->ChangeLayerOrder(str1,str2);
	
	CAtlasView* pView = (CAtlasView *)(((CMainFrame*)AfxGetMainWnd())->GetActiveView());
	pView->Invalidate();

    
}

void CLayerCtrlDlg::OnOK() 
{
	// TODO: Add extra validation here
	CAtlasView * pView = (CAtlasView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView());
	pView->b_Condition=false;
	CDialog::OnOK();
}

void CLayerCtrlDlg::OnUPLayer() 
{
	// TODO: Add your control notification handler code here
	int n=m_LayerList.GetCurSel();
	CString str;
	m_LayerList.GetText(n-1,str);
	m_LayerList.InsertString(n+1,str);
	m_LayerList.DeleteString(n-1);
	
	OnPaint();
	
	ChangeLayerOrder(n,n-1);
	
}
 
void CLayerCtrlDlg::OnLayerInfo() 
{
	// TODO: Add your control notification handler code here
    CLayerAttri dlg;
	
	CLayerCtrlDlg  *pLayerCtrlDlg=NULL;
    int n=m_LayerList.GetCurSel();
	
	pLayerCtrlDlg=this;
	if(dlg.DoModal()==IDOK)
	{
		UpdateData(true);
	}
	else
	{
	}
	
	m_LayerList.SetCurSel(n);
	
}

void CLayerCtrlDlg::OnAddLayer() 
{
	// TODO: Add your control notification handler code here
	m_LayerList.InsertString(0,"新图层");
	m_LayerList.SetCurSel(0);
	OnPaint();
	//增加图层
	CAtlasDoc *pDoc=(CAtlasDoc *)( ((CMainFrame*)AfxGetMainWnd())->GetActiveDocument() );
	CGeoLayer *layer=new CGeoLayer;
	pDoc->pMap->AddLayer(layer);
	UpdateData(false);
	
}

void CLayerCtrlDlg::OnEdit() 
{
	// TODO: Add your control notification handler code here
	//得到当前活动视图指针
    CAtlasView * pView = (CAtlasView *)(((CMainFrame*)AfxGetMainWnd())->GetActiveView());
	pView->b_Condition=false;
	
	int n=m_LayerList.GetCurSel();
	if(n>=0)
	{
		CString str;
		m_LayerList.GetText(n,str);
		CAtlasDoc *pDoc=(CAtlasDoc*)( ((CMainFrame*)AfxGetMainWnd())->GetActiveDocument() );
		int opr=pDoc->pMap->GetLayerNumByName(str);
		if(opr!=-1)
		{
			CGeoLayer *layer=pDoc->pMap->m_parLayer[opr];
			pDoc->pMap->m_EditableLayer=layer;	
			if(layer->m_uLayerType==2||layer->m_uLayerType==3)
				layer->m_bIsShowVertex=true;
		}
		pView->b_Condition=true;
	}
	
	CDialog::OnOK();
	
}

void CLayerCtrlDlg::OnDOWNLayer() 
{
	// TODO: Add your control notification handler code here
	int n=m_LayerList.GetCurSel();
	CString str;
	m_LayerList.GetText(n+1,str);
	m_LayerList.InsertString(n,str);
	m_LayerList.DeleteString(n+2);
	
	OnPaint();
	ChangeLayerOrder(n,n+1);
		
	
}

void CLayerCtrlDlg::OnDeleteLayer() 
{
	// TODO: Add your control notification handler code here
	if(MessageBox("将选中图层删除，确定?","确认删除",4)==6)//弹出消息框提示，"是"则返回
	{
		int n=m_LayerList.GetCurSel(),num=m_LayerList.GetCount();
		CString str;
		m_LayerList.GetText(n,str);
		m_LayerList.DeleteString(n);
		if(n==num-1)
			m_LayerList.SetCurSel(n-1);
		else
			m_LayerList.SetCurSel(n);
		//删除图层
		CAtlasDoc *pDoc=(CAtlasDoc *)( ((CMainFrame*)AfxGetMainWnd())->GetActiveDocument() );
		int del=pDoc->pMap->GetLayerNumByName(str);
		if(del!=-1)
			pDoc->pMap->DeleteLayer(del);
		
		OnPaint();
		UpdateData(false);
		
	}
	
}

BOOL CLayerCtrlDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CAtlasDoc *pDoc=(CAtlasDoc *)( ((CMainFrame*)AfxGetMainWnd())->GetActiveDocument() );
	for(int i=0;i<pDoc->pMap->m_parLayer.GetSize();i++)//按显示先后顺序加入图层名
	{
		m_LayerList.InsertString(0,pDoc->pMap->m_parLayer[i]->m_LayerName);
	}
	
	m_LayerList.SetCurSel(0);
	
	/*(CButton *)GetDlgItem(IDC_UP_Layer)->EnableWindow(false);*/
	
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLayerCtrlDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	(CButton*)GetDlgItem(IDC_LAYER_INFO)->EnableWindow(true);
	(CButton*)GetDlgItem(IDC_ADD_LAYER)->EnableWindow(true);
	(CButton*)GetDlgItem(IDC_DELETE_LAYER)->EnableWindow(true);
	(CButton*)GetDlgItem(IDC_Edit)->EnableWindow(true);
	(CButton*)GetDlgItem(IDC_UP_Layer)->EnableWindow(true);
	(CButton*)GetDlgItem(IDC_DOWN_Layer)->EnableWindow(true);

	if(m_LayerList.GetCount()<1)//无图层时
	{
		(CButton*)GetDlgItem(IDC_LAYER_INFO)->EnableWindow(false);
		(CButton*)GetDlgItem(IDC_DELETE_LAYER)->EnableWindow(false);
		(CButton*)GetDlgItem(IDC_Edit)->EnableWindow(false);
		(CButton*)GetDlgItem(IDC_UP_Layer)->EnableWindow(false);
		(CButton*)GetDlgItem(IDC_DOWN_Layer)->EnableWindow(false);
		
	}
	
	else 
	{
		if(m_LayerList.GetCurSel()==0)
			(CButton*)GetDlgItem(IDC_UP_Layer)->EnableWindow(false);
		if(m_LayerList.GetCurSel()==m_LayerList.GetCount()-1)
			(CButton*)GetDlgItem(IDC_DOWN_Layer)->EnableWindow(false);
	}
	
	
	// Do not call CDialog::OnPaint() for painting messages
}

HBRUSH CLayerCtrlDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
//	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	HBRUSH hbr=::CreateSolidBrush(RGB(204,230,255));
	
	// TODO: Change any attributes of the DC here
	pDC->SetTextColor(RGB(255,0,0));
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetBkColor(RGB(204,230,255));
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CLayerCtrlDlg::OnSelchangeLayerLIST() 
{
	// TODO: Add your control notification handler code here
    OnPaint();
	
}
