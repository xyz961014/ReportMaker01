// EventEditDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ReportMaker01.h"
#include "EventEditDlg.h"
#include "afxdialogex.h"
#include "ReportMaker01Doc.h"
#include "EventDlg.h"


// CEventEditDlg �Ի���

IMPLEMENT_DYNAMIC(CEventEditDlg, CDialogEx)

CEventEditDlg::CEventEditDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEventEditDlg::IDD, pParent)
{

}

CEventEditDlg::~CEventEditDlg()
{
}

void CEventEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EVENT_STOPPAGETIME_EDIT, m_EventStoppageTime);
	DDX_Control(pDX, IDC_EVENT_TIME_EDIT, m_EventTime);
	DDX_Control(pDX, IDC_EVENT_TYPE_COMBO, m_EventType);
	DDX_Control(pDX, IDC_EVENTHOME_RADIO, m_HomeRadio);
	DDX_Control(pDX, IDC_EVENT_PLAYEREXTRA_COMBO, m_PlayerExtra);
	DDX_Control(pDX, IDC_EVENT_PLAYERINEXTRA_COMBO, m_PlayerInExtra);
	DDX_Control(pDX, IDC_PLAYERINNAME_EDIT, m_PlayerInName);
	DDX_Control(pDX, IDC_PLAYERINNUM_EDIT, m_PlayerInNum);
	DDX_Control(pDX, IDC_PLAYERINNUM_CHECK, m_PlayerInNumCheck);
	DDX_Control(pDX, IDC_PLAYERNAME_COMBO, m_PlayerName);
	DDX_Control(pDX, IDC_EVENT_PLAYERNUM_COMBO, m_PlayerNum);
	DDX_Control(pDX, IDC_PLAYERNUM_CHECK, m_PlayerNumCheck);
	DDX_Control(pDX, IDC_PLAYEROUTNAME_COMBO, m_PlayerOutName);
	DDX_Control(pDX, IDC_PLAYEROUTNUM_COMBO, m_PlayerOutNum);
	DDX_Control(pDX, IDC_PLAYEROUTNUM_CHECK, m_PlayerOutNumCheck);
	DDX_Control(pDX, IDC_EVENT_PLAYEROUTEXTRA_COMBO, m_PlayerOutExtra);
}


BEGIN_MESSAGE_MAP(CEventEditDlg, CDialogEx)
	ON_BN_CLICKED(IDC_OK, &CEventEditDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CANCEL, &CEventEditDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_EVENTHOME_RADIO, &CEventEditDlg::OnBnClickedEventhomeRadio)
	ON_BN_CLICKED(IDC_EVENTAWAY_RADIO, &CEventEditDlg::OnBnClickedEventawayRadio)
	ON_CBN_SELCHANGE(IDC_PLAYERNAME_COMBO, &CEventEditDlg::OnCbnSelchangePlayernameCombo)
	ON_CBN_SELCHANGE(IDC_PLAYEROUTNAME_COMBO, &CEventEditDlg::OnCbnSelchangePlayeroutnameCombo)
	ON_CBN_SELCHANGE(IDC_EVENT_PLAYERNUM_COMBO, &CEventEditDlg::OnCbnSelchangeEventPlayernumCombo)
	ON_CBN_SELCHANGE(IDC_PLAYEROUTNUM_COMBO, &CEventEditDlg::OnCbnSelchangePlayeroutnumCombo)
	ON_CBN_EDITCHANGE(IDC_EVENT_PLAYERNUM_COMBO, &CEventEditDlg::OnCbnEditchangeEventPlayernumCombo)
	ON_CBN_EDITCHANGE(IDC_PLAYERNAME_COMBO, &CEventEditDlg::OnCbnEditchangePlayernameCombo)
	ON_CBN_EDITCHANGE(IDC_PLAYEROUTNUM_COMBO, &CEventEditDlg::OnCbnEditchangePlayeroutnumCombo)
	ON_CBN_EDITCHANGE(IDC_PLAYEROUTNAME_COMBO, &CEventEditDlg::OnCbnEditchangePlayeroutnameCombo)
	ON_CBN_SELCHANGE(IDC_EVENT_TYPE_COMBO, &CEventEditDlg::OnCbnSelchangeEventTypeCombo)
	ON_BN_CLICKED(IDC_PLAYERNUM_CHECK, &CEventEditDlg::OnBnClickedPlayernumCheck)
	ON_BN_CLICKED(IDC_PLAYEROUTNUM_CHECK, &CEventEditDlg::OnBnClickedPlayeroutnumCheck)
	ON_BN_CLICKED(IDC_PLAYERINNUM_CHECK, &CEventEditDlg::OnBnClickedPlayerinnumCheck)
