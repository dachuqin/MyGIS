// GeoPolygon.cpp: implementation of the CGeoPolygon class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Atlas.h"
#include "GeoPolygon.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGeoPolygon::CGeoPolygon()
{

}

CGeoPolygon::~CGeoPolygon()
{

}

void CGeoPolygon::Draw(CDC *pDC)
{
	//如果一条线CGeoPolygon只存储了一个点
	if(m_parPoint.GetSize() == 1){
		RECT *Rt;
		Rt = new RECT;
		long det = 50;
		Rt->left = m_parPoint.GetAt(0)->x - det;
		Rt->right = m_parPoint.GetAt(0)->x + det;
		Rt->top = m_parPoint.GetAt(0)->y + det;
		Rt->bottom = m_parPoint.GetAt(0)->y - det;
		pDC->Ellipse(Rt);
		delete Rt;//czl
	}
	
	//CGeoPolygon多于一个点
	else{
		//pDC->MoveTo(*m_parPoint.GetAt(0));
		//for(int i = 0; i < m_parPoint.GetSize(); i++){
		//	pDC->LineTo(*m_parPoint.GetAt(i));
		//}
		POINT *Point = new POINT[m_parPoint.GetSize()];
		for(int i = 0; i < m_parPoint.GetSize(); i++){
			Point[i].x = m_parPoint.GetAt(i)->x;
			Point[i].y = m_parPoint.GetAt(i)->y;
			//	MessageBox(
		}
		//MessageBox(NULL,m_parPoint.GetSize(),NULL,0);
		
		//MessageBox(NULL,m_parPoint.GetSize()
		INT_PTR p = m_parPoint.GetSize();
		pDC->Polygon(Point,p);
		//	AfxMessageBox("已经画了Polygon");
		delete []Point;
	}
}

void CGeoPolygon::Draw(CDC *pDC, CAtlasDoc *pDoc,int i)
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
	
	//如果一条线CGeoPolygon只存储了一个点
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
	
	//CGeoPolygon多于一个点
	else
	{
		//pDC->MoveTo(*m_parPoint.GetAt(0));
		//for(int i = 0; i < m_parPoint.GetSize(); i++){
		//	pDC->LineTo(*m_parPoint.GetAt(i));
		//}
		POINT *Point = new POINT[m_parPoint.GetSize()];
		for(int i = 0; i < m_parPoint.GetSize(); i++)
		{
			Point[i].x = m_parPoint.GetAt(i)->x;
			Point[i].y = m_parPoint.GetAt(i)->y;
			//	MessageBox(
		}
		//MessageBox(NULL,m_parPoint.GetSize(),NULL,0);
		
		//MessageBox(NULL,m_parPoint.GetSize()
		INT_PTR p = m_parPoint.GetSize();
		pDC->Polygon(Point,p);
		delete []Point;
	}
	
	//恢复原来的绘图环境
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	delete pPen;
	pPen = NULL;
	delete pBrush;
	pBrush = NULL;
}
