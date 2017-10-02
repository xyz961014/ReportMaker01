#pragma once


// CCheckDlg �Ի���

class CCheckDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCheckDlg)

public:
	CCheckDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCheckDlg();

// �Ի�������
	enum { IDD = IDD_CHECK_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	PlayerCheck HomePlayerStats[50];
	PlayerCheck AwayPlayerStats[50];
	int HomePlayerNum;
	int AwayPlayerNum;
	int HomeGoal;
	int AwayGoal;
	CString HomeStatic;
	CString AwayStatic;
	BOOL HomeProblem;
	BOOL AwayProblem;
};