END_MESSAGE_MAP()


// CEventEditDlg ��Ϣ�������


void CEventEditDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


void CEventEditDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	CEventDlg* pParent=(CEventDlg *)GetParent();
	UpdateData(TRUE);
	int n;
	CString Temp;
	n=pParent->m_EventList.GetCurSel();
	pDoc->Events[n].IsHome=m_HomeRadio.GetCheck();

	m_EventTime.GetWindowTextW(Temp);
	pDoc->Events[n].Time=_ttoi(Temp);

	m_EventStoppageTime.GetWindowTextW(Temp);
	pDoc->Events[n].StoppageTime=_ttoi(Temp);
	CString Type;
	m_EventType.GetLBText(m_EventType.GetCurSel(),Type);
	if(Type=="����")
		pDoc->Events[n].EventType=EVENT_GOAL;
	else if(Type=="������")
		pDoc->Events[n].EventType=EVENT_OWNGOAL;
	else if(Type=="����")
		pDoc->Events[n].EventType=EVENT_SUBSTITUTION;
	else if(Type=="����")
		pDoc->Events[n].EventType=EVENT_YELLOW;
	else if(Type=="����")
		pDoc->Events[n].EventType=EVENT_RED;
	else if(Type=="���Ʋ�һ��")
		pDoc->Events[n].EventType=EVENT_TWOYELLOW;
	else if(Type=="����")
		pDoc->Events[n].EventType=EVENT_PENALTY;
	else if(Type=="����ʧ")
		pDoc->Events[n].EventType=EVENT_PENALTYMISS;
	
	if(Type=="����")
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
		        if(Num==Cur) //������Ա��������������Ա�������Ͷ��½�������Ա������ʱ��
		        {
					if(m_HomeRadio.GetCheck())
					{
						pDoc->Events[n].Player1=pDoc->HomePlayers[i];
						if(m_PlayerInNumCheck.GetCheck())
						{
							pDoc->HomePlayers[pDoc->HomePlayerPt].IsPlayerNumber=TRUE;
							m_PlayerInNum.GetWindowTextW(Temp);
							pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerNumber=_ttoi(Temp);
						}
						else
							pDoc->HomePlayers[pDoc->HomePlayerPt].IsPlayerNumber=FALSE;
						m_PlayerInName.GetWindowTextW(pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerName);
					    CString PlayerExtra;
	                    m_PlayerInExtra.GetLBText(m_PlayerInExtra.GetCurSel(),PlayerExtra);
	                    if(PlayerExtra=="��")
		                    pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	                    else if(PlayerExtra=="����")
		                    pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_ZUTE;
	                    else if(PlayerExtra=="У��")
						    pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_XIAOYOU;
				        else if(PlayerExtra=="�̹�")
							pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_JIAOGONG;
						pDoc->HomePlayers[pDoc->HomePlayerPt].IsFirst=FALSE;
						pDoc->Events[n].Player2=pDoc->HomePlayers[pDoc->HomePlayerPt];
						pDoc->HomePlayerPt++;
						pDoc->HomePlayerNum++;
						CDialog::OnOK();return;
					}
					else
					{
						pDoc->Events[n].Player1=pDoc->AwayPlayers[i];
						if(m_PlayerInNumCheck.GetCheck())
						{
							pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsPlayerNumber=TRUE;
							m_PlayerInNum.GetWindowTextW(Temp);
							pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerNumber=_ttoi(Temp);
						}
						else
							pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsPlayerNumber=FALSE;
						m_PlayerInName.GetWindowTextW(pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerName);
					    CString PlayerExtra;
	                    m_PlayerInExtra.GetLBText(m_PlayerInExtra.GetCurSel(),PlayerExtra);
	                    if(PlayerExtra=="��")
		                    pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	                    else if(PlayerExtra=="����")
		                    pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_ZUTE;
	                    else if(PlayerExtra=="У��")
						    pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_XIAOYOU;
				        else if(PlayerExtra=="�̹�")
							pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_JIAOGONG;
						pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsFirst=FALSE;
						pDoc->Events[n].Player2=pDoc->AwayPlayers[pDoc->AwayPlayerPt];
						pDoc->AwayPlayerNum++;
						pDoc->AwayPlayerPt++;
						CDialog::OnOK();return;
					}
			     
		        }
		        i++;
	        }
	        while((Num!=Cur)&&(i<Playernum));

			if(m_HomeRadio.GetCheck())    //������Ա������Ա�������ͶӴ�����Ա���鲢�����¼�
			{
				if(m_PlayerOutNumCheck.GetCheck())
				{
					pDoc->HomePlayers[pDoc->HomePlayerPt].IsPlayerNumber=TRUE;
					CString Number;
					m_PlayerOutNum.GetWindowTextW(Number);
					pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerNumber=_ttoi(Number);
				}
				else
					pDoc->HomePlayers[pDoc->HomePlayerPt].IsPlayerNumber=FALSE;
			    m_PlayerOutName.GetWindowTextW(pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerName);
				CString PlayerExtra;
	            m_PlayerOutExtra.GetLBText(m_PlayerOutExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="��")
		            pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="����")
		            pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="У��")
			        pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="�̹�")
				    pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pDoc->HomePlayers[pDoc->HomePlayerPt].IsFirst=FALSE;
				pDoc->Events[n].Player1=pDoc->HomePlayers[pDoc->HomePlayerPt];
				pDoc->HomePlayerPt++;
				pDoc->HomePlayerNum++;
				if(m_PlayerInNumCheck.GetCheck())
				{
					pDoc->HomePlayers[pDoc->HomePlayerPt].IsPlayerNumber=TRUE;
					m_PlayerInNum.GetWindowTextW(Temp);
					pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerNumber=_ttoi(Temp);
				}
				else
					pDoc->HomePlayers[pDoc->HomePlayerPt].IsPlayerNumber=FALSE;
				m_PlayerInName.GetWindowTextW(pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerName);
	            m_PlayerInExtra.GetLBText(m_PlayerInExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="��")
		            pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="����")
		            pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="У��")
	     			pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="�̹�")
					pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pDoc->HomePlayers[pDoc->HomePlayerPt].IsFirst=FALSE;
				pDoc->Events[n].Player2=pDoc->HomePlayers[pDoc->HomePlayerPt];
				pDoc->HomePlayerPt++;
				pDoc->HomePlayerNum++;
				CDialog::OnOK();return;
			}
			else
			{
				if(m_PlayerOutNumCheck.GetCheck())
				{
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsPlayerNumber=TRUE;
					CString Number;
					m_PlayerOutNum.GetWindowTextW(Number);
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerNumber=_ttoi(Number);
				}
				else
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsPlayerNumber=FALSE;
			    m_PlayerOutName.GetWindowTextW(pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerName);
				CString PlayerExtra;
	            m_PlayerOutExtra.GetLBText(m_PlayerOutExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="��")
		            pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="����")
		            pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="У��")
			        pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="�̹�")
				    pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsFirst=FALSE;
				pDoc->Events[n].Player1=pDoc->AwayPlayers[pDoc->AwayPlayerPt];
				pDoc->AwayPlayerPt++;
				pDoc->AwayPlayerNum++;
				if(m_PlayerInNumCheck.GetCheck())
				{
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsPlayerNumber=TRUE;
					m_PlayerInNum.GetWindowTextW(Temp);
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerNumber=_ttoi(Temp);
				}
				else
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsPlayerNumber=FALSE;
				m_PlayerInName.GetWindowTextW(pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerName);
	            m_PlayerInExtra.GetLBText(m_PlayerInExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="��")
		            pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="����")
		            pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="У��")
	     			pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="�̹�")
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsFirst=FALSE;
				pDoc->Events[n].Player2=pDoc->AwayPlayers[pDoc->AwayPlayerPt];
				pDoc->AwayPlayerPt++;
				pDoc->AwayPlayerNum++;
				CDialog::OnOK();return;
			}
		} 
		else    //������Աû�к�������
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
						pDoc->Events[n].Player1=pDoc->HomePlayers[i];
						if(m_PlayerInNumCheck.GetCheck())
						{
							pDoc->HomePlayers[pDoc->HomePlayerPt].IsPlayerNumber=TRUE;
							m_PlayerInNum.GetWindowTextW(Temp);
							pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerNumber=_ttoi(Temp);
						}
						else
							pDoc->HomePlayers[pDoc->HomePlayerPt].IsPlayerNumber=FALSE;
						m_PlayerInName.GetWindowTextW(pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerName);
					    CString PlayerExtra;
	                    m_PlayerInExtra.GetLBText(m_PlayerInExtra.GetCurSel(),PlayerExtra);
	                    if(PlayerExtra=="��")
		                    pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	                    else if(PlayerExtra=="����")
		                    pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_ZUTE;
	                    else if(PlayerExtra=="У��")
						    pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_XIAOYOU;
				        else if(PlayerExtra=="�̹�")
							pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_JIAOGONG;
						pDoc->HomePlayers[pDoc->HomePlayerPt].IsFirst=FALSE;
						pDoc->Events[n].Player2=pDoc->HomePlayers[pDoc->HomePlayerPt];
						pDoc->HomePlayerPt++;
						pDoc->HomePlayerNum++;
						CDialog::OnOK();return;
					}
					else
					{
						pDoc->Events[n].Player1=pDoc->AwayPlayers[i];
						if(m_PlayerInNumCheck.GetCheck())
						{
							pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsPlayerNumber=TRUE;
							m_PlayerInNum.GetWindowTextW(Temp);
							pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerNumber=_ttoi(Temp);
						}
						else
							pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsPlayerNumber=FALSE;
						m_PlayerInName.GetWindowTextW(pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerName);
					    CString PlayerExtra;
	                    m_PlayerInExtra.GetLBText(m_PlayerInExtra.GetCurSel(),PlayerExtra);
	                    if(PlayerExtra=="��")
		                    pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	                    else if(PlayerExtra=="����")
		                    pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_ZUTE;
	                    else if(PlayerExtra=="У��")
						    pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_XIAOYOU;
				        else if(PlayerExtra=="�̹�")
							pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_JIAOGONG;
						pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsFirst=FALSE;
						pDoc->Events[n].Player2=pDoc->AwayPlayers[pDoc->AwayPlayerPt];
						pDoc->AwayPlayerNum++;
						pDoc->AwayPlayerPt++;
						CDialog::OnOK();return;
					}
			     
		        }
		        i++;
	        }
	        while((Name!=Cur)&&(i<Playernum));
			if(m_HomeRadio.GetCheck())    //������Ա������Ա�������ͶӴ�����Ա���鲢�����¼�
			{
				if(m_PlayerOutNumCheck.GetCheck())
				{
					pDoc->HomePlayers[pDoc->HomePlayerPt].IsPlayerNumber=TRUE;
					CString Number;
					m_PlayerOutNum.GetWindowTextW(Number);
					pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerNumber=_ttoi(Number);
				}
				else
					pDoc->HomePlayers[pDoc->HomePlayerPt].IsPlayerNumber=FALSE;
			    m_PlayerOutName.GetWindowTextW(pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerName);
				CString PlayerExtra;
	            m_PlayerOutExtra.GetLBText(m_PlayerOutExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="��")
		            pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="����")
		            pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="У��")
			        pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="�̹�")
				    pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pDoc->HomePlayers[pDoc->HomePlayerPt].IsFirst=FALSE;
				pDoc->Events[n].Player1=pDoc->HomePlayers[pDoc->HomePlayerPt];
				pDoc->HomePlayerPt++;
				pDoc->HomePlayerNum++;
				if(m_PlayerInNumCheck.GetCheck())
				{
					pDoc->HomePlayers[pDoc->HomePlayerPt].IsPlayerNumber=TRUE;
					m_PlayerInNum.GetWindowTextW(Temp);
					pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerNumber=_ttoi(Temp);
				}
				else
					pDoc->HomePlayers[pDoc->HomePlayerPt].IsPlayerNumber=FALSE;
				m_PlayerInName.GetWindowTextW(pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerName);
	            m_PlayerInExtra.GetLBText(m_PlayerInExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="��")
		            pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="����")
		            pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="У��")
	     			pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="�̹�")
					pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pDoc->HomePlayers[pDoc->HomePlayerPt].IsFirst=FALSE;
				pDoc->Events[n].Player2=pDoc->HomePlayers[pDoc->HomePlayerPt];
				pDoc->HomePlayerPt++;
				pDoc->HomePlayerNum++;
				CDialog::OnOK();return;
			}
			else
			{
				if(m_PlayerOutNumCheck.GetCheck())
				{
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsPlayerNumber=TRUE;
					CString Number;
					m_PlayerOutNum.GetWindowTextW(Number);
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerNumber=_ttoi(Number);
				}
				else
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsPlayerNumber=FALSE;
			    m_PlayerOutName.GetWindowTextW(pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerName);
				CString PlayerExtra;
	            m_PlayerOutExtra.GetLBText(m_PlayerOutExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="��")
		            pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="����")
		            pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="У��")
			        pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="�̹�")
				    pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsFirst=FALSE;
				pDoc->Events[n].Player1=pDoc->AwayPlayers[pDoc->AwayPlayerPt];
				pDoc->AwayPlayerPt++;
				pDoc->AwayPlayerNum++;
				if(m_PlayerInNumCheck.GetCheck())
				{
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsPlayerNumber=TRUE;
					m_PlayerInNum.GetWindowTextW(Temp);
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerNumber=_ttoi(Temp);
				}
				else
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsPlayerNumber=FALSE;
				m_PlayerInName.GetWindowTextW(pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerName);
	            m_PlayerInExtra.GetLBText(m_PlayerInExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="��")
		            pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="����")
		            pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="У��")
	     			pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="�̹�")
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsFirst=FALSE;
				pDoc->Events[n].Player2=pDoc->AwayPlayers[pDoc->AwayPlayerPt];
				pDoc->AwayPlayerPt++;
				pDoc->AwayPlayerNum++;
				CDialog::OnOK();return;
			}
		}
	}
	else  //���ǡ����ˡ������
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
						pDoc->Events[n].Player1=pDoc->HomePlayers[i];
						CDialog::OnOK();return;
					}
					else
					{
						pDoc->Events[n].Player1=pDoc->AwayPlayers[i];
						CDialog::OnOK();return;
					}
			     
		        }
		        i++;
	        }
	        while((Num!=Cur)&&(i<Playernum));
			if(m_HomeRadio.GetCheck())    //��Ա������Ա�������ͶӴ�����Ա���鲢�����¼�
			{
				if(m_PlayerNumCheck.GetCheck())
				{
					pDoc->HomePlayers[pDoc->HomePlayerPt].IsPlayerNumber=TRUE;
					CString Number;
					m_PlayerNum.GetWindowTextW(Number);
					pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerNumber=_ttoi(Number);
				}
				else
					pDoc->HomePlayers[pDoc->HomePlayerPt].IsPlayerNumber=FALSE;
			    m_PlayerName.GetWindowTextW(pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerName);
				CString PlayerExtra;
	            m_PlayerExtra.GetLBText(m_PlayerExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="��")
		            pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="����")
		            pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="У��")
			        pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="�̹�")
				    pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pDoc->HomePlayers[pDoc->HomePlayerPt].IsFirst=FALSE;
				pDoc->Events[n].Player1=pDoc->HomePlayers[pDoc->HomePlayerPt];
				pDoc->HomePlayerPt++;
				pDoc->HomePlayerNum++;
				CDialog::OnOK();return;
			}
			else
			{
				if(m_PlayerNumCheck.GetCheck())
				{
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsPlayerNumber=TRUE;
					CString Number;
					m_PlayerNum.GetWindowTextW(Number);
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerNumber=_ttoi(Number);
				}
				else
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsPlayerNumber=FALSE;
			    m_PlayerName.GetWindowTextW(pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerName);
				CString PlayerExtra;
	            m_PlayerExtra.GetLBText(m_PlayerExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="��")
		            pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="����")
		            pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="У��")
			        pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="�̹�")
				    pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsFirst=FALSE;
				pDoc->Events[n].Player1=pDoc->AwayPlayers[pDoc->AwayPlayerPt];
				pDoc->AwayPlayerPt++;
				pDoc->AwayPlayerNum++;
				CDialog::OnOK();return;
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
						pDoc->Events[n].Player1=pDoc->HomePlayers[i];
						CDialog::OnOK();return;
					}
					else
					{
						pDoc->Events[n].Player1=pDoc->AwayPlayers[i];
						CDialog::OnOK();return;
					}
			     
		        }
		        i++;
	        }
	        while((Name!=Cur)&&(i<Playernum));
			if(m_HomeRadio.GetCheck())    //��Ա������Ա�������ͶӴ�����Ա���鲢�����¼�
			{
				if(m_PlayerNumCheck.GetCheck())
				{
					pDoc->HomePlayers[pDoc->HomePlayerPt].IsPlayerNumber=TRUE;
					CString Number;
					m_PlayerNum.GetWindowTextW(Number);
					pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerNumber=_ttoi(Number);
				}
				else
					pDoc->HomePlayers[pDoc->HomePlayerPt].IsPlayerNumber=FALSE;
			    m_PlayerName.GetWindowTextW(pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerName);
				CString PlayerExtra;
	            m_PlayerExtra.GetLBText(m_PlayerExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="��")
		            pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="����")
		            pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="У��")
			        pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="�̹�")
				    pDoc->HomePlayers[pDoc->HomePlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pDoc->HomePlayers[pDoc->HomePlayerPt].IsFirst=FALSE;
				pDoc->Events[n].Player1=pDoc->HomePlayers[pDoc->HomePlayerPt];
				pDoc->HomePlayerPt++;
				pDoc->HomePlayerNum++;
				CDialog::OnOK();return;
			}
			else
			{
				if(m_PlayerNumCheck.GetCheck())
				{
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsPlayerNumber=TRUE;
					CString Number;
					m_PlayerNum.GetWindowTextW(Number);
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerNumber=_ttoi(Number);
				}
				else
					pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsPlayerNumber=FALSE;
			    m_PlayerName.GetWindowTextW(pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerName);
				CString PlayerExtra;
	            m_PlayerExtra.GetLBText(m_PlayerExtra.GetCurSel(),PlayerExtra);
	            if(PlayerExtra=="��")
		            pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_NULL;
	            else if(PlayerExtra=="����")
		            pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_ZUTE;
	            else if(PlayerExtra=="У��")
			        pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_XIAOYOU;
			    else if(PlayerExtra=="�̹�")
				    pDoc->AwayPlayers[pDoc->AwayPlayerPt].PlayerExtra=PLAYER_JIAOGONG;
				pDoc->AwayPlayers[pDoc->AwayPlayerPt].IsFirst=FALSE;
				pDoc->Events[n].Player1=pDoc->AwayPlayers[pDoc->AwayPlayerPt];
				pDoc->AwayPlayerPt++;
				pDoc->AwayPlayerNum++;
				CDialog::OnOK();return;
			}
		}
	}
	
}


void CEventEditDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnCancel();
}


BOOL CEventEditDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	CEventDlg* pParent=(CEventDlg *)GetParent();
	m_HomeRadio.SetWindowTextW(pDoc->HomeName);
	GetDlgItem(IDC_EVENTAWAY_RADIO)->SetWindowTextW(pDoc->AwayName);
	int cur;
	cur=pParent->m_EventList.GetCurSel();
	EventInfo CurE;
	CString Temp;
	CurE=pDoc->Events[cur];
	m_HomeRadio.SetCheck(CurE.IsHome);
	((CButton *)GetDlgItem(IDC_EVENTAWAY_RADIO))->SetCheck(!CurE.IsHome);
	m_PlayerInExtra.SetCurSel(0);
	m_PlayerOutExtra.SetCurSel(0);
	if(CurE.IsHome)
	{
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
	}
	else
	{
		CString str;
	for(int i=0;i<pDoc->AwayPlayerNum;i++)
	{
		if(pDoc->AwayPlayers[i].IsPlayerNumber)
		{
			str.Format(_T("%d"),pDoc->AwayPlayers[i].PlayerNumber);
			m_PlayerNum.AddString(str);
			m_PlayerOutNum.AddString(str);
		}
		
	}
	m_PlayerNum.SetCurSel(0);
	m_PlayerOutNum.SetCurSel(0);
	for(int i=0;i<pDoc->AwayPlayerNum;i++)
	{
		m_PlayerName.AddString(pDoc->AwayPlayers[i].PlayerName);
		m_PlayerOutName.AddString(pDoc->AwayPlayers[i].PlayerName);
	}
	m_PlayerName.SetCurSel(0);
	m_PlayerOutName.SetCurSel(0);
	}
	Temp.Format(_T("%d"),CurE.Time);
	m_EventTime.SetWindowTextW(Temp);
	Temp.Format(_T("%d"),CurE.StoppageTime);
	m_EventStoppageTime.SetWindowTextW(Temp);
	if(CurE.EventType==EVENT_GOAL)
		m_EventType.SetCurSel(0);
	else if(CurE.EventType==EVENT_SUBSTITUTION)
		m_EventType.SetCurSel(1);
	else if(CurE.EventType==EVENT_YELLOW)
		m_EventType.SetCurSel(2);
	else if(CurE.EventType==EVENT_RED)
		m_EventType.SetCurSel(3);
	else if(CurE.EventType==EVENT_TWOYELLOW)
		m_EventType.SetCurSel(4);
	else if(CurE.EventType==EVENT_PENALTY)
		m_EventType.SetCurSel(5);
	else if(CurE.EventType==EVENT_OWNGOAL)
		m_EventType.SetCurSel(6);
	else if(CurE.EventType==EVENT_PENALTYMISS)
		m_EventType.SetCurSel(7);
	if(CurE.EventType==EVENT_SUBSTITUTION)
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
		if(CurE.Player1.IsPlayerNumber)
		{
			m_PlayerOutNumCheck.SetCheck(TRUE);
			Temp.Format(_T("%d"),CurE.Player1.PlayerNumber);
			m_PlayerOutNum.SetWindowTextW(Temp);
		}
		else
		{
			m_PlayerOutNumCheck.SetCheck(FALSE);
			m_PlayerOutNum.EnableWindow(FALSE);
		}
		if(CurE.Player2.IsPlayerNumber)
		{
			m_PlayerInNumCheck.SetCheck(TRUE);
			Temp.Format(_T("%d"),CurE.Player2.PlayerNumber);
			m_PlayerInNum.SetWindowTextW(Temp);
		}
		else
		{
			m_PlayerInNumCheck.SetCheck(FALSE);
			m_PlayerInNum.EnableWindow(FALSE);
		}
		m_PlayerOutName.SetWindowTextW(CurE.Player1.PlayerName);
		m_PlayerInName.SetWindowTextW(CurE.Player2.PlayerName);
		int Extra;
		Extra=CurE.Player1.PlayerExtra;
	    if(Extra==PLAYER_NULL)
			m_PlayerOutExtra.SetCurSel(0);
		else if(Extra==PLAYER_ZUTE)
			m_PlayerOutExtra.SetCurSel(1);
		else if(Extra==PLAYER_XIAOYOU)
			m_PlayerOutExtra.SetCurSel(2);
		else if(Extra==PLAYER_JIAOGONG)
			m_PlayerOutExtra.SetCurSel(3);
		Extra=CurE.Player2.PlayerExtra;
	    if(Extra==PLAYER_NULL)
			m_PlayerInExtra.SetCurSel(0);
		else if(Extra==PLAYER_ZUTE)
			m_PlayerInExtra.SetCurSel(1);
		else if(Extra==PLAYER_XIAOYOU)
			m_PlayerInExtra.SetCurSel(2);
		else if(Extra==PLAYER_JIAOGONG)
			m_PlayerInExtra.SetCurSel(3);
	}
	else
	{
		if(CurE.Player1.IsPlayerNumber)
		{
			m_PlayerNumCheck.SetCheck(TRUE);
			Temp.Format(_T("%d"),CurE.Player1.PlayerNumber);
			m_PlayerNum.SetWindowTextW(Temp);
		}
		else
		{
			m_PlayerNumCheck.SetCheck(FALSE);
			m_PlayerNum.EnableWindow(FALSE);
		}
		m_PlayerName.SetWindowTextW(CurE.Player1.PlayerName);
		int Extra;
		Extra=CurE.Player1.PlayerExtra;
	    if(Extra==PLAYER_NULL)
			m_PlayerExtra.SetCurSel(0);
		else if(Extra==PLAYER_ZUTE)
			m_PlayerExtra.SetCurSel(1);
		else if(Extra==PLAYER_XIAOYOU)
			m_PlayerExtra.SetCurSel(2);
		else if(Extra==PLAYER_JIAOGONG)
			m_PlayerExtra.SetCurSel(3);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CEventEditDlg::OnBnClickedEventhomeRadio()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
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
	m_PlayerNum.SetCurSel(0);
	m_PlayerOutNum.SetCurSel(0);
	for(int i=0;i<pParent->HomePlayerNum;i++)
	{
		m_PlayerName.AddString(pParent->HomePlayers[i].PlayerName);
		m_PlayerOutName.AddString(pParent->HomePlayers[i].PlayerName);
	}
	m_PlayerName.SetCurSel(0);
	m_PlayerOutName.SetCurSel(0);
	OnCbnSelchangePlayernameCombo();
	OnCbnSelchangePlayeroutnameCombo();
}


