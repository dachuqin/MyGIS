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
	CString m_nType;		//��ʾ��ǰ��¼���������
	int m_nLyerIndex;	//�������ڵĲ��������
	int m_nPtIndex;		//���������ڲ��ڵ�������
};
class CGeoGrid  
{
public:
	CGeoGrid();
    virtual ~CGeoGrid();
   vector<CGeoGridAttri> m_vecGeoGdAtt;//��ǰ������ĳ������Ϣ�����������õ���


};

#endif // !defined(AFX_GEOGRID_H__B11BCC54_BB28_4822_BAFF_84244CB15DD4__INCLUDED_)
