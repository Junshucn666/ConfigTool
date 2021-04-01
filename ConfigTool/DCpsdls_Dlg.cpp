// DCpsdls_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "DCpsdls_Dlg.h"
#include "afxdialogex.h"

///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"
// DCap_Dlg 对话框
extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern DCpsdls_Dlg m_DCpsdls_Dlg;
DCpsdls_Dlg*	lpDCpsdls_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(DCpsdls_Dlg, CMyTabBaseDlg)

DCpsdls_Dlg::DCpsdls_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(DCpsdls_Dlg::IDD, pParent)
{

}

DCpsdls_Dlg::~DCpsdls_Dlg()
{
}

void DCpsdls_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_CHECK_SoG, m_Check_SoG);
	DDX_Control(pDX, IDC_CHECK_Rb1, m_Check_Rb1);
	DDX_Control(pDX, IDC_CHECK_Rb2, m_Check_Rb2);
	DDX_Control(pDX, IDC_CHECK_Iolkp, m_Check_Iolkp);
	DDX_Control(pDX, IDC_CHECK_Soi, m_Check_Soi);
	DDX_Control(pDX, IDC_CHECK_Sows, m_Check_Sows);
	DDX_Control(pDX, IDC_CHECK_Sodi, m_Check_Sodi);
	DDX_Control(pDX, IDC_CHECK_SoS, m_Check_SoS);
	DDX_Control(pDX, IDC_CHECK_SSR, m_Check_SSR);
	DDX_Control(pDX, IDC_CHECK_Somp, m_Check_Somp);
	DDX_Control(pDX, IDC_CHECK_PEO, m_Check_PEO);
	DDX_Control(pDX, IDC_CHECK_ca, m_Check_Ca);
}


BEGIN_MESSAGE_MAP(DCpsdls_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &DCpsdls_Dlg::OnCbnSelchangeComboM)
	ON_BN_CLICKED(IDC_CHECK_SoG, &DCpsdls_Dlg::OnBnClickedCheckSog)
	ON_BN_CLICKED(IDC_CHECK_Rb1, &DCpsdls_Dlg::OnBnClickedCheckRb1)
	ON_BN_CLICKED(IDC_CHECK_Rb2, &DCpsdls_Dlg::OnBnClickedCheckRb2)
	ON_BN_CLICKED(IDC_CHECK_Iolkp, &DCpsdls_Dlg::OnBnClickedCheckIolkp)
	ON_BN_CLICKED(IDC_CHECK_Soi, &DCpsdls_Dlg::OnBnClickedCheckSoi)
	ON_BN_CLICKED(IDC_CHECK_Sows, &DCpsdls_Dlg::OnBnClickedCheckSows)
	ON_BN_CLICKED(IDC_CHECK_Sodi, &DCpsdls_Dlg::OnBnClickedCheckSodi)
	ON_BN_CLICKED(IDC_CHECK_SoS, &DCpsdls_Dlg::OnBnClickedCheckSos)
	ON_BN_CLICKED(IDC_CHECK_SSR, &DCpsdls_Dlg::OnBnClickedCheckSsr)
	ON_BN_CLICKED(IDC_CHECK_Somp, &DCpsdls_Dlg::OnBnClickedCheckSomp)
	ON_BN_CLICKED(IDC_CHECK_PEO, &DCpsdls_Dlg::OnBnClickedCheckPeo)
	ON_BN_CLICKED(IDC_CHECK_ca, &DCpsdls_Dlg::OnBnClickedCheckca)
END_MESSAGE_MAP()


// DCpsdls_Dlg 消息处理程序


