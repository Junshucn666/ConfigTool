// ASrdc_Dlgtwo.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ASrdc_Dlgtwo.h"
#include "afxdialogex.h"
#include "ASrdc_Dlgnew.h"
#include "MYWORK.h"

// ASrdc_Dlgtwo 对话框
extern ASrdc_Dlgnew*	lpASrdc_Dlgnew;
extern ASrdc_Dlgtwo	m_ASrdc_Dlgtwo;
extern CMYWORK	m_MYWORK;
ASrdc_Dlgtwo*	lpASrdc_Dlgtwo;

IMPLEMENT_DYNAMIC(ASrdc_Dlgtwo, CDialogEx)

ASrdc_Dlgtwo::ASrdc_Dlgtwo(CWnd* pParent /*=NULL*/)
	: CDialogEx(ASrdc_Dlgtwo::IDD, pParent)
{

}

ASrdc_Dlgtwo::~ASrdc_Dlgtwo()
{
}

void ASrdc_Dlgtwo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_RS, m_Edit_RS);
	DDX_Control(pDX, IDC_EDIT_RE, m_Edit_RE);
	DDX_Control(pDX, IDC_SPIN_RS, m_Spin_RS);
	DDX_Control(pDX, IDC_SPIN_RE, m_Spin_RE);
}


BEGIN_MESSAGE_MAP(ASrdc_Dlgtwo, CDialogEx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_RS, &ASrdc_Dlgtwo::OnDeltaposSpinRs)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_RE, &ASrdc_Dlgtwo::OnDeltaposSpinRe)
	ON_EN_CHANGE(IDC_EDIT_RS, &ASrdc_Dlgtwo::OnEnChangeEditRs)
	ON_EN_CHANGE(IDC_EDIT_RE, &ASrdc_Dlgtwo::OnEnChangeEditRe)
	ON_EN_CHANGE(IDC_EDIT_R1, &ASrdc_Dlgtwo::OnEnChangeEditR1)
	ON_EN_CHANGE(IDC_EDIT_R2, &ASrdc_Dlgtwo::OnEnChangeEditR2)
	ON_EN_CHANGE(IDC_EDIT_R3, &ASrdc_Dlgtwo::OnEnChangeEditR3)
	ON_EN_CHANGE(IDC_EDIT_R4, &ASrdc_Dlgtwo::OnEnChangeEditR4)
	ON_EN_CHANGE(IDC_EDIT_R5, &ASrdc_Dlgtwo::OnEnChangeEditR5)
	ON_EN_CHANGE(IDC_EDIT_R51, &ASrdc_Dlgtwo::OnEnChangeEditR51)
	ON_EN_CHANGE(IDC_EDIT_R52, &ASrdc_Dlgtwo::OnEnChangeEditR52)
	ON_EN_CHANGE(IDC_EDIT_R53, &ASrdc_Dlgtwo::OnEnChangeEditR53)
	ON_EN_CHANGE(IDC_EDIT_R54, &ASrdc_Dlgtwo::OnEnChangeEditR54)
	ON_EN_CHANGE(IDC_EDIT_R55, &ASrdc_Dlgtwo::OnEnChangeEditR55)
	ON_EN_CHANGE(IDC_EDIT_R6, &ASrdc_Dlgtwo::OnEnChangeEditR6)
	ON_EN_CHANGE(IDC_EDIT_R7, &ASrdc_Dlgtwo::OnEnChangeEditR7)
	ON_EN_CHANGE(IDC_EDIT_R8, &ASrdc_Dlgtwo::OnEnChangeEditR8)
	ON_EN_CHANGE(IDC_EDIT_R9, &ASrdc_Dlgtwo::OnEnChangeEditR9)
	ON_EN_CHANGE(IDC_EDIT_R10, &ASrdc_Dlgtwo::OnEnChangeEditR10)
	ON_EN_CHANGE(IDC_EDIT_R56, &ASrdc_Dlgtwo::OnEnChangeEditR56)
	ON_EN_CHANGE(IDC_EDIT_R57, &ASrdc_Dlgtwo::OnEnChangeEditR57)
	ON_EN_CHANGE(IDC_EDIT_R58, &ASrdc_Dlgtwo::OnEnChangeEditR58)
	ON_EN_CHANGE(IDC_EDIT_R59, &ASrdc_Dlgtwo::OnEnChangeEditR59)
	ON_EN_CHANGE(IDC_EDIT_R60, &ASrdc_Dlgtwo::OnEnChangeEditR60)
END_MESSAGE_MAP()


// ASrdc_Dlgtwo 消息处理程序


