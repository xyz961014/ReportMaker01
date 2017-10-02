// EventDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ReportMaker01.h"
#include "EventDlg.h"
#include "afxdialogex.h"
#include "ReportMaker01Doc.h"


// CEventDlg 对话框

IMPLEMENT_DYNAMIC(CEventDlg, CDialogEx)

CEventDlg::CEventDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEventDlg::IDD, pParent)
	, m_EventTime(0)
	, m_EventStoppageTime(0)
	, m_PlayerInNum(0)
	, m_PlayerInName(_T(""))
{

}

CEventDlg::~CEventDlg()
{
}

void CEventDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EVENT_PLAYERNUM_COMBO, m_PlayerNum);
	DDX_Control(pDX, IDC_EVENT_TYPE_COMBO, m_EventType);
	DDX_Text(pDX, IDC_EVENT_TIME_EDIT, m_EventTime);
	DDX_Text(pDX, IDC_EVENT_STOPPAGETIME_EDIT, m_EventStoppageTime);
	DDX_Control(pDX, IDC_PLAYEROUTNUM_COMBO, m_PlayerOutNum);
	DDX_Text(pDX, IDC_PLAYERINNUM_EDIT, m_PlayerInNum);
	//  DDX_Control(pDX, IDC_PLAYEROUTNAME_EDIT, m_PlayerOutName);
	DDX_Text(pDX, IDC_PLAYERINNAME_EDIT, m_PlayerInName);
	DDX_Control(pDX, IDC_EVENT_EDIT_BOTTON, m_EventEdit);
	DDX_Control(pDX, IDC_EVENT_DELETE_BOTTON, m_EventDelete);
	DDX_Control(pDX, IDC_PLAYEROUTNAME_COMBO, m_PlayerOutName);
	DDX_Control(pDX, IDC_PLAYERNAME_COMBO, m_PlayerName);
	DDX_Control(pDX, IDC_EVENTHOME_RADIO, m_HomeRadio);
	DDX_Control(pDX, IDC_EVENT_PLAYEREXTRA_COMBO, m_PlayerExtra);
	DDX_Control(pDX, IDC_EVENT_PLAYEROUTEXTRA_COMBO, m_PlayerOutExtra);
	DDX_Control(pDX, IDC_EVENT_PLAYERINEXTRA_COMBO, m_PlayerInExtra);
	DDX_Control(pDX, IDC_PLAYERNUM_CHECK, m_PlayerNumCheck);
	DDX_Control(pDX, IDC_PLAYEROUTNUM_CHECK, m_PlayerOutNumCheck);
	DDX_Control(pDX, IDC_PLAYERINNUM_CHECK, m_PlayerInNumCheck);
	DDX_Control(pDX, IDC_EVENT_LIST, m_EventList);
}


BEGIN_MESSAGE_MAP(CEventDlg, CDialogEx)
	ON_BN_CLICKED(IDC_EVENT_EDIT_BOTTON, &CEventDlg::OnBnClickedEventEditBotton)
	ON_BN_CLICKED(IDC_OK, &CEventDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_EVENTHOME_RADIO, &CEventDlg::OnBnClickedEventhomeRadio)
	ON_BN_CLICKED(IDC_EVENTAWAY_RADIO, &CEventDlg::OnBnClickedEventawayRadio)
	ON_CBN_SELCHANGE(IDC_EVENT_TYPE_COMBO, &CEventDlg::OnCbnSelchangeEventTypeCombo)
	ON_CBN_SELCHANGE(IDC_EVENT_PLAYERNUM_COMBO, &CEventDlg::OnCbnSelchangeEventPlayernumCombo)
	ON_CBN_EDITCHANGE(IDC_EVENT_PLAYERNUM_COMBO, &CEventDlg::OnCbnEditchangeEventPlayernumCombo)
	ON_CBN_SELCHANGE(IDC_PLAYERNAME_COMBO, &CEventDlg::OnCbnSelchangePlayernameCombo)
	ON_CBN_EDITCHANGE(IDC_PLAYERNAME_COMBO, &CEventDlg::OnCbnEditchangePlayernameCombo)
	ON_CBN_SELCHANGE(IDC_PLAYEROUTNUM_COMBO, &CEventDlg::OnCbnSelchangePlayeroutnumCombo)
	ON_CBN_EDITCHANGE(IDC_PLAYEROUTNUM_COMBO, &CEventDlg::OnCbnEditchangePlayeroutnumCombo)
	ON_CBN_SELCHANGE(IDC_PLAYEROUTNAME_COMBO, &CEventDlg::OnCbnSelchangePlayeroutnameCombo)
	ON_CBN_EDITCHANGE(IDC_PLAYEROUTNAME_COMBO, &CEventDlg::OnCbnEditchangePlayeroutnameCombo)
	ON_BN_CLICKED(IDC_EVENTOK, &CEventDlg::OnBnClickedEventok)
	ON_BN_CLICKED(IDC_PLAYERNUM_CHECK, &CEventDlg::OnBnClickedPlayernumCheck)
	ON_BN_CLICKED(IDC_PLAYEROUTNUM_CHECK, &CEventDlg::OnBnClickedPlayeroutnumCheck)
	ON_BN_CLICKED(IDC_EVENTREFRESH_BOTTON, &CEventDlg::OnBnClickedEventrefreshBotton)
	ON_LBN_SELCHANGE(IDC_EVENT_LIST, &CEventDlg::OnLbnSelchangeEventList)
	ON_BN_CLICKED(IDC_EVENT_DELETE_BOTTON, &CEventDlg::OnBnClickedEventDeleteBotton)
	ON_BN_CLICKED(IDC_PLAYERINNUM_CHECK, &CEventDlg::OnBnClickedPlayerinnumCheck)
	ON_BN_CLICKED(IDC_EVENTUP_BUTTON, &CEventDlg::OnBnClickedEventupButton)
	ON_BN_CLICKED(IDC_EVENTDOWN_BUTTON, &CEventDlg::OnBnClickedEventdownButton)
