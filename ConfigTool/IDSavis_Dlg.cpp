// IDSavis_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "IDSavis_Dlg.h"
#include "afxdialogex.h"

///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern IDSavis_Dlg m_IDSavis_Dlg;
IDSavis_Dlg*	lpIDSavis_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(IDSavis_Dlg, CMyTabBaseDlg)

IDSavis_Dlg::IDSavis_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(IDSavis_Dlg::IDD, pParent)
{

}

IDSavis_Dlg::~IDSavis_Dlg()
{
}

void IDSavis_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN_SRD, m_Spin_SRD);
	DDX_Control(pDX, IDC_SPIN_SMV, m_Spin_SMV);
	DDX_Control(pDX, IDC_EDIT_SRD, m_Edit_SRD);
	DDX_Control(pDX, IDC_EDIT_SMV, m_Edit_SMV);
}


BEGIN_MESSAGE_MAP(IDSavis_Dlg, CMyTabBaseDlg)
	ON_EN_CHANGE(IDC_EDIT_SRD, &IDSavis_Dlg::OnEnChangeEditSrd)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_SRD, &IDSavis_Dlg::OnDeltaposSpinSrd)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_SMV, &IDSavis_Dlg::OnDeltaposSpinSmv)
	ON_EN_CHANGE(IDC_EDIT_SMV, &IDSavis_Dlg::OnEnChangeEditSmv)
END_MESSAGE_MAP()


// IDSavis_Dlg 消息处理程序


BOOL IDSavis_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpIDSavis_Dlg=&m_IDSavis_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_IDSavis_Dlg;
	m_iWhoamI=GTAVS;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTAVS].sCmdstr);

	SetDlgItemText(IDC_EDIT_SRD,"120");
	m_Spin_SRD.SetBuddy(GetDlgItem(IDC_EDIT_SRD)); //得到指向编辑框的窗口指针
	m_Spin_SRD.SetRange(1,255);
	/////////////////
	SetDlgItemText(IDC_EDIT_SMV,"10");
	m_Spin_SMV.SetBuddy(GetDlgItem(IDC_EDIT_SMV)); //得到指向编辑框的窗口指针
	m_Spin_SMV.SetRange(1,255);
	/////////////////

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString IDSavis_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL IDSavis_Dlg::UpdataPage(CString sStr)
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
		m_Edit_SRD.SetWindowText(ValueList.GetAt(1));
		m_Edit_SMV.SetWindowText(ValueList.GetAt(2));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}

}

void IDSavis_Dlg::OnDeltaposSpinSrd(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_SRD.GetPos();
	m_Spin_SRD.SetPos(iTemp);
	m_Edit_SRD.GetWindowText(strValue);  
	*pResult = 0;
}


void IDSavis_Dlg::OnDeltaposSpinSmv(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_SMV.GetPos();
	m_Spin_SMV.SetPos(iTemp);
	m_Edit_SMV.GetWindowText(strValue);  
	*pResult = 0;
}
//2
void IDSavis_Dlg::OnEnChangeEditSrd()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_SRD.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,1,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}
//3
void IDSavis_Dlg::OnEnChangeEditSmv()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_SMV.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,2,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


