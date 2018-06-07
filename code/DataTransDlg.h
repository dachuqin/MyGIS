#if !defined(AFX_DATATRANSDLG_H__D47E2FA5_25DE_4C68_8D96_D066BF8A8D6D__INCLUDED_)
#define AFX_DATATRANSDLG_H__D47E2FA5_25DE_4C68_8D96_D066BF8A8D6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataTransDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DataTransDlg dialog

class DataTransDlg : public CDialog
{
// Construction
public:
	CString m_ExportFilePath;//导出文件夹路径
	CString m_ImportFilePath;//导入文件路径
	DataTransDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DataTransDlg)
	enum { IDD = IDD_DATATRANSDLG_DIALOG };
	CEdit	m_EditImport;
	CEdit	m_EditExport;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DataTransDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DataTransDlg)
	virtual void OnOK();
	afx_msg void OnButtonImportDlg();
	afx_msg void OnButtonExportDlg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATATRANSDLG_H__D47E2FA5_25DE_4C68_8D96_D066BF8A8D6D__INCLUDED_)
