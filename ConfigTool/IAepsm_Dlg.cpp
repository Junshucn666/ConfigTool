// IAepsm_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "IAepsm_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern IAepsm_Dlg m_IAepsm_Dlg;
IAepsm_Dlg*	lpIAepsm_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(IAepsm_Dlg, CMyTabBaseDlg)

IAepsm_Dlg::IAepsm_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(IAepsm_Dlg::IDD, pParent)
{

}

IAepsm_Dlg::~IAepsm_Dlg()
{
}

void IAepsm_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_SPIN_MT1, m_Spin_MT1);
	DDX_Control(pDX, IDC_SPIN_MT2, m_Spin_MT2);
	DDX_Control(pDX, IDC_SPIN_SP, m_Spin_SP);
	DDX_Control(pDX, IDC_SPIN_DT, m_Spin_DT);
	DDX_Control(pDX, IDC_SPIN_MVT, m_Spin_MVT);
	DDX_Control(pDX, IDC_EDIT_MT1, m_Edit_MT1);
	DDX_Control(pDX, IDC_EDIT_MT2, m_Edit_MT2);
	DDX_Control(pDX, IDC_EDIT_SP, m_Edit_SP);
	DDX_Control(pDX, IDC_EDIT_DT, m_Edit_DT);
	DDX_Control(pDX, IDC_EDIT_MVT, m_Edit_MVT);
	DDX_Control(pDX, IDC_COMBO_OI, m_ComboBox_OI);
	DDX_Control(pDX, IDC_CHECK_OutS, m_Check_OutS);
	DDX_Control(pDX, IDC_SPIN_D, m_Spin_D);
	DDX_Control(pDX, IDC_SPIN_TT, m_Spin_TT);
	DDX_Control(pDX, IDC_EDIT_D, m_Edit_D);
	DDX_Control(pDX, IDC_EDIT_TT, m_Edit_TT);
	DDX_Control(pDX, IDC_CHECK_SWF, m_Check_SWF);
	DDX_Control(pDX, IDC_COMBO_SWF, m_ComboBox_SWF);
}


BEGIN_MESSAGE_MAP(IAepsm_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &IAepsm_Dlg::OnCbnSelchangeComboM)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MT1, &IAepsm_Dlg::OnDeltaposSpinMt1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_SP, &IAepsm_Dlg::OnDeltaposSpinSp)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_DT, &IAepsm_Dlg::OnDeltaposSpinDt)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MT2, &IAepsm_Dlg::OnDeltaposSpinMt2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MVT, &IAepsm_Dlg::OnDeltaposSpinMvt)
	ON_EN_CHANGE(IDC_EDIT_SP, &IAepsm_Dlg::OnEnChangeEditSp)
	ON_EN_CHANGE(IDC_EDIT_MT1, &IAepsm_Dlg::OnEnChangeEditMt1)
	ON_EN_CHANGE(IDC_EDIT_DT, &IAepsm_Dlg::OnEnChangeEditDt)
	ON_EN_CHANGE(IDC_EDIT_MVT, &IAepsm_Dlg::OnEnChangeEditMvt)
	ON_EN_CHANGE(IDC_EDIT_MT2, &IAepsm_Dlg::OnEnChangeEditMt2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D, &IAepsm_Dlg::OnDeltaposSpinD)
	ON_CBN_SELCHANGE(IDC_COMBO_OI, &IAepsm_Dlg::OnCbnSelchangeComboOi)
	ON_BN_CLICKED(IDC_CHECK_OutS, &IAepsm_Dlg::OnBnClickedCheckOuts)
	ON_EN_CHANGE(IDC_EDIT_D, &IAepsm_Dlg::OnEnChangeEditD)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT, &IAepsm_Dlg::OnDeltaposSpinTt)
	ON_EN_CHANGE(IDC_EDIT_TT, &IAepsm_Dlg::OnEnChangeEditTt)
	ON_CBN_SELCHANGE(IDC_COMBO_SWF, &IAepsm_Dlg::OnCbnSelchangeComboSwf)
	ON_BN_CLICKED(IDC_CHECK_SWF, &IAepsm_Dlg::OnBnClickedCheckSwf)
END_MESSAGE_MAP()


// IAepsm_Dlg 消息处理程序


