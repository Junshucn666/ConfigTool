// m_Para_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "m_Para_Dlg.h"
#include "afxdialogex.h"


// m_Para_Dlg 对话框

IMPLEMENT_DYNAMIC(m_Para_Dlg, CDialogEx)

m_Para_Dlg::m_Para_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(m_Para_Dlg::IDD, pParent)
{

}

m_Para_Dlg::~m_Para_Dlg()
{
}

void m_Para_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(m_Para_Dlg, CDialogEx)
END_MESSAGE_MAP()


// m_Para_Dlg 消息处理程序
