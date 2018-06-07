// GeoPoint.cpp: implementation of the CGeoPoint class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Atlas.h"
#include "GeoPoint.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGeoPoint::CGeoPoint()
{

}

CGeoPoint::~CGeoPoint()
{

}

void CGeoPoint::Draw(CDC *pDC)
{
	if(m_parPoint.GetSize() == 1)
	{
		RECT *Rt;
		Rt = new RECT;
		long det = 50;
		Rt->left = m_parPoint.GetAt(0)->x - det;
		Rt->right = m_parPoint.GetAt(0)->x + det;
		Rt->top = m_parPoint.GetAt(0)->y + det;
		Rt->bottom = m_parPoint.GetAt(0)->y - det;
		pDC->Ellipse(Rt);
		delete Rt;
	}
}

void CGeoPoint::Draw(CDC *pDC, CAtlasDoc *pDoc,int i)
{
	LOGPEN tmp_logpen;
	SetObjectPen(tmp_logpen,pDoc,i);					//根据线CGeoLine的属性标识码设置画笔CPen
	
	LOGBRUSH tmp_logbrush;
	SetObjectBrush(tmp_logbrush,pDoc,i);				//根据线CGeoLine的属性标识码设置画笔CBrush
	
	CPen *pPen = new CPen();
	pPen->CreatePenIndirect(&tmp_logpen);
	CBrush *pBrush = new CBrush();
	pBrush->CreateBrushIndirect(&tmp_logbrush);
	CPen *pOldPen = pDC->SelectObject(pPen);		//保存原来CPen的状态
	CBrush *pOldBrush = pDC->SelectObject(pBrush);	//保存原来CBrush的状态
	
	if(m_parPoint.GetSize() == 1)
	{
		RECT *Rt;
		Rt = new RECT;
		long det = 50;
		Rt->left = m_parPoint.GetAt(0)->x - det;
		Rt->right = m_parPoint.GetAt(0)->x + det;
		Rt->top = m_parPoint.GetAt(0)->y + det;
		Rt->bottom = m_parPoint.GetAt(0)->y - det;
		pDC->Ellipse(Rt);
		delete Rt;
	}
	
	//恢复原来的绘图环境
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	delete pPen;
	pPen = NULL;
	delete pBrush;
	pBrush = NULL;
}
