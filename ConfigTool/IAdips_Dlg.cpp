// IAdips_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "IAdips_Dlg.h"
#include "afxdialogex.h"

///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern IAdips_Dlg m_IAdips_Dlg;
IAdips_Dlg*	lpIAdips_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(IAdips_Dlg, CMyTabBaseDlg)

IAdips_Dlg::IAdips_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(IAdips_Dlg::IDD, pParent)
{

}

IAdips_Dlg::~IAdips_Dlg()
{
}

void IAdips_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_VT, m_Edit_VT);
	DDX_Control(pDX, IDC_CHECK_ETI, m_Check_ETI);
	DDX_Control(pDX, IDC_COMBO_ITS, m_ComboBox_ITS);
	DDX_Control(pDX, IDC_SPIN_VT, m_Spin_VT);
}


BEGIN_MESSAGE_MAP(IAdips_Dlg, CMyTabBaseDlg)
	ON_EN_CHANGE(IDC_EDIT_VT, &IAdips_Dlg::OnEnChangeEditVt)
	ON_BN_CLICKED(IDC_CHECK_ETI, &IAdips_Dlg::OnBnClickedCheckEti)
	ON_CBN_SELCHANGE(IDC_COMBO_ITS, &IAdips_Dlg::OnCbnSelchangeComboIts)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_VT, &IAdips_Dlg::OnDeltaposSpinVt)
END_MESSAGE_MAP()


// IAdips_Dlg 消息处理程序


BOOL IAdips_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpIAdips_Dlg=&m_IAdips_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_IAdips_Dlg;
	m_iWhoamI=GTDIS;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTDIS].sCmdstr);

	m_ComboBox_ITS.InsertString(0,"0: Including real time position in the report");
	m_ComboBox_ITS.InsertString(1,"1: Including the last known position in the report");
	m_ComboBox_ITS.SetCurSel(0);
	///////////////
	SetDlgItemText(IDC_EDIT_VT,"0");
	m_Spin_VT.SetBuddy(GetDlgItem(IDC_EDIT_VT)); //得到指向编辑框的窗口指针
	m_Spin_VT.SetRange(1,12);
	/////////////////
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}



CString IAdips_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL IAdips_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>8)
	{
		m_Check_ETI.SetCheck(atoi(ValueList.GetAt(6)));
		OnBnClickedCheckEti();

		m_Edit_VT.SetWindowText(ValueList.GetAt(8));

		m_ComboBox_ITS.SetCurSel(atoi(ValueList.GetAt(2)));
		OnCbnSelchangeComboIts();
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}
//9
void IAdips_Dlg::OnEnChangeEditVt()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_VT.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,8,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//7
void IAdips_Dlg::OnBnClickedCheckEti()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_ETI.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,6,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//3
void IAdips_Dlg::OnCbnSelchangeComboIts()
{

	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_ITS.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,2,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void IAdips_Dlg::OnDeltaposSpinVt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_VT.GetPos();
	m_Spin_VT.SetPos(iTemp);
	m_Edit_VT.GetWindowText(strValue);  
	*pResult = 0;
}
