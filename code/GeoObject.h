// GeoObject.h: interface for the CGeoObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GEOOBJECT_H__8E0EA6FE_60A7_4614_AE28_6F7035E658A6__INCLUDED_)
#define AFX_GEOOBJECT_H__8E0EA6FE_60A7_4614_AE28_6F7035E658A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//#include "AtlasDoc.h"
#include "StdAfx.h"
#include "AtlasDoc.h"

class CAtlasDoc;

class CGeoObject  
{
public:
	CTypedPtrArray<CPtrArray,CPoint*> m_parPoint;
	CString m_ObjectName;
public:
/*	virtual void Draw(CDC *pDC)=0;*/
/*	virtual void Draw(CDC *pDC,CAtlasDoc *pDoc)=0;*/
	void SetPoint(CPoint &point);
	void SetObjectName(CString ObjectName);
	CGeoObject();
	virtual ~CGeoObject();
public:
	void SetObjectBrush(LOGBRUSH &brush, CAtlasDoc *pDoc,int i);
	void SetObjectPen(LOGPEN &pen, CAtlasDoc *pDoc,int i);
	virtual void Draw(CDC *pDC)=0;
	virtual void Draw(CDC *pDC,CAtlasDoc *pDoc,int i) = 0;
};

#endif // !defined(AFX_GEOOBJECT_H__8E0EA6FE_60A7_4614_AE28_6F7035E658A6__INCLUDED_)