END_MESSAGE_MAP()


// CEventDlg 消息处理程序


void CEventDlg::OnBnClickedEventEditBotton()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	CEventEditDlg dlgEventedit;
	dlgEventedit.DoModal();
	OnBnClickedEventrefreshBotton();
}


BOOL CEventDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	m_EventType.SetCurSel(0);
	if(pDoc->HomePlayers[0].IsPlayerNumber)
	{
		m_PlayerNumCheck.SetCheck(TRUE);
		m_PlayerOutNumCheck.SetCheck(TRUE);
		m_PlayerInNumCheck.SetCheck(TRUE);
	}
	else
	{
		m_PlayerNumCheck.SetCheck(FALSE);
		m_PlayerOutNumCheck.SetCheck(FALSE);
		m_PlayerInNumCheck.SetCheck(FALSE);
		m_PlayerNum.EnableWindow(FALSE);
		m_PlayerOutNum.EnableWindow(FALSE);
	}
	CString str;
	for(int i=0;i<pDoc->HomePlayerNum;i++)
	{
		if(pDoc->HomePlayers[i].IsPlayerNumber)
		{
			str.Format(_T("%d"),pDoc->HomePlayers[i].PlayerNumber);
			m_PlayerNum.AddString(str);
			m_PlayerOutNum.AddString(str);
		}
		
	}
	m_PlayerNum.SetCurSel(0);
	m_PlayerOutNum.SetCurSel(0);
	for(int i=0;i<pDoc->HomePlayerNum;i++)
	{
		m_PlayerName.AddString(pDoc->HomePlayers[i].PlayerName);
		m_PlayerOutName.AddString(pDoc->HomePlayers[i].PlayerName);
	}
	m_PlayerName.SetCurSel(0);
	m_PlayerOutName.SetCurSel(0);
	m_EventTime=0;
	m_EventStoppageTime=0;
	m_HomeRadio.SetCheck(TRUE);
	m_HomeRadio.SetWindowTextW(pDoc->HomeName);
	GetDlgItem(IDC_EVENTAWAY_RADIO)->SetWindowTextW(pDoc->AwayName);
	m_PlayerOutExtra.SetCurSel(0);
	m_PlayerInExtra.SetCurSel(0);
	m_PlayerExtra.SetCurSel(0);
	OnCbnSelchangePlayernameCombo();
	OnCbnSelchangePlayeroutnameCombo();

	OnBnClickedEventrefreshBotton();
	


	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CEventDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	pDoc->UpdateAllViews(NULL);
	CDialog::OnOK();
}


void CEventDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CEventDlg::OnBnClickedEventhomeRadio()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int num=m_PlayerNum.GetCurSel();
	int outnum=m_PlayerOutNum.GetCurSel();
	int name=m_PlayerName.GetCurSel();
	int outname=m_PlayerOutName.GetCurSel();
	m_PlayerNum.ResetContent();
	m_PlayerName.ResetContent();
	m_PlayerOutName.ResetContent();
	m_PlayerOutNum.ResetContent();
	CString str;
	for(int i=0;i<pParent->HomePlayerNum;i++)
	{
		if(pParent->HomePlayers[i].IsPlayerNumber)
		{
			str.Format(_T("%d"),pParent->HomePlayers[i].PlayerNumber);
			m_PlayerNum.AddString(str);
			m_PlayerOutNum.AddString(str);
		}
		
	}
	m_PlayerNum.SetCurSel(num);
	m_PlayerOutNum.SetCurSel(outnum);
	for(int i=0;i<pParent->HomePlayerNum;i++)
	{
		m_PlayerName.AddString(pParent->HomePlayers[i].PlayerName);
		m_PlayerOutName.AddString(pParent->HomePlayers[i].PlayerName);
	}
	m_PlayerName.SetCurSel(name);
	m_PlayerOutName.SetCurSel(outname);
	OnCbnSelchangePlayernameCombo();
	OnCbnSelchangePlayeroutnameCombo();
}


void CEventDlg::OnBnClickedEventawayRadio()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int num=m_PlayerNum.GetCurSel();
	int outnum=m_PlayerOutNum.GetCurSel();
	int name=m_PlayerName.GetCurSel();
	int outname=m_PlayerOutName.GetCurSel();
	m_PlayerNum.ResetContent();
	m_PlayerName.ResetContent();
	m_PlayerOutName.ResetContent();
	m_PlayerOutNum.ResetContent();
	CString str;
	for(int i=0;i<pParent->AwayPlayerNum;i++)
	{
		if(pParent->AwayPlayers[i].IsPlayerNumber)
		{
			str.Format(_T("%d"),pParent->AwayPlayers[i].PlayerNumber);
			m_PlayerNum.AddString(str);
			m_PlayerOutNum.AddString(str);
		}
		
	}
	m_PlayerNum.SetCurSel(num);
	m_PlayerOutNum.SetCurSel(outnum);
	for(int i=0;i<pParent->AwayPlayerNum;i++)
	{
		m_PlayerName.AddString(pParent->AwayPlayers[i].PlayerName);
		m_PlayerOutName.AddString(pParent->AwayPlayers[i].PlayerName);
	}
	m_PlayerName.SetCurSel(name);
	m_PlayerOutName.SetCurSel(outname);
	OnCbnSelchangePlayernameCombo();
	OnCbnSelchangePlayeroutnameCombo();
}


