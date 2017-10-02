
// ReportMaker01Doc.cpp : CReportMaker01Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ReportMaker01.h"
#include "GameNameDlg.h"
#include "Penalty.h"
#include "PlayerDlg.h"
#include "CheckDlg.h"

#endif

#include "ReportMaker01Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CReportMaker01Doc

IMPLEMENT_DYNCREATE(CReportMaker01Doc, CDocument)

BEGIN_MESSAGE_MAP(CReportMaker01Doc, CDocument)
	
	ON_COMMAND(ID_FIRSTELEVEN, &CReportMaker01Doc::OnFirsteleven)
	ON_COMMAND(ID_EVENT, &CReportMaker01Doc::OnEvent)
	ON_COMMAND(ID_DRAW, &CReportMaker01Doc::OnDraw)
	ON_COMMAND(ID_GAMENAME, &CReportMaker01Doc::OnGamename)
	ON_COMMAND(ID_PENALTY, &CReportMaker01Doc::OnPenalty)
	ON_COMMAND(ID_PLAYER, &CReportMaker01Doc::OnPlayer)
	ON_COMMAND(ID_CHECK, &CReportMaker01Doc::OnCheck)
END_MESSAGE_MAP()


// CReportMaker01Doc 构造/析构

CReportMaker01Doc::CReportMaker01Doc()
	: HomePenaltyNum(0)
	, AwayPenaltyNum(0)
	, PenaltyTime(0)
{
	// TODO: 在此添加一次性构造代码

}

CReportMaker01Doc::~CReportMaker01Doc()
{
}

BOOL CReportMaker01Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	HomePlayerPt=0;
	HomePlayerNum=0;
	AwayPlayerPt=0;
	AwayPlayerNum=0;
	EventPt=0;
	EventNum=0;
	HomeName="主队";
	AwayName="客队";
	SetTitle(_T("ReportMaker"));
	GameName="示例比赛";
	IsPenalty=FALSE;
	linered=90;
	linegreen=90;
	lineblue=90;
	strtitle="黑体";
	strname="仿宋";
	strfirst="微软雅黑";
	strtext="宋体";
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CReportMaker01Doc 序列化

