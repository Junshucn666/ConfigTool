// AShbm_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "AShbm_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern AShbm_Dlg m_AShbm_Dlg;
AShbm_Dlg*	lpAShbm_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
extern AShbm_Dlg m_AShbm_Dlg;
////////////

IMPLEMENT_DYNAMIC(AShbm_Dlg, CMyTabBaseDlg)

AShbm_Dlg::AShbm_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(AShbm_Dlg::IDD, pParent)
{

}

AShbm_Dlg::~AShbm_Dlg()
{
}

void AShbm_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_SPIN_AT1, m_Spin_AT1);
	DDX_Control(pDX, IDC_EDIT_AT1, m_Edit_AT1);
	DDX_Control(pDX, IDC_EDIT_AT2, m_Edit_AT2);
	DDX_Control(pDX, IDC_EDIT_AT3, m_Edit_AT3);
	DDX_Control(pDX, IDC_EDIT_AT4, m_Edit_AT4);
	DDX_Control(pDX, IDC_SPIN_AT2, m_Spin_AT2);
	DDX_Control(pDX, IDC_SPIN_AT3, m_Spin_AT3);
	DDX_Control(pDX, IDC_SPIN_AT4, m_Spin_AT4);
	DDX_Control(pDX, IDC_SPIN_BT1, m_Spin_BT1);
	DDX_Control(pDX, IDC_SPIN_BT2, m_Spin_BT2);
	DDX_Control(pDX, IDC_SPIN_BT3, m_Spin_BT3);
	DDX_Control(pDX, IDC_SPIN_BT4, m_Spin_BT4);
	DDX_Control(pDX, IDC_EDIT_BT1, m_Edit_BT1);
	DDX_Control(pDX, IDC_EDIT_BT2, m_Edit_BT2);
	DDX_Control(pDX, IDC_EDIT_BT3, m_Edit_BT3);
	DDX_Control(pDX, IDC_EDIT_BT4, m_Edit_BT4);
	DDX_Control(pDX, IDC_SPIN_HBD, m_Spin_HBD);
	DDX_Control(pDX, IDC_SPIN_HAD, m_Spin_HAD);
	DDX_Control(pDX, IDC_EDIT_HBD, m_Edit_HBD);
	DDX_Control(pDX, IDC_EDIT_HAD, m_Edit_HAD);
	DDX_Control(pDX, IDC_SPIN_D, m_Spin_D);
	DDX_Control(pDX, IDC_SPIN_TT, m_Spin_TT);
	DDX_Control(pDX, IDC_EDIT_TT, m_Edit_TT);
	DDX_Control(pDX, IDC_EDIT_D, m_Edit_D);
	DDX_Control(pDX, IDC_CHECK_OutS, m_Check_OutS);
	DDX_Control(pDX, IDC_COMBO_OI, m_ComboBox_OI);
}


BEGIN_MESSAGE_MAP(AShbm_Dlg, CMyTabBaseDlg)
	ON_BN_CLICKED(IDC_BUTTON_Read, &AShbm_Dlg::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_Send, &AShbm_Dlg::OnBnClickedButtonSend)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &AShbm_Dlg::OnCbnSelchangeComboM)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_AT1, &AShbm_Dlg::OnDeltaposSpinAt1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_AT2, &AShbm_Dlg::OnDeltaposSpinAt2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_AT3, &AShbm_Dlg::OnDeltaposSpinAt3)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_AT4, &AShbm_Dlg::OnDeltaposSpinAt4)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_BT1, &AShbm_Dlg::OnDeltaposSpinBt1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_BT2, &AShbm_Dlg::OnDeltaposSpinBt2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_BT3, &AShbm_Dlg::OnDeltaposSpinBt3)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_BT4, &AShbm_Dlg::OnDeltaposSpinBt4)
	ON_EN_CHANGE(IDC_EDIT_AT1, &AShbm_Dlg::OnEnChangeEditAt1)
	ON_EN_CHANGE(IDC_EDIT_AT2, &AShbm_Dlg::OnEnChangeEditAt2)
	ON_EN_CHANGE(IDC_EDIT_AT3, &AShbm_Dlg::OnEnChangeEditAt3)
	ON_EN_CHANGE(IDC_EDIT_AT4, &AShbm_Dlg::OnEnChangeEditAt4)
	ON_EN_CHANGE(IDC_EDIT_BT1, &AShbm_Dlg::OnEnChangeEditBt1)
	ON_EN_CHANGE(IDC_EDIT_BT2, &AShbm_Dlg::OnEnChangeEditBt2)
	ON_EN_CHANGE(IDC_EDIT_BT3, &AShbm_Dlg::OnEnChangeEditBt3)
	ON_EN_CHANGE(IDC_EDIT_BT4, &AShbm_Dlg::OnEnChangeEditBt4)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_HAD, &AShbm_Dlg::OnDeltaposSpinHad)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_HBD, &AShbm_Dlg::OnDeltaposSpinHbd)
	ON_EN_CHANGE(IDC_EDIT_HAD, &AShbm_Dlg::OnEnChangeEditHad)
	ON_EN_CHANGE(IDC_EDIT_HBD, &AShbm_Dlg::OnEnChangeEditHbd)
	ON_CBN_SELCHANGE(IDC_COMBO_OI, &AShbm_Dlg::OnCbnSelchangeComboOi)
	ON_BN_CLICKED(IDC_CHECK_OutS, &AShbm_Dlg::OnBnClickedCheckOuts)
	ON_EN_CHANGE(IDC_EDIT_D, &AShbm_Dlg::OnEnChangeEditD)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D, &AShbm_Dlg::OnDeltaposSpinD)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT, &AShbm_Dlg::OnDeltaposSpinTt)
	ON_EN_CHANGE(IDC_EDIT_TT, &AShbm_Dlg::OnEnChangeEditTt)
