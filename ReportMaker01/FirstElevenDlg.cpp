// FirstElevenDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ReportMaker01.h"
#include "FirstElevenDlg.h"
#include "afxdialogex.h"
#include "ReportMaker01Doc.h"


// CFirstElevenDlg �Ի���

IMPLEMENT_DYNAMIC(CFirstElevenDlg, CDialogEx)

CFirstElevenDlg::CFirstElevenDlg(CWnd* pParent)
	: CDialogEx(CFirstElevenDlg::IDD, pParent)
	, m_HomeName(_T(""))
	, m_AwayName(_T(""))
	, m_HomePlayerNumCheck(FALSE)
	, m_AwayPlayerNumCheck(FALSE)
	, m_HomePlayerNumber(0)
	, m_AwayPlayerNumber(0)
	, m_HomePlayerName(_T(""))
	, m_AwayPlayerName(_T(""))

	
	
{	
}

CFirstElevenDlg::~CFirstElevenDlg()
{
}


void CFirstElevenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_HOMENAME_EDIT, m_HomeName);
	DDX_Text(pDX, IDC_AWAYNAME_EDIT, m_AwayName);
	DDX_Check(pDX, IDC_HOME_PLAYERNUM_CHECK, m_HomePlayerNumCheck);
	DDX_Check(pDX, IDC_AWAY_PLAYERNUM_CHECK, m_AwayPlayerNumCheck);
	DDX_Text(pDX, IDC_HOME_PLAYERNUM_EDIT, m_HomePlayerNumber);
	DDX_Text(pDX, IDC_AWAY_PLAYERNUM_EDIT, m_AwayPlayerNumber);
	DDX_Text(pDX, IDC_HOME_PLAYERNAME_EDIT, m_HomePlayerName);
	DDX_Text(pDX, IDC_AWAY_PLAYERNAME_EDIT, m_AwayPlayerName);
	DDX_Control(pDX, IDC_HOME_PLAYEREXTRA_COMBO, m_HomePlayerExtra);
	DDX_Control(pDX, IDC_AWAY_PLAYEREXTRA_COMBO, m_AwayPlayerExtra);
	DDX_Control(pDX, IDC_HOME_PLAYER_LIST, m_HomePlayerList);
	DDX_Control(pDX, IDC_AWAY_PLAYER_LIST, m_AwayPlayerList);
	DDX_Control(pDX, IDC_HOME_PLAYEROK_BUTTON, m_HomePlayerOK);
	DDX_Control(pDX, IDC_AWAY_PLAYEROK_BUTTON, m_AwayPlayerOK);
	DDX_Control(pDX, IDC_HOME_PLAYERDELETE_BOTTON, m_HomePlayerDelete);
	DDX_Control(pDX, IDC_AWAY_PLAYERDELETE_BOTTON, m_AwayPlayerDelete);
	DDX_Control(pDX, IDC_HOMRPLAYERDOWN_BOTTON, m_HomePlayerDown);
	DDX_Control(pDX, IDC_HOMEPLAYERUP_BOTTON, m_HomePlayerUp);
	DDX_Control(pDX, IDC_HOME_PLAYEREDIT_BOTTON, m_HomePlayerEdit);
	DDX_Control(pDX, IDC_AWAYPLAYERUP_BOTTON, m_AwayPlayerUp);
	DDX_Control(pDX, IDC_AWAYPLAYERDOWN_BOTTON, m_AwayPlayerDown);
	DDX_Control(pDX, IDC_AWAY_PLAYEREDIT_BOTTON, m_AwayPlayerEdit);
}


