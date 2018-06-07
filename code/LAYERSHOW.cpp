// LAYERSHOW.cpp : implementation file
//

#include "stdafx.h"
#include "Atlas.h"
#include "LAYERSHOW.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLAYERSHOW dialog


CLAYERSHOW::CLAYERSHOW(CWnd* pParent /*=NULL*/)
	: CDialog(CLAYERSHOW::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLAYERSHOW)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLAYERSHOW::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLAYERSHOW)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLAYERSHOW, CDialog)
	//{{AFX_MSG_MAP(CLAYERSHOW)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLAYERSHOW message handlers
