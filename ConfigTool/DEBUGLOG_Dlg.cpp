// DEBUGLOG_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "DEBUGLOG_Dlg.h"
#include "afxdialogex.h"


// DEBUGLOG_Dlg 对话框

IMPLEMENT_DYNAMIC(DEBUGLOG_Dlg, CDialogEx)

DEBUGLOG_Dlg::DEBUGLOG_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DEBUGLOG_Dlg::IDD, pParent)
{

}

DEBUGLOG_Dlg::~DEBUGLOG_Dlg()
{
}

void DEBUGLOG_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DebugLog, m_DebugLogForm);
}


BEGIN_MESSAGE_MAP(DEBUGLOG_Dlg, CDialogEx)
END_MESSAGE_MAP()


// DEBUGLOG_Dlg 消息处理程序
