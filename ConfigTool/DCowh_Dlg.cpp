// DCowh_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "DCowh_Dlg.h"
#include "afxdialogex.h"

///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"
// DCap_Dlg 对话框
extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern DCowh_Dlg m_DCowh_Dlg;
DCowh_Dlg*	lpDCowh_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(DCowh_Dlg, CMyTabBaseDlg)

DCowh_Dlg::DCowh_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(DCowh_Dlg::IDD, pParent)
{

}

DCowh_Dlg::~DCowh_Dlg()
{
}

void DCowh_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_COMBO_D, m_ComboBox_D);
	DDX_Control(pDX, IDC_COMBO_O, m_ComboBox_O);
	DDX_Control(pDX, IDC_CHECK_Mon, m_Check_Mon);
	DDX_Control(pDX, IDC_CHECK_Tue, m_Check_Tue);
	DDX_Control(pDX, IDC_CHECK_Wed, m_Check_Wed);
	DDX_Control(pDX, IDC_CHECK_Thu, m_Check_Thu);
	DDX_Control(pDX, IDC_CHECK_Fri, m_Check_Fri);
	DDX_Control(pDX, IDC_CHECK_Sat, m_Check_Sat);
	DDX_Control(pDX, IDC_CHECK_Sun, m_Check_Sun);
	DDX_Control(pDX, IDC_CHECK_ca, m_Check_ca);
	DDX_Control(pDX, IDC_EDIT_WHS1, m_Edit_WHS1);
	DDX_Control(pDX, IDC_EDIT_WHS2, m_Edit_WHS2);
	DDX_Control(pDX, IDC_EDIT_WHE1, m_Edit_WHE1);
	DDX_Control(pDX, IDC_EDIT_WHE2, m_Edit_WHE2);
	DDX_Control(pDX, IDC_CHECK_OS, m_Check_OS);
	DDX_Control(pDX, IDC_SPIN_D, m_Spin_D);
	DDX_Control(pDX, IDC_EDIT_D, m_Edit_D);
	DDX_Control(pDX, IDC_SPIN_TT, m_Spin_TT);
	DDX_Control(pDX, IDC_EDIT_TT, m_Edit_TT);
}


BEGIN_MESSAGE_MAP(DCowh_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &DCowh_Dlg::OnCbnSelchangeComboM)
	ON_BN_CLICKED(IDC_CHECK_Mon, &DCowh_Dlg::OnBnClickedCheckMon)
	ON_BN_CLICKED(IDC_CHECK_Tue, &DCowh_Dlg::OnBnClickedCheckTue)
	ON_BN_CLICKED(IDC_CHECK_Wed, &DCowh_Dlg::OnBnClickedCheckWed)
	ON_BN_CLICKED(IDC_CHECK_Thu, &DCowh_Dlg::OnBnClickedCheckThu)
	ON_BN_CLICKED(IDC_CHECK_Fri, &DCowh_Dlg::OnBnClickedCheckFri)
	ON_BN_CLICKED(IDC_CHECK_Sat, &DCowh_Dlg::OnBnClickedCheckSat)
	ON_BN_CLICKED(IDC_CHECK_Sun, &DCowh_Dlg::OnBnClickedCheckSun)
	ON_BN_CLICKED(IDC_CHECK_ca, &DCowh_Dlg::OnBnClickedCheckca)
	ON_EN_CHANGE(IDC_EDIT_WHS1, &DCowh_Dlg::OnEnChangeEditWhs1)
	ON_EN_CHANGE(IDC_EDIT_WHS2, &DCowh_Dlg::OnEnChangeEditWhs2)
	ON_EN_CHANGE(IDC_EDIT_WHE1, &DCowh_Dlg::OnEnChangeEditWhe1)
	ON_EN_CHANGE(IDC_EDIT_WHE2, &DCowh_Dlg::OnEnChangeEditWhe2)
	ON_CBN_SELCHANGE(IDC_COMBO_D, &DCowh_Dlg::OnCbnSelchangeComboD)
	ON_CBN_SELCHANGE(IDC_COMBO_O, &DCowh_Dlg::OnCbnSelchangeComboO)
	ON_BN_CLICKED(IDC_CHECK_OS, &DCowh_Dlg::OnBnClickedCheckOs)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D, &DCowh_Dlg::OnDeltaposSpinD)
	ON_EN_CHANGE(IDC_EDIT_D, &DCowh_Dlg::OnEnChangeEditD)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT, &DCowh_Dlg::OnDeltaposSpinTt)
	ON_EN_CHANGE(IDC_EDIT_TT, &DCowh_Dlg::OnEnChangeEditTt)
