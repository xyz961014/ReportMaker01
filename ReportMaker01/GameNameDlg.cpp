// GameNameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ReportMaker01.h"
#include "GameNameDlg.h"
#include "afxdialogex.h"
#include "ReportMaker01Doc.h"

// CGameNameDlg 对话框

IMPLEMENT_DYNAMIC(CGameNameDlg, CDialogEx)

CGameNameDlg::CGameNameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGameNameDlg::IDD, pParent)
{

}

CGameNameDlg::~CGameNameDlg()
{
}

void CGameNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GAMENAME_EDIT, m_GameNameEdit);
}


BEGIN_MESSAGE_MAP(CGameNameDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CGameNameDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CGameNameDlg 消息处理程序


BOOL CGameNameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	m_GameNameEdit.SetWindowTextW(pDoc->GameName);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CGameNameDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	m_GameNameEdit.GetWindowTextW(pDoc->GameName);
	CDialogEx::OnOK();
}
