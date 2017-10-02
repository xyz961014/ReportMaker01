
// ReportMaker01Doc.h : CReportMaker01Doc 类的接口
//


#pragma once
#include "FirstElevenDlg.h"
#include "EventDlg.h"


class CReportMaker01Doc : public CDocument
{
protected: // 仅从序列化创建
	CReportMaker01Doc();
	DECLARE_DYNCREATE(CReportMaker01Doc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CReportMaker01Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	PlayerInfo HomePlayers[50];//主队球员
	PlayerInfo AwayPlayers[50];//客队球员
	EventInfo Events[200];//事件
	CString HomeName;//主队名称
	CString AwayName;//客队名称
	CFirstElevenDlg DlgFirstEleven;//首发球员对话框
	CEventDlg DlgEvent;//事件对话框
	int HomePlayerPt;//主队球员标记
	int HomePlayerNum;//主队球员人数
	int AwayPlayerPt;//客队球员标记
	int AwayPlayerNum;//客队球员人数
	int EventPt;//事件标记
	int EventNum;//事件数
	PenaltyShootout HomePenalty[50];
	PenaltyShootout AwayPenalty[50];
	BOOL IsPenalty;
	CString GameName;

	
	afx_msg void OnFirsteleven();
	afx_msg void OnEvent();
	
	void SortEvent(void);
	afx_msg void OnDraw();
	afx_msg void OnGamename();
	afx_msg void OnPenalty();
	int HomePenaltyNum;
	int AwayPenaltyNum;
	int PenaltyTime;
	int linered,linegreen,lineblue;
	LPCSTR strtitle,strname,strfirst,strtext;
	afx_msg void OnPlayer();
	afx_msg void OnCheck();
};
