// GeoObject.cpp: implementation of the CGeoObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Atlas.h"
#include "GeoObject.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGeoObject::CGeoObject()
{
	m_parPoint.RemoveAll();
}

CGeoObject::~CGeoObject()
{

}

void CGeoObject::SetObjectName(CString ObjectName)
{
	if (ObjectName!="0")
	{
		m_ObjectName=ObjectName;
	}
	else
	{
		m_ObjectName="";
	}
}

void CGeoObject::SetPoint(CPoint &point)
{
	m_parPoint.Add(new CPoint(point));
}

// void CGeoObject::Draw(CDC *pDC, CAtlasDoc *pDoc)
// {
// 
// }
// 
// void CGeoObject::Draw(CDC *pDC)
// {
// 
// }

void CGeoObject::SetObjectPen(LOGPEN &pen, CAtlasDoc *pDoc,int i)
{
// 	if(MyApp.nDataStructure == 1){//����������������ļ�
// 		CAttri *tmp;
// 		//int j = pDoc->MyMap.Lookup((LPCTSTR)this->GetLayerName(), (CObject*&)tmp);
// 		if(pDoc->MyMap.Lookup((LPCTSTR)this->GetLayerName(), (CObject*&)tmp)){
// 			pen.lopnColor = tmp->GetPenColor();
// 			pen.lopnStyle = tmp->GetPenStyle();
// 			pen.lopnWidth = tmp->GetPenWidth();
// 			this->GetLayerName().ReleaseBuffer();
// 			return;
// 		}
// 	}
	//���δ�����������ļ�,�����Ҳ�����Ӧ�����Լ�¼

	pen=pDoc->pMap->GetLayer(i)->SetLayerPen();
}

void CGeoObject::SetObjectBrush(LOGBRUSH &brush, CAtlasDoc *pDoc,int i)
{
// 	if(MyApp.nDataStructure == 1)
// 	{//����������������ļ�
// 		CAttri *tmp;	//��ָ�뷵��GeoObject��Ӧ�����Լ�¼
// 		//	int k = pDoc->MyMap.Lookup((LPCTSTR)this->GetLayerName(),(CObject* &)tmp);
// 		//dxy
// 		//MessageBox(NULL,(this->GetLayerName()).GetBuffer(),L"Attribution Data Debug",MB_OK);
// 		//(this->GetLayerName()).ReleaseBuffer();
// 		//dxy
// 		//if(pDoc->MyMap.Lookup((LPCTSTR)this->GetLayerName(),(CObject* &)tmp)){
// 		//if(pDoc->MyMap.Lookup(L"bk",(CObject* &)tmp)){
// 		if(pDoc->MyMap.Lookup((this->GetLayerName()),(CObject* &)tmp)){
// 			brush.lbColor = tmp->GetBrushColor();
// 			brush.lbStyle = tmp->GetBrushStyle();
// 			
// 			return;
// 		}
// 	}
	//���δ�����������ļ�,�����Ҳ�����Ӧ�����Լ�¼
	brush=pDoc->pMap->GetLayer(i)->SetLayerBrush();
}
