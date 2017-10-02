
// ReportMaker01.h : ReportMaker01 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CReportMaker01App:
// �йش����ʵ�֣������ ReportMaker01.cpp
//

class CReportMaker01App : public CWinApp
{
public:
	CReportMaker01App();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnVideo();
};

extern CReportMaker01App theApp;

class PlayerInfo
{
public:
	BOOL IsFirst;
	CString PlayerName;
	int PlayerNumber;
	BOOL IsPlayerNumber;
	int PlayerExtra;
	CString PlayerNameOutStr;
	void GetPlayerNameOutStr(void)  
	{
		CString CurPlayerStr;
		if(PlayerExtra==PLAYER_NULL)
		{
			if(IsPlayerNumber)
			    CurPlayerStr.Format(_T("%d-%s"),PlayerNumber,PlayerName);
		    else
			    CurPlayerStr=PlayerName;
			PlayerNameOutStr=CurPlayerStr;
		}
		else if(PlayerExtra==PLAYER_ZUTE)
		{
			if(IsPlayerNumber)
			    CurPlayerStr.Format(_T("%d-%s(����)"),PlayerNumber,PlayerName);
		    else
			    CurPlayerStr.Format(_T("%s(����)"),PlayerName);
		        PlayerNameOutStr=CurPlayerStr;
		}
		else if(PlayerExtra==PLAYER_XIAOYOU)
		{
			if(IsPlayerNumber)
			    CurPlayerStr.Format(_T("%d-%s(У��)"),PlayerNumber,PlayerName);
		    else
			    CurPlayerStr.Format(_T("%s(У��)"),PlayerName);
		        PlayerNameOutStr=CurPlayerStr;
		}
		else if(PlayerExtra==PLAYER_JIAOGONG)
		{
			if(IsPlayerNumber)
			    CurPlayerStr.Format(_T("%d-%s(�̹�)"),PlayerNumber,PlayerName);
		    else
			    CurPlayerStr.Format(_T("%s(�̹�)"),PlayerName);
		        PlayerNameOutStr=CurPlayerStr;
		}
	}
};

class EventInfo
{
public:
	BOOL IsHome;
	CString Timestr;
	CString EventListOutStr;
	int Time;
	int StoppageTime;
	int EventType;
	PlayerInfo Player1;
	PlayerInfo Player2;
	void GetTime(void)
	{
		if (StoppageTime!=0)
			Timestr.Format(_T("%d+%d"),Time,StoppageTime);
		else
			Timestr.Format(_T("%d"),Time);
		
	}
	void GetEventListOutStr(void)
	{
		GetTime();
		Player1.GetPlayerNameOutStr();
		Player2.GetPlayerNameOutStr();
		if(IsHome==TRUE)
		{
			if(EventType==EVENT_GOAL)
				EventListOutStr.Format(_T("��        %s'        ����        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_OWNGOAL)
				EventListOutStr.Format(_T("��        %s'        ������        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_SUBSTITUTION)
				EventListOutStr.Format(_T("��        %s'        ���£�%s    ���ϣ�%s"),Timestr,Player1.PlayerNameOutStr,Player2.PlayerNameOutStr);
			else if(EventType==EVENT_YELLOW)
				EventListOutStr.Format(_T("��        %s'        ����        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_RED)
				EventListOutStr.Format(_T("��        %s'        ����        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_TWOYELLOW)
				EventListOutStr.Format(_T("��        %s'        ���Ʋ�һ��        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_PENALTY)
				EventListOutStr.Format(_T("��        %s'        ����        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_PENALTYMISS)
				EventListOutStr.Format(_T("��        %s'        ����ʧ        %s"),Timestr,Player1.PlayerNameOutStr);
		}
		else
		{
			if(EventType==EVENT_GOAL)
				EventListOutStr.Format(_T("��        %s'        ����        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_OWNGOAL)
				EventListOutStr.Format(_T("��        %s'        ������        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_SUBSTITUTION)
				EventListOutStr.Format(_T("��        %s'        ���£�%s    ���ϣ�%s"),Timestr,Player1.PlayerNameOutStr,Player2.PlayerNameOutStr);
			else if(EventType==EVENT_YELLOW)
				EventListOutStr.Format(_T("��        %s'        ����        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_RED)
				EventListOutStr.Format(_T("��        %s'        ����        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_TWOYELLOW)
				EventListOutStr.Format(_T("��        %s'        ���Ʋ�һ��        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_PENALTY)
				EventListOutStr.Format(_T("��        %s'        ����        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_PENALTYMISS)
				EventListOutStr.Format(_T("��        %s'        ����ʧ        %s"),Timestr,Player1.PlayerNameOutStr);
		}
	}
};

class CRectangle
{
public:
	int Width;
	int Height;
};

class PenaltyShootout
{
	public:
		PlayerInfo Player;
		BOOL IsGoal;
		CString ListOutstr;
		void GetListOutstr(void)
		{
			Player.GetPlayerNameOutStr();
			if(IsGoal)
				ListOutstr.Format(_T("%s        ����"),Player.PlayerNameOutStr);
			else
				ListOutstr.Format(_T("%s        ��ʧ"),Player.PlayerNameOutStr);
		}
};

class PlayerCheck
{
public:
	PlayerInfo Player;
	BOOL OnPitch;
	int Yellow;
	int TwoYellow;
	int Red;
	int Goal;
};
