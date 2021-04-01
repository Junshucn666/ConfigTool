// ASeid_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ASeid_Dlg.h"
#include "afxdialogex.h"

///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern ASeid_Dlg m_ASeid_Dlg;
ASeid_Dlg*	lpASeid_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
extern ASeid_Dlg m_ASeid_Dlg;
////////////

IMPLEMENT_DYNAMIC(ASeid_Dlg, CMyTabBaseDlg)

ASeid_Dlg::ASeid_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(ASeid_Dlg::IDD, pParent)
{

}

ASeid_Dlg::~ASeid_Dlg()
{
}

void ASeid_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_SPIN_IDT, m_Spin_IDT);
	DDX_Control(pDX, IDC_EDIT_IDT, m_Edit_IDT);
	DDX_Control(pDX, IDC_SPIN_IET, m_Spin_IET);
	DDX_Control(pDX, IDC_EDIT_IET, m_Edit_IET);
	DDX_Control(pDX, IDC_COMBO_DO, m_ComboBox_DO);
	DDX_Control(pDX, IDC_COMBO_OI, m_ComboBox_OI);
	DDX_Control(pDX, IDC_CHECK_OutS, m_Check_OutS);
	DDX_Control(pDX, IDC_SPIN_D, m_Spin_D);
	DDX_Control(pDX, IDC_EDIT_D, m_Edit_D);
	DDX_Control(pDX, IDC_SPIN_TT, m_Spin_TT);
	DDX_Control(pDX, IDC_EDIT_TT, m_Edit_TT);
}


BEGIN_MESSAGE_MAP(ASeid_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &ASeid_Dlg::OnCbnSelchangeComboM)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_IDT, &ASeid_Dlg::OnDeltaposSpinIdt)
	ON_EN_CHANGE(IDC_EDIT_IDT, &ASeid_Dlg::OnEnChangeEditIdt)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_IET, &ASeid_Dlg::OnDeltaposSpinIet)
	ON_EN_CHANGE(IDC_EDIT_IET, &ASeid_Dlg::OnEnChangeEditIet)
	ON_CBN_SELCHANGE(IDC_COMBO_DO, &ASeid_Dlg::OnCbnSelchangeComboDo)
	ON_CBN_SELCHANGE(IDC_COMBO_OI, &ASeid_Dlg::OnCbnSelchangeComboOi)
	ON_BN_CLICKED(IDC_CHECK_OutS, &ASeid_Dlg::OnBnClickedCheckOuts)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D, &ASeid_Dlg::OnDeltaposSpinD)
	ON_EN_CHANGE(IDC_EDIT_D, &ASeid_Dlg::OnEnChangeEditD)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT, &ASeid_Dlg::OnDeltaposSpinTt)
	ON_EN_CHANGE(IDC_EDIT_TT, &ASeid_Dlg::OnEnChangeEditTt)
END_MESSAGE_MAP()


// ASeid_Dlg 消息处理程序


BOOL ASeid_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpASeid_Dlg=&m_ASeid_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_ASeid_Dlg;
	m_iWhoamI=GTIDL;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTIDL].sCmdstr);

	m_ComboBox_M.InsertString(0,"0: Disable this function");
	m_ComboBox_M.InsertString(1,"1: Enable this function");
	m_ComboBox_M.SetCurSel(0);

	SetDlgItemText(IDC_EDIT_IDT,"2");
	m_Spin_IDT.SetBuddy(GetDlgItem(IDC_EDIT_IDT)); //得到指向编辑框的窗口指针
	m_Spin_IDT.SetRange(1,30);

	SetDlgItemText(IDC_EDIT_IET,"1");
	m_Spin_IET.SetBuddy(GetDlgItem(IDC_EDIT_IET)); //得到指向编辑框的窗口指针
	m_Spin_IET.SetRange(1,5);

	m_ComboBox_DO.InsertString(0,"0");
	m_ComboBox_DO.InsertString(1,"1");
	m_ComboBox_DO.SetCurSel(0);
	///////////////
	m_ComboBox_OI.InsertString(0,"0");
	m_ComboBox_OI.InsertString(1,"1");
	m_ComboBox_OI.InsertString(2,"2");
	m_ComboBox_OI.SetCurSel(0);
	///////////////
	SetDlgItemText(IDC_EDIT_D,"0");
	m_Spin_D.SetBuddy(GetDlgItem(IDC_EDIT_D)); //得到指向编辑框的窗口指针
	m_Spin_D.SetRange(0,255);

	SetDlgItemText(IDC_EDIT_TT,"0");
	m_Spin_TT.SetBuddy(GetDlgItem(IDC_EDIT_TT)); //得到指向编辑框的窗口指针
	m_Spin_TT.SetRange(0,255);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