BEGIN_MESSAGE_MAP(CFirstElevenDlg, CDialogEx)
	ON_BN_CLICKED(IDC_HOME_PLAYEROK_BUTTON, &CFirstElevenDlg::OnBnClickedHomePlayerokButton)
	ON_BN_CLICKED(IDC_HOMEREFRESH_BOTTON, &CFirstElevenDlg::OnBnClickedHomerefreshBotton)
	ON_LBN_SELCHANGE(IDC_HOME_PLAYER_LIST, &CFirstElevenDlg::OnLbnSelchangeHomePlayerList)
	ON_BN_CLICKED(IDC_HOME_PLAYERDELETE_BOTTON, &CFirstElevenDlg::OnBnClickedHomePlayerdeleteBotton)
	ON_BN_CLICKED(IDC_HOMEPLAYERUP_BOTTON, &CFirstElevenDlg::OnBnClickedHomeplayerupBotton)
	ON_BN_CLICKED(IDC_HOMRPLAYERDOWN_BOTTON, &CFirstElevenDlg::OnBnClickedHomrplayerdownBotton)
	ON_BN_CLICKED(IDC_HOME_PLAYEREDIT_BOTTON, &CFirstElevenDlg::OnBnClickedHomePlayereditBotton)
	ON_BN_CLICKED(IDOK, &CFirstElevenDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_AWAY_PLAYEROK_BUTTON, &CFirstElevenDlg::OnBnClickedAwayPlayerokButton)
	ON_BN_CLICKED(IDC_AWAYREFRESH_BOTTON, &CFirstElevenDlg::OnBnClickedAwayrefreshBotton)
	ON_LBN_SELCHANGE(IDC_AWAY_PLAYER_LIST, &CFirstElevenDlg::OnLbnSelchangeAwayPlayerList)
	ON_BN_CLICKED(IDC_AWAY_PLAYERDELETE_BOTTON, &CFirstElevenDlg::OnBnClickedAwayPlayerdeleteBotton)
	ON_BN_CLICKED(IDC_AWAYPLAYERDOWN_BOTTON, &CFirstElevenDlg::OnBnClickedAwayplayerdownBotton)
	ON_BN_CLICKED(IDC_AWAYPLAYERUP_BOTTON, &CFirstElevenDlg::OnBnClickedAwayplayerupBotton)
	ON_BN_CLICKED(IDC_AWAY_PLAYEREDIT_BOTTON, &CFirstElevenDlg::OnBnClickedAwayPlayereditBotton)
	ON_BN_CLICKED(IDC_HOME_PLAYERNUM_CHECK, &CFirstElevenDlg::OnBnClickedHomePlayernumCheck)
	ON_BN_CLICKED(IDC_AWAY_PLAYERNUM_CHECK, &CFirstElevenDlg::OnBnClickedAwayPlayernumCheck)
//	ON_WM_KEYDOWN()
	//ON_EN_CHANGE(IDC_HOME_PLAYERNAME_EDIT, &CFirstElevenDlg::OnEnChangeHomePlayernameEdit)
	ON_EN_KILLFOCUS(IDC_HOME_PLAYERNUM_EDIT, &CFirstElevenDlg::OnEnKillfocusHomePlayernumEdit)
	//ON_EN_CHANGE(IDC_AWAY_PLAYERNUM_EDIT, &CFirstElevenDlg::OnEnChangeAwayPlayernumEdit)
	ON_EN_KILLFOCUS(IDC_AWAY_PLAYERNUM_EDIT, &CFirstElevenDlg::OnEnKillfocusAwayPlayernumEdit)
END_MESSAGE_MAP()


// CFirstElevenDlg ��Ϣ�������


void CFirstElevenDlg::OnBnClickedHomePlayerokButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	UpdateData(TRUE);//��������
	if(pParent->HomePlayerNum==49)
	{
		AfxMessageBox(_T("�Ѵﵽ��Ա�������ޣ������������Ա"));
		return;
	}
	pParent->HomePlayers[pParent->HomePlayerPt].IsFirst=TRUE;
	if (m_HomePlayerNumCheck)
	{
		pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber= TRUE;
		for(int i=0;i<pParent->HomePlayerNum;i++)
		{
			if(pParent->HomePlayers[i].IsPlayerNumber && pParent->HomePlayers[i].PlayerNumber==m_HomePlayerNumber)
			{
				AfxMessageBox(_T("�벻Ҫ�����ظ�����Ա���룡"));
				return;
			}
		}
		pParent->HomePlayers[pParent->HomePlayerPt].PlayerNumber=m_HomePlayerNumber;//�ж���Ա�Ƿ��к��룬����ǣ���������
	}
	else
	{
		pParent->HomePlayers[pParent->HomePlayerPt].IsPlayerNumber= FALSE;
	}
	pParent->HomePlayers[pParent->HomePlayerPt].PlayerName=m_HomePlayerName;//������Ա����
	pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	CString HomePlayerExtra;
	m_HomePlayerExtra.GetLBText(m_HomePlayerExtra.GetCurSel(),HomePlayerExtra);
	if(HomePlayerExtra=="��")
		pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	else if(HomePlayerExtra=="����")
		pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_ZUTE;
	else if(HomePlayerExtra=="У��")
		pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_XIAOYOU;
	else if(HomePlayerExtra=="�̹�")
		pParent->HomePlayers[pParent->HomePlayerPt].PlayerExtra=PLAYER_JIAOGONG;//������Ա������Ϣ
	pParent->HomePlayerPt++;
	pParent->HomePlayerNum++;
	OnBnClickedHomerefreshBotton();//ˢ���б��
	GetDlgItem(IDC_HOME_PLAYERNAME_EDIT)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_HOME_PLAYERNUM_EDIT)->SetWindowTextW(_T(""));
	m_HomePlayerExtra.SetCurSel(0);
	if(m_HomePlayerNumCheck)
		GetDlgItem(IDC_HOME_PLAYERNUM_EDIT)->SetFocus();
	else
	{
		GetDlgItem(IDC_HOME_PLAYERNUM_EDIT)->SetFocus();
		GetDlgItem(IDC_HOME_PLAYERNUM_EDIT)->SetWindowTextW(_T("0"));
	}
}






