// SCbsi_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "SCbsi_Dlg.h"
#include "afxdialogex.h"
#include "ConfigToolDlg.h"
#include "MYWORK.h"

// SCbsi_Dlg 对话框
extern CConfigToolDlg*	lpCConfigToolDlg;
//extern HANDLE g_hEvent;
//extern BOOL MYTHREAD_WORK;
SCbsi_Dlg*	lpSCbsi_Dlg;
extern int g_CSelTab;
extern ConfigCMD stu_ConfigCMD;
//extern CMYWORK	m_MYWORK;
extern SCbsi_Dlg m_SCbsi_Dlg;


IMPLEMENT_DYNAMIC(SCbsi_Dlg, CMyTabBaseDlg)

SCbsi_Dlg::SCbsi_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(SCbsi_Dlg::IDD, pParent)
{

}

SCbsi_Dlg::~SCbsi_Dlg()
{
}

void SCbsi_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_APN, m_Edit_APN);
	DDX_Control(pDX, IDC_EDIT_UserName, m_Edit_UserName);
	DDX_Control(pDX, IDC_EDIT_Password, m_Edit_Password);
	DDX_Control(pDX, IDC_EDIT_bAPN, m_Edit_BAPN);
	DDX_Control(pDX, IDC_EDIT_BUserName, m_Edit_BUserName);
	DDX_Control(pDX, IDC_EDIT_BPassword, m_Edit_BPassword);
	DDX_Control(pDX, IDC_COMBO_Ma, m_ComboBox_Ma);
	DDX_Control(pDX, IDC_COMBO_L, m_ComboBox_L);
	DDX_Control(pDX, IDC_COMBO_N, m_ComboBox_N);
	DDX_Control(pDX, IDC_COMBO_A, m_ComboBox_A);
}


BEGIN_MESSAGE_MAP(SCbsi_Dlg, CMyTabBaseDlg)
	ON_EN_CHANGE(IDC_EDIT_APN, &SCbsi_Dlg::OnEnChangeEditApn)
	ON_EN_CHANGE(IDC_EDIT_UserName, &SCbsi_Dlg::OnEnChangeEditUsername)
	ON_EN_CHANGE(IDC_EDIT_Password, &SCbsi_Dlg::OnEnChangeEditPassword)
	ON_EN_CHANGE(IDC_EDIT_bAPN, &SCbsi_Dlg::OnEnChangeEditbapn)
	ON_EN_CHANGE(IDC_EDIT_BUserName, &SCbsi_Dlg::OnEnChangeEditBusername)
	ON_EN_CHANGE(IDC_EDIT_BPassword, &SCbsi_Dlg::OnEnChangeEditBpassword)
	ON_CBN_SELCHANGE(IDC_COMBO_N, &SCbsi_Dlg::OnCbnSelchangeComboN)
	ON_CBN_SELCHANGE(IDC_COMBO_Ma, &SCbsi_Dlg::OnCbnSelchangeComboMa)
	ON_CBN_SELCHANGE(IDC_COMBO_L, &SCbsi_Dlg::OnCbnSelchangeComboL)
	ON_CBN_SELCHANGE(IDC_COMBO_A, &SCbsi_Dlg::OnCbnSelchangeComboA)
//	ON_WM_PAINT()
END_MESSAGE_MAP()


// SCbsi_Dlg 消息处理程序

