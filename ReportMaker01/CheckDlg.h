#pragma once


// CCheckDlg 对话框

class CCheckDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCheckDlg)

public:
	CCheckDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCheckDlg();

// 对话框数据
	enum { IDD = IDD_CHECK_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
