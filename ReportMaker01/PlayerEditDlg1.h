#pragma once
#include "afxwin.h"
#include "FirstElevenDlg.h"
// CPlayerEditDlg1 �Ի���

class CPlayerEditDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CPlayerEditDlg1)

public:
	CPlayerEditDlg1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPlayerEditDlg1();

// �Ի�������
	enum { IDD = IDD_PLAYEREDIT_DLG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CButton m_PlayerEditNumCheck;
	CEdit m_PlayerEditNum;
	CEdit m_PlayerEditName;
	CComboBox m_PlayerEditExtra;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
