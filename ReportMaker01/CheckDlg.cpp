// CheckDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ReportMaker01.h"
#include "CheckDlg.h"
#include "afxdialogex.h"
#include "ReportMaker01Doc.h"
#include "ReportMaker01.h"

// CCheckDlg 对话框

IMPLEMENT_DYNAMIC(CCheckDlg, CDialogEx)

CCheckDlg::CCheckDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCheckDlg::IDD, pParent)
{

}

CCheckDlg::~CCheckDlg()
{
}

void CCheckDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCheckDlg, CDialogEx)
END_MESSAGE_MAP()


// CCheckDlg 消息处理程序


BOOL CCheckDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	HomeStatic="主队：\n\n";
	AwayStatic="客队：\n\n";
	int homef=0;
	int awayf=0;
	HomeGoal=0;
	AwayGoal=0;
	HomePlayerNum=0;
	AwayPlayerNum=0;
	HomeProblem=FALSE;
	AwayProblem=FALSE;
	CString zaidi;
	CString noton;
	CString ison;
	CString off;
	CString on;
	CString yellow;
	CString twoy;
	CString red;
	CString yellowerr;
	CString twoyerr;
	CString goal;
	CString penalty;
	CString owng;
	CString penmiss;
	CString rederr;
	CString nogoal;
	CString nvzu;
	zaidi="在第";
	noton="不是场上球员\n\n";
	ison="已是场上球员\n\n";
	off="分钟被换下时";
	on="分钟被换上时";
	yellow="分钟得到黄牌时";
	twoy="分钟得到第二张黄牌时";
	red="分钟得到红牌时";
	goal="分钟进球时";
	penalty="分钟罚进点球时";
	owng="分钟打入乌龙球时";
	penmiss="分钟罚失点球时";
	yellowerr="已有一张黄牌，应选择两黄变一红选项\n\n";
	rederr="已被红牌罚下\n\n";
	twoyerr="并没有得到第一张黄牌\n\n";
	nogoal="没有进球\n\n";
	nvzu="马杯女足";

	for(int i=0;i<pDoc->HomePlayerNum;i++)//存入主队首发球员
	{
		if(pDoc->HomePlayers[i].IsFirst)
		{
			homef++;
			HomePlayerStats[HomePlayerNum].Player=pDoc->HomePlayers[i];
			HomePlayerStats[HomePlayerNum].OnPitch=TRUE;
			HomePlayerStats[HomePlayerNum].Red=0;
			HomePlayerStats[HomePlayerNum].TwoYellow=0;
			HomePlayerStats[HomePlayerNum].Yellow=0;
			HomePlayerStats[HomePlayerNum].Goal=0;
			HomePlayerStats[HomePlayerNum].Player.GetPlayerNameOutStr();
			HomePlayerNum++;
		}
	}

	for(int i=0;i<pDoc->AwayPlayerNum;i++)//存入客队首发球员
	{
		if(pDoc->AwayPlayers[i].IsFirst)
		{
			awayf++;
			AwayPlayerStats[AwayPlayerNum].Player=pDoc->AwayPlayers[i];
			AwayPlayerStats[AwayPlayerNum].OnPitch=TRUE;
			AwayPlayerStats[AwayPlayerNum].Red=0;
			AwayPlayerStats[AwayPlayerNum].TwoYellow=0;
			AwayPlayerStats[AwayPlayerNum].Yellow=0;
			AwayPlayerStats[AwayPlayerNum].Goal=0;
			AwayPlayerStats[AwayPlayerNum].Player.GetPlayerNameOutStr();
			AwayPlayerNum++;
		}
	}
	if(pDoc->GameName=="示例比赛")
	{
		HomeStatic+="请填写比赛名称\n\n";
		AwayStatic+="请填写比赛名称\n\n";
		HomeProblem=TRUE;
		AwayProblem=TRUE;
	}
	for(int i=0;i<pDoc->EventNum;i++)
	{
		EventInfo CurEvent;
		BOOL on1=FALSE;
		BOOL on2=FALSE;
		CurEvent=pDoc->Events[i];
		CurEvent.Player1.GetPlayerNameOutStr();
		CurEvent.Player2.GetPlayerNameOutStr();
		CurEvent.GetTime();
		if(CurEvent.IsHome)//主队事件
		{
			if(CurEvent.EventType==EVENT_GOAL)//进球
			{
				HomeGoal++;
				for(int j=0;j<HomePlayerNum;j++)
				{
					if(CurEvent.Player1.PlayerNameOutStr==HomePlayerStats[j].Player.PlayerNameOutStr)
					{
						on1=TRUE;
						HomePlayerStats[j].Goal++;
						if(!HomePlayerStats[j].OnPitch)
						{
							HomeStatic=HomeStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+goal+noton;
							HomeProblem=TRUE;
						}
					}
				}
				if(!on1)
				{
					HomeStatic=HomeStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+goal+noton;
					HomeProblem=TRUE;
				}
			}

			if(CurEvent.EventType==EVENT_PENALTY)//点球
			{
				HomeGoal++;
				for(int j=0;j<HomePlayerNum;j++)
				{
					if(CurEvent.Player1.PlayerNameOutStr==HomePlayerStats[j].Player.PlayerNameOutStr)
					{
						on1=TRUE;
						HomePlayerStats[j].Goal++;
						if(!HomePlayerStats[j].OnPitch)
						{
							HomeStatic=HomeStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+penalty+noton;
							HomeProblem=TRUE;
						}
					}
				}
				if(!on1)
				{
					HomeStatic=HomeStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+penalty+noton;
					HomeProblem=TRUE;
				}
			}

			if(CurEvent.EventType==EVENT_OWNGOAL)//乌龙球
			{
				AwayGoal++;
				for(int j=0;j<HomePlayerNum;j++)
				{
					if(CurEvent.Player1.PlayerNameOutStr==HomePlayerStats[j].Player.PlayerNameOutStr)
					{
						on1=TRUE;
						HomePlayerStats[j].Goal++;
						if(!HomePlayerStats[j].OnPitch)
						{
							HomeStatic=HomeStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+owng+noton;
							HomeProblem=TRUE;
						}
					}
				}
				if(!on1)
				{
					HomeStatic=HomeStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+owng+noton;
					HomeProblem=TRUE;
				}
			}

			if(CurEvent.EventType==EVENT_PENALTYMISS)//罚失点球
			{
				for(int j=0;j<HomePlayerNum;j++)
				{
					if(CurEvent.Player1.PlayerNameOutStr==HomePlayerStats[j].Player.PlayerNameOutStr)
					{
						on1=TRUE;
						if(!HomePlayerStats[j].OnPitch)
						{
							HomeStatic=HomeStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+penmiss+noton;
							HomeProblem=TRUE;
						}
					}
				}
				if(!on1)
				{
					HomeStatic=HomeStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+penmiss+noton;
					HomeProblem=TRUE;
				}
			}

			if(CurEvent.EventType==EVENT_SUBSTITUTION)//换人
			{
				for(int j=0;j<HomePlayerNum;j++)
				{
					if(CurEvent.Player1.PlayerNameOutStr==HomePlayerStats[j].Player.PlayerNameOutStr)
					{
						if(HomePlayerStats[j].OnPitch)
							HomePlayerStats[j].OnPitch=FALSE;
						else
						{
							HomeStatic=HomeStatic+HomePlayerStats[j].Player.PlayerNameOutStr+zaidi+CurEvent.Timestr+off+noton;
							HomeProblem=TRUE;
						}
						on1=TRUE;
					}

					if(CurEvent.Player2.PlayerNameOutStr==HomePlayerStats[j].Player.PlayerNameOutStr)
					{
						if(HomePlayerStats[j].OnPitch)
						{
							HomeStatic=HomeStatic+CurEvent.Player2.PlayerNameOutStr+zaidi+CurEvent.Timestr+on+ison;
							HomeProblem=TRUE;
						}
						else if(HomePlayerStats[j].Red==1)
						{
							HomeStatic=HomeStatic+CurEvent.Player2.PlayerNameOutStr+zaidi+CurEvent.Timestr+on+rederr;
							HomeProblem=TRUE;
						}
						else
							HomePlayerStats[j].OnPitch=TRUE;
						on2=TRUE;
					}

				}
				if(!on1)
				{
					HomeStatic=HomeStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+off+noton;
					HomeProblem=TRUE;
				}
				if(!on2)
				{
					HomePlayerStats[HomePlayerNum].Player=CurEvent.Player2;
					HomePlayerStats[HomePlayerNum].OnPitch=TRUE;
					HomePlayerStats[HomePlayerNum].Red=0;
					HomePlayerStats[HomePlayerNum].TwoYellow=0;
					HomePlayerStats[HomePlayerNum].Yellow=0;
					HomePlayerStats[HomePlayerNum].Goal=0;
					HomePlayerStats[HomePlayerNum].Player.GetPlayerNameOutStr();
					HomePlayerNum++;
				}
			}

			if(CurEvent.EventType==EVENT_YELLOW)//黄牌
			{
				for(int j=0;j<HomePlayerNum;j++)
				{
					if(CurEvent.Player1.PlayerNameOutStr==HomePlayerStats[j].Player.PlayerNameOutStr)
					{
						on1=TRUE;
						if(HomePlayerStats[j].Red==1)
						{
							HomeStatic=HomeStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+yellow+rederr;
							HomeProblem=TRUE;
						}
						else if(HomePlayerStats[j].Yellow==1)
						{
							HomeStatic=HomeStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+yellow+yellowerr;
							HomeProblem=TRUE;
						}
						else
						{
							HomePlayerStats[j].Yellow=1;
						}
					}
				}
				if(!on1)
				{
					HomePlayerStats[HomePlayerNum].Player=CurEvent.Player1;
					HomePlayerStats[HomePlayerNum].OnPitch=FALSE;
					HomePlayerStats[HomePlayerNum].Red=0;
					HomePlayerStats[HomePlayerNum].TwoYellow=0;
					HomePlayerStats[HomePlayerNum].Yellow=1;
					HomePlayerStats[HomePlayerNum].Goal=0;
					HomePlayerStats[HomePlayerNum].Player.GetPlayerNameOutStr();
					HomePlayerNum++;
				}
			}

			if(CurEvent.EventType==EVENT_TWOYELLOW)//两黄
			{
				for(int j=0;j<HomePlayerNum;j++)
				{
					if(CurEvent.Player1.PlayerNameOutStr==HomePlayerStats[j].Player.PlayerNameOutStr)
					{
						on1=TRUE;
						if(HomePlayerStats[j].OnPitch)
						{
							HomePlayerStats[j].OnPitch=FALSE;
						}
						if(HomePlayerStats[j].Red==1)
						{
							HomeStatic=HomeStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+red+rederr;
							HomeProblem=TRUE;
						}
						else if(HomePlayerStats[j].Yellow==0)
						{
							HomeStatic=HomeStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+twoy+twoyerr;
							HomeProblem=TRUE;
						}
						else
						{
							HomePlayerStats[j].Red=1;
							HomePlayerStats[j].Yellow=2;
						}
					}
				}
				if(!on1)
				{
					HomeStatic=HomeStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+twoy+twoyerr;
					HomeProblem=TRUE;
					HomePlayerStats[HomePlayerNum].Player=CurEvent.Player1;
					HomePlayerStats[HomePlayerNum].OnPitch=FALSE;
					HomePlayerStats[HomePlayerNum].Red=1;
					HomePlayerStats[HomePlayerNum].TwoYellow=0;
					HomePlayerStats[HomePlayerNum].Yellow=2;
					HomePlayerStats[HomePlayerNum].Goal=0;
					HomePlayerStats[HomePlayerNum].Player.GetPlayerNameOutStr();
					HomePlayerNum++;
				}
			}

			if(CurEvent.EventType==EVENT_RED)//红牌
			{
				for(int j=0;j<HomePlayerNum;j++)
				{
					if(CurEvent.Player1.PlayerNameOutStr==HomePlayerStats[j].Player.PlayerNameOutStr)
					{
						on1=TRUE;
						if(HomePlayerStats[j].OnPitch)
						{
							HomePlayerStats[j].OnPitch=FALSE;
						}
						if(HomePlayerStats[j].Red==0)
							HomePlayerStats[j].Red=1;
						else if(HomePlayerStats[j].Red==1)
						{
							HomeStatic=HomeStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+red+rederr;
							HomeProblem=TRUE;
						}
					}
				}
				if(!on1)
				{
					HomePlayerStats[HomePlayerNum].Player=CurEvent.Player1;
					HomePlayerStats[HomePlayerNum].OnPitch=FALSE;
					HomePlayerStats[HomePlayerNum].Red=1;
					HomePlayerStats[HomePlayerNum].TwoYellow=0;
					HomePlayerStats[HomePlayerNum].Yellow=0;
					HomePlayerStats[HomePlayerNum].Goal=0;
					HomePlayerStats[HomePlayerNum].Player.GetPlayerNameOutStr();
					HomePlayerNum++;
				}
			}
		}
		else//客队事件
		{
			if(CurEvent.EventType==EVENT_GOAL)//进球
			{
				AwayGoal++;
				for(int j=0;j<AwayPlayerNum;j++)
				{
					if(CurEvent.Player1.PlayerNameOutStr==AwayPlayerStats[j].Player.PlayerNameOutStr)
					{
						on1=TRUE;
						AwayPlayerStats[j].Goal++;
						if(!AwayPlayerStats[j].OnPitch)
						{
							AwayStatic=AwayStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+goal+noton;
							AwayProblem=TRUE;
						}
					}
				}
				if(!on1)
				{
					AwayStatic=AwayStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+goal+noton;
					AwayProblem=TRUE;
				}
			}

			if(CurEvent.EventType==EVENT_PENALTY)//点球
			{
				AwayGoal++;
				for(int j=0;j<AwayPlayerNum;j++)
				{
					if(CurEvent.Player1.PlayerNameOutStr==AwayPlayerStats[j].Player.PlayerNameOutStr)
					{
						on1=TRUE;
						AwayPlayerStats[j].Goal++;
						if(!AwayPlayerStats[j].OnPitch)
						{
							AwayStatic=AwayStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+penalty+noton;
							AwayProblem=TRUE;
						}
					}
				}
				if(!on1)
				{
					AwayStatic=AwayStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+penalty+noton;
					AwayProblem=TRUE;
				}
			}

			if(CurEvent.EventType==EVENT_OWNGOAL)//乌龙球
			{
				HomeGoal++;
				for(int j=0;j<AwayPlayerNum;j++)
				{
					if(CurEvent.Player1.PlayerNameOutStr==AwayPlayerStats[j].Player.PlayerNameOutStr)
					{
						on1=TRUE;
						AwayPlayerStats[j].Goal++;
						if(!AwayPlayerStats[j].OnPitch)
						{
							AwayStatic=AwayStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+owng+noton;
							AwayProblem=TRUE;
						}
					}
				}
				if(!on1)
				{
					AwayStatic=AwayStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+owng+noton;
					AwayProblem=TRUE;
				}
			}

			if(CurEvent.EventType==EVENT_PENALTYMISS)//罚失点球
			{
				for(int j=0;j<AwayPlayerNum;j++)
				{
					if(CurEvent.Player1.PlayerNameOutStr==AwayPlayerStats[j].Player.PlayerNameOutStr)
					{
						on1=TRUE;
						if(!AwayPlayerStats[j].OnPitch)
						{
							AwayStatic=AwayStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+penmiss+noton;
							AwayProblem=TRUE;
						}
					}
				}
				if(!on1)
				{
					AwayStatic=AwayStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+penmiss+noton;
					AwayProblem=TRUE;
				}
			}

			if(CurEvent.EventType==EVENT_SUBSTITUTION)//换人
			{
				for(int j=0;j<AwayPlayerNum;j++)
				{
					if(CurEvent.Player1.PlayerNameOutStr==AwayPlayerStats[j].Player.PlayerNameOutStr)
					{
						if(AwayPlayerStats[j].OnPitch)
							AwayPlayerStats[j].OnPitch=FALSE;
						else
						{
							AwayStatic=AwayStatic+AwayPlayerStats[j].Player.PlayerNameOutStr+zaidi+CurEvent.Timestr+off+noton;
							AwayProblem=TRUE;
						}
						on1=TRUE;
					}

					if(CurEvent.Player2.PlayerNameOutStr==AwayPlayerStats[j].Player.PlayerNameOutStr)
					{
						if(AwayPlayerStats[j].OnPitch)
						{
							AwayStatic=AwayStatic+CurEvent.Player2.PlayerNameOutStr+zaidi+CurEvent.Timestr+on+ison;
							AwayProblem=TRUE;
						}
						else if(AwayPlayerStats[j].Red==1)
						{
							AwayStatic=AwayStatic+CurEvent.Player2.PlayerNameOutStr+zaidi+CurEvent.Timestr+on+rederr;
							AwayProblem=TRUE;
						}
						else
							AwayPlayerStats[j].OnPitch=TRUE;
						on2=TRUE;
					}

				}
				if(!on1)
				{
					AwayStatic=AwayStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+off+noton;
					AwayProblem=TRUE;
				}
				if(!on2)
				{
					AwayPlayerStats[AwayPlayerNum].Player=CurEvent.Player2;
					AwayPlayerStats[AwayPlayerNum].OnPitch=TRUE;
					AwayPlayerStats[AwayPlayerNum].Red=0;
					AwayPlayerStats[AwayPlayerNum].TwoYellow=0;
					AwayPlayerStats[AwayPlayerNum].Yellow=0;
					AwayPlayerStats[AwayPlayerNum].Goal=0;
					AwayPlayerStats[AwayPlayerNum].Player.GetPlayerNameOutStr();
					AwayPlayerNum++;
				}
			}

			if(CurEvent.EventType==EVENT_YELLOW)//黄牌
			{
				for(int j=0;j<AwayPlayerNum;j++)
				{
					if(CurEvent.Player1.PlayerNameOutStr==AwayPlayerStats[j].Player.PlayerNameOutStr)
					{
						on1=TRUE;
						if(AwayPlayerStats[j].Red==1)
						{
							AwayStatic=AwayStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+yellow+rederr;
							AwayProblem=TRUE;
						}
						else if(AwayPlayerStats[j].Yellow==1)
						{
							AwayStatic=AwayStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+yellow+yellowerr;
							AwayProblem=TRUE;
						}
						else
						{
							AwayPlayerStats[j].Yellow=1;
						}
					}
				}
				if(!on1)
				{
					AwayPlayerStats[AwayPlayerNum].Player=CurEvent.Player1;
					AwayPlayerStats[AwayPlayerNum].OnPitch=FALSE;
					AwayPlayerStats[AwayPlayerNum].Red=0;
					AwayPlayerStats[AwayPlayerNum].TwoYellow=0;
					AwayPlayerStats[AwayPlayerNum].Yellow=1;
					AwayPlayerStats[AwayPlayerNum].Goal=0;
					AwayPlayerStats[AwayPlayerNum].Player.GetPlayerNameOutStr();
					AwayPlayerNum++;
				}
			}

			if(CurEvent.EventType==EVENT_TWOYELLOW)//两黄
			{
				for(int j=0;j<AwayPlayerNum;j++)
				{
					if(CurEvent.Player1.PlayerNameOutStr==AwayPlayerStats[j].Player.PlayerNameOutStr)
					{
						on1=TRUE;
						if(AwayPlayerStats[j].OnPitch)
						{
							AwayPlayerStats[j].OnPitch=FALSE;
						}
						if(AwayPlayerStats[j].Red==1)
						{
							AwayStatic=AwayStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+red+rederr;
							AwayProblem=TRUE;
						}
						else if(AwayPlayerStats[j].Yellow==0)
						{
							AwayStatic=AwayStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+twoy+twoyerr;
							AwayProblem=TRUE;
						}
						else
						{
							AwayPlayerStats[j].Red=1;
							AwayPlayerStats[j].Yellow=2;
						}
					}
				}
				if(!on1)
				{
					AwayStatic=AwayStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+twoy+twoyerr;
					AwayProblem=TRUE;
					AwayPlayerStats[AwayPlayerNum].Player=CurEvent.Player1;
					AwayPlayerStats[AwayPlayerNum].OnPitch=FALSE;
					AwayPlayerStats[AwayPlayerNum].Red=1;
					AwayPlayerStats[AwayPlayerNum].TwoYellow=0;
					AwayPlayerStats[AwayPlayerNum].Yellow=2;
					AwayPlayerStats[AwayPlayerNum].Goal=0;
					AwayPlayerStats[AwayPlayerNum].Player.GetPlayerNameOutStr();
					AwayPlayerNum++;
				}
			}

			if(CurEvent.EventType==EVENT_RED)//红牌
			{
				for(int j=0;j<AwayPlayerNum;j++)
				{
					if(CurEvent.Player1.PlayerNameOutStr==AwayPlayerStats[j].Player.PlayerNameOutStr)
					{
						on1=TRUE;
						if(AwayPlayerStats[j].OnPitch)
						{
							AwayPlayerStats[j].OnPitch=FALSE;
						}
						if(AwayPlayerStats[j].Red==0)
							AwayPlayerStats[j].Red=1;
						else if(AwayPlayerStats[j].Red==1)
						{
							AwayStatic=AwayStatic+CurEvent.Player1.PlayerNameOutStr+zaidi+CurEvent.Timestr+red+rederr;
							AwayProblem=TRUE;
						}
					}
				}
				if(!on1)
				{
					AwayPlayerStats[AwayPlayerNum].Player=CurEvent.Player1;
					AwayPlayerStats[AwayPlayerNum].OnPitch=FALSE;
					AwayPlayerStats[AwayPlayerNum].Red=1;
					AwayPlayerStats[AwayPlayerNum].TwoYellow=0;
					AwayPlayerStats[AwayPlayerNum].Yellow=0;
					AwayPlayerStats[AwayPlayerNum].Goal=0;
					AwayPlayerStats[AwayPlayerNum].Player.GetPlayerNameOutStr();
					AwayPlayerNum++;
				}
			}
		}
	}
	if(HomeGoal!=AwayGoal && pDoc->IsPenalty)
	{
		HomeStatic+="非平局的比赛不能出现点球决胜\n\n";
		AwayStatic+="非平局的比赛不能出现点球决胜\n\n";
		HomeProblem=TRUE;
		AwayProblem=TRUE;
	}
	for(int k=0;k<HomePlayerNum;k++)
	{
		if(HomePlayerStats[k].Player.PlayerName=="冈嫱")
		{
			if(HomePlayerStats[k].Goal==0)
			{
				HomeStatic=HomeStatic+HomePlayerStats[k].Player.PlayerNameOutStr+nogoal;
			}
			if(HomePlayerStats[k].Goal>=3 && pDoc->HomeName=="自动化系" && pDoc->GameName>nvzu && HomePlayerStats[k].Player.PlayerNumber==99 && homef==7 && awayf==7)
			{
				HomeStatic+="嫱哥我爱你！\n\n";
			}
		}
	}
	for(int k=0;k<AwayPlayerNum;k++)
	{
		if(AwayPlayerStats[k].Player.PlayerName=="冈嫱")
		{
			if(AwayPlayerStats[k].Goal==0)
			{
				AwayStatic=AwayStatic+AwayPlayerStats[k].Player.PlayerNameOutStr+nogoal;
			}
			if(AwayPlayerStats[k].Goal>=3 && pDoc->AwayName=="自动化系" && pDoc->GameName>nvzu && AwayPlayerStats[k].Player.PlayerNumber==99 && homef==7 && awayf==7)
			{
				AwayStatic+="嫱哥我爱你！\n\n";
			}
		}
	}
	if(!HomeProblem)
		HomeStatic+="没有问题！";
	if(!AwayProblem)
		AwayStatic+="没有问题！";
	GetDlgItem(IDC_HOME_STATIC)->SetWindowTextW(HomeStatic);
	GetDlgItem(IDC_AWAY_STATIC)->SetWindowTextW(AwayStatic);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
