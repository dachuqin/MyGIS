// Atlas.h : main header file for the ATLAS application
//

#if !defined(AFX_ATLAS_H__8D65AF08_E076_41BB_ABE3_926EB45CC37B__INCLUDED_)
#define AFX_ATLAS_H__8D65AF08_E076_41BB_ABE3_926EB45CC37B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "AppFace.h" 
/////////////////////////////////////////////////////////////////////////////
// CAtlasApp:
// See Atlas.cpp for the implementation of this class
//

class CAtlasApp : public CWinApp
{
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CAtlasApp();
	CAppFace m_af  ;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAtlasApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAtlasApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATLAS_H__8D65AF08_E076_41BB_ABE3_926EB45CC37B__INCLUDED_)
