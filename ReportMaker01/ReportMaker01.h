
// ReportMaker01.h : ReportMaker01 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CReportMaker01App:
// 有关此类的实现，请参阅 ReportMaker01.cpp
//

class CReportMaker01App : public CWinApp
{
public:
	CReportMaker01App();


// 重写
public:
	virtual BOOL InitInstance();

// 实现
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
			    CurPlayerStr.Format(_T("%d-%s(足特)"),PlayerNumber,PlayerName);
		    else
			    CurPlayerStr.Format(_T("%s(足特)"),PlayerName);
		        PlayerNameOutStr=CurPlayerStr;
		}
		else if(PlayerExtra==PLAYER_XIAOYOU)
		{
			if(IsPlayerNumber)
			    CurPlayerStr.Format(_T("%d-%s(校友)"),PlayerNumber,PlayerName);
		    else
			    CurPlayerStr.Format(_T("%s(校友)"),PlayerName);
		        PlayerNameOutStr=CurPlayerStr;
		}
		else if(PlayerExtra==PLAYER_JIAOGONG)
		{
			if(IsPlayerNumber)
			    CurPlayerStr.Format(_T("%d-%s(教工)"),PlayerNumber,PlayerName);
		    else
			    CurPlayerStr.Format(_T("%s(教工)"),PlayerName);
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
				EventListOutStr.Format(_T("主        %s'        进球        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_OWNGOAL)
				EventListOutStr.Format(_T("主        %s'        乌龙球        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_SUBSTITUTION)
				EventListOutStr.Format(_T("主        %s'        换下：%s    换上：%s"),Timestr,Player1.PlayerNameOutStr,Player2.PlayerNameOutStr);
			else if(EventType==EVENT_YELLOW)
				EventListOutStr.Format(_T("主        %s'        黄牌        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_RED)
				EventListOutStr.Format(_T("主        %s'        红牌        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_TWOYELLOW)
				EventListOutStr.Format(_T("主        %s'        两黄并一红        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_PENALTY)
				EventListOutStr.Format(_T("主        %s'        点球        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_PENALTYMISS)
				EventListOutStr.Format(_T("主        %s'        点球罚失        %s"),Timestr,Player1.PlayerNameOutStr);
		}
		else
		{
			if(EventType==EVENT_GOAL)
				EventListOutStr.Format(_T("客        %s'        进球        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_OWNGOAL)
				EventListOutStr.Format(_T("客        %s'        乌龙球        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_SUBSTITUTION)
				EventListOutStr.Format(_T("客        %s'        换下：%s    换上：%s"),Timestr,Player1.PlayerNameOutStr,Player2.PlayerNameOutStr);
			else if(EventType==EVENT_YELLOW)
				EventListOutStr.Format(_T("客        %s'        黄牌        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_RED)
				EventListOutStr.Format(_T("客        %s'        红牌        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_TWOYELLOW)
				EventListOutStr.Format(_T("客        %s'        两黄并一红        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_PENALTY)
				EventListOutStr.Format(_T("客        %s'        点球        %s"),Timestr,Player1.PlayerNameOutStr);
			else if(EventType==EVENT_PENALTYMISS)
				EventListOutStr.Format(_T("客        %s'        点球罚失        %s"),Timestr,Player1.PlayerNameOutStr);
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
				ListOutstr.Format(_T("%s        罚进"),Player.PlayerNameOutStr);
			else
				ListOutstr.Format(_T("%s        罚失"),Player.PlayerNameOutStr);
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
