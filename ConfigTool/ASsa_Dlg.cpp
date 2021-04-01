// ASsa_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ASsa_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern ASsa_Dlg m_ASsa_Dlg;
ASsa_Dlg*	lpASsa_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(ASsa_Dlg, CMyTabBaseDlg)

ASsa_Dlg::ASsa_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(ASsa_Dlg::IDD, pParent)
{

}

ASsa_Dlg::~ASsa_Dlg()
{
}

void ASsa_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_SPIN_MS, m_Spin_MS);
	DDX_Control(pDX, IDC_EDIT_MS, m_Edit_MS);
	DDX_Control(pDX, IDC_SPIN_V, m_Spin_V);
	DDX_Control(pDX, IDC_EDIT_V, m_Edit_V);
	DDX_Control(pDX, IDC_SPIN_MaxS, m_Spin_MaxS);
	DDX_Control(pDX, IDC_EDIT_MaxS, m_Edit_MaxS);
	DDX_Control(pDX, IDC_SPIN_SI, m_Spin_SI);
	DDX_Control(pDX, IDC_EDIT_SI, m_Edit_SI);
	DDX_Control(pDX, IDC_COMBO_OI, m_ComboBox_OI);
	DDX_Control(pDX, IDC_CHECK_OutS, m_Check_OS);
	DDX_Control(pDX, IDC_SPIN_D, m_Spin_D);
	DDX_Control(pDX, IDC_EDIT_D, m_Edit_D);
	DDX_Control(pDX, IDC_SPIN_TT, m_Spin_TT);
	DDX_Control(pDX, IDC_EDIT_TT, m_Edit_TT);
}


BEGIN_MESSAGE_MAP(ASsa_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &ASsa_Dlg::OnCbnSelchangeComboM)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MS, &ASsa_Dlg::OnDeltaposSpinMs)
	ON_EN_CHANGE(IDC_EDIT_MS, &ASsa_Dlg::OnEnChangeEditMs)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_V, &ASsa_Dlg::OnDeltaposSpinV)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MaxS, &ASsa_Dlg::OnDeltaposSpinMaxs)
	ON_EN_CHANGE(IDC_EDIT_MaxS, &ASsa_Dlg::OnEnChangeEditMaxs)
	ON_EN_CHANGE(IDC_EDIT_V, &ASsa_Dlg::OnEnChangeEditV)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_SI, &ASsa_Dlg::OnDeltaposSpinSi)
	ON_EN_CHANGE(IDC_EDIT_SI, &ASsa_Dlg::OnEnChangeEditSi)
	ON_CBN_SELCHANGE(IDC_COMBO_OI, &ASsa_Dlg::OnCbnSelchangeComboOi)
	ON_BN_CLICKED(IDC_CHECK_OutS, &ASsa_Dlg::OnBnClickedCheckOuts)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D, &ASsa_Dlg::OnDeltaposSpinD)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT, &ASsa_Dlg::OnDeltaposSpinTt)
	ON_EN_CHANGE(IDC_EDIT_D, &ASsa_Dlg::OnEnChangeEditD)
	ON_EN_CHANGE(IDC_EDIT_TT, &ASsa_Dlg::OnEnChangeEditTt)

END_MESSAGE_MAP()


// ASsa_Dlg 消息处理程序


