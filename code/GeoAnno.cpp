// GeoAnno.cpp: implementation of the CGeoAnno class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Atlas.h"
#include "GeoAnno.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGeoAnno::CGeoAnno()
{

}

CGeoAnno::~CGeoAnno()
{

}

//DEL void CGeoAnno::SetAnnoPoint(CPoint &point)
//DEL {
//DEL 	m_parAnnoPoint.Add(new CPoint(point));
//DEL }

void CGeoAnno::Draw(CDC *pDC)
{

}

void CGeoAnno::Draw(CDC *pDC, CAtlasDoc *pDoc,int i)
{
	COLORREF AnnoColor=m_AnnoColor;
	//if(m_bIsSelected)
	//	AnnoColor=RGB(179,0,225);
	
	CFont font;
	font.CreateFont((int)m_FontHeight,0,0,0,400,false,false,0,ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS,
		m_FontType);
	CFont* oldFont=pDC->SelectObject(&font);
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(AnnoColor);
	
	//if(m_bShowMBR)
	//{
	//	DrawBoundary(pDC);
	//}
	
	
	pDC->TextOut(m_AnnoVertex.x,m_AnnoVertex.y,m_AnnoText);
}