BOOL DCpsdls_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpDCpsdls_Dlg=&m_DCpsdls_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_DCpsdls_Dlg;
	m_iWhoamI=GTPDS;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTPDS].sCmdstr);

	m_ComboBox_M.InsertString(0,"Disable this function");
	m_ComboBox_M.InsertString(1,"Preserve Device State");
	m_ComboBox_M.InsertString(2,"Reset ogical states list in the <Mask>");
	m_ComboBox_M.SetCurSel(1);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString DCpsdls_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL DCpsdls_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>2)
	{
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboM();
		SetMSValue(ValueList.GetAt(2));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
}
//2
void DCpsdls_Dlg::OnCbnSelchangeComboM()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_M.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//3
void DCpsdls_Dlg::GetMSValue()
{
	int iB1,iB2,iB3,iB4,iB5,iB6,iB7,iB8,iB9,iBa,iBb;
	CString sStrB="",sStrH="",sCmd="",sNewCmd="";

	iB1=m_Check_SoG.GetCheck();
	iB2=m_Check_Rb1.GetCheck();
	iB3=m_Check_Rb2.GetCheck();
	iB4=m_Check_Iolkp.GetCheck();
	iB5=m_Check_Soi.GetCheck();
	iB6=m_Check_Sows.GetCheck();
	iB7=m_Check_Sodi.GetCheck();
	iB8=m_Check_SoS.GetCheck();
	iB9=m_Check_SSR.GetCheck();
	iBa=m_Check_Somp.GetCheck();
	iBb=m_Check_PEO.GetCheck();

	sStrB.Format("%d%d%d%d%d%d%d%d%d%d%d",iBb,iBa,iB9,iB8,iB7,iB6,iB5,iB4,iB3,iB2,iB1);
	m_MYWORK.BsToHex(sStrB,sStrH,4);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStrH,2,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void DCpsdls_Dlg::SetMSValue(CString sStrH)
{
	CString sStrB="",sTemp="";
	int iB0=0,iB1=0,iB2,iB3,iB4,iB5,iB6,iB7,iB8,iB9,iB10;
	m_MYWORK.HexToBsStr(sStrH,sStrB,11);

	sTemp.Format("%c",sStrB[0]);
	iB10=atoi(sTemp);
	m_Check_PEO.SetCheck(iB10);

	sTemp.Format("%c",sStrB[1]);
	iB9=atoi(sTemp);
	m_Check_Somp.SetCheck(iB9);

	sTemp.Format("%c",sStrB[2]);
	iB8=atoi(sTemp);
	m_Check_SSR.SetCheck(iB8);
	sTemp.Format("%c",sStrB[3]);
	iB7=atoi(sTemp);
	m_Check_SoS.SetCheck(iB7);
	sTemp.Format("%c",sStrB[4]);
	iB6=atoi(sTemp);
	m_Check_Sodi.SetCheck(iB6);
	sTemp.Format("%c",sStrB[5]);
	iB5=atoi(sTemp);
	m_Check_Sows.SetCheck(iB5);
	sTemp.Format("%c",sStrB[6]);
	iB4=atoi(sTemp);
	m_Check_Soi.SetCheck(iB4);
	sTemp.Format("%c",sStrB[7]);
	iB3=atoi(sTemp);
	m_Check_Iolkp.SetCheck(iB3);
	sTemp.Format("%c",sStrB[8]);
	iB2=atoi(sTemp);
	m_Check_Rb2.SetCheck(iB2);
	sTemp.Format("%c",sStrB[9]);
	iB1=atoi(sTemp);
	m_Check_Rb1.SetCheck(iB1);
	sTemp.Format("%c",sStrB[10]);
	iB0=atoi(sTemp);
	m_Check_SoG.SetCheck(iB0);

	GetMSValue();
}

void DCpsdls_Dlg::OnBnClickedCheckSog()
{
	GetMSValue();
}


void DCpsdls_Dlg::OnBnClickedCheckRb1()
{
		GetMSValue();
}


void DCpsdls_Dlg::OnBnClickedCheckRb2()
{
		GetMSValue();
}


void DCpsdls_Dlg::OnBnClickedCheckIolkp()
{
	GetMSValue();
}


void DCpsdls_Dlg::OnBnClickedCheckSoi()
{
	GetMSValue();
}


void DCpsdls_Dlg::OnBnClickedCheckSows()
{
	GetMSValue();
}


void DCpsdls_Dlg::OnBnClickedCheckSodi()
{
	GetMSValue();
}


void DCpsdls_Dlg::OnBnClickedCheckSos()
{
	GetMSValue();
}


void DCpsdls_Dlg::OnBnClickedCheckSsr()
{
	GetMSValue();
}


void DCpsdls_Dlg::OnBnClickedCheckSomp()
{
	GetMSValue();
}


void DCpsdls_Dlg::OnBnClickedCheckPeo()
{
	GetMSValue();
}


void DCpsdls_Dlg::OnBnClickedCheckca()
{
	int iTemp=0;
	iTemp=m_Check_Ca.GetCheck();
	if (iTemp)
	{
		m_Check_SoG.SetCheck(1);
		m_Check_Rb1.SetCheck(1);
		m_Check_Rb2.SetCheck(1);
		m_Check_Iolkp.SetCheck(1);
		m_Check_Soi.SetCheck(1);
		m_Check_Sows.SetCheck(1);
		m_Check_Sodi.SetCheck(1);
		m_Check_SoS.SetCheck(1);
		m_Check_SSR.SetCheck(1);
		m_Check_Somp.SetCheck(1);
		m_Check_PEO.SetCheck(1);
	}
	else
	{
		m_Check_SoG.SetCheck(0);
		m_Check_Rb1.SetCheck(0);
		m_Check_Rb2.SetCheck(0);
		m_Check_Iolkp.SetCheck(0);
		m_Check_Soi.SetCheck(0);
		m_Check_Sows.SetCheck(0);
		m_Check_Sodi.SetCheck(0);
		m_Check_SoS.SetCheck(0);
		m_Check_SSR.SetCheck(0);
		m_Check_Somp.SetCheck(0);
		m_Check_PEO.SetCheck(0);
	}
	GetMSValue();
}


