// ASsadr_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ASsadr_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern ASsadr_Dlg m_ASsadr_Dlg;
ASsadr_Dlg*	lpASsadr_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(ASsadr_Dlg, CMyTabBaseDlg)

ASsadr_Dlg::ASsadr_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(ASsadr_Dlg::IDD, pParent)
{

}

ASsadr_Dlg::~ASsadr_Dlg()
{
}

void ASsadr_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_COMBO_DRM, m_ComboBox_DRM);
	DDX_Control(pDX, IDC_SPIN_DRI, m_Spin_DRI);
	DDX_Control(pDX, IDC_SPIN_DRD, m_Spin_DRD);
	DDX_Control(pDX, IDC_SPIN_DRM, m_Spin_DRM);
	DDX_Control(pDX, IDC_SPIN_MN, m_Spin_MN);
	DDX_Control(pDX, IDC_EDIT_DRI, m_Edit_DRI);
	DDX_Control(pDX, IDC_EDIT_DRD, m_Edit_DRD);
	DDX_Control(pDX, IDC_EDIT_DRM, m_Edit_DRM);
	DDX_Control(pDX, IDC_EDIT_MN, m_Edit_MN);
}


BEGIN_MESSAGE_MAP(ASsadr_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &ASsadr_Dlg::OnCbnSelchangeComboM)
	ON_CBN_SELCHANGE(IDC_COMBO_DRM, &ASsadr_Dlg::OnCbnSelchangeComboDrm)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_DRI, &ASsadr_Dlg::OnDeltaposSpinDri)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_DRD, &ASsadr_Dlg::OnDeltaposSpinDrd)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_DRM, &ASsadr_Dlg::OnDeltaposSpinDrm)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MN, &ASsadr_Dlg::OnDeltaposSpinMn)
	ON_EN_CHANGE(IDC_EDIT_DRI, &ASsadr_Dlg::OnEnChangeEditDri)
	ON_EN_CHANGE(IDC_EDIT_DRD, &ASsadr_Dlg::OnEnChangeEditDrd)
	ON_EN_CHANGE(IDC_EDIT_DRM, &ASsadr_Dlg::OnEnChangeEditDrm)
	ON_EN_CHANGE(IDC_EDIT_MN, &ASsadr_Dlg::OnEnChangeEditMn)
END_MESSAGE_MAP()


// ASsadr_Dlg 消息处理程序


BOOL ASsadr_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpASsadr_Dlg=&m_ASsadr_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_ASsadr_Dlg;
	m_iWhoamI=GTSDS;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTSDS].sCmdstr);

	m_ComboBox_M.InsertString(0,"0: Disable the start report");
	m_ComboBox_M.InsertString(1,"1: Enable the start report");
	m_ComboBox_M.InsertString(2,"2: Enable the Start report regardless of Start event");
	m_ComboBox_M.SetCurSel(0);
	///////////////
	m_ComboBox_DRM.InsertString(0,"0: Disable the drive report");
	m_ComboBox_DRM.InsertString(1,"1: Fixed Time Drive Report");
	m_ComboBox_DRM.InsertString(2,"2: Fixed Distance Drive Report");
	m_ComboBox_DRM.InsertString(3,"3: Fixed Mileage Drive Report");
	m_ComboBox_DRM.SetCurSel(0);
	///////////////
	SetDlgItemText(IDC_EDIT_DRI,"0");
	m_Spin_DRI.SetBuddy(GetDlgItem(IDC_EDIT_DRI)); //得到指向编辑框的窗口指针
	m_Spin_DRI.SetRange32(5,86400);
	/////////////////
	SetDlgItemText(IDC_EDIT_DRD,"0");
	m_Spin_DRD.SetBuddy(GetDlgItem(IDC_EDIT_DRD)); //得到指向编辑框的窗口指针
	m_Spin_DRD.SetRange32(50,65535);
	/////////////////
	SetDlgItemText(IDC_EDIT_DRM,"0");
	m_Spin_DRM.SetBuddy(GetDlgItem(IDC_EDIT_DRM)); //得到指向编辑框的窗口指针
	m_Spin_DRM.SetRange32(50,65535);
	/////////////////
	SetDlgItemText(IDC_EDIT_MN,"0");
	m_Spin_MN.SetBuddy(GetDlgItem(IDC_EDIT_MN)); //得到指向编辑框的窗口指针
	m_Spin_MN.SetRange(5,9999);
	///////////////////////////////////////////
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString ASsadr_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL ASsadr_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>6)
	{
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboM();	
		m_ComboBox_DRM.SetCurSel(atoi(ValueList.GetAt(2)));
		OnCbnSelchangeComboDrm();		


		m_Edit_DRI.SetWindowText(ValueList.GetAt(3));
		m_Edit_DRD.SetWindowText(ValueList.GetAt(4));
		m_Edit_DRM.SetWindowText(ValueList.GetAt(5));

		m_Edit_MN.SetWindowText(ValueList.GetAt(6));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}

}

void ASsadr_Dlg::OnCbnSelchangeComboM()
{

	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_M.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void ASsadr_Dlg::OnCbnSelchangeComboDrm()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_DRM.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,2,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void ASsadr_Dlg::OnDeltaposSpinDri(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_DRI.GetPos();
	m_Spin_DRI.SetPos(iTemp);
	m_Edit_DRI.GetWindowText(strValue);  
	*pResult = 0;
}


void ASsadr_Dlg::OnDeltaposSpinDrd(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_DRD.GetPos();
	m_Spin_DRD.SetPos(iTemp);
	m_Edit_DRD.GetWindowText(strValue);  
	*pResult = 0;
}


void ASsadr_Dlg::OnDeltaposSpinDrm(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_DRM.GetPos();
	m_Spin_DRM.SetPos(iTemp);
	m_Edit_DRM.GetWindowText(strValue);  
	*pResult = 0;
}


void ASsadr_Dlg::OnDeltaposSpinMn(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_MN.GetPos();
	m_Spin_MN.SetPos(iTemp);
	m_Edit_MN.GetWindowText(strValue);  
	*pResult = 0;
}

//4
void ASsadr_Dlg::OnEnChangeEditDri()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_DRI.GetWindowText(sStr);
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
void ASsadr_Dlg::OnEnChangeEditDrd()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_DRD.GetWindowText(sStr);
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

//6
void ASsadr_Dlg::OnEnChangeEditDrm()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_DRM.GetWindowText(sStr);
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
	sNewCmd=m_MYWORK.UpdataCMD(strDigit,5,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//7
void ASsadr_Dlg::OnEnChangeEditMn()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_MN.GetWindowText(sStr);
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
	sNewCmd=m_MYWORK.UpdataCMD(strDigit,6,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


