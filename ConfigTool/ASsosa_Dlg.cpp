// ASsosa_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ASsosa_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern ASsosa_Dlg m_ASsosa_Dlg;
ASsosa_Dlg*	lpASsosa_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(ASsosa_Dlg, CMyTabBaseDlg)

ASsosa_Dlg::ASsosa_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(ASsosa_Dlg::IDD, pParent)
{

}

ASsosa_Dlg::~ASsosa_Dlg()
{
}

void ASsosa_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_COMBO_DOI, m_ComboBox_DOI);
	DDX_Control(pDX, IDC_COMBO_OI, m_ComboBox_OI);
	DDX_Control(pDX, IDC_CHECK_OutS, m_Check_OutS);
	DDX_Control(pDX, IDC_SPIN_D, m_Spin_D);
	DDX_Control(pDX, IDC_EDIT_D, m_Edit_D);
	DDX_Control(pDX, IDC_SPIN_TT, m_Spin_TT);
	DDX_Control(pDX, IDC_EDIT_TT, m_Edit_TT);
}


BEGIN_MESSAGE_MAP(ASsosa_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &ASsosa_Dlg::OnCbnSelchangeComboM)
	ON_CBN_SELCHANGE(IDC_COMBO_DOI, &ASsosa_Dlg::OnCbnSelchangeComboDoi)
	ON_CBN_SELCHANGE(IDC_COMBO_OI, &ASsosa_Dlg::OnCbnSelchangeComboOi)
	ON_BN_CLICKED(IDC_CHECK_OutS, &ASsosa_Dlg::OnBnClickedCheckOuts)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D, &ASsosa_Dlg::OnDeltaposSpinD)
	ON_EN_CHANGE(IDC_EDIT_D, &ASsosa_Dlg::OnEnChangeEditD)
	ON_EN_CHANGE(IDC_EDIT_TT, &ASsosa_Dlg::OnEnChangeEditTt)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT, &ASsosa_Dlg::OnDeltaposSpinTt)
END_MESSAGE_MAP()


// ASsosa_Dlg 消息处理程序


BOOL ASsosa_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpASsosa_Dlg=&m_ASsosa_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_ASsosa_Dlg;
	m_iWhoamI=GTSOS;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTSOS].sCmdstr);

	m_ComboBox_M.InsertString(0,"0: Disable SOS function.");
	m_ComboBox_M.InsertString(1,"1: Send the current position +RESP:GTSOS to the backend server");
	m_ComboBox_M.InsertString(2,"2: Send the current position to the SMS gateway and Direct Number List");
	m_ComboBox_M.SetCurSel(0);

	m_ComboBox_DOI.InsertString(0,"0");
	m_ComboBox_DOI.InsertString(1,"1");
	m_ComboBox_DOI.SetCurSel(0);

	m_ComboBox_OI.InsertString(0,"0");
	m_ComboBox_OI.InsertString(1,"2");
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

CString ASsosa_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL ASsosa_Dlg::UpdataPage(CString sStr)
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
	m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(1)));
	OnCbnSelchangeComboM();
	m_ComboBox_DOI.SetCurSel(atoi(ValueList.GetAt(2)));
	OnCbnSelchangeComboDoi();

	if (ValueList.GetAt(4)=="2") m_ComboBox_OI.SetCurSel(1);
	else m_ComboBox_OI.SetCurSel(0);	
	OnCbnSelchangeComboOi();

	m_Check_OutS.SetCheck(atoi(ValueList.GetAt(5)));
	OnBnClickedCheckOuts();
	m_Edit_D.SetWindowText(ValueList.GetAt(6));
	m_Edit_TT.SetWindowText(ValueList.GetAt(7));

	return TRUE;
}

//2
void ASsosa_Dlg::OnCbnSelchangeComboM()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_M.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//3
void ASsosa_Dlg::OnCbnSelchangeComboDoi()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_DOI.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,2,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//5
void ASsosa_Dlg::OnCbnSelchangeComboOi()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_OI.GetCurSel();
	if (iTemp==0)
	{
		sStr="0";
	}
	else if (iTemp==1)
	{
		sStr="2";
	}
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,4,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//6
void ASsosa_Dlg::OnBnClickedCheckOuts()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_OutS.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,5,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void ASsosa_Dlg::OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D.GetPos();
	m_Spin_D.SetPos(iTemp);
	m_Edit_D.GetWindowText(strValue);  
	*pResult = 0;
}

//7
void ASsosa_Dlg::OnEnChangeEditD()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_D.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,6,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//8
void ASsosa_Dlg::OnEnChangeEditTt()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TT.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,7,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void ASsosa_Dlg::OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT.GetPos();
	m_Spin_TT.SetPos(iTemp);
	m_Edit_TT.GetWindowText(strValue);  
	*pResult = 0;
}
