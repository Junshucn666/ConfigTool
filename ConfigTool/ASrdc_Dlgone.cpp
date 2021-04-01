// ASrdc_Dlgone.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ASrdc_Dlgone.h"
#include "afxdialogex.h"
#include "ASrdc_Dlgnew.h"
#include "MYWORK.h"

// ASrdc_Dlgone 对话框
extern ASrdc_Dlgnew*	lpASrdc_Dlgnew;
extern ASrdc_Dlgone	m_ASrdc_Dlgone;
extern CMYWORK	m_MYWORK;
extern CString g_sKREMValue,g_sUREMValue;
ASrdc_Dlgone*	lpASrdc_Dlgone;

IMPLEMENT_DYNAMIC(ASrdc_Dlgone, CDialogEx)

ASrdc_Dlgone::ASrdc_Dlgone(CWnd* pParent /*=NULL*/)
	: CDialogEx(ASrdc_Dlgone::IDD, pParent)
{

}

ASrdc_Dlgone::~ASrdc_Dlgone()
{
}

void ASrdc_Dlgone::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_B0, m_Check_B0);
	DDX_Control(pDX, IDC_CHECK_B1, m_Check_B1);
	DDX_Control(pDX, IDC_CHECK_B2, m_Check_B2);
	DDX_Control(pDX, IDC_CHECK_B3, m_Check_B3);
	DDX_Control(pDX, IDC_CHECK_B4, m_Check_B4);
	DDX_Control(pDX, IDC_CHECK_B5, m_Check_B5);
	DDX_Control(pDX, IDC_CHECK_B6, m_Check_B6);
	DDX_Control(pDX, IDC_CHECK_B7, m_Check_B7);
	DDX_Control(pDX, IDC_CHECK_B8, m_Check_B8);
	DDX_Control(pDX, IDC_CHECK_B9, m_Check_B9);
	DDX_Control(pDX, IDC_CHECK_B10, m_Check_B10);
	DDX_Control(pDX, IDC_CHECK_B11, m_Check_B11);
	DDX_Control(pDX, IDC_CHECK_B12, m_Check_B12);
	DDX_Control(pDX, IDC_CHECK_B13, m_Check_B13);
	DDX_Control(pDX, IDC_CHECK_B14, m_Check_B14);
	DDX_Control(pDX, IDC_CHECK_U0, m_Check_U0);
	DDX_Control(pDX, IDC_CHECK_U1, m_Check_U1);
	DDX_Control(pDX, IDC_CHECK_U2, m_Check_U2);
	DDX_Control(pDX, IDC_CHECK_U3, m_Check_U3);
	DDX_Control(pDX, IDC_CHECK_U4, m_Check_U4);
	DDX_Control(pDX, IDC_CHECK_U5, m_Check_U5);
	DDX_Control(pDX, IDC_CHECK_U6, m_Check_U6);
	DDX_Control(pDX, IDC_CHECK_U7, m_Check_U7);
	DDX_Control(pDX, IDC_CHECK_U8, m_Check_U8);
	DDX_Control(pDX, IDC_CHECK_U9, m_Check_U9);
	DDX_Control(pDX, IDC_CHECK_U10, m_Check_U10);
	DDX_Control(pDX, IDC_CHECK_U11, m_Check_U11);
	DDX_Control(pDX, IDC_CHECK_U12, m_Check_U12);
	DDX_Control(pDX, IDC_CHECK_U13, m_Check_U13);
	DDX_Control(pDX, IDC_CHECK_U14, m_Check_U14);
	DDX_Control(pDX, IDC_EDIT_HS, m_Edit_HS);
	DDX_Control(pDX, IDC_EDIT_HE, m_Edit_HE);
	DDX_Control(pDX, IDC_SPIN_MS, m_Spin_MS);
	DDX_Control(pDX, IDC_SPIN_ME, m_Spin_ME);
	DDX_Control(pDX, IDC_CHECK_EMca, m_Check_EMca);
	DDX_Control(pDX, IDC_CHECK_EMca2, m_Check_EMca2);
	DDX_Control(pDX, IDC_EDIT_BS, m_Edit_BS);
	DDX_Control(pDX, IDC_EDIT_BE, m_Edit_BE);
	DDX_Control(pDX, IDC_SPIN_BS, m_Spin_BS);
	DDX_Control(pDX, IDC_SPIN_BE, m_Spin_BE);
}


