// AScd_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "AScd_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern AScd_Dlg m_AScd_Dlg;
AScd_Dlg*	lpAScd_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
extern CMYWORK	m_MYWORK;
extern AScd_Dlg m_AScd_Dlg;
////////////

IMPLEMENT_DYNAMIC(AScd_Dlg, CMyTabBaseDlg)

AScd_Dlg::AScd_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(AScd_Dlg::IDD, pParent)
{

}

AScd_Dlg::~AScd_Dlg()
{
}

void AScd_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_COMBO_GS, m_ComboBox_GS);
	DDX_Control(pDX, IDC_SPIN_S, m_Spin_S);
	DDX_Control(pDX, IDC_SPIN_GB, m_Spin_GB);
	DDX_Control(pDX, IDC_SPIN_GA, m_Spin_GA);
	DDX_Control(pDX, IDC_SPIN_GB2, m_Spin_GB2);
	DDX_Control(pDX, IDC_SPIN_GA2, m_Spin_GA2);
	DDX_Control(pDX, IDC_EDIT_S, m_Edit_S);
	DDX_Control(pDX, IDC_EDIT_GB, m_Edit_GB);
	DDX_Control(pDX, IDC_EDIT_GA, m_Edit_GA);
	DDX_Control(pDX, IDC_EDIT_GB2, m_Edit_GB2);
	DDX_Control(pDX, IDC_EDIT_GA2, m_Edit_GA2);
	DDX_Control(pDX, IDC_COMBO_OI, m_ComboBox_OI);
	DDX_Control(pDX, IDC_CHECK_OutS, m_Check_OutS);
	DDX_Control(pDX, IDC_SPIN_D, m_Spin_D);
	DDX_Control(pDX, IDC_SPIN_TT, m_Spin_TT);
	DDX_Control(pDX, IDC_EDIT_D, m_Edit_D);
	DDX_Control(pDX, IDC_EDIT_TT, m_Edit_TT);
}


BEGIN_MESSAGE_MAP(AScd_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &AScd_Dlg::OnCbnSelchangeComboM)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_S, &AScd_Dlg::OnDeltaposSpinS)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_GB, &AScd_Dlg::OnDeltaposSpinGb)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_GA, &AScd_Dlg::OnDeltaposSpinGa)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_GB2, &AScd_Dlg::OnDeltaposSpinGb2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_GA2, &AScd_Dlg::OnDeltaposSpinGa2)
	ON_CBN_SELCHANGE(IDC_COMBO_GS, &AScd_Dlg::OnCbnSelchangeComboGs)
	ON_EN_CHANGE(IDC_EDIT_S, &AScd_Dlg::OnEnChangeEditS)
	ON_EN_CHANGE(IDC_EDIT_GB, &AScd_Dlg::OnEnChangeEditGb)
	ON_EN_CHANGE(IDC_EDIT_GA, &AScd_Dlg::OnEnChangeEditGa)
	ON_EN_CHANGE(IDC_EDIT_GB2, &AScd_Dlg::OnEnChangeEditGb2)
	ON_EN_CHANGE(IDC_EDIT_GA2, &AScd_Dlg::OnEnChangeEditGa2)
	ON_CBN_SELCHANGE(IDC_COMBO_OI, &AScd_Dlg::OnCbnSelchangeComboOi)
	ON_BN_CLICKED(IDC_CHECK_OutS, &AScd_Dlg::OnBnClickedCheckOuts)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D, &AScd_Dlg::OnDeltaposSpinD)
	ON_EN_CHANGE(IDC_EDIT_D, &AScd_Dlg::OnEnChangeEditD)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT, &AScd_Dlg::OnDeltaposSpinTt)
	ON_EN_CHANGE(IDC_EDIT_TT, &AScd_Dlg::OnEnChangeEditTt)
END_MESSAGE_MAP()


// AScd_Dlg 消息处理程序


