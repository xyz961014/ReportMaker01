#pragma once
#include "afxwin.h"
#include "FirstElevenDlg.h"

// CPlayerEditDlg �Ի���

class CPlayerEditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPlayerEditDlg)

public:
	CPlayerEditDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPlayerEditDlg();

// �Ի�������
	enum { IDD = IDD_PLAYEREDIT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	
	CComboBox m_PlayerEditExtra;
	
	virtual BOOL OnInitDialog();
	CButton m_PlayerEditNumCheck;
	CEdit m_PlayerEditNum;
	CEdit m_PlayerEditName;
	afx_msg void OnBnClickedOk();
};
