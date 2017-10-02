// PlayerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ReportMaker01.h"
#include "PlayerDlg.h"
#include "afxdialogex.h"
#include "ReportMaker01Doc.h"


// CPlayerDlg �Ի���

IMPLEMENT_DYNAMIC(CPlayerDlg, CDialogEx)

CPlayerDlg::CPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPlayerDlg::IDD, pParent)
{

}

CPlayerDlg::~CPlayerDlg()
{
}

void CPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HOMELIST, m_HomePlayerList);
	DDX_Control(pDX, IDC_AWAYLIST, m_AwayPlayerList);
}


BEGIN_MESSAGE_MAP(CPlayerDlg, CDialogEx)
	ON_BN_CLICKED(IDC_HOMEREFRESH_BN, &CPlayerDlg::OnBnClickedHomerefreshBn)
	ON_BN_CLICKED(IDC_AWAYREFRESH_BN, &CPlayerDlg::OnBnClickedAwayrefreshBn)
	ON_LBN_SELCHANGE(IDC_HOMELIST, &CPlayerDlg::OnLbnSelchangeHomelist)
	ON_LBN_SELCHANGE(IDC_AWAYLIST, &CPlayerDlg::OnLbnSelchangeAwaylist)
	ON_BN_CLICKED(IDC_HOMEDEL_BN, &CPlayerDlg::OnBnClickedHomedelBn)
	ON_BN_CLICKED(IDC_AWAYDEL_BN, &CPlayerDlg::OnBnClickedAwaydelBn)
	ON_BN_CLICKED(IDOK, &CPlayerDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CPlayerDlg ��Ϣ�������


BOOL CPlayerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	OnBnClickedHomerefreshBn();
	OnBnClickedAwayrefreshBn();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CPlayerDlg::OnBnClickedHomerefreshBn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	m_HomePlayerList.ResetContent();
	int i=0;
	CString curplayer;
	for(i=0;i<pDoc->HomePlayerNum;i++)
	{
		pDoc->HomePlayers[i].GetPlayerNameOutStr();
		if(pDoc->HomePlayers[i].IsFirst)
			curplayer.Format(_T("%s          �׷���Ա"),pDoc->HomePlayers[i].PlayerNameOutStr);
		else
			curplayer.Format(_T("%s          �油��Ա"),pDoc->HomePlayers[i].PlayerNameOutStr);
		m_HomePlayerList.AddString(curplayer);
	}
	GetDlgItem(IDC_HOMEDEL_BN)->EnableWindow(FALSE);
	GetDlgItem(IDC_HOMEREFRESH_BN)->EnableWindow(FALSE);
}


void CPlayerDlg::OnBnClickedAwayrefreshBn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	m_AwayPlayerList.ResetContent();
	int i=0;
	CString curplayer;
	for(i=0;i<pDoc->AwayPlayerNum;i++)
	{
		pDoc->AwayPlayers[i].GetPlayerNameOutStr();
		if(pDoc->AwayPlayers[i].IsFirst)
			curplayer.Format(_T("%s          �׷���Ա"),pDoc->AwayPlayers[i].PlayerNameOutStr);
		else
			curplayer.Format(_T("%s          �油��Ա"),pDoc->AwayPlayers[i].PlayerNameOutStr);
		m_AwayPlayerList.AddString(curplayer);
	}
	GetDlgItem(IDC_AWAYDEL_BN)->EnableWindow(FALSE);
	GetDlgItem(IDC_AWAYREFRESH_BN)->EnableWindow(FALSE);
}


//void CPlayerDlg::OnLbnSelchangeList4()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//
//}


void CPlayerDlg::OnLbnSelchangeHomelist()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_HOMEDEL_BN)->EnableWindow(TRUE);
	GetDlgItem(IDC_HOMEREFRESH_BN)->EnableWindow(TRUE);
}


void CPlayerDlg::OnLbnSelchangeAwaylist()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_AWAYDEL_BN)->EnableWindow(TRUE);
	GetDlgItem(IDC_AWAYREFRESH_BN)->EnableWindow(TRUE);
}


void CPlayerDlg::OnBnClickedHomedelBn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int del;
	del=m_HomePlayerList.GetCurSel();
	for(int i=del;i<pDoc->HomePlayerNum;i++)
	{
		pDoc->HomePlayers[i]=pDoc->HomePlayers[i+1];
	}
	pDoc->HomePlayerNum--;
	pDoc->HomePlayerPt--;
	OnBnClickedHomerefreshBn();
}


void CPlayerDlg::OnBnClickedAwaydelBn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int del;
	del=m_AwayPlayerList.GetCurSel();
	for(int i=del;i<pDoc->AwayPlayerNum;i++)
	{
		pDoc->AwayPlayers[i]=pDoc->AwayPlayers[i+1];
	}
	pDoc->AwayPlayerNum--;
	pDoc->AwayPlayerPt--;
	OnBnClickedAwayrefreshBn();
}


void CPlayerDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	pDoc->UpdateAllViews(NULL);
	CDialogEx::OnOK();
}
