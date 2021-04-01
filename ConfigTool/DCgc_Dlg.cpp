// DCgc_Dlg.cpp : 实现文件
//
#include "stdafx.h"
#include "ConfigTool.h"
#include "DCgc_Dlg.h"
#include "afxdialogex.h"
///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"
// DCap_Dlg 对话框
extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern DCgc_Dlg m_DCgc_Dlg;
DCgc_Dlg*	lpDCgc_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

// DCgc_Dlg 对话框

IMPLEMENT_DYNAMIC(DCgc_Dlg, CMyTabBaseDlg)

DCgc_Dlg::DCgc_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(DCgc_Dlg::IDD, pParent)
{

}

DCgc_Dlg::~DCgc_Dlg()
{
}

void DCgc_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_PSM, m_ComboBox_PSM);
	DDX_Control(pDX, IDC_COMBO_IM, m_ComboBox_IM);
	DDX_Control(pDX, IDC_COMBO_BBCM, m_ComboBox_BBCM);
	DDX_Control(pDX, IDC_COMBO_SR, m_ComboBox_SR);
	DDX_Control(pDX, IDC_CHECK_CMs, m_Check_CMs);
	DDX_Control(pDX, IDC_CHECK_CMca, m_Check_CMca);
	DDX_Control(pDX, IDC_CHECK_CMa, m_CHECK_CMa);
	DDX_Control(pDX, IDC_CHECK_CMal, m_CHECK_CMal);
	DDX_Control(pDX, IDC_CHECK_CMcind, m_CHECK_CMcind);
	DDX_Control(pDX, IDC_CHECK_CMm, m_CHECK_CMm);
	DDX_Control(pDX, IDC_CHECK_CMst, m_CHECK_CMst);
	DDX_Control(pDX, IDC_CHECK_CMdn, m_CHECK_CMdn);
	DDX_Control(pDX, IDC_CHECK_EMna, m_Check_EMna);
	DDX_Control(pDX, IDC_CHECK_EMfa, m_Check_EMfa);
	DDX_Control(pDX, IDC_CHECK_EMpn, m_Check_EMpn);
	DDX_Control(pDX, IDC_CHECK_EMpf, m_Check_EMpf);
	DDX_Control(pDX, IDC_CHECK_EMr1, m_Check_EMr1);
	DDX_Control(pDX, IDC_CHECK_EMpl, m_Check_EMpl);
	DDX_Control(pDX, IDC_CHECK_EMtc, m_Check_EMtc);
	DDX_Control(pDX, IDC_CHECK_EMtc2, m_Check_EMtc2);
	DDX_Control(pDX, IDC_CHECK_EMtt, m_Check_EMtt);
	DDX_Control(pDX, IDC_CHECK_EMr2, m_Check_EMr2);
	DDX_Control(pDX, IDC_CHECK_EMdp, m_Check_EMdp);
	DDX_Control(pDX, IDC_CHECK_EMnl, m_Check_EMnl);
	DDX_Control(pDX, IDC_CHECK_EMgf, m_Check_EMgf);
	DDX_Control(pDX, IDC_CHECK_EMgl, m_Check_EMgl);
	DDX_Control(pDX, IDC_CHECK_EMca, m_Check_EMca);
	DDX_Control(pDX, IDC_EDIT_DN, m_Edit_DN);
	DDX_Control(pDX, IDC_EDIT_NP, m_Edit_NP);
	DDX_Control(pDX, IDC_EDIT_OIM, m_Edit_OIM);
	DDX_Control(pDX, IDC_CHECK_OE, m_Check_OE);
	DDX_Control(pDX, IDC_CHECK_LO, m_Check_LO);
	DDX_Control(pDX, IDC_CHECK_IRE, m_Check_IRE);
	DDX_Control(pDX, IDC_SPIN_MSP_IRI, m_Spin_IRI);
	DDX_Control(pDX, IDC_EDIT_IRI, m_Edit_IRI);
	DDX_Control(pDX, IDC_SPIN_GLT, m_Spin_GLT);
	DDX_Control(pDX, IDC_EDIT_GLT, m_Edit_GLT);
	DDX_Control(pDX, IDC_COMBO_A, m_ComboBox_A);
}


