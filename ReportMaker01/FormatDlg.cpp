// FormatDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ReportMaker01.h"
#include "FormatDlg.h"
#include "afxdialogex.h"
#include "ReportMaker01View.h"


// CFormatDlg 对话框

IMPLEMENT_DYNAMIC(CFormatDlg, CDialogEx)

CFormatDlg::CFormatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFormatDlg::IDD, pParent)
{

}

CFormatDlg::~CFormatDlg()
{
}

void CFormatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDERRED, m_SliderRed);
	DDX_Control(pDX, IDC_SLIDERGREEN, m_SliderGreen);
	DDX_Control(pDX, IDC_SLIDERBLUE, m_SliderBlue);
	DDX_Control(pDX, IDC_COMBOTITLE, m_title);
	DDX_Control(pDX, IDC_COMBONAME, m_name);
	//DDX_Control(pDX, IDC_COMBOTIME, m_time);
	DDX_Control(pDX, IDC_COMBOTEXT, m_text);
	DDX_Control(pDX, IDC_COMBONAMEFIRST, m_first);
}


BEGIN_MESSAGE_MAP(CFormatDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CFormatDlg::OnBnClickedOk)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDERRED, &CFormatDlg::OnNMCustomdrawSliderred)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDERGREEN, &CFormatDlg::OnNMCustomdrawSlidergreen)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDERBLUE, &CFormatDlg::OnNMCustomdrawSliderblue)
	ON_CBN_SELCHANGE(IDC_COMBOTITLE, &CFormatDlg::OnCbnSelchangeCombotitle)
	ON_CBN_SELCHANGE(IDC_COMBONAME, &CFormatDlg::OnCbnSelchangeComboname)
	ON_CBN_SELCHANGE(IDC_COMBONAMEFIRST, &CFormatDlg::OnCbnSelchangeCombonamefirst)
	ON_CBN_SELCHANGE(IDC_COMBOTEXT, &CFormatDlg::OnCbnSelchangeCombotext)
	ON_BN_CLICKED(IDC_BUTTONDEFAULT, &CFormatDlg::OnBnClickedButtondefault)
END_MESSAGE_MAP()


// CFormatDlg 消息处理程序


BOOL CFormatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	m_SliderRed.SetRange(0,255);
	m_SliderGreen.SetRange(0,255);
	m_SliderBlue.SetRange(0,255);
	m_SliderRed.SetPos(pDoc->linered);
	m_SliderGreen.SetPos(pDoc->linegreen);
	m_SliderBlue.SetPos(pDoc->lineblue);
	strred.Format(_T("%d"),m_SliderRed.GetPos());
	strgreen.Format(_T("%d"),m_SliderGreen.GetPos());
	strblue.Format(_T("%d"),m_SliderBlue.GetPos());
	GetDlgItem(IDC_STATICRED)->SetWindowTextW(strred);
	GetDlgItem(IDC_STATICGREEN)->SetWindowTextW(strgreen);
	GetDlgItem(IDC_STATICBLUE)->SetWindowTextW(strblue);
	if(pDoc->strtitle=="黑体")
		m_title.SetCurSel(0);
	else if(pDoc->strtitle=="宋体")
		m_title.SetCurSel(1);
	else if(pDoc->strtitle=="仿宋")
		m_title.SetCurSel(2);
	else if(pDoc->strtitle=="微软雅黑")
		m_title.SetCurSel(3);

	if(pDoc->strname=="黑体")
		m_name.SetCurSel(0);
	else if(pDoc->strname=="宋体")
		m_name.SetCurSel(1);
	else if(pDoc->strname=="仿宋")
		m_name.SetCurSel(2);
	else if(pDoc->strname=="微软雅黑")
		m_name.SetCurSel(3);

	if(pDoc->strfirst=="黑体")
		m_first.SetCurSel(0);
	else if(pDoc->strfirst=="宋体")
		m_first.SetCurSel(1);
	else if(pDoc->strfirst=="仿宋")
		m_first.SetCurSel(2);
	else if(pDoc->strfirst=="微软雅黑")
		m_first.SetCurSel(3);

	if(pDoc->strtext=="黑体")
		m_text.SetCurSel(0);
	else if(pDoc->strtext=="宋体")
		m_text.SetCurSel(1);
	else if(pDoc->strtext=="仿宋")
		m_text.SetCurSel(2);
	else if(pDoc->strtext=="微软雅黑")
		m_text.SetCurSel(3);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CFormatDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CFormatDlg::OnNMCustomdrawSliderred(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int n;
	n=m_SliderRed.GetPos();
	CString str;
	str.Format(_T("%d"),n);
	GetDlgItem(IDC_STATICRED)->SetWindowTextW(str);
	pDoc->linered=n;
	*pResult = 0;
}


void CFormatDlg::OnNMCustomdrawSlidergreen(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int n;
	n=m_SliderGreen.GetPos();
	CString str;
	str.Format(_T("%d"),n);
	GetDlgItem(IDC_STATICGREEN)->SetWindowTextW(str);
	pDoc->linegreen=n;
	*pResult = 0;
}


void CFormatDlg::OnNMCustomdrawSliderblue(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int n;
	n=m_SliderBlue.GetPos();
	CString str;
	str.Format(_T("%d"),n);
	GetDlgItem(IDC_STATICBLUE)->SetWindowTextW(str);
	pDoc->lineblue=n;
	*pResult = 0;
}


void CFormatDlg::OnCbnSelchangeCombotitle()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int n;
	n=m_title.GetCurSel();
	if(n==0)
		pDoc->strtitle="黑体";
	else if(n==1)
		pDoc->strtitle="宋体";
	else if(n==2)
		pDoc->strtitle="仿宋";
	else if(n==3)
		pDoc->strtitle="微软雅黑";

}


void CFormatDlg::OnCbnSelchangeComboname()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int n;
	n=m_name.GetCurSel();
	if(n==0)
		pDoc->strname="黑体";
	else if(n==1)
		pDoc->strname="宋体";
	else if(n==2)
		pDoc->strname="仿宋";
	else if(n==3)
		pDoc->strname="微软雅黑";

}


void CFormatDlg::OnCbnSelchangeCombonamefirst()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int n;
	n=m_first.GetCurSel();
	if(n==0)
		pDoc->strfirst="黑体";
	else if(n==1)
		pDoc->strfirst="宋体";
	else if(n==2)
		pDoc->strfirst="仿宋";
	else if(n==3)
		pDoc->strfirst="微软雅黑";

}


void CFormatDlg::OnCbnSelchangeCombotext()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int n;
	n=m_text.GetCurSel();
	if(n==0)
		pDoc->strtext="黑体";
	else if(n==1)
		pDoc->strtext="宋体";
	else if(n==2)
		pDoc->strtext="仿宋";
	else if(n==3)
		pDoc->strtext="微软雅黑";

}


void CFormatDlg::OnBnClickedButtondefault()
{
	// TODO: 在此添加控件通知处理程序代码
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	pDoc->linered=90;
	pDoc->linegreen=90;
	pDoc->lineblue=90;
	pDoc->strtitle="黑体";
	pDoc->strname="仿宋";
	pDoc->strfirst="微软雅黑";
	pDoc->strtext="宋体";
	OnInitDialog();
}
