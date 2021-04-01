// ASbad_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ASbad_Dlg.h"
#include "afxdialogex.h"

///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern ASbad_Dlg m_ASbad_Dlg;
ASbad_Dlg*	lpASbad_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
extern ASbad_Dlg m_ASbad_Dlg;
////////////

IMPLEMENT_DYNAMIC(ASbad_Dlg, CMyTabBaseDlg)

ASbad_Dlg::ASbad_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(ASbad_Dlg::IDD, pParent)
{

}

ASbad_Dlg::~ASbad_Dlg()
{
}

void ASbad_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_OI, m_ComboBox_OI);
	DDX_Control(pDX, IDC_CHECK_OS1, m_Check_OS1);
	DDX_Control(pDX, IDC_CHECK_OS2, m_Check_OS2);
	DDX_Control(pDX, IDC_CHECK_OS3, m_Check_OS3);
	DDX_Control(pDX, IDC_CHECK_OS4, m_Check_OS4);
	DDX_Control(pDX, IDC_SPIN_D1, m_Spin_D1);
	DDX_Control(pDX, IDC_SPIN_D2, m_Spin_D2);
	DDX_Control(pDX, IDC_SPIN_D3, m_Spin_D3);
	DDX_Control(pDX, IDC_SPIN_D4, m_Spin_D4);
	DDX_Control(pDX, IDC_EDIT_D1, m_Edit_D1);
	DDX_Control(pDX, IDC_EDIT_D2, m_Edit_D2);
	DDX_Control(pDX, IDC_EDIT_D3, m_Edit_D3);
	DDX_Control(pDX, IDC_EDIT_D4, m_Edit_D4);
	DDX_Control(pDX, IDC_SPIN_TT1, m_Spin_TT1);
	DDX_Control(pDX, IDC_SPIN_TT2, m_Spin_TT2);
	DDX_Control(pDX, IDC_SPIN_TT3, m_Spin_TT3);
	DDX_Control(pDX, IDC_SPIN_TT4, m_Spin_TT4);
	DDX_Control(pDX, IDC_EDIT_TT1, m_Edit_TT1);
	DDX_Control(pDX, IDC_EDIT_TT2, m_Edit_TT2);
	DDX_Control(pDX, IDC_EDIT_TT3, m_Edit_TT3);
	DDX_Control(pDX, IDC_EDIT_TT4, m_Edit_TT4);
}


BEGIN_MESSAGE_MAP(ASbad_Dlg, CMyTabBaseDlg)
	ON_BN_CLICKED(IDC_BUTTON_Read, &ASbad_Dlg::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_Send, &ASbad_Dlg::OnBnClickedButtonSend)
	ON_EN_CHANGE(IDC_EDIT_D1, &ASbad_Dlg::OnEnChangeEditD1)
	ON_CBN_SELCHANGE(IDC_COMBO_OI, &ASbad_Dlg::OnCbnSelchangeComboOi)
	ON_BN_CLICKED(IDC_CHECK_OS1, &ASbad_Dlg::OnBnClickedCheckOs1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D1, &ASbad_Dlg::OnDeltaposSpinD1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT1, &ASbad_Dlg::OnDeltaposSpinTt1)
	ON_EN_CHANGE(IDC_EDIT_TT1, &ASbad_Dlg::OnEnChangeEditTt1)
	ON_BN_CLICKED(IDC_CHECK_OS2, &ASbad_Dlg::OnBnClickedCheckOs2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D2, &ASbad_Dlg::OnDeltaposSpinD2)
	ON_EN_CHANGE(IDC_EDIT_D2, &ASbad_Dlg::OnEnChangeEditD2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT2, &ASbad_Dlg::OnDeltaposSpinTt2)
	ON_EN_CHANGE(IDC_EDIT_TT2, &ASbad_Dlg::OnEnChangeEditTt2)
	ON_BN_CLICKED(IDC_CHECK_OS3, &ASbad_Dlg::OnBnClickedCheckOs3)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D3, &ASbad_Dlg::OnDeltaposSpinD3)
	ON_EN_CHANGE(IDC_EDIT_D3, &ASbad_Dlg::OnEnChangeEditD3)
	ON_EN_CHANGE(IDC_EDIT_TT3, &ASbad_Dlg::OnEnChangeEditTt3)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT3, &ASbad_Dlg::OnDeltaposSpinTt3)
	ON_BN_CLICKED(IDC_CHECK_OS4, &ASbad_Dlg::OnBnClickedCheckOs4)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D4, &ASbad_Dlg::OnDeltaposSpinD4)
	ON_EN_CHANGE(IDC_EDIT_D4, &ASbad_Dlg::OnEnChangeEditD4)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT4, &ASbad_Dlg::OnDeltaposSpinTt4)
	ON_EN_CHANGE(IDC_EDIT_TT4, &ASbad_Dlg::OnEnChangeEditTt4)
