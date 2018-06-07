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
	bool m_bIsEditable;   //ͼ���Ƿ�ɱ༭��1����༭��0�����༭
public:
	void SetColor(CDC *pDC,COLORREF colorref);  //������ɫ
	void SetLayerEditable(bool editable);
	void SetLayerSelectable(bool selectable);
	void SetDisplay(bool bDispaly);
	bool GetLayerEditable( );
	bool GetLayerSelectable( );
	bool GetDisplay( );
	void SetLayerName(CString strName);
	CString GetLayerName( );
	void SetLayerType(UINT layer_type)  //����ͼ������
	{
        m_nLayerType=layer_type;
	}
	int GetLayerType()   //��ȡͼ������
	{
		return m_nLayerType;
	}
	int GetGeoObjectNum( )
	{
		return  m_parGeoObject.GetSize( );   //��ô洢�Ķ�������
	}
	CGeoObject* GetGeoObject(UINT i){return m_parGeoObject.GetAt(i);}	//ͨ�������������ö���
	void SetGeoObject(CGeoObject *object); 
	int m_nLayerType;  //ͼ�����ͣ�1����㣬2�����ߣ�3�����棬4����ע�ǣ�5�����ϣ�-1�����ʼ��
	CString m_strName;  //ͼ������
	bool  m_bDisplay;    //ͼ���Ƿ�ɼ���1��ʾ�ɼ��� 0��ʾ����
	bool m_bIsSelectable; //ͼ���Ƿ��ѡ��1�����ѡ��0������ѡ
	CLayer();
	virtual ~CLayer();
public:
	
	virtual void Draw(CDC *pDC,CAtlasDoc *pDoc)=0;
	virtual void Save(FILE *fp)=0;
	virtual void Draw(CDC *pDC)=0;  // ��������ɫ



};

#endif // !defined(AFX_LAYER_H__7F59A0AB_B25D_4A85_B13F_947A5A80B1FD__INCLUDED_)
