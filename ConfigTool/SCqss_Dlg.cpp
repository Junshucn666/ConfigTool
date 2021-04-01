// SCqss_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "SCqss_Dlg.h"
#include "afxdialogex.h"
#include "ConfigToolDlg.h"
#include "MYWORK.h"

// SCbsi_Dlg 对话框
extern CConfigToolDlg*	lpCConfigToolDlg;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
SCqss_Dlg*	lpSCqss_Dlg;
extern SCqss_Dlg m_SCqss_Dlg;
extern CMYWORK	m_MYWORK;
extern ConfigCMD stu_ConfigCMD;
IMPLEMENT_DYNAMIC(SCqss_Dlg, CMyTabBaseDlg)

SCqss_Dlg::SCqss_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(SCqss_Dlg::IDD, pParent)
{

}

SCqss_Dlg::~SCqss_Dlg()
{
}

void SCqss_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_qssRM, m_ComboBox_qssRM);
	DDX_Control(pDX, IDC_COMBO_BM, m_ComboBox_qssBM);
	DDX_Control(pDX, IDC_COMBO_SE, m_ComboBox_qssSE);
	DDX_Control(pDX, IDC_COMBO_PF, m_ComboBox_qssPF);
	//DDX_Control(pDX, IDC_EDIT_GTCMD, m_Edit_GTCMD);
	DDX_Control(pDX, IDC_EDIT_APN, m_Edit_APN);
	DDX_Control(pDX, IDC_EDIT_UserName, m_Edit_UN);
	DDX_Control(pDX, IDC_EDIT_Password, m_Edit_PW);
	DDX_Control(pDX, IDC_EDIT_qssMSI, m_Edit_qssMSI);
	DDX_Control(pDX, IDC_SPIN_MSP, m_Spin_MSP);
	DDX_Control(pDX, IDC_EDIT_qssMSP, m_Edit_MSP);
	DDX_Control(pDX, IDC_EDIT_qssBSI, m_Edit_BSI);
	DDX_Control(pDX, IDC_SPIN_BSP, m_Spin_BSP);
	DDX_Control(pDX, IDC_EDIT_qssBSP, m_Edit_BSP);
	DDX_Control(pDX, IDC_EDIT_qssSG, m_Edit_SG);
	DDX_Control(pDX, IDC_SPIN_HI, m_Spin_HI);
	DDX_Control(pDX, IDC_EDIT_HI, m_Edit_HI);
	DDX_Control(pDX, IDC_CHECK_SSE, m_Check_SSE);
}


BEGIN_MESSAGE_MAP(SCqss_Dlg, CMyTabBaseDlg)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &SCqss_Dlg::OnDeltaposSpin1)
	//ON_BN_CLICKED(IDC_BUTTON_Read, &SCqss_Dlg::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_Send, &SCqss_Dlg::OnBnClickedButtonSend)
	ON_CBN_SELCHANGE(IDC_COMBO_qssRM, &SCqss_Dlg::OnCbnSelchangeComboqssrm)
	ON_EN_CHANGE(IDC_EDIT_APN, &SCqss_Dlg::OnEnChangeEditApn)
	ON_EN_CHANGE(IDC_EDIT_UserName, &SCqss_Dlg::OnEnChangeEditUsername)
	ON_EN_CHANGE(IDC_EDIT_Password, &SCqss_Dlg::OnEnChangeEditPassword)
	ON_EN_CHANGE(IDC_EDIT_qssMSI, &SCqss_Dlg::OnEnChangeEditqssmsi)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MSP, &SCqss_Dlg::OnDeltaposSpinMsp)
	ON_EN_CHANGE(IDC_EDIT_qssMSP, &SCqss_Dlg::OnEnChangeEditqssmsp)
	ON_EN_CHANGE(IDC_EDIT_qssBSI, &SCqss_Dlg::OnEnChangeEditqssbsi)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_BSP, &SCqss_Dlg::OnDeltaposSpinBsp)
	ON_EN_CHANGE(IDC_EDIT_qssBSP, &SCqss_Dlg::OnEnChangeEditqssbsp)
	ON_EN_CHANGE(IDC_EDIT_qssSG, &SCqss_Dlg::OnEnChangeEditqsssg)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_HI, &SCqss_Dlg::OnDeltaposSpinHi)
	ON_EN_CHANGE(IDC_EDIT_HI, &SCqss_Dlg::OnEnChangeEditHi)
	ON_CBN_SELCHANGE(IDC_COMBO_BM, &SCqss_Dlg::OnCbnSelchangeComboBm)
	ON_CBN_SELCHANGE(IDC_COMBO_SE, &SCqss_Dlg::OnCbnSelchangeComboSe)
	ON_CBN_SELCHANGE(IDC_COMBO_PF, &SCqss_Dlg::OnCbnSelchangeComboPf)
	ON_BN_CLICKED(IDC_CHECK_SSE, &SCqss_Dlg::OnBnClickedCheckSse)
	//ON_EN_CHANGE(IDC_EDIT_GTCMD, &SCqss_Dlg::OnEnChangeEditGtqss)
