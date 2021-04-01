// PRRfcofri_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "PRRfcofri_Dlg.h"
#include "afxdialogex.h"
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern PRRfcofri_Dlg m_PRRfcofri_Dlg;
PRRfcofri_Dlg*	lpPRRfcofri_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(PRRfcofri_Dlg, CMyTabBaseDlg)

PRRfcofri_Dlg::PRRfcofri_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(PRRfcofri_Dlg::IDD, pParent)
{

}

PRRfcofri_Dlg::~PRRfcofri_Dlg()
{
}

void PRRfcofri_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_P, m_ComboBox_P);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_COMBO_FM, m_ComboBox_FM);
	DDX_Control(pDX, IDC_SPIN_FIR, m_Spin_FIR);
	DDX_Control(pDX, IDC_EDIT_FIR, m_Edit_FIR);
	DDX_Control(pDX, IDC_SPIN_FRD, m_Spin_FRD);
	DDX_Control(pDX, IDC_EDIT_FRD, m_Edit_FRD);
	DDX_Control(pDX, IDC_SPIN_FRM, m_Spin_FRM);
	DDX_Control(pDX, IDC_EDIT_FRM, m_Edit_FRM);
	DDX_Control(pDX, IDC_SPIN_FIR2, m_Spin_FIR2);
	DDX_Control(pDX, IDC_EDIT_FIR2, m_Edit_FIR2);
	DDX_Control(pDX, IDC_SPIN_CR, m_Spin_CR);
	DDX_Control(pDX, IDC_EDIT_CR, m_Edit_CR);
}


BEGIN_MESSAGE_MAP(PRRfcofri_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_P, &PRRfcofri_Dlg::OnCbnSelchangeComboP)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &PRRfcofri_Dlg::OnCbnSelchangeComboM)
	ON_CBN_SELCHANGE(IDC_COMBO_FM, &PRRfcofri_Dlg::OnCbnSelchangeComboFm)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_FIR, &PRRfcofri_Dlg::OnDeltaposSpinFir)
	ON_EN_CHANGE(IDC_EDIT_FIR, &PRRfcofri_Dlg::OnEnChangeEditFir)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_FRD, &PRRfcofri_Dlg::OnDeltaposSpinFrd)
	ON_EN_CHANGE(IDC_EDIT_FRD, &PRRfcofri_Dlg::OnEnChangeEditFrd)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_FRM, &PRRfcofri_Dlg::OnDeltaposSpinFrm)
	ON_EN_CHANGE(IDC_EDIT_FRM, &PRRfcofri_Dlg::OnEnChangeEditFrm)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_FIR2, &PRRfcofri_Dlg::OnDeltaposSpinFir2)
	ON_EN_CHANGE(IDC_EDIT_FIR2, &PRRfcofri_Dlg::OnEnChangeEditFir2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_CR, &PRRfcofri_Dlg::OnDeltaposSpinCr)
	ON_EN_CHANGE(IDC_EDIT_CR, &PRRfcofri_Dlg::OnEnChangeEditCr)
END_MESSAGE_MAP()


// PRRfcofri_Dlg 消息处理程序