void CFirstElevenDlg::OnBnClickedHomerefreshBotton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	m_HomePlayerList.ResetContent();//����б��
    CString CurPlayerStr;
	int i=0;
	for(i=0;i<pParent->HomePlayerNum;i++)//����Ա��Ϣ�������μ����б��
	{
		pParent->HomePlayers[i].GetPlayerNameOutStr();
		if(pParent->HomePlayers[i].IsFirst)
			m_HomePlayerList.AddString(pParent->HomePlayers[i].PlayerNameOutStr);
	
	}
	CString HomeNum;
	HomeNum.Format(_T("������%d"),m_HomePlayerList.GetCount());
	GetDlgItem(IDC_HOMENUM_STATIC)->SetWindowTextW(HomeNum);
	m_HomePlayerDelete.EnableWindow(FALSE);
	m_HomePlayerDown.EnableWindow(FALSE);
	m_HomePlayerUp.EnableWindow(FALSE);
	m_HomePlayerEdit.EnableWindow(FALSE);
}




void CFirstElevenDlg::OnLbnSelchangeHomePlayerList()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_HomePlayerDelete.EnableWindow(TRUE);
	m_HomePlayerDown.EnableWindow(TRUE);
	m_HomePlayerEdit.EnableWindow(TRUE);
	m_HomePlayerUp.EnableWindow(TRUE);//ֻ���б��ѡ��ʱ���Բ����ĸ���ť
}


void CFirstElevenDlg::OnBnClickedHomePlayerdeleteBotton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int cur;
	cur=m_HomePlayerList.GetCurSel();
	int i=0,j=0;
	for(i=0;i<pParent->HomePlayerNum;i++)
	{
		if(pParent->HomePlayers[i].IsFirst)
			j++;
		if(j==cur+1)
			break;
	}
	int del;
	del=i;

	for(int i=del;i<pParent->HomePlayerNum;i++)
	{
		pParent->HomePlayers[i]=pParent->HomePlayers[i+1];//ɾ����Ա��Ϣ
	}
	pParent->HomePlayerNum--;
	pParent->HomePlayerPt--;
	OnBnClickedHomerefreshBotton();
	m_HomePlayerDelete.EnableWindow(FALSE);
	m_HomePlayerDown.EnableWindow(FALSE);
	m_HomePlayerUp.EnableWindow(FALSE);
	m_HomePlayerEdit.EnableWindow(FALSE);
}


void CFirstElevenDlg::OnBnClickedHomeplayerupBotton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();

	int cur;
	cur=m_HomePlayerList.GetCurSel();
	int i=0,j=0;
	for(i=0;i<pParent->HomePlayerNum;i++)
	{
		if(pParent->HomePlayers[i].IsFirst)
			j++;
		if(j==cur+1)
			break;
	}
    int up,prev;
	PlayerInfo temp;
	up=i;
	
	i=0;j=0;
	for(i=0;i<pParent->HomePlayerNum;i++)
	{
		if(pParent->HomePlayers[i].IsFirst)
			j++;
		if(j==cur)
			break;
	}
	prev=i;

	if(up!=0)
	{
		temp=pParent->HomePlayers[up];
		pParent->HomePlayers[up]=pParent->HomePlayers[prev];//������Ա��Ϣ
		pParent->HomePlayers[prev]=temp;
	}
	OnBnClickedHomerefreshBotton();
	m_HomePlayerDelete.EnableWindow(FALSE);
	m_HomePlayerDown.EnableWindow(FALSE);
	m_HomePlayerUp.EnableWindow(FALSE);
	m_HomePlayerEdit.EnableWindow(FALSE);
}