END_MESSAGE_MAP()


// DCowh_Dlg 消息处理程序


BOOL DCowh_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpDCowh_Dlg=&m_DCowh_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_DCowh_Dlg;
	m_iWhoamI=GTOWH;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTOWH].sCmdstr);
	SetDlgItemText(IDC_EDIT_WHS1,"0900");
	SetDlgItemText(IDC_EDIT_WHE1,"1200");
	SetDlgItemText(IDC_EDIT_WHS2,"1300");
	SetDlgItemText(IDC_EDIT_WHE2,"1800");
	SetDlgItemText(IDC_EDIT_D,"0");
	m_Spin_D.SetBuddy(GetDlgItem(IDC_EDIT_D)); //得到指向编辑框的窗口指针
	m_Spin_D.SetRange(0,255);
	SetDlgItemText(IDC_EDIT_TT,"0");
	m_Spin_TT.SetBuddy(GetDlgItem(IDC_EDIT_TT)); //得到指向编辑框的窗口指针
	m_Spin_TT.SetRange(0,255);
	///////////////////////////////
	m_ComboBox_M.InsertString(0,"Disable this function");
	m_ComboBox_M.InsertString(1,"Manual mode");
	m_ComboBox_M.InsertString(2,"Full manual mode");
    m_ComboBox_M.InsertString(3,"Automatic mode");
	m_ComboBox_M.SetCurSel(0);
	m_ComboBox_D.InsertString(0,"0");
	m_ComboBox_D.InsertString(1,"1");
	m_ComboBox_D.SetCurSel(0);
	m_ComboBox_O.InsertString(0,"0");
	m_ComboBox_O.InsertString(1,"1");
	m_ComboBox_O.InsertString(2,"2");
	m_ComboBox_O.SetCurSel(0);
	////////////
	m_Check_Mon.SetCheck(1);
	m_Check_Tue.SetCheck(1);
	m_Check_Wed.SetCheck(1);
	m_Check_Thu.SetCheck(1);
	m_Check_Fri.SetCheck(1);
	m_Check_Sat.SetCheck(0);
	m_Check_Sun.SetCheck(0);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString DCowh_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL DCowh_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>13)
	{
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboM();

		m_Edit_WHS1.SetWindowText(ValueList.GetAt(3));
		m_Edit_WHE1.SetWindowText(ValueList.GetAt(4));
		m_Edit_WHS2.SetWindowText(ValueList.GetAt(5));
		m_Edit_WHE2.SetWindowText(ValueList.GetAt(6));

		m_ComboBox_D.SetCurSel(atoi(ValueList.GetAt(9)));
		OnCbnSelchangeComboD();	

		m_ComboBox_O.SetCurSel(atoi(ValueList.GetAt(10)));
		OnCbnSelchangeComboO();
		m_Check_OS.SetCheck(atoi(ValueList.GetAt(11)));
		OnBnClickedCheckOs();
		m_Edit_D.SetWindowText(ValueList.GetAt(12));
		m_Edit_TT.SetWindowText(ValueList.GetAt(13));

		SetDoWValue(ValueList.GetAt(2));

		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}

	
}
//2
void DCowh_Dlg::OnCbnSelchangeComboM()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_M.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void DCowh_Dlg::OnBnClickedCheckMon()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDoWValue();
}
//3
void DCowh_Dlg::GetDoWValue()
{
	int iMon=0,iTue=0,iWed=0,iThu=0,iFri=0,iSat=0,iSun=0;
	CString sStrB="",sStrH="",sCmd="",sNewCmd="";

	iMon=m_Check_Mon.GetCheck();
	iTue=m_Check_Tue.GetCheck();
	iWed=m_Check_Wed.GetCheck();
	iThu=m_Check_Thu.GetCheck();
	iFri=m_Check_Fri.GetCheck();
	iSat=m_Check_Sat.GetCheck();
	iSun=m_Check_Sun.GetCheck();

	sStrB.Format("%d%d%d%d%d%d%d",iSun,iSat,iFri,iThu,iWed,iTue,iMon);
	m_MYWORK.BsToHex2Bit(sStrB,sStrH);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStrH,2,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void DCowh_Dlg::SetDoWValue(CString sStrH)
{
	CString sStrB="",sTemp="";
	int iB0=0,iB1=0,iB2=0,iB3=0,iB4=0,iB5=0,iB6=0;
	m_MYWORK.HexToBsStr(sStrH,sStrB,7);
	sTemp.Format("%c",sStrB[0]);
	iB6=atoi(sTemp);
	m_Check_Sun.SetCheck(iB6);
	sTemp.Format("%c",sStrB[1]);
	iB5=atoi(sTemp);
	m_Check_Sat.SetCheck(iB5);
	sTemp.Format("%c",sStrB[2]);
	iB4=atoi(sTemp);
	m_Check_Fri.SetCheck(iB4);
	sTemp.Format("%c",sStrB[3]);
	iB3=atoi(sTemp);
	m_Check_Thu.SetCheck(iB3);
	sTemp.Format("%c",sStrB[4]);
	iB2=atoi(sTemp);
	m_Check_Wed.SetCheck(iB2);
	sTemp.Format("%c",sStrB[5]);
	iB1=atoi(sTemp);
	m_Check_Tue.SetCheck(iB1);
	sTemp.Format("%c",sStrB[6]);
	iB0=atoi(sTemp);
	m_Check_Mon.SetCheck(iB0);

	GetDoWValue();
}


void DCowh_Dlg::OnBnClickedCheckTue()
{
	GetDoWValue();
}


void DCowh_Dlg::OnBnClickedCheckWed()
{
	GetDoWValue();
}


void DCowh_Dlg::OnBnClickedCheckThu()
{
	GetDoWValue();
}


void DCowh_Dlg::OnBnClickedCheckFri()
{
	GetDoWValue();
}


void DCowh_Dlg::OnBnClickedCheckSat()
{
	GetDoWValue();
}


void DCowh_Dlg::OnBnClickedCheckSun()
{
	GetDoWValue();
}


void DCowh_Dlg::OnBnClickedCheckca()
{
	int iTemp=0;
	iTemp=m_Check_ca.GetCheck();
	if (iTemp)
	{
		m_Check_Mon.SetCheck(1);
		m_Check_Tue.SetCheck(1);
		m_Check_Wed.SetCheck(1);
		m_Check_Thu.SetCheck(1);
		m_Check_Fri.SetCheck(1);
		m_Check_Sat.SetCheck(1);
		m_Check_Sun.SetCheck(1);
	}
	else
	{
		m_Check_Mon.SetCheck(0);
		m_Check_Tue.SetCheck(0);
		m_Check_Wed.SetCheck(0);
		m_Check_Thu.SetCheck(0);
		m_Check_Fri.SetCheck(0);
		m_Check_Sat.SetCheck(0);
		m_Check_Sun.SetCheck(0);
	}
   GetDoWValue();
}

//4
void DCowh_Dlg::OnEnChangeEditWhs1()
{
	CString sStr="",sGTBSI="",sNewGTBSI="";
	m_Edit_WHS1.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sGTBSI);
	sNewGTBSI=UpdataCMD(sStr,3,sGTBSI);
	m_Edit_GTCMD.SetWindowText(sNewGTBSI);
}

