#pragma once
#include "afxwin.h"


// CPenalty 对话框

class CPenalty : public CDialogEx
{
	DECLARE_DYNAMIC(CPenalty)

public:
	CPenalty(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPenalty();

// 对话框数据
	enum { IDD = IDD_PENALTY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CButton m_IsPenalty;
	CComboBox m_Homenum;
	CComboBox m_Homename;
	CButton m_Homegoal;
	CListBox m_Homelist;
	CComboBox m_Awaynum;
	CComboBox m_Awayname;
	CButton m_Awaygoal;
	CListBox m_Awaylist;
	void HomeListRefresh(void);
	void AwayListRefresh(void);
	afx_msg void OnCbnSelchangeHomenumCombo();
	afx_msg void OnCbnSelchangeAwaynumCombo();
	afx_msg void OnCbnSelchangeHomenameCombo();
	afx_msg void OnCbnSelchangeAwaynameCombo();
	afx_msg void OnBnClickedHomeaddButton();
	afx_msg void OnBnClickedAwayaddButton();
	afx_msg void OnLbnSelchangeHomeList();
	afx_msg void OnLbnSelchangeAwayList();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedHomeupButton();
	afx_msg void OnBnClickedAwayupButton();
	afx_msg void OnBnClickedHomedownButton();
	afx_msg void OnBnClickedAwaydownButton();
	afx_msg void OnBnClickedHomedelButton();
	afx_msg void OnBnClickedAwaydelButton();
	CEdit m_Time;
};
