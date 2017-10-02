// FormatDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ReportMaker01.h"
#include "FormatDlg.h"
#include "afxdialogex.h"
#include "ReportMaker01View.h"


// CFormatDlg �Ի���

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


// CFormatDlg ��Ϣ�������


BOOL CFormatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
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
	if(pDoc->strtitle=="����")
		m_title.SetCurSel(0);
	else if(pDoc->strtitle=="����")
		m_title.SetCurSel(1);
	else if(pDoc->strtitle=="����")
		m_title.SetCurSel(2);
	else if(pDoc->strtitle=="΢���ź�")
		m_title.SetCurSel(3);

	if(pDoc->strname=="����")
		m_name.SetCurSel(0);
	else if(pDoc->strname=="����")
		m_name.SetCurSel(1);
	else if(pDoc->strname=="����")
		m_name.SetCurSel(2);
	else if(pDoc->strname=="΢���ź�")
		m_name.SetCurSel(3);

	if(pDoc->strfirst=="����")
		m_first.SetCurSel(0);
	else if(pDoc->strfirst=="����")
		m_first.SetCurSel(1);
	else if(pDoc->strfirst=="����")
		m_first.SetCurSel(2);
	else if(pDoc->strfirst=="΢���ź�")
		m_first.SetCurSel(3);

	if(pDoc->strtext=="����")
		m_text.SetCurSel(0);
	else if(pDoc->strtext=="����")
		m_text.SetCurSel(1);
	else if(pDoc->strtext=="����")
		m_text.SetCurSel(2);
	else if(pDoc->strtext=="΢���ź�")
		m_text.SetCurSel(3);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CFormatDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CFormatDlg::OnNMCustomdrawSliderred(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int n;
	n=m_title.GetCurSel();
	if(n==0)
		pDoc->strtitle="����";
	else if(n==1)
		pDoc->strtitle="����";
	else if(n==2)
		pDoc->strtitle="����";
	else if(n==3)
		pDoc->strtitle="΢���ź�";

}


void CFormatDlg::OnCbnSelchangeComboname()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int n;
	n=m_name.GetCurSel();
	if(n==0)
		pDoc->strname="����";
	else if(n==1)
		pDoc->strname="����";
	else if(n==2)
		pDoc->strname="����";
	else if(n==3)
		pDoc->strname="΢���ź�";

}


void CFormatDlg::OnCbnSelchangeCombonamefirst()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int n;
	n=m_first.GetCurSel();
	if(n==0)
		pDoc->strfirst="����";
	else if(n==1)
		pDoc->strfirst="����";
	else if(n==2)
		pDoc->strfirst="����";
	else if(n==3)
		pDoc->strfirst="΢���ź�";

}


void CFormatDlg::OnCbnSelchangeCombotext()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	int n;
	n=m_text.GetCurSel();
	if(n==0)
		pDoc->strtext="����";
	else if(n==1)
		pDoc->strtext="����";
	else if(n==2)
		pDoc->strtext="����";
	else if(n==3)
		pDoc->strtext="΢���ź�";

}


void CFormatDlg::OnBnClickedButtondefault()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReportMaker01Doc* pDoc=(CReportMaker01Doc *)((CFrameWnd*)AfxGetMainWnd())->GetActiveDocument();
	pDoc->linered=90;
	pDoc->linegreen=90;
	pDoc->lineblue=90;
	pDoc->strtitle="����";
	pDoc->strname="����";
	pDoc->strfirst="΢���ź�";
	pDoc->strtext="����";
	OnInitDialog();
}
