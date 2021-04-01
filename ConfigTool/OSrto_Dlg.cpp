// OSrto_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "OSrto_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern OSrto_Dlg m_OSrto_Dlg;
OSrto_Dlg*	lpOSrto_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(OSrto_Dlg, CMyTabBaseDlg)

OSrto_Dlg::OSrto_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(OSrto_Dlg::IDD, pParent)
{

}

OSrto_Dlg::~OSrto_Dlg()
{
}

void OSrto_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SC, m_ComboBox_SC);
	DDX_Control(pDX, IDC_COMBO_OD, m_ComboBox_OD);
}


BEGIN_MESSAGE_MAP(OSrto_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_RM, &OSrto_Dlg::OnCbnSelchangeComboRm)
	ON_CBN_SELCHANGE(IDC_COMBO_SC, &OSrto_Dlg::OnCbnSelchangeComboSc)
	ON_CBN_SELCHANGE(IDC_COMBO_OD, &OSrto_Dlg::OnCbnSelchangeComboOd)
END_MESSAGE_MAP()


// OSrto_Dlg 消息处理程序

BOOL OSrto_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpOSrto_Dlg=&m_OSrto_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_OSrto_Dlg;
	m_iWhoamI=GTRTO;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTRTO].sCmdstr);
	m_ComboBox_SC.InsertString(0,"0: GPS. Get the GPS related information via message +RESP: GTGPS.");
	m_ComboBox_SC.InsertString(1,"1: RTL. Request the terminal to report its current position immediately via message +RESP: GTRTL");
	m_ComboBox_SC.InsertString(2,"2: READ. Get the current configuration of the terminal via message +RESP: GTALM or +RESP: GTALS or +RESP: GTALC.");
	m_ComboBox_SC.InsertString(3,"3: REBOOT. Reboot the terminal.");
	m_ComboBox_SC.InsertString(4,"4: RESET. Reset all parameters to factory setting. Parameters configured by AT+GTBSI, AT+GTSRI, AT+GTCFG,AT+GTPIN and AT+GTTMA will not be reset.");
	m_ComboBox_SC.InsertString(5,"5: PWROFF. Power off the device.");
	m_ComboBox_SC.InsertString(6,"6: CID. Get the ICCID of the SIM card which is being used by the terminal via message +RESP:GTCID.");
	m_ComboBox_SC.InsertString(7,"7: CSQ. Get the current received signal strength of the terminal via message +RESP: GTCSQ.");
	m_ComboBox_SC.InsertString(8,"8: VER. Get the version information of the device via message +RESP: GTVER.");
	m_ComboBox_SC.InsertString(9,"9: BAT. Get the battery percentage and adapter status of the terminal via message +RESP: GTBAT.");
	m_ComboBox_SC.InsertString(10,"A: IOS. Get status of all the IO ports via message +RESP: GTIOS.");
	m_ComboBox_SC.InsertString(11,"B: TMZ. Get the time zone settings via message +RESP:GTTMZ.");
	m_ComboBox_SC.InsertString(12,"E: GSV: Request the device to report the GPS fix level.");
	m_ComboBox_SC.InsertString(13,"F: INF: Read the device information report function. The corresponding information will be reported via the message +RESP:GTINF.");
	m_ComboBox_SC.InsertString(14,"13: CLASC. Clear calibration data.");
	m_ComboBox_SC.InsertString(15,"14: DELBUF. Delete all the buffered reports.");
	m_ComboBox_SC.InsertString(16,"15: LGNMSG. It is used to store configuration string in the device. The configuration string is a summary of the current Device Settings");
	m_ComboBox_SC.SetCurSel(0);
	m_ComboBox_OD.InsertString(0,"0: The message will be output to the backend server.");
	m_ComboBox_OD.InsertString(1,"1: The message will be output to the main serial port.");
	m_ComboBox_OD.InsertString(2,"2: Reserved.");
	m_ComboBox_OD.InsertString(3,"3: If the command is received via SMS, the message will be output to the original SMS number.");
	m_ComboBox_OD.SetCurSel(0);
	// TODO:  在此添加额外的初始化
		///////////////////////////////////////////
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


CString OSrto_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL OSrto_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>3)
	{
		if (atoi(ValueList.GetAt(1))<=9)
		{
			m_ComboBox_SC.SetCurSel(atoi(ValueList.GetAt(1)));
		}
		else if (ValueList.GetAt(1)=="A")
		{
			m_ComboBox_SC.SetCurSel(10);
		}
		else if (ValueList.GetAt(1)=="B")
		{
			m_ComboBox_SC.SetCurSel(11);
		}
		else if (ValueList.GetAt(1)=="E")
		{
			m_ComboBox_SC.SetCurSel(12);
		}
		else if  (ValueList.GetAt(1)=="F")
		{
			m_ComboBox_SC.SetCurSel(13);
		}
		else if  (ValueList.GetAt(1)=="13")
		{
			m_ComboBox_SC.SetCurSel(14);
		}
		else if  (ValueList.GetAt(1)=="14")
		{
			m_ComboBox_SC.SetCurSel(15);
		}
		else if  (ValueList.GetAt(1)=="15")
		{
			m_ComboBox_SC.SetCurSel(16);
		}
		OnCbnSelchangeComboSc();

		m_ComboBox_OD.SetCurSel(atoi(ValueList.GetAt(3)));
		OnCbnSelchangeComboOd();
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}

	
}





void OSrto_Dlg::OnCbnSelchangeComboRm()
{
	// TODO: 在此添加控件通知处理程序代码
}


void OSrto_Dlg::OnCbnSelchangeComboSc()
{

	///////////////
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_SC.GetCurSel();
	if (iTemp<=9)
	{
		sStr.Format("%d",iTemp);
	}
	else if (iTemp==10)
	{
		sStr="A";
	}
	else if (iTemp==11)
	{
		sStr="B";
	}
	else if (iTemp==12)
	{
		sStr="E";
	}
	else if (iTemp==13)
	{
		sStr="F";
	}
	else if (iTemp==14)
	{
		sStr="13";
	}
	else if (iTemp==15)
	{
		sStr="14";
	}
	else if (iTemp==16)
	{
		sStr="15";
	}
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void OSrto_Dlg::OnCbnSelchangeComboOd()
{

	///////////////
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_OD.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,3,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}
