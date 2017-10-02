// PlayerEditDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ReportMaker01.h"
#include "PlayerEditDlg.h"
#include "afxdialogex.h"
#include "ReportMaker01Doc.h"


// CPlayerEditDlg �Ի���

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


// CPlayerEditDlg ��Ϣ�������






BOOL CPlayerEditDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
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
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CPlayerEditDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
				AfxMessageBox(_T("�벻Ҫ�����ظ�����Ա���룡"));
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
	if(PlayerExtra=="��")
		pDoc->HomePlayers[cur].PlayerExtra=PLAYER_NULL;
	else if(PlayerExtra=="����")
		pDoc->HomePlayers[cur].PlayerExtra=PLAYER_ZUTE;
	else if(PlayerExtra=="У��")
		pDoc->HomePlayers[cur].PlayerExtra=PLAYER_XIAOYOU;
	else if(PlayerExtra=="�̹�")
		pDoc->HomePlayers[cur].PlayerExtra=PLAYER_JIAOGONG;

	CDialogEx::OnOK();
}
