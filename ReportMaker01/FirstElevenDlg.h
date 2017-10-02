#pragma once
#include "PlayerEditDlg.h"
#include "PlayerEditDlg1.h"
#include "afxwin.h"
#include "ReportMaker01.h"

// CFirstElevenDlg 对话框

class CFirstElevenDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFirstElevenDlg)

public:
	CFirstElevenDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFirstElevenDlg();

// 对话框数据
	enum { IDD = IDD_FIRSTELEVEN_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_HomeName;
	CString m_AwayName;
	BOOL m_HomePlayerNumCheck;
	BOOL m_AwayPlayerNumCheck;
	int m_HomePlayerNumber;
	int m_AwayPlayerNumber;
	CString m_HomePlayerName;
	CString m_AwayPlayerName;
	CComboBox m_HomePlayerExtra;
	CComboBox m_AwayPlayerExtra;
	CListBox m_HomePlayerList;
	CListBox m_AwayPlayerList;
//	PlayerInfo HomePlayers[30];
//	PlayerInfo AwayPlayers[30];
	afx_msg void OnBnClickedHomePlayerokButton();
//	int HomePlayerPt;
//	int AwayPlayerPt;
//	int HomePlayerNum;
//	int AwayPlayerNum;
	afx_msg void OnBnClickedHomerefreshBotton();
	CButton m_HomePlayerOK;
	CButton m_AwayPlayerOK;
	CButton m_HomePlayerDelete;
	CButton m_AwayPlayerDelete;
	afx_msg void OnLbnSelchangeHomePlayerList();
	afx_msg void OnBnClickedHomePlayerdeleteBotton();
	CButton m_HomePlayerDown;
	CButton m_HomePlayerUp;
	CButton m_HomePlayerEdit;
	CButton m_AwayPlayerUp;
	CButton m_AwayPlayerDown;
	CButton m_AwayPlayerEdit;
	afx_msg void OnBnClickedHomeplayerupBotton();
	afx_msg void OnBnClickedHomrplayerdownBotton();
	afx_msg void OnBnClickedHomePlayereditBotton();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedAwayPlayerokButton();
	afx_msg void OnBnClickedAwayrefreshBotton();
	afx_msg void OnLbnSelchangeAwayPlayerList();
	afx_msg void OnBnClickedAwayPlayerdeleteBotton();
	afx_msg void OnBnClickedAwayplayerdownBotton();
	afx_msg void OnBnClickedAwayplayerupBotton();
	afx_msg void OnBnClickedAwayPlayereditBotton();
	afx_msg void OnBnClickedHomePlayernumCheck();
	afx_msg void OnBnClickedAwayPlayernumCheck();
//	afx_msg void OnEnChangeHomePlayernameEdit();
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnEnChangeHomePlayernameEdit();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnEnKillfocusHomePlayernumEdit();
//	afx_msg void OnEnChangeAwayPlayernumEdit();
	afx_msg void OnEnKillfocusAwayPlayernumEdit();
};
