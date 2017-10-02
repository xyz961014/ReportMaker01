// PlayerEditDlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "ReportMaker01.h"
#include "PlayerEditDlg1.h"
#include "afxdialogex.h"
#include "ReportMaker01Doc.h"


// CPlayerEditDlg1 对话框

IMPLEMENT_DYNAMIC(CPlayerEditDlg1, CDialogEx)

CPlayerEditDlg1::CPlayerEditDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPlayerEditDlg1::IDD, pParent)
{

}

CPlayerEditDlg1::~CPlayerEditDlg1()
{
}

void CPlayerEditDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PLAYERNUM_CHECK, m_PlayerEditNumCheck);
	DDX_Control(pDX, IDC_PLAYERNUM_EDIT, m_PlayerEditNum);
	DDX_Control(pDX, IDC_PLAYERNAME_EDIT, m_PlayerEditName);
	DDX_Control(pDX, IDC_PLAYEREXTRA_COMBO, m_PlayerEditExtra);
}


BEGIN_MESSAGE_MAP(CPlayerEditDlg1, CDialogEx)
	ON_BN_CLICKED(IDOK, &CPlayerEditDlg1::OnBnClickedOk)
END_MESSAGE_MAP()


// CPlayerEditDlg1 消息处理程序


BOOL CPlayerEditDlg1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	CFirstElevenDlg* pParent=(CFirstElevenDlg *)GetParent();
	int Cur;
	Cur=pParent->m_AwayPlayerList.GetCurSel();
	int i=0,j=0;
	for(i=0;i<pDoc->AwayPlayerNum;i++)
	{
		if(pDoc->AwayPlayers[i].IsFirst)
			j++;
		if(j==Cur+1)
			break;
	}


	int cur;
	cur=i;
	m_PlayerEditNumCheck.SetCheck(pDoc->AwayPlayers[cur].IsPlayerNumber);
	CString PlayerNumstr;
	if(pDoc->AwayPlayers[cur].IsPlayerNumber)
	{
		PlayerNumstr.Format(_T("%d"),pDoc->AwayPlayers[cur].PlayerNumber);
	    m_PlayerEditNum.SetWindowTextW(PlayerNumstr);
	}
	m_PlayerEditName.SetWindowTextW(pDoc->AwayPlayers[cur].PlayerName);
	if(pDoc->AwayPlayers[cur].PlayerExtra==PLAYER_NULL)
		m_PlayerEditExtra.SetCurSel(0);
	else if(pDoc->AwayPlayers[cur].PlayerExtra==PLAYER_ZUTE)
		m_PlayerEditExtra.SetCurSel(1);
	else if(pDoc->AwayPlayers[cur].PlayerExtra==PLAYER_XIAOYOU)
		m_PlayerEditExtra.SetCurSel(2);
	else if(pDoc->AwayPlayers[cur].PlayerExtra==PLAYER_JIAOGONG)
		m_PlayerEditExtra.SetCurSel(3);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CPlayerEditDlg1::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	CFirstElevenDlg* pParent=(CFirstElevenDlg *)GetParent();
	int Cur;
	Cur=pParent->m_AwayPlayerList.GetCurSel();
	int i=0,j=0;
	for(i=0;i<pDoc->AwayPlayerNum;i++)
	{
		if(pDoc->AwayPlayers[i].IsFirst)
			j++;
		if(j==Cur+1)
			break;
	}


	int cur;
	cur=i;
	pDoc->AwayPlayers[cur].IsPlayerNumber=m_PlayerEditNumCheck.GetCheck();
	int Num;
	CString PlayerNumstr;
	if(m_PlayerEditNumCheck.GetCheck())
	{
		int len=m_PlayerEditNum.LineLength();
	    m_PlayerEditNum.GetLine(0,PlayerNumstr.GetBuffer(len),len);
	    PlayerNumstr.ReleaseBuffer(len);
	    Num=_ttoi(PlayerNumstr);
		for(int i=0;i<pDoc->AwayPlayerNum;i++)
		{
			if(pDoc->AwayPlayers[i].IsPlayerNumber && pDoc->AwayPlayers[i].PlayerNumber==Num &&i!=cur)
			{
				AfxMessageBox(_T("请不要输入重复的球员号码！"));
				return;
			}
		}
	    pDoc->AwayPlayers[cur].PlayerNumber=Num;
	}
	CString PlayerName;
	int len=m_PlayerEditName.LineLength();
	m_PlayerEditName.GetLine(0,PlayerName.GetBuffer(len),len);
	PlayerName.ReleaseBuffer(len);
	pDoc->AwayPlayers[cur].PlayerName=PlayerName;
		
	CString PlayerExtra;
	m_PlayerEditExtra.GetLBText(m_PlayerEditExtra.GetCurSel(),PlayerExtra);
	if(PlayerExtra=="无")
		pDoc->AwayPlayers[cur].PlayerExtra=PLAYER_NULL;
	else if(PlayerExtra=="足特")
		pDoc->AwayPlayers[cur].PlayerExtra=PLAYER_ZUTE;
	else if(PlayerExtra=="校友")
		pDoc->AwayPlayers[cur].PlayerExtra=PLAYER_XIAOYOU;
	else if(PlayerExtra=="教工")
		pDoc->AwayPlayers[cur].PlayerExtra=PLAYER_JIAOGONG;
	CDialogEx::OnOK();
}