void CFirstElevenDlg::OnBnClickedHomrplayerdownBotton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();

	int cur;
	cur=m_HomePlayerList.GetCurSel();
	int i=0,j=0;
	for(i=0;i<pParent->HomePlayerNum;i++)
	{
		if(pParent->HomePlayers[i].IsFirst)
			j++;
		if(j==cur+1)
			break;
	}
    int down,next;
	PlayerInfo temp;
	down=i;
	
	i=0;j=0;
	for(i=0;i<pParent->HomePlayerNum;i++)
	{
		if(pParent->HomePlayers[i].IsFirst)
			j++;
		if(j==cur+2)
			break;
	}
	next=i;
	if(i==pParent->HomePlayerNum)
		next=down;
	if(down!=m_HomePlayerList.GetCount()-1)
	{
		temp=pParent->HomePlayers[down];
		pParent->HomePlayers[down]=pParent->HomePlayers[next];//������Ա��Ϣ
		pParent->HomePlayers[next]=temp;
	}
	OnBnClickedHomerefreshBotton();

}


void CFirstElevenDlg::OnBnClickedHomePlayereditBotton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CPlayerEditDlg DlgPlayerEdit;
	DlgPlayerEdit.DoModal();//�����༭�ӶԻ���

	OnBnClickedHomerefreshBotton();
}

BOOL CFirstElevenDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	m_HomePlayerExtra.SetCurSel(0);
	m_AwayPlayerExtra.SetCurSel(0);
	GetDlgItem(IDC_HOMENAME_EDIT)->SetWindowTextW(pParent->HomeName);
	GetDlgItem(IDC_AWAYNAME_EDIT)->SetWindowTextW(pParent->AwayName);
	m_HomeName=pParent->HomeName;
	m_AwayName=pParent->AwayName;
	OnBnClickedHomerefreshBotton();
	OnBnClickedAwayrefreshBotton();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CFirstElevenDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	UpdateData(TRUE);
	pParent->HomeName=m_HomeName;
	pParent->AwayName=m_AwayName;
	pParent->UpdateAllViews(NULL);
	CDialogEx::OnOK();
}


void CFirstElevenDlg::OnBnClickedAwayPlayerokButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	UpdateData(TRUE);//��������
	if(pParent->AwayPlayerNum==49)
	{
		AfxMessageBox(_T("�Ѵﵽ��Ա�������ޣ������������Ա"));
		return;
	}
	pParent->AwayPlayers[pParent->AwayPlayerPt].IsFirst=TRUE;
	if (m_AwayPlayerNumCheck)
	{
		pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber= TRUE;
		for(int i=0;i<pParent->AwayPlayerNum;i++)
		{
			if(pParent->AwayPlayers[i].IsPlayerNumber && pParent->AwayPlayers[i].PlayerNumber==m_AwayPlayerNumber)
			{
				AfxMessageBox(_T("�벻Ҫ�����ظ�����Ա���룡"));
				return;
			}
		}
		pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerNumber=m_AwayPlayerNumber;//�ж���Աʮ���к��룬����ǣ���������
	}
	else
	{
			pParent->AwayPlayers[pParent->AwayPlayerPt].IsPlayerNumber= FALSE;
	}
	pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerName=m_AwayPlayerName;//������Ա����
	pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	CString AwayPlayerExtra;
	m_AwayPlayerExtra.GetLBText(m_AwayPlayerExtra.GetCurSel(),AwayPlayerExtra);
	if(AwayPlayerExtra=="��")
		pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	else if(AwayPlayerExtra=="����")
		pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_ZUTE;
	else if(AwayPlayerExtra=="У��")
		pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_XIAOYOU;
	else if(AwayPlayerExtra=="�̹�")
		pParent->AwayPlayers[pParent->AwayPlayerPt].PlayerExtra=PLAYER_JIAOGONG;//������Ա������Ϣ
	pParent->AwayPlayerPt++;
	pParent->AwayPlayerNum++;
	OnBnClickedAwayrefreshBotton();//ˢ���б��
	GetDlgItem(IDC_AWAY_PLAYERNAME_EDIT)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_AWAY_PLAYERNUM_EDIT)->SetWindowTextW(_T(""));
	m_AwayPlayerExtra.SetCurSel(0);
	if(m_AwayPlayerNumCheck)
		GetDlgItem(IDC_AWAY_PLAYERNUM_EDIT)->SetFocus();
	else
	{
		GetDlgItem(IDC_AWAY_PLAYERNUM_EDIT)->SetFocus();
		GetDlgItem(IDC_AWAY_PLAYERNUM_EDIT)->SetWindowTextW(_T("0"));
	}
}