BEGIN_MESSAGE_MAP(DCgc_Dlg, CMyTabBaseDlg)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MSP, &DCgc_Dlg::OnDeltaposSpinMsp)
	ON_BN_CLICKED(IDC_CHECK_CMca, &DCgc_Dlg::OnBnClickedCheckCmca)
	ON_BN_CLICKED(IDC_CHECK_CMs, &DCgc_Dlg::OnBnClickedCheckCms)
	ON_BN_CLICKED(IDC_CHECK_EMca, &DCgc_Dlg::OnBnClickedCheckEmca)
	ON_EN_CHANGE(IDC_EDIT_DN, &DCgc_Dlg::OnEnChangeEditDn)
	ON_EN_CHANGE(IDC_EDIT_NP, &DCgc_Dlg::OnEnChangeEditNp)
	ON_EN_CHANGE(IDC_EDIT_OIM, &DCgc_Dlg::OnEnChangeEditOim)
	ON_BN_CLICKED(IDC_CHECK_OE, &DCgc_Dlg::OnBnClickedCheckOe)
	ON_CBN_SELCHANGE(IDC_COMBO_PSM, &DCgc_Dlg::OnCbnSelchangeComboPsm)
	ON_CBN_SELCHANGE(IDC_COMBO_IM, &DCgc_Dlg::OnCbnSelchangeComboIm)
	ON_CBN_SELCHANGE(IDC_COMBO_BBCM, &DCgc_Dlg::OnCbnSelchangeComboBbcm)
	ON_CBN_SELCHANGE(IDC_COMBO_SR, &DCgc_Dlg::OnCbnSelchangeComboSr)
	ON_BN_CLICKED(IDC_CHECK_LO, &DCgc_Dlg::OnBnClickedCheckLo)
	ON_BN_CLICKED(IDC_CHECK_CMa, &DCgc_Dlg::OnBnClickedCheckCma)
	ON_BN_CLICKED(IDC_CHECK_CMal, &DCgc_Dlg::OnBnClickedCheckCmal)
	ON_BN_CLICKED(IDC_CHECK_CMcind, &DCgc_Dlg::OnBnClickedCheckCmcind)
	ON_BN_CLICKED(IDC_CHECK_CMm, &DCgc_Dlg::OnBnClickedCheckCmm)
	ON_BN_CLICKED(IDC_CHECK_CMst, &DCgc_Dlg::OnBnClickedCheckCmst)
	ON_BN_CLICKED(IDC_CHECK_CMdn, &DCgc_Dlg::OnBnClickedCheckCmdn)
	ON_BN_CLICKED(IDC_CHECK_EMna, &DCgc_Dlg::OnBnClickedCheckEmna)
	ON_BN_CLICKED(IDC_CHECK_EMfa, &DCgc_Dlg::OnBnClickedCheckEmfa)
	ON_BN_CLICKED(IDC_CHECK_EMpn, &DCgc_Dlg::OnBnClickedCheckEmpn)
	ON_BN_CLICKED(IDC_CHECK_EMpf, &DCgc_Dlg::OnBnClickedCheckEmpf)
	ON_BN_CLICKED(IDC_CHECK_EMr1, &DCgc_Dlg::OnBnClickedCheckEmr1)
	ON_BN_CLICKED(IDC_CHECK_EMpl, &DCgc_Dlg::OnBnClickedCheckEmpl)
	ON_BN_CLICKED(IDC_CHECK_EMtc, &DCgc_Dlg::OnBnClickedCheckEmtc)
	ON_BN_CLICKED(IDC_CHECK_EMtc2, &DCgc_Dlg::OnBnClickedCheckEmtc2)
	ON_BN_CLICKED(IDC_CHECK_EMtt, &DCgc_Dlg::OnBnClickedCheckEmtt)
	ON_BN_CLICKED(IDC_CHECK_EMr2, &DCgc_Dlg::OnBnClickedCheckEmr2)
	ON_BN_CLICKED(IDC_CHECK_EMdp, &DCgc_Dlg::OnBnClickedCheckEmdp)
	ON_BN_CLICKED(IDC_CHECK_EMnl, &DCgc_Dlg::OnBnClickedCheckEmnl)
	ON_BN_CLICKED(IDC_CHECK_EMgf, &DCgc_Dlg::OnBnClickedCheckEmgf)
	ON_BN_CLICKED(IDC_CHECK_EMgl, &DCgc_Dlg::OnBnClickedCheckEmgl)
	ON_BN_CLICKED(IDC_CHECK_IRE, &DCgc_Dlg::OnBnClickedCheckIre)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MSP_IRI, &DCgc_Dlg::OnDeltaposSpinMspIri)
	ON_EN_CHANGE(IDC_EDIT_IRI, &DCgc_Dlg::OnEnChangeEditIri)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_GLT, &DCgc_Dlg::OnDeltaposSpinGlt)
	ON_EN_CHANGE(IDC_EDIT_GLT, &DCgc_Dlg::OnEnChangeEditGlt)
	ON_CBN_SELCHANGE(IDC_COMBO_A, &DCgc_Dlg::OnCbnSelchangeComboA)
