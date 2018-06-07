// GeoLayer.cpp: implementation of the CGeoLayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Atlas.h"
#include "GeoLayer.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGeoLayer::CGeoLayer()
{
	m_LayerVisible=TRUE;
	m_LayerSelectable=TRUE;
	m_LayerVisible=FALSE;
	m_LayerName="新图层";
	m_parGeoObject.RemoveAll();
    
	m_pen.lopnColor = RGB(rand()*255,rand()*255,rand()*255);
	m_pen.lopnStyle = PS_SOLID;
	m_pen.lopnWidth.x = 1;

	m_brush.lbColor = RGB(rand()*255,rand()*255,rand()*255);
	m_brush.lbHatch = HS_HORIZONTAL;
	m_brush.lbStyle = BS_SOLID;
}

CGeoLayer::~CGeoLayer()
{

}

void CGeoLayer::SetLayerName(CString LayerName)
{
	m_LayerName=LayerName;
}

void CGeoLayer::SetLayerKeyNO(int key)
{
	m_LayerKeyNO=key;
}

BOOL CGeoLayer::LayerVisible(int visible)
{
	if (visible==1)
	{
		m_LayerVisible=TRUE;
		return TRUE;
	}
	else
	{
		m_LayerVisible=FALSE;
		return FALSE;
	}
}

BOOL CGeoLayer::LayerSelectable(int Selectable)
{
	if (Selectable==1)
	{
		m_LayerSelectable=TRUE;
		return TRUE;
	}
	else
	{
		m_LayerSelectable=FALSE;
		return FALSE;
	}
}

BOOL CGeoLayer::LayerEditable(int Editable)
{
	if (Editable==1)
	{
		m_LayerEditable=TRUE;
		return TRUE;
	}
	else
	{
		m_LayerEditable=FALSE;
		return FALSE;
	}
}

void CGeoLayer::SetGeoObject(CGeoObject *object)
{
	m_parGeoObject.Add(object);
}

void CGeoLayer::Draw(CDC *pDC, CAtlasDoc *pDoc,int i)
{
	//获得原来初始绘图环境的绘图模式
	int nOldMode = pDC->GetROP2();
	//如果是画图模式设置为不可见（false），则将绘图模式设置为异或方式
	if(m_LayerVisible == FALSE)
	{
		//	nOldMode = pDC->SetROP2(R2_XORPEN);
		return;
	}
	//如果可见则直接使用画笔的颜色
	else
	{
		nOldMode = pDC->SetROP2(R2_COPYPEN);
	}
	
	for(int j = 0; j < m_parGeoObject.GetSize(); j++)
	{
		m_parGeoObject.GetAt(j)->Draw(pDC, pDoc,i);
	}
	pDC->SetROP2(nOldMode);
}

void CGeoLayer::Draw(CDC *pDC)
{
	int nOldMode = pDC->GetROP2();
	//如果是画图模式设置为不可见（false），则将绘图模式设置为异或方式
	if(m_LayerVisible == FALSE)
	{
		return;
	}
	//如果可见则直接使用画笔的颜色
	else
	{
		nOldMode = pDC->SetROP2(R2_COPYPEN);
	}
	AfxMessageBox("我已经画了");
	for(int i = 0; i < m_parGeoObject.GetSize(); i++)
	{
		m_parGeoObject.GetAt(i)->Draw(pDC);
	}
	pDC->SetROP2(nOldMode);	
}

LOGPEN CGeoLayer::SetLayerPen()
{
	return m_pen;
}

LOGBRUSH CGeoLayer::SetLayerBrush()
{
	return m_brush;
}

CGeoLayer::CGeoLayer(UINT type, CString name)
{
	m_uLayerType=type;
	m_LayerName=name;
	m_LayerVisible=TRUE;
    m_LayerSelectable=TRUE;
	m_LayerEditable=TRUE;
	m_bIsShowVertex=TRUE;
	m_parGeoObject.RemoveAll();

}

void CGeoLayer::Initiate(UINT type, CString name)
{
	m_uLayerType=type;
	m_LayerName=name;
	m_LayerVisible=TRUE;
	m_LayerVisible=TRUE;
	m_LayerEditable=TRUE;
	m_bIsShowVertex=TRUE;

}
