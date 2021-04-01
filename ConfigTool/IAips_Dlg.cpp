// IAips_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "IAips_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern IAips_Dlg m_IAips_Dlg;
IAips_Dlg*	lpIAips_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(IAips_Dlg, CMyTabBaseDlg)

IAips_Dlg::IAips_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(IAips_Dlg::IDD, pParent)
{

}

IAips_Dlg::~IAips_Dlg()
{
}

void IAips_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_II, m_ComboBox_II);
	DDX_Control(pDX, IDC_CHECK_ID1, m_Check_ID1);
	DDX_Control(pDX, IDC_CHECK_DI1, m_Check_DI1);
	DDX_Control(pDX, IDC_CHECK_ID2, m_Check_ID2);
	DDX_Control(pDX, IDC_CHECK_DI2, m_Check_DI2);
	DDX_Control(pDX, IDC_SPIN_SP, m_Spin_SP);
	DDX_Control(pDX, IDC_EDIT_SP, m_Edit_SP);
	DDX_Control(pDX, IDC_COMBO_OI, m_ComboBox_OI);
	DDX_Control(pDX, IDC_CHECK_OutS, m_Check_OutS);
	DDX_Control(pDX, IDC_SPIN_D, m_Spin_D);
	DDX_Control(pDX, IDC_EDIT_D, m_Edit_D);
	DDX_Control(pDX, IDC_EDIT_TT, m_Edit_TT);
	DDX_Control(pDX, IDC_SPIN_TT, m_Spin_TT);
}


BEGIN_MESSAGE_MAP(IAips_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_II, &IAips_Dlg::OnCbnSelchangeComboIi)
	ON_BN_CLICKED(IDC_CHECK_ID1, &IAips_Dlg::OnBnClickedCheckId1)
	ON_BN_CLICKED(IDC_CHECK_DI1, &IAips_Dlg::OnBnClickedCheckDi1)
	ON_BN_CLICKED(IDC_CHECK_ID2, &IAips_Dlg::OnBnClickedCheckId2)
	ON_BN_CLICKED(IDC_CHECK_DI2, &IAips_Dlg::OnBnClickedCheckDi2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_SP, &IAips_Dlg::OnDeltaposSpinSp)
	ON_EN_CHANGE(IDC_EDIT_SP, &IAips_Dlg::OnEnChangeEditSp)
	ON_CBN_SELCHANGE(IDC_COMBO_OI, &IAips_Dlg::OnCbnSelchangeComboOi)
	ON_BN_CLICKED(IDC_CHECK_OutS, &IAips_Dlg::OnBnClickedCheckOuts)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D, &IAips_Dlg::OnDeltaposSpinD)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT, &IAips_Dlg::OnDeltaposSpinTt)
	ON_EN_CHANGE(IDC_EDIT_TT, &IAips_Dlg::OnEnChangeEditTt)
	ON_EN_CHANGE(IDC_EDIT_D, &IAips_Dlg::OnEnChangeEditD)
END_MESSAGE_MAP()


// IAips_Dlg 消息处理程序


BOOL IAips_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpIAips_Dlg=&m_IAips_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_IAips_Dlg;
	m_iWhoamI=GTIOB;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTIOB].sCmdstr);

	m_ComboBox_II.InsertString(0,"0");
	m_ComboBox_II.InsertString(1,"1");
	m_ComboBox_II.InsertString(2,"2");
	m_ComboBox_II.InsertString(3,"3");
	m_ComboBox_II.SetCurSel(0);
	///////////////
	SetDlgItemText(IDC_EDIT_SP,"0");
	m_Spin_SP.SetBuddy(GetDlgItem(IDC_EDIT_SP)); //得到指向编辑框的窗口指针
	m_Spin_SP.SetRange(1,12);
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

	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