BEGIN_MESSAGE_MAP(ASrdc_Dlgone, CDialogEx)
	ON_BN_CLICKED(IDOK, &ASrdc_Dlgone::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ASrdc_Dlgone::OnBnClickedCancel)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MS, &ASrdc_Dlgone::OnDeltaposSpinMs)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ME, &ASrdc_Dlgone::OnDeltaposSpinMe)
	ON_BN_CLICKED(IDC_CHECK_B0, &ASrdc_Dlgone::OnBnClickedCheckB0)
	ON_BN_CLICKED(IDC_CHECK_B6, &ASrdc_Dlgone::OnBnClickedCheckB6)
	ON_BN_CLICKED(IDC_CHECK_B12, &ASrdc_Dlgone::OnBnClickedCheckB12)
	ON_BN_CLICKED(IDC_CHECK_B1, &ASrdc_Dlgone::OnBnClickedCheckB1)
	ON_BN_CLICKED(IDC_CHECK_B7, &ASrdc_Dlgone::OnBnClickedCheckB7)
	ON_BN_CLICKED(IDC_CHECK_B2, &ASrdc_Dlgone::OnBnClickedCheckB2)
	ON_BN_CLICKED(IDC_CHECK_B8, &ASrdc_Dlgone::OnBnClickedCheckB8)
	ON_BN_CLICKED(IDC_CHECK_B13, &ASrdc_Dlgone::OnBnClickedCheckB13)
	ON_BN_CLICKED(IDC_CHECK_B3, &ASrdc_Dlgone::OnBnClickedCheckB3)
	ON_BN_CLICKED(IDC_CHECK_B9, &ASrdc_Dlgone::OnBnClickedCheckB9)
	ON_BN_CLICKED(IDC_CHECK_B14, &ASrdc_Dlgone::OnBnClickedCheckB14)
	ON_BN_CLICKED(IDC_CHECK_B4, &ASrdc_Dlgone::OnBnClickedCheckB4)
	ON_BN_CLICKED(IDC_CHECK_B10, &ASrdc_Dlgone::OnBnClickedCheckB10)
	ON_BN_CLICKED(IDC_CHECK_B5, &ASrdc_Dlgone::OnBnClickedCheckB5)
	ON_BN_CLICKED(IDC_CHECK_B11, &ASrdc_Dlgone::OnBnClickedCheckB11)
	ON_BN_CLICKED(IDC_CHECK_EMca, &ASrdc_Dlgone::OnBnClickedCheckEmca)
	ON_BN_CLICKED(IDC_CHECK_U0, &ASrdc_Dlgone::OnBnClickedCheckU0)
	ON_BN_CLICKED(IDC_CHECK_U6, &ASrdc_Dlgone::OnBnClickedCheckU6)
	ON_BN_CLICKED(IDC_CHECK_U12, &ASrdc_Dlgone::OnBnClickedCheckU12)
	ON_BN_CLICKED(IDC_CHECK_U1, &ASrdc_Dlgone::OnBnClickedCheckU1)
	ON_BN_CLICKED(IDC_CHECK_U7, &ASrdc_Dlgone::OnBnClickedCheckU7)
	ON_BN_CLICKED(IDC_CHECK_U2, &ASrdc_Dlgone::OnBnClickedCheckU2)
	ON_BN_CLICKED(IDC_CHECK_U8, &ASrdc_Dlgone::OnBnClickedCheckU8)
	ON_BN_CLICKED(IDC_CHECK_U13, &ASrdc_Dlgone::OnBnClickedCheckU13)
	ON_BN_CLICKED(IDC_CHECK_U3, &ASrdc_Dlgone::OnBnClickedCheckU3)
	ON_BN_CLICKED(IDC_CHECK_U9, &ASrdc_Dlgone::OnBnClickedCheckU9)
	ON_BN_CLICKED(IDC_CHECK_U14, &ASrdc_Dlgone::OnBnClickedCheckU14)
	ON_BN_CLICKED(IDC_CHECK_U4, &ASrdc_Dlgone::OnBnClickedCheckU4)
	ON_BN_CLICKED(IDC_CHECK_U10, &ASrdc_Dlgone::OnBnClickedCheckU10)
	ON_BN_CLICKED(IDC_CHECK_U5, &ASrdc_Dlgone::OnBnClickedCheckU5)
	ON_BN_CLICKED(IDC_CHECK_U11, &ASrdc_Dlgone::OnBnClickedCheckU11)
	ON_BN_CLICKED(IDC_CHECK_EMca2, &ASrdc_Dlgone::OnBnClickedCheckEmca2)
	ON_EN_CHANGE(IDC_EDIT_HS, &ASrdc_Dlgone::OnEnChangeEditHs)
	ON_EN_CHANGE(IDC_EDIT_HE, &ASrdc_Dlgone::OnEnChangeEditHe)
	ON_EN_CHANGE(IDC_EDIT_H1, &ASrdc_Dlgone::OnEnChangeEditH1)
	ON_EN_CHANGE(IDC_EDIT_H2, &ASrdc_Dlgone::OnEnChangeEditH2)
	ON_EN_CHANGE(IDC_EDIT_H3, &ASrdc_Dlgone::OnEnChangeEditH3)
	ON_EN_CHANGE(IDC_EDIT_H4, &ASrdc_Dlgone::OnEnChangeEditH4)
	ON_EN_CHANGE(IDC_EDIT_H5, &ASrdc_Dlgone::OnEnChangeEditH5)
	ON_EN_CHANGE(IDC_EDIT_H6, &ASrdc_Dlgone::OnEnChangeEditH6)
	ON_EN_CHANGE(IDC_EDIT_H7, &ASrdc_Dlgone::OnEnChangeEditH7)
	ON_EN_CHANGE(IDC_EDIT_H8, &ASrdc_Dlgone::OnEnChangeEditH8)
	ON_EN_CHANGE(IDC_EDIT_H9, &ASrdc_Dlgone::OnEnChangeEditH9)
	ON_EN_CHANGE(IDC_EDIT_H10, &ASrdc_Dlgone::OnEnChangeEditH10)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_BS, &ASrdc_Dlgone::OnDeltaposSpinBs)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_BE, &ASrdc_Dlgone::OnDeltaposSpinBe)
	ON_EN_CHANGE(IDC_EDIT_BS, &ASrdc_Dlgone::OnEnChangeEditBs)
	ON_EN_CHANGE(IDC_EDIT_BE, &ASrdc_Dlgone::OnEnChangeEditBe)
	ON_EN_CHANGE(IDC_EDIT_C1, &ASrdc_Dlgone::OnEnChangeEditC1)
	ON_EN_CHANGE(IDC_EDIT_C3, &ASrdc_Dlgone::OnEnChangeEditC3)
	ON_EN_CHANGE(IDC_EDIT_C2, &ASrdc_Dlgone::OnEnChangeEditC2)
	ON_EN_CHANGE(IDC_EDIT_C5, &ASrdc_Dlgone::OnEnChangeEditC5)
	ON_EN_CHANGE(IDC_EDIT_C4, &ASrdc_Dlgone::OnEnChangeEditC4)
	ON_EN_CHANGE(IDC_EDIT_C6, &ASrdc_Dlgone::OnEnChangeEditC6)
	ON_EN_CHANGE(IDC_EDIT_C7, &ASrdc_Dlgone::OnEnChangeEditC7)
	ON_EN_CHANGE(IDC_EDIT_C8, &ASrdc_Dlgone::OnEnChangeEditC8)
	ON_EN_CHANGE(IDC_EDIT_C9, &ASrdc_Dlgone::OnEnChangeEditC9)
	ON_EN_CHANGE(IDC_EDIT_C10, &ASrdc_Dlgone::OnEnChangeEditC10)
	ON_EN_CHANGE(IDC_EDIT_C11, &ASrdc_Dlgone::OnEnChangeEditC11)
	ON_EN_CHANGE(IDC_EDIT_C12, &ASrdc_Dlgone::OnEnChangeEditC12)
	ON_EN_CHANGE(IDC_EDIT_C13, &ASrdc_Dlgone::OnEnChangeEditC13)
	ON_EN_CHANGE(IDC_EDIT_C14, &ASrdc_Dlgone::OnEnChangeEditC14)
	ON_EN_CHANGE(IDC_EDIT_C15, &ASrdc_Dlgone::OnEnChangeEditC15)
	ON_EN_CHANGE(IDC_EDIT_C16, &ASrdc_Dlgone::OnEnChangeEditC16)
	ON_EN_CHANGE(IDC_EDIT_C17, &ASrdc_Dlgone::OnEnChangeEditC17)
	ON_EN_CHANGE(IDC_EDIT_C18, &ASrdc_Dlgone::OnEnChangeEditC18)
	ON_EN_CHANGE(IDC_EDIT_C19, &ASrdc_Dlgone::OnEnChangeEditC19)
	ON_EN_CHANGE(IDC_EDIT_C20, &ASrdc_Dlgone::OnEnChangeEditC20)