void CEventDlg::OnCbnSelchangeEventTypeCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	int EventType;
	EventType=m_EventType.GetCurSel();
	if(EventType==1)
	{
		GetDlgItem(IDC_PLAYEROUT_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_PLAYERIN_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_PLAYEROUTNUM_COMBO)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_PLAYERINNUM_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_NAMEPLAYEROUT_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_NAMEPLAYERIN_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_PLAYEROUTNUM_CHECK)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_PLAYERINNUM_CHECK)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_PLAYEROUTNAME_COMBO)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_PLAYERINNAME_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_PLAYEROUTEXTRA_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EVENT_PLAYEROUTEXTRA_COMBO)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_PLAYERINEXTRA_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EVENT_PLAYERINEXTRA_COMBO)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_PLAYERNAME_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_PLAYERNAME_COMBO)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_PLAYERNUM_CHECK)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EVENT_PLAYERNUM_COMBO)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_PLAYEREXTRA_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EVENT_PLAYEREXTRA_COMBO)->ShowWindow(SW_HIDE);
	
	}
	else
	{
		GetDlgItem(IDC_PLAYEROUT_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_PLAYERIN_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_PLAYEROUTNUM_COMBO)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_PLAYERINNUM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NAMEPLAYEROUT_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NAMEPLAYERIN_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_PLAYEROUTNUM_CHECK)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_PLAYERINNUM_CHECK)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_PLAYEROUTNAME_COMBO)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_PLAYERINNAME_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_PLAYEROUTEXTRA_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EVENT_PLAYEROUTEXTRA_COMBO)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_PLAYERINEXTRA_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EVENT_PLAYERINEXTRA_COMBO)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_PLAYERNAME_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_PLAYERNAME_COMBO)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_PLAYERNUM_CHECK)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EVENT_PLAYERNUM_COMBO)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_PLAYEREXTRA_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EVENT_PLAYEREXTRA_COMBO)->ShowWindow(SW_SHOW);
	}
}


void CEventDlg::OnCbnSelchangeEventPlayernumCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	int Num;
	Num=m_PlayerNum.GetCurSel();
	m_PlayerName.SetCurSel(Num);
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int Curr;
	Curr=m_PlayerNum.GetCurSel();
	int Extra;
	if(m_HomeRadio.GetCheck())
		Extra=pParent->HomePlayers[Curr].PlayerExtra;
	else
		Extra=pParent->AwayPlayers[Curr].PlayerExtra;
	if(Extra==PLAYER_NULL)
		m_PlayerExtra.SetCurSel(0);
	else if(Extra==PLAYER_ZUTE)
		m_PlayerExtra.SetCurSel(1);
	else if(Extra==PLAYER_XIAOYOU)
		m_PlayerExtra.SetCurSel(2);
	else if(Extra==PLAYER_JIAOGONG)
		m_PlayerExtra.SetCurSel(3);
}


void CEventDlg::OnCbnEditchangeEventPlayernumCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	CString Cur;
	m_PlayerNum.GetWindowTextW(Cur);
	CString Num;
	int Playernum;
	Playernum=m_PlayerNum.GetCount();
	int i=0;
    do
	{
		if(Playernum!=0)
			m_PlayerNum.GetLBText(i,Num);
		if(Num==Cur)
		{
			m_PlayerName.SetCurSel(i);
	        int Curr;
	        Curr=i;
	        int Extra;
	        if(m_HomeRadio.GetCheck())
		        Extra=pParent->HomePlayers[Curr].PlayerExtra;
	        else
	        	Extra=pParent->AwayPlayers[Curr].PlayerExtra;
	        if(Extra==PLAYER_NULL)
	        	m_PlayerExtra.SetCurSel(0);
	        else if(Extra==PLAYER_ZUTE)
	        	m_PlayerExtra.SetCurSel(1);
	        else if(Extra==PLAYER_XIAOYOU)
	        	m_PlayerExtra.SetCurSel(2);
	        else if(Extra==PLAYER_JIAOGONG)
	        	m_PlayerExtra.SetCurSel(3);
			break;
		}
		i++;
	}
	while((Num!=Cur)&&(i<Playernum));

}


void CEventDlg::OnCbnSelchangePlayernameCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	int Name;
	Name=m_PlayerName.GetCurSel();
	m_PlayerNum.SetCurSel(Name);
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int Curr;
	Curr=m_PlayerName.GetCurSel();
	int Extra;
	if(m_HomeRadio.GetCheck())
		Extra=pParent->HomePlayers[Curr].PlayerExtra;
	else
		Extra=pParent->AwayPlayers[Curr].PlayerExtra;
	if(Extra==PLAYER_NULL)
		m_PlayerExtra.SetCurSel(0);
	else if(Extra==PLAYER_ZUTE)
		m_PlayerExtra.SetCurSel(1);
	else if(Extra==PLAYER_XIAOYOU)
		m_PlayerExtra.SetCurSel(2);
	else if(Extra==PLAYER_JIAOGONG)
		m_PlayerExtra.SetCurSel(3);
}


void CEventDlg::OnCbnEditchangePlayernameCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString Cur;
	m_PlayerName.GetWindowTextW(Cur);
	CString Name;
	int Playernum;
	Playernum=m_PlayerNum.GetCount();
	int i=0;
    do
	{
		if(Playernum!=0)
			m_PlayerName.GetLBText(i,Name);
		if(Name==Cur)
		{
			m_PlayerNum.SetCurSel(i);
			CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	        int Curr;
	        Curr=i;
	        int Extra;
	        if(m_HomeRadio.GetCheck())
		        Extra=pParent->HomePlayers[Curr].PlayerExtra;
	        else
	        	Extra=pParent->AwayPlayers[Curr].PlayerExtra;
	        if(Extra==PLAYER_NULL)
	        	m_PlayerExtra.SetCurSel(0);
	        else if(Extra==PLAYER_ZUTE)
	        	m_PlayerExtra.SetCurSel(1);
	        else if(Extra==PLAYER_XIAOYOU)
	        	m_PlayerExtra.SetCurSel(2);
	        else if(Extra==PLAYER_JIAOGONG)
	        	m_PlayerExtra.SetCurSel(3);
			break;
		}
		i++;
	}
	while((Name!=Cur)&&(i<Playernum));
}


