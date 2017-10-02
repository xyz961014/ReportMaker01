// GameNameDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ReportMaker01.h"
#include "GameNameDlg.h"
#include "afxdialogex.h"
#include "ReportMaker01Doc.h"

// CGameNameDlg �Ի���

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


// CGameNameDlg ��Ϣ�������


BOOL CGameNameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	m_GameNameEdit.SetWindowTextW(pDoc->GameName);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CGameNameDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	m_GameNameEdit.GetWindowTextW(pDoc->GameName);
	CDialogEx::OnOK();
}
