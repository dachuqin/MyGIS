// GeoLayer.h: interface for the CGeoLayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GEOLAYER_H__60DADB97_4413_46CB_9095_F1C673F4F101__INCLUDED_)
#define AFX_GEOLAYER_H__60DADB97_4413_46CB_9095_F1C673F4F101__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GeoObject.h"
#include "AtlasDoc.h"

class CAtlasDoc;
class CGeoObject;

class CGeoLayer  
{
public:
	CTypedPtrArray<CPtrArray, CGeoObject*> m_parGeoObject;
	CArray<CGeoObject*,CGeoObject*> objs;//����Ŀ�꣬Ĭ��Ϊͬ�ࣨ�㡢�ߡ��桢ע��֮һ��
	int m_LayerKeyNO;
	CString m_LayerName;   //����
	UINT m_uLayerType;//�����ͣ�1-�㣬2-�ߣ�3-�棬4-ע�ǣ�5-���������ϣ�դ��ר��ȣ�,-1-��ʼ��

public:
	void Initiate(UINT type,CString name);
	CGeoLayer(UINT type, CString name);
	LOGBRUSH SetLayerBrush();
	LOGPEN SetLayerPen();
	BOOL m_LayerEditable;
	BOOL m_LayerSelectable;
	BOOL m_LayerVisible;
	BOOL m_bIsShowVertex;
	void Draw(CDC *pDC);
	void Draw(CDC *pDC,CAtlasDoc *pDoc,int i);
	void SetGeoObject(CGeoObject *object);
	BOOL LayerEditable(int Editable);
	BOOL LayerSelectable(int Selectable);
	BOOL LayerVisible(int visible);
	void SetLayerKeyNO(int key);
	void SetLayerName(CString LayerName);
	CGeoLayer();
	virtual ~CGeoLayer();

private:
	LOGBRUSH m_brush;
	LOGPEN m_pen;
};

#endif // !defined(AFX_GEOLAYER_H__60DADB97_4413_46CB_9095_F1C673F4F101__INCLUDED_)
