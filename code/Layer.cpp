// Layer.cpp: implementation of the CLayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Atlas.h"
#include "Layer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLayer::CLayer()
{
    m_bDisplay = true;
	m_bIsSelectable = true;
	m_bIsEditable = false;
	m_strName = "";
	//m_parGeoObject.RemoveAll();
	m_nLayerType = -1;		//初始化图层类型
}

CLayer::~CLayer()
{

}

CString CLayer::GetLayerName()   
{
    return m_strName;
}

void CLayer::SetLayerName(CString strName)
{
   m_strName=strName;
}

bool CLayer::GetDisplay()
{
   return m_bDisplay;
}

bool CLayer::GetLayerSelectable()
{
    return m_bIsSelectable;
}

bool CLayer::GetLayerEditable()
{
    return m_bIsEditable;
}

void CLayer::SetDisplay(bool bDispaly)
{
     m_bDisplay=bDispaly;
}

void CLayer::SetLayerSelectable(bool selectable)
{
     m_bIsSelectable=selectable;
}

void CLayer::SetLayerEditable(bool editable)
{
    m_bIsEditable=editable;
}

void CLayer::SetColor(CDC *pDC, COLORREF colorref)
{
    LOGPEN tmp_logpen;
	tmp_logpen.lopnColor = colorref;                        
	tmp_logpen.lopnStyle = PS_SOLID;
	tmp_logpen.lopnWidth.x = 10;
	LOGBRUSH tmp_logbrush;//定义空的笔刷
	tmp_logbrush.lbStyle = BS_SOLID;
	
	
	CPen *pPen=new CPen();
	pPen->CreatePenIndirect(&tmp_logpen);
	CBrush *pBrush=new CBrush();
	pBrush->CreateBrushIndirect(&tmp_logbrush);
	CPen *pOldPen=pDC->SelectObject(pPen);
	CBrush *pOldBrush=pDC->SelectObject(pBrush);
	AfxMessageBox("准备好了");
	Draw(pDC);

}

void CLayer::SetGeoObject(CGeoObject *object)
{
    m_parGeoObject.Add(object);
}