END_MESSAGE_MAP()


// AShbm_Dlg 消息处理程序


BOOL AShbm_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpAShbm_Dlg=&m_AShbm_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_AShbm_Dlg;
	m_iWhoamI=GTHBM;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTHBM].sCmdstr);

	m_ComboBox_M.InsertString(0,"0: Disable this function");
	m_ComboBox_M.InsertString(1,"1: Enable this function");
	m_ComboBox_M.SetCurSel(0);
	///////////////
	SetDlgItemText(IDC_EDIT_AT1,"150");
	m_Spin_AT1.SetBuddy(GetDlgItem(IDC_EDIT_AT1)); //得到指向编辑框的窗口指针
	m_Spin_AT1.SetRange(10,999);
	/////////////////
	SetDlgItemText(IDC_EDIT_AT2,"200");
	m_Spin_AT2.SetBuddy(GetDlgItem(IDC_EDIT_AT2)); //得到指向编辑框的窗口指针
	m_Spin_AT2.SetRange(10,999);
	/////////////////
	SetDlgItemText(IDC_EDIT_AT3,"250");
	m_Spin_AT3.SetBuddy(GetDlgItem(IDC_EDIT_AT3)); //得到指向编辑框的窗口指针
	m_Spin_AT3.SetRange(10,999);
	/////////////////
	SetDlgItemText(IDC_EDIT_AT4,"300");
	m_Spin_AT4.SetBuddy(GetDlgItem(IDC_EDIT_AT4)); //得到指向编辑框的窗口指针
	m_Spin_AT4.SetRange(10,999);
	/////////////////
	///////////////
	SetDlgItemText(IDC_EDIT_BT1,"150");
	m_Spin_BT1.SetBuddy(GetDlgItem(IDC_EDIT_BT1)); //得到指向编辑框的窗口指针
	m_Spin_BT1.SetRange(10,999);
	/////////////////
	SetDlgItemText(IDC_EDIT_BT2,"200");
	m_Spin_BT2.SetBuddy(GetDlgItem(IDC_EDIT_BT2)); //得到指向编辑框的窗口指针
	m_Spin_BT2.SetRange(10,999);
	/////////////////
	SetDlgItemText(IDC_EDIT_BT3,"250");
	m_Spin_BT3.SetBuddy(GetDlgItem(IDC_EDIT_BT3)); //得到指向编辑框的窗口指针
	m_Spin_BT3.SetRange(10,999);
	/////////////////
	SetDlgItemText(IDC_EDIT_BT4,"300");
	m_Spin_BT4.SetBuddy(GetDlgItem(IDC_EDIT_BT4)); //得到指向编辑框的窗口指针
	m_Spin_BT4.SetRange(10,999);
	/////////////////
	SetDlgItemText(IDC_EDIT_HAD,"50");
	m_Spin_HAD.SetBuddy(GetDlgItem(IDC_EDIT_HAD)); //得到指向编辑框的窗口指针
	m_Spin_HAD.SetRange(10,50);
	/////////////////
	SetDlgItemText(IDC_EDIT_HBD,"50");
	m_Spin_HBD.SetBuddy(GetDlgItem(IDC_EDIT_HBD)); //得到指向编辑框的窗口指针
	m_Spin_HBD.SetRange(10,50);
	/////////////////
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

