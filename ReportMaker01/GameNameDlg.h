#pragma once
#include "afxwin.h"


// CGameNameDlg 对话框

class CGameNameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGameNameDlg)

public:
	CGameNameDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGameNameDlg();

// 对话框数据
	enum { IDD = IDD_GAMENAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_GameNameEdit;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
