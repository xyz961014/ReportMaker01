#pragma once
#include "afxwin.h"


// CGameNameDlg �Ի���

class CGameNameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGameNameDlg)

public:
	CGameNameDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGameNameDlg();

// �Ի�������
	enum { IDD = IDD_GAMENAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_GameNameEdit;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
