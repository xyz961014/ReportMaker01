
// ReportMaker01View.h : CReportMaker01View ��Ľӿ�
//

#pragma once
#include "ReportMaker01Doc.h"


class CReportMaker01View : public CScrollView
{
protected: // �������л�����
	CReportMaker01View();
	DECLARE_DYNCREATE(CReportMaker01View)

// ����
public:
	CReportMaker01Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CReportMaker01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	
	virtual void OnInitialUpdate();
	int Y;
	int LineLoc;//����x����
	afx_msg void OnSavepic();
	int HomeGoal;//���ӵ÷�
	int AwayGoal;//�Ͷӵ÷�
	CString Score;//�ȷ��ַ���
	afx_msg void OnFormat();

};

#ifndef _DEBUG  // ReportMaker01View.cpp �еĵ��԰汾
inline CReportMaker01Doc* CReportMaker01View::GetDocument() const
   { return reinterpret_cast<CReportMaker01Doc*>(m_pDocument); }
#endif