END_MESSAGE_MAP()


// SCqss_Dlg 消息处理程序
BOOL SCqss_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	// TODO:  在此添加额外的初始化
	lpSCqss_Dlg=&m_SCqss_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_SCqss_Dlg;
	m_iWhoamI=GTQSS;
	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[m_iWhoamI].sCmdstr);
	//AT+GTQSS=HYIoT,,,,3,,1,116.226.44.17,7011,116.226.45.229,7012,+8613812341234,15,1,0,0,0002$
	SetDlgItemText(IDC_EDIT_qssMSI,"");
	SetDlgItemText(IDC_EDIT_qssMSP,"");
	m_Spin_MSP.SetBuddy(GetDlgItem(IDC_EDIT_qssMSP)); //得到指向编辑框的窗口指针
	m_Spin_MSP.SetRange32(0,65535);
	SetDlgItemText(IDC_EDIT_qssBSI,"");
	SetDlgItemText(IDC_EDIT_qssBSP,"");
	m_Spin_BSP.SetBuddy(GetDlgItem(IDC_EDIT_qssBSP)); //得到指向编辑框的窗口指针
	m_Spin_BSP.SetRange32(0,65535);
	SetDlgItemText(IDC_EDIT_qssSG,"");

	SetDlgItemText(IDC_EDIT_HI,"0");
	m_Spin_HI.SetBuddy(GetDlgItem(IDC_EDIT_HI)); //得到指向编辑框的窗口指针
	m_Spin_HI.SetRange(5,360);
	//////////////////////////////////
	m_ComboBox_qssRM.InsertString(0,"0.Stop reporting");
	m_ComboBox_qssRM.InsertString(1,"1.TCP short-connection preferred mode");
	m_ComboBox_qssRM.InsertString(2,"2.TCP short-connection forced mode");
	m_ComboBox_qssRM.InsertString(3,"3.TCP long-connection mode");
	m_ComboBox_qssRM.InsertString(4,"4.UDP mode");
	m_ComboBox_qssRM.InsertString(5,"5.Force on SMS");
	m_ComboBox_qssRM.InsertString(6,"6.UDP with fixed local port");
	m_ComboBox_qssRM.InsertString(7,"7.TCP long-connection mode with the backup server");
	m_ComboBox_qssRM.SetCurSel(0);
	///////////////////////////////////
	m_ComboBox_qssBM.InsertString(0,"0:Disable");
	m_ComboBox_qssBM.InsertString(1,"1:Low priority");
	m_ComboBox_qssBM.InsertString(2,"2:High priority");
	m_ComboBox_qssBM.SetCurSel(1);
	//////////////////////////////////
	m_ComboBox_qssSE.InsertString(0,"Disable SACK");
	m_ComboBox_qssSE.InsertString(1,"Receive SACK and check it");
	m_ComboBox_qssSE.InsertString(2,"Receive SACK but not check");
	m_ComboBox_qssSE.SetCurSel(0);
	//////////////////////////////////////////////
	m_ComboBox_qssPF.InsertString(0,"ASCII");
	m_ComboBox_qssPF.InsertString(1,"HEX");
	m_ComboBox_qssPF.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void SCqss_Dlg::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

