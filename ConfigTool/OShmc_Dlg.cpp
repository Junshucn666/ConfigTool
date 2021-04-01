// OShmc_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "OShmc_Dlg.h"
#include "afxdialogex.h"
///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern OShmc_Dlg m_OShmc_Dlg;
OShmc_Dlg*	lpOShmc_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(OShmc_Dlg, CMyTabBaseDlg)

OShmc_Dlg::OShmc_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(OShmc_Dlg::IDD, pParent)
{

}

OShmc_Dlg::~OShmc_Dlg()
{
}

void OShmc_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_H, m_Check_H);
	DDX_Control(pDX, IDC_EDIT_I, m_Edit_I);
}


BEGIN_MESSAGE_MAP(OShmc_Dlg, CMyTabBaseDlg)
	ON_BN_CLICKED(IDC_CHECK_H, &OShmc_Dlg::OnBnClickedCheckH)
	ON_EN_CHANGE(IDC_EDIT_I, &OShmc_Dlg::OnEnChangeEditI)
END_MESSAGE_MAP()


// OShmc_Dlg 消息处理程序


BOOL OShmc_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpOShmc_Dlg=&m_OShmc_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_OShmc_Dlg;
	m_iWhoamI=GTHMC;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTHMC].sCmdstr);
	SetDlgItemText(IDC_EDIT_I,"00000:00:00");

	
	///////////////////////////////////////////
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


CString OShmc_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL OShmc_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>2)
	{
		m_Check_H.SetCheck(atoi(ValueList.GetAt(1)));
		OnBnClickedCheckH();
		m_Edit_I.SetWindowText(ValueList.GetAt(2));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}

}

void OShmc_Dlg::OnBnClickedCheckH()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_H.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}





void OShmc_Dlg::OnEnChangeEditI()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_I.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,2,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


