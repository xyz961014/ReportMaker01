// PlayerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ReportMaker01.h"
#include "PlayerDlg.h"
#include "afxdialogex.h"
#include "ReportMaker01Doc.h"


// CPlayerDlg 对话框

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


// CPlayerDlg 消息处理程序


BOOL CPlayerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	OnBnClickedHomerefreshBn();
	OnBnClickedAwayrefreshBn();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CPlayerDlg::OnBnClickedHomerefreshBn()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	m_HomePlayerList.ResetContent();
	int i=0;
	CString curplayer;
	for(i=0;i<pDoc->HomePlayerNum;i++)
	{
		pDoc->HomePlayers[i].GetPlayerNameOutStr();
		if(pDoc->HomePlayers[i].IsFirst)
			curplayer.Format(_T("%s          首发球员"),pDoc->HomePlayers[i].PlayerNameOutStr);
		else
			curplayer.Format(_T("%s          替补球员"),pDoc->HomePlayers[i].PlayerNameOutStr);
		m_HomePlayerList.AddString(curplayer);
	}
	GetDlgItem(IDC_HOMEDEL_BN)->EnableWindow(FALSE);
	GetDlgItem(IDC_HOMEREFRESH_BN)->EnableWindow(FALSE);
}


void CPlayerDlg::OnBnClickedAwayrefreshBn()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	m_AwayPlayerList.ResetContent();
	int i=0;
	CString curplayer;
	for(i=0;i<pDoc->AwayPlayerNum;i++)
	{
		pDoc->AwayPlayers[i].GetPlayerNameOutStr();
		if(pDoc->AwayPlayers[i].IsFirst)
			curplayer.Format(_T("%s          首发球员"),pDoc->AwayPlayers[i].PlayerNameOutStr);
		else
			curplayer.Format(_T("%s          替补球员"),pDoc->AwayPlayers[i].PlayerNameOutStr);
		m_AwayPlayerList.AddString(curplayer);
	}
	GetDlgItem(IDC_AWAYDEL_BN)->EnableWindow(FALSE);
	GetDlgItem(IDC_AWAYREFRESH_BN)->EnableWindow(FALSE);
}


//void CPlayerDlg::OnLbnSelchangeList4()
//{
//	// TODO: 在此添加控件通知处理程序代码
//
//}


void CPlayerDlg::OnLbnSelchangeHomelist()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_HOMEDEL_BN)->EnableWindow(TRUE);
	GetDlgItem(IDC_HOMEREFRESH_BN)->EnableWindow(TRUE);
}


void CPlayerDlg::OnLbnSelchangeAwaylist()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_AWAYDEL_BN)->EnableWindow(TRUE);
	GetDlgItem(IDC_AWAYREFRESH_BN)->EnableWindow(TRUE);
}


void CPlayerDlg::OnBnClickedHomedelBn()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	pDoc->UpdateAllViews(NULL);
	CDialogEx::OnOK();
}
