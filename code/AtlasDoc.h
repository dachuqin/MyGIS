// AtlasDoc.h : interface of the CAtlasDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ATLASDOC_H__238F514F_C037_4B21_9332_4D70978AA3F2__INCLUDED_)
#define AFX_ATLASDOC_H__238F514F_C037_4B21_9332_4D70978AA3F2__INCLUDED_

#include "GeoMap.h"	// Added by ClassView
#include "GeoLayer.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGeoLayer;
class CGeoMap;

class CAtlasDoc : public CDocument
{
protected: // create from serialization only
	CAtlasDoc();
	DECLARE_DYNCREATE(CAtlasDoc)

// Attributes
public:
	
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAtlasDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	int LayerNum;
	CGeoLayer *pLayer;
	CGeoMap *pMap;
	CString m_InputFilePath;
	BOOL OpenDXF(FILE *Path,CRect &MapExtent);
	BOOL OpenCW(CString Path,CRect &MapExtent);

	BOOL DataTransform(CString ImportPath,CString ExportPath,CRect &MapExtent);
	virtual ~CAtlasDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAtlasDoc)
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnMenuAddattribute();
	afx_msg void OnMenuAddlayer();
	afx_msg void OnFileSavebmp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATLASDOC_H__238F514F_C037_4B21_9332_4D70978AA3F2__INCLUDED_)
