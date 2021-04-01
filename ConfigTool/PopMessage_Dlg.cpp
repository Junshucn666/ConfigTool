// PopMessage_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "PopMessage_Dlg.h"
#include "afxdialogex.h"
#include "ConfigToolDlg.h"

extern CConfigToolDlg* lpCConfigToolDlg;
CImage g_KeyImage;
CRect g_KeyRect;  //控件矩形对象

IMPLEMENT_DYNAMIC(PopMessage_Dlg, CDialogEx)

PopMessage_Dlg::PopMessage_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(PopMessage_Dlg::IDD, pParent)
{
	cfont_showmsg.CreatePointFont(130,"Verdana");
}

PopMessage_Dlg::~PopMessage_Dlg()
{
}

void PopMessage_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_Msg, m_static_showmsg);
	DDX_Control(pDX, IDC_STATIC_Key, m_CStatic_Key);
}


BEGIN_MESSAGE_MAP(PopMessage_Dlg, CDialogEx)
	ON_WM_CTLCOLOR()
//	ON_WM_PAINT()
ON_WM_PAINT()
END_MESSAGE_MAP()


// PopMessage_Dlg 消息处理程序
BOOL PopMessage_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_static_showmsg.SetWindowText(this->sShowText);
	m_static_showmsg.SetFont(&cfont_showmsg);
	SetBackgroundColor(RGB(176,196,222),1);
	CheckPicture();	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void PopMessage_Dlg::ExitShow()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(IDOK);    //关闭窗口 
	CDialog::OnClose(); 
}


BOOL PopMessage_Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类

	return CDialogEx::PreTranslateMessage(pMsg);
}


HBRUSH PopMessage_Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if(pWnd->GetDlgCtrlID()==IDC_STATIC_Msg)
	{
		pDC->SetTextColor(RGB(0,0,205));//设置字体颜色：
		pDC->SetBkMode(TRANSPARENT);//设置背景模式：这里设置为透明
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

void PopMessage_Dlg::CheckPicture()
{	
	CString strPath="",MainPath="",SubPath="";	
	CRect rectPicture;   //图片矩形对象
	strPath=lpCConfigToolDlg->GetExeFilePath();
	MainPath=strPath+"main.jpg";
	//加载图片
	if (PathFileExists(MainPath))
	{	
		g_KeyImage.Load(MainPath);//装载路径下图片信息到图片类 
		KeyPicShow();
	}
}

void PopMessage_Dlg::KeyPicShow()
{
	//获得控件的区域对象,获得显示控件的DC 
	m_CStatic_Key.GetClientRect(&g_KeyRect);   
	CDC* pKeyDC = m_CStatic_Key.GetWindowDC();  
	//解决颜色失真
	::SetStretchBltMode(*pKeyDC, HALFTONE);//HALFTONE：將要删掉的像素跟周围的中和起來,(相当于PS的那个模糊工具)
	::SetBrushOrgEx(*pKeyDC, 0, 0, NULL);
	g_KeyImage.StretchBlt(*pKeyDC, 20, 132, 140, 198, SRCCOPY);//坐标无效不知道原因
	//绘图
	g_KeyImage.Draw( pKeyDC ->m_hDC,g_KeyRect);  
	g_KeyImage.Destroy();
}



void PopMessage_Dlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CDialogEx::OnPaint();
	CDialog::UpdateWindow(); //更新windows窗口  
	CheckPicture();     //重绘图片函数   
}