END_MESSAGE_MAP()


// DCgc_Dlg 消息处理程序


BOOL DCgc_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpDCgc_Dlg=&m_DCgc_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_DCgc_Dlg;
	m_iWhoamI=GTCFG;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTCFG].sCmdstr);
	                             //AT+GTCFG=HYIoT,,,0,123.4,0,,003F,1,,3BFF,0,0,0,300,10,,0,,,0,0003$
	                                      //HYIoT,nw,HYIoT,0,123.4,,,63,1,,65535,0,0,0,300,0,,0,0,,0,,,,,,,,,,,,FFFF$
	SetDlgItemText(IDC_EDIT_OIM,"123.4");
	SetDlgItemText(IDC_EDIT_IRI,"300");
	m_Spin_IRI.SetBuddy(GetDlgItem(IDC_EDIT_IRI)); //得到指向编辑框的窗口指针
	m_Spin_IRI.SetRange32(0,86400);
	SetDlgItemText(IDC_EDIT_GLT,"0");
	m_Spin_GLT.SetBuddy(GetDlgItem(IDC_EDIT_GLT)); //得到指向编辑框的窗口指针
	m_Spin_GLT.SetRange(0,30);
	////////////////////////////////
	m_ComboBox_PSM.InsertString(0,"0:Disable Power saving Function");
	m_ComboBox_PSM.InsertString(1,"1:GPS Deep saving mode");
	m_ComboBox_PSM.InsertString(2,"2:GPS low saving mode");
	m_ComboBox_PSM.SetCurSel(1);
	////////////////////////////////
	m_ComboBox_IM.InsertString(0,"0 means input");
	m_ComboBox_IM.InsertString(1,"1 means output");
	m_ComboBox_IM.SetCurSel(0);
	////////////////////////////////
	m_ComboBox_BBCM.InsertString(0,"0:Charge on need");
	m_ComboBox_BBCM.InsertString(1,"1:Charge when ignition on");
	m_ComboBox_BBCM.SetCurSel(0);
	////////////////////////////////
	m_ComboBox_SR.InsertString(0,"00:disable request position");
	m_ComboBox_SR.InsertString(1,"10:Report the current position(+RESP:GTLBC) when the device receives SMS Position Request Message via SMS");
	m_ComboBox_SR.InsertString(2,"20:Report the current position with a Google Map link through SMS to the original number when the device receives SMS Position Request via SMS ");
	m_ComboBox_SR.SetCurSel(0);
	///////////////
	m_Check_CMca.SetCheck(0);
	m_Check_CMs.SetCheck(1);
	m_CHECK_CMa.SetCheck(1);
	m_CHECK_CMal.SetCheck(1);
	m_CHECK_CMcind.SetCheck(1);
	m_CHECK_CMm.SetCheck(1);
	m_CHECK_CMst.SetCheck(1);
	m_CHECK_CMdn.SetCheck(0);	
	////
	m_Check_EMca.SetCheck(1);
	m_Check_EMna.SetCheck(1);
	m_Check_EMfa.SetCheck(1);
	m_Check_EMpn.SetCheck(1);
	m_Check_EMpf.SetCheck(1);
	m_Check_EMr1.SetCheck(1);
	m_Check_EMpl.SetCheck(1);
	m_Check_EMtc.SetCheck(1);
	m_Check_EMtc2.SetCheck(1);
	m_Check_EMtt.SetCheck(1);
	m_Check_EMr2.SetCheck(1);
	m_Check_EMdp.SetCheck(0);
	m_Check_EMnl.SetCheck(1);
	m_Check_EMgf.SetCheck(1);
	m_Check_EMgl.SetCheck(1);

	m_ComboBox_A.InsertString(0,"0: Disable the AGPS function.");
	m_ComboBox_A.InsertString(1,"1: AGPS Offline mode.");
	m_ComboBox_A.SetCurSel(0);
	///////////////
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString DCgc_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL DCgc_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>20)
	{
		m_ComboBox_PSM.SetCurSel(atoi(ValueList.GetAt(8)));
		OnCbnSelchangeComboPsm();
		m_ComboBox_IM.SetCurSel(atoi(ValueList.GetAt(11)));
		OnCbnSelchangeComboIm();
		m_ComboBox_BBCM.SetCurSel(atoi(ValueList.GetAt(17)));
		OnCbnSelchangeComboBbcm();

		if (("00"==ValueList.GetAt(15))||("0"==ValueList.GetAt(15)))
		{
			m_ComboBox_SR.SetCurSel(0);
		}
		if ("10"==ValueList.GetAt(15))
		{
			m_ComboBox_SR.SetCurSel(1);
		}
		if ("20"==ValueList.GetAt(15))
		{
			m_ComboBox_SR.SetCurSel(2);
		}
		OnCbnSelchangeComboSr();

		m_ComboBox_A.SetCurSel(atoi(ValueList.GetAt(18)));
		OnCbnSelchangeComboA();

		m_Check_OE.SetCheck(atoi(ValueList.GetAt(3)));
		OnBnClickedCheckOe();
		m_Check_LO.SetCheck(atoi(ValueList.GetAt(12)));
		OnBnClickedCheckLo();
		m_Check_IRE.SetCheck(atoi(ValueList.GetAt(13)));
		OnBnClickedCheckIre();

		m_Edit_DN.SetWindowText(ValueList.GetAt(2));
		m_Edit_NP.SetWindowText(ValueList.GetAt(1));

		m_Edit_OIM.SetWindowText(ValueList.GetAt(4));
		m_Edit_NP.SetWindowText(ValueList.GetAt(1));
		m_Edit_IRI.SetWindowText(ValueList.GetAt(14));
		m_Edit_GLT.SetWindowText(ValueList.GetAt(20));

		SetCMValue(ValueList.GetAt(7));

		SetEMValue(ValueList.GetAt(10));

		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}


