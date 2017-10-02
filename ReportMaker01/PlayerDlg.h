#pragma once
#include "afxwin.h"


// CPlayerDlg 对话框

class CPlayerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPlayerDlg)

public:
	CPlayerDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPlayerDlg();

// 对话框数据
	enum { IDD = IDD_PLAYER_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_HomePlayerList;
	CListBox m_AwayPlayerList;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedHomerefreshBn();
	afx_msg void OnBnClickedAwayrefreshBn();
//	afx_msg void OnLbnSelchangeList4();
	afx_msg void OnLbnSelchangeHomelist();
	afx_msg void OnLbnSelchangeAwaylist();
	afx_msg void OnBnClickedHomedelBn();
	afx_msg void OnBnClickedAwaydelBn();
	afx_msg void OnBnClickedOk();
};