//6
void DCowh_Dlg::OnEnChangeEditWhs2()
{
	CString sStr="",sGTBSI="",sNewGTBSI="";
	m_Edit_WHS2.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sGTBSI);
	sNewGTBSI=UpdataCMD(sStr,5,sGTBSI);
	m_Edit_GTCMD.SetWindowText(sNewGTBSI);
}

//5
void DCowh_Dlg::OnEnChangeEditWhe1()
{
	CString sStr="",sGTBSI="",sNewGTBSI="";
	m_Edit_WHE1.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sGTBSI);
	sNewGTBSI=UpdataCMD(sStr,4,sGTBSI);
	m_Edit_GTCMD.SetWindowText(sNewGTBSI);
}

//7
void DCowh_Dlg::OnEnChangeEditWhe2()
{
	CString sStr="",sGTBSI="",sNewGTBSI="";
	m_Edit_WHE2.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sGTBSI);
	sNewGTBSI=UpdataCMD(sStr,6,sGTBSI);
	m_Edit_GTCMD.SetWindowText(sNewGTBSI);
}

//10
void DCowh_Dlg::OnCbnSelchangeComboD()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_D.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,9,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//11
void DCowh_Dlg::OnCbnSelchangeComboO()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_O.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,10,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//12
void DCowh_Dlg::OnBnClickedCheckOs()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_OS.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,11,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void DCowh_Dlg::OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D.GetPos();
	m_Spin_D.SetPos(iTemp);
	m_Edit_D.GetWindowText(strValue);  
	*pResult = 0;
}

//13
void DCowh_Dlg::OnEnChangeEditD()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_D.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=UpdataCMD(sStr,12,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void DCowh_Dlg::OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT.GetPos();
	m_Spin_TT.SetPos(iTemp);
	m_Edit_TT.GetWindowText(strValue);  
	*pResult = 0;
}

//14
void DCowh_Dlg::OnEnChangeEditTt()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TT.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=UpdataCMD(sStr,13,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