void CEventDlg::OnCbnSelchangePlayeroutnumCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	int Num;
	Num=m_PlayerOutNum.GetCurSel();
	m_PlayerOutName.SetCurSel(Num);
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int Curr;
	Curr=m_PlayerOutNum.GetCurSel();
	int Extra;
	if(m_HomeRadio.GetCheck())
		Extra=pParent->HomePlayers[Curr].PlayerExtra;
	else
		Extra=pParent->AwayPlayers[Curr].PlayerExtra;
	if(Extra==PLAYER_NULL)
		m_PlayerOutExtra.SetCurSel(0);
	else if(Extra==PLAYER_ZUTE)
		m_PlayerOutExtra.SetCurSel(1);
	else if(Extra==PLAYER_XIAOYOU)
		m_PlayerOutExtra.SetCurSel(2);
	else if(Extra==PLAYER_JIAOGONG)
		m_PlayerOutExtra.SetCurSel(3);
}


void CEventDlg::OnCbnEditchangePlayeroutnumCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString Cur;
	m_PlayerOutNum.GetWindowTextW(Cur);
	CString Num;
	int Playernum;
	Playernum=m_PlayerOutNum.GetCount();
	int i=0;
    do
	{
		if(Playernum!=0)
			m_PlayerOutNum.GetLBText(i,Num);
		if(Num==Cur)
		{
			m_PlayerOutName.SetCurSel(i);
			CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	        int Curr;
	        Curr=i;
	        int Extra;
	        if(m_HomeRadio.GetCheck())
		        Extra=pParent->HomePlayers[Curr].PlayerExtra;
	        else
	        	Extra=pParent->AwayPlayers[Curr].PlayerExtra;
	        if(Extra==PLAYER_NULL)
	        	m_PlayerOutExtra.SetCurSel(0);
	        else if(Extra==PLAYER_ZUTE)
	        	m_PlayerOutExtra.SetCurSel(1);
	        else if(Extra==PLAYER_XIAOYOU)
	        	m_PlayerOutExtra.SetCurSel(2);
	        else if(Extra==PLAYER_JIAOGONG)
	        	m_PlayerOutExtra.SetCurSel(3);
			break;
		}
		i++;
	}
	while((Num!=Cur)&&(i<Playernum));
}


void CEventDlg::OnCbnSelchangePlayeroutnameCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	int Name;
	Name=m_PlayerOutName.GetCurSel();
	m_PlayerOutNum.SetCurSel(Name);
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int Curr;
	Curr=m_PlayerOutName.GetCurSel();
	int Extra;
	if(m_HomeRadio.GetCheck())
		Extra=pParent->HomePlayers[Curr].PlayerExtra;
	else
		Extra=pParent->AwayPlayers[Curr].PlayerExtra;
	if(Extra==PLAYER_NULL)
		m_PlayerOutExtra.SetCurSel(0);
	else if(Extra==PLAYER_ZUTE)
		m_PlayerOutExtra.SetCurSel(1);
	else if(Extra==PLAYER_XIAOYOU)
		m_PlayerOutExtra.SetCurSel(2);
	else if(Extra==PLAYER_JIAOGONG)
		m_PlayerOutExtra.SetCurSel(3);

}


void CEventDlg::OnCbnEditchangePlayeroutnameCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString Cur;
	m_PlayerOutName.GetWindowTextW(Cur);
	CString Name;
	int Playernum;
	Playernum=m_PlayerOutNum.GetCount();
	int i=0;
    do
	{
		if(Playernum!=0)
			m_PlayerOutName.GetLBText(i,Name);
		if(Name==Cur)
		{
			m_PlayerOutNum.SetCurSel(i);
			CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	        int Curr;
	        Curr=i;
	        int Extra;
	        if(m_HomeRadio.GetCheck())
		        Extra=pParent->HomePlayers[Curr].PlayerExtra;
	        else
	        	Extra=pParent->AwayPlayers[Curr].PlayerExtra;
	        if(Extra==PLAYER_NULL)
	        	m_PlayerOutExtra.SetCurSel(0);
	        else if(Extra==PLAYER_ZUTE)
	        	m_PlayerOutExtra.SetCurSel(1);
	        else if(Extra==PLAYER_XIAOYOU)
	        	m_PlayerOutExtra.SetCurSel(2);
	        else if(Extra==PLAYER_JIAOGONG)
	        	m_PlayerOutExtra.SetCurSel(3);
			break;
		}
		i++;
	}
	while((Name!=Cur)&&(i<Playernum));
}


