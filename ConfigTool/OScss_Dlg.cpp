// OScss_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "OScss_Dlg.h"
#include "afxdialogex.h"

///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern OScss_Dlg m_OScss_Dlg;
OScss_Dlg*	lpOScss_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(OScss_Dlg, CMyTabBaseDlg)

OScss_Dlg::OScss_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(OScss_Dlg::IDD, pParent)
{

}

OScss_Dlg::~OScss_Dlg()
{
}

void OScss_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_Mode, m_ComboBox_M);
	DDX_Control(pDX, IDC_COMBO_SI, m_ComboBox_SI);
	DDX_Control(pDX, IDC_EDIT_C, m_Edit_C);
}


BEGIN_MESSAGE_MAP(OScss_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_Mode, &OScss_Dlg::OnCbnSelchangeComboMode)
	ON_CBN_SELCHANGE(IDC_COMBO_SI, &OScss_Dlg::OnCbnSelchangeComboSi)
	ON_EN_CHANGE(IDC_EDIT_C, &OScss_Dlg::OnEnChangeEditC)
	ON_EN_CHANGE(IDC_EDIT_GTCMD, &OScss_Dlg::OnEnChangeEditGtcmd)
END_MESSAGE_MAP()


// OScss_Dlg 消息处理程序


BOOL OScss_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpOScss_Dlg=&m_OScss_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_OScss_Dlg;
	m_iWhoamI=GTCMD;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTCMD].sCmdstr);
	// TODO:  在此添加额外的初始化
	m_ComboBox_M.InsertString(0,"0: Delete the stored command.");
	m_ComboBox_M.InsertString(1,"1: Add the stored command.");
	m_ComboBox_M.SetCurSel(0);

	for (int i=0;i<32;i++)
	{
		CString str="";
		str.Format("%d",i);
		m_ComboBox_SI.InsertString(i,str);
	}
	m_ComboBox_SI.SetCurSel(0);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


CString OScss_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL OScss_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>3)
	{
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboMode();
		m_ComboBox_SI.SetCurSel(atoi(ValueList.GetAt(2)));
		OnCbnSelchangeComboSi();
		m_Edit_C.SetWindowText(ValueList.GetAt(3));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}

}



void OScss_Dlg::OnCbnSelchangeComboMode()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_M.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void OScss_Dlg::OnCbnSelchangeComboSi()
{

	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_SI.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,2,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void OScss_Dlg::OnEnChangeEditC()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_C.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,3,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


