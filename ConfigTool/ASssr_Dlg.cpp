// ASssr_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ASssr_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern ASssr_Dlg m_ASssr_Dlg;
ASssr_Dlg*	lpASssr_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(ASssr_Dlg, CMyTabBaseDlg)

ASssr_Dlg::ASssr_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(ASssr_Dlg::IDD, pParent)
{

}

ASssr_Dlg::~ASssr_Dlg()
{
}

void ASssr_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_SPIN_Stop, m_Spin_Stop);
	DDX_Control(pDX, IDC_SPIN_Start, m_Spin_Start);
	DDX_Control(pDX, IDC_SPIN_SS, m_Spin_SS);
	DDX_Control(pDX, IDC_SPIN_LS, m_Spin_LS);
	DDX_Control(pDX, IDC_EDIT_Stop, m_Edit_Stop);
	DDX_Control(pDX, IDC_EDIT_Start, m_Edit_Start);
	DDX_Control(pDX, IDC_EDIT_SS, m_Edit_SS);
	DDX_Control(pDX, IDC_EDIT_LS, m_Edit_LS);
	DDX_Control(pDX, IDC_COMBO_TU, m_ComboBox_TU);
}


BEGIN_MESSAGE_MAP(ASssr_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &ASssr_Dlg::OnCbnSelchangeComboM)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Stop, &ASssr_Dlg::OnDeltaposSpinStop)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Start, &ASssr_Dlg::OnDeltaposSpinStart)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_SS, &ASssr_Dlg::OnDeltaposSpinSs)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_LS, &ASssr_Dlg::OnDeltaposSpinLs)
	ON_EN_CHANGE(IDC_EDIT_Stop, &ASssr_Dlg::OnEnChangeEditStop)
	ON_EN_CHANGE(IDC_EDIT_Start, &ASssr_Dlg::OnEnChangeEditStart)
	ON_EN_CHANGE(IDC_EDIT_SS, &ASssr_Dlg::OnEnChangeEditSs)
	ON_EN_CHANGE(IDC_EDIT_LS, &ASssr_Dlg::OnEnChangeEditLs)
	ON_CBN_SELCHANGE(IDC_COMBO_TU, &ASssr_Dlg::OnCbnSelchangeComboTu)
END_MESSAGE_MAP()


// ASssr_Dlg 消息处理程序


BOOL ASssr_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpASssr_Dlg=&m_ASssr_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_AScd_Dlg;
	m_iWhoamI=GTSSR;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTSSR].sCmdstr);

	m_ComboBox_M.InsertString(0,"0: Disable this function");
	m_ComboBox_M.InsertString(1,"1: Enable this function");
	m_ComboBox_M.SetCurSel(0);

	m_ComboBox_TU.InsertString(0,"0: The unit is minute.");
	m_ComboBox_TU.InsertString(1,"1: The unit is second");
	m_ComboBox_TU.SetCurSel(0);
	///////////////
	SetDlgItemText(IDC_EDIT_Stop,"2");
	m_Spin_Stop.SetBuddy(GetDlgItem(IDC_EDIT_Stop)); //得到指向编辑框的窗口指针
	m_Spin_Stop.SetRange(0,30);

	SetDlgItemText(IDC_EDIT_Start,"1");
	m_Spin_Start.SetBuddy(GetDlgItem(IDC_EDIT_Start)); //得到指向编辑框的窗口指针
	m_Spin_Start.SetRange(1,5);

	SetDlgItemText(IDC_EDIT_SS,"5");
	m_Spin_SS.SetBuddy(GetDlgItem(IDC_EDIT_SS)); //得到指向编辑框的窗口指针
	m_Spin_SS.SetRange(1,10);

	SetDlgItemText(IDC_EDIT_LS,"0");
	m_Spin_LS.SetBuddy(GetDlgItem(IDC_EDIT_LS)); //得到指向编辑框的窗口指针
	m_Spin_LS.SetRange32(0,43200);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString ASssr_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL ASssr_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>6)
	{
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboM();		
		m_Edit_Stop.SetWindowText(ValueList.GetAt(2));
		m_Edit_Start.SetWindowText(ValueList.GetAt(3));	
		m_Edit_SS.SetWindowText(ValueList.GetAt(4));
		m_Edit_LS.SetWindowText(ValueList.GetAt(5));
		m_ComboBox_TU.SetCurSel(atoi(ValueList.GetAt(6)));
		OnCbnSelchangeComboTu();	

		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}

}

void ASssr_Dlg::OnCbnSelchangeComboM()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_M.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void ASssr_Dlg::OnDeltaposSpinStop(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_Stop.GetPos();
	m_Spin_Stop.SetPos(iTemp);
	m_Edit_Stop.GetWindowText(strValue);  
	*pResult = 0;
}


void ASssr_Dlg::OnDeltaposSpinStart(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_Start.GetPos();
	m_Spin_Start.SetPos(iTemp);
	m_Edit_Start.GetWindowText(strValue);  
	*pResult = 0;
}


void ASssr_Dlg::OnDeltaposSpinSs(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_SS.GetPos();
	m_Spin_SS.SetPos(iTemp);
	m_Edit_SS.GetWindowText(strValue);  
	*pResult = 0;
}


void ASssr_Dlg::OnDeltaposSpinLs(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_LS.GetPos();
	m_Spin_LS.SetPos(iTemp);
	m_Edit_LS.GetWindowText(strValue);  
	*pResult = 0;
}

//3
void ASssr_Dlg::OnEnChangeEditStop()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_Stop.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,2,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//4
void ASssr_Dlg::OnEnChangeEditStart()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_Start.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,3,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//5
void ASssr_Dlg::OnEnChangeEditSs()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_SS.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,4,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//6
void ASssr_Dlg::OnEnChangeEditLs()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_LS.GetWindowText(sStr);
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
	sNewCmd=m_MYWORK.UpdataCMD(strDigit,5,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//7
void ASssr_Dlg::OnCbnSelchangeComboTu()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_TU.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,6,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}