void DCgc_Dlg::OnDeltaposSpinMsp(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void DCgc_Dlg::OnBnClickedCheckCmca()
{
	// TODO: 在此添加控件通知处理程序代码
	int iTemp=0;
	iTemp=m_Check_CMca.GetCheck();
	if (iTemp)
	{
		m_Check_CMs.SetCheck(1);
		m_CHECK_CMa.SetCheck(1);
		m_CHECK_CMal.SetCheck(1);
		m_CHECK_CMcind.SetCheck(1);
		m_CHECK_CMm.SetCheck(1);
		m_CHECK_CMst.SetCheck(1);
		m_CHECK_CMdn.SetCheck(1);	

	}
	else
	{
		m_Check_CMs.SetCheck(0);
		m_CHECK_CMa.SetCheck(0);
		m_CHECK_CMal.SetCheck(0);
		m_CHECK_CMcind.SetCheck(0);
		m_CHECK_CMm.SetCheck(0);
		m_CHECK_CMst.SetCheck(0);
		m_CHECK_CMdn.SetCheck(0);	
	}
	  GetCMValue();
}


void DCgc_Dlg::OnBnClickedCheckCms()
{
  GetCMValue();
}

void DCgc_Dlg::GetCMValue()
{
	int iB0=0,iB1=0,iB2=0,iB3=0,iB4=0,iB5=0,iB6=0;
	CString sStrB="",sStrH="",sCmd="",sNewCmd="";
	iB6=m_CHECK_CMdn.GetCheck();	
	iB5=m_CHECK_CMst.GetCheck();	
	iB4=m_CHECK_CMm.GetCheck();
	iB3=m_CHECK_CMcind.GetCheck();
	iB2=m_CHECK_CMal.GetCheck();
	iB1=m_CHECK_CMa.GetCheck();	
	iB0=m_Check_CMs.GetCheck();
	sStrB.Format("%d%d%d%d%d%d%d",iB6,iB5,iB4,iB3,iB2,iB1,iB0);
	m_MYWORK.BsToHex(sStrB,sStrH,4);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStrH,7,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void DCgc_Dlg::SetCMValue(CString sStrH)
{
	CString sStrB="",sTemp="";
	int iB0=0,iB1=0,iB2=0,iB3=0,iB4=0,iB5=0,iB6=0;
	m_MYWORK.HexToBsStr(sStrH,sStrB,7);

	sTemp.Format("%c",sStrB[0]);
	iB6=atoi(sTemp);
	m_CHECK_CMdn.SetCheck(iB6);

	sTemp.Format("%c",sStrB[1]);
	iB5=atoi(sTemp);
	m_CHECK_CMst.SetCheck(iB5);

	sTemp.Format("%c",sStrB[2]);
	iB4=atoi(sTemp);
	m_CHECK_CMm.SetCheck(iB4);
	sTemp.Format("%c",sStrB[3]);
	iB3=atoi(sTemp);
	m_CHECK_CMcind.SetCheck(iB3);
	sTemp.Format("%c",sStrB[4]);
	iB2=atoi(sTemp);
	m_CHECK_CMal.SetCheck(iB2);
	sTemp.Format("%c",sStrB[5]);
	iB1=atoi(sTemp);
	m_CHECK_CMa.SetCheck(iB1);
	sTemp.Format("%c",sStrB[6]);
	iB0=atoi(sTemp);
	m_Check_CMs.SetCheck(iB0);

	GetCMValue();

}

void DCgc_Dlg::GetEMValue()
{
	int iB0=0,iB1=0,iB2=0,iB3=0,iB4=0,iB5=0,iB6=0,iB7=0,iB8=0,iB9=0,iB10=0,iB11=0,iB12=0,iB13=0;
	CString sStrB="",sStrH="",sCmd="",sNewCmd="";

	iB0=m_Check_EMna.GetCheck();
	iB1=m_Check_EMfa.GetCheck();
	iB2=m_Check_EMpn.GetCheck();
	iB3=m_Check_EMpf.GetCheck();
	iB4=m_Check_EMr1.GetCheck();
	iB5=m_Check_EMpl.GetCheck();
	iB6=m_Check_EMtc.GetCheck();
	iB7=m_Check_EMtc2.GetCheck();
	iB8=m_Check_EMtt.GetCheck();
	iB9=m_Check_EMr2.GetCheck();
	iB10=m_Check_EMdp.GetCheck();
	iB11=m_Check_EMnl.GetCheck();
	iB12=m_Check_EMgf.GetCheck();
	iB13=m_Check_EMgl.GetCheck();

	sStrB.Format("%d%d%d%d%d%d%d%d%d%d%d%d%d%d",iB13,iB12,iB11,iB10,iB9,iB8,iB7,iB6,iB5,iB4,iB3,iB2,iB1,iB0);
	m_MYWORK.BsToHex(sStrB,sStrH,4);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStrH,10,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void DCgc_Dlg::SetEMValue(CString sStrH)
{
	CString sStrB="",sTemp="";
	int iB0=0,iB1=0,iB2=0,iB3=0,iB4=0,iB5=0,iB6=0,iB7=0,iB8=0,iB9=0,iB10=0,iB11=0,iB12=0,iB13=0;
	m_MYWORK.HexToBsStr(sStrH,sStrB,14);
	sTemp.Format("%c",sStrB[0]);
	iB13=atoi(sTemp);
	m_Check_EMgl.SetCheck(iB13);
	sTemp.Format("%c",sStrB[1]);
	iB12=atoi(sTemp);
	m_Check_EMgf.SetCheck(iB12);
	sTemp.Format("%c",sStrB[2]);
	iB11=atoi(sTemp);
	m_Check_EMnl.SetCheck(iB11);
	sTemp.Format("%c",sStrB[3]);
	iB10=atoi(sTemp);
	m_Check_EMdp.SetCheck(iB10);
	sTemp.Format("%c",sStrB[4]);
	iB9=atoi(sTemp);
	m_Check_EMr2.SetCheck(iB9);
	sTemp.Format("%c",sStrB[5]);
	iB8=atoi(sTemp);
	m_Check_EMtt.SetCheck(iB8);

	sTemp.Format("%c",sStrB[6]);
	iB7=atoi(sTemp);
	m_Check_EMtc2.SetCheck(iB7);

	sTemp.Format("%c",sStrB[7]);
	iB6=atoi(sTemp);
	m_Check_EMtc.SetCheck(iB6);
	sTemp.Format("%c",sStrB[8]);
	iB5=atoi(sTemp);
	m_Check_EMpl.SetCheck(iB5);
	sTemp.Format("%c",sStrB[9]);
	iB4=atoi(sTemp);
	m_Check_EMr1.SetCheck(iB4);
	sTemp.Format("%c",sStrB[10]);
	iB3=atoi(sTemp);
	m_Check_EMpf.SetCheck(iB3);
	sTemp.Format("%c",sStrB[11]);
	iB2=atoi(sTemp);
	m_Check_EMpn.SetCheck(iB2);
	sTemp.Format("%c",sStrB[12]);
	iB1=atoi(sTemp);
	m_Check_EMfa.SetCheck(iB1);
	sTemp.Format("%c",sStrB[13]);
	iB0=atoi(sTemp);
	m_Check_EMna.SetCheck(iB0);
	
	GetEMValue();

}


void DCgc_Dlg::OnBnClickedCheckEmca()
{
	// TODO: 在此添加控件通知处理程序代码
	int iTemp=0;
	iTemp=m_Check_EMca.GetCheck();
	if (iTemp)
	{
		m_Check_EMna.SetCheck(1);
		m_Check_EMfa.SetCheck(1);
		m_Check_EMpn.SetCheck(1);
		m_Check_EMpf.SetCheck(1);
		m_Check_EMr1.SetCheck(1);
		m_Check_EMpl.SetCheck(1);
		m_Check_EMtc.SetCheck(1);
		m_Check_EMtc2.SetCheck(1);
		m_Check_EMtt.SetCheck(1);
		m_Check_EMr2.SetCheck(1);
		m_Check_EMdp.SetCheck(1);
		m_Check_EMnl.SetCheck(1);
		m_Check_EMgf.SetCheck(1);
		m_Check_EMgl.SetCheck(1);

	}
	else
	{
		m_Check_EMca.SetCheck(0);
		m_Check_EMna.SetCheck(0);
		m_Check_EMfa.SetCheck(0);
		m_Check_EMpn.SetCheck(0);
		m_Check_EMpf.SetCheck(0);
		m_Check_EMr1.SetCheck(0);
		m_Check_EMpl.SetCheck(0);
		m_Check_EMtc.SetCheck(0);
		m_Check_EMtc2.SetCheck(0);
		m_Check_EMtt.SetCheck(0);
		m_Check_EMr2.SetCheck(0);
		m_Check_EMdp.SetCheck(0);
		m_Check_EMnl.SetCheck(0);
		m_Check_EMgf.SetCheck(0);
		m_Check_EMgl.SetCheck(0);
	}
		GetEMValue();
}

void DCgc_Dlg::OnEnChangeEditDn()
{
	CString sStr="",sCmd="",sNewCmd="";
	m_Edit_DN.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,2,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void DCgc_Dlg::OnEnChangeEditNp()
{
	CString sStr="",sCmd="",sNewCmd="";
	m_Edit_NP.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void DCgc_Dlg::OnEnChangeEditOim()
{
	CString sStr="",sCmd="",sNewCmd="";
	m_Edit_OIM.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,4,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void DCgc_Dlg::OnBnClickedCheckOe()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_OE.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,3,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void DCgc_Dlg::OnCbnSelchangeComboPsm()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_PSM.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,8,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void DCgc_Dlg::OnCbnSelchangeComboIm()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_IM.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,11,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void DCgc_Dlg::OnCbnSelchangeComboBbcm()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_BBCM.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,17,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);	
}


void DCgc_Dlg::OnCbnSelchangeComboSr()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_SR.GetCurSel();
	if (iTemp==0)
	{
		sStr.Format("00");
	}
	if (iTemp==1)
	{
		sStr.Format("10");
	}
	if (iTemp==2)
	{
		sStr.Format("20");
	}
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,15,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);

}


void DCgc_Dlg::OnBnClickedCheckLo()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_LO.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,12,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void DCgc_Dlg::OnBnClickedCheckCma()
{
	// TODO: 在此添加控件通知处理程序代码
	  GetCMValue();
}


void DCgc_Dlg::OnBnClickedCheckCmal()
{
	// TODO: 在此添加控件通知处理程序代码
	  GetCMValue();
}


void DCgc_Dlg::OnBnClickedCheckCmcind()
{
	// TODO: 在此添加控件通知处理程序代码
	  GetCMValue();
}


void DCgc_Dlg::OnBnClickedCheckCmm()
{
	// TODO: 在此添加控件通知处理程序代码
	  GetCMValue();
}


void DCgc_Dlg::OnBnClickedCheckCmst()
{
	// TODO: 在此添加控件通知处理程序代码
	  GetCMValue();
}


void DCgc_Dlg::OnBnClickedCheckCmdn()
{
	// TODO: 在此添加控件通知处理程序代码
	  GetCMValue();
}


void DCgc_Dlg::OnBnClickedCheckEmna()
{
	// TODO: 在此添加控件通知处理程序代码
	GetEMValue();
}


void DCgc_Dlg::OnBnClickedCheckEmfa()
{
	// TODO: 在此添加控件通知处理程序代码
		GetEMValue();
}


void DCgc_Dlg::OnBnClickedCheckEmpn()
{
	// TODO: 在此添加控件通知处理程序代码
		GetEMValue();
}


void DCgc_Dlg::OnBnClickedCheckEmpf()
{
	// TODO: 在此添加控件通知处理程序代码
		GetEMValue();
}


void DCgc_Dlg::OnBnClickedCheckEmr1()
{
	// TODO: 在此添加控件通知处理程序代码
		GetEMValue();
}


void DCgc_Dlg::OnBnClickedCheckEmpl()
{
	// TODO: 在此添加控件通知处理程序代码
		GetEMValue();
}


void DCgc_Dlg::OnBnClickedCheckEmtc()
{
	// TODO: 在此添加控件通知处理程序代码
		GetEMValue();
}


void DCgc_Dlg::OnBnClickedCheckEmtc2()
{
	// TODO: 在此添加控件通知处理程序代码
		GetEMValue();
}


void DCgc_Dlg::OnBnClickedCheckEmtt()
{
	// TODO: 在此添加控件通知处理程序代码
		GetEMValue();
}


void DCgc_Dlg::OnBnClickedCheckEmr2()
{
	// TODO: 在此添加控件通知处理程序代码
		GetEMValue();
}


void DCgc_Dlg::OnBnClickedCheckEmdp()
{
	// TODO: 在此添加控件通知处理程序代码
		GetEMValue();
}


void DCgc_Dlg::OnBnClickedCheckEmnl()
{
	// TODO: 在此添加控件通知处理程序代码
		GetEMValue();
}


void DCgc_Dlg::OnBnClickedCheckEmgf()
{
	// TODO: 在此添加控件通知处理程序代码
		GetEMValue();
}


void DCgc_Dlg::OnBnClickedCheckEmgl()
{
	// TODO: 在此添加控件通知处理程序代码
		GetEMValue();
}

void DCgc_Dlg::OnBnClickedCheckIre()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_IRE.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,13,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);

}


void DCgc_Dlg::OnDeltaposSpinMspIri(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_IRI.GetPos();
	m_Spin_IRI.SetPos(iTemp);
	m_Edit_IRI.GetWindowText(strValue);                 //得到编辑框中的内容

	*pResult = 0;
}

//15
void DCgc_Dlg::OnEnChangeEditIri()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	m_Edit_IRI.GetWindowText(sStr);
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
	sNewCmd=UpdataCMD(strDigit,14,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void DCgc_Dlg::OnDeltaposSpinGlt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_GLT.GetPos();
	m_Spin_GLT.SetPos(iTemp);
	m_Edit_GLT.GetWindowText(strValue);                 //得到编辑框中的内容
	
	*pResult = 0;
}

//21
void DCgc_Dlg::OnEnChangeEditGlt()
{
	CString sStr="",sCmd="",sNewCmd="";
	m_Edit_GLT.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,20,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//19
void DCgc_Dlg::OnCbnSelchangeComboA()
{

	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_A.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,18,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}
