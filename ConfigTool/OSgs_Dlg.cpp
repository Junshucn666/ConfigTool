// OSgs_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "OSgs_Dlg.h"
#include "afxdialogex.h"

///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern OSgs_Dlg m_OSgs_Dlg;
OSgs_Dlg*	lpOSgs_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(OSgs_Dlg, CMyTabBaseDlg)

OSgs_Dlg::OSgs_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(OSgs_Dlg::IDD, pParent)
{

}

OSgs_Dlg::~OSgs_Dlg()
{
}

void OSgs_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN_BS, m_Spin_BS);
	DDX_Control(pDX, IDC_SPIN_DS, m_Spin_DS);
	DDX_Control(pDX, IDC_SPIN_DH, m_Spin_DH);
	DDX_Control(pDX, IDC_EDIT_BS, m_Edit_BS);
	DDX_Control(pDX, IDC_EDIT_DS, m_Edit_DS);
	DDX_Control(pDX, IDC_EDIT_DH, m_Edit_DH);
	DDX_Control(pDX, IDC_COMBO_OI, m_ComboBox_OI);
	DDX_Control(pDX, IDC_EDIT_TT, m_Edit_TT);
	DDX_Control(pDX, IDC_EDIT_D, m_Edit_D);
	DDX_Control(pDX, IDC_CHECK_OutS, m_Check_OutS);
	DDX_Control(pDX, IDC_SPIN_D, m_Spin_D);
	DDX_Control(pDX, IDC_SPIN_TT, m_Spin_TT);
}


BEGIN_MESSAGE_MAP(OSgs_Dlg, CMyTabBaseDlg)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_BS, &OSgs_Dlg::OnDeltaposSpinBs)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_DS, &OSgs_Dlg::OnDeltaposSpinDs)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_DH, &OSgs_Dlg::OnDeltaposSpinDh)
	ON_EN_CHANGE(IDC_EDIT_BS, &OSgs_Dlg::OnEnChangeEditBs)
	ON_EN_CHANGE(IDC_EDIT_DS, &OSgs_Dlg::OnEnChangeEditDs)
	ON_EN_CHANGE(IDC_EDIT_DH, &OSgs_Dlg::OnEnChangeEditDh)
	ON_CBN_SELCHANGE(IDC_COMBO_OI, &OSgs_Dlg::OnCbnSelchangeComboOi)
	ON_BN_CLICKED(IDC_CHECK_OutS, &OSgs_Dlg::OnBnClickedCheckOuts)
	ON_EN_CHANGE(IDC_EDIT_D, &OSgs_Dlg::OnEnChangeEditD)
	ON_EN_CHANGE(IDC_EDIT_TT, &OSgs_Dlg::OnEnChangeEditTt)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D, &OSgs_Dlg::OnDeltaposSpinD)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT, &OSgs_Dlg::OnDeltaposSpinTt)
END_MESSAGE_MAP()


// OSgs_Dlg 消息处理程序


BOOL OSgs_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpOSgs_Dlg=&m_OSgs_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_OSgs_Dlg;
	m_iWhoamI=GTASC;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTASC].sCmdstr);

	SetDlgItemText(IDC_EDIT_BS,"50");
	m_Spin_BS.SetBuddy(GetDlgItem(IDC_EDIT_BS)); //得到指向编辑框的窗口指针
	m_Spin_BS.SetRange(18,250);
	/////////////////
	SetDlgItemText(IDC_EDIT_DS,"10");
	m_Spin_DS.SetBuddy(GetDlgItem(IDC_EDIT_DS)); //得到指向编辑框的窗口指针
	m_Spin_DS.SetRange(3,46);
	/////////////////
	SetDlgItemText(IDC_EDIT_DH,"5");
	m_Spin_DH.SetBuddy(GetDlgItem(IDC_EDIT_DH)); //得到指向编辑框的窗口指针
	m_Spin_DH.SetRange(0,5);
	/////////////////
	/////////////////
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
	/////////////
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString OSgs_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL OSgs_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>11)
	{
		m_Edit_BS.SetWindowText(ValueList.GetAt(1));
		m_Edit_DS.SetWindowText(ValueList.GetAt(2));
		m_Edit_DH.SetWindowText(ValueList.GetAt(3));

		m_ComboBox_OI.SetCurSel(atoi(ValueList.GetAt(8)));
		OnCbnSelchangeComboOi();
		m_Check_OutS.SetCheck(atoi(ValueList.GetAt(9)));
		OnBnClickedCheckOuts();
		m_Edit_D.SetWindowText(ValueList.GetAt(10));
		m_Edit_TT.SetWindowText(ValueList.GetAt(11));

		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}

}

void OSgs_Dlg::OnDeltaposSpinBs(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_BS.GetPos();
	m_Spin_BS.SetPos(iTemp);
	m_Edit_BS.GetWindowText(strValue);  
	*pResult = 0;
}


void OSgs_Dlg::OnDeltaposSpinDs(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_DS.GetPos();
	m_Spin_DS.SetPos(iTemp);
	m_Edit_DS.GetWindowText(strValue);  
	*pResult = 0;
}


void OSgs_Dlg::OnDeltaposSpinDh(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_DH.GetPos();
	m_Spin_DH.SetPos(iTemp);
	m_Edit_DH.GetWindowText(strValue);  
	*pResult = 0;
}


void OSgs_Dlg::OnEnChangeEditBs()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_BS.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,1,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void OSgs_Dlg::OnEnChangeEditDs()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_DS.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,2,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void OSgs_Dlg::OnEnChangeEditDh()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_DH.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,3,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//9
void OSgs_Dlg::OnCbnSelchangeComboOi()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_OI.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,8,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//10
void OSgs_Dlg::OnBnClickedCheckOuts()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_OutS.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,9,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//11
void OSgs_Dlg::OnEnChangeEditD()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_D.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,10,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//12
void OSgs_Dlg::OnEnChangeEditTt()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TT.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,11,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void OSgs_Dlg::OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D.GetPos();
	m_Spin_D.SetPos(iTemp);
	m_Edit_D.GetWindowText(strValue);  
	*pResult = 0;
}


void OSgs_Dlg::OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT.GetPos();
	m_Spin_TT.SetPos(iTemp);
	m_Edit_TT.GetWindowText(strValue);  
	*pResult = 0;
}