void CEventDlg::OnBnClickedEventok()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	UpdateData(TRUE);
	if(pParent->EventNum==199)
	{
		AfxMessageBox(_T("已达到事件数量上限，无法再添加事件"));
		return;
	}
	pParent->Events[pParent->EventPt].IsHome=m_HomeRadio.GetCheck();
	pParent->Events[pParent->EventPt].Time=m_EventTime;
	pParent->Events[pParent->EventPt].StoppageTime=m_EventStoppageTime;
	CString Type;
	m_EventType.GetLBText(m_EventType.GetCurSel(),Type);
	if(Type=="进球")
		pParent->Events[pParent->EventPt].EventType=EVENT_GOAL;
	else if(Type=="乌龙球")
		pParent->Events[pParent->EventPt].EventType=EVENT_OWNGOAL;
	else if(Type=="换人")
		pParent->Events[pParent->EventPt].EventType=EVENT_SUBSTITUTION;
	else if(Type=="黄牌")
		pParent->Events[pParent->EventPt].EventType=EVENT_YELLOW;
	else if(Type=="红牌")
		pParent->Events[pParent->EventPt].EventType=EVENT_RED;
	else if(Type=="两黄并一红")
		pParent->Events[pParent->EventPt].EventType=EVENT_TWOYELLOW;
	else if(Type=="点球")
		pParent->Events[pParent->EventPt].EventType=EVENT_PENALTY;
	else if(Type=="点球罚失")
		pParent->Events[pParent->EventPt].EventType=EVENT_PENALTYMISS;
	
	if(Type=="换人")
	{
		if(m_PlayerOutNumCheck.GetCheck())
		{
			CString Cur;
	        m_PlayerOutNum.GetWindowTextW(Cur);
	        CString Num;
	        int Playernum;
	        Playernum=m_PlayerOutNum.GetCount();
	        int i=0;
            do
	        {
		        m_PlayerOutNum.GetLBText(i,Num);
		        if(Num==Cur) //换下球员号码是数组中球员，分主客队新建换上球员并存入时间
		        {
					if(m_HomeRadio.GetCheck())
					{
						pParent->Events[pParent->EventPt].Player1=pParent->HomePlayers[i];
						if(m_PlayerInNumCheck.GetCheck())
						{
							pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber=TRUE;
							pParent->HomePlayers[pParent->HomePlayerPt].PlayerNumber=m_PlayerInNum;
						}
						else
							pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber=FALSE;
						pParent->HomePlayers[pParent->HomePlayerPt].PlayerName=m_PlayerInName;
					    CString PlayerExtra;
	                    m_PlayerInExtra.GetLBText(m_PlayerInExtra.GetCurSel(),PlayerExtra);
	                    if(PlayerExtra=="无")
		                    pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	                    else if(PlayerExtra=="足特")
		                    pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_ZUTE;
	                    else if(PlayerExtra=="校友")
						    pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_XIAOYOU;
				        else if(PlayerExtra=="教工")
							pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_JIAOGONG;
						pParent->HomePlayers[pParent->HomePlayerPt].IsFirst=FALSE;
						pParent->Events[pParent->EventPt].Player2=pParent->HomePlayers[pParent->HomePlayerPt];
						pParent->HomePlayerPt++;
						pParent->HomePlayerNum++;
						pParent->EventPt++;
						pParent->EventNum++;
						OnBnClickedEventrefreshBotton();
						return;
					}
					else
					{
						pParent->Events[pParent->EventPt].Player1=pParent->AwayPlayers[i];
						if(m_PlayerInNumCheck.GetCheck())
						{
							pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber=TRUE;
							pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerNumber=m_PlayerInNum;
						}
						else
							pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber=FALSE;
						pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerName=m_PlayerInName;
					    CString PlayerExtra;
	                    m_PlayerInExtra.GetLBText(m_PlayerInExtra.GetCurSel(),PlayerExtra);
	                    if(PlayerExtra=="无")
		                    pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	                    else if(PlayerExtra=="足特")
		                    pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_ZUTE;
	                    else if(PlayerExtra=="校友")
						    pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_XIAOYOU;
				        else if(PlayerExtra=="教工")
							pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_JIAOGONG;
						pParent->AwayPlayers[pParent->AwayPlayerPt].IsFirst=FALSE;
						pParent->Events[pParent->EventPt].Player2=pParent->AwayPlayers[pParent->AwayPlayerPt];
						pParent->AwayPlayerNum++;
						pParent->AwayPlayerPt++;
						pParent->EventPt++;
						pParent->EventNum++;
						OnBnClickedEventrefreshBotton();
						return;
					}
			     
		        }
		        i++;
	        }
	        while((Num!=Cur)&&(i<Playernum));

			if(m_HomeRadio.GetCheck())    //换下球员是新球员，分主客队存入球员数组并存入事件
			{
				if(m_PlayerOutNumCheck.GetCheck())
				{
					pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber=TRUE;
					CString Number;
					m_PlayerOutNum.GetWindowTextW(Number);
					pParent->HomePlayers[pParent->HomePlayerPt].PlayerNumber=_ttoi(Number);
				}
				else
					pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber=FALSE;
			    m_PlayerOutName.GetWindowTextW(pParent->HomePlayers[pParent->HomePlayerPt].PlayerName);
				CString PlayerExtra;
	            m_PlayerOutExtra.GetLBText(m_PlayerOutExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="无")
		            pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="足特")
		            pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="校友")
			        pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="教工")
				    pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pParent->HomePlayers[pParent->HomePlayerPt].IsFirst=FALSE;
				pParent->Events[pParent->EventPt].Player1=pParent->HomePlayers[pParent->HomePlayerPt];
				pParent->HomePlayerPt++;
				pParent->HomePlayerNum++;
				if(m_PlayerInNumCheck.GetCheck())
				{
					pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber=TRUE;
					pParent->HomePlayers[pParent->HomePlayerPt].PlayerNumber=m_PlayerInNum;
				}
				else
					pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber=FALSE;
				pParent->HomePlayers[pParent->HomePlayerPt].PlayerName=m_PlayerInName;
	            m_PlayerInExtra.GetLBText(m_PlayerInExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="无")
		            pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="足特")
		            pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="校友")
	     			pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="教工")
					pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pParent->HomePlayers[pParent->HomePlayerPt].IsFirst=FALSE;
				pParent->Events[pParent->EventPt].Player2=pParent->HomePlayers[pParent->HomePlayerPt];
				pParent->HomePlayerPt++;
				pParent->HomePlayerNum++;
				pParent->EventPt++;
				pParent->EventNum++;
				OnBnClickedEventrefreshBotton();
				return;
			}
			else
			{
				if(m_PlayerOutNumCheck.GetCheck())
				{
					pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber=TRUE;
					CString Number;
					m_PlayerOutNum.GetWindowTextW(Number);
					pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerNumber=_ttoi(Number);
				}
				else
					pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber=FALSE;
			    m_PlayerOutName.GetWindowTextW(pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerName);
				CString PlayerExtra;
	            m_PlayerOutExtra.GetLBText(m_PlayerOutExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="无")
		            pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="足特")
		            pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="校友")
			        pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="教工")
				    pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pParent->AwayPlayers[pParent->AwayPlayerPt].IsFirst=FALSE;
				pParent->Events[pParent->EventPt].Player1=pParent->AwayPlayers[pParent->AwayPlayerPt];
				pParent->AwayPlayerPt++;
				pParent->AwayPlayerNum++;
				if(m_PlayerInNumCheck.GetCheck())
				{
					pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber=TRUE;
					pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerNumber=m_PlayerInNum;
				}
				else
					pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber=FALSE;
				pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerName=m_PlayerInName;
	            m_PlayerInExtra.GetLBText(m_PlayerInExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="无")
		            pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="足特")
		            pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="校友")
	     			pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="教工")
					pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pParent->AwayPlayers[pParent->HomePlayerPt].IsFirst=FALSE;
				pParent->Events[pParent->EventPt].Player2=pParent->AwayPlayers[pParent->HomePlayerPt];
				pParent->AwayPlayerPt++;
				pParent->AwayPlayerNum++;
				pParent->EventPt++;
				pParent->EventNum++;
				OnBnClickedEventrefreshBotton();
				return;
			}
		} 
		else    //换下球员没有号码的情况
		{
			CString Cur;
	        m_PlayerOutName.GetWindowTextW(Cur);
	        CString Name;
	        int Playernum;
	        Playernum=m_PlayerOutName.GetCount();
	        int i=0;
            do
	        {
		        m_PlayerOutName.GetLBText(i,Name);
		        if(Name==Cur)
		        {
					if(m_HomeRadio.GetCheck())
					{
						pParent->Events[pParent->EventPt].Player1=pParent->HomePlayers[i];
						if(m_PlayerInNumCheck.GetCheck())
						{
							pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber=TRUE;
							pParent->HomePlayers[pParent->HomePlayerPt].PlayerNumber=m_PlayerInNum;
						}
						else
							pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber=FALSE;
						pParent->HomePlayers[pParent->HomePlayerPt].PlayerName=m_PlayerInName;
					    CString PlayerExtra;
	                    m_PlayerInExtra.GetLBText(m_PlayerInExtra.GetCurSel(),PlayerExtra);
	                    if(PlayerExtra=="无")
		                    pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	                    else if(PlayerExtra=="足特")
		                    pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_ZUTE;
	                    else if(PlayerExtra=="校友")
						    pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_XIAOYOU;
				        else if(PlayerExtra=="教工")
							pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_JIAOGONG;
						pParent->HomePlayers[pParent->HomePlayerPt].IsFirst=FALSE;
						pParent->Events[pParent->EventPt].Player2=pParent->HomePlayers[pParent->HomePlayerPt];
						pParent->HomePlayerPt++;
						pParent->HomePlayerNum++;
						pParent->EventPt++;
						pParent->EventNum++;
						OnBnClickedEventrefreshBotton();
						return;
					}
					else
					{
						pParent->Events[pParent->EventPt].Player1=pParent->AwayPlayers[i];
						if(m_PlayerInNumCheck.GetCheck())
						{
							pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber=TRUE;
							pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerNumber=m_PlayerInNum;
						}
						else
							pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber=FALSE;
						pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerName=m_PlayerInName;
					    CString PlayerExtra;
	                    m_PlayerInExtra.GetLBText(m_PlayerInExtra.GetCurSel(),PlayerExtra);
	                    if(PlayerExtra=="无")
		                    pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	                    else if(PlayerExtra=="足特")
		                    pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_ZUTE;
	                    else if(PlayerExtra=="校友")
						    pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_XIAOYOU;
				        else if(PlayerExtra=="教工")
							pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_JIAOGONG;
						pParent->AwayPlayers[pParent->AwayPlayerPt].IsFirst=FALSE;
						pParent->Events[pParent->EventPt].Player2=pParent->AwayPlayers[pParent->AwayPlayerPt];
						pParent->AwayPlayerNum++;
						pParent->AwayPlayerPt++;
						pParent->EventPt++;
						pParent->EventNum++;
						OnBnClickedEventrefreshBotton();
						return;
					}
			     
		        }
		        i++;
	        }
	        while((Name!=Cur)&&(i<Playernum));
			if(m_HomeRadio.GetCheck())    //换下球员是新球员，分主客队存入球员数组并存入事件
			{
				if(m_PlayerOutNumCheck.GetCheck())
				{
					pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber=TRUE;
					CString Number;
					m_PlayerOutNum.GetWindowTextW(Number);
					pParent->HomePlayers[pParent->HomePlayerPt].PlayerNumber=_ttoi(Number);
				}
				else
					pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber=FALSE;
			    m_PlayerOutName.GetWindowTextW(pParent->HomePlayers[pParent->HomePlayerPt].PlayerName);
				CString PlayerExtra;
	            m_PlayerOutExtra.GetLBText(m_PlayerOutExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="无")
		            pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="足特")
		            pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="校友")
			        pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="教工")
				    pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pParent->HomePlayers[pParent->HomePlayerPt].IsFirst=FALSE;
				pParent->Events[pParent->EventPt].Player1=pParent->HomePlayers[pParent->HomePlayerPt];
				pParent->HomePlayerPt++;
				pParent->HomePlayerNum++;
				if(m_PlayerInNumCheck.GetCheck())
				{
					pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber=TRUE;
					pParent->HomePlayers[pParent->HomePlayerPt].PlayerNumber=m_PlayerInNum;
				}
				else
					pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber=FALSE;
				pParent->HomePlayers[pParent->HomePlayerPt].PlayerName=m_PlayerInName;
	            m_PlayerInExtra.GetLBText(m_PlayerInExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="无")
		            pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="足特")
		            pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="校友")
	     			pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="教工")
					pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pParent->HomePlayers[pParent->HomePlayerPt].IsFirst=FALSE;
				pParent->Events[pParent->EventPt].Player2=pParent->HomePlayers[pParent->HomePlayerPt];
				pParent->HomePlayerPt++;
				pParent->HomePlayerNum++;
				pParent->EventPt++;
				pParent->EventNum++;
				OnBnClickedEventrefreshBotton();
				return;
			}
			else
			{
				if(m_PlayerOutNumCheck.GetCheck())
				{
					pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber=TRUE;
					CString Number;
					m_PlayerOutNum.GetWindowTextW(Number);
					pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerNumber=_ttoi(Number);
				}
				else
					pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber=FALSE;
			    m_PlayerOutName.GetWindowTextW(pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerName);
				CString PlayerExtra;
	            m_PlayerOutExtra.GetLBText(m_PlayerOutExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="无")
		            pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="足特")
		            pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="校友")
			        pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="教工")
				    pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pParent->AwayPlayers[pParent->AwayPlayerPt].IsFirst=FALSE;
				pParent->Events[pParent->EventPt].Player1=pParent->AwayPlayers[pParent->AwayPlayerPt];
				pParent->AwayPlayerPt++;
				pParent->AwayPlayerNum++;
				if(m_PlayerInNumCheck.GetCheck())
				{
					pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber=TRUE;
					pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerNumber=m_PlayerInNum;
				}
				else
					pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber=FALSE;
				pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerName=m_PlayerInName;
	            m_PlayerInExtra.GetLBText(m_PlayerInExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="无")
		            pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="足特")
		            pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="校友")
	     			pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="教工")
					pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pParent->AwayPlayers[pParent->HomePlayerPt].IsFirst=FALSE;
				pParent->Events[pParent->EventPt].Player2=pParent->AwayPlayers[pParent->HomePlayerPt];
				pParent->AwayPlayerPt++;
				pParent->AwayPlayerNum++;
				pParent->EventPt++;
				pParent->EventNum++;
				OnBnClickedEventrefreshBotton();
				return;
			}
		}
	}
	else  //不是“换人”的情况
	{
		if(m_PlayerNumCheck.GetCheck())
		{
			CString Cur;
	        m_PlayerNum.GetWindowTextW(Cur);
	        CString Num;
	        int Playernum;
	        Playernum=m_PlayerNum.GetCount();
	        int i=0;
            do
	        {
		        m_PlayerNum.GetLBText(i,Num);
		        if(Num==Cur)
		        {
					if(m_HomeRadio.GetCheck())
					{
						pParent->Events[pParent->EventPt].Player1=pParent->HomePlayers[i];
						pParent->EventPt++;
						pParent->EventNum++;
						OnBnClickedEventrefreshBotton();
						return;
					}
					else
					{
						pParent->Events[pParent->EventPt].Player1=pParent->AwayPlayers[i];
						pParent->EventPt++;
						pParent->EventNum++;
						OnBnClickedEventrefreshBotton();
						return;
					}
			     
		        }
		        i++;
	        }
	        while((Num!=Cur)&&(i<Playernum));
			if(m_HomeRadio.GetCheck())    //球员是新球员，分主客队存入球员数组并存入事件
			{
				if(m_PlayerNumCheck.GetCheck())
				{
					pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber=TRUE;
					CString Number;
					m_PlayerNum.GetWindowTextW(Number);
					pParent->HomePlayers[pParent->HomePlayerPt].PlayerNumber=_ttoi(Number);
				}
				else
					pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber=FALSE;
			    m_PlayerName.GetWindowTextW(pParent->HomePlayers[pParent->HomePlayerPt].PlayerName);
				CString PlayerExtra;
	            m_PlayerExtra.GetLBText(m_PlayerExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="无")
		            pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="足特")
		            pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="校友")
			        pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="教工")
				    pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pParent->HomePlayers[pParent->HomePlayerPt].IsFirst=FALSE;
				pParent->Events[pParent->EventPt].Player1=pParent->HomePlayers[pParent->HomePlayerPt];
				pParent->HomePlayerPt++;
				pParent->HomePlayerNum++;
				pParent->EventPt++;
				pParent->EventNum++;
				OnBnClickedEventrefreshBotton();
				return;
			}
			else
			{
				if(m_PlayerNumCheck.GetCheck())
				{
					pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber=TRUE;
					CString Number;
					m_PlayerNum.GetWindowTextW(Number);
					pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerNumber=_ttoi(Number);
				}
				else
					pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber=FALSE;
			    m_PlayerName.GetWindowTextW(pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerName);
				CString PlayerExtra;
	            m_PlayerExtra.GetLBText(m_PlayerExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="无")
		            pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="足特")
		            pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="校友")
			        pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="教工")
				    pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pParent->AwayPlayers[pParent->AwayPlayerPt].IsFirst=FALSE;
				pParent->Events[pParent->EventPt].Player1=pParent->AwayPlayers[pParent->AwayPlayerPt];
				pParent->AwayPlayerPt++;
				pParent->AwayPlayerNum++;
				pParent->EventPt++;
				pParent->EventNum++;
				OnBnClickedEventrefreshBotton();
				return;
			}
		}
		else
		{
			CString Cur;
	        m_PlayerName.GetWindowTextW(Cur);
	        CString Name;
	        int Playernum;
	        Playernum=m_PlayerName.GetCount();
	        int i=0;
            do
	        {
		        m_PlayerName.GetLBText(i,Name);
		        if(Name==Cur)
		        {
					if(m_HomeRadio.GetCheck())
					{
						pParent->Events[pParent->EventPt].Player1=pParent->HomePlayers[i];
						pParent->EventPt++;
						pParent->EventNum++;
						OnBnClickedEventrefreshBotton();
						return;
					}
					else
					{
						pParent->Events[pParent->EventPt].Player1=pParent->AwayPlayers[i];
						pParent->EventPt++;
						pParent->EventNum++;
						OnBnClickedEventrefreshBotton();
						return;
					}
			     
		        }
		        i++;
	        }
	        while((Name!=Cur)&&(i<Playernum));
			if(m_HomeRadio.GetCheck())    //球员是新球员，分主客队存入球员数组并存入事件
			{
				if(m_PlayerNumCheck.GetCheck())
				{
					pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber=TRUE;
					CString Number;
					m_PlayerNum.GetWindowTextW(Number);
					pParent->HomePlayers[pParent->HomePlayerPt].PlayerNumber=_ttoi(Number);
				}
				else
					pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber=FALSE;
			    m_PlayerName.GetWindowTextW(pParent->HomePlayers[pParent->HomePlayerPt].PlayerName);
				CString PlayerExtra;
	            m_PlayerExtra.GetLBText(m_PlayerExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="无")
		            pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="足特")
		            pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="校友")
			        pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="教工")
				    pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pParent->HomePlayers[pParent->HomePlayerPt].IsFirst=FALSE;
				pParent->Events[pParent->EventPt].Player1=pParent->HomePlayers[pParent->HomePlayerPt];
				pParent->HomePlayerPt++;
				pParent->HomePlayerNum++;
				pParent->EventPt++;
				pParent->EventNum++;
				OnBnClickedEventrefreshBotton();
				return;
			}
			else
			{
				if(m_PlayerNumCheck.GetCheck())
				{
					pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber=TRUE;
					CString Number;
					m_PlayerNum.GetWindowTextW(Number);
					pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerNumber=_ttoi(Number);
				}
				else
					pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber=FALSE;
			    m_PlayerName.GetWindowTextW(pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerName);
				CString PlayerExtra;
	            m_PlayerExtra.GetLBText(m_PlayerExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="无")
		            pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="足特")
		            pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="校友")
			        pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="教工")
				    pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pParent->AwayPlayers[pParent->AwayPlayerPt].IsFirst=FALSE;
				pParent->Events[pParent->EventPt].Player1=pParent->AwayPlayers[pParent->AwayPlayerPt];
				pParent->AwayPlayerPt++;
				pParent->AwayPlayerNum++;
				pParent->EventPt++;
				pParent->EventNum++;
				OnBnClickedEventrefreshBotton();
				return;
			}
		}
	}
}