END_MESSAGE_MAP()


// ASbad_Dlg 消息处理程序


BOOL ASbad_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	// TODO:  在此添加额外的初始化
	lpASbad_Dlg=&m_ASbad_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_ASbad_Dlg;
	m_iWhoamI=GTBZA;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTBZA].sCmdstr);

	m_ComboBox_OI.InsertString(0,"0");
	m_ComboBox_OI.InsertString(1,"1");
	m_ComboBox_OI.InsertString(2,"2");
	m_ComboBox_OI.SetCurSel(0);
	///////////////
	SetDlgItemText(IDC_EDIT_D1,"0");
	m_Spin_D1.SetBuddy(GetDlgItem(IDC_EDIT_D1)); //得到指向编辑框的窗口指针
	m_Spin_D1.SetRange(0,255);
	SetDlgItemText(IDC_EDIT_TT1,"0");
	m_Spin_TT1.SetBuddy(GetDlgItem(IDC_EDIT_TT1)); //得到指向编辑框的窗口指针
	m_Spin_TT1.SetRange(0,255);
	/////////////////
	SetDlgItemText(IDC_EDIT_D2,"0");
	m_Spin_D2.SetBuddy(GetDlgItem(IDC_EDIT_D2)); //得到指向编辑框的窗口指针
	m_Spin_D2.SetRange(0,255);
	SetDlgItemText(IDC_EDIT_TT2,"0");
	m_Spin_TT2.SetBuddy(GetDlgItem(IDC_EDIT_TT2)); //得到指向编辑框的窗口指针
	m_Spin_TT2.SetRange(0,255);
	/////////////////
	SetDlgItemText(IDC_EDIT_D3,"0");
	m_Spin_D3.SetBuddy(GetDlgItem(IDC_EDIT_D3)); //得到指向编辑框的窗口指针
	m_Spin_D3.SetRange(0,255);
	SetDlgItemText(IDC_EDIT_TT3,"0");
	m_Spin_TT3.SetBuddy(GetDlgItem(IDC_EDIT_TT3)); //得到指向编辑框的窗口指针
	m_Spin_TT3.SetRange(0,255);
	/////////////////	///////////////
	SetDlgItemText(IDC_EDIT_D4,"0");
	m_Spin_D4.SetBuddy(GetDlgItem(IDC_EDIT_D4)); //得到指向编辑框的窗口指针
	m_Spin_D4.SetRange(0,255);
	SetDlgItemText(IDC_EDIT_TT4,"0");
	m_Spin_TT4.SetBuddy(GetDlgItem(IDC_EDIT_TT4)); //得到指向编辑框的窗口指针
	m_Spin_TT4.SetRange(0,255);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


CString ASbad_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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


void ASbad_Dlg::GetCMD()
{
	CArray<CString,CString>CmdList;
	int iTemp=0;
	CString sNewCmd="";	CString sStr="";
	CString s1="",s2="",s3="",s4="",s5="",s6="",s7="",s8="",s9="",s10="",s11="",s12="",s13="",s14="",s15="";
	CmdList.InsertAt(1,"AT+GTBZA=HYIoT");
	try
	{

		CmdList.Add("");
		CmdList.Add("");
		CmdList.Add("FFFF$");
		////////////////////////////
		for (int i=1;i<CmdList.GetSize();i++)
		{
			if (1==i)
			{
				sNewCmd=CmdList.GetAt(1);
			}
			else
			{
				sNewCmd=sNewCmd+","+CmdList.GetAt(i);
			}
		}
		m_Edit_GTCMD.SetWindowText(sNewCmd);
	}
	catch (...)
	{
		AfxMessageBox("Error Happend,Please Contact Engineer!");
		return ;
	}	
}

