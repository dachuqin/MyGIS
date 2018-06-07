#if !defined(AFX_LAYERATTRI_H__3E7625C1_7E7B_4122_9E1A_4DAAEDB8CEB5__INCLUDED_)
#define AFX_LAYERATTRI_H__3E7625C1_7E7B_4122_9E1A_4DAAEDB8CEB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LayerAttri.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLayerAttri dialog
#include "GeoLayer.h"
class CLayerAttri : public CDialog
{
// Construction
public:
	CLayerAttri(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLayerAttri)
	enum { IDD = IDD_LAYERATTRI_DIALOG };
	float	m_ZoomMax;
	float	m_ZoomMin;
	BOOL	m_bVisible;
	CString	m_LayerName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLayerAttri)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	public:
	UINT ListIndex;//记录调用对话框中列表框图层序号
	CGeoLayer *layer;//指向操作图层的指针
	int opr;//图层序号，

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLayerAttri)
	afx_msg void OnLayerStyle();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAYERATTRI_H__3E7625C1_7E7B_4122_9E1A_4DAAEDB8CEB5__INCLUDED_)