END_MESSAGE_MAP()


// ASrdc_Dlgone 消息处理程序


BOOL ASrdc_Dlgone::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化
	lpASrdc_Dlgone=&m_ASrdc_Dlgone;//窗口寻址
	SetBackgroundColor(RGB(176,196,222));

	SetDlgItemText(IDC_EDIT_HS,"1");
	m_Spin_MS.SetBuddy(GetDlgItem(IDC_EDIT_HS)); //得到指向编辑框的窗口指针
	m_Spin_MS.SetRange(1,10);
	/////////////////
	SetDlgItemText(IDC_EDIT_HE,"1");
	m_Spin_ME.SetBuddy(GetDlgItem(IDC_EDIT_HE)); //得到指向编辑框的窗口指针
	m_Spin_ME.SetRange(1,10);

	SetDlgItemText(IDC_EDIT_BS,"1");
	m_Spin_BS.SetBuddy(GetDlgItem(IDC_EDIT_BS)); //得到指向编辑框的窗口指针
	m_Spin_BS.SetRange(1,20);
	/////////////////
	SetDlgItemText(IDC_EDIT_BE,"1");
	m_Spin_BE.SetBuddy(GetDlgItem(IDC_EDIT_BE)); //得到指向编辑框的窗口指针
	m_Spin_BE.SetRange(1,20);

    m_Check_EMca.SetCheck(1);
	OnBnClickedCheckEmca();

	m_Check_EMca2.SetCheck(1);
	OnBnClickedCheckEmca2();

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


