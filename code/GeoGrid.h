// GeoGrid.h: interface for the CGeoGrid class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GEOGRID_H__B11BCC54_BB28_4822_BAFF_84244CB15DD4__INCLUDED_)
#define AFX_GEOGRID_H__B11BCC54_BB28_4822_BAFF_84244CB15DD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
using namespace std;
class CGeoGridAttri
{
public:
	CString m_nType;		//表示当前记录地物的类型
	int m_nLyerIndex;	//地物所在的层的索引号
	int m_nPtIndex;		//地物在所在层内的索引号
};
class CGeoGrid  
{
public:
	CGeoGrid();
    virtual ~CGeoGrid();
   vector<CGeoGridAttri> m_vecGeoGdAtt;//当前格网内某地物信息，用来索引该地物


};

#endif // !defined(AFX_GEOGRID_H__B11BCC54_BB28_4822_BAFF_84244CB15DD4__INCLUDED_)
