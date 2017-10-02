// PlayerEditDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ReportMaker01.h"
#include "PlayerEditDlg.h"
#include "afxdialogex.h"
#include "ReportMaker01Doc.h"


// CPlayerEditDlg 对话框

IMPLEMENT_DYNAMIC(CPlayerEditDlg, CDialogEx)

CPlayerEditDlg::CPlayerEditDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPlayerEditDlg::IDD, pParent)

{

}

CPlayerEditDlg::~CPlayerEditDlg()
{
}

void CPlayerEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_PLAYEREXTRA_COMBO, m_PlayerEditExtra);
	DDX_Control(pDX, IDC_PLAYERNUM_CHECK, m_PlayerEditNumCheck);
	DDX_Control(pDX, IDC_PLAYERNUM_EDIT, m_PlayerEditNum);
	DDX_Control(pDX, IDC_PLAYERNAME_EDIT, m_PlayerEditName);
}


BEGIN_MESSAGE_MAP(CPlayerEditDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CPlayerEditDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CPlayerEditDlg 消息处理程序






BOOL CPlayerEditDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CFirstElevenDlg* pParent=(CFirstElevenDlg *)GetParent();
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();

	int Cur;
	Cur=pParent->m_HomePlayerList.GetCurSel();
	int i=0,j=0;
	for(i=0;i<pDoc->HomePlayerNum;i++)
	{
		if(pDoc->HomePlayers[i].IsFirst)
			j++;
		if(j==Cur+1)
			break;
	}


	int cur;
	cur=i;
	m_PlayerEditNumCheck.SetCheck(pDoc->HomePlayers[cur].IsPlayerNumber);
	CString PlayerNumstr;
	if(pDoc->HomePlayers[cur].IsPlayerNumber)
	{
		PlayerNumstr.Format(_T("%d"),pDoc->HomePlayers[cur].PlayerNumber);
	    m_PlayerEditNum.SetWindowTextW(PlayerNumstr);
	}
	m_PlayerEditName.SetWindowTextW(pDoc->HomePlayers[cur].PlayerName);
	if(pDoc->HomePlayers[cur].PlayerExtra==PLAYER_NULL)
		m_PlayerEditExtra.SetCurSel(0);
	else if(pDoc->HomePlayers[cur].PlayerExtra==PLAYER_ZUTE)
		m_PlayerEditExtra.SetCurSel(1);
	else if(pDoc->HomePlayers[cur].PlayerExtra==PLAYER_XIAOYOU)
		m_PlayerEditExtra.SetCurSel(2);
	else if(pDoc->HomePlayers[cur].PlayerExtra==PLAYER_JIAOGONG)
		m_PlayerEditExtra.SetCurSel(3);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CPlayerEditDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	CFirstElevenDlg* pParent=(CFirstElevenDlg *)GetParent();
	int Cur;
	Cur=pParent->m_HomePlayerList.GetCurSel();
	int i=0,j=0;
	for(i=0;i<pDoc->HomePlayerNum;i++)
	{
		if(pDoc->HomePlayers[i].IsFirst)
			j++;
		if(j==Cur+1)
			break;
	}


	int cur;
	cur=i;
	pDoc->HomePlayers[cur].IsPlayerNumber=m_PlayerEditNumCheck.GetCheck();
	int Num;
	CString PlayerNumstr;
	if(m_PlayerEditNumCheck.GetCheck())
	{
		m_PlayerEditNum.GetWindowTextW(PlayerNumstr);
	    Num=_ttoi(PlayerNumstr);
		for(int i=0;i<pDoc->HomePlayerNum;i++)
		{
			if(pDoc->HomePlayers[i].IsPlayerNumber && pDoc->HomePlayers[i].PlayerNumber==Num &&i!=cur)
			{
				AfxMessageBox(_T("请不要输入重复的球员号码！"));
				return;
			}
		}
	    pDoc->HomePlayers[cur].PlayerNumber=Num;
	}
	CString PlayerName;
	m_PlayerEditName.GetWindowTextW(PlayerName);
	pDoc->HomePlayers[cur].PlayerName=PlayerName;
		
	CString PlayerExtra;
	m_PlayerEditExtra.GetLBText(m_PlayerEditExtra.GetCurSel(),PlayerExtra);
	if(PlayerExtra=="无")
		pDoc->HomePlayers[cur].PlayerExtra=PLAYER_NULL;
	else if(PlayerExtra=="足特")
		pDoc->HomePlayers[cur].PlayerExtra=PLAYER_ZUTE;
	else if(PlayerExtra=="校友")
		pDoc->HomePlayers[cur].PlayerExtra=PLAYER_XIAOYOU;
	else if(PlayerExtra=="教工")
		pDoc->HomePlayers[cur].PlayerExtra=PLAYER_JIAOGONG;

	CDialogEx::OnOK();
}
