// AStac_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "AStac_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern AStac_Dlg m_AStac_Dlg;
AStac_Dlg*	lpAStac_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(AStac_Dlg, CMyTabBaseDlg)

AStac_Dlg::AStac_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(AStac_Dlg::IDD, pParent)
{

}

AStac_Dlg::~AStac_Dlg()
{
}

void AStac_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN_Eott, m_Spin_Eott);
	DDX_Control(pDX, IDC_EDIT_Eott, m_Edit_Eott);
	DDX_Control(pDX, IDC_CHECK_TE, m_Check_TE);
	DDX_Control(pDX, IDC_SPIN_FTD, m_Spin_FTD);
	DDX_Control(pDX, IDC_EDIT_FTD, m_Edit_FTD);
	DDX_Control(pDX, IDC_SPIN_TI, m_Spin_TI);
	DDX_Control(pDX, IDC_EDIT_TI, m_Edit_TI);
	DDX_Control(pDX, IDC_COMBO_TOI, m_ComboBox_TOI);
	DDX_Control(pDX, IDC_CHECK_TOS, m_Check_TOS);
	DDX_Control(pDX, IDC_SPIN_TOD, m_Spin_TOD);
	DDX_Control(pDX, IDC_EDIT_TOD, m_Edit_TOD);
	DDX_Control(pDX, IDC_SPIN_TOTT, m_Spin_TOTT);
	DDX_Control(pDX, IDC_EDIT_TOTT, m_Edit_TOTT);
	DDX_Control(pDX, IDC_SPIN_RD, m_Spin_RD);
	DDX_Control(pDX, IDC_EDIT_RD, m_Edit_RD);
	DDX_Control(pDX, IDC_SPIN_MD, m_Spin_MD);
	DDX_Control(pDX, IDC_EDIT_MD, m_Edit_MD);
	DDX_Control(pDX, IDC_COMBO_MT, m_ComboBox_MT);
}


BEGIN_MESSAGE_MAP(AStac_Dlg, CMyTabBaseDlg)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Eott, &AStac_Dlg::OnDeltaposSpinEott)
	ON_BN_CLICKED(IDC_CHECK_TE, &AStac_Dlg::OnBnClickedCheckTe)
	ON_EN_CHANGE(IDC_EDIT_GTTOW, &AStac_Dlg::OnEnChangeEditGttow)
	ON_EN_CHANGE(IDC_EDIT_Eott, &AStac_Dlg::OnEnChangeEditEott)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_FTD, &AStac_Dlg::OnDeltaposSpinFtd)
	ON_EN_CHANGE(IDC_EDIT_FTD, &AStac_Dlg::OnEnChangeEditFtd)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TI, &AStac_Dlg::OnDeltaposSpinTi)
	ON_EN_CHANGE(IDC_EDIT_TI, &AStac_Dlg::OnEnChangeEditTi)
	ON_CBN_SELCHANGE(IDC_COMBO_TOI, &AStac_Dlg::OnCbnSelchangeComboToi)
	ON_BN_CLICKED(IDC_CHECK_TOS, &AStac_Dlg::OnBnClickedCheckTos)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TOD, &AStac_Dlg::OnDeltaposSpinTod)
	ON_EN_CHANGE(IDC_EDIT_TOD, &AStac_Dlg::OnEnChangeEditTod)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TOTT, &AStac_Dlg::OnDeltaposSpinTott)
	ON_EN_CHANGE(IDC_EDIT_TOTT, &AStac_Dlg::OnEnChangeEditTott)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_RD, &AStac_Dlg::OnDeltaposSpinRd)
	ON_EN_CHANGE(IDC_EDIT_RD, &AStac_Dlg::OnEnChangeEditRd)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MD, &AStac_Dlg::OnDeltaposSpinMd)
	ON_EN_CHANGE(IDC_EDIT_MD, &AStac_Dlg::OnEnChangeEditMd)
	ON_CBN_SELCHANGE(IDC_COMBO_MT, &AStac_Dlg::OnCbnSelchangeComboMt)