BOOL IAepsm_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpIAepsm_Dlg=&m_IAepsm_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_IAepsm_Dlg;
	m_iWhoamI=GTEPS;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTEPS].sCmdstr);

	m_ComboBox_M.InsertString(0,"0: Disable the External Power Supply Monitoring Settings");
	m_ComboBox_M.InsertString(1,"1: Enable If the current voltage is within the range of (<Min Threshold>, <Max Threshold>)");
	m_ComboBox_M.InsertString(2,"2: Enable If the current voltage is outside the range of (<Min Threshold>, <Max Threshold>)");
	m_ComboBox_M.InsertString(3,"3: Enable If the current voltage is within or outside the range of (<Min Threshold>, <Max Threshold>)");
	m_ComboBox_M.SetCurSel(0);
	///////////////
	SetDlgItemText(IDC_EDIT_MT1,"250");
	m_Spin_MT1.SetBuddy(GetDlgItem(IDC_EDIT_MT1)); //得到指向编辑框的窗口指针
	m_Spin_MT1.SetRange(250,32000);
	SetDlgItemText(IDC_EDIT_MT2,"450");
	m_Spin_MT2.SetBuddy(GetDlgItem(IDC_EDIT_MT2)); //得到指向编辑框的窗口指针
	m_Spin_MT2.SetRange(450,32000);
	//SetDlgItemText(IDC_EDIT_SP,"250");
	//m_Spin_SP.SetBuddy(GetDlgItem(IDC_EDIT_SP)); //得到指向编辑框的窗口指针
	//m_Spin_SP.SetRange(250,32000);
	SetDlgItemText(IDC_EDIT_DT,"0");
	m_Spin_DT.SetBuddy(GetDlgItem(IDC_EDIT_DT)); //得到指向编辑框的窗口指针
	m_Spin_DT.SetRange(0,250);

	SetDlgItemText(IDC_EDIT_MVT,"200");
	m_Spin_MVT.SetBuddy(GetDlgItem(IDC_EDIT_MVT)); //得到指向编辑框的窗口指针
	m_Spin_MVT.SetRange(0,2000);
	///////////////
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

	m_ComboBox_SWF.InsertString(0,"0: Do not report external power supply voltage with fixed message");
	m_ComboBox_SWF.InsertString(1,"1: Report external power supply voltage with fixed message");
	m_ComboBox_SWF.SetCurSel(0);
	///////////////
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}



CString IAepsm_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL IAepsm_Dlg::UpdataPage(CString sStr)
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
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboM();
		m_Edit_MT1.SetWindowText(ValueList.GetAt(2));
		m_Edit_MT2.SetWindowText(ValueList.GetAt(3));
		m_Edit_DT.SetWindowText(ValueList.GetAt(5));

		m_ComboBox_OI.SetCurSel(atoi(ValueList.GetAt(6)));
		OnCbnSelchangeComboOi();
		m_Check_OutS.SetCheck(atoi(ValueList.GetAt(7)));
		OnBnClickedCheckOuts();
		m_Edit_D.SetWindowText(ValueList.GetAt(8));
		m_Edit_TT.SetWindowText(ValueList.GetAt(9));

		m_ComboBox_SWF.SetCurSel(atoi(ValueList.GetAt(10)));
		OnCbnSelchangeComboSwf();
		m_Edit_MVT.SetWindowText(ValueList.GetAt(11));

		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}

void IAepsm_Dlg::OnCbnSelchangeComboM()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_M.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void IAepsm_Dlg::OnDeltaposSpinMt1(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_MT1.GetPos();
	m_Spin_MT1.SetPos(iTemp);
	m_Edit_MT1.GetWindowText(strValue);  
	*pResult = 0;
}

void IAepsm_Dlg::OnDeltaposSpinMt2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_MT2.GetPos();
	m_Spin_MT2.SetPos(iTemp);
	m_Edit_MT2.GetWindowText(strValue);  
	*pResult = 0;
}

void IAepsm_Dlg::OnDeltaposSpinSp(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_SP.GetPos();
	m_Spin_SP.SetPos(iTemp);
	m_Edit_SP.GetWindowText(strValue);  
	*pResult = 0;
}


void IAepsm_Dlg::OnDeltaposSpinDt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_DT.GetPos();
	m_Spin_DT.SetPos(iTemp);
	m_Edit_DT.GetWindowText(strValue);  
	*pResult = 0;
}

void IAepsm_Dlg::OnDeltaposSpinMvt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_MVT.GetPos();
	m_Spin_MVT.SetPos(iTemp);
	m_Edit_MVT.GetWindowText(strValue);  
	*pResult = 0;
}


void IAepsm_Dlg::OnEnChangeEditSp()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CMyTabBaseDlg::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

//3
void IAepsm_Dlg::OnEnChangeEditMt1()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_MT1.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,2,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//4
void IAepsm_Dlg::OnEnChangeEditMt2()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_MT2.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,3,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//6
void IAepsm_Dlg::OnEnChangeEditDt()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_DT.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,5,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//12
void IAepsm_Dlg::OnEnChangeEditMvt()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_MVT.GetWindowText(sStr);
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
	sNewCmd=m_MYWORK.UpdataCMD(strDigit,11,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//7
void IAepsm_Dlg::OnCbnSelchangeComboOi()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_OI.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,6,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//8
void IAepsm_Dlg::OnBnClickedCheckOuts()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_OutS.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,7,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void IAepsm_Dlg::OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D.GetPos();
	m_Spin_D.SetPos(iTemp);
	m_Edit_D.GetWindowText(strValue);  
	*pResult = 0;
}

//9
void IAepsm_Dlg::OnEnChangeEditD()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_D.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,8,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void IAepsm_Dlg::OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT.GetPos();
	m_Spin_TT.SetPos(iTemp);
	m_Edit_TT.GetWindowText(strValue);  
	*pResult = 0;
}

//10
void IAepsm_Dlg::OnEnChangeEditTt()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TT.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,9,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//11
void IAepsm_Dlg::OnCbnSelchangeComboSwf()
{

	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_SWF.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,10,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//11
void IAepsm_Dlg::OnBnClickedCheckSwf()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_SWF.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,10,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


