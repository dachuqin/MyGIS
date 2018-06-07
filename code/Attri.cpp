// Attri.cpp: implementation of the CAttri class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Atlas.h"
#include "Attri.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAttri::CAttri()
{
	m_LayerName = "";
	m_ID = 0;
	m_PenColor = RGB(0, 0, 0);
	m_PenStyle = PS_SOLID;
	m_PenWidth.x = 1;
	m_BrushStyle = BS_HOLLOW;
	m_BrushColor = RGB(255,255,255);

}

CAttri::~CAttri()
{

}

void CAttri::SetLayerName(const CString &layer_name)
{
	m_LayerName=layer_name;
}

void CAttri::SetID(const int id)
{
    m_ID=id;
}

void CAttri::SetPenColor(UINT r, UINT g, UINT b)
{ 
	m_PenColor=RGB(r,g,b);

}

void CAttri::SetBrushColor(UINT r, UINT g, UINT b)
{
   m_BrushColor=RGB(r,g,b);
}

void CAttri::SetPenStyle(const UINT pen_style)
{
    m_PenStyle=pen_style;
}

void CAttri::SetBrushStyle(const UINT brush_style)
{
    m_BrushStyle=brush_style;
}

void CAttri::SetPenWidth(const LONG pen_width)
{
   m_PenWidth.x=pen_width;
}
