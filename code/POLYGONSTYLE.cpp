// POLYGONSTYLE.cpp : implementation file
//

#include "stdafx.h"
#include "Atlas.h"
#include "POLYGONSTYLE.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPOLYGONSTYLE dialog


CPOLYGONSTYLE::CPOLYGONSTYLE(CWnd* pParent /*=NULL*/)
	: CDialog(CPOLYGONSTYLE::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPOLYGONSTYLE)
	m_EdgeColor = _T("");
	m_FillColor = _T("");
	//}}AFX_DATA_INIT
}


void CPOLYGONSTYLE::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPOLYGONSTYLE)
	DDX_Control(pDX, IDC_EDGE_WIDTH, m_EdgeWidth);
	DDX_Control(pDX, IDC_EDGE_STYLE, m_EdgeType);
	DDX_Text(pDX, IDC_EDGE_COLOR, m_EdgeColor);
	DDX_Text(pDX, IDC_FILL_COLOR, m_FillColor);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPOLYGONSTYLE, CDialog)
	//{{AFX_MSG_MAP(CPOLYGONSTYLE)
	ON_BN_CLICKED(IDC_SEL_EDGE_COLOR, OnSelEdgeColor)
	ON_BN_CLICKED(IDC_SEL_FILL_COLOR, OnSelFillColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPOLYGONSTYLE message handlers

void CPOLYGONSTYLE::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(false);
	CString str;
	m_EdgeWidth.GetWindowText(str);
	EdgeWidth=atoi(str);
	m_EdgeType.GetWindowText(str);
	EdgeType=m_EdgeType.FindString(0,str);
	
	CDialog::OnOK();
}

void CPOLYGONSTYLE::OnSelEdgeColor() 
{
	// TODO: Add your control notification handler code here
	BYTE cRvalue,cGvalue,cBvalue;
	int nFlags=CC_FULLOPEN|CC_SHOWHELP;
	CColorDialog aDlg(RGB(0,255,255),nFlags);
	//	aDlg.SetWindowText("…Ë÷√±ﬂøÚ—’…´");
	if (aDlg.DoModal()==IDOK)
	{
		EdgeColor=aDlg.GetColor();
		cRvalue=GetRValue(EdgeColor);
		cGvalue=GetGValue(EdgeColor);
		cBvalue=GetBValue(EdgeColor);
		m_EdgeColor.Format("R:%d G:%d B:%d",cRvalue,cGvalue,cBvalue);
	}
	
	UpdateData(false);
	
}

void CPOLYGONSTYLE::OnSelFillColor() 
{
	// TODO: Add your control notification handler code here
	BYTE cRvalue,cGvalue,cBvalue;
	int nFlags=CC_FULLOPEN|CC_SHOWHELP;
	CColorDialog aDlg(RGB(0,255,255),nFlags);
	//	aDlg.SetWindowText("…Ë÷√ÃÓ≥‰—’…´");
	if (aDlg.DoModal()==IDOK)
	{
		FillColor=aDlg.GetColor();
		cRvalue=GetRValue(FillColor);
		cGvalue=GetGValue(FillColor);
		cBvalue=GetBValue(FillColor);
		m_FillColor.Format("R:%d G:%d B:%d",cRvalue,cGvalue,cBvalue);
	}
	
	UpdateData(false);
	
}

BOOL CPOLYGONSTYLE::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_EdgeType.AddString("PS_SOLID");
	m_EdgeType.AddString("PS_DASH");
	m_EdgeType.AddString("PS_DOT");
	m_EdgeType.AddString("PS_DASHDOT");
	m_EdgeType.AddString("PS_DASHDOTDOT");
	m_EdgeType.AddString("PS_NULL");
	m_EdgeType.AddString("PS_INSIDEFRAME");
	m_EdgeType.AddString("PS_GEOMETRIC");
	m_EdgeType.AddString("PS_ALTERNATE");
	m_EdgeType.AddString("PS_USERSTYLE");
	m_EdgeType.AddString("PS_ENDCAP_ROUND");
	m_EdgeType.AddString("PS_ENDCAP_SQUARE");
	m_EdgeType.AddString("PS_ENDCAP_FLAT");
	m_EdgeType.AddString("PS_JOIN_BEVEL");
	m_EdgeType.AddString("PS_JOIN_MITER");
	m_EdgeType.AddString("PS_JOIN_ROUND");
	
	m_EdgeType.SetCurSel(0);
	char str[100];
	for(int i=1;i<20;i++)
	{
		_itoa(i,str,10);
		m_EdgeWidth.AddString(str);
	}
	m_EdgeWidth.SetCurSel(0);
	
	EdgeType=0;
	EdgeWidth=0;
	EdgeColor=RGB(51,51,51);
	FillColor=RGB(204,204,204);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
