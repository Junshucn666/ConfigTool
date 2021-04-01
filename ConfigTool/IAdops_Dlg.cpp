// IAdops_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "IAdops_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern IAdops_Dlg m_IAdops_Dlg;
IAdops_Dlg*	lpIAdops_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(IAdops_Dlg, CMyTabBaseDlg)

IAdops_Dlg::IAdops_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(IAdops_Dlg::IDD, pParent)
{

}

IAdops_Dlg::~IAdops_Dlg()
{
}

void IAdops_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_OutS1, m_Check_OutS1);
	DDX_Control(pDX, IDC_CHECK_OutS2, m_Check_OutS2);
	DDX_Control(pDX, IDC_SPIN_D1, m_Spin_D1);
	DDX_Control(pDX, IDC_SPIN_D2, m_Spin_D2);
	DDX_Control(pDX, IDC_SPIN_TT2, m_Spin_TT2);
	DDX_Control(pDX, IDC_SPIN_TT1, m_Spin_TT1);
	DDX_Control(pDX, IDC_EDIT_D1, m_Edit_D1);
	DDX_Control(pDX, IDC_EDIT_D2, m_Edit_D2);
	DDX_Control(pDX, IDC_EDIT_TT1, m_Edit_TT1);
	DDX_Control(pDX, IDC_EDIT_TT2, m_Edit_TT2);
	DDX_Control(pDX, IDC_CHECK_O1, m_Check_O1);
	DDX_Control(pDX, IDC_CHECK_O2, m_Check_O2);
	DDX_Control(pDX, IDC_SPIN_L1, m_Spin_L1);
	DDX_Control(pDX, IDC_SPIN_L2, m_Spin_L2);
	DDX_Control(pDX, IDC_EDIT_L1, m_Edit_L1);
	DDX_Control(pDX, IDC_EDIT_L2, m_Edit_L2);
}


BEGIN_MESSAGE_MAP(IAdops_Dlg, CMyTabBaseDlg)
	ON_BN_CLICKED(IDC_CHECK_OutS1, &IAdops_Dlg::OnBnClickedCheckOuts1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D1, &IAdops_Dlg::OnDeltaposSpinD1)
	ON_EN_CHANGE(IDC_EDIT_D1, &IAdops_Dlg::OnEnChangeEditD1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT1, &IAdops_Dlg::OnDeltaposSpinTt1)
	ON_EN_CHANGE(IDC_EDIT_TT1, &IAdops_Dlg::OnEnChangeEditTt1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D2, &IAdops_Dlg::OnDeltaposSpinD2)
	ON_EN_CHANGE(IDC_EDIT_D2, &IAdops_Dlg::OnEnChangeEditD2)
	ON_BN_CLICKED(IDC_CHECK_OutS2, &IAdops_Dlg::OnBnClickedCheckOuts2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT2, &IAdops_Dlg::OnDeltaposSpinTt2)
	ON_EN_CHANGE(IDC_EDIT_TT2, &IAdops_Dlg::OnEnChangeEditTt2)
	ON_BN_CLICKED(IDC_CHECK_O1, &IAdops_Dlg::OnBnClickedCheckO1)
	ON_BN_CLICKED(IDC_CHECK_O2, &IAdops_Dlg::OnBnClickedCheckO2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_L1, &IAdops_Dlg::OnDeltaposSpinL1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_L2, &IAdops_Dlg::OnDeltaposSpinL2)
	ON_EN_CHANGE(IDC_EDIT_L1, &IAdops_Dlg::OnEnChangeEditL1)
	ON_EN_CHANGE(IDC_EDIT_L2, &IAdops_Dlg::OnEnChangeEditL2)
END_MESSAGE_MAP()


// IAdops_Dlg 消息处理程序


BOOL IAdops_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpIAdops_Dlg=&m_IAdops_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_IAdops_Dlg;
	m_iWhoamI=GTOUT;


	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTOUT].sCmdstr);
	
	///////////////
	//SetDlgItemText(IDC_EDIT_D1,"0");
	//m_Spin_D1.SetBuddy(GetDlgItem(IDC_EDIT_D1)); //得到指向编辑框的窗口指针
	//m_Spin_D1.SetRange(0,255);

	//SetDlgItemText(IDC_EDIT_TT1,"0");
	//m_Spin_TT1.SetBuddy(GetDlgItem(IDC_EDIT_TT1)); //得到指向编辑框的窗口指针
	//m_Spin_TT1.SetRange(0,255);

	///////////////
	SetDlgItemText(IDC_EDIT_D2,"0");
	m_Spin_D2.SetBuddy(GetDlgItem(IDC_EDIT_D2)); //得到指向编辑框的窗口指针
	m_Spin_D2.SetRange(0,255);

	SetDlgItemText(IDC_EDIT_TT2,"0");
	m_Spin_TT2.SetBuddy(GetDlgItem(IDC_EDIT_TT2)); //得到指向编辑框的窗口指针
	m_Spin_TT2.SetRange(0,255);

	SetDlgItemText(IDC_EDIT_L1,"0");
	m_Spin_L1.SetBuddy(GetDlgItem(IDC_EDIT_L1)); //得到指向编辑框的窗口指针
	m_Spin_L1.SetRange(0,120);
	SetDlgItemText(IDC_EDIT_L2,"0");
	m_Spin_L2.SetBuddy(GetDlgItem(IDC_EDIT_L2)); //得到指向编辑框的窗口指针
	m_Spin_L2.SetRange(0,120);
	
	///////////////////////////////////////////
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