void SCqss_Dlg::GetCMD()
{
	CArray<CString,CString>CmdList;
	int iTemp=0;
	CString sNewCmd="";	CString sStr="";
	CString s1="",s2="",s3="",s4="",s5="",s6="",s7="",s8="",s9="",s10="",s11="",s12="",s13="",s14="",s15="",s16="";
	CmdList.InsertAt(1,"AT+GTQSS=HYIoT");
	try
	{
		m_Edit_APN.GetWindowText(s2);
		CmdList.InsertAt(2,s2);
		m_Edit_UN.GetWindowText(s3);
		CmdList.InsertAt(3,s3);
		m_Edit_PW.GetWindowText(s4);
		CmdList.InsertAt(4,s4);
		iTemp=m_ComboBox_qssRM.GetCurSel();
		if (iTemp==-1) iTemp=0;
		s5.Format("%d",iTemp);
		CmdList.InsertAt(5,s5);
		CmdList.Add("");

		iTemp=m_ComboBox_qssBM.GetCurSel();
		if (iTemp==-1) iTemp=1;
		s7.Format("%d",iTemp);
		CmdList.InsertAt(7,s7);

		m_Edit_qssMSI.GetWindowText(s8);
		CmdList.InsertAt(8,s8);

		m_Edit_MSP.GetWindowText(sStr);
		if (sStr.Find(",")!=-1)
		{      
			for( int i=0;i < sStr.GetLength(); i++)
			{
				if(sStr.GetAt(i)>='0' &&  sStr.GetAt(i)<='9')
				{
					s9 += sStr.GetAt(i);
				}
			}
		}
		else
		{
			s9=sStr;
		}
		CmdList.InsertAt(9,s9);
		m_Edit_BSI.GetWindowText(s10);
		CmdList.InsertAt(10,s10);

		m_Edit_BSP.GetWindowText(sStr);
		if (sStr.Find(",")!=-1)
		{      
			for( int i=0;i < sStr.GetLength(); i++)
			{
				if(sStr.GetAt(i)>='0' &&  sStr.GetAt(i)<='9')
				{
					s11 += sStr.GetAt(i);
				}
			}
		}
		else
		{
			s11=sStr;
		}
		CmdList.InsertAt(11,s11);

		m_Edit_SG.GetWindowText(s12);
		CmdList.InsertAt(12,s12);

		m_Edit_HI.GetWindowText(s13);
		CmdList.InsertAt(13,s13);

		iTemp=m_ComboBox_qssSE.GetCurSel();   ///Combox
		if (iTemp==-1) iTemp=0;
		s14.Format("%d",iTemp);
		CmdList.InsertAt(14,s14);

		iTemp=m_ComboBox_qssPF.GetCurSel();   ///Combox
		if (iTemp==-1) iTemp=0;
		s15.Format("%d",iTemp);
		CmdList.InsertAt(15,s15);

		iTemp=m_Check_SSE.GetCheck();  
		s16.Format("%d",iTemp);
		CmdList.InsertAt(16,s16);
		CmdList.Add("FFFF$");
		////////////////////////////
		for (int i=1;i<CmdList.GetSize();i++)
		{
			if (1==i)
			{
				sNewCmd=CmdList.GetAt(1);
			}
			else
			{
				sNewCmd=sNewCmd+","+CmdList.GetAt(i);
			}
		}
		m_Edit_GTCMD.SetWindowText(sNewCmd);
	}
	catch (...)
	{
		AfxMessageBox("Error Happend,Please Contact Engineer!");
		return ;
	}	
}

BOOL SCqss_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>15)
	{
		m_ComboBox_qssRM.SetCurSel(atoi(ValueList.GetAt(4)));
		OnCbnSelchangeComboqssrm();

		m_Edit_APN.SetWindowText(ValueList.GetAt(1));
		m_Edit_UN.SetWindowText(ValueList.GetAt(2));
		m_Edit_PW.SetWindowText(ValueList.GetAt(3));
		m_Edit_qssMSI.SetWindowText(ValueList.GetAt(7));

		m_Edit_MSP.SetWindowText(ValueList.GetAt(8));
		m_Edit_BSI.SetWindowText(ValueList.GetAt(9));
		m_Edit_BSP.SetWindowText(ValueList.GetAt(10));
		m_Edit_SG.SetWindowText(ValueList.GetAt(11));
		m_Edit_HI.SetWindowText(ValueList.GetAt(12));

		m_Check_SSE.SetCheck(atoi(ValueList.GetAt(15)));
		OnBnClickedCheckSse();

		m_ComboBox_qssBM.SetCurSel(atoi(ValueList.GetAt(6)));
		OnCbnSelchangeComboBm();
		m_ComboBox_qssPF.SetCurSel(atoi(ValueList.GetAt(14)));
		OnCbnSelchangeComboPf();
		m_ComboBox_qssSE.SetCurSel(atoi(ValueList.GetAt(13)));
		OnCbnSelchangeComboSe();
		return TRUE;
	}
	else
	{
		AfxMessageBox("ERROR DATA");
		return FALSE;
	}

}

