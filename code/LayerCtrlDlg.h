#if !defined(AFX_LAYERCTRLDLG_H__F4975B94_CB3F_475F_8825_A83DA926A03B__INCLUDED_)
#define AFX_LAYERCTRLDLG_H__F4975B94_CB3F_475F_8825_A83DA926A03B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LayerCtrlDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLayerCtrlDlg dialog

class CLayerCtrlDlg : public CDialog
{
// Construction
public:
	CLayerCtrlDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLayerCtrlDlg)
	enum { IDD = IDD_LAYERCTRLDLG_DIALOG };
	CButton	m_UpButton;
	CButton	m_DownButton;
	CListBox	m_LayerList;
	//}}AFX_DATA
public:
	void ChangeLayerOrder(int m,int n);


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLayerCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLayerCtrlDlg)
	virtual void OnOK();
	afx_msg void OnUPLayer();
	afx_msg void OnLayerInfo();
	afx_msg void OnAddLayer();
	afx_msg void OnEdit();
	afx_msg void OnDOWNLayer();
	afx_msg void OnDeleteLayer();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSelchangeLayerLIST();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAYERCTRLDLG_H__F4975B94_CB3F_475F_8825_A83DA926A03B__INCLUDED_)
