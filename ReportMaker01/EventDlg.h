#pragma once
#include "EventEditDlg.h"
#include "afxwin.h"

// CEventDlg 对话框

class CEventDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEventDlg)

public:
	CEventDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEventDlg();

// 对话框数据
	enum { IDD = IDD_EVENT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	EventInfo Events[50];
	//事件
//	int EventPt;
	//事件标记
//	int EventNum;
	//事件数
	afx_msg void OnBnClickedEventEditBotton();
	virtual BOOL OnInitDialog();
	CComboBox m_PlayerNum;
	CComboBox m_EventType;
	int m_EventTime;
	int m_EventStoppageTime;
	CComboBox m_PlayerOutNum;
	int m_PlayerInNum;
//	CEdit m_PlayerOutName;
	CString m_PlayerInName;
	CButton m_EventEdit;
	CButton m_EventDelete;
	CComboBox m_PlayerOutName;
	CComboBox m_PlayerName;
	afx_msg void OnBnClickedOk();
	virtual void OnOK();
	CButton m_HomeRadio;
	afx_msg void OnBnClickedEventhomeRadio();
	afx_msg void OnBnClickedEventawayRadio();
	afx_msg void OnCbnSelchangeEventTypeCombo();
	afx_msg void OnCbnSelchangeEventPlayernumCombo();
	afx_msg void OnCbnEditchangeEventPlayernumCombo();
	afx_msg void OnCbnSelchangePlayernameCombo();
	afx_msg void OnCbnEditchangePlayernameCombo();
	afx_msg void OnCbnSelchangePlayeroutnumCombo();
	afx_msg void OnCbnEditchangePlayeroutnumCombo();
	afx_msg void OnCbnSelchangePlayeroutnameCombo();
	afx_msg void OnCbnEditchangePlayeroutnameCombo();
	afx_msg void OnBnClickedEventok();
	CComboBox m_PlayerExtra;
	CComboBox m_PlayerOutExtra;
	CComboBox m_PlayerInExtra;
	CButton m_PlayerNumCheck;
	CButton m_PlayerOutNumCheck;
	CButton m_PlayerInNumCheck;
	afx_msg void OnBnClickedPlayernumCheck();
	afx_msg void OnBnClickedPlayeroutnumCheck();
	afx_msg void OnBnClickedEventrefreshBotton();
	CListBox m_EventList;
	afx_msg void OnLbnSelchangeEventList();
	afx_msg void OnBnClickedEventDeleteBotton();
	afx_msg void OnBnClickedPlayerinnumCheck();
	afx_msg void OnBnClickedEventupButton();
	afx_msg void OnBnClickedEventdownButton();
};
