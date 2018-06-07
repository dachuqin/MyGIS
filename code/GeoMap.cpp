// GeoMap.cpp: implementation of the CGeoMap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Atlas.h"
#include "GeoMap.h"
#include "MainFrm.h"
#include "AtlasView.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGeoMap::CGeoMap()
{
	m_parLayer.RemoveAll();
}

CGeoMap::~CGeoMap()
{

}

void CGeoMap::SetMapName(CString &MapName)
{
	m_strMapName = MapName;
}

void CGeoMap::SetMapBoundary(CRect MapExtent)
{
	m_MapExtent=MapExtent;
}

void CGeoMap::SetLayerNum(int LayerNum)
{
	m_LayerNum=LayerNum;
}

void CGeoMap::SetLayer(CGeoLayer *layer)
{
	m_parLayer.Add(layer);
}

int CGeoMap::GetLayerNum()
{
	return m_parLayer.GetSize();
}

CGeoLayer * CGeoMap::GetLayer(int i)
{
	return m_parLayer.GetAt(i);
}

void CGeoMap::DrawMap(CDC *pDC, CAtlasDoc *pDoc)
{
	for(int i = 0; i < m_parLayer.GetSize(); i++)
	{
		//m_parLayer.GetAt(i)->Draw(pDC, m_parLayer.GetAt(i)->GetDisplay());	
		CGeoLayer *pLayer = (CGeoLayer *)m_parLayer.GetAt(i);
		pLayer->Draw(pDC,pDoc,i);
	}
}

void CGeoMap::ChangeLayerOrder(CString str1, CString str2)
{
	CGeoLayer *temLayer=NULL;
	int a=GetLayerNumByName(str1);
	int b=GetLayerNumByName(str2);
	if(a!=-1&&b!=-1)
	{
		temLayer=m_parLayer[a];
		m_parLayer[a]=m_parLayer[b];
		m_parLayer[b]=temLayer;
	}

}

int CGeoMap::GetLayerNumByName(CString str)
{
	for(int i=0; i<m_parLayer.GetSize(); i++)
	{
		if(m_parLayer[i]->m_LayerName==str)
			return i;
	}	
	
	::AfxMessageBox("failed to return a valid layer");    //Œ Ã‚
	return -1;//¥ÌŒÛ∑µªÿ

}

void CGeoMap::AddLayer(CGeoLayer *layer)
{
	m_parLayer.Add(layer);
	SelEditableLayer(m_parLayer.GetSize()-1);

}

void CGeoMap::AddLayer(UINT add, CGeoLayer *layer)
{
	m_parLayer.InsertAt(add,layer);
      
}

void CGeoMap::SelEditableLayer(UINT edit)
{
	for(int i=0;i<m_parLayer.GetSize();i++)
    m_parLayer[i]->m_LayerEditable=false;
    m_parLayer[edit]->m_LayerEditable=true;

}

void CGeoMap::DeleteLayer(UINT del)
{
   m_parLayer.RemoveAt(del);
}

void CGeoMap::Draw(CDC *pDC)
{
	CAtlasView * pView = (CAtlasView *)(((CMainFrame*)AfxGetMainWnd())->GetActiveView());
	
	for(int i=0;i<m_parLayer.GetSize(); i++)
	{
		if(pView->m_fScaleCtrl<=1000&&pView->m_fScaleCtrl>=0)
			//		order=DrawOrder[i];
			m_parLayer[i]->Draw(pDC);
	}

}
