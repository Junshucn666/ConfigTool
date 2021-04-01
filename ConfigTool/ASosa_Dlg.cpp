// ASosa_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ASosa_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern ASosa_Dlg m_ASosa_Dlg;
ASosa_Dlg*	lpASosa_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
extern ASosa_Dlg m_ASosa_Dlg;
////////////

IMPLEMENT_DYNAMIC(ASosa_Dlg, CMyTabBaseDlg)

ASosa_Dlg::ASosa_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(ASosa_Dlg::IDD, pParent)
{

}

ASosa_Dlg::~ASosa_Dlg()
{
}

void ASosa_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_Mode, m_ComboBox_M);
	DDX_Control(pDX, IDC_SPIN_ST1, m_Spin_ST1);
	DDX_Control(pDX, IDC_SPIN_ST2, m_Spin_ST2);
	DDX_Control(pDX, IDC_SPIN_ST3, m_Spin_ST3);
	DDX_Control(pDX, IDC_SPIN_ST4, m_Spin_ST4);
	DDX_Control(pDX, IDC_EDIT_ST1, m_Edit_ST1);
	DDX_Control(pDX, IDC_EDIT_ST2, m_Edit_ST2);
	DDX_Control(pDX, IDC_EDIT_ST3, m_Edit_ST3);
	DDX_Control(pDX, IDC_EDIT_ST4, m_Edit_ST4);
	DDX_Control(pDX, IDC_SPIN_V1, m_Spin_V1);
	DDX_Control(pDX, IDC_SPIN_V2, m_Spin_V2);
	DDX_Control(pDX, IDC_SPIN_V3, m_Spin_V3);
	DDX_Control(pDX, IDC_SPIN_V4, m_Spin_V4);
	DDX_Control(pDX, IDC_EDIT_V1, m_Edit_V1);
	DDX_Control(pDX, IDC_EDIT_V2, m_Edit_V2);
	DDX_Control(pDX, IDC_EDIT_V3, m_Edit_V3);
	DDX_Control(pDX, IDC_EDIT_V4, m_Edit_V4);
	DDX_Control(pDX, IDC_SPIN_AT1, m_Spin_AT1);
	DDX_Control(pDX, IDC_SPIN_AT2, m_Spin_AT2);
	DDX_Control(pDX, IDC_SPIN_AT3, m_Spin_AT3);
	DDX_Control(pDX, IDC_SPIN_AT4, m_Spin_AT4);
	DDX_Control(pDX, IDC_EDIT_AT1, m_Edit_AT1);
	DDX_Control(pDX, IDC_EDIT_AT2, m_Edit_AT2);
	DDX_Control(pDX, IDC_EDIT_AT3, m_Edit_AT3);
	DDX_Control(pDX, IDC_EDIT_AT4, m_Edit_AT4);
}


BEGIN_MESSAGE_MAP(ASosa_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_Mode, &ASosa_Dlg::OnCbnSelchangeComboMode)
	ON_EN_CHANGE(IDC_EDIT_AT1, &ASosa_Dlg::OnEnChangeEditAt1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ST1, &ASosa_Dlg::OnDeltaposSpinSt1)
	ON_EN_CHANGE(IDC_EDIT_ST1, &ASosa_Dlg::OnEnChangeEditSt1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_V1, &ASosa_Dlg::OnDeltaposSpinV1)
	ON_EN_CHANGE(IDC_EDIT_V1, &ASosa_Dlg::OnEnChangeEditV1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_AT1, &ASosa_Dlg::OnDeltaposSpinAt1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ST2, &ASosa_Dlg::OnDeltaposSpinSt2)
	ON_EN_CHANGE(IDC_EDIT_ST2, &ASosa_Dlg::OnEnChangeEditSt2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_V2, &ASosa_Dlg::OnDeltaposSpinV2)
	ON_EN_CHANGE(IDC_EDIT_V2, &ASosa_Dlg::OnEnChangeEditV2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_AT2, &ASosa_Dlg::OnDeltaposSpinAt2)
	ON_EN_CHANGE(IDC_EDIT_AT2, &ASosa_Dlg::OnEnChangeEditAt2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ST3, &ASosa_Dlg::OnDeltaposSpinSt3)
	ON_EN_CHANGE(IDC_EDIT_ST3, &ASosa_Dlg::OnEnChangeEditSt3)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_V3, &ASosa_Dlg::OnDeltaposSpinV3)
	ON_EN_CHANGE(IDC_EDIT_V3, &ASosa_Dlg::OnEnChangeEditV3)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_AT3, &ASosa_Dlg::OnDeltaposSpinAt3)
	ON_EN_CHANGE(IDC_EDIT_AT3, &ASosa_Dlg::OnEnChangeEditAt3)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ST4, &ASosa_Dlg::OnDeltaposSpinSt4)
	ON_EN_CHANGE(IDC_EDIT_ST4, &ASosa_Dlg::OnEnChangeEditSt4)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_V4, &ASosa_Dlg::OnDeltaposSpinV4)
	ON_EN_CHANGE(IDC_EDIT_V4, &ASosa_Dlg::OnEnChangeEditV4)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_AT4, &ASosa_Dlg::OnDeltaposSpinAt4)
	ON_EN_CHANGE(IDC_EDIT_AT4, &ASosa_Dlg::OnEnChangeEditAt4)
