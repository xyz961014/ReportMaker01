#pragma once
#include "afxwin.h"
#include "FirstElevenDlg.h"
// CPlayerEditDlg1 对话框

class CPlayerEditDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CPlayerEditDlg1)

public:
	CPlayerEditDlg1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPlayerEditDlg1();

// 对话框数据
	enum { IDD = IDD_PLAYEREDIT_DLG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton m_PlayerEditNumCheck;
	CEdit m_PlayerEditNum;
	CEdit m_PlayerEditName;
	CComboBox m_PlayerEditExtra;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