BOOL AScd_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpAScd_Dlg=&m_AScd_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_AScd_Dlg;
	m_iWhoamI=GTCRA;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTCRA].sCmdstr);
	                                      //HYIoT,0,7,3,3,3,0,,10,10,,1,0,0,0,,FFFF$
	                                      //HYIoT,0,7,3,3,3,0,,10,10,,0,0,0,0,,FFFF$
	m_ComboBox_M.InsertString(0,"0: Disable this function");
	m_ComboBox_M.InsertString(1,"1: Enable this function");
	m_ComboBox_M.SetCurSel(0);

	m_ComboBox_GS.InsertString(0,"0: 100Hz");
	m_ComboBox_GS.InsertString(1,"1: 200Hz");
	m_ComboBox_GS.SetCurSel(0);

	SetDlgItemText(IDC_EDIT_S,"7");
	m_Spin_S.SetBuddy(GetDlgItem(IDC_EDIT_S)); //得到指向编辑框的窗口指针
	m_Spin_S.SetRange(1,99);
	SetDlgItemText(IDC_EDIT_GB,"3");
	m_Spin_GB.SetBuddy(GetDlgItem(IDC_EDIT_GB)); //得到指向编辑框的窗口指针
	m_Spin_GB.SetRange(1,5);
	SetDlgItemText(IDC_EDIT_GA,"3");
	m_Spin_GA.SetBuddy(GetDlgItem(IDC_EDIT_GA)); //得到指向编辑框的窗口指针
	m_Spin_GA.SetRange(1,5);
	SetDlgItemText(IDC_EDIT_GB2,"10");
	m_Spin_GB2.SetBuddy(GetDlgItem(IDC_EDIT_GB2)); //得到指向编辑框的窗口指针
	m_Spin_GB2.SetRange(0,10);
	SetDlgItemText(IDC_EDIT_GA2,"10");
	m_Spin_GA2.SetBuddy(GetDlgItem(IDC_EDIT_GA2)); //得到指向编辑框的窗口指针
	m_Spin_GA2.SetRange(0,10);
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

CString AScd_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL AScd_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>13)
	{
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboM();	

		m_Edit_S.SetWindowText(ValueList.GetAt(2));
		m_Edit_GB.SetWindowText(ValueList.GetAt(3));
		m_Edit_GA.SetWindowText(ValueList.GetAt(4));
		m_Edit_GB2.SetWindowText(ValueList.GetAt(7));
		m_Edit_GA2.SetWindowText(ValueList.GetAt(8));

		m_ComboBox_GS.SetCurSel(atoi(ValueList.GetAt(5)));
		OnCbnSelchangeComboGs();	

		m_ComboBox_OI.SetCurSel(atoi(ValueList.GetAt(10)));
		OnCbnSelchangeComboOi();
		m_Check_OutS.SetCheck(atoi(ValueList.GetAt(11)));
		OnBnClickedCheckOuts();
		m_Edit_D.SetWindowText(ValueList.GetAt(12));
		m_Edit_TT.SetWindowText(ValueList.GetAt(13));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}

//2
void AScd_Dlg::OnCbnSelchangeComboM()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_M.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}
//3
void AScd_Dlg::OnEnChangeEditS()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_S.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,2,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//4
void AScd_Dlg::OnEnChangeEditGb()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_GB.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,3,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//5
void AScd_Dlg::OnEnChangeEditGa()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_GA.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,4,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//6
void AScd_Dlg::OnCbnSelchangeComboGs()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_GS.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,5,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void AScd_Dlg::OnDeltaposSpinS(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_S.GetPos();
	m_Spin_S.SetPos(iTemp);
	m_Edit_S.GetWindowText(strValue);  
	*pResult = 0;
}


void AScd_Dlg::OnDeltaposSpinGb(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_GB.GetPos();
	m_Spin_GB.SetPos(iTemp);
	m_Edit_GB.GetWindowText(strValue);  
	*pResult = 0;
}


void AScd_Dlg::OnDeltaposSpinGa(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_GA.GetPos();
	m_Spin_GA.SetPos(iTemp);
	m_Edit_GA.GetWindowText(strValue);  
	*pResult = 0;
}


void AScd_Dlg::OnDeltaposSpinGb2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_GB2.GetPos();
	m_Spin_GB2.SetPos(iTemp);
	m_Edit_GB2.GetWindowText(strValue);  
	*pResult = 0;
}


void AScd_Dlg::OnDeltaposSpinGa2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_GA2.GetPos();
	m_Spin_GA2.SetPos(iTemp);
	m_Edit_GA2.GetWindowText(strValue);  
	*pResult = 0;
}


//8
void AScd_Dlg::OnEnChangeEditGb2()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_GB2.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,7,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//9
void AScd_Dlg::OnEnChangeEditGa2()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_GA2.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,8,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//11
void AScd_Dlg::OnCbnSelchangeComboOi()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_OI.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,10,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//12
void AScd_Dlg::OnBnClickedCheckOuts()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_OutS.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,11,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void AScd_Dlg::OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D.GetPos();
	m_Spin_D.SetPos(iTemp);
	m_Edit_D.GetWindowText(strValue);  
	*pResult = 0;
}

//13
void AScd_Dlg::OnEnChangeEditD()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_D.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,12,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void AScd_Dlg::OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT.GetPos();
	m_Spin_TT.SetPos(iTemp);
	m_Edit_TT.GetWindowText(strValue);  
	*pResult = 0;
}

//14
void AScd_Dlg::OnEnChangeEditTt()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TT.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,13,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


