
// ReportMaker01View.h : CReportMaker01View 类的接口
//

#pragma once
#include "ReportMaker01Doc.h"


class CReportMaker01View : public CScrollView
{
protected: // 仅从序列化创建
	CReportMaker01View();
	DECLARE_DYNCREATE(CReportMaker01View)

// 特性
public:
	CReportMaker01Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CReportMaker01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	
	virtual void OnInitialUpdate();
	int Y;
	int LineLoc;//中线x坐标
	afx_msg void OnSavepic();
	int HomeGoal;//主队得分
	int AwayGoal;//客队得分
	CString Score;//比分字符串
	afx_msg void OnFormat();

};

#ifndef _DEBUG  // ReportMaker01View.cpp 中的调试版本
inline CReportMaker01Doc* CReportMaker01View::GetDocument() const
   { return reinterpret_cast<CReportMaker01Doc*>(m_pDocument); }
#endif