void SCqss_Dlg::OnBnClickedButtonSend()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sStr="";
	m_Edit_qssMSI.GetWindowText(sStr);
	if (sStr=="") 
	{
		AfxMessageBox("Main Server IP IS EMPTY!!");
		return;
	}
	DoSendWork();
}
//5
void SCqss_Dlg::OnCbnSelchangeComboqssrm()
{
	// TODO: 在此添加控件通知处理程序代码
	GetCMD();
	//CString sStr="",sCmd="",sNewCmd="";
	//int iTemp=0;
	//iTemp=m_ComboBox_qssRM.GetCurSel();
	//sStr.Format("%d",iTemp);
	//m_Edit_GTQSS.GetWindowText(sCmd);
	//sNewCmd=m_MYWORK.UpdataCMD(sStr,4,sCmd);
	//m_Edit_GTQSS.SetWindowText(sNewCmd);
}

void SCqss_Dlg::OnEnChangeEditApn()
{
	//CString sStr="",sCmd="",sNewCmd="";
	//m_Edit_APN.GetWindowText(sStr);
	//m_Edit_GTQSS.GetWindowText(sCmd);
	//sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	//m_Edit_GTQSS.SetWindowText(sNewCmd);
		GetCMD();
}

void SCqss_Dlg::OnEnChangeEditUsername()
{
	//CString sStr="",sCmd="",sNewCmd="";
	//m_Edit_UN.GetWindowText(sStr);
	//m_Edit_GTQSS.GetWindowText(sCmd);
	//sNewCmd=m_MYWORK.UpdataCMD(sStr,2,sCmd);
	//m_Edit_GTQSS.SetWindowText(sNewCmd);
		GetCMD();
}

void SCqss_Dlg::OnEnChangeEditPassword()
{
	//CString sStr="",sCmd="",sNewCmd="";
	//m_Edit_PW.GetWindowText(sStr);
	//m_Edit_GTQSS.GetWindowText(sCmd);
	//sNewCmd=m_MYWORK.UpdataCMD(sStr,3,sCmd);
	//m_Edit_GTQSS.SetWindowText(sNewCmd);
		GetCMD();
}

void SCqss_Dlg::OnEnChangeEditqssmsi()
{
	//CString sStr="",sCmd="",sNewCmd="";
	//m_Edit_qssMSI.GetWindowText(sStr);
	//m_Edit_GTQSS.GetWindowText(sCmd);
	//sNewCmd=m_MYWORK.UpdataCMD(sStr,7,sCmd);
	//m_Edit_GTQSS.SetWindowText(sNewCmd);
		GetCMD();
}

void SCqss_Dlg::OnDeltaposSpinMsp(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_MSP.GetPos();
	m_Spin_MSP.SetPos(iTemp);
	m_Edit_MSP.GetWindowText(strValue);                 //得到编辑框中的内容
	*pResult = 0;
}

void SCqss_Dlg::OnEnChangeEditqssmsp()
{
	//CString sStr="",sCmd="",sNewCmd="",strDigit="";
	//int i=0;
	//m_Edit_MSP.GetWindowText(sStr);
	//if (sStr.Find(",")!=-1)
	//{      
	//	for( int i=0;i < sStr.GetLength(); i++)
	//	{
	//		if(sStr.GetAt(i)>='0' &&  sStr.GetAt(i)<='9')
	//		{
	//			strDigit += sStr.GetAt(i);
	//		}
	//	}
	//}
	//else
	//{
	//	strDigit=sStr;
	//}
	//m_Edit_GTQSS.GetWindowText(sCmd);
	//sNewCmd=m_MYWORK.UpdataCMD(strDigit,8,sCmd);//第6个
	//m_Edit_GTQSS.SetWindowText(sNewCmd);

		GetCMD();
}

void SCqss_Dlg::OnEnChangeEditqssbsi()
{
	//CString sStr="",sCmd="",sNewCmd="";
	//m_Edit_BSI.GetWindowText(sStr);
	//m_Edit_GTQSS.GetWindowText(sCmd);
	//sNewCmd=m_MYWORK.UpdataCMD(sStr,9,sCmd);
	//m_Edit_GTQSS.SetWindowText(sNewCmd);

		GetCMD();
}

