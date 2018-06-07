#if !defined(AFX_LAYERSHOW_H__5FD834C2_5EAB_4E8E_8F3B_627C8806EFD8__INCLUDED_)
#define AFX_LAYERSHOW_H__5FD834C2_5EAB_4E8E_8F3B_627C8806EFD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LAYERSHOW.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLAYERSHOW dialog

class CLAYERSHOW : public CDialog
{
// Construction
public:
	CLAYERSHOW(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLAYERSHOW)
	enum { IDD = IDD_LAYERSHOW_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLAYERSHOW)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLAYERSHOW)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAYERSHOW_H__5FD834C2_5EAB_4E8E_8F3B_627C8806EFD8__INCLUDED_)