BOOL ASsa_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpASsa_Dlg=&m_ASsa_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_ASsa_Dlg;
	m_iWhoamI=GTSPD;
	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTSPD].sCmdstr);

	m_ComboBox_M.InsertString(0,"0: Disable Speed Alarm Settings");
	m_ComboBox_M.InsertString(1,"1: Report Speed Alarm Settings if the current speed is within the speed range defined by <Min Speed> and <Max Speed>");
	m_ComboBox_M.InsertString(2,"2: Report Speed Alarm Settings if the current speed is outside the speed range defined by <Min Speed> and <Max Speed>.");
	m_ComboBox_M.InsertString(3,"3: Report Speed Alarm Settings only once if the current speed is within or outside the speed range defined by <Min Speed> and <Max Speed>");
	m_ComboBox_M.InsertString(4,"4: Report Speed Alarm Settings if the speed changes from inside to outside or from outside to inside of the speed range");
	m_ComboBox_M.SetCurSel(0);

	SetDlgItemText(IDC_EDIT_MS,"0");
	m_Spin_MS.SetBuddy(GetDlgItem(IDC_EDIT_MS)); //得到指向编辑框的窗口指针
	m_Spin_MS.SetRange(0,400);

	SetDlgItemText(IDC_EDIT_MaxS,"0");
	m_Spin_MaxS.SetBuddy(GetDlgItem(IDC_EDIT_MaxS)); //得到指向编辑框的窗口指针
	m_Spin_MaxS.SetRange(0,400);

	SetDlgItemText(IDC_EDIT_V,"60");
	m_Spin_V.SetBuddy(GetDlgItem(IDC_EDIT_V)); //得到指向编辑框的窗口指针
	m_Spin_V.SetRange(0,3600);

	SetDlgItemText(IDC_EDIT_SI,"300");
	m_Spin_SI.SetBuddy(GetDlgItem(IDC_EDIT_SI)); //得到指向编辑框的窗口指针
	m_Spin_SI.SetRange(30,3600);

	m_ComboBox_OI.InsertString(0,"0");
	m_ComboBox_OI.InsertString(1,"1");
	m_ComboBox_OI.InsertString(2,"2");
	m_ComboBox_OI.SetCurSel(0);

	SetDlgItemText(IDC_EDIT_D,"0");
	m_Spin_D.SetBuddy(GetDlgItem(IDC_EDIT_D)); //得到指向编辑框的窗口指针
	m_Spin_D.SetRange(0,255);

	SetDlgItemText(IDC_EDIT_TT,"0");
	m_Spin_TT.SetBuddy(GetDlgItem(IDC_EDIT_TT)); //得到指向编辑框的窗口指针
	m_Spin_TT.SetRange(0,255);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString ASsa_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL ASsa_Dlg::UpdataPage(CString sStr)
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
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboM();
		m_Edit_MS.SetWindowText(ValueList.GetAt(2));
		m_Edit_V.SetWindowText(ValueList.GetAt(4));
		m_Edit_SI.SetWindowText(ValueList.GetAt(5));
		m_Edit_MaxS.SetWindowText(ValueList.GetAt(3));

		m_ComboBox_OI.SetCurSel(atoi(ValueList.GetAt(6)));
		OnCbnSelchangeComboOi();
		m_Check_OS.SetCheck(atoi(ValueList.GetAt(7)));
		OnBnClickedCheckOuts();
		m_Edit_D.SetWindowText(ValueList.GetAt(8));
		m_Edit_TT.SetWindowText(ValueList.GetAt(9));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}

//2
void ASsa_Dlg::OnCbnSelchangeComboM()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_M.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void ASsa_Dlg::OnDeltaposSpinMs(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_MS.GetPos();
	m_Spin_MS.SetPos(iTemp);
	m_Edit_MS.GetWindowText(strValue);  
	*pResult = 0;
}

//3
void ASsa_Dlg::OnEnChangeEditMs()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_MS.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,2,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void ASsa_Dlg::OnDeltaposSpinV(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_V.GetPos();
	m_Spin_V.SetPos(iTemp);
	m_Edit_V.GetWindowText(strValue);  
	*pResult = 0;
}


void ASsa_Dlg::OnDeltaposSpinMaxs(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_MaxS.GetPos();
	m_Spin_MaxS.SetPos(iTemp);
	m_Edit_MaxS.GetWindowText(strValue);  
	*pResult = 0;
}

//4
void ASsa_Dlg::OnEnChangeEditMaxs()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_MaxS.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,3,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//5
void ASsa_Dlg::OnEnChangeEditV()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_V.GetWindowText(sStr);
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


void ASsa_Dlg::OnDeltaposSpinSi(NMHDR *pNMHDR, LRESULT *pResult)
{
		LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
		CString strValue="";
		int iTemp=0;
		iTemp=m_Spin_SI.GetPos();
		m_Spin_SI.SetPos(iTemp);
		m_Edit_SI.GetWindowText(strValue);  
		*pResult = 0;
}

//6
void ASsa_Dlg::OnEnChangeEditSi()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_SI.GetWindowText(sStr);
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
void ASsa_Dlg::OnCbnSelchangeComboOi()
{
	//////////	
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_OI.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,6,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//8
void ASsa_Dlg::OnBnClickedCheckOuts()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_OS.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,7,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void ASsa_Dlg::OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D.GetPos();
	m_Spin_D.SetPos(iTemp);
	m_Edit_D.GetWindowText(strValue);  
	*pResult = 0;
}


void ASsa_Dlg::OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult)
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
void ASsa_Dlg::OnEnChangeEditD()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_D.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,8,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//10
void ASsa_Dlg::OnEnChangeEditTt()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TT.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,9,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

