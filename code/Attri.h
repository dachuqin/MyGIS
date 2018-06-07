// Attri.h: interface for the CAttri class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ATTRI_H__26B3FD05_A94C_4BB8_9FEF_CBA12867F66D__INCLUDED_)
#define AFX_ATTRI_H__26B3FD05_A94C_4BB8_9FEF_CBA12867F66D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAttri  
{
public:
	void SetPenWidth(const LONG pen_width);
	void SetBrushStyle(const UINT brush_style);
	void SetPenStyle(const UINT pen_style);
	void SetBrushColor(UINT r,UINT g,UINT b);
	void SetPenColor(UINT r,UINT g,UINT b);
	void SetID(const int  id);
	void SetLayerName(const CString &);
	CAttri();
	virtual ~CAttri();
	//获取属性信息
    CString GetLayerName()
	{return m_LayerName;}
	int GetID()
	{return m_ID;}
	COLORREF GetPenColor()
	{return m_PenColor;}
	COLORREF GetBrushColor()
	{return m_BrushColor;}
	UINT GetPenStyle()
	{return m_PenStyle;}
	UINT GetBrushStyle()
	{return m_BrushStyle;}
	POINT GetPenWidth()
	{return m_PenWidth;}

private:
	CString m_LayerName;  //图层名
	int m_ID;
	COLORREF m_PenColor;
	COLORREF m_BrushColor;
	UINT m_PenStyle;
	UINT m_BrushStyle;
	POINT m_PenWidth;
};

#endif // !defined(AFX_ATTRI_H__26B3FD05_A94C_4BB8_9FEF_CBA12867F66D__INCLUDED_)
