// GeoPoint.h: interface for the CGeoPoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GEOPOINT_H__FE4C038C_8795_4A43_B1F8_394B1E2D662F__INCLUDED_)
#define AFX_GEOPOINT_H__FE4C038C_8795_4A43_B1F8_394B1E2D662F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GeoObject.h"
#include "AtlasDoc.h"

class CAtlasDoc;

class CGeoPoint : public CGeoObject  
{
public:
	void Draw(CDC *pDC,CAtlasDoc *pDoc,int i);
	void Draw(CDC *pDC);
	CGeoPoint();
	virtual ~CGeoPoint();

};

#endif // !defined(AFX_GEOPOINT_H__FE4C038C_8795_4A43_B1F8_394B1E2D662F__INCLUDED_)
