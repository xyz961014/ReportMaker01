
// ReportMaker01Doc.h : CReportMaker01Doc ��Ľӿ�
//


#pragma once
#include "FirstElevenDlg.h"
#include "EventDlg.h"


class CReportMaker01Doc : public CDocument
{
protected: // �������л�����
	CReportMaker01Doc();
	DECLARE_DYNCREATE(CReportMaker01Doc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CReportMaker01Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	PlayerInfo HomePlayers[50];//������Ա
	PlayerInfo AwayPlayers[50];//�Ͷ���Ա
	EventInfo Events[200];//�¼�
	CString HomeName;//��������
	CString AwayName;//�Ͷ�����
	CFirstElevenDlg DlgFirstEleven;//�׷���Ա�Ի���
	CEventDlg DlgEvent;//�¼��Ի���
	int HomePlayerPt;//������Ա���
	int HomePlayerNum;//������Ա����
	int AwayPlayerPt;//�Ͷ���Ա���
	int AwayPlayerNum;//�Ͷ���Ա����
	int EventPt;//�¼����
	int EventNum;//�¼���
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
