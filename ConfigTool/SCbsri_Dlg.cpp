// SCbsri_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "SCbsri_Dlg.h"
#include "afxdialogex.h"
#include "ConfigToolDlg.h"


// SCbsri_Dlg 对话框
extern CConfigToolDlg*	lpCConfigToolDlg;
//extern HANDLE g_hEvent;
//extern BOOL MYTHREAD_WORK;
SCbsri_Dlg*	lpSCbsri_Dlg; 
extern ConfigCMD stu_ConfigCMD;
extern SCbsri_Dlg m_SCbsri_Dlg;
//extern CMYWORK	m_MYWORK;

IMPLEMENT_DYNAMIC(SCbsri_Dlg, CMyTabBaseDlg)

SCbsri_Dlg::SCbsri_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(SCbsri_Dlg::IDD, pParent)
{

}

SCbsri_Dlg::~SCbsri_Dlg()
{
}

void SCbsri_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_RM, m_ComboBox_RM);
	DDX_Control(pDX, IDC_COMBO_BM, m_ComboBox_BM);
	DDX_Control(pDX, IDC_COMBO_SE, m_ComboBox_SE);
	DDX_Control(pDX, IDC_COMBO_PF, m_ComboBox_PF);
	DDX_Control(pDX, IDC_EDIT_MSP, m_Edit_MSP);
	DDX_Control(pDX, IDC_EDIT_MSI, m_Edit_MSI);
	DDX_Control(pDX, IDC_SPIN_MSP, m_Spin_MSP);
	DDX_Control(pDX, IDC_EDIT_BSI, m_Edit_BSI);
	DDX_Control(pDX, IDC_EDIT_BSP, m_Edit_BSP);
	DDX_Control(pDX, IDC_SPIN_BSP, m_Spin_BSP);
	DDX_Control(pDX, IDC_EDIT_SG, m_Edit_SG);
	DDX_Control(pDX, IDC_SPIN_HI, m_Spin_HI);
	DDX_Control(pDX, IDC_EDIT_HI, m_Edit_HI);
	DDX_Control(pDX, IDC_CHECK_SSE, m_Check_SSE);
}


BEGIN_MESSAGE_MAP(SCbsri_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_RM, &SCbsri_Dlg::OnCbnSelchangeComboRm)
	ON_BN_CLICKED(IDC_BUTTON_Send, &SCbsri_Dlg::OnBnClickedButtonSend)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MSP, &SCbsri_Dlg::OnDeltaposSpinMsp)
	ON_EN_CHANGE(IDC_EDIT_MSI, &SCbsri_Dlg::OnEnChangeEditMsi)
	ON_EN_CHANGE(IDC_EDIT_MSP, &SCbsri_Dlg::OnEnChangeEditMsp)
	ON_EN_CHANGE(IDC_EDIT_BSI, &SCbsri_Dlg::OnEnChangeEditBsi)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_BSP, &SCbsri_Dlg::OnDeltaposSpinBsp)
	ON_EN_CHANGE(IDC_EDIT_BSP, &SCbsri_Dlg::OnEnChangeEditBsp)
	ON_EN_CHANGE(IDC_EDIT_SG, &SCbsri_Dlg::OnEnChangeEditSg)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_HI, &SCbsri_Dlg::OnDeltaposSpinHi)
	ON_EN_CHANGE(IDC_EDIT_HI, &SCbsri_Dlg::OnEnChangeEditHi)
	ON_CBN_SELCHANGE(IDC_COMBO_BM, &SCbsri_Dlg::OnCbnSelchangeComboBm)
	ON_CBN_SELCHANGE(IDC_COMBO_SE, &SCbsri_Dlg::OnCbnSelchangeComboSe)
	ON_CBN_SELCHANGE(IDC_COMBO_PF, &SCbsri_Dlg::OnCbnSelchangeComboPf)
	ON_BN_CLICKED(IDC_CHECK_SSE, &SCbsri_Dlg::OnBnClickedCheckSse)
END_MESSAGE_MAP()


// SCbsri_Dlg 消息处理程序