BOOL IAdops_Dlg::UpdataPage(CString sStr)
{   //位置iPos是从0开始的
	CString sNewCmd="",sRight="",sLeft="",sTemp="";
	CArray<CString,CString>ValueList;
	int index1=0,index2=0;
	sTemp=sStr;//准备分割
	for (int i=0;i<20;i++)
	{
		index1=sTemp.Find(",");
		if (-1==index1)
		{	
			ValueList.Add(sLeft);
			break;
		}
		sRight=sTemp.Left(index1).Trim();//截取有用的
		index2=index1+1;
		sLeft=sTemp.Right(sTemp.GetLength()-index2).Trim();
		sTemp=sLeft;
		ValueList.Add(sRight);;
	}

	m_Check_OutS1.SetCheck(atoi(ValueList.GetAt(1)));
	OnBnClickedCheckOuts1();

	m_Check_OutS2.SetCheck(atoi(ValueList.GetAt(4)));
	OnBnClickedCheckOuts2();

	m_Edit_D2.SetWindowText(ValueList.GetAt(5));
	m_Edit_TT2.SetWindowText(ValueList.GetAt(6));
	m_Edit_L1.SetWindowText(ValueList.GetAt(17));
	m_Edit_L2.SetWindowText(ValueList.GetAt(18));

	SetOuValue(ValueList.GetAt(16));

	return TRUE;
}

//2
void IAdops_Dlg::OnBnClickedCheckOuts1()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_OutS1.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void IAdops_Dlg::OnDeltaposSpinD1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D1.GetPos();
	m_Spin_D1.SetPos(iTemp);
	m_Edit_D1.GetWindowText(strValue);  
	*pResult = 0;
}

//3
void IAdops_Dlg::OnEnChangeEditD1()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_D1.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,2,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void IAdops_Dlg::OnDeltaposSpinTt1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT1.GetPos();
	m_Spin_TT1.SetPos(iTemp);
	m_Edit_TT1.GetWindowText(strValue);  
	*pResult = 0;
}
//4
void IAdops_Dlg::OnEnChangeEditTt1()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TT1.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,3,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//5
void IAdops_Dlg::OnBnClickedCheckOuts2()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_OutS2.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,4,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void IAdops_Dlg::OnDeltaposSpinD2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D2.GetPos();
	m_Spin_D2.SetPos(iTemp);
	m_Edit_D2.GetWindowText(strValue);  
	*pResult = 0;
}

//6
void IAdops_Dlg::OnEnChangeEditD2()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_D2.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,5,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void IAdops_Dlg::OnDeltaposSpinTt2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT2.GetPos();
	m_Spin_TT2.SetPos(iTemp);
	m_Edit_TT2.GetWindowText(strValue);  
	*pResult = 0;
}
//7
void IAdops_Dlg::OnEnChangeEditTt2()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TT2.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,6,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}
//17
void IAdops_Dlg::GetOuValue()
{
	int iB0=0,iB1=0;
	CString sStrB="",sStrH="",sCmd="",sNewCmd="";
	iB0=m_Check_O1.GetCheck();
	iB1=m_Check_O2.GetCheck();
	sStrB.Format("%d%d",iB1,iB0);
	m_MYWORK.BsToHex(sStrB,sStrH,1);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStrH,16,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void IAdops_Dlg::SetOuValue(CString sStrH)
{
	CString sStrB="",sTemp="";
	int iB0=0,iB1=0;
	m_MYWORK.HexToBsStr(sStrH,sStrB,2);

	sTemp.Format("%c",sStrB[0]);
	iB1=atoi(sTemp);
	m_Check_O2.SetCheck(iB1);
	OnBnClickedCheckO2();

	sTemp.Format("%c",sStrB[1]);
	iB0=atoi(sTemp);
	m_Check_O1.SetCheck(iB0);
	OnBnClickedCheckO1();
}


void IAdops_Dlg::OnBnClickedCheckO1()
{
	GetOuValue();
}


void IAdops_Dlg::OnBnClickedCheckO2()
{
	GetOuValue();
}


void IAdops_Dlg::OnDeltaposSpinL1(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_L1.GetPos();
	m_Spin_L1.SetPos(iTemp);
	m_Edit_L1.GetWindowText(strValue);  
	*pResult = 0;
}


void IAdops_Dlg::OnDeltaposSpinL2(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_L2.GetPos();
	m_Spin_L2.SetPos(iTemp);
	m_Edit_L2.GetWindowText(strValue);  
	*pResult = 0;
}

//18
void IAdops_Dlg::OnEnChangeEditL1()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_L1.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,17,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//19
void IAdops_Dlg::OnEnChangeEditL2()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_L2.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,18,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

