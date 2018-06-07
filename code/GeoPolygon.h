// GeoPolygon.h: interface for the CGeoPolygon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GEOPOLYGON_H__CC506ED2_AC63_401A_AC31_052AD191412B__INCLUDED_)
#define AFX_GEOPOLYGON_H__CC506ED2_AC63_401A_AC31_052AD191412B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GeoObject.h"
#include "AtlasDoc.h"

class CAtlasDoc;

class CGeoPolygon : public CGeoObject  
{
public:
	void Draw(CDC *pDC,CAtlasDoc *pDoc,int i);
	void Draw(CDC *pDC);
	CGeoPolygon();
	virtual ~CGeoPolygon();
public:
	int m_iEdgeType;
	int m_iEdgeWidth;
	COLORREF m_EdgeColor;
	COLORREF m_FillColor;

};

#endif // !defined(AFX_GEOPOLYGON_H__CC506ED2_AC63_401A_AC31_052AD191412B__INCLUDED_)
