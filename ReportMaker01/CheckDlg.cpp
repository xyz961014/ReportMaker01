// CheckDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ReportMaker01.h"
#include "CheckDlg.h"
#include "afxdialogex.h"
#include "ReportMaker01Doc.h"
#include "ReportMaker01.h"

// CCheckDlg �Ի���

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


// CCheckDlg ��Ϣ�������


BOOL CCheckDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	HomeStatic="���ӣ�\n\n";
	AwayStatic="�Ͷӣ�\n\n";
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
	zaidi="�ڵ�";
	noton="���ǳ�����Ա\n\n";
	ison="���ǳ�����Ա\n\n";
	off="���ӱ�����ʱ";
	on="���ӱ�����ʱ";
	yellow="���ӵõ�����ʱ";
	twoy="���ӵõ��ڶ��Ż���ʱ";
	red="���ӵõ�����ʱ";
	goal="���ӽ���ʱ";
	penalty="���ӷ�������ʱ";
	owng="���Ӵ���������ʱ";
	penmiss="���ӷ�ʧ����ʱ";
	yellowerr="����һ�Ż��ƣ�Ӧѡ�����Ʊ�һ��ѡ��\n\n";
	rederr="�ѱ����Ʒ���\n\n";
	twoyerr="��û�еõ���һ�Ż���\n\n";
	nogoal="û�н���\n\n";
	nvzu="��Ů��";

	for(int i=0;i<pDoc->HomePlayerNum;i++)//���������׷���Ա
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

	for(int i=0;i<pDoc->AwayPlayerNum;i++)//����Ͷ��׷���Ա
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
	if(pDoc->GameName=="ʾ������")
	{
		HomeStatic+="����д��������\n\n";
		AwayStatic+="����д��������\n\n";
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
		if(CurEvent.IsHome)//�����¼�
		{
			if(CurEvent.EventType==EVENT_GOAL)//����
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

			if(CurEvent.EventType==EVENT_PENALTY)//����
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

			if(CurEvent.EventType==EVENT_OWNGOAL)//������
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

			if(CurEvent.EventType==EVENT_PENALTYMISS)//��ʧ����
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

			if(CurEvent.EventType==EVENT_SUBSTITUTION)//����
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

			if(CurEvent.EventType==EVENT_YELLOW)//����
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

			if(CurEvent.EventType==EVENT_TWOYELLOW)//����
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

			if(CurEvent.EventType==EVENT_RED)//����
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
		else//�Ͷ��¼�
		{
			if(CurEvent.EventType==EVENT_GOAL)//����
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

			if(CurEvent.EventType==EVENT_PENALTY)//����
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

			if(CurEvent.EventType==EVENT_OWNGOAL)//������
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

			if(CurEvent.EventType==EVENT_PENALTYMISS)//��ʧ����
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

			if(CurEvent.EventType==EVENT_SUBSTITUTION)//����
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

			if(CurEvent.EventType==EVENT_YELLOW)//����
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

			if(CurEvent.EventType==EVENT_TWOYELLOW)//����
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

			if(CurEvent.EventType==EVENT_RED)//����
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
		HomeStatic+="��ƽ�ֵı������ܳ��ֵ����ʤ\n\n";
		AwayStatic+="��ƽ�ֵı������ܳ��ֵ����ʤ\n\n";
		HomeProblem=TRUE;
		AwayProblem=TRUE;
	}
	for(int k=0;k<HomePlayerNum;k++)
	{
		if(HomePlayerStats[k].Player.PlayerName=="����")
		{
			if(HomePlayerStats[k].Goal==0)
			{
				HomeStatic=HomeStatic+HomePlayerStats[k].Player.PlayerNameOutStr+nogoal;
			}
			if(HomePlayerStats[k].Goal>=3 && pDoc->HomeName=="�Զ���ϵ" && pDoc->GameName>nvzu && HomePlayerStats[k].Player.PlayerNumber==99 && homef==7 && awayf==7)
			{
				HomeStatic+="�͸��Ұ��㣡\n\n";
			}
		}
	}
	for(int k=0;k<AwayPlayerNum;k++)
	{
		if(AwayPlayerStats[k].Player.PlayerName=="����")
		{
			if(AwayPlayerStats[k].Goal==0)
			{
				AwayStatic=AwayStatic+AwayPlayerStats[k].Player.PlayerNameOutStr+nogoal;
			}
			if(AwayPlayerStats[k].Goal>=3 && pDoc->AwayName=="�Զ���ϵ" && pDoc->GameName>nvzu && AwayPlayerStats[k].Player.PlayerNumber==99 && homef==7 && awayf==7)
			{
				AwayStatic+="�͸��Ұ��㣡\n\n";
			}
		}
	}
	if(!HomeProblem)
		HomeStatic+="û�����⣡";
	if(!AwayProblem)
		AwayStatic+="û�����⣡";
	GetDlgItem(IDC_HOME_STATIC)->SetWindowTextW(HomeStatic);
	GetDlgItem(IDC_AWAY_STATIC)->SetWindowTextW(AwayStatic);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