void CEventEditDlg::OnBnClickedEventawayRadio()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pParent=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
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
	m_PlayerNum.SetCurSel(0);
	m_PlayerOutNum.SetCurSel(0);
	for(int i=0;i<pParent->AwayPlayerNum;i++)
	{
		m_PlayerName.AddString(pParent->AwayPlayers[i].PlayerName);
		m_PlayerOutName.AddString(pParent->AwayPlayers[i].PlayerName);
	}
	m_PlayerName.SetCurSel(0);
	m_PlayerOutName.SetCurSel(0);
	OnCbnSelchangePlayernameCombo();
	OnCbnSelchangePlayeroutnameCombo();
	
}


void CEventEditDlg::OnCbnSelchangePlayernameCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void CEventEditDlg::OnCbnSelchangePlayeroutnameCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void CEventEditDlg::OnCbnSelchangeEventPlayernumCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void CEventEditDlg::OnCbnSelchangePlayeroutnumCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void CEventEditDlg::OnCbnEditchangeEventPlayernumCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
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
			m_PlayerName.SetCurSel(i);
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
	while((Num!=Cur)&&(i<Playernum));
}


void CEventEditDlg::OnCbnEditchangePlayernameCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString Cur;
	m_PlayerName.GetWindowTextW(Cur);
	CString Name;
	int Playernum;
	Playernum=m_PlayerNum.GetCount();
	int i=0;
    do
	{
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


void CEventEditDlg::OnCbnEditchangePlayeroutnumCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString Cur;
	m_PlayerOutNum.GetWindowTextW(Cur);
	CString Num;
	int Playernum;
	Playernum=m_PlayerOutNum.GetCount();
	int i=0;
    do
	{
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


void CEventEditDlg::OnCbnEditchangePlayeroutnameCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString Cur;
	m_PlayerOutName.GetWindowTextW(Cur);
	CString Name;
	int Playernum;
	Playernum=m_PlayerOutNum.GetCount();
	int i=0;
    do
	{
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


void CEventEditDlg::OnCbnSelchangeEventTypeCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void CEventEditDlg::OnBnClickedPlayernumCheck()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_PlayerNumCheck.GetCheck())
		m_PlayerNum.EnableWindow(TRUE);
	else
		m_PlayerNum.EnableWindow(FALSE);
}


void CEventEditDlg::OnBnClickedPlayeroutnumCheck()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_PlayerOutNumCheck.GetCheck())
		m_PlayerOutNum.EnableWindow(TRUE);
	else
		m_PlayerOutNum.EnableWindow(FALSE);
}


void CEventEditDlg::OnBnClickedPlayerinnumCheck()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_PlayerInNumCheck.GetCheck())
		GetDlgItem(IDC_PLAYERINNUM_EDIT)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_PLAYERINNUM_EDIT)->EnableWindow(FALSE);
}