void CReportMaker01Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		int i;
		ar<<HomeName;
		ar<<AwayName;
		ar<<HomePlayerNum;
		ar<<HomePlayerPt;
		ar<<AwayPlayerNum;
		ar<<AwayPlayerPt;
		ar<<EventNum;
		ar<<EventPt;
		ar<<GameName;
		for(i=0;i<HomePlayerNum;i++)
		{
			ar<<HomePlayers[i].IsFirst;
			ar<<HomePlayers[i].IsPlayerNumber;
			ar<<HomePlayers[i].PlayerExtra;
			ar<<HomePlayers[i].PlayerName;
			ar<<HomePlayers[i].PlayerNameOutStr;
			ar<<HomePlayers[i].PlayerNumber;
		}
		for(i=0;i<AwayPlayerNum;i++)
		{
			ar<<AwayPlayers[i].IsFirst;
			ar<<AwayPlayers[i].IsPlayerNumber;
			ar<<AwayPlayers[i].PlayerExtra;
			ar<<AwayPlayers[i].PlayerName;
			ar<<AwayPlayers[i].PlayerNameOutStr;
			ar<<AwayPlayers[i].PlayerNumber;
		}
		for(i=0;i<EventNum;i++)
		{
			ar<<Events[i].EventListOutStr;
			ar<<Events[i].EventType;
			ar<<Events[i].IsHome;
			ar<<Events[i].Player1.IsFirst;
			ar<<Events[i].Player1.IsPlayerNumber;
			ar<<Events[i].Player1.PlayerExtra;
			ar<<Events[i].Player1.PlayerName;
			ar<<Events[i].Player1.PlayerNameOutStr;
			ar<<Events[i].Player1.PlayerNumber;
			ar<<Events[i].Player2.IsFirst;
			ar<<Events[i].Player2.IsPlayerNumber;
			ar<<Events[i].Player2.PlayerExtra;
			ar<<Events[i].Player2.PlayerName;
			ar<<Events[i].Player2.PlayerNameOutStr;
			ar<<Events[i].Player2.PlayerNumber;
			ar<<Events[i].StoppageTime;
			ar<<Events[i].Time;
			ar<<Events[i].Timestr;

		}

		ar<<IsPenalty;
		ar<<HomePenaltyNum;
		ar<<AwayPenaltyNum;
		ar<<PenaltyTime;
		for(i=0;i<HomePenaltyNum;i++)
		{
			ar<<HomePenalty[i].IsGoal;
			ar<<HomePenalty[i].ListOutstr;
			ar<<HomePenalty[i].Player.IsFirst;
			ar<<HomePenalty[i].Player.IsPlayerNumber;
			ar<<HomePenalty[i].Player.PlayerExtra;
			ar<<HomePenalty[i].Player.PlayerName;
			ar<<HomePenalty[i].Player.PlayerNameOutStr;
			ar<<HomePenalty[i].Player.PlayerNumber;
		}
		for(i=0;i<AwayPenaltyNum;i++)
		{
			ar<<AwayPenalty[i].IsGoal;
			ar<<AwayPenalty[i].ListOutstr;
			ar<<AwayPenalty[i].Player.IsFirst;
			ar<<AwayPenalty[i].Player.IsPlayerNumber;
			ar<<AwayPenalty[i].Player.PlayerExtra;
			ar<<AwayPenalty[i].Player.PlayerName;
			ar<<AwayPenalty[i].Player.PlayerNameOutStr;
			ar<<AwayPenalty[i].Player.PlayerNumber;
		}

	}
	else
	{
		// TODO: 在此添加加载代码
		int i;
		ar>>HomeName;
		ar>>AwayName;
		ar>>HomePlayerNum;
		ar>>HomePlayerPt;
		ar>>AwayPlayerNum;
		ar>>AwayPlayerPt;
		ar>>EventNum;
		ar>>EventPt;
		ar>>GameName;
		for(i=0;i<HomePlayerNum;i++)
		{
			ar>>HomePlayers[i].IsFirst;
			ar>>HomePlayers[i].IsPlayerNumber;
			ar>>HomePlayers[i].PlayerExtra;
			ar>>HomePlayers[i].PlayerName;
			ar>>HomePlayers[i].PlayerNameOutStr;
			ar>>HomePlayers[i].PlayerNumber;
		}
		for(i=0;i<AwayPlayerNum;i++)
		{
			ar>>AwayPlayers[i].IsFirst;
			ar>>AwayPlayers[i].IsPlayerNumber;
			ar>>AwayPlayers[i].PlayerExtra;
			ar>>AwayPlayers[i].PlayerName;
			ar>>AwayPlayers[i].PlayerNameOutStr;
			ar>>AwayPlayers[i].PlayerNumber;
		}
		for(i=0;i<EventNum;i++)
		{
			ar>>Events[i].EventListOutStr;
			ar>>Events[i].EventType;
			ar>>Events[i].IsHome;
			ar>>Events[i].Player1.IsFirst;
			ar>>Events[i].Player1.IsPlayerNumber;
			ar>>Events[i].Player1.PlayerExtra;
			ar>>Events[i].Player1.PlayerName;
			ar>>Events[i].Player1.PlayerNameOutStr;
			ar>>Events[i].Player1.PlayerNumber;
			ar>>Events[i].Player2.IsFirst;
			ar>>Events[i].Player2.IsPlayerNumber;
			ar>>Events[i].Player2.PlayerExtra;
			ar>>Events[i].Player2.PlayerName;
			ar>>Events[i].Player2.PlayerNameOutStr;
			ar>>Events[i].Player2.PlayerNumber;
			ar>>Events[i].StoppageTime;
			ar>>Events[i].Time;
			ar>>Events[i].Timestr;

		}

		ar>>IsPenalty;
		ar>>HomePenaltyNum;
		ar>>AwayPenaltyNum;
		ar>>PenaltyTime;
		for(i=0;i<HomePenaltyNum;i++)
		{
			ar>>HomePenalty[i].IsGoal;
			ar>>HomePenalty[i].ListOutstr;
			ar>>HomePenalty[i].Player.IsFirst;
			ar>>HomePenalty[i].Player.IsPlayerNumber;
			ar>>HomePenalty[i].Player.PlayerExtra;
			ar>>HomePenalty[i].Player.PlayerName;
			ar>>HomePenalty[i].Player.PlayerNameOutStr;
			ar>>HomePenalty[i].Player.PlayerNumber;
		}
		for(i=0;i<AwayPenaltyNum;i++)
		{
			ar>>AwayPenalty[i].IsGoal;
			ar>>AwayPenalty[i].ListOutstr;
			ar>>AwayPenalty[i].Player.IsFirst;
			ar>>AwayPenalty[i].Player.IsPlayerNumber;
			ar>>AwayPenalty[i].Player.PlayerExtra;
			ar>>AwayPenalty[i].Player.PlayerName;
			ar>>AwayPenalty[i].Player.PlayerNameOutStr;
			ar>>AwayPenalty[i].Player.PlayerNumber;
		}

	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CReportMaker01Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CReportMaker01Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CReportMaker01Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CReportMaker01Doc 诊断

#ifdef _DEBUG
void CReportMaker01Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CReportMaker01Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CReportMaker01Doc 命令




void CReportMaker01Doc::OnFirsteleven()
{
	// TODO: 在此添加命令处理程序代码
	DlgFirstEleven.DoModal();
	
	
}


void CReportMaker01Doc::OnEvent()
{
	// TODO: 在此添加命令处理程序代码
	DlgEvent.DoModal();
}












void CReportMaker01Doc::SortEvent(void)
{
	int i=0,j=0;
	EventInfo Temp;
	for(i=0;i<EventNum;i++)
	{
		for(j=0;j<EventNum-i-1;j++)
		{
			if(Events[j].Time>Events[j+1].Time)
			{
				Temp=Events[j];
				Events[j]=Events[j+1];
				Events[j+1]=Temp;
			}
			else if(Events[j].Time==Events[j+1].Time)
			{
				if(Events[j].StoppageTime>Events[j+1].StoppageTime)
				{
					Temp=Events[j];
				    Events[j]=Events[j+1];
					Events[j+1]=Temp;
				}
			}
		}
	}
}


void CReportMaker01Doc::OnDraw()
{
	// TODO: 在此添加命令处理程序代码
	UpdateAllViews(NULL);
}


void CReportMaker01Doc::OnGamename()
{
	// TODO: 在此添加命令处理程序代码
	CGameNameDlg Dlg;
	if(Dlg.DoModal()==IDOK)
		UpdateAllViews(NULL);
}


void CReportMaker01Doc::OnPenalty()
{
	// TODO: 在此添加命令处理程序代码
	if(HomePlayerNum!=0 && AwayPlayerNum!=0)
	{
	CPenalty DlgPenalty;
	DlgPenalty.DoModal();
	}
	else
		AfxMessageBox(_T("请先输入球员信息！"));
}


void CReportMaker01Doc::OnPlayer()
{
	// TODO: 在此添加命令处理程序代码
	CPlayerDlg DlgPlayer;
	DlgPlayer.DoModal();
}


void CReportMaker01Doc::OnCheck()
{
	// TODO: 在此添加命令处理程序代码
	CCheckDlg DlgCheck;
	DlgCheck.DoModal();
}