void CFirstElevenDlg::OnBnClickedAwayrefreshBotton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	m_AwayPlayerList.ResetContent();//����б��
    CString CurPlayerStr;
	int i=0;
	for(i=0;i<pParent->AwayPlayerNum;i++)//����Ա��Ϣ�������μ����б��
	{
		pParent->AwayPlayers[i].GetPlayerNameOutStr();
		if(pParent->AwayPlayers[i].IsFirst)
			m_AwayPlayerList.AddString(pParent->AwayPlayers[i].PlayerNameOutStr);
	
		
	}
	CString AwayNum;
	AwayNum.Format(_T("������%d"),m_AwayPlayerList.GetCount());
	GetDlgItem(IDC_AWAYNUM_STATIC)->SetWindowTextW(AwayNum);
	m_AwayPlayerDelete.EnableWindow(FALSE);
	m_AwayPlayerDown.EnableWindow(FALSE);
	m_AwayPlayerUp.EnableWindow(FALSE);
	m_AwayPlayerEdit.EnableWindow(FALSE);
}


void CFirstElevenDlg::OnLbnSelchangeAwayPlayerList()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_AwayPlayerDelete.EnableWindow(TRUE);
	m_AwayPlayerDown.EnableWindow(TRUE);
	m_AwayPlayerEdit.EnableWindow(TRUE);
	m_AwayPlayerUp.EnableWindow(TRUE);//ֻ���б��ѡ��ʱ���Բ����ĸ���ť
}


void CFirstElevenDlg::OnBnClickedAwayPlayerdeleteBotton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int cur;
	cur=m_AwayPlayerList.GetCurSel();
	int i=0,j=0;
	for(i=0;i<pParent->AwayPlayerNum;i++)
	{
		if(pParent->AwayPlayers[i].IsFirst)
			j++;
		if(j==cur+1)
			break;
	}
	int del;
	del=i;
	for(int i=del;i<pParent->AwayPlayerNum;i++)
	{
		pParent->AwayPlayers[i]=pParent->AwayPlayers[i+1];//ɾ����Ա��Ϣ
	}
	pParent->AwayPlayerNum--;
	pParent->AwayPlayerPt--;
	OnBnClickedAwayrefreshBotton();
	m_AwayPlayerDelete.EnableWindow(FALSE);
	m_AwayPlayerDown.EnableWindow(FALSE);
	m_AwayPlayerUp.EnableWindow(FALSE);
	m_AwayPlayerEdit.EnableWindow(FALSE);
}


void CFirstElevenDlg::OnBnClickedAwayplayerdownBotton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int cur;
	cur=m_AwayPlayerList.GetCurSel();
	int i=0,j=0;
	for(i=0;i<pParent->AwayPlayerNum;i++)
	{
		if(pParent->AwayPlayers[i].IsFirst)
			j++;
		if(j==cur+1)
			break;
	}
    int down,next;
	PlayerInfo temp;
	down=i;
	
	i=0;j=0;
	for(i=0;i<pParent->AwayPlayerNum;i++)
	{
		if(pParent->AwayPlayers[i].IsFirst)
			j++;
		if(j==cur+2)
			break;
	}
	next=i;
	if(i==pParent->AwayPlayerNum)
		next=down;
	if(down!=m_AwayPlayerList.GetCount()-1)
	{
		temp=pParent->AwayPlayers[down];
		pParent->AwayPlayers[down]=pParent->AwayPlayers[next];//������Ա��Ϣ
		pParent->AwayPlayers[next]=temp;
	}
	OnBnClickedAwayrefreshBotton();
	m_AwayPlayerDelete.EnableWindow(FALSE);
	m_AwayPlayerDown.EnableWindow(FALSE);
	m_AwayPlayerUp.EnableWindow(FALSE);
	m_AwayPlayerEdit.EnableWindow(FALSE);

}