void CEventDlg::OnBnClickedPlayernumCheck()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_PlayerNumCheck.GetCheck())
		m_PlayerNum.EnableWindow(TRUE);
	else
		m_PlayerNum.EnableWindow(FALSE);
}


void CEventDlg::OnBnClickedPlayeroutnumCheck()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_PlayerOutNumCheck.GetCheck())
		m_PlayerOutNum.EnableWindow(TRUE);
	else
		m_PlayerOutNum.EnableWindow(FALSE);
}


void CEventDlg::OnBnClickedEventrefreshBotton()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	pParent->SortEvent();
	int num=pParent->EventNum;
	m_EventList.ResetContent();
	for(int i=0;i<num;i++)
	{
		pParent->Events[i].GetEventListOutStr();
		m_EventList.AddString(pParent->Events[i].EventListOutStr);
	}
	if(m_HomeRadio.GetCheck())
		OnBnClickedEventhomeRadio();
	else
		OnBnClickedEventawayRadio();
	GetDlgItem(IDC_EVENT_EDIT_BOTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_EVENT_DELETE_BOTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_EVENTUP_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_EVENTDOWN_BUTTON)->EnableWindow(FALSE);
}


void CEventDlg::OnLbnSelchangeEventList()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_EVENT_EDIT_BOTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_EVENT_DELETE_BOTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_EVENTUP_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_EVENTDOWN_BUTTON)->EnableWindow(TRUE);

}


