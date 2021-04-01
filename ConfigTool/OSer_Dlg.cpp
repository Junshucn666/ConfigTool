// OSer_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "OSer_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern OSer_Dlg m_OSer_Dlg;
OSer_Dlg*	lpOSer_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(OSer_Dlg, CMyTabBaseDlg)

OSer_Dlg::OSer_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(OSer_Dlg::IDD, pParent)
{

}

OSer_Dlg::~OSer_Dlg()
{
}

void OSer_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN_IT, m_Spin_IT);
	DDX_Control(pDX, IDC_SPIN_IC, m_Spin_IC);
	DDX_Control(pDX, IDC_SPIN_ER, m_Spin_ER);
	DDX_Control(pDX, IDC_SPIN_RA, m_Spin_RA);
	DDX_Control(pDX, IDC_EDIT_IT, m_Edit_IT);
	DDX_Control(pDX, IDC_EDIT_IC, m_Edit_IC);
	DDX_Control(pDX, IDC_EDIT_ER, m_Edit_ER);
	DDX_Control(pDX, IDC_EDIT_RA, m_Edit_RA);
	DDX_Control(pDX, IDC_COMBO_NR, m_ComboBox_NR);
}


BEGIN_MESSAGE_MAP(OSer_Dlg, CMyTabBaseDlg)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_IT, &OSer_Dlg::OnDeltaposSpinIt)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_IC, &OSer_Dlg::OnDeltaposSpinIc)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ER, &OSer_Dlg::OnDeltaposSpinEr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_RA, &OSer_Dlg::OnDeltaposSpinRa)
	ON_EN_CHANGE(IDC_EDIT_IT, &OSer_Dlg::OnEnChangeEditIt)
	ON_EN_CHANGE(IDC_EDIT_IC, &OSer_Dlg::OnEnChangeEditIc)
	ON_EN_CHANGE(IDC_EDIT_ER, &OSer_Dlg::OnEnChangeEditEr)
	ON_EN_CHANGE(IDC_EDIT_RA, &OSer_Dlg::OnEnChangeEditRa)
	ON_CBN_SELCHANGE(IDC_COMBO_NR, &OSer_Dlg::OnCbnSelchangeComboNr)
END_MESSAGE_MAP()


// OSer_Dlg 消息处理程序


BOOL OSer_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpOSer_Dlg=&m_OSer_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_OSer_Dlg;
	m_iWhoamI=GTEMR;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTEMR].sCmdstr);

	SetDlgItemText(IDC_EDIT_IT,"0");
	m_Spin_IT.SetBuddy(GetDlgItem(IDC_EDIT_IT)); //得到指向编辑框的窗口指针
	m_Spin_IT.SetRange(20,90);
	/////////////////
	SetDlgItemText(IDC_EDIT_IC,"0");
	m_Spin_IC.SetBuddy(GetDlgItem(IDC_EDIT_IC)); //得到指向编辑框的窗口指针
	m_Spin_IC.SetRange(5,60);
	/////////////////
	SetDlgItemText(IDC_EDIT_ER,"0");
	m_Spin_ER.SetBuddy(GetDlgItem(IDC_EDIT_ER)); //得到指向编辑框的窗口指针
	m_Spin_ER.SetRange(1,24);
	/////////////////
	SetDlgItemText(IDC_EDIT_RA,"30");
	m_Spin_RA.SetBuddy(GetDlgItem(IDC_EDIT_RA)); //得到指向编辑框的窗口指针
	m_Spin_RA.SetRange(1,60);
	/////////////////
	m_ComboBox_NR.InsertString(0,"0: Disable Emergency Settings when there is network coverage");
	m_ComboBox_NR.InsertString(1,"1: Enable Emergency Settings when there is network coverage.");
	m_ComboBox_NR.SetCurSel(0);
	///////////////
	
	///////////////////////////////////////////
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}



CString OSer_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL OSer_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>5)
	{
		m_Edit_IT.SetWindowText(ValueList.GetAt(1));
		m_Edit_IC.SetWindowText(ValueList.GetAt(2));
		m_Edit_ER.SetWindowText(ValueList.GetAt(3));
		m_Edit_RA.SetWindowText(ValueList.GetAt(5));
		m_ComboBox_NR.SetCurSel(atoi(ValueList.GetAt(4)));
		OnCbnSelchangeComboNr();

		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}

}

void OSer_Dlg::OnDeltaposSpinIt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_IT.GetPos();
	m_Spin_IT.SetPos(iTemp);
	m_Edit_IT.GetWindowText(strValue);  
	*pResult = 0;
}

void OSer_Dlg::OnDeltaposSpinIc(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_IC.GetPos();
	m_Spin_IC.SetPos(iTemp);
	m_Edit_IC.GetWindowText(strValue);  
	*pResult = 0;
}


void OSer_Dlg::OnDeltaposSpinEr(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_ER.GetPos();
	m_Spin_ER.SetPos(iTemp);
	m_Edit_ER.GetWindowText(strValue);  
	*pResult = 0;
}


void OSer_Dlg::OnDeltaposSpinRa(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_RA.GetPos();
	m_Spin_RA.SetPos(iTemp);
	m_Edit_RA.GetWindowText(strValue);  
	*pResult = 0;
}


void OSer_Dlg::OnEnChangeEditIt()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_IT.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,1,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void OSer_Dlg::OnEnChangeEditIc()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_IC.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,2,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void OSer_Dlg::OnEnChangeEditEr()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_ER.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,3,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void OSer_Dlg::OnEnChangeEditRa()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_RA.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,5,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//5
void OSer_Dlg::OnCbnSelchangeComboNr()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_NR.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,4,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