void CFirstElevenDlg::OnBnClickedAwayplayerupBotton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int cur=m_AwayPlayerList.GetCurSel();
	int i=0,j=0;
	for(i=0;i<pParent->AwayPlayerNum;i++)
	{
		if(pParent->AwayPlayers[i].IsFirst)
			j++;
		if(j==cur+1)
			break;
	}
	int up,prev;
	PlayerInfo temp;
	up=i;
	i=0;j=0;
	for(i=0;i<pParent->AwayPlayerNum;i++)
	{
		if(pParent->AwayPlayers[i].IsFirst)
			j++;
		if(j==cur)
			break;
	}
	prev=i;
	if(up!=0)
	{
		temp=pParent->AwayPlayers[up];
		pParent->AwayPlayers[up]=pParent->AwayPlayers[prev];//������Ա��Ϣ
		pParent->AwayPlayers[prev]=temp;
	}
	OnBnClickedAwayrefreshBotton();
	m_AwayPlayerDelete.EnableWindow(FALSE);
	m_AwayPlayerDown.EnableWindow(FALSE);
	m_AwayPlayerUp.EnableWindow(FALSE);
	m_AwayPlayerEdit.EnableWindow(FALSE);
}


void CFirstElevenDlg::OnBnClickedAwayPlayereditBotton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CPlayerEditDlg1 DlgPlayerEdit;
	DlgPlayerEdit.DoModal();//�����༭�ӶԻ���
    OnBnClickedAwayrefreshBotton();
}


void CFirstElevenDlg::OnBnClickedHomePlayernumCheck()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if(m_HomePlayerNumCheck)
	{
		GetDlgItem(IDC_HOME_PLAYERNUM_EDIT)->SetWindowTextW(_T(""));
		GetDlgItem(IDC_HOME_PLAYERNUM_EDIT)->SetFocus();
	}
	else
	{
		GetDlgItem(IDC_HOME_PLAYERNUM_EDIT)->SetWindowTextW(_T("0"));
		GetDlgItem(IDC_HOME_PLAYERNAME_EDIT)->SetFocus();
	}
}


void CFirstElevenDlg::OnBnClickedAwayPlayernumCheck()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if(m_AwayPlayerNumCheck)
	{
		GetDlgItem(IDC_AWAY_PLAYERNUM_EDIT)->SetWindowTextW(_T(""));
		GetDlgItem(IDC_AWAY_PLAYERNUM_EDIT)->SetFocus();
	}
	else
	{
		GetDlgItem(IDC_AWAY_PLAYERNUM_EDIT)->SetWindowTextW(_T("0"));
		GetDlgItem(IDC_AWAY_PLAYERNAME_EDIT)->SetFocus();
	}
}


//void CFirstElevenDlg::OnEnChangeHomePlayernameEdit()
//{
//	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
//	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
//	// ���������� CRichEditCtrl().SetEventMask()��
//	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
//
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//	
//}


//void CFirstElevenDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	if(nChar==VK_RETURN && GetDlgItem(IDC_HOME_PLAYERNAME_EDIT)->GetSafeHwnd() == ::GetFocus())
//		OnBnClickedHomePlayerokButton();
//	else if(nChar==VK_RETURN && GetDlgItem(IDC_AWAY_PLAYERNAME_EDIT)==GetFocus())
//		OnBnClickedAwayPlayerokButton();
//
//	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
//}


//void CFirstElevenDlg::OnEnChangeHomePlayernameEdit()
//{
//	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
//	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
//	// ���������� CRichEditCtrl().SetEventMask()��
//	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
//
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}


BOOL CFirstElevenDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	if(pMsg-> wParam==VK_RETURN && GetDlgItem(IDC_HOME_PLAYERNAME_EDIT)==GetFocus())   
       {  
		   OnBnClickedHomePlayerokButton();
       }
	else if(pMsg-> wParam==VK_RETURN && GetDlgItem(IDC_AWAY_PLAYERNAME_EDIT)==GetFocus())   
       {  
		   OnBnClickedAwayPlayerokButton();
       }
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CFirstElevenDlg::OnEnKillfocusHomePlayernumEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(!(GetDlgItem(IDC_HOME_PLAYERNAME_EDIT)==GetFocus())) 
		GetDlgItem(IDC_HOME_PLAYERNUM_EDIT)->SetWindowTextW(_T("0"));
}


//void CFirstElevenDlg::OnEnChangeAwayPlayernumEdit()
//{
//	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
//	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
//	// ���������� CRichEditCtrl().SetEventMask()��
//	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
//
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//
//}


void CFirstElevenDlg::OnEnKillfocusAwayPlayernumEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		if(!(GetDlgItem(IDC_AWAY_PLAYERNAME_EDIT)==GetFocus())) 
		GetDlgItem(IDC_AWAY_PLAYERNUM_EDIT)->SetWindowTextW(_T("0"));
}
