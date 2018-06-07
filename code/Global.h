// Global.h: interface for the CGlobal class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLOBAL_H__0B3EC9D3_819E_49E9_B7D5_18EAA4C70710__INCLUDED_)
#define AFX_GLOBAL_H__0B3EC9D3_819E_49E9_B7D5_18EAA4C70710__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGlobal  
{
public:
	int nDataStructure; //1 DXF文件 ， 2 CW文件，3其他类型文件
	CGlobal();
	virtual ~CGlobal();


};
extern CGlobal MyApp;
#endif // !defined(AFX_GLOBAL_H__0B3EC9D3_819E_49E9_B7D5_18EAA4C70710__INCLUDED_)