END_MESSAGE_MAP()


// AStac_Dlg 消息处理程序


BOOL AStac_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpAStac_Dlg=&m_AStac_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_AStac_Dlg;
	m_iWhoamI=GTTOW;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTTOW].sCmdstr);
	                             //AT+GTTOW=HYIoT,0,120,120,,0,0,0,0,,,,,,,,,,,,FFFF$
	                             //AT+GTTOW=HYIoT,0,10,1,300,0,0,0,0,2,3,,,,,,,,,,FFFF$

	SetDlgItemText(IDC_EDIT_Eott,"10");
	m_Spin_Eott.SetBuddy(GetDlgItem(IDC_EDIT_Eott)); //得到指向编辑框的窗口指针
	m_Spin_Eott.SetRange(5,15);

	SetDlgItemText(IDC_EDIT_FTD,"1");
	m_Spin_FTD.SetBuddy(GetDlgItem(IDC_EDIT_FTD)); //得到指向编辑框的窗口指针
	m_Spin_FTD.SetRange(0,10);

	SetDlgItemText(IDC_EDIT_TI,"300");
	m_Spin_TI.SetBuddy(GetDlgItem(IDC_EDIT_TI)); //得到指向编辑框的窗口指针
	m_Spin_TI.SetRange32(30,86400);

	m_ComboBox_TOI.InsertString(0,"0");
	m_ComboBox_TOI.InsertString(1,"1");
	m_ComboBox_TOI.InsertString(2,"2");
	m_ComboBox_TOI.SetCurSel(0);

	SetDlgItemText(IDC_EDIT_TOD,"0");
	m_Spin_TOD.SetBuddy(GetDlgItem(IDC_EDIT_TOD)); //得到指向编辑框的窗口指针
	m_Spin_TOD.SetRange(0,255);

	SetDlgItemText(IDC_EDIT_TOTT,"0");
	m_Spin_TOTT.SetBuddy(GetDlgItem(IDC_EDIT_TOTT)); //得到指向编辑框的窗口指针
	m_Spin_TOTT.SetRange(0,255);

	SetDlgItemText(IDC_EDIT_RD,"2");
	m_Spin_RD.SetBuddy(GetDlgItem(IDC_EDIT_RD)); //得到指向编辑框的窗口指针
	m_Spin_RD.SetRange(1,255);

	SetDlgItemText(IDC_EDIT_MD,"3");
	m_Spin_MD.SetBuddy(GetDlgItem(IDC_EDIT_MD)); //得到指向编辑框的窗口指针
	m_Spin_MD.SetRange(1,10);

	m_ComboBox_MT.InsertString(0,"2");
	m_ComboBox_MT.InsertString(1,"3");
	m_ComboBox_MT.InsertString(2,"4");
	m_ComboBox_MT.SetCurSel(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString AStac_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
{   //位置iPos是从0开始的
	CString sNewCmd="",sRight="",sLeft="",sTemp="";
	CArray<CString,CString>ValueList;
	int index1=0,index2=0;
	sTemp=sParestr;//准备分割
	for (int i=0;i<100;i++)
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

BOOL AStac_Dlg::UpdataPage(CString sStr)
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
		m_Edit_Eott.SetWindowText(ValueList.GetAt(2));
		m_Edit_FTD.SetWindowText(ValueList.GetAt(3));
		m_Edit_TI.SetWindowText(ValueList.GetAt(4));
		m_Check_TE.SetCheck(atoi(ValueList.GetAt(1)));
		OnBnClickedCheckTe();

		m_ComboBox_TOI.SetCurSel(atoi(ValueList.GetAt(5)));
		OnCbnSelchangeComboToi();
		m_Check_TOS.SetCheck(atoi(ValueList.GetAt(6)));
		OnBnClickedCheckTos();
		m_Edit_TOD.SetWindowText(ValueList.GetAt(7));
		m_Edit_TOTT.SetWindowText(ValueList.GetAt(8));
		m_Edit_RD.SetWindowText(ValueList.GetAt(9));
		m_Edit_MD.SetWindowText(ValueList.GetAt(10));

		m_ComboBox_MT.SetCurSel(atoi(ValueList.GetAt(11)));
		OnCbnSelchangeComboMt();
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}

void AStac_Dlg::OnDeltaposSpinEott(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_Eott.GetPos();
	m_Spin_Eott.SetPos(iTemp);
	m_Edit_Eott.GetWindowText(strValue);  
	*pResult = 0;
}

//2
void AStac_Dlg::OnBnClickedCheckTe()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_TE.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void AStac_Dlg::OnEnChangeEditGttow()
{
	CString sTemp="";
	m_Edit_GTCMD.GetWindowText(sTemp);
	if (sTemp!=stu_ConfigCMD.tdWriteCmds[GTTOW].sCmdstr) stu_ConfigCMD.tdWriteCmds[GTTOW].sCmdstr=sTemp;
}

//3
void AStac_Dlg::OnEnChangeEditEott()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_Eott.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,2,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void AStac_Dlg::OnDeltaposSpinFtd(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_FTD.GetPos();
	m_Spin_FTD.SetPos(iTemp);
	m_Edit_FTD.GetWindowText(strValue);  
	*pResult = 0;
}

//4
void AStac_Dlg::OnEnChangeEditFtd()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_FTD.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,3,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void AStac_Dlg::OnDeltaposSpinTi(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TI.GetPos();
	m_Spin_TI.SetPos(iTemp);
	m_Edit_TI.GetWindowText(strValue);  
	*pResult = 0;
}

//5
void AStac_Dlg::OnEnChangeEditTi()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_TI.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{      
		for( int i=0;i < sStr.GetLength(); i++)
		{
			if(sStr.GetAt(i)>='0' &&  sStr.GetAt(i)<='9')
			{
				strDigit += sStr.GetAt(i);
			}
		}
	}
	else
	{
		strDigit=sStr;
	}
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(strDigit,4,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//6
void AStac_Dlg::OnCbnSelchangeComboToi()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_TOI.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,5,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//7
void AStac_Dlg::OnBnClickedCheckTos()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_TOS.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,6,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void AStac_Dlg::OnDeltaposSpinTod(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TOD.GetPos();
	m_Spin_TOD.SetPos(iTemp);
	m_Edit_TOD.GetWindowText(strValue);  
	*pResult = 0;
}

//8
void AStac_Dlg::OnEnChangeEditTod()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TOD.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,7,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void AStac_Dlg::OnDeltaposSpinTott(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TOTT.GetPos();
	m_Spin_TOTT.SetPos(iTemp);
	m_Edit_TOTT.GetWindowText(strValue);  
	*pResult = 0;
}

//9
void AStac_Dlg::OnEnChangeEditTott()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TOTT.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,8,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void AStac_Dlg::OnDeltaposSpinRd(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_RD.GetPos();
	m_Spin_RD.SetPos(iTemp);
	m_Edit_RD.GetWindowText(strValue);  
	*pResult = 0;
}

//10
void AStac_Dlg::OnEnChangeEditRd()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_RD.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,9,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void AStac_Dlg::OnDeltaposSpinMd(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_MD.GetPos();
	m_Spin_MD.SetPos(iTemp);
	m_Edit_MD.GetWindowText(strValue);  
	*pResult = 0;
}

//11
void AStac_Dlg::OnEnChangeEditMd()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_MD.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,10,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//12
void AStac_Dlg::OnCbnSelchangeComboMt()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_MT.GetCurSel();
	if (iTemp==0)
	{
       sStr="2";
	}
	else if (iTemp==1)
	{
		 sStr="3";
	}
	else if (iTemp==2)
	{
		sStr="4";
	}
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,11,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