END_MESSAGE_MAP()


// ASosa_Dlg 消息处理程序


BOOL ASosa_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpASosa_Dlg=&m_ASosa_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_ASosa_Dlg;
	m_iWhoamI=GTSPA;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTSPA].sCmdstr);
	m_ComboBox_M.InsertString(0,"0: Disable this function");
	m_ComboBox_M.InsertString(1,"1: Strict Standard Mode. This mode will check the speed and trigger the buzzer alarm during speedup or slowdown");
	m_ComboBox_M.InsertString(2,"2: Warning Mode. This mode will only check the speed and trigger the buzzer alarm during speedup");
	m_ComboBox_M.SetCurSel(0);

	SetDlgItemText(IDC_EDIT_ST1,"50");
	m_Spin_ST1.SetBuddy(GetDlgItem(IDC_EDIT_ST1)); //得到指向编辑框的窗口指针
	m_Spin_ST1.SetRange(0,400);
	SetDlgItemText(IDC_EDIT_V1,"60");
	m_Spin_V1.SetBuddy(GetDlgItem(IDC_EDIT_V1)); //得到指向编辑框的窗口指针
	m_Spin_V1.SetRange(0,3600);
	SetDlgItemText(IDC_EDIT_AT1,"0");
	m_Spin_AT1.SetBuddy(GetDlgItem(IDC_EDIT_AT1)); //得到指向编辑框的窗口指针
	m_Spin_AT1.SetRange(0,4);
	/////////////////

	SetDlgItemText(IDC_EDIT_ST2,"70");
	m_Spin_ST2.SetBuddy(GetDlgItem(IDC_EDIT_ST2)); //得到指向编辑框的窗口指针
	m_Spin_ST2.SetRange(0,400);
	SetDlgItemText(IDC_EDIT_V2,"60");
	m_Spin_V2.SetBuddy(GetDlgItem(IDC_EDIT_V2)); //得到指向编辑框的窗口指针
	m_Spin_V2.SetRange(0,3600);
	SetDlgItemText(IDC_EDIT_AT2,"0");
	m_Spin_AT2.SetBuddy(GetDlgItem(IDC_EDIT_AT2)); //得到指向编辑框的窗口指针
	m_Spin_AT2.SetRange(0,4);
	/////////////////

	SetDlgItemText(IDC_EDIT_ST3,"90");
	m_Spin_ST3.SetBuddy(GetDlgItem(IDC_EDIT_ST3)); //得到指向编辑框的窗口指针
	m_Spin_ST3.SetRange(0,400);
	SetDlgItemText(IDC_EDIT_V3,"60");
	m_Spin_V3.SetBuddy(GetDlgItem(IDC_EDIT_V3)); //得到指向编辑框的窗口指针
	m_Spin_V3.SetRange(0,3600);
	SetDlgItemText(IDC_EDIT_AT3,"0");
	m_Spin_AT3.SetBuddy(GetDlgItem(IDC_EDIT_AT3)); //得到指向编辑框的窗口指针
	m_Spin_AT3.SetRange(0,4);
	/////////////////

	SetDlgItemText(IDC_EDIT_ST4,"110");
	m_Spin_ST4.SetBuddy(GetDlgItem(IDC_EDIT_ST4)); //得到指向编辑框的窗口指针
	m_Spin_ST4.SetRange(0,400);
	SetDlgItemText(IDC_EDIT_V4,"60");
	m_Spin_V4.SetBuddy(GetDlgItem(IDC_EDIT_V4)); //得到指向编辑框的窗口指针
	m_Spin_V4.SetRange(0,3600);
	SetDlgItemText(IDC_EDIT_AT4,"0");
	m_Spin_AT4.SetBuddy(GetDlgItem(IDC_EDIT_AT4)); //得到指向编辑框的窗口指针
	m_Spin_AT4.SetRange(0,4);
	/////////////////
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString ASosa_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL ASosa_Dlg::UpdataPage(CString sStr)
{   //位置iPos是从0开始的
	CString sNewCmd="",sRight="",sLeft="",sTemp="";
	CArray<CString,CString>ValueList;
	int index1=0,index2=0;
	sTemp=sStr;//准备分割
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
	if (ValueList.GetSize()>23)
	{
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboMode();		

		m_Edit_ST1.SetWindowText(ValueList.GetAt(2));
		m_Edit_V1.SetWindowText(ValueList.GetAt(4));
		m_Edit_AT1.SetWindowText(ValueList.GetAt(5));

		m_Edit_ST2.SetWindowText(ValueList.GetAt(8));
		m_Edit_V2.SetWindowText(ValueList.GetAt(10));
		m_Edit_AT2.SetWindowText(ValueList.GetAt(11));

		m_Edit_ST3.SetWindowText(ValueList.GetAt(14));
		m_Edit_V3.SetWindowText(ValueList.GetAt(16));
		m_Edit_AT3.SetWindowText(ValueList.GetAt(17));

		m_Edit_ST4.SetWindowText(ValueList.GetAt(20));
		m_Edit_V4.SetWindowText(ValueList.GetAt(22));
		m_Edit_AT4.SetWindowText(ValueList.GetAt(23));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}

void ASosa_Dlg::OnCbnSelchangeComboMode()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_M.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void ASosa_Dlg::OnDeltaposSpinSt1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_ST1.GetPos();
	m_Spin_ST1.SetPos(iTemp);
	m_Edit_ST1.GetWindowText(strValue);  
	*pResult = 0;
}