void ASrdc_Dlgone::ReSize(UINT nType, int cx, int cy)
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

void ASrdc_Dlgone::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}

void ASrdc_Dlgone::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnCancel();
}

void ASrdc_Dlgone::GetKREMValue()
{
	int iB0=0,iB1=0,iB2=0,iB3=0,iB4=0,iB5=0,iB6=0,iB7=0,iB8=0,iB9=0,iB10=0,iB11=0,iB12=0,iB13=0,iB14=0;
	CString sStrB="",sStrH="",sCmd="",sNewCmd="";

	iB0=m_Check_B0.GetCheck();
	iB1=m_Check_B1.GetCheck();
	iB2=m_Check_B2.GetCheck();
	iB3=m_Check_B3.GetCheck();
	iB4=m_Check_B4.GetCheck();
	iB5=m_Check_B5.GetCheck();
	iB6=m_Check_B6.GetCheck();
	iB7=m_Check_B7.GetCheck();
	iB8=m_Check_B8.GetCheck();
	iB9=m_Check_B9.GetCheck();
	iB10=m_Check_B10.GetCheck();
	iB11=m_Check_B11.GetCheck();
	iB12=m_Check_B12.GetCheck();
	iB13=m_Check_B13.GetCheck();
	iB14=m_Check_B14.GetCheck();
	sStrB.Format("0%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",iB14,iB13,iB12,iB11,iB10,iB9,iB8,iB7,iB6,iB5,iB4,iB3,iB2,iB1,iB0);
	m_MYWORK.BsToHex(sStrB,sStrH,4);
	g_sKREMValue=sStrH;
	lpASrdc_Dlgnew->GetCMD();
}

