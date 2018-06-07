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
	//���һ����CGeoPolygonֻ�洢��һ����
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
	
	//CGeoPolygon����һ����
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
		//	AfxMessageBox("�Ѿ�����Polygon");
		delete []Point;
	}
}

void CGeoPolygon::Draw(CDC *pDC, CAtlasDoc *pDoc,int i)
{
	LOGPEN tmp_logpen;
	SetObjectPen(tmp_logpen,pDoc,i);					//������CGeoLine�����Ա�ʶ�����û���CPen
	
	LOGBRUSH tmp_logbrush;
	SetObjectBrush(tmp_logbrush,pDoc,i);				//������CGeoLine�����Ա�ʶ�����û���CBrush
	
	CPen *pPen = new CPen();
	pPen->CreatePenIndirect(&tmp_logpen);
	CBrush *pBrush = new CBrush();
	pBrush->CreateBrushIndirect(&tmp_logbrush);
	CPen *pOldPen = pDC->SelectObject(pPen);		//����ԭ��CPen��״̬
	CBrush *pOldBrush = pDC->SelectObject(pBrush);	//����ԭ��CBrush��״̬
	
	//���һ����CGeoPolygonֻ�洢��һ����
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
	
	//CGeoPolygon����һ����
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
	
	//�ָ�ԭ���Ļ�ͼ����
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	delete pPen;
	pPen = NULL;
	delete pBrush;
	pBrush = NULL;
}
