#if !defined(AFX_POLYGONSTYLE_H__1266B67A_9EA3_4E41_B1F6_108D1F369302__INCLUDED_)
#define AFX_POLYGONSTYLE_H__1266B67A_9EA3_4E41_B1F6_108D1F369302__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// POLYGONSTYLE.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPOLYGONSTYLE dialog

class CPOLYGONSTYLE : public CDialog
{
// Construction
public:
	CPOLYGONSTYLE(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPOLYGONSTYLE)
	enum { IDD = IDD_POLYGONSTYLE_DIALOG };
	CComboBox	m_EdgeWidth;
	CComboBox	m_EdgeType;
	CString	m_EdgeColor;
	CString	m_FillColor;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPOLYGONSTYLE)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	public:
		COLORREF EdgeColor;
		COLORREF FillColor;
		int EdgeWidth;
	    int EdgeType;

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPOLYGONSTYLE)
	virtual void OnOK();
	afx_msg void OnSelEdgeColor();
	afx_msg void OnSelFillColor();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POLYGONSTYLE_H__1266B67A_9EA3_4E41_B1F6_108D1F369302__INCLUDED_)