void ASrdc_Dlgone::SetKREMValue(CString sStrH)
{
	CArray<CButton*,CButton* > arrButtonlp;
	/////////////////////
	CString sStrB="",sTemp="";
	m_MYWORK.HexToBsStr(sStrH,sStrB,15);
	///////////////////////////////
	arrButtonlp.Add(&m_Check_B0);//0是低位14是高位
	arrButtonlp.Add(&m_Check_B1);//0是低位14是高位
	arrButtonlp.Add(&m_Check_B2);//0是低位14是高位
	arrButtonlp.Add(&m_Check_B3);//0是低位14是高位
	arrButtonlp.Add(&m_Check_B4);//0是低位14是高位
	arrButtonlp.Add(&m_Check_B5);//0是低位14是高位
	arrButtonlp.Add(&m_Check_B6);//0是低位14是高位
	arrButtonlp.Add(&m_Check_B7);//0是低位14是高位
	arrButtonlp.Add(&m_Check_B8);//0是低位14是高位
	arrButtonlp.Add(&m_Check_B9);//0是低位14是高位
	arrButtonlp.Add(&m_Check_B10);//0是低位14是高位
	arrButtonlp.Add(&m_Check_B11);//0是低位14是高位
	arrButtonlp.Add(&m_Check_B12);//0是低位14是高位
	arrButtonlp.Add(&m_Check_B13);//0是低位14是高位
	arrButtonlp.Add(&m_Check_B14);//0是低位14是高位

	for (int i=0;i<arrButtonlp.GetSize();i++)
	{
		CString sStr="";
		sStr.Format("%c",sStrB[i]);
		int j=atoi(sStr);
		arrButtonlp.GetAt(arrButtonlp.GetSize()-1-i)->SetCheck(j);
	}
	GetKREMValue();
}

void ASrdc_Dlgone::GetUREMValue()
{
	int iB0=0,iB1=0,iB2=0,iB3=0,iB4=0,iB5=0,iB6=0,iB7=0,iB8=0,iB9=0,iB10=0,iB11=0,iB12=0,iB13=0,iB14=0;
	CString sStrB="",sStrH="",sCmd="",sNewCmd="";

	iB0=m_Check_U0.GetCheck();
	iB1=m_Check_U1.GetCheck();
	iB2=m_Check_U2.GetCheck();
	iB3=m_Check_U3.GetCheck();
	iB4=m_Check_U4.GetCheck();
	iB5=m_Check_U5.GetCheck();
	iB6=m_Check_U6.GetCheck();
	iB7=m_Check_U7.GetCheck();
	iB8=m_Check_U8.GetCheck();
	iB9=m_Check_U9.GetCheck();
	iB10=m_Check_U10.GetCheck();
	iB11=m_Check_U11.GetCheck();
	iB12=m_Check_U12.GetCheck();
	iB13=m_Check_U13.GetCheck();
	iB14=m_Check_U14.GetCheck();

	sStrB.Format("0%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",iB14,iB13,iB12,iB11,iB10,iB9,iB8,iB7,iB6,iB5,iB4,iB3,iB2,iB1,iB0);
	m_MYWORK.BsToHex(sStrB,sStrH,4);
	g_sUREMValue=sStrH;
	lpASrdc_Dlgnew->GetCMD();
}