//3
void ASosa_Dlg::OnEnChangeEditSt1()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_ST1.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,2,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void ASosa_Dlg::OnDeltaposSpinV1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_V1.GetPos();
	m_Spin_V1.SetPos(iTemp);
	m_Edit_V1.GetWindowText(strValue);  
	*pResult = 0;
}

//5
void ASosa_Dlg::OnEnChangeEditV1()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_V1.GetWindowText(sStr);
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


void ASosa_Dlg::OnDeltaposSpinAt1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_AT1.GetPos();
	m_Spin_AT1.SetPos(iTemp);
	m_Edit_AT1.GetWindowText(strValue);  
	*pResult = 0;
}
//6
void ASosa_Dlg::OnEnChangeEditAt1()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_AT1.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,5,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void ASosa_Dlg::OnDeltaposSpinSt2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_ST2.GetPos();
	m_Spin_ST2.SetPos(iTemp);
	m_Edit_ST2.GetWindowText(strValue);  
	*pResult = 0;
}

//9
void ASosa_Dlg::OnEnChangeEditSt2()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_ST2.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,8,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void ASosa_Dlg::OnDeltaposSpinV2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_V2.GetPos();
	m_Spin_V2.SetPos(iTemp);
	m_Edit_V2.GetWindowText(strValue);  
	*pResult = 0;
}

//11
void ASosa_Dlg::OnEnChangeEditV2()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_V2.GetWindowText(sStr);
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
	sNewCmd=m_MYWORK.UpdataCMD(strDigit,10,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void ASosa_Dlg::OnDeltaposSpinAt2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_AT2.GetPos();
	m_Spin_AT2.SetPos(iTemp);
	m_Edit_AT2.GetWindowText(strValue);  
	*pResult = 0;
}
//12
void ASosa_Dlg::OnEnChangeEditAt2()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_AT2.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,11,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//15
void ASosa_Dlg::OnDeltaposSpinSt3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_ST3.GetPos();
	m_Spin_ST3.SetPos(iTemp);
	m_Edit_ST3.GetWindowText(strValue);  
	*pResult = 0;
}

//15
void ASosa_Dlg::OnEnChangeEditSt3()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_ST3.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,14,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void ASosa_Dlg::OnDeltaposSpinV3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_V3.GetPos();
	m_Spin_V3.SetPos(iTemp);
	m_Edit_V3.GetWindowText(strValue);  
	*pResult = 0;
}

//17
void ASosa_Dlg::OnEnChangeEditV3()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_V3.GetWindowText(sStr);
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
	sNewCmd=m_MYWORK.UpdataCMD(strDigit,16,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void ASosa_Dlg::OnDeltaposSpinAt3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_AT3.GetPos();
	m_Spin_AT3.SetPos(iTemp);
	m_Edit_AT3.GetWindowText(strValue);  
	*pResult = 0;
}
//18
void ASosa_Dlg::OnEnChangeEditAt3()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_AT3.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,17,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}



void ASosa_Dlg::OnDeltaposSpinSt4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_ST4.GetPos();
	m_Spin_ST4.SetPos(iTemp);
	m_Edit_ST4.GetWindowText(strValue);  
	*pResult = 0;
}

//21
void ASosa_Dlg::OnEnChangeEditSt4()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_ST4.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,20,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void ASosa_Dlg::OnDeltaposSpinV4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_V4.GetPos();
	m_Spin_V4.SetPos(iTemp);
	m_Edit_V4.GetWindowText(strValue);  
	*pResult = 0;
}

//23
void ASosa_Dlg::OnEnChangeEditV4()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_V4.GetWindowText(sStr);
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
	sNewCmd=m_MYWORK.UpdataCMD(strDigit,22,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void ASosa_Dlg::OnDeltaposSpinAt4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_AT4.GetPos();
	m_Spin_AT4.SetPos(iTemp);
	m_Edit_AT4.GetWindowText(strValue);  
	*pResult = 0;
}
//24
void ASosa_Dlg::OnEnChangeEditAt4()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_AT4.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,23,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

