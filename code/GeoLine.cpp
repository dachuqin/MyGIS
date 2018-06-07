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
	
	//CGeoLine多于一个点
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
	SetObjectPen(tmp_logpen,pDoc,i);					//根据线CGeoLine的属性标识码设置画笔CPen
	
	//The LOGBRUSH structure defines the style, color, and pattern of a physical brush. 
	//It is used by the Windows CreateBrushIndirect and ExtCreatePen functions.
	LOGBRUSH tmp_logbrush;
	SetObjectBrush(tmp_logbrush,pDoc,i);				//根据线CGeoLine的属性标识码设置画笔CBrush
	
	CPen *pPen = new CPen();
	pPen->CreatePenIndirect(&tmp_logpen);
	CBrush *pBrush = new CBrush();
	pBrush->CreateBrushIndirect(&tmp_logbrush);
	CPen *pOldPen = pDC->SelectObject(pPen);		//保存原来CPen的状态
	CBrush *pOldBrush = pDC->SelectObject(pBrush);	//保存原来CBrush的状态
	
	//如果一条线CGeoLine只存储了一个点
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
	
	//CGeoLine多于一个点
	else{
		pDC->MoveTo(*m_parPoint.GetAt(0));
		for(int i = 0; i < m_parPoint.GetSize(); i++){
			pDC->LineTo(*m_parPoint.GetAt(i));
		}
	}
	
	//恢复原来的绘图环境
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	delete pPen;
	pPen = NULL;
	delete pBrush;
	pBrush = NULL;
}
