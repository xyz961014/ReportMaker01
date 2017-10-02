// Penalty.cpp : 实现文件
//

#include "stdafx.h"
#include "ReportMaker01.h"
#include "Penalty.h"
#include "afxdialogex.h"
#include "ReportMaker01Doc.h"


// CPenalty 对话框

IMPLEMENT_DYNAMIC(CPenalty, CDialogEx)

CPenalty::CPenalty(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPenalty::IDD, pParent)
{

}

CPenalty::~CPenalty()
{
}

void CPenalty::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PENALTY_CHECK, m_IsPenalty);
	DDX_Control(pDX, IDC_HOMENUM_COMBO, m_Homenum);
	DDX_Control(pDX, IDC_HOMENAME_COMBO, m_Homename);
	DDX_Control(pDX, IDC_HOMEGOAL_RADIO, m_Homegoal);
	DDX_Control(pDX, IDC_HOME_LIST, m_Homelist);
	DDX_Control(pDX, IDC_AWAYNUM_COMBO, m_Awaynum);
	DDX_Control(pDX, IDC_AWAYNAME_COMBO, m_Awayname);
	DDX_Control(pDX, IDC_AWAYGOAL_RADIO, m_Awaygoal);
	DDX_Control(pDX, IDC_AWAY_LIST, m_Awaylist);
	DDX_Control(pDX, IDC_TIME_EDIT, m_Time);
}


BEGIN_MESSAGE_MAP(CPenalty, CDialogEx)
	ON_CBN_SELCHANGE(IDC_HOMENUM_COMBO, &CPenalty::OnCbnSelchangeHomenumCombo)
	ON_CBN_SELCHANGE(IDC_AWAYNUM_COMBO, &CPenalty::OnCbnSelchangeAwaynumCombo)
	ON_CBN_SELCHANGE(IDC_HOMENAME_COMBO, &CPenalty::OnCbnSelchangeHomenameCombo)
	ON_CBN_SELCHANGE(IDC_AWAYNAME_COMBO, &CPenalty::OnCbnSelchangeAwaynameCombo)
	ON_BN_CLICKED(IDC_HOMEADD_BUTTON, &CPenalty::OnBnClickedHomeaddButton)
	ON_BN_CLICKED(IDC_AWAYADD_BUTTON, &CPenalty::OnBnClickedAwayaddButton)
	ON_LBN_SELCHANGE(IDC_HOME_LIST, &CPenalty::OnLbnSelchangeHomeList)
	ON_LBN_SELCHANGE(IDC_AWAY_LIST, &CPenalty::OnLbnSelchangeAwayList)
	ON_BN_CLICKED(IDOK, &CPenalty::OnBnClickedOk)
	ON_BN_CLICKED(IDC_HOMEUP_BUTTON, &CPenalty::OnBnClickedHomeupButton)
	ON_BN_CLICKED(IDC_AWAYUP_BUTTON, &CPenalty::OnBnClickedAwayupButton)
	ON_BN_CLICKED(IDC_HOMEDOWN_BUTTON, &CPenalty::OnBnClickedHomedownButton)
	ON_BN_CLICKED(IDC_AWAYDOWN_BUTTON, &CPenalty::OnBnClickedAwaydownButton)
	ON_BN_CLICKED(IDC_HOMEDEL_BUTTON, &CPenalty::OnBnClickedHomedelButton)
	ON_BN_CLICKED(IDC_AWAYDEL_BUTTON, &CPenalty::OnBnClickedAwaydelButton)
END_MESSAGE_MAP()


// CPenalty 消息处理程序


BOOL CPenalty::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	GetDlgItem(IDC_HOME_STATIC)->SetWindowTextW(pDoc->HomeName);
	GetDlgItem(IDC_AWAY_STATIC)->SetWindowTextW(pDoc->AwayName);
	m_IsPenalty.SetCheck(pDoc->IsPenalty);
	CString time;
	time.Format(_T("%d"),pDoc->PenaltyTime);
	m_Time.SetWindowTextW(time);
	CString Numstr;
	int i;
	for(i=0;i<pDoc->HomePlayerNum;i++)
	{
		if(pDoc->HomePlayers[i].IsPlayerNumber)
		{
		Numstr.Format(_T("%d"),pDoc->HomePlayers[i].PlayerNumber);
		m_Homenum.AddString(Numstr);
		}
	}
	m_Homenum.SetCurSel(0);
	for(i=0;i<pDoc->AwayPlayerNum;i++)
	{
		if(pDoc->AwayPlayers[i].IsPlayerNumber)
		{
		Numstr.Format(_T("%d"),pDoc->AwayPlayers[i].PlayerNumber);
		m_Awaynum.AddString(Numstr);
		}
	}
	m_Awaynum.SetCurSel(0);

	for(i=0;i<pDoc->HomePlayerNum;i++)
	{
		m_Homename.AddString(pDoc->HomePlayers[i].PlayerName);
	}
	m_Homename.SetCurSel(0);

	for(i=0;i<pDoc->AwayPlayerNum;i++)
	{
		m_Awayname.AddString(pDoc->AwayPlayers[i].PlayerName);
	}
	m_Awayname.SetCurSel(0);

	m_Homegoal.SetCheck(TRUE);
	m_Awaygoal.SetCheck(TRUE);
	HomeListRefresh();
	AwayListRefresh();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CPenalty::HomeListRefresh(void)
{
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	m_Homelist.ResetContent();
	int i;
	for(i=0;i<pDoc->HomePenaltyNum;i++)
	{
		pDoc->HomePenalty[i].GetListOutstr();
		m_Homelist.AddString(pDoc->HomePenalty[i].ListOutstr);
	}
	GetDlgItem(IDC_HOMEUP_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_HOMEDOWN_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_HOMEDEL_BUTTON)->EnableWindow(FALSE);
}