CString IAips_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL IAips_Dlg::UpdataPage(CString sStr)
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
		m_ComboBox_II.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboIi();
		m_Edit_SP.SetWindowText(ValueList.GetAt(4));

		m_ComboBox_OI.SetCurSel(atoi(ValueList.GetAt(5)));
		OnCbnSelchangeComboOi();
		m_Check_OutS.SetCheck(atoi(ValueList.GetAt(6)));
		OnBnClickedCheckOuts();
		m_Edit_D.SetWindowText(ValueList.GetAt(7));
		m_Edit_TT.SetWindowText(ValueList.GetAt(8));

		SetIMValue(ValueList.GetAt(2));
		SetTMValue(ValueList.GetAt(3));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}

//2
void IAips_Dlg::OnCbnSelchangeComboIi()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_II.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void IAips_Dlg::OnBnClickedCheckId1()
{
	GetIMValue();
}


void IAips_Dlg::OnBnClickedCheckDi1()
{
	GetIMValue();
}
//3
void IAips_Dlg::GetIMValue()
{
	int iB0=0,iB1=0;
	CString sStrB="",sStrH="",sCmd="",sNewCmd="";
	iB0=m_Check_ID1.GetCheck();
	iB1=m_Check_DI1.GetCheck();
	sStrB.Format("%d%d",iB1,iB0);
	m_MYWORK.BsToHex2Bit(sStrB,sStrH);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStrH,2,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void IAips_Dlg::SetIMValue(CString sStrH)
{
	CString sStrB="",sTemp="";
	int iB0=0,iB1=0;
	m_MYWORK.HexToBsStr(sStrH,sStrB,2);

	sTemp.Format("%c",sStrB[0]);
	iB1=atoi(sTemp);
	m_Check_DI1.SetCheck(iB1);
	OnBnClickedCheckDi1();

	sTemp.Format("%c",sStrB[1]);
	iB0=atoi(sTemp);
	m_Check_ID1.SetCheck(iB0);
	OnBnClickedCheckId1();
}

void IAips_Dlg::OnBnClickedCheckId2()
{
	GetTMValue();
}


void IAips_Dlg::OnBnClickedCheckDi2()
{
	GetTMValue();
}

//4
void IAips_Dlg::GetTMValue()
{
	int iB0=0,iB1=0;
	CString sStrB="",sStrH="",sCmd="",sNewCmd="";
	iB0=m_Check_ID2.GetCheck();
	iB1=m_Check_DI2.GetCheck();
	sStrB.Format("%d%d",iB1,iB0);
	m_MYWORK.BsToHex2Bit(sStrB,sStrH);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStrH,3,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void IAips_Dlg::SetTMValue(CString sStrH)
{
	CString sStrB="",sTemp="";
	int iB0=0,iB1=0;
	m_MYWORK.HexToBsStr(sStrH,sStrB,2);

	sTemp.Format("%c",sStrB[0]);
	iB1=atoi(sTemp);
	m_Check_DI2.SetCheck(iB1);
	OnBnClickedCheckDi2();

	sTemp.Format("%c",sStrB[1]);
	iB0=atoi(sTemp);
	m_Check_ID2.SetCheck(iB0);
	OnBnClickedCheckId2();
}

void IAips_Dlg::OnDeltaposSpinSp(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_SP.GetPos();
	m_Spin_SP.SetPos(iTemp);
	m_Edit_SP.GetWindowText(strValue);  
	*pResult = 0;
}

//5
void IAips_Dlg::OnEnChangeEditSp()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_SP.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,4,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//6
void IAips_Dlg::OnCbnSelchangeComboOi()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_OI.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,5,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//7
void IAips_Dlg::OnBnClickedCheckOuts()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_OutS.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,6,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void IAips_Dlg::OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D.GetPos();
	m_Spin_D.SetPos(iTemp);
	m_Edit_D.GetWindowText(strValue);  
	*pResult = 0;
}

//8
void IAips_Dlg::OnEnChangeEditD()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_D.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,7,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void IAips_Dlg::OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT.GetPos();
	m_Spin_TT.SetPos(iTemp);
	m_Edit_TT.GetWindowText(strValue);  
	*pResult = 0;
}

//9
void IAips_Dlg::OnEnChangeEditTt()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TT.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,8,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