BOOL ASrdc_Dlgtwo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpASrdc_Dlgtwo=&m_ASrdc_Dlgtwo;//窗口寻址

	SetBackgroundColor(RGB(176,196,222));

	SetDlgItemText(IDC_EDIT_RS,"1");
	m_Spin_RS.SetBuddy(GetDlgItem(IDC_EDIT_RS)); //得到指向编辑框的窗口指针
	m_Spin_RS.SetRange(1,100);
	/////////////////
	SetDlgItemText(IDC_EDIT_RE,"1");
	m_Spin_RE.SetBuddy(GetDlgItem(IDC_EDIT_RE)); //得到指向编辑框的窗口指针
	m_Spin_RE.SetRange(1,100);
	//////////////////////////////////////////////
	CRect rect;  
	lpASrdc_Dlgnew->m_Table_rdc.GetWindowRect(&rect);  
	m_listRect.AddTail(rect);//对话框的区域  
	CWnd* pReWnd = GetWindow(GW_CHILD);//获取子窗体  
	while(pReWnd)  
	{  
		pReWnd->GetWindowRect(rect);//子窗体的区域  
		m_listRect.AddTail(rect);           //CList<CRect,CRect> m_listRect成员变量  
		pReWnd = pReWnd->GetNextWindow();//取下一个子窗体  
	}  

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void ASrdc_Dlgtwo::ReSize(UINT nType, int cx, int cy)
{
	if (m_listRect.GetCount() > 0)  
	{  
		CRect dlgNow;  
		lpASrdc_Dlgnew->m_Table_rdc.GetWindowRect(&dlgNow);  
		POSITION pos = m_listRect.GetHeadPosition();//第一个保存的是对话框的Rect  

		CRect dlgSaved;  
		dlgSaved = m_listRect.GetNext(pos);  
		ScreenToClient(dlgNow);  

		double x = dlgNow.Width() * 1.0 / dlgSaved.Width();//根据当前和之前保存的对话框的宽高求比例  
		double y = dlgNow.Height()  *1.0/ dlgSaved.Height();  
		ClientToScreen(dlgNow);  

		CRect childSaved;  

		CWnd* pWnd = GetWindow(GW_CHILD);  
		while(pWnd)  
		{  
			childSaved = m_listRect.GetNext(pos);//依次获取子窗体的Rect  
			childSaved.left = (long)(dlgNow.left + (childSaved.left - dlgSaved.left)*x);//根据比例调整控件上下左右距离对话框的距离  
			childSaved.right = (long)(dlgNow.right + (childSaved.right - dlgSaved.right)*x);  
			childSaved.top = (long)(dlgNow.top + (childSaved.top - dlgSaved.top)*y);  
			childSaved.bottom = (long)(dlgNow.bottom + (childSaved.bottom - dlgSaved.bottom)*y);  
			if(pWnd->IsKindOf(RUNTIME_CLASS(CComboBox))) childSaved.bottom = childSaved.bottom+100;//判断是否为ComboBox类型
			ScreenToClient(childSaved);  
			pWnd->MoveWindow(childSaved);  
			pWnd = pWnd->GetNextWindow();  
		}  
	}
}


void ASrdc_Dlgtwo::OnDeltaposSpinRs(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_RS.GetPos();
	m_Spin_RS.SetPos(iTemp);
	m_Edit_RS.GetWindowText(strValue);  
	*pResult = 0;
}


void ASrdc_Dlgtwo::OnDeltaposSpinRe(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_RE.GetPos();
	m_Spin_RE.SetPos(iTemp);
	m_Edit_RE.GetWindowText(strValue);  
	*pResult = 0;
}


void ASrdc_Dlgtwo::OnEnChangeEditRs()
{
	CString sStart="",sEnd="";
	m_Edit_RS.GetWindowText(sStart);
	m_Edit_RE.GetWindowText(sEnd);
	if (atoi(sStart)>atoi(sEnd))
	{
		m_Edit_RE.SetWindowText(sStart);
	}
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditRe()
{
	CString sStart="",sEnd="";
	m_Edit_RS.GetWindowText(sStart);
	m_Edit_RE.GetWindowText(sEnd);
	if (atoi(sStart)>atoi(sEnd))
	{
		m_Edit_RS.SetWindowText(sEnd);
	}
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR1()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR2()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR3()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR4()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR5()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR51()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR52()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR53()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR54()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR55()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR6()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR7()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR8()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR9()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR10()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR56()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR57()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR58()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR59()
{
lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgtwo::OnEnChangeEditR60()
{
lpASrdc_Dlgnew->GetCMD();
}
