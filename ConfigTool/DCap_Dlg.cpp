// DCap_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "DCap_Dlg.h"
#include "afxdialogex.h"
///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern DCap_Dlg m_DCap_Dlg;
DCap_Dlg*	lpDCap_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(DCap_Dlg, CMyTabBaseDlg)

DCap_Dlg::DCap_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(DCap_Dlg::IDD, pParent)
{

}

DCap_Dlg::~DCap_Dlg()
{
}

void DCap_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_EAUP, m_Check_EAUP);
	DDX_Control(pDX, IDC_EDIT_UP, m_Edit_UP);
}


BEGIN_MESSAGE_MAP(DCap_Dlg, CMyTabBaseDlg)
	ON_BN_CLICKED(IDC_CHECK_EAUP, &DCap_Dlg::OnBnClickedCheckEaup)
	ON_EN_CHANGE(IDC_EDIT_UP, &DCap_Dlg::OnEnChangeEditUp)
END_MESSAGE_MAP()


// DCap_Dlg 消息处理程序


BOOL DCap_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	// TODO:  在此添加额外的初始化
	lpDCap_Dlg=&m_DCap_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_DCap_Dlg;
	m_iWhoamI=GTPIN;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTPIN].sCmdstr);
	                                      //HYIoT,1,1234,,,,,,0011$

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString DCap_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL DCap_Dlg::UpdataPage(CString sStr)
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
		m_Check_EAUP.SetCheck(atoi(ValueList.GetAt(1)));
		m_Edit_UP.SetWindowText(ValueList.GetAt(2));

		m_Check_EAUP.SetCheck(atoi(ValueList.GetAt(1)));
		OnBnClickedCheckEaup();
		m_Edit_UP.SetWindowText(ValueList.GetAt(2));


		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}

}

void DCap_Dlg::OnBnClickedCheckEaup()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_EAUP.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void DCap_Dlg::OnEnChangeEditUp()
{
	CString sStr="",sCmd="",sNewCmd="";
	m_Edit_UP.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,2,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