void CPenalty::AwayListRefresh(void)
{
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	m_Awaylist.ResetContent();
	int i;
	for(i=0;i<pDoc->AwayPenaltyNum;i++)
	{
		pDoc->AwayPenalty[i].GetListOutstr();
		m_Awaylist.AddString(pDoc->AwayPenalty[i].ListOutstr);
	}
	GetDlgItem(IDC_AWAYUP_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_AWAYDOWN_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_AWAYDEL_BUTTON)->EnableWindow(FALSE);
}


void CPenalty::OnCbnSelchangeHomenumCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Homename.SetCurSel(m_Homenum.GetCurSel());
}


void CPenalty::OnCbnSelchangeAwaynumCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Awayname.SetCurSel(m_Awaynum.GetCurSel());
}


void CPenalty::OnCbnSelchangeHomenameCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	if(pDoc->HomePlayers[m_Homename.GetCurSel()].IsPlayerNumber)
		m_Homenum.SetCurSel(m_Homename.GetCurSel());
}


void CPenalty::OnCbnSelchangeAwaynameCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	if(pDoc->AwayPlayers[m_Awayname.GetCurSel()].IsPlayerNumber)
		m_Awaynum.SetCurSel(m_Awayname.GetCurSel());
}


void CPenalty::OnBnClickedHomeaddButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	UpdateData(TRUE);
	if(pDoc->HomePenaltyNum==49)
	{
		AfxMessageBox(_T("已达到点球数量上限，无法再添加点球"));
		return;
	}
	pDoc->HomePenalty[pDoc->HomePenaltyNum].IsGoal=m_Homegoal.GetCheck();
	pDoc->HomePenalty[pDoc->HomePenaltyNum].Player=pDoc->HomePlayers[m_Homename.GetCurSel()];
	pDoc->HomePenaltyNum++;
	HomeListRefresh();
}


void CPenalty::OnBnClickedAwayaddButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	UpdateData(TRUE);
	if(pDoc->AwayPenaltyNum==49)
	{
		AfxMessageBox(_T("已达到点球数量上限，无法再添加点球"));
		return;
	}
	pDoc->AwayPenalty[pDoc->AwayPenaltyNum].IsGoal=m_Awaygoal.GetCheck();
	pDoc->AwayPenalty[pDoc->AwayPenaltyNum].Player=pDoc->AwayPlayers[m_Awayname.GetCurSel()];
	pDoc->AwayPenaltyNum++;
	AwayListRefresh();
}


void CPenalty::OnLbnSelchangeHomeList()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_HOMEUP_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_HOMEDOWN_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_HOMEDEL_BUTTON)->EnableWindow(TRUE);
}


void CPenalty::OnLbnSelchangeAwayList()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_AWAYUP_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_AWAYDOWN_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_AWAYDEL_BUTTON)->EnableWindow(TRUE);
}


void CPenalty::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	UpdateData(TRUE);
	pDoc->IsPenalty=m_IsPenalty.GetCheck();
	CString time;
	m_Time.GetWindowTextW(time);
	pDoc->PenaltyTime=_ttoi(time);
	pDoc->OnDraw();
	CDialogEx::OnOK();
}


void CPenalty::OnBnClickedHomeupButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int up;
	PenaltyShootout temp;
	up=m_Homelist.GetCurSel();
	if(up!=0)
	{
		temp=pDoc->HomePenalty[up];
		pDoc->HomePenalty[up]=pDoc->HomePenalty[up-1];
		pDoc->HomePenalty[up-1]=temp;
	}
	HomeListRefresh();
}


void CPenalty::OnBnClickedAwayupButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int up;
	PenaltyShootout temp;
	up=m_Awaylist.GetCurSel();
	if(up!=0)
	{
		temp=pDoc->AwayPenalty[up];
		pDoc->AwayPenalty[up]=pDoc->AwayPenalty[up-1];
		pDoc->AwayPenalty[up-1]=temp;
	}
	AwayListRefresh();
}


void CPenalty::OnBnClickedHomedownButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int down;
	PenaltyShootout temp;
	down=m_Homelist.GetCurSel();
	if(down!=pDoc->HomePenaltyNum-1)
	{
		temp=pDoc->HomePenalty[down];
		pDoc->HomePenalty[down]=pDoc->HomePenalty[down+1];
		pDoc->HomePenalty[down+1]=temp;
	}
	HomeListRefresh();
}


void CPenalty::OnBnClickedAwaydownButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int down;
	PenaltyShootout temp;
	down=m_Awaylist.GetCurSel();
	if(down!=pDoc->AwayPenaltyNum-1)
	{
		temp=pDoc->AwayPenalty[down];
		pDoc->AwayPenalty[down]=pDoc->AwayPenalty[down+1];
		pDoc->AwayPenalty[down+1]=temp;
	}
	AwayListRefresh();
}


void CPenalty::OnBnClickedHomedelButton()
{
	// TODO: 在此添加控件通知处理程序代码
	int del;
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	del=m_Homelist.GetCurSel();
	int i;
	for(i=del;i<pDoc->HomePenaltyNum;i++)
	{
		pDoc->HomePenalty[i]=pDoc->HomePenalty[i+1];
	}
	pDoc->HomePenaltyNum--;
	HomeListRefresh();
}


void CPenalty::OnBnClickedAwaydelButton()
{
	// TODO: 在此添加控件通知处理程序代码
	int del;
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	del=m_Awaylist.GetCurSel();
	int i;
	for(i=del;i<pDoc->AwayPenaltyNum;i++)
	{
		pDoc->AwayPenalty[i]=pDoc->AwayPenalty[i+1];
	}
	pDoc->AwayPenaltyNum--;
	AwayListRefresh();
}