void CEventDlg::OnBnClickedEventDeleteBotton()
{
	// TODO: 在此添加控件通知处理程序代码
	int del;
	del=m_EventList.GetCurSel();
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	for(int i=del;i<pParent->EventNum;i++)
	{
		pParent->Events[i]=pParent->Events[i+1];
	}
	pParent->EventNum--;
	pParent->EventPt--;
	OnBnClickedEventrefreshBotton();
}


void CEventDlg::OnBnClickedPlayerinnumCheck()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_PlayerInNumCheck.GetCheck())
		GetDlgItem(IDC_PLAYERINNUM_EDIT)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_PLAYERINNUM_EDIT)->EnableWindow(FALSE);
}


void CEventDlg::OnBnClickedEventupButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int up;
	EventInfo Temp;
	up=m_EventList.GetCurSel();
	if(up!=0)
	{
		Temp=pParent->Events[up];
		pParent->Events[up]=pParent->Events[up-1];
		pParent->Events[up-1]=Temp;
	}
	OnBnClickedEventrefreshBotton();
}


void CEventDlg::OnBnClickedEventdownButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int down;
	EventInfo Temp;
	down=m_EventList.GetCurSel();
	if(down!=pParent->EventNum-1)
	{
		Temp=pParent->Events[down];
		pParent->Events[down]=pParent->Events[down+1];
		pParent->Events[down+1]=Temp;
	}
	OnBnClickedEventrefreshBotton();
}
