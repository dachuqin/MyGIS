// GeoLine.h: interface for the CGeoLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GEOLINE_H__5528F046_6C42_4201_B002_5AFEE65739D7__INCLUDED_)
#define AFX_GEOLINE_H__5528F046_6C42_4201_B002_5AFEE65739D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GeoObject.h"
#include "AtlasDoc.h"

class CAtlasDoc;

class CGeoLine : public CGeoObject  
{
public:
	void Draw(CDC *pDC,CAtlasDoc *pDoc,int i);
	void Draw(CDC *pDC);
	CGeoLine();
	virtual ~CGeoLine();

};

#endif // !defined(AFX_GEOLINE_H__5528F046_6C42_4201_B002_5AFEE65739D7__INCLUDED_)
