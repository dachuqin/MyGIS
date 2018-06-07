// GeoAnno.h: interface for the CGeoAnno class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GEOANNO_H__88B33DA8_E41C_4FC5_9E5E_2905F09E54E3__INCLUDED_)
#define AFX_GEOANNO_H__88B33DA8_E41C_4FC5_9E5E_2905F09E54E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GeoObject.h"
#include "AtlasDoc.h"

class CAtlasDoc;

class CGeoAnno : public CGeoObject  
{
public:
	CPoint m_AnnoVertex;
	COLORREF m_AnnoColor;
	void Draw(CDC *pDC,CAtlasDoc *pDoc,int i);
	void Draw(CDC *pDC);
	CString m_FontType;
	CString m_AnnoText;
	float m_FontHeight;
	CGeoAnno();
	virtual ~CGeoAnno();

};

#endif // !defined(AFX_GEOANNO_H__88B33DA8_E41C_4FC5_9E5E_2905F09E54E3__INCLUDED_)
