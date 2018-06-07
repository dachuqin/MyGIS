// GeoMap.h: interface for the CGeoMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GEOMAP_H__D71648FD_9D37_4412_A52D_64A53D693ABC__INCLUDED_)
#define AFX_GEOMAP_H__D71648FD_9D37_4412_A52D_64A53D693ABC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GeoLayer.h"
#include "AtlasDoc.h"

class CAtlasDoc;
class CGeoLayer;

class CGeoMap  
{
private:
	
	int m_LayerNum;
	RECT m_MapExtent;//CRect Or RECT
	CString m_strMapName;  //图名，载入地图时取文件名作图名
public:
	int GetLayerNumByName(CString str);
	void ChangeLayerOrder(CString str1, CString str2);
	void DrawMap(CDC *pDC,CAtlasDoc *pDoc);
	CGeoLayer * GetLayer(int i);
	int GetLayerNum();
	void SetLayer(CGeoLayer *layer);
	void SetLayerNum(int LayerNum);
	void SetMapBoundary(CRect MapExtent);
	void SetMapName(CString &MapName);
	CGeoMap();
	virtual ~CGeoMap();
public:
	void Draw(CDC *pDC);
	void DeleteLayer(UINT del);
	void SelEditableLayer(UINT edit);
	void AddLayer(UINT add, CGeoLayer *layer);
	void AddLayer(CGeoLayer *layer);
	/*CArray<CGeoLayer*,CGeoLayer*> layers;//图层*/
	CGeoLayer *m_EditableLayer;//可编辑图层
	CTypedPtrArray<CPtrArray, CGeoLayer*> m_parLayer;
	

};

#endif // !defined(AFX_GEOMAP_H__D71648FD_9D37_4412_A52D_64A53D693ABC__INCLUDED_)