BOOL ASbad_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>22)
	{
		m_ComboBox_OI.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboOi();		

		m_Check_OS1.SetCheck(atoi(ValueList.GetAt(5)));
		OnBnClickedCheckOs1();	
		m_Edit_D1.SetWindowText(ValueList.GetAt(6));
		m_Edit_TT1.SetWindowText(ValueList.GetAt(7));

		m_Check_OS2.SetCheck(atoi(ValueList.GetAt(10)));
		OnBnClickedCheckOs2();	
		m_Edit_D2.SetWindowText(ValueList.GetAt(11));
		m_Edit_TT2.SetWindowText(ValueList.GetAt(12));	

		m_Check_OS3.SetCheck(atoi(ValueList.GetAt(15)));
		OnBnClickedCheckOs3();	
		m_Edit_D3.SetWindowText(ValueList.GetAt(16));
		m_Edit_TT3.SetWindowText(ValueList.GetAt(17));	

		m_Check_OS4.SetCheck(atoi(ValueList.GetAt(20)));
		OnBnClickedCheckOs4();	
		m_Edit_D4.SetWindowText(ValueList.GetAt(21));
		m_Edit_TT4.SetWindowText(ValueList.GetAt(22));
		return TRUE;
	}
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}

void ASbad_Dlg::OnCbnSelchangeComboOi()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_OI.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//6
void ASbad_Dlg::OnBnClickedCheckOs1()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_OS1.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,5,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//7
void ASbad_Dlg::OnEnChangeEditD1()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_D1.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,6,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

void ASbad_Dlg::OnDeltaposSpinD1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D1.GetPos();
	m_Spin_D1.SetPos(iTemp);
	m_Edit_D1.GetWindowText(strValue);  
	*pResult = 0;
}


void ASbad_Dlg::OnDeltaposSpinTt1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT1.GetPos();
	m_Spin_TT1.SetPos(iTemp);
	m_Edit_TT1.GetWindowText(strValue);  
	*pResult = 0;
}

//8
void ASbad_Dlg::OnEnChangeEditTt1()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TT1.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,7,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}



//11
void ASbad_Dlg::OnBnClickedCheckOs2()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_OS2.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,10,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//12
void ASbad_Dlg::OnEnChangeEditD2()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_D2.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,11,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

void ASbad_Dlg::OnDeltaposSpinD2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D2.GetPos();
	m_Spin_D2.SetPos(iTemp);
	m_Edit_D2.GetWindowText(strValue);  
	*pResult = 0;
}

//13
void ASbad_Dlg::OnDeltaposSpinTt2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT2.GetPos();
	m_Spin_TT2.SetPos(iTemp);
	m_Edit_TT2.GetWindowText(strValue);  
	*pResult = 0;
}

//13
void ASbad_Dlg::OnEnChangeEditTt2()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TT2.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,12,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


//16
void ASbad_Dlg::OnBnClickedCheckOs3()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_OS3.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,15,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//17
void ASbad_Dlg::OnEnChangeEditD3()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_D3.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,16,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

void ASbad_Dlg::OnDeltaposSpinD3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D3.GetPos();
	m_Spin_D3.SetPos(iTemp);
	m_Edit_D3.GetWindowText(strValue);  
	*pResult = 0;
}


void ASbad_Dlg::OnDeltaposSpinTt3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT3.GetPos();
	m_Spin_TT3.SetPos(iTemp);
	m_Edit_TT3.GetWindowText(strValue);  
	*pResult = 0;
}

//18
void ASbad_Dlg::OnEnChangeEditTt3()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TT3.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,17,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


//21
void ASbad_Dlg::OnBnClickedCheckOs4()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_OS4.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,20,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}
//22
void ASbad_Dlg::OnEnChangeEditD4()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_D4.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,21,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

void ASbad_Dlg::OnDeltaposSpinD4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D4.GetPos();
	m_Spin_D4.SetPos(iTemp);
	m_Edit_D4.GetWindowText(strValue);  
	*pResult = 0;
}


void ASbad_Dlg::OnDeltaposSpinTt4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT4.GetPos();
	m_Spin_TT4.SetPos(iTemp);
	m_Edit_TT4.GetWindowText(strValue);  
	*pResult = 0;
}

//23
void ASbad_Dlg::OnEnChangeEditTt4()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TT4.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,22,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}
