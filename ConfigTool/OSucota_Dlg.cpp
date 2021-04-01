// OSucota_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "OSucota_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern OSucota_Dlg m_OSucota_Dlg;
OSucota_Dlg*	lpOSucota_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(OSucota_Dlg, CMyTabBaseDlg)

OSucota_Dlg::OSucota_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(OSucota_Dlg::IDD, pParent)
{

}

OSucota_Dlg::~OSucota_Dlg()
{
}

void OSucota_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_MR, m_ComboBox_MR);
	DDX_Control(pDX, IDC_SPIN_TD, m_Spin_TD);
	DDX_Control(pDX, IDC_EDIT_DT, m_Edit_TD);
	DDX_Control(pDX, IDC_CHECK_RE, m_Check_RE);
	DDX_Control(pDX, IDC_SPIN_UI, m_Spin_UI);
	DDX_Control(pDX, IDC_EDIT_UI, m_Edit_UI);
	DDX_Control(pDX, IDC_EDIT_DU, m_Edit_DU);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
}


BEGIN_MESSAGE_MAP(OSucota_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_MR, &OSucota_Dlg::OnCbnSelchangeComboMr)
	ON_EN_CHANGE(IDC_EDIT_DT, &OSucota_Dlg::OnEnChangeEditDt)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TD, &OSucota_Dlg::OnDeltaposSpinTd)
	ON_BN_CLICKED(IDC_CHECK_RE, &OSucota_Dlg::OnBnClickedCheckRe)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_UI, &OSucota_Dlg::OnDeltaposSpinUi)
	ON_EN_CHANGE(IDC_EDIT_UI, &OSucota_Dlg::OnEnChangeEditUi)
	ON_EN_CHANGE(IDC_EDIT_DU, &OSucota_Dlg::OnEnChangeEditDu)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &OSucota_Dlg::OnCbnSelchangeComboM)
END_MESSAGE_MAP()


// OSucota_Dlg 消息处理程序


BOOL OSucota_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpOSucota_Dlg=&m_OSucota_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_OSucota_Dlg;
	m_iWhoamI=GTUPC;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTUPC].sCmdstr);



	m_ComboBox_MR.InsertString(0,"0");
	m_ComboBox_MR.InsertString(1,"1");
	m_ComboBox_MR.InsertString(2,"2");
	m_ComboBox_MR.InsertString(3,"3");
	m_ComboBox_MR.SetCurSel(0);

	SetDlgItemText(IDC_EDIT_DT,"10");
	m_Spin_TD.SetBuddy(GetDlgItem(IDC_EDIT_DT)); //得到指向编辑框的窗口指针
	m_Spin_TD.SetRange(5,30);

	SetDlgItemText(IDC_EDIT_UI,"0");
	m_Spin_UI.SetBuddy(GetDlgItem(IDC_EDIT_UI)); //得到指向编辑框的窗口指针
	m_Spin_UI.SetRange(0,8760);

	m_ComboBox_M.InsertString(0,"0: Disable this function.");
	m_ComboBox_M.InsertString(1,"1: Enable this function");
	m_ComboBox_M.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


CString OSucota_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL OSucota_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>7)
	{
		m_ComboBox_MR.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboMr();
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(7)));
		OnCbnSelchangeComboM();
		m_Check_RE.SetCheck(atoi(ValueList.GetAt(4)));
		OnBnClickedCheckRe();
		m_Edit_TD.SetWindowText(ValueList.GetAt(2));
		m_Edit_UI.SetWindowText(ValueList.GetAt(5));
		m_Edit_DU.SetWindowText(ValueList.GetAt(6));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}

void OSucota_Dlg::OnCbnSelchangeComboMr()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_MR.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void OSucota_Dlg::OnEnChangeEditDt()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TD.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,2,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void OSucota_Dlg::OnDeltaposSpinTd(NMHDR *pNMHDR, LRESULT *pResult)
{

	/////////////////
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TD.GetPos();
	m_Spin_TD.SetPos(iTemp);
	m_Edit_TD.GetWindowText(strValue);  
	*pResult = 0;
}


void OSucota_Dlg::OnBnClickedCheckRe()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_RE.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,4,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void OSucota_Dlg::OnDeltaposSpinTd2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void OSucota_Dlg::OnDeltaposSpinUi(NMHDR *pNMHDR, LRESULT *pResult)
{

	/////////////////
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_UI.GetPos();
	m_Spin_UI.SetPos(iTemp);
	m_Spin_UI.GetWindowText(strValue);  
	*pResult = 0;
}


void OSucota_Dlg::OnEnChangeEditUi()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_UI.GetWindowText(sStr);
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



void OSucota_Dlg::OnEnChangeEditDu()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_DU.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UpdataCMD(sStr,6,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void OSucota_Dlg::OnCbnSelchangeComboM()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_M.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,7,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