void SCqss_Dlg::OnDeltaposSpinBsp(NMHDR *pNMHDR, LRESULT *pResult)
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

void SCqss_Dlg::OnEnChangeEditqssbsp()
{
	//CString sStr="",sCmd="",sNewCmd="",strDigit="";
	//int i=0;
	//m_Edit_BSP.GetWindowText(sStr);
	//if (sStr.Find(",")!=-1)
	//{      
	//	for( int i=0;i < sStr.GetLength(); i++)
	//	{
	//		if(sStr.GetAt(i)>='0' &&  sStr.GetAt(i)<='9')
	//		{
	//			strDigit += sStr.GetAt(i);
	//		}
	//	}
	//}
	//else
	//{
	//	strDigit=sStr;
	//}
	//m_Edit_GTQSS.GetWindowText(sCmd);
	//sNewCmd=m_MYWORK.UpdataCMD(strDigit,10,sCmd);
	//m_Edit_GTQSS.SetWindowText(sNewCmd);

		GetCMD();
}


void SCqss_Dlg::OnEnChangeEditqsssg()
{
	//CString sStr="",sCmd="",sNewCmd="";
	//m_Edit_SG.GetWindowText(sStr);
	//m_Edit_GTQSS.GetWindowText(sCmd);
	//sNewCmd=m_MYWORK.UpdataCMD(sStr,11,sCmd);
	//m_Edit_GTQSS.SetWindowText(sNewCmd);
		GetCMD();
}


void SCqss_Dlg::OnDeltaposSpinHi(NMHDR *pNMHDR, LRESULT *pResult)
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

void SCqss_Dlg::OnEnChangeEditHi()
{
	//CString sStr="",sCmd="",sNewCmd="";
	//m_Edit_HI.GetWindowText(sStr);
	//m_Edit_GTQSS.GetWindowText(sCmd);
	//sNewCmd=m_MYWORK.UpdataCMD(sStr,12,sCmd);
	//m_Edit_GTQSS.SetWindowText(sNewCmd);
		GetCMD();
}

void SCqss_Dlg::OnCbnSelchangeComboBm()
{
	//CString sStr="",sCmd="",sNewCmd="";
	//int iTemp=0;
	//iTemp=m_ComboBox_qssBM.GetCurSel();
	//sStr.Format("%d",iTemp);
	//m_Edit_GTQSS.GetWindowText(sCmd);
	//sNewCmd=m_MYWORK.UpdataCMD(sStr,6,sCmd);
	//m_Edit_GTQSS.SetWindowText(sNewCmd);
			GetCMD();

}

void SCqss_Dlg::OnCbnSelchangeComboSe()
{
	//CString sStr="",sCmd="",sNewCmd="";
	//int iTemp=0;
	//iTemp=m_ComboBox_qssSE.GetCurSel();
	//sStr.Format("%d",iTemp);
	//m_Edit_GTQSS.GetWindowText(sCmd);
	//sNewCmd=m_MYWORK.UpdataCMD(sStr,13,sCmd);
	//m_Edit_GTQSS.SetWindowText(sNewCmd);
			GetCMD();
}

void SCqss_Dlg::OnCbnSelchangeComboPf()
{
	//CString sStr="",sCmd="",sNewCmd="";
	//int iTemp=0;
	//iTemp=m_ComboBox_qssPF.GetCurSel();
	//sStr.Format("%d",iTemp);
	//m_Edit_GTQSS.GetWindowText(sCmd);
	//sNewCmd=m_MYWORK.UpdataCMD(sStr,14,sCmd);
	//m_Edit_GTQSS.SetWindowText(sNewCmd);
			GetCMD();
}

void SCqss_Dlg::OnBnClickedCheckSse()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString sStr="",sCmd="",sNewCmd="";
	//int iTemp=0;
	//iTemp=m_Check_SSE.GetCheck();
	//sStr.Format("%d",iTemp);
	//m_Edit_GTQSS.GetWindowText(sCmd);
	//sNewCmd=m_MYWORK.UpdataCMD(sStr,15,sCmd);
	//m_Edit_GTQSS.SetWindowText(sNewCmd);
			GetCMD();
}

