// LayerAttri.cpp : implementation file
//

#include "stdafx.h"
#include "Atlas.h"
#include "LayerAttri.h"
#include "POLYGONSTYLE.h"
#include "LayerCtrlDlg.h"
#include "GeoPolygon.h"
#include "POLYGONSTYLE.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLayerAttri dialog


CLayerAttri::CLayerAttri(CWnd* pParent /*=NULL*/)
	: CDialog(CLayerAttri::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLayerAttri)
	m_ZoomMax = 0.0f;
	m_ZoomMin = 0.0f;
	m_bVisible = FALSE;
	m_LayerName = _T("");
	//}}AFX_DATA_INIT
}


void CLayerAttri::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLayerAttri)
	DDX_Text(pDX, IDC_EDIT2, m_ZoomMax);
	DDV_MinMaxFloat(pDX, m_ZoomMax, 0.f, 10000.f);
	DDX_Text(pDX, IDC_EDIT1, m_ZoomMin);
	DDV_MinMaxFloat(pDX, m_ZoomMin, 0.f, 10000.f);
	DDX_Check(pDX, IDC_CHECK1, m_bVisible);
	DDX_Text(pDX, IDC_Layer_Name, m_LayerName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLayerAttri, CDialog)
	//{{AFX_MSG_MAP(CLayerAttri)
	ON_BN_CLICKED(IDC_Layer_Style, OnLayerStyle)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLayerAttri message handlers

void CLayerAttri::OnLayerStyle() 
{
	// TODO: Add your control notification handler code here
	
		CPOLYGONSTYLE dlg;
		if(dlg.DoModal()==IDOK)
		{
			CGeoPolygon *polygon=NULL;
			
			for(int i=0;i<layer->m_parGeoObject.GetSize();i++)
			{
				polygon=(CGeoPolygon*)layer->m_parGeoObject[i];
				polygon->m_EdgeColor=dlg.EdgeColor;
				polygon->m_iEdgeType=dlg.EdgeType;
				polygon->m_iEdgeWidth=dlg.EdgeWidth;
				polygon->m_FillColor=dlg.FillColor;
			}
		}
		
	
	
}
extern CLayerCtrlDlg * pLayerCtrlDlg;
BOOL CLayerAttri::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	ListIndex=pLayerCtrlDlg->m_LayerList.GetCurSel();
	pLayerCtrlDlg->m_LayerList.GetText(ListIndex,m_LayerName);
	
	CAtlasDoc *pDoc=(CAtlasDoc *)( ((CMainFrame*)AfxGetMainWnd())->GetActiveDocument() );
	opr=pDoc->pMap->GetLayerNumByName(m_LayerName);
	if(opr!=-1)
	{
		layer=pDoc->pMap->m_parLayer[opr];
		m_bVisible=layer->m_LayerVisible;
		m_ZoomMax=1000;
		m_ZoomMin=0;
	
	}
	if(layer->m_uLayerType==5||layer->m_uLayerType==-1)
			(CButton *)GetDlgItem(IDC_Layer_Style)->EnableWindow(false);
	UpdateData(false);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLayerAttri::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	
	//更新图层控制对话框的信息
	if(NULL!=pLayerCtrlDlg)
	{
		pLayerCtrlDlg->m_LayerList.DeleteString(ListIndex);
		pLayerCtrlDlg->m_LayerList.InsertString(ListIndex,m_LayerName);
	}
	
	if(opr!=-1)
	{
		layer->m_LayerName=m_LayerName;
		layer->m_LayerVisible=m_bVisible;
		m_ZoomMin=0;
		m_ZoomMax=1000;
	    
	}
	
	layer=NULL;
	
	CDialog::OnOK();
}

HBRUSH CLayerAttri::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