BOOL SCbsri_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	// TODO:  在此添加额外的初始化
	lpSCbsri_Dlg=&m_SCbsri_Dlg;//窗口寻址
	m_lpMyTabBaseDlg=&m_SCbsri_Dlg;
	m_iWhoamI=GTSRI;
	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[m_iWhoamI].sCmdstr); 
	                             //AT+GTSRI=HYIoT,3,,1,some.host.name,7071,116.226.45.229,7012,+8613812341234,15,1,0,0,,,0001$
	SetDlgItemText(IDC_EDIT_MSI,"");
	SetDlgItemText(IDC_EDIT_MSP,"");
	m_Spin_MSP.SetBuddy(GetDlgItem(IDC_EDIT_MSP)); //得到指向编辑框的窗口指针
	m_Spin_MSP.SetRange32(0,65535);
	SetDlgItemText(IDC_EDIT_BSI,"");
	SetDlgItemText(IDC_EDIT_BSP,"");
	m_Spin_BSP.SetBuddy(GetDlgItem(IDC_EDIT_BSP)); //得到指向编辑框的窗口指针
	m_Spin_BSP.SetRange32(0,65530);
	SetDlgItemText(IDC_EDIT_SG,"");

	SetDlgItemText(IDC_EDIT_HI,"0");
	m_Spin_HI.SetBuddy(GetDlgItem(IDC_EDIT_HI)); //得到指向编辑框的窗口指针
	m_Spin_HI.SetRange(5,360);
	//////////////////////////////////
	m_ComboBox_RM.InsertString(0,"Stop reporting");
	m_ComboBox_RM.InsertString(1,"TCP short-connection preferred mode");
	m_ComboBox_RM.InsertString(2,"TCP short-connection forced mode");
	m_ComboBox_RM.InsertString(3,"TCP long-connection mode");
	m_ComboBox_RM.InsertString(4,"UDP mode");
	m_ComboBox_RM.InsertString(5,"Force on SMS");
	m_ComboBox_RM.InsertString(6,"UDP with fixed local port");
	m_ComboBox_RM.InsertString(7,"TCP long-connection mode with the backup server");
	m_ComboBox_RM.SetCurSel(0);
	///////////////////////////////////
	m_ComboBox_BM.InsertString(0,"0:Disable");
	m_ComboBox_BM.InsertString(1,"1:Low priority");
	m_ComboBox_BM.InsertString(2,"2:High priority");
	m_ComboBox_BM.SetCurSel(1);
	//////////////////////////////////
	m_ComboBox_SE.InsertString(0,"Disable SACK");
	m_ComboBox_SE.InsertString(1,"Receive SACK and check it");
	m_ComboBox_SE.InsertString(2,"Receive SACK but not check");
	m_ComboBox_SE.SetCurSel(0);
	//////////////////////////////////////////////
	m_ComboBox_PF.InsertString(0,"ASCII");
	m_ComboBox_PF.InsertString(1,"HEX");
	m_ComboBox_PF.SetCurSel(0);
	 
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void SCbsri_Dlg::OnBnClickedButtonSend()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sStr="";
	m_Edit_MSI.GetWindowText(sStr);
	if (sStr=="") 
	{
		AfxMessageBox("Main Server IP IS EMPTY!!");
		return;
	}
	DoSendWork();
}

CString SCbsri_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL SCbsri_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>12)
	{
		m_ComboBox_RM.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboRm();
		m_Edit_MSI.SetWindowText(ValueList.GetAt(4));
		m_Edit_MSP.SetWindowText(ValueList.GetAt(5));
		m_Edit_BSI.SetWindowText(ValueList.GetAt(6));
		m_Edit_BSP.SetWindowText(ValueList.GetAt(7));
		m_Edit_SG.SetWindowText(ValueList.GetAt(8));
		m_Edit_HI.SetWindowText(ValueList.GetAt(9));

		m_ComboBox_BM.SetCurSel(atoi(ValueList.GetAt(3)));
		OnCbnSelchangeComboBm();
		m_ComboBox_SE.SetCurSel(atoi(ValueList.GetAt(10)));
		OnCbnSelchangeComboSe();
		m_ComboBox_PF.SetCurSel(atoi(ValueList.GetAt(11)));
		OnCbnSelchangeComboPf();
		m_Check_SSE.SetCheck(atoi(ValueList.GetAt(12)));
		OnBnClickedCheckSse();
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}

void SCbsri_Dlg::OnCbnSelchangeComboRm()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_RM.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,1,sCmd);//Report Mode第二个参数
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void SCbsri_Dlg::OnDeltaposSpinMsp(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码	
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_MSP.GetPos();
	m_Spin_MSP.SetPos(iTemp);
	m_Edit_MSP.GetWindowText(strValue);   //得到编辑框中的内容
	*pResult = 0;
}

void SCbsri_Dlg::OnEnChangeEditMsi()
{
	// TODO:  在此添加控件通知处理程序代码
	CString sStr="",sCmd="",sNewCmd="";
	m_Edit_MSI.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,4,sCmd);//第5个
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void SCbsri_Dlg::OnEnChangeEditMsp()
{
	// TODO:  在此添加控件通知处理程序代码
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_MSP.GetWindowText(sStr);
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
	sNewCmd=UpdataCMD(strDigit,5,sCmd);//第6个
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void SCbsri_Dlg::OnEnChangeEditBsi()
{
	CString sStr="",sCmd="",sNewCmd="";
	m_Edit_BSI.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,6,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void SCbsri_Dlg::OnDeltaposSpinBsp(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_BSP.GetPos();
	m_Spin_BSP.SetPos(iTemp);
	m_Edit_BSP.GetWindowText(strValue);                 //得到编辑框中的内容
	*pResult = 0;
}


void SCbsri_Dlg::OnEnChangeEditBsp()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_BSP.GetWindowText(sStr);
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


void SCbsri_Dlg::OnEnChangeEditSg()
{
	CString sStr="",sCmd="",sNewCmd="";
	m_Edit_SG.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,8,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void SCbsri_Dlg::OnDeltaposSpinHi(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_HI.GetPos();
	m_Spin_HI.SetPos(iTemp);
	m_Edit_HI.GetWindowText(strValue);                 //得到编辑框中的内容
	*pResult = 0;
}


void SCbsri_Dlg::OnEnChangeEditHi()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_HI.GetWindowText(sStr);
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
	sNewCmd=UpdataCMD(strDigit,9,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void SCbsri_Dlg::OnCbnSelchangeComboBm()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_BM.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,3,sCmd);//第4个Buffer Mode
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void SCbsri_Dlg::OnCbnSelchangeComboSe()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_SE.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,10,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void SCbsri_Dlg::OnCbnSelchangeComboPf()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_PF.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,11,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void SCbsri_Dlg::OnBnClickedCheckSse()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_SSE.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,12,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