BOOL SCbsi_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	// TODO:  在此添加额外的初始化
	lpSCbsi_Dlg=&m_SCbsi_Dlg;//窗口寻址
	m_lpMyTabBaseDlg=&m_SCbsi_Dlg;
	m_iWhoamI=GTBSI;
	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[m_iWhoamI].sCmdstr);
	                             
	SetDlgItemText(IDC_EDIT_UserName,"");
	SetDlgItemText(IDC_EDIT_Password,"");

	m_ComboBox_Ma.InsertString(0,"0: Cat-M1 First (Cat-M1 & Cat-NB1).");
	m_ComboBox_Ma.InsertString(1,"1: Cat-NB1 First (Cat-M1 & Cat-NB1).");
	m_ComboBox_Ma.InsertString(2,"2: Cat-M1.");
	m_ComboBox_Ma.InsertString(3,"3: Cat-NB1.");
	m_ComboBox_Ma.SetCurSel(2);
	///////////////
	m_ComboBox_L.InsertString(0,"0: Disable manually register the network");
	m_ComboBox_L.InsertString(1,"1: Enable manually register the network");
	m_ComboBox_L.SetCurSel(0);
	///////////////
	m_ComboBox_N.InsertString(0,"0: Auto. (LTE &GSM)");
	m_ComboBox_N.InsertString(1,"1: GSM only.");
	m_ComboBox_N.InsertString(2,"2: LTE only.");
	m_ComboBox_N.InsertString(3,"3: GSM First. (LTE & GSM)");
	m_ComboBox_N.SetCurSel(0);
	///////////////
	m_ComboBox_A.InsertString(0,"0: No authentication.");
	m_ComboBox_A.InsertString(1,"1: PAP authentication");
	m_ComboBox_A.InsertString(2,"2: CHAP authentication.");
	m_ComboBox_A.InsertString(3,"3: PAP or CHAP authentication.");
	m_ComboBox_A.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString SCbsi_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL SCbsi_Dlg::UpdataPage(CString sStr)
{   //位置iPos是从0开始的
	CString sNewCmd="",sRight="",sLeft="",sTemp="";
	CArray<CString,CString>ValueList;
	int index1=0,index2=0;
	sTemp=sStr;//准备分割
	for (int i=0;i<100;i++)
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

	if (ValueList.GetSize()>9)
	{
		m_Edit_APN.SetWindowText(ValueList.GetAt(1));
		m_Edit_UserName.SetWindowText(ValueList.GetAt(2));
		m_Edit_Password.SetWindowText(ValueList.GetAt(3));
		m_Edit_BAPN.SetWindowText(ValueList.GetAt(4));
		m_Edit_BUserName.SetWindowText(ValueList.GetAt(5));
		m_Edit_BPassword.SetWindowText(ValueList.GetAt(6));

		m_ComboBox_Ma.SetCurSel(atoi(ValueList.GetAt(8)));
		OnCbnSelchangeComboMa();
		m_ComboBox_L.SetCurSel(atoi(ValueList.GetAt(9)));
		OnCbnSelchangeComboL();

		SetNAValue(ValueList.GetAt(7));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}

void SCbsi_Dlg::SetNAValue(CString sStrH)
{
	CString sStrB="",sTemp="";
	int iB0=0,iB1=0;
	sTemp.Format("%c",sStrH[0]);
	iB1=atoi(sTemp);
	m_ComboBox_N.SetCurSel(iB1);
	sTemp.Format("%c",sStrH[1]);
	iB0=atoi(sTemp);
	m_ComboBox_A.SetCurSel(iB0);

	GetValueNA();


}

void SCbsi_Dlg::OnEnChangeEditApn()
{
	// TODO:  在此添加控件通知处理程序代码
		CString sStr="",sGTBSI="",sNewGTBSI="";
		m_Edit_APN.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sGTBSI);
		sNewGTBSI=UpdataCMD(sStr,1,sGTBSI);
		m_Edit_GTCMD.SetWindowText(sNewGTBSI);
}

void SCbsi_Dlg::OnEnChangeEditUsername()
{
	CString sStr="",sGTBSI="",sNewGTBSI="";
	m_Edit_UserName.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sGTBSI);
	sNewGTBSI=UpdataCMD(sStr,2,sGTBSI);
	m_Edit_GTCMD.SetWindowText(sNewGTBSI);

}

void SCbsi_Dlg::OnEnChangeEditPassword()
{
	CString sStr="",sGTBSI="",sNewGTBSI="";
	m_Edit_Password.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sGTBSI);
	sNewGTBSI=UpdataCMD(sStr,3,sGTBSI);
	m_Edit_GTCMD.SetWindowText(sNewGTBSI);
}
//5
void SCbsi_Dlg::OnEnChangeEditbapn()
{
	CString sStr="",sGTBSI="",sNewGTBSI="";
	m_Edit_BAPN.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sGTBSI);
	sNewGTBSI=UpdataCMD(sStr,4,sGTBSI);
	m_Edit_GTCMD.SetWindowText(sNewGTBSI);
}

void SCbsi_Dlg::OnEnChangeEditBusername()
{
	CString sStr="",sGTBSI="",sNewGTBSI="";
	m_Edit_BUserName.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sGTBSI);
	sNewGTBSI=UpdataCMD(sStr,5,sGTBSI);
	m_Edit_GTCMD.SetWindowText(sNewGTBSI);
}

void SCbsi_Dlg::OnEnChangeEditBpassword()
{
	CString sStr="",sGTBSI="",sNewGTBSI="";
	m_Edit_BPassword.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sGTBSI);
	sNewGTBSI=UpdataCMD(sStr,6,sGTBSI);
	m_Edit_GTCMD.SetWindowText(sNewGTBSI);
}

//8
void SCbsi_Dlg::OnCbnSelchangeComboN()
{
	GetValueNA();
}

void SCbsi_Dlg::OnCbnSelchangeComboA()
{

	GetValueNA();
}

void SCbsi_Dlg::GetValueNA()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iN=0,iA=0;
	iN=m_ComboBox_N.GetCurSel();
	iA=m_ComboBox_A.GetCurSel();
	sStr.Format("%d%d",iN,iA);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,7,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//9
void SCbsi_Dlg::OnCbnSelchangeComboMa()
{

	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_Ma.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,8,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//10
void SCbsi_Dlg::OnCbnSelchangeComboL()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_L.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,9,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

