// Layer.h: interface for the CLayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAYER_H__7F59A0AB_B25D_4A85_B13F_947A5A80B1FD__INCLUDED_)
#define AFX_LAYER_H__7F59A0AB_B25D_4A85_B13F_947A5A80B1FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Atlas.h"
#include "StdAfx.h"
#include "GeoObject.h"
#include "AtlasDoc.h"
class CAtlasDoc;
class CGeoObject;
class CLayer  
{
protected:
	CTypedPtrArray<CPtrArray,CGeoObject*> m_parGeoObject;
	bool m_bIsEditable;   //图层是否可编辑，1代表编辑，0代表不编辑
public:
	void SetColor(CDC *pDC,COLORREF colorref);  //设置颜色
	void SetLayerEditable(bool editable);
	void SetLayerSelectable(bool selectable);
	void SetDisplay(bool bDispaly);
	bool GetLayerEditable( );
	bool GetLayerSelectable( );
	bool GetDisplay( );
	void SetLayerName(CString strName);
	CString GetLayerName( );
	void SetLayerType(UINT layer_type)  //设置图层类型
	{
        m_nLayerType=layer_type;
	}
	int GetLayerType()   //获取图层类型
	{
		return m_nLayerType;
	}
	int GetGeoObjectNum( )
	{
		return  m_parGeoObject.GetSize( );   //获得存储的对象总数
	}
	CGeoObject* GetGeoObject(UINT i){return m_parGeoObject.GetAt(i);}	//通过对象的索引获得对象
	void SetGeoObject(CGeoObject *object); 
	int m_nLayerType;  //图层类型，1代表点，2代表线，3代表面，4代表注记，5代表复合，-1代表初始化
	CString m_strName;  //图层名称
	bool  m_bDisplay;    //图层是否可见，1表示可见， 0表示隐藏
	bool m_bIsSelectable; //图层是否可选，1代表可选，0代表不可选
	CLayer();
	virtual ~CLayer();
public:
	
	virtual void Draw(CDC *pDC,CAtlasDoc *pDoc)=0;
	virtual void Save(FILE *fp)=0;
	virtual void Draw(CDC *pDC)=0;  // 设置颜色



};

#endif // !defined(AFX_LAYER_H__7F59A0AB_B25D_4A85_B13F_947A5A80B1FD__INCLUDED_)
