#pragma once
#include "afxwin.h"
#include "FirstElevenDlg.h"

// CPlayerEditDlg 对话框

class CPlayerEditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPlayerEditDlg)

public:
	CPlayerEditDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPlayerEditDlg();

// 对话框数据
	enum { IDD = IDD_PLAYEREDIT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	
	CComboBox m_PlayerEditExtra;
	
	virtual BOOL OnInitDialog();
	CButton m_PlayerEditNumCheck;
	CEdit m_PlayerEditNum;
	CEdit m_PlayerEditName;
	afx_msg void OnBnClickedOk();
};
