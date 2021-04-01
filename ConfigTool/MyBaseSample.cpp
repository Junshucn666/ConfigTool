// MyBaseSample.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "MyBaseSample.h"
#include "afxdialogex.h"


// MyBaseSample 对话框

IMPLEMENT_DYNAMIC(MyBaseSample, CDialogEx)

MyBaseSample::MyBaseSample(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyBaseSample::IDD, pParent)
{

}

MyBaseSample::~MyBaseSample()
{
}

void MyBaseSample::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_GTCMD, m_Edit_GTCMD);
	DDX_Control(pDX, IDC_BUTTON_Read, m_Button_Read);
	DDX_Control(pDX, IDC_BUTTON_Send, m_Button_Send);
}


BEGIN_MESSAGE_MAP(MyBaseSample, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_GTCMD, &MyBaseSample::OnEnChangeEditGtcmd)
	ON_BN_CLICKED(IDC_BUTTON_Read, &MyBaseSample::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_Send, &MyBaseSample::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDOK, &MyBaseSample::OnBnClickedOk)
END_MESSAGE_MAP()


// MyBaseSample 消息处理程序

BOOL MyBaseSample::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetBackgroundColor(RGB(176,196,222));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void MyBaseSample::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	//AfxMessageBox("Base");
	//CDialogEx::OnOK();
}

void MyBaseSample::OnEnChangeEditGtcmd()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void MyBaseSample::OnBnClickedButtonRead()
{
	// TODO: 在此添加控件通知处理程序代码
}


void MyBaseSample::OnBnClickedButtonSend()
{
	// TODO: 在此添加控件通知处理程序代码
}


void MyBaseSample::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
