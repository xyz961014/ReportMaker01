#pragma once
#include "afxwin.h"


// CEventEditDlg 对话框

class CEventEditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEventEditDlg)

public:
	CEventEditDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEventEditDlg();

// 对话框数据
	enum { IDD = IDD_EVENTEDIT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CEdit m_EventStoppageTime;
	CEdit m_EventTime;
	CComboBox m_EventType;
	CButton m_HomeRadio;
	CComboBox m_PlayerExtra;
	CComboBox m_PlayerInExtra;
	CEdit m_PlayerInName;
	CEdit m_PlayerInNum;
	CButton m_PlayerInNumCheck;
	CComboBox m_PlayerName;
	CComboBox m_PlayerNum;
	CButton m_PlayerNumCheck;
	CComboBox m_PlayerOutName;
	CComboBox m_PlayerOutNum;
	CButton m_PlayerOutNumCheck;
	virtual BOOL OnInitDialog();
	CComboBox m_PlayerOutExtra;
	afx_msg void OnBnClickedEventhomeRadio();
	afx_msg void OnBnClickedEventawayRadio();
	afx_msg void OnCbnSelchangePlayernameCombo();
	afx_msg void OnCbnSelchangePlayeroutnameCombo();
	afx_msg void OnCbnSelchangeEventPlayernumCombo();
	afx_msg void OnCbnSelchangePlayeroutnumCombo();
	afx_msg void OnCbnEditchangeEventPlayernumCombo();
	afx_msg void OnCbnEditchangePlayernameCombo();
	afx_msg void OnCbnEditchangePlayeroutnumCombo();
	afx_msg void OnCbnEditchangePlayeroutnameCombo();
	afx_msg void OnCbnSelchangeEventTypeCombo();
	afx_msg void OnBnClickedPlayernumCheck();
	afx_msg void OnBnClickedPlayeroutnumCheck();
	afx_msg void OnBnClickedPlayerinnumCheck();
};