void ASrdc_Dlgone::SetUREMValue(CString sStrH)
{
	CArray<CButton*,CButton* > arrButtonlp;
	/////////////////////
	CString sStrB="",sTemp="";
	m_MYWORK.HexToBsStr(sStrH,sStrB,15);
	///////////////////////////////
	arrButtonlp.Add(&m_Check_U0);//0是低位14是高位
	arrButtonlp.Add(&m_Check_U1);//0是低位14是高位
	arrButtonlp.Add(&m_Check_U2);//0是低位14是高位
	arrButtonlp.Add(&m_Check_U3);//0是低位14是高位
	arrButtonlp.Add(&m_Check_U4);//0是低位14是高位
	arrButtonlp.Add(&m_Check_U5);//0是低位14是高位
	arrButtonlp.Add(&m_Check_U6);//0是低位14是高位
	arrButtonlp.Add(&m_Check_U7);//0是低位14是高位
	arrButtonlp.Add(&m_Check_U8);//0是低位14是高位
	arrButtonlp.Add(&m_Check_U9);//0是低位14是高位
	arrButtonlp.Add(&m_Check_U10);//0是低位14是高位
	arrButtonlp.Add(&m_Check_U11);//0是低位14是高位
	arrButtonlp.Add(&m_Check_U12);//0是低位14是高位
	arrButtonlp.Add(&m_Check_U13);//0是低位14是高位
	arrButtonlp.Add(&m_Check_U14);//0是低位14是高位

	for (int i=0;i<arrButtonlp.GetSize();i++)
	{
		CString sStr="";
		sStr.Format("%c",sStrB[i]);
		int j=atoi(sStr);
		arrButtonlp.GetAt(arrButtonlp.GetSize()-1-i)->SetCheck(j);
	}
	GetUREMValue();
}

void ASrdc_Dlgone::OnDeltaposSpinMs(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_MS.GetPos();
	m_Spin_MS.SetPos(iTemp);
	m_Edit_HS.GetWindowText(strValue);  
	*pResult = 0;
}

void ASrdc_Dlgone::OnDeltaposSpinMe(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_ME.GetPos();
	m_Spin_ME.SetPos(iTemp);
	m_Edit_HE.GetWindowText(strValue);  
	*pResult = 0;
}

