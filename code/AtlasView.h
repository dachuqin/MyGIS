// AtlasView.h : interface of the CAtlasView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ATLASVIEW_H__A99C6113_3ADF_4196_8305_55F912B3EFBB__INCLUDED_)
#define AFX_ATLASVIEW_H__A99C6113_3ADF_4196_8305_55F912B3EFBB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAtlasView : public CView
{
protected: // create from serialization only
	CAtlasView();
	DECLARE_DYNCREATE(CAtlasView)

// Attributes
public:
	//�ж��Ƿ���ص�ͼ
	BOOL m_bIsLoadMap;

	//��ͼԭʼ��Χ
	CRect m_rtMapRange;
	
	//��ǰ��ͼ��Χ��ӳ�䵽��Ļ�ķ�Χ  �߼�����
	CRect m_rCurWinScope;

	//������ͼ��������
	float m_fScaleCtrl;

	//�����Ϣ
	long m_lCurMess;

	CGeoLayer *pLayer;//ָ��ɱ༭ͼ��

	UINT m_uSelectedTool;//��ѡ��ı༭����0 1 2 3 4 5 6

	//��������ξ���
	CRect m_rtZoom;

	//����һ�ΰ���
	BOOL m_bFirstPoint;
	BOOL b_Condition;//�Ӳ�״̬

	//���ڼ�¼�������ɵ�ͼ�����������������
	CArray<CPoint,CPoint> pts;

	CPoint m_ptStart,m_ptOld;

	CAtlasDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAtlasView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void ShowDistance(CPoint pt);
	void ShowArea();
	void ScopeChange(float scale,CPoint pt);
	virtual ~CAtlasView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnContextMenu(CWnd*, CPoint point);
	//{{AFX_MSG(CAtlasView)
	afx_msg void OnDataTransDlg();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnMenuFullmap();
	afx_msg void OnMenuZoomout();
	afx_msg void OnMenuZoomin();
	afx_msg void OnMenuPan();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMenuZoominByrect();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMenuDistance();
	afx_msg void OnMenuArea();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMenuLayermanage();
	afx_msg void OnMenuAnno();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AtlasView.cpp
inline CAtlasDoc* CAtlasView::GetDocument()
   { return (CAtlasDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATLASVIEW_H__A99C6113_3ADF_4196_8305_55F912B3EFBB__INCLUDED_)
