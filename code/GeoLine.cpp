// GeoLine.cpp: implementation of the CGeoLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Atlas.h"
#include "GeoLine.h"
//#include "AtlasDoc.h"
#include "MainFrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGeoLine::CGeoLine()
{

}

CGeoLine::~CGeoLine()
{

}

void CGeoLine::Draw(CDC *pDC)
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
		pDC->DPtoLP(Rt);
		pDC->Ellipse(Rt);
		delete Rt;
	}
	
	//CGeoLine����һ����
	else
	{
		pDC->MoveTo(*m_parPoint.GetAt(0));
		for(int i = 0; i < m_parPoint.GetSize(); i++)
		{
			pDC->LineTo(*m_parPoint.GetAt(i));
		}
	}
}

void CGeoLine::Draw(CDC *pDC, CAtlasDoc *pDoc,int i)
{
	LOGPEN tmp_logpen;
	SetObjectPen(tmp_logpen,pDoc,i);					//������CGeoLine�����Ա�ʶ�����û���CPen
	
	//The LOGBRUSH structure defines the style, color, and pattern of a physical brush. 
	//It is used by the Windows CreateBrushIndirect and ExtCreatePen functions.
	LOGBRUSH tmp_logbrush;
	SetObjectBrush(tmp_logbrush,pDoc,i);				//������CGeoLine�����Ա�ʶ�����û���CBrush
	
	CPen *pPen = new CPen();
	pPen->CreatePenIndirect(&tmp_logpen);
	CBrush *pBrush = new CBrush();
	pBrush->CreateBrushIndirect(&tmp_logbrush);
	CPen *pOldPen = pDC->SelectObject(pPen);		//����ԭ��CPen��״̬
	CBrush *pOldBrush = pDC->SelectObject(pBrush);	//����ԭ��CBrush��״̬
	
	//���һ����CGeoLineֻ�洢��һ����
	if(m_parPoint.GetSize() == 1){
		RECT *Rt;
		Rt = new RECT;
		long det = 50;
		Rt->left = m_parPoint.GetAt(0)->x - det;
		Rt->right = m_parPoint.GetAt(0)->x + det;
		Rt->top = m_parPoint.GetAt(0)->y + det;
		Rt->bottom = m_parPoint.GetAt(0)->y - det;
		pDC->DPtoLP(Rt);
		pDC->Ellipse(Rt);
		delete Rt;//czl
	}
	
	//CGeoLine����һ����
	else{
		pDC->MoveTo(*m_parPoint.GetAt(0));
		for(int i = 0; i < m_parPoint.GetSize(); i++){
			pDC->LineTo(*m_parPoint.GetAt(i));
		}
	}
	
	//�ָ�ԭ���Ļ�ͼ����
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	delete pPen;
	pPen = NULL;
	delete pBrush;
	pBrush = NULL;
}
