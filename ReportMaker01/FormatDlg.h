#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CFormatDlg �Ի���

class CFormatDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFormatDlg)

public:
	CFormatDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFormatDlg();

// �Ի�������
	enum { IDD = IDD_FORMAT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl m_SliderRed;
	CSliderCtrl m_SliderGreen;
	CSliderCtrl m_SliderBlue;
	CComboBox m_title;
	CComboBox m_name;
	//CComboBox m_time;
	CComboBox m_text;
	virtual BOOL OnInitDialog();
	CString strred,strgreen,strblue;
	CComboBox m_first;
	afx_msg void OnBnClickedOk();
	afx_msg void OnNMCustomdrawSliderred(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlidergreen(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderblue(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeCombotitle();
	afx_msg void OnCbnSelchangeComboname();
	afx_msg void OnCbnSelchangeCombonamefirst();
	afx_msg void OnCbnSelchangeCombotext();
	afx_msg void OnBnClickedButtondefault();
};