BOOL PRRfcofri_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpPRRfcofri_Dlg=&m_PRRfcofri_Dlg;//窗口寻址
	m_lpMyTabBaseDlg=&m_PRRfcofri_Dlg;
	m_iWhoamI=GTFFC;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTFFC].sCmdstr);

	m_ComboBox_P.InsertString(0,"0");
	m_ComboBox_P.InsertString(1,"1");
	m_ComboBox_P.InsertString(2,"2");
	m_ComboBox_P.InsertString(3,"3");
	m_ComboBox_P.InsertString(4,"4");
	m_ComboBox_P.SetCurSel(0);

	m_ComboBox_M.InsertString(0,"0: Disable the parameters in the specified priority");
	m_ComboBox_M.InsertString(1,"1: Change the fixed report parameter when the device enters into any of the defined Geo-Fence");
	m_ComboBox_M.InsertString(2,"2: Change the fixed report parameter when the device enters into known roaming state");
	m_ComboBox_M.InsertString(3,"3: Change the fixed report parameter when the device enters into unknown roaming state");
	m_ComboBox_M.SetCurSel(0);

	m_ComboBox_FM.InsertString(0,"0: Do not change the working mode");
	m_ComboBox_FM.InsertString(1,"1: Change the working mode to ‘Timing Report’");
	m_ComboBox_FM.InsertString(2,"2: Change the working mode to ‘Distance Report’");
	m_ComboBox_FM.InsertString(3,"3: Change the working mode to ‘Mileage Report’");
	m_ComboBox_FM.InsertString(4,"4: Change the working mode to ‘Optimum Report’");
	m_ComboBox_FM.InsertString(5,"5: Change the working mode to ‘Fixed Time or Mileage Report’");
	m_ComboBox_FM.SetCurSel(0);

	SetDlgItemText(IDC_EDIT_FIR,"30");
	m_Spin_FIR.SetBuddy(GetDlgItem(IDC_EDIT_FIR)); //得到指向编辑框的窗口指针
	m_Spin_FIR.SetRange32(5,86400);

	SetDlgItemText(IDC_EDIT_FIR2,"300");
	m_Spin_FIR2.SetBuddy(GetDlgItem(IDC_EDIT_FIR2)); //得到指向编辑框的窗口指针
	m_Spin_FIR2.SetRange32(5,86400);

	SetDlgItemText(IDC_EDIT_FRD,"500");
	m_Spin_FRD.SetBuddy(GetDlgItem(IDC_EDIT_FRD)); //得到指向编辑框的窗口指针
	m_Spin_FRD.SetRange32(5,65535);

	SetDlgItemText(IDC_EDIT_FRM,"500");
	m_Spin_FRM.SetBuddy(GetDlgItem(IDC_EDIT_FRM)); //得到指向编辑框的窗口指针
	m_Spin_FRM.SetRange32(5,65535);

	SetDlgItemText(IDC_EDIT_CR,"0");
	m_Spin_CR.SetBuddy(GetDlgItem(IDC_EDIT_CR)); //得到指向编辑框的窗口指针
	m_Spin_CR.SetRange(0,180);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString PRRfcofri_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL PRRfcofri_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>9)
	{
		m_ComboBox_P.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboP();

		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(2)));
		OnCbnSelchangeComboM();
		m_ComboBox_FM.SetCurSel(atoi(ValueList.GetAt(3)));
		OnCbnSelchangeComboFm();

		m_Edit_FIR.SetWindowText(ValueList.GetAt(4));
		m_Edit_FRD.SetWindowText(ValueList.GetAt(5));
		m_Edit_FRM.SetWindowText(ValueList.GetAt(6));
		m_Edit_FIR2.SetWindowText(ValueList.GetAt(7));
		m_Edit_CR.SetWindowText(ValueList.GetAt(9));

		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}

}

//2
void PRRfcofri_Dlg::OnCbnSelchangeComboP()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_P.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//3
void PRRfcofri_Dlg::OnCbnSelchangeComboM()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_M.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,2,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//4
void PRRfcofri_Dlg::OnCbnSelchangeComboFm()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_FM.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,3,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void PRRfcofri_Dlg::OnDeltaposSpinFir(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_FIR.GetPos();
	m_Spin_FIR.SetPos(iTemp);
	m_Edit_FIR.GetWindowText(strValue);  
	*pResult = 0;
}

//5
void PRRfcofri_Dlg::OnEnChangeEditFir()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_FIR.GetWindowText(sStr);
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
	sNewCmd=UpdataCMD(strDigit,4,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void PRRfcofri_Dlg::OnDeltaposSpinFrd(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_FRD.GetPos();
	m_Spin_FRD.SetPos(iTemp);
	m_Edit_FRD.GetWindowText(strValue);  
	*pResult = 0;
}

//6
void PRRfcofri_Dlg::OnEnChangeEditFrd()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_FRD.GetWindowText(sStr);
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
	sNewCmd=UpdataCMD(strDigit,5,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void PRRfcofri_Dlg::OnDeltaposSpinFrm(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_FRM.GetPos();
	m_Spin_FRM.SetPos(iTemp);
	m_Edit_FRM.GetWindowText(strValue);  
	*pResult = 0;
}

//7
void PRRfcofri_Dlg::OnEnChangeEditFrm()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_FRM.GetWindowText(sStr);
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
	sNewCmd=UpdataCMD(strDigit,6,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void PRRfcofri_Dlg::OnDeltaposSpinFir2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_FIR2.GetPos();
	m_Spin_FIR2.SetPos(iTemp);
	m_Edit_FIR2.GetWindowText(strValue);  
	*pResult = 0;
}

//8
void PRRfcofri_Dlg::OnEnChangeEditFir2()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_FIR2.GetWindowText(sStr);
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
	sNewCmd=UpdataCMD(strDigit,7,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void PRRfcofri_Dlg::OnDeltaposSpinCr(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_CR.GetPos();
	m_Spin_CR.SetPos(iTemp);
	m_Edit_CR.GetWindowText(strValue);  
	*pResult = 0;
}

//10
void PRRfcofri_Dlg::OnEnChangeEditCr()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_CR.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=UpdataCMD(sStr,9,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