CString AShbm_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL AShbm_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>19)
	{
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboM();	
		m_Edit_AT1.SetWindowText(ValueList.GetAt(2));
		m_Edit_AT2.SetWindowText(ValueList.GetAt(3));	
		m_Edit_AT3.SetWindowText(ValueList.GetAt(4));
		m_Edit_AT4.SetWindowText(ValueList.GetAt(5));
		m_Edit_BT1.SetWindowText(ValueList.GetAt(7));
		m_Edit_BT2.SetWindowText(ValueList.GetAt(8));	
		m_Edit_BT3.SetWindowText(ValueList.GetAt(9));
		m_Edit_BT4.SetWindowText(ValueList.GetAt(10));	
		m_Edit_HAD.SetWindowText(ValueList.GetAt(6));
		m_Edit_HBD.SetWindowText(ValueList.GetAt(11));	

		m_ComboBox_OI.SetCurSel(atoi(ValueList.GetAt(16)));
		OnCbnSelchangeComboOi();
		m_Check_OutS.SetCheck(atoi(ValueList.GetAt(17)));
		OnBnClickedCheckOuts();
		m_Edit_D.SetWindowText(ValueList.GetAt(18));
		m_Edit_TT.SetWindowText(ValueList.GetAt(19));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}

void AShbm_Dlg::OnCbnSelchangeComboM()
{

	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_M.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void AShbm_Dlg::OnDeltaposSpinAt1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_AT1.GetPos();
	m_Spin_AT1.SetPos(iTemp);
	m_Edit_AT1.GetWindowText(strValue);  
	*pResult = 0;
}


void AShbm_Dlg::OnDeltaposSpinAt2(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_AT2.GetPos();
	m_Spin_AT2.SetPos(iTemp);
	m_Edit_AT2.GetWindowText(strValue);  
	*pResult = 0;
}


void AShbm_Dlg::OnDeltaposSpinAt3(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_AT3.GetPos();
	m_Spin_AT3.SetPos(iTemp);
	m_Edit_AT3.GetWindowText(strValue);  
	*pResult = 0;
}


void AShbm_Dlg::OnDeltaposSpinAt4(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_AT4.GetPos();
	m_Spin_AT4.SetPos(iTemp);
	m_Edit_AT4.GetWindowText(strValue);  
	*pResult = 0;
}


void AShbm_Dlg::OnDeltaposSpinBt1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_BT1.GetPos();
	m_Spin_BT1.SetPos(iTemp);
	m_Edit_BT1.GetWindowText(strValue);  
	*pResult = 0;
}


void AShbm_Dlg::OnDeltaposSpinBt2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_BT2.GetPos();
	m_Spin_BT2.SetPos(iTemp);
	m_Edit_BT2.GetWindowText(strValue);  
	*pResult = 0;
}


void AShbm_Dlg::OnDeltaposSpinBt3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_BT3.GetPos();
	m_Spin_BT3.SetPos(iTemp);
	m_Edit_BT3.GetWindowText(strValue);  
	*pResult = 0;
}


void AShbm_Dlg::OnDeltaposSpinBt4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_BT4.GetPos();
	m_Spin_BT4.SetPos(iTemp);
	m_Edit_BT4.GetWindowText(strValue);  
	*pResult = 0;
}

//3
void AShbm_Dlg::OnEnChangeEditAt1()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_AT1.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,2,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//4
void AShbm_Dlg::OnEnChangeEditAt2()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_AT2.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,3,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//5
void AShbm_Dlg::OnEnChangeEditAt3()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_AT3.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,4,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//6
void AShbm_Dlg::OnEnChangeEditAt4()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_AT4.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,5,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//8
void AShbm_Dlg::OnEnChangeEditBt1()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_BT1.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,7,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void AShbm_Dlg::OnEnChangeEditBt2()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_BT2.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,8,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void AShbm_Dlg::OnEnChangeEditBt3()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_BT3.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,9,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//11
void AShbm_Dlg::OnEnChangeEditBt4()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_BT4.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,10,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void AShbm_Dlg::OnDeltaposSpinHad(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_HAD.GetPos();
	m_Spin_HAD.SetPos(iTemp);
	m_Edit_HAD.GetWindowText(strValue);  
	*pResult = 0;
}


void AShbm_Dlg::OnDeltaposSpinHbd(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_HBD.GetPos();
	m_Spin_HBD.SetPos(iTemp);
	m_Edit_HBD.GetWindowText(strValue);  
	*pResult = 0;
}

//7
void AShbm_Dlg::OnEnChangeEditHad()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_HAD.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,6,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//12
void AShbm_Dlg::OnEnChangeEditHbd()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_HBD.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,11,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//17
void AShbm_Dlg::OnCbnSelchangeComboOi()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_OI.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,16,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//18
void AShbm_Dlg::OnBnClickedCheckOuts()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_OutS.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,17,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void AShbm_Dlg::OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D.GetPos();
	m_Spin_D.SetPos(iTemp);
	m_Edit_D.GetWindowText(strValue);  
	*pResult = 0;
}

//19
void AShbm_Dlg::OnEnChangeEditD()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_D.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,18,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//
void AShbm_Dlg::OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT.GetPos();
	m_Spin_TT.SetPos(iTemp);
	m_Edit_TT.GetWindowText(strValue);  
	*pResult = 0;
}

//20
void AShbm_Dlg::OnEnChangeEditTt()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TT.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,19,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