void ASrdc_Dlgone::OnBnClickedCheckB0()
{
   GetKREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckB6()
{
	GetKREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckB12()
{
	  GetKREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckB1()
{
	  GetKREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckB7()
{
    GetKREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckB2()
{
	  GetKREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckB8()
{
	  GetKREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckB13()
{
  GetKREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckB3()
{
  GetKREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckB9()
{
	  GetKREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckB14()
{
  GetKREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckB4()
{
  GetKREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckB10()
{
	  GetKREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckB5()
{
  GetKREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckB11()
{
	  GetKREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckEmca()
{
	int iTemp=0;
	iTemp=m_Check_EMca.GetCheck();
	if (iTemp)
	{
		m_Check_B0.SetCheck(1);
		m_Check_B1.SetCheck(1);
		m_Check_B2.SetCheck(1);
		m_Check_B3.SetCheck(1);
		m_Check_B4.SetCheck(1);
		m_Check_B5.SetCheck(1);
		m_Check_B6.SetCheck(1);
		m_Check_B7.SetCheck(1);
		m_Check_B8.SetCheck(1);
		m_Check_B9.SetCheck(1);
		m_Check_B10.SetCheck(1);
		m_Check_B11.SetCheck(1);
		m_Check_B12.SetCheck(1);
		m_Check_B13.SetCheck(1);
		m_Check_B14.SetCheck(1);
	}
	else
	{
		m_Check_B0.SetCheck(0);
		m_Check_B1.SetCheck(0);
		m_Check_B2.SetCheck(0);
		m_Check_B3.SetCheck(0);
		m_Check_B4.SetCheck(0);
		m_Check_B5.SetCheck(0);
		m_Check_B6.SetCheck(0);
		m_Check_B7.SetCheck(0);
		m_Check_B8.SetCheck(0);
		m_Check_B9.SetCheck(0);
		m_Check_B10.SetCheck(0);
		m_Check_B11.SetCheck(0);
		m_Check_B12.SetCheck(0);
		m_Check_B13.SetCheck(0);
		m_Check_B14.SetCheck(0);
	}
	GetKREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckU0()
{
	GetUREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckU6()
{
	GetUREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckU12()
{
	GetUREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckU1()
{
	GetUREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckU7()
{
	GetUREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckU2()
{
	GetUREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckU8()
{
	GetUREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckU13()
{
	GetUREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckU3()
{
	GetUREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckU9()
{
	GetUREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckU14()
{
	GetUREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckU4()
{
	GetUREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckU10()
{
	GetUREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckU5()
{
	GetUREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckU11()
{
	GetUREMValue();
}


void ASrdc_Dlgone::OnBnClickedCheckEmca2()
{
	int iTemp=0;
	iTemp=m_Check_EMca2.GetCheck();
	if (iTemp)
	{
		m_Check_U0.SetCheck(1);
		m_Check_U1.SetCheck(1);
		m_Check_U2.SetCheck(1);
		m_Check_U3.SetCheck(1);
		m_Check_U4.SetCheck(1);
		m_Check_U5.SetCheck(1);
		m_Check_U6.SetCheck(1);
		m_Check_U7.SetCheck(1);
		m_Check_U8.SetCheck(1);
		m_Check_U9.SetCheck(1);
		m_Check_U10.SetCheck(1);
		m_Check_U11.SetCheck(1);
		m_Check_U12.SetCheck(1);
		m_Check_U13.SetCheck(1);
		m_Check_U14.SetCheck(1);
	}
	else
	{
		m_Check_U0.SetCheck(0);
		m_Check_U1.SetCheck(0);
		m_Check_U2.SetCheck(0);
		m_Check_U3.SetCheck(0);
		m_Check_U4.SetCheck(0);
		m_Check_U5.SetCheck(0);
		m_Check_U6.SetCheck(0);
		m_Check_U7.SetCheck(0);
		m_Check_U8.SetCheck(0);
		m_Check_U9.SetCheck(0);
		m_Check_U10.SetCheck(0);
		m_Check_U11.SetCheck(0);
		m_Check_U12.SetCheck(0);
		m_Check_U13.SetCheck(0);
		m_Check_U14.SetCheck(0);
	}
	GetUREMValue();
}


void ASrdc_Dlgone::OnEnChangeEditHs()
{
	CString sStart="",sEnd="";
	m_Edit_HS.GetWindowText(sStart);
	m_Edit_HE.GetWindowText(sEnd);
	if (atoi(sStart)>atoi(sEnd))
	{
		m_Edit_HE.SetWindowText(sStart);
	}
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditHe()
{
	CString sStart="",sEnd="";
	m_Edit_HS.GetWindowText(sStart);
	m_Edit_HE.GetWindowText(sEnd);
	if (atoi(sStart)>atoi(sEnd))
	{
		m_Edit_HS.SetWindowText(sEnd);
	}
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditH1()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditH2()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditH3()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditH4()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditH5()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditH6()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditH7()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditH8()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditH9()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditH10()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnDeltaposSpinBs(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_BS.GetPos();
	m_Spin_BS.SetPos(iTemp);
	m_Edit_BS.GetWindowText(strValue);  
	*pResult = 0;
}


void ASrdc_Dlgone::OnDeltaposSpinBe(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_BE.GetPos();
	m_Spin_BE.SetPos(iTemp);
	m_Edit_BE.GetWindowText(strValue);  
	*pResult = 0;
}


void ASrdc_Dlgone::OnEnChangeEditBs()
{
	CString sStart="",sEnd="";
	m_Edit_BS.GetWindowText(sStart);
	m_Edit_BE.GetWindowText(sEnd);
	if (atoi(sStart)>atoi(sEnd))
	{
		m_Edit_BE.SetWindowText(sStart);
	}
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditBe()
{
	CString sStart="",sEnd="";
	m_Edit_BS.GetWindowText(sStart);
	m_Edit_BE.GetWindowText(sEnd);
	if (atoi(sStart)>atoi(sEnd))
	{
		m_Edit_BS.SetWindowText(sEnd);
	}
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC1()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC3()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC2()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC5()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC4()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC6()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC7()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC8()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC9()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC10()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC11()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC12()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC13()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC14()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC15()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC16()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC17()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC18()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC19()
{
	lpASrdc_Dlgnew->GetCMD();
}


void ASrdc_Dlgone::OnEnChangeEditC20()
{
	lpASrdc_Dlgnew->GetCMD();
}
