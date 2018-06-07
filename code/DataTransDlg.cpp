// DataTransDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Atlas.h"
#include "AtlasDoc.h"
#include "MainFrm.h"
#include "DataTransDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DataTransDlg dialog


DataTransDlg::DataTransDlg(CWnd* pParent /*=NULL*/)
	: CDialog(DataTransDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(DataTransDlg)
	//}}AFX_DATA_INIT
}


void DataTransDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DataTransDlg)
	DDX_Control(pDX, IDC_EDIT_IMPORT, m_EditImport);
	DDX_Control(pDX, IDC_EDIT_EXPORT, m_EditExport);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DataTransDlg, CDialog)
	//{{AFX_MSG_MAP(DataTransDlg)
	ON_BN_CLICKED(IDC_BUTTON_IMPORT, OnButtonImportDlg)
	ON_BN_CLICKED(IDC_BUTTON_EXPORT, OnButtonExportDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DataTransDlg message handlers

void DataTransDlg::OnOK() //响应确认按钮事件，调用DataTransform函数进行数据转换
{
	// TODO: Add extra validation here
	if(strcmp(m_ImportFilePath,"")==0)
	{
		AfxMessageBox("错误:\n请选择需要转换的文件!");
        return;
	}
	
	
    if(strcmp(m_ExportFilePath,"")==0)
	{
		AfxMessageBox("错误:\n请选择保存转换后文件的文件夹路径!");
        return; 
	}

	CAtlasDoc *pDoc=(CAtlasDoc*)(((CMainFrame*)AfxGetMainWnd())->GetActiveDocument());
	CRect tmp(0,0,0,0);
	if(pDoc->DataTransform(m_ImportFilePath,m_ExportFilePath,tmp)==TRUE)
	{
		AfxMessageBox("转换文件格式成功完成!\n请点确定返回!");
	}

	CDialog::OnOK();
}

void DataTransDlg::OnButtonImportDlg() //导入文件，响应导入浏览按钮事件
{
	// TODO: Add your control notification handler code here
	CFileDialog ImportDlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"DXF文件(*.dxf)|*.dxf|CW文件(*.cw)|*.cw|任意文件(*.*)|*.*||",NULL);
	if(ImportDlg.DoModal() == IDOK)
	{
		m_ImportFilePath=ImportDlg.GetPathName();
		m_EditImport.SetWindowText((LPCTSTR)m_ImportFilePath);
	}
}

void DataTransDlg::OnButtonExportDlg() //导出路径选择，响应导出浏览按钮事件
{
	// TODO: Add your control notification handler code here
	char   szTitle[80]   =   _T("选择你要保存文件的目录:");     
	BROWSEINFO   bi;   
	bi.hwndOwner   =   m_hWnd;   
	bi.pidlRoot   =   NULL;   
	bi.pszDisplayName   =   NULL;   
	bi.lpszTitle   =   szTitle;   
	bi.ulFlags   =   BIF_RETURNONLYFSDIRS;   
	bi.lpfn   =   NULL;   
	LPITEMIDLIST   pidl   =   SHBrowseForFolder(&bi);   
	if   (!pidl)     
	{   
		return   ;   
	}     
	CString   m_szPath;   
	BOOL   bSuccess   =   SHGetPathFromIDList(pidl,   m_szPath.GetBuffer(1024));   
	if   (bSuccess)   
	{   
		m_szPath.ReleaseBuffer();   
		m_ExportFilePath =   m_szPath; 
		m_EditExport.SetWindowText((LPCTSTR)m_ExportFilePath);
	}

}
