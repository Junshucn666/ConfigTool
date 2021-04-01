// IDSidbvs_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "IDSidbvs_Dlg.h"
#include "afxdialogex.h"

///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern IDSidbvs_Dlg m_IDSidbvs_Dlg;
IDSidbvs_Dlg*	lpIDSidbvs_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(IDSidbvs_Dlg, CMyTabBaseDlg)

IDSidbvs_Dlg::IDSidbvs_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(IDSidbvs_Dlg::IDD, pParent)
{

}

IDSidbvs_Dlg::~IDSidbvs_Dlg()
{
}

void IDSidbvs_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN_IoV, m_Spin_IoV);
	DDX_Control(pDX, IDC_SPIN_Vo, m_Spin_Vo);
	DDX_Control(pDX, IDC_SPIN_D, m_Spin_D);
	DDX_Control(pDX, IDC_SPIN_IN, m_Spin_IN);
	DDX_Control(pDX, IDC_SPIN_IF, m_Spin_IF);
	DDX_Control(pDX, IDC_EDIT_IoV, m_Edit_IoV);
	DDX_Control(pDX, IDC_EDIT_Vo, m_Edit_Vo);
	DDX_Control(pDX, IDC_EDIT_D, m_Edit_D);
	DDX_Control(pDX, IDC_EDIT_IN, m_Edit_IN);
	DDX_Control(pDX, IDC_EDIT_IF, m_Edit_IF);
}


BEGIN_MESSAGE_MAP(IDSidbvs_Dlg, CMyTabBaseDlg)
	ON_EN_CHANGE(IDC_EDIT_IoV, &IDSidbvs_Dlg::OnEnChangeEditIov)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_IoV, &IDSidbvs_Dlg::OnDeltaposSpinIov)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Vo, &IDSidbvs_Dlg::OnDeltaposSpinVo)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D, &IDSidbvs_Dlg::OnDeltaposSpinD)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_IN, &IDSidbvs_Dlg::OnDeltaposSpinIn)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_IF, &IDSidbvs_Dlg::OnDeltaposSpinIf)
	ON_EN_CHANGE(IDC_EDIT_IN, &IDSidbvs_Dlg::OnEnChangeEditIn)
	ON_EN_CHANGE(IDC_EDIT_IF, &IDSidbvs_Dlg::OnEnChangeEditIf)
END_MESSAGE_MAP()


// IDSidbvs_Dlg 消息处理程序


BOOL IDSidbvs_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpIDSidbvs_Dlg=&m_IDSidbvs_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_IDSidbvs_Dlg;
	m_iWhoamI=GTVVS;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTVVS].sCmdstr);
	                             //AT+GTVVS=HYIoT,13000,500,10,,,000B$
	//SetDlgItemText(IDC_EDIT_IoV,"0");
	//m_Spin_IoV.SetBuddy(GetDlgItem(IDC_EDIT_IoV)); //得到指向编辑框的窗口指针
	//m_Spin_IoV.SetRange(0,255);
	/////////////////
	SetDlgItemText(IDC_EDIT_IN,"1");
	m_Spin_IN.SetBuddy(GetDlgItem(IDC_EDIT_IN)); //得到指向编辑框的窗口指针
	m_Spin_IN.SetRange(1,255);
	SetDlgItemText(IDC_EDIT_IF,"1");
	m_Spin_IF.SetBuddy(GetDlgItem(IDC_EDIT_IF)); //得到指向编辑框的窗口指针
	m_Spin_IF.SetRange(1,255);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


CString IDSidbvs_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL IDSidbvs_Dlg::UpdataPage(CString sStr)
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
		ValueList.Add(sRight);
	}
	if (ValueList.GetSize()>5)
	{
		m_Edit_IN.SetWindowText(ValueList.GetAt(4));
		m_Edit_IF.SetWindowText(ValueList.GetAt(5));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}

}


void IDSidbvs_Dlg::OnDeltaposSpinIov(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_IoV.GetPos();
	m_Spin_IoV.SetPos(iTemp);
	m_Edit_IoV.GetWindowText(strValue);  
	*pResult = 0;
}


void IDSidbvs_Dlg::OnDeltaposSpinVo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_Vo.GetPos();
	m_Spin_Vo.SetPos(iTemp);
	m_Edit_Vo.GetWindowText(strValue);  
	*pResult = 0;
}


void IDSidbvs_Dlg::OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D.GetPos();
	m_Spin_D.SetPos(iTemp);
	m_Edit_D.GetWindowText(strValue);  
	*pResult = 0;
}


void IDSidbvs_Dlg::OnDeltaposSpinIn(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_IN.GetPos();
	m_Spin_IN.SetPos(iTemp);
	m_Edit_IN.GetWindowText(strValue);  
	*pResult = 0;
}


void IDSidbvs_Dlg::OnDeltaposSpinIf(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_IF.GetPos();
	m_Spin_IF.SetPos(iTemp);
	m_Edit_IF.GetWindowText(strValue);  
	*pResult = 0;
}

void IDSidbvs_Dlg::OnEnChangeEditIov()
{

}

//5
void IDSidbvs_Dlg::OnEnChangeEditIn()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_IN.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,4,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//6
void IDSidbvs_Dlg::OnEnChangeEditIf()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_IF.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,5,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

