
// ReportMaker01View.cpp : CReportMaker01View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ReportMaker01.h"
#endif

#include "ReportMaker01Doc.h"
#include "ReportMaker01View.h"
#include "EventDlg.h"
#include "FirstElevenDlg.h"
#include "FormatDlg.h"
using namespace ATL;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CReportMaker01View

IMPLEMENT_DYNCREATE(CReportMaker01View, CScrollView)

BEGIN_MESSAGE_MAP(CReportMaker01View, CScrollView)
	
	ON_COMMAND(ID_SAVEPIC, &CReportMaker01View::OnSavepic)
	ON_COMMAND(ID_FORMAT, &CReportMaker01View::OnFormat)
END_MESSAGE_MAP()

// CReportMaker01View 构造/析构

CReportMaker01View::CReportMaker01View()
	: Y(0)
	, LineLoc(0)
	, HomeGoal(0)
	, AwayGoal(0)
	, Score(_T(""))

{
	// TODO: 在此处添加构造代码

}

CReportMaker01View::~CReportMaker01View()
{
}

BOOL CReportMaker01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CReportMaker01View 绘制

void CReportMaker01View::OnDraw(CDC* pDC)
{
	CReportMaker01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC DcMemory;
	TEXTMETRIC tm;
	CSize size;
	int X,X0,Y0,i;
	Y=10;
	int Y1,Y2;
	HomeGoal=0;AwayGoal=0;
	DcMemory.CreateCompatibleDC(pDC);
	CRect rectClient;
	CRectangle HomeEventRect,AwayEventRect;
    GetClientRect(rectClient);	// 获取当前客户区的指针
    CSize sizeClient=rectClient.Size();	// 获取当前客户区的大小
	LineLoc=sizeClient.cx/2;
	CBrush *brush=CBrush::FromHandle((HBRUSH)GetStockObject(HOLLOW_BRUSH));
	pDC->SelectObject(brush);
	CBitmap BmpGoal;
	BmpGoal.LoadBitmapW(IDB_GOAL);
	CBitmap BmpOwngoal;
	BmpOwngoal.LoadBitmapW(IDB_OWNGOAL);
	CBitmap BmpUp;
	BmpUp.LoadBitmapW(IDB_UP);
	CBitmap BmpDown;
	BmpDown.LoadBitmapW(IDB_DOWN);
	CBitmap BmpYellow;
	BmpYellow.LoadBitmapW(IDB_YELLOW);
	CBitmap BmpRed;
	BmpRed.LoadBitmapW(IDB_RED);
	CBitmap BmpTwoyellow;
	BmpTwoyellow.LoadBitmapW(IDB_TWOYELLOW);
	CBitmap BmpPenalty;
	BmpPenalty.LoadBitmapW(IDB_PENALTY);
	CBitmap BmpPenaltymiss;
	BmpPenaltymiss.LoadBitmapW(IDB_PENALTYMISS);
	CBitmap BmpEnd;
	BmpEnd.LoadBitmapW(IDB_END);
	CBitmap BmpExpl;
	BmpExpl.LoadBitmapW(IDB_EXPLANATION);
	CBitmap BmpHt;
	BmpHt.LoadBitmapW(IDB_HT);
	CBitmap BmpStart;
	BmpStart.LoadBitmapW(IDB_START);
	HFONT hF_Title,hF_Text,hF_Time,hF_Subtitle,hF_First;
	HPEN hP_Thick,hP_Thin;
	hP_Thick=CreatePen(PS_SOLID,12,RGB(pDoc->linered,pDoc->linegreen,pDoc->lineblue));
	hP_Thin=CreatePen(PS_SOLID,2,RGB(pDoc->linered,pDoc->linegreen,pDoc->lineblue));
	hF_Title=CreateFontA(
						50,				//字体的高度
						0,				//由系统根据高宽比选取字体最佳宽度值
						0,				//文本的倾斜度为0，表示水平
						0,				//字体的倾斜度为0
						800,		//字体的粗度
						0,				//非斜体字
						0,				//无下划线
						0,				//无删除线
						GB2312_CHARSET,	//表示所用的字符集为ANSI_CHARSET
						OUT_DEFAULT_PRECIS,	//输出精度为缺省精度
						CLIP_DEFAULT_PRECIS,	//剪裁精度为缺省精度
						DEFAULT_QUALITY,		//输出质量为缺省值
						DEFAULT_PITCH|FF_DONTCARE,//字间距和字体系列使用缺省值
						pDoc->strtitle				//字体名称
						);
	hF_Text=CreateFontA(
						40,				//字体的高度
						0,				//由系统根据高宽比选取字体最佳宽度值
						0,				//文本的倾斜度为0，表示水平
						0,				//字体的倾斜度为0
						500,		//字体的粗度
						0,				//非斜体字
						0,				//无下划线
						0,				//无删除线
						GB2312_CHARSET,	//表示所用的字符集为ANSI_CHARSET
						OUT_DEFAULT_PRECIS,	//输出精度为缺省精度
						CLIP_DEFAULT_PRECIS,	//剪裁精度为缺省精度
						DEFAULT_QUALITY,		//输出质量为缺省值
						DEFAULT_PITCH|FF_DONTCARE,//字间距和字体系列使用缺省值
						pDoc->strtext				//字体名称
						);
	hF_Time=CreateFontA(
						38,				//字体的高度
						0,				//由系统根据高宽比选取字体最佳宽度值
						0,				//文本的倾斜度为0，表示水平
						0,				//字体的倾斜度为0
						400,		//字体的粗度
						0,				//非斜体字
						0,				//无下划线
						0,				//无删除线
						ANSI_CHARSET,	//表示所用的字符集为ANSI_CHARSET
						OUT_DEFAULT_PRECIS,	//输出精度为缺省精度
						CLIP_DEFAULT_PRECIS,	//剪裁精度为缺省精度
						DEFAULT_QUALITY,		//输出质量为缺省值
						DEFAULT_PITCH|FF_DONTCARE,//字间距和字体系列使用缺省值
						"时间字"				//字体名称
						);
	hF_Subtitle=CreateFontA(
						25,				//字体的高度
						0,				//由系统根据高宽比选取字体最佳宽度值
						0,				//文本的倾斜度为0，表示水平
						0,				//字体的倾斜度为0
						400,		//字体的粗度
						0,				//非斜体字
						0,				//无下划线
						0,				//无删除线
						GB2312_CHARSET,	//表示所用的字符集为ANSI_CHARSET
						OUT_DEFAULT_PRECIS,	//输出精度为缺省精度
						CLIP_DEFAULT_PRECIS,	//剪裁精度为缺省精度
						DEFAULT_QUALITY,		//输出质量为缺省值
						DEFAULT_PITCH|FF_DONTCARE,//字间距和字体系列使用缺省值
						pDoc->strname			//字体名称
						);
	
	hF_First=CreateFontA(
						36,				//字体的高度
						0,				//由系统根据高宽比选取字体最佳宽度值
						0,				//文本的倾斜度为0，表示水平
						0,				//字体的倾斜度为0
						400,		//字体的粗度
						0,				//非斜体字
						0,				//无下划线
						0,				//无删除线
						GB2312_CHARSET,	//表示所用的字符集为ANSI_CHARSET
						OUT_DEFAULT_PRECIS,	//输出精度为缺省精度
						CLIP_DEFAULT_PRECIS,	//剪裁精度为缺省精度
						DEFAULT_QUALITY,		//输出质量为缺省值
						DEFAULT_PITCH|FF_DONTCARE,//字间距和字体系列使用缺省值
						pDoc->strfirst				//字体名称
						);
	SelectObject(pDC->m_hDC,hF_Title);
	GetTextMetricsW(pDC->m_hDC,&tm);
	pDC->TextOutW(LineLoc/2-pDC->GetTextExtent(pDoc->HomeName).cx/2,Y,pDoc->HomeName);
	pDC->TextOutW(LineLoc*3/2-pDC->GetTextExtent(pDoc->AwayName).cx/2,Y,pDoc->AwayName);
	Y=Y+tm.tmHeight+tm.tmExternalLeading;

	if(pDoc->IsPenalty)
	{
		Y=Y+tm.tmHeight+tm.tmExternalLeading;
	}

	SelectObject(pDC->m_hDC,hF_Subtitle);
	GetTextMetricsW(pDC->m_hDC,&tm);
	pDC->TextOutW(LineLoc-pDC->GetTextExtent(pDoc->GameName).cx/2,Y,pDoc->GameName);
	Y=Y+tm.tmHeight+tm.tmExternalLeading;
	SelectObject(pDC->m_hDC,hF_Time);
	GetTextMetricsW(pDC->m_hDC,&tm);

	Y0=Y;
	CString First;
	First="首发阵容";
	SelectObject(pDC->m_hDC,hF_Time);
	GetTextMetricsW(pDC->m_hDC,&tm);

	
	Y=Y0;
	Y1=Y;Y2=Y;
	SelectObject(pDC->m_hDC,hF_First);
	GetTextMetricsW(pDC->m_hDC,&tm);
	X=10;
	for(i=0;i<pDoc->HomePlayerNum;i++)
	{
		if(pDoc->HomePlayers[i].IsFirst)
		{
			pDoc->HomePlayers[i].GetPlayerNameOutStr();
			if(X+pDC->GetTextExtent(pDoc->HomePlayers[i].PlayerNameOutStr).cx+pDC->GetTextExtent(First).cx<LineLoc)
			{
				pDC->TextOutW(X,Y1,pDoc->HomePlayers[i].PlayerNameOutStr);
				X=X+pDC->GetTextExtent(pDoc->HomePlayers[i].PlayerNameOutStr).cx+40;
			}
			else
			{
				X=10;
				Y1=Y1+tm.tmHeight+tm.tmExternalLeading*2;
				pDC->TextOutW(X,Y1,pDoc->HomePlayers[i].PlayerNameOutStr);
				X=X+pDC->GetTextExtent(pDoc->HomePlayers[i].PlayerNameOutStr).cx+40;
			}
		}
	}
	X=LineLoc+pDC->GetTextExtent(First).cx;
	for(i=0;i<pDoc->AwayPlayerNum;i++)
	{
		if(pDoc->AwayPlayers[i].IsFirst)
		{
			pDoc->AwayPlayers[i].GetPlayerNameOutStr();
			if(X+pDC->GetTextExtent(pDoc->AwayPlayers[i].PlayerNameOutStr).cx<LineLoc*2)
			{
				pDC->TextOutW(X,Y2,pDoc->AwayPlayers[i].PlayerNameOutStr);
				X=X+pDC->GetTextExtent(pDoc->AwayPlayers[i].PlayerNameOutStr).cx+40;
			}
			else
			{
				X=LineLoc+pDC->GetTextExtent(First).cx;
				Y2=Y2+tm.tmHeight+tm.tmExternalLeading*2;
				pDC->TextOutW(X,Y2,pDoc->AwayPlayers[i].PlayerNameOutStr);
				X=X+pDC->GetTextExtent(pDoc->AwayPlayers[i].PlayerNameOutStr).cx+40;
			}
		}
	}
	size=pDC->GetTextExtent(First);
	pDC->TextOutW(LineLoc-size.cx/2,Y0+(min(Y1,Y2)-Y0)/2,First);
	SelectObject(pDC->m_hDC,hF_Text);
	GetTextMetricsW(pDC->m_hDC,&tm);

	Y=max(max(Y1,Y2),Y0+(min(Y1,Y2)-Y0)/2+tm.tmHeight);
	DcMemory.SelectObject(&BmpStart);
	pDC->StretchBlt(LineLoc-20,Y,40,40,&DcMemory,0,0,40,40,SRCCOPY);
	Y=Y+37;
	SelectObject(pDC->m_hDC,hP_Thick);
	pDC->MoveTo(LineLoc,Y);

	
	pDoc->SortEvent();
	int begin=0,end=0;
	for(i=0;i<pDoc->EventNum;i++)
	{
		Y1=Y;Y2=Y;
		HomeEventRect.Width=0;
		HomeEventRect.Height=2*tm.tmExternalLeading;
		AwayEventRect.Width=0;
		AwayEventRect.Height=2*tm.tmExternalLeading;
		begin=i;end=i;  //得到所有时间相同的事件，开头为begin，结尾为end
		if(i<pDoc->EventNum-1)
		{
			pDoc->Events[i].GetTime();
			pDoc->Events[i+1].GetTime();
			while(pDoc->Events[i+1].Timestr==pDoc->Events[i].Timestr)
			{
				i++;
				end++;
				if(i==pDoc->EventNum-1)
					break;
				else
				{
					pDoc->Events[i].GetTime();
					pDoc->Events[i+1].GetTime();
				}
			}
		}
		for(int j=begin;j<=end;j++) //遍历begin到end的情况，确定框的大小
		{
			if(pDoc->Events[j].IsHome) //主队事件
			{
				if(pDoc->Events[j].EventType==EVENT_SUBSTITUTION)  //主队-换人
				{
					pDoc->Events[j].Player1.GetPlayerNameOutStr();
					pDoc->Events[j].Player2.GetPlayerNameOutStr();
					HomeEventRect.Width=max(HomeEventRect.Width,max(20+40+10+20+pDC->GetTextExtent(pDoc->Events[j].Player1.PlayerNameOutStr).cx,20+40+10+20+pDC->GetTextExtent(pDoc->Events[j].Player2.PlayerNameOutStr).cx));
					HomeEventRect.Height=HomeEventRect.Height+4*tm.tmExternalLeading+2*tm.tmHeight;

				}
				else //主队-非换人
				{
					pDoc->Events[j].Player1.GetPlayerNameOutStr();
					HomeEventRect.Width=max(HomeEventRect.Width,20+40+10+20+pDC->GetTextExtent(pDoc->Events[j].Player1.PlayerNameOutStr).cx);
					HomeEventRect.Height=HomeEventRect.Height+2*tm.tmExternalLeading+tm.tmHeight;
				}
			}
			else //客队事件
			{
				if(pDoc->Events[j].EventType==EVENT_SUBSTITUTION)  //客队-换人
				{
					pDoc->Events[j].Player1.GetPlayerNameOutStr();
					pDoc->Events[j].Player2.GetPlayerNameOutStr();
					AwayEventRect.Width=max(AwayEventRect.Width,max(20+40+10+20+pDC->GetTextExtent(pDoc->Events[j].Player1.PlayerNameOutStr).cx,20+40+10+20+pDC->GetTextExtent(pDoc->Events[j].Player2.PlayerNameOutStr).cx));
					AwayEventRect.Height=AwayEventRect.Height+4*tm.tmExternalLeading+2*tm.tmHeight;

				}
				else //客队-非换人
				{
					pDoc->Events[j].Player1.GetPlayerNameOutStr();
					AwayEventRect.Width=max(AwayEventRect.Width,20+40+10+20+pDC->GetTextExtent(pDoc->Events[j].Player1.PlayerNameOutStr).cx);
					AwayEventRect.Height=AwayEventRect.Height+2*tm.tmExternalLeading+tm.tmHeight;
				}
			 }
			
		}
		if(HomeEventRect.Width!=0 && AwayEventRect.Width!=0)//确定基准点
			{
				Y=Y+30+max(HomeEventRect.Height,AwayEventRect.Height);
				Y1=Y1+30+max(HomeEventRect.Height,AwayEventRect.Height)/2;//基准点
				pDC->LineTo(LineLoc,Y);
				SelectObject(pDC->m_hDC,hF_Time);
				GetTextMetricsW(pDC->m_hDC,&tm);
				SelectObject(pDC->m_hDC,hP_Thin);
				pDoc->Events[begin].GetTime();
				pDC->MoveTo(LineLoc-106,Y1);
				pDC->LineTo(LineLoc+106,Y1);
				pDC->MoveTo(LineLoc,Y);
				pDC->TextOutW(LineLoc-56-pDC->GetTextExtent(pDoc->Events[begin].Timestr).cx/2,Y1-tm.tmHeight-tm.tmExternalLeading,pDoc->Events[begin].Timestr);
				pDC->TextOutW(LineLoc+56-pDC->GetTextExtent(pDoc->Events[begin].Timestr).cx/2,Y1-tm.tmHeight-tm.tmExternalLeading,pDoc->Events[begin].Timestr);
				pDC->RoundRect(LineLoc-106-HomeEventRect.Width,Y1-HomeEventRect.Height/2,LineLoc-106,Y1+HomeEventRect.Height/2,20,20);
				pDC->RoundRect(LineLoc+106,Y1-AwayEventRect.Height/2,LineLoc+106+AwayEventRect.Width,Y1+AwayEventRect.Height/2,20,20);
				SelectObject(pDC->m_hDC,hF_Text);
				GetTextMetricsW(pDC->m_hDC,&tm);
				SelectObject(pDC->m_hDC,hP_Thick);
			}
			else if(HomeEventRect.Width!=0 && AwayEventRect.Width==0)
			{
				Y=Y+30+HomeEventRect.Height;
				Y1=Y1+30+HomeEventRect.Height/2;//基准点
				pDC->LineTo(LineLoc,Y);
				SelectObject(pDC->m_hDC,hF_Time);
				GetTextMetricsW(pDC->m_hDC,&tm);
				SelectObject(pDC->m_hDC,hP_Thin);
				pDoc->Events[begin].GetTime();
				pDC->MoveTo(LineLoc-106,Y1);
				pDC->LineTo(LineLoc,Y1);
				pDC->MoveTo(LineLoc,Y);
				pDC->TextOutW(LineLoc-56-pDC->GetTextExtent(pDoc->Events[begin].Timestr).cx/2,Y1-tm.tmHeight-tm.tmExternalLeading,pDoc->Events[begin].Timestr);
				pDC->RoundRect(LineLoc-106-HomeEventRect.Width,Y1-HomeEventRect.Height/2,LineLoc-106,Y1+HomeEventRect.Height/2,20,20);
				SelectObject(pDC->m_hDC,hF_Text);
				GetTextMetricsW(pDC->m_hDC,&tm);
				SelectObject(pDC->m_hDC,hP_Thick);
			}
			else if(HomeEventRect.Width==0 && AwayEventRect.Width!=0)
			{
				Y=Y+30+AwayEventRect.Height;
				Y1=Y1+30+AwayEventRect.Height/2;//基准点
				pDC->LineTo(LineLoc,Y);
				SelectObject(pDC->m_hDC,hF_Time);
				GetTextMetricsW(pDC->m_hDC,&tm);
				SelectObject(pDC->m_hDC,hP_Thin);
				pDoc->Events[begin].GetTime();
				pDC->MoveTo(LineLoc,Y1);
				pDC->LineTo(LineLoc+106,Y1);
				pDC->MoveTo(LineLoc,Y);
				pDC->TextOutW(LineLoc+56-pDC->GetTextExtent(pDoc->Events[begin].Timestr).cx/2,Y1-tm.tmHeight-tm.tmExternalLeading,pDoc->Events[begin].Timestr);
				pDC->RoundRect(LineLoc+106,Y1-AwayEventRect.Height/2,LineLoc+106+AwayEventRect.Width,Y1+AwayEventRect.Height/2,20,20);
				SelectObject(pDC->m_hDC,hF_Text);
				GetTextMetricsW(pDC->m_hDC,&tm);
				SelectObject(pDC->m_hDC,hP_Thick);
			}
		if(HomeEventRect.Width!=0)
		{
			X=LineLoc-106-HomeEventRect.Width+20;
			X0=X;
			Y2=Y1-HomeEventRect.Height/2+2*tm.tmExternalLeading;
			for(int k=begin;k<=end;k++)
			{
				if(pDoc->Events[k].IsHome)
				{
					if(pDoc->Events[k].EventType==EVENT_SUBSTITUTION)
					{
						DcMemory.SelectObject(&BmpDown);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player1.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player1.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;

						DcMemory.SelectObject(&BmpUp);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player2.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player2.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
					else if(pDoc->Events[k].EventType==EVENT_GOAL)
					{
						HomeGoal++;
						DcMemory.SelectObject(&BmpGoal);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player1.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player1.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
					else if(pDoc->Events[k].EventType==EVENT_YELLOW)
					{
						DcMemory.SelectObject(&BmpYellow);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player1.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player1.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
					else if(pDoc->Events[k].EventType==EVENT_RED)
					{
						DcMemory.SelectObject(&BmpRed);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player1.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player1.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
					else if(pDoc->Events[k].EventType==EVENT_TWOYELLOW)
					{
						DcMemory.SelectObject(&BmpTwoyellow);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player1.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player1.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
					else if(pDoc->Events[k].EventType==EVENT_OWNGOAL)
					{
						AwayGoal++;
						DcMemory.SelectObject(&BmpOwngoal);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player1.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player1.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
					else if(pDoc->Events[k].EventType==EVENT_PENALTY)
					{
						HomeGoal++;
						DcMemory.SelectObject(&BmpPenalty);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player1.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player1.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
					else if(pDoc->Events[k].EventType==EVENT_PENALTYMISS)
					{
						DcMemory.SelectObject(&BmpPenaltymiss);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player1.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player1.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
				}
			}

		}

		if(AwayEventRect.Width!=0)
		{
			X=LineLoc+106+20;
			X0=X;
			Y2=Y1-AwayEventRect.Height/2+2*tm.tmExternalLeading;
			for(int k=begin;k<=end;k++)
			{
				if(!pDoc->Events[k].IsHome)
				{
					if(pDoc->Events[k].EventType==EVENT_SUBSTITUTION)
					{
						DcMemory.SelectObject(&BmpDown);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player1.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player1.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;

						DcMemory.SelectObject(&BmpUp);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player2.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player2.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
					else if(pDoc->Events[k].EventType==EVENT_GOAL)
					{
						AwayGoal++;
						DcMemory.SelectObject(&BmpGoal);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player1.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player1.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
					else if(pDoc->Events[k].EventType==EVENT_YELLOW)
					{
						DcMemory.SelectObject(&BmpYellow);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player1.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player1.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
					else if(pDoc->Events[k].EventType==EVENT_RED)
					{
						DcMemory.SelectObject(&BmpRed);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player1.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player1.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
					else if(pDoc->Events[k].EventType==EVENT_TWOYELLOW)
					{
						DcMemory.SelectObject(&BmpTwoyellow);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player1.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player1.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
					else if(pDoc->Events[k].EventType==EVENT_OWNGOAL)
					{
						HomeGoal++;
						DcMemory.SelectObject(&BmpOwngoal);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player1.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player1.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
					else if(pDoc->Events[k].EventType==EVENT_PENALTY)
					{
						AwayGoal++;
						DcMemory.SelectObject(&BmpPenalty);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player1.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player1.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
					else if(pDoc->Events[k].EventType==EVENT_PENALTYMISS)
					{
						DcMemory.SelectObject(&BmpPenaltymiss);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->Events[k].Player1.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->Events[k].Player1.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
				}
			}
		}

	}

	if(pDoc->IsPenalty)
	{
		int i=0;
		SelectObject(pDC->m_hDC,hF_Text);
	    GetTextMetricsW(pDC->m_hDC,&tm);
		Y1=Y;Y2=Y;
		HomeEventRect.Width=0;
		HomeEventRect.Height=2*tm.tmExternalLeading;
		AwayEventRect.Width=0;
		AwayEventRect.Height=2*tm.tmExternalLeading;
		for(i=0;i<pDoc->HomePenaltyNum;i++)
		{
			pDoc->HomePenalty[i].Player.GetPlayerNameOutStr();
			HomeEventRect.Width=max(HomeEventRect.Width,90+pDC->GetTextExtent(pDoc->HomePenalty[i].Player.PlayerNameOutStr).cx);
			HomeEventRect.Height=HomeEventRect.Height+2*tm.tmExternalLeading+tm.tmHeight;
		}
		for(i=0;i<pDoc->AwayPenaltyNum;i++)
		{
			pDoc->AwayPenalty[i].Player.GetPlayerNameOutStr();
			AwayEventRect.Width=max(AwayEventRect.Width,90+pDC->GetTextExtent(pDoc->AwayPenalty[i].Player.PlayerNameOutStr).cx);
			AwayEventRect.Height=AwayEventRect.Height+2*tm.tmExternalLeading+tm.tmHeight;
		}
		if(HomeEventRect.Width!=0 && AwayEventRect.Width!=0)//确定基准点
			{
				Y=Y+30+max(HomeEventRect.Height,AwayEventRect.Height);
				Y1=Y1+30+max(HomeEventRect.Height,AwayEventRect.Height)/2;//基准点
				pDC->LineTo(LineLoc,Y);
				SelectObject(pDC->m_hDC,hF_Time);
				GetTextMetricsW(pDC->m_hDC,&tm);
				SelectObject(pDC->m_hDC,hP_Thin);
				pDC->MoveTo(LineLoc-106,Y1);
				pDC->LineTo(LineLoc+106,Y1);
				pDC->MoveTo(LineLoc,Y);
				CString time;
				time.Format(_T("%d"),pDoc->PenaltyTime);
				pDC->TextOutW(LineLoc-56-pDC->GetTextExtent(time).cx/2,Y1-tm.tmHeight-tm.tmExternalLeading,time);
				pDC->TextOutW(LineLoc+56-pDC->GetTextExtent(time).cx/2,Y1-tm.tmHeight-tm.tmExternalLeading,time);
				pDC->RoundRect(LineLoc-106-HomeEventRect.Width,Y1-HomeEventRect.Height/2,LineLoc-106,Y1+HomeEventRect.Height/2,20,20);
				pDC->RoundRect(LineLoc+106,Y1-AwayEventRect.Height/2,LineLoc+106+AwayEventRect.Width,Y1+AwayEventRect.Height/2,20,20);
				SelectObject(pDC->m_hDC,hF_Text);
				GetTextMetricsW(pDC->m_hDC,&tm);
				SelectObject(pDC->m_hDC,hP_Thick);
			}

		if(HomeEventRect.Width!=0)
		{
			X=LineLoc-106-HomeEventRect.Width+20;
			X0=X;
			Y2=Y1-HomeEventRect.Height/2+2*tm.tmExternalLeading;
			for(int k=0;k<pDoc->HomePenaltyNum;k++)
			{
				
				if(pDoc->HomePenalty[k].IsGoal)
					{
						DcMemory.SelectObject(&BmpPenalty);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->HomePenalty[k].Player.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->HomePenalty[k].Player.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
				else
					{
						DcMemory.SelectObject(&BmpPenaltymiss);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->HomePenalty[k].Player.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->HomePenalty[k].Player.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
				
			}

		}

		if(AwayEventRect.Width!=0)
		{
			X=LineLoc+106+20;
			X0=X;
			Y2=Y1-AwayEventRect.Height/2+2*tm.tmExternalLeading;
			for(int k=0;k<pDoc->AwayPenaltyNum;k++)
			{
				
				if(pDoc->AwayPenalty[k].IsGoal)
					{
						DcMemory.SelectObject(&BmpPenalty);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->AwayPenalty[k].Player.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->AwayPenalty[k].Player.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
				else
					{
						DcMemory.SelectObject(&BmpPenaltymiss);
						pDC->StretchBlt(X,Y2,40,40,&DcMemory,0,0,40,40,SRCCOPY);
						X=X+50;
						pDoc->AwayPenalty[k].Player.GetPlayerNameOutStr();
						pDC->TextOutW(X,Y2,pDoc->AwayPenalty[k].Player.PlayerNameOutStr);
						X=X0;
						Y2=Y2+2*tm.tmExternalLeading+tm.tmHeight;
					}
				
			}

		}
	}


	Y=Y+20;
	DcMemory.SelectObject(&BmpEnd);
	pDC->StretchBlt(LineLoc-20,Y,40,40,&DcMemory,0,0,40,40,SRCCOPY);
	pDC->LineTo(LineLoc,Y+3);

	BITMAP bmpinfo;
	BmpExpl.GetBitmap(&bmpinfo);
	DcMemory.SelectObject(&BmpExpl);
	pDC->StretchBlt(LineLoc-20*bmpinfo.bmWidth/bmpinfo.bmHeight,Y+60,40*bmpinfo.bmWidth/bmpinfo.bmHeight,40,&DcMemory,0,0,bmpinfo.bmWidth,bmpinfo.bmHeight,SRCCOPY);

	Score.Format(_T("%d:%d"),HomeGoal,AwayGoal);
	SelectObject(pDC->m_hDC,hF_Title);
	GetTextMetricsW(pDC->m_hDC,&tm);
	pDC->TextOutW(LineLoc-pDC->GetTextExtent(Score).cx/2,10,Score);
	if(pDoc->IsPenalty)
	{
		CString Scorestr;
		int hg=0,ag=0;
		hg=HomeGoal;
		ag=AwayGoal;
		int i=0;
		for(i=0;i<pDoc->HomePenaltyNum;i++)
		{
			if(pDoc->HomePenalty[i].IsGoal)
				hg++;
		}
		for(i=0;i<pDoc->AwayPenaltyNum;i++)
		{
			if(pDoc->AwayPenalty[i].IsGoal)
				ag++;
		}
		Scorestr.Format(_T("(%d:%d)"),hg,ag);
		pDC->TextOutW(LineLoc-pDC->GetTextExtent(Scorestr).cx/2,10+tm.tmHeight+tm.tmExternalLeading,Scorestr);
	}
}


// CReportMaker01View 诊断

#ifdef _DEBUG
void CReportMaker01View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CReportMaker01View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CReportMaker01Doc* CReportMaker01View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CReportMaker01Doc)));
	return (CReportMaker01Doc*)m_pDocument;
}
#endif //_DEBUG


// CReportMaker01View 消息处理程序



void CReportMaker01View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	CSize sizeTotal(1800,5000);  
    SetScrollSizes(MM_TEXT, sizeTotal); 
}


void CReportMaker01View::OnSavepic()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC;
	pDC=GetDC();
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);

	CReportMaker01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(LineLoc==0 ||Y==0)
		return;

	CBitmap Virt;
	Virt.CreateCompatibleBitmap(pDC,2*LineLoc,Y+120);
	memDC.SelectObject(Virt);
	memDC.BitBlt(0,0,2*LineLoc,Y+120,pDC,0,0,WHITENESS);
	
	OnDraw(&memDC);

	CImage img;
    HBITMAP hbmp;
	CString StrName;
	StrName.Format(_T("%s%d：%d%s"),pDoc->HomeName,HomeGoal,AwayGoal,pDoc->AwayName);
	hbmp=(HBITMAP)Virt.GetSafeHandle();
    img.Attach(hbmp);
	CFileDialog dlg(FALSE,_T("JPG图片(*.jpg)|*.jpg"),StrName,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,_T("JPG图片(*.jpg)|*.jpg|BMP图片(*.bmp)|*.bmp||"),this);
	dlg.DoModal();
	img.Save(dlg.GetPathName());
}


void CReportMaker01View::OnFormat()
{
	// TODO: 在此添加命令处理程序代码
	CReportMaker01Doc* pDoc = GetDocument();
	CFormatDlg dlg;
	CDC* pDC;
	pDC=GetDC();
	if(dlg.DoModal()==IDOK)
	{
		pDoc->OnDraw();
	}


}
