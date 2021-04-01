// ASser_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ASser_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern ASser_Dlg m_ASser_Dlg;
ASser_Dlg*	lpASser_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(ASser_Dlg, CMyTabBaseDlg)

ASser_Dlg::ASser_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(ASser_Dlg::IDD, pParent)
{

}

ASser_Dlg::~ASser_Dlg()
{
}

void ASser_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_SPIN_T1, m_Spin_T1);
	DDX_Control(pDX, IDC_SPIN_T2, m_Spin_T2);
	DDX_Control(pDX, IDC_SPIN_T3, m_Spin_T3);
	DDX_Control(pDX, IDC_EDIT_T1, m_Edit_T1);
	DDX_Control(pDX, IDC_EDIT_T2, m_Edit_T2);
	DDX_Control(pDX, IDC_EDIT_T3, m_Edit_T3);
}


BEGIN_MESSAGE_MAP(ASser_Dlg, CMyTabBaseDlg)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_T1, &ASser_Dlg::OnDeltaposSpinT1)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &ASser_Dlg::OnCbnSelchangeComboM)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_T2, &ASser_Dlg::OnDeltaposSpinT2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_T3, &ASser_Dlg::OnDeltaposSpinT3)
	ON_EN_CHANGE(IDC_EDIT_T1, &ASser_Dlg::OnEnChangeEditT1)
	ON_EN_CHANGE(IDC_EDIT_T2, &ASser_Dlg::OnEnChangeEditT2)
	ON_EN_CHANGE(IDC_EDIT_T3, &ASser_Dlg::OnEnChangeEditT3)
END_MESSAGE_MAP()


// ASser_Dlg 消息处理程序


BOOL ASser_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpASser_Dlg=&m_ASser_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_ASser_Dlg;
	m_iWhoamI=GTSTP;
	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTSTP].sCmdstr);

	m_ComboBox_M.InsertString(0,"0: Disable this function");
	m_ComboBox_M.InsertString(1,"1: Enable this function");
	m_ComboBox_M.SetCurSel(0);
	///////////////
	SetDlgItemText(IDC_EDIT_T1,"0");
	m_Spin_T1.SetBuddy(GetDlgItem(IDC_EDIT_T1)); //得到指向编辑框的窗口指针
	m_Spin_T1.SetRange(10,240);
	/////////////////
	SetDlgItemText(IDC_EDIT_T2,"0");
	m_Spin_T2.SetBuddy(GetDlgItem(IDC_EDIT_T2)); //得到指向编辑框的窗口指针
	m_Spin_T2.SetRange(240,1440);
	/////////////////
	SetDlgItemText(IDC_EDIT_T3,"0");
	m_Spin_T3.SetBuddy(GetDlgItem(IDC_EDIT_T3)); //得到指向编辑框的窗口指针
	m_Spin_T3.SetRange(1,30);
	/////////////////
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString ASser_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL ASser_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>4)
	{
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboM();	
		m_Edit_T1.SetWindowText(ValueList.GetAt(2));
		m_Edit_T2.SetWindowText(ValueList.GetAt(3));
		m_Edit_T3.SetWindowText(ValueList.GetAt(4));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}

}


void ASser_Dlg::OnCbnSelchangeComboM()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_M.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void ASser_Dlg::OnDeltaposSpinT1(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_T1.GetPos();
	m_Spin_T1.SetPos(iTemp);
	m_Edit_T1.GetWindowText(strValue);  
	*pResult = 0;
}

void ASser_Dlg::OnDeltaposSpinT2(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_T2.GetPos();
	m_Spin_T2.SetPos(iTemp);
	m_Edit_T2.GetWindowText(strValue);  
	*pResult = 0;
}


void ASser_Dlg::OnDeltaposSpinT3(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_T3.GetPos();
	m_Spin_T3.SetPos(iTemp);
	m_Edit_T3.GetWindowText(strValue);  
	*pResult = 0;
}

//3
void ASser_Dlg::OnEnChangeEditT1()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_T1.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{      
		for( int i=0;i < sStr.GetLength(); i++)
		{
			if(sStr.GetAt(i)>='0' &&  sStr.GetAt(i)<='9')
			{
				strDigit += sStr.GetAt(i);
			}
		}
	}
	else
	{
		strDigit=sStr;
	}
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(strDigit,2,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//4
void ASser_Dlg::OnEnChangeEditT2()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_T2.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{      
		for( int i=0;i < sStr.GetLength(); i++)
		{
			if(sStr.GetAt(i)>='0' &&  sStr.GetAt(i)<='9')
			{
				strDigit += sStr.GetAt(i);
			}
		}
	}
	else
	{
		strDigit=sStr;
	}
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(strDigit,3,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//5
void ASser_Dlg::OnEnChangeEditT3()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_T3.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{      
		for( int i=0;i < sStr.GetLength(); i++)
		{
			if(sStr.GetAt(i)>='0' &&  sStr.GetAt(i)<='9')
			{
				strDigit += sStr.GetAt(i);
			}
		}
	}
	else
	{
		strDigit=sStr;
	}
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(strDigit,4,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}