CString ASeid_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
{   //位置iPos是从0开始的
	CString sNewCmd="",sRight="",sLeft="",sTemp="";
	CArray<CString,CString>ValueList;
	int index1=0,index2=0;
	sTemp=sParestr;//准备分割
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
	for (int i=0;i<ValueList.GetSize();i++)
	{
		if (0==i)
		{
			sNewCmd=ValueList.GetAt(0);
		}
		else
		{
			if (i==iPos)
			{
				sNewCmd=sNewCmd+","+sChildstr;
			}
			else
			{
				sNewCmd=sNewCmd+","+ValueList.GetAt(i);
			}
		}
	}
	return sNewCmd;
}

BOOL ASeid_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>12)
	{
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboM();	
		m_Edit_IDT.SetWindowText(ValueList.GetAt(2));
		m_Edit_IET.SetWindowText(ValueList.GetAt(3));	
		m_ComboBox_DO.SetCurSel(atoi(ValueList.GetAt(12)));
		OnCbnSelchangeComboDo();

		m_ComboBox_OI.SetCurSel(atoi(ValueList.GetAt(8)));
		OnCbnSelchangeComboOi();
		m_Check_OutS.SetCheck(atoi(ValueList.GetAt(9)));
		OnBnClickedCheckOuts();
		m_Edit_D.SetWindowText(ValueList.GetAt(10));
		m_Edit_TT.SetWindowText(ValueList.GetAt(11));

		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}
//2
void ASeid_Dlg::OnCbnSelchangeComboM()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_M.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void ASeid_Dlg::OnDeltaposSpinIdt(NMHDR *pNMHDR, LRESULT *pResult)
{
	/////////////////
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_IDT.GetPos();
	m_Spin_IDT.SetPos(iTemp);
	m_Edit_IDT.GetWindowText(strValue);  
	*pResult = 0;
}

//3
void ASeid_Dlg::OnEnChangeEditIdt()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_IDT.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,2,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void ASeid_Dlg::OnDeltaposSpinIet(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_IET.GetPos();
	m_Spin_IET.SetPos(iTemp);
	m_Edit_IET.GetWindowText(strValue);  
	*pResult = 0;
}

//4
void ASeid_Dlg::OnEnChangeEditIet()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_IET.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,3,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//13
void ASeid_Dlg::OnCbnSelchangeComboDo()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_DO.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,12,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//9
void ASeid_Dlg::OnCbnSelchangeComboOi()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_OI.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,8,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//10
void ASeid_Dlg::OnBnClickedCheckOuts()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_OutS.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,9,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void ASeid_Dlg::OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D.GetPos();
	m_Spin_D.SetPos(iTemp);
	m_Edit_D.GetWindowText(strValue);  
	*pResult = 0;
}

//11
void ASeid_Dlg::OnEnChangeEditD()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_D.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,10,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void ASeid_Dlg::OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT.GetPos();
	m_Spin_TT.SetPos(iTemp);
	m_Edit_TT.GetWindowText(strValue);  
	*pResult = 0;
}

//12
void ASeid_Dlg::OnEnChangeEditTt()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TT.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,11,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

