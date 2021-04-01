// ASgc_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ASgc_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern ASgc_Dlg m_ASgc_Dlg;
ASgc_Dlg*	lpASgc_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
extern ASgc_Dlg m_ASgc_Dlg;
#define dMax 180.0
#define dMin -180.0
////////////

IMPLEMENT_DYNAMIC(ASgc_Dlg, CMyTabBaseDlg)

ASgc_Dlg::ASgc_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(ASgc_Dlg::IDD, pParent)
	//,m_LotdNum(0),m_LondNum(0)
{
	m_LotdNum = 31.187891;
    m_LondNum = 121.412248;
}

ASgc_Dlg::~ASgc_Dlg()
{
}

void ASgc_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDV_MinMaxDouble(pDX, m_LotdNum, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_LondNum, dMin, dMax);
	DDX_Control(pDX, IDC_COMBO_GI, m_ComboBox_GI);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_SPIN_Lat, m_Spin_Lat);
	DDX_Control(pDX, IDC_EDIT_Lat, m_Edit_Lat);
	DDX_Control(pDX, IDC_EDIT_Lon, m_Edit_Lon);
	DDX_Control(pDX, IDC_SPIN_R, m_Spin_R);
	DDX_Control(pDX, IDC_EDIT_R, m_Edit_R);
	DDX_Control(pDX, IDC_SPIN_CI, m_Spin_CI);
	DDX_Control(pDX, IDC_EDIT_CI, m_Edit_CI);
	DDX_Control(pDX, IDC_COMBO_OI, m_ComboBox_OI);
	DDX_Control(pDX, IDC_CHECK_OutS, m_Check_OutS);
	DDX_Control(pDX, IDC_SPIN_D, m_Spin_D);
	DDX_Control(pDX, IDC_EDIT_D, m_Edit_D);
	DDX_Control(pDX, IDC_SPIN_TT, m_Spin_TT);
	DDX_Control(pDX, IDC_EDIT_TT, m_Edit_TT);
	DDX_Control(pDX, IDC_COMBO_TM, m_ComboBox_TM);
	DDX_Control(pDX, IDC_COMBO_TR, m_ComboBox_TR);
}


BEGIN_MESSAGE_MAP(ASgc_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_GI, &ASgc_Dlg::OnCbnSelchangeComboGi)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &ASgc_Dlg::OnCbnSelchangeComboM)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Lat, &ASgc_Dlg::OnDeltaposSpinLat)
	ON_EN_CHANGE(IDC_EDIT_Lat, &ASgc_Dlg::OnEnChangeEditLat)
	ON_EN_CHANGE(IDC_EDIT_Lon, &ASgc_Dlg::OnEnChangeEditLon)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_R, &ASgc_Dlg::OnDeltaposSpinR)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_CI, &ASgc_Dlg::OnDeltaposSpinCi)
	ON_EN_CHANGE(IDC_EDIT_R, &ASgc_Dlg::OnEnChangeEditR)
	ON_EN_CHANGE(IDC_EDIT_CI, &ASgc_Dlg::OnEnChangeEditCi)
	ON_CBN_SELCHANGE(IDC_COMBO_OI, &ASgc_Dlg::OnCbnSelchangeComboOi)
	ON_BN_CLICKED(IDC_CHECK_OutS, &ASgc_Dlg::OnBnClickedCheckOuts)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D, &ASgc_Dlg::OnDeltaposSpinD)
	ON_EN_CHANGE(IDC_EDIT_D, &ASgc_Dlg::OnEnChangeEditD)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT, &ASgc_Dlg::OnDeltaposSpinTt)
	ON_EN_CHANGE(IDC_EDIT_TT, &ASgc_Dlg::OnEnChangeEditTt)
	ON_CBN_SELCHANGE(IDC_COMBO_TM, &ASgc_Dlg::OnCbnSelchangeComboTm)
	ON_CBN_SELCHANGE(IDC_COMBO_TR, &ASgc_Dlg::OnCbnSelchangeComboTr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Lon, &ASgc_Dlg::OnDeltaposSpinLon)
END_MESSAGE_MAP()


// ASgc_Dlg 消息处理程序


BOOL ASgc_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpASgc_Dlg=&m_ASgc_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_ASgc_Dlg;
	m_iWhoamI=GTGEO;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTGEO].sCmdstr);
	CString sNumber="";
	for (int i=0;i<20;i++)
	{
		sNumber.Format("%d",i);
		m_ComboBox_GI.InsertString(i,sNumber);
		sNumber.ReleaseBuffer();
		sNumber="";
	}
	m_ComboBox_GI.SetCurSel(0);

	m_ComboBox_M.InsertString(0,"0: Disable the Geo-Fence function");
	m_ComboBox_M.InsertString(1,"1: Entering the zone. The report will be generated only when the terminal enters the Geo-Fence");
	m_ComboBox_M.InsertString(2,"2: Exiting the zone. The report will be generated only when the terminal exits the Geo-Fence");
	m_ComboBox_M.InsertString(3,"3: Both entering and exiting");	
	m_ComboBox_M.SetCurSel(0);

	SetDlgItemText(IDC_EDIT_Lat,"31.187891");
	SetDlgItemText(IDC_EDIT_Lon,"121.412248");
	//m_Spin_Lat.SetBuddy(GetDlgItem(IDC_EDIT_Lat)); //得到指向编辑框的窗口指针
	//m_Spin_Lat.SetRange32(0.000001,1000.000000);

	SetDlgItemText(IDC_EDIT_R,"50");
	m_Spin_R.SetBuddy(GetDlgItem(IDC_EDIT_R)); //得到指向编辑框的窗口指针
	m_Spin_R.SetRange32(50,6000000);

	SetDlgItemText(IDC_EDIT_CI,"0");
	m_Spin_CI.SetBuddy(GetDlgItem(IDC_EDIT_CI)); //得到指向编辑框的窗口指针
	m_Spin_CI.SetRange32(5,86400);

	m_ComboBox_OI.InsertString(0,"0");
	m_ComboBox_OI.InsertString(1,"1");
	m_ComboBox_OI.InsertString(2,"2");
	m_ComboBox_OI.SetCurSel(0);

	SetDlgItemText(IDC_EDIT_D,"0");
	m_Spin_D.SetBuddy(GetDlgItem(IDC_EDIT_D)); //得到指向编辑框的窗口指针
	m_Spin_D.SetRange(0,255);

	SetDlgItemText(IDC_EDIT_TT,"0");
	m_Spin_TT.SetBuddy(GetDlgItem(IDC_EDIT_TT)); //得到指向编辑框的窗口指针
	m_Spin_TT.SetRange(5,1440);

	m_ComboBox_TM.InsertString(0,"0: Disable auto trigger mode");
	m_ComboBox_TM.InsertString(1,"21: Automatically set circular Geo Fence after ignition off");
	m_ComboBox_TM.InsertString(2,"22: Manually enable circular Geo-Fence after ignition off");
	m_ComboBox_TM.SetCurSel(0);

	m_ComboBox_TR.InsertString(0,"0");
	m_ComboBox_TR.InsertString(1,"1");
	m_ComboBox_TR.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void ASgc_Dlg::GetCMD()
{
	CArray<CString,CString>CmdList;
	int iTemp=0;
	CString sNewCmd="";	CString sStr="";
	CString s1="",s2="",s3="",s4="",s5="",s6="",s7="",s8="",s9="",s10="",s11="",s12="",s13="",s14="",s15="";
	CmdList.InsertAt(1,"AT+GTGEO=HYIoT");
	try
	{
		iTemp=m_ComboBox_GI.GetCurSel();
		if (iTemp==-1) iTemp=0;
		s2.Format("%d",iTemp);
		CmdList.InsertAt(2,s2);
		iTemp=m_ComboBox_M.GetCurSel();
		if (iTemp==-1) iTemp=0;
		s3.Format("%d",iTemp);
		CmdList.InsertAt(3,s3);
		m_Edit_Lon.GetWindowText(s4);
		m_Edit_Lat.GetWindowText(s5);
		CmdList.InsertAt(4,s4);
		CmdList.InsertAt(5,s5);
		m_Edit_R.GetWindowText(sStr);
		if (sStr.Find(",")!=-1)
		{      
			for( int i=0;i < sStr.GetLength(); i++)
			{
				if(sStr.GetAt(i)>='0' &&  sStr.GetAt(i)<='9')
				{
					s6 += sStr.GetAt(i);
				}
			}
		}
		else
		{
			s6=sStr;
		}
		CmdList.InsertAt(6,s6);
		m_Edit_CI.GetWindowText(sStr);
		if (sStr.Find(",")!=-1)
		{      
			for( int i=0;i < sStr.GetLength(); i++)
			{
				if(sStr.GetAt(i)>='0' &&  sStr.GetAt(i)<='9')
				{
					s7 += sStr.GetAt(i);
				}
			}
		}
		else
		{
			s7=sStr;
		}
		CmdList.InsertAt(7,s7);
		iTemp=m_ComboBox_OI.GetCurSel();
		s8.Format("%d",iTemp);
		CmdList.InsertAt(8,s8);
		iTemp=m_Check_OutS.GetCheck();
		s9.Format("%d",iTemp);
		CmdList.InsertAt(9,s9);
		m_Edit_D.GetWindowText(s10);
		CmdList.InsertAt(10,s10);
		m_Edit_TT.GetWindowText(s11);
		CmdList.InsertAt(11,s11);

		iTemp=m_ComboBox_TM.GetCurSel();
		if (iTemp==-1) iTemp=0;
		if (iTemp==0)
		{
			s12.Format("0");
		}
		else if (iTemp==1)
		{
			s12.Format("21");
		}
		else if (iTemp==2)
		{
			s12.Format("22");
		}
		CmdList.InsertAt(12,s12);

		iTemp=m_ComboBox_TR.GetCurSel();
		if (iTemp==-1) iTemp=0;
		s13.Format("%d",iTemp);
		CmdList.InsertAt(13,s13);
		CmdList.Add("");
		CmdList.Add("");
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

CString ASgc_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL ASgc_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>10)
	{
		m_ComboBox_GI.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboGi();
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(2)));
		OnCbnSelchangeComboM();
		m_Edit_Lat.SetWindowText(ValueList.GetAt(4));
		m_Edit_Lon.SetWindowText(ValueList.GetAt(3));
		m_Edit_R.SetWindowText(ValueList.GetAt(5));
		m_Edit_CI.SetWindowText(ValueList.GetAt(6));

		if (ValueList.GetAt(11)=="0")
		{
			m_ComboBox_TM.SetCurSel(0);
		}
		if (ValueList.GetAt(11)=="21")
		{
			m_ComboBox_TM.SetCurSel(1);
		}
		if (ValueList.GetAt(11)=="22")
		{
			m_ComboBox_TM.SetCurSel(2);
		}
		OnCbnSelchangeComboTm();

		m_ComboBox_TR.SetCurSel(atoi(ValueList.GetAt(12)));
		OnCbnSelchangeComboTr();


		m_ComboBox_OI.SetCurSel(atoi(ValueList.GetAt(7)));
		OnCbnSelchangeComboOi();
		m_Check_OutS.SetCheck(atoi(ValueList.GetAt(8)));
		OnBnClickedCheckOuts();
		m_Edit_D.SetWindowText(ValueList.GetAt(9));
		m_Edit_TT.SetWindowText(ValueList.GetAt(10));

		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}

//2
void ASgc_Dlg::OnCbnSelchangeComboGi()
{
	GetCMD();
}

//3
void ASgc_Dlg::OnCbnSelchangeComboM()
{
	GetCMD();
}


void ASgc_Dlg::OnDeltaposSpinLat(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_LotdNum = m_LotdNum + 0.1;
		CString str;
		str.Format("%06f",m_LotdNum);
		m_Edit_Lat.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
    {
	     m_LotdNum = m_LotdNum - 0.1;
		 CString str;
		 str.Format("%05f",m_LotdNum);
		 m_Edit_Lat.SetWindowText(str);
	}
	*pResult = 0;
}

//5
void ASgc_Dlg::OnEnChangeEditLat()
{
	GetCMD();
}

//4
void ASgc_Dlg::OnEnChangeEditLon()
{
	GetCMD();
}


void ASgc_Dlg::OnDeltaposSpinR(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_R.GetPos();
	m_Spin_R.SetPos(iTemp);
	m_Edit_R.GetWindowText(strValue);  
	*pResult = 0;
}


void ASgc_Dlg::OnDeltaposSpinCi(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_CI.GetPos();
	m_Spin_CI.SetPos(iTemp);
	m_Edit_CI.GetWindowText(strValue);  
	*pResult = 0;
}

//6
void ASgc_Dlg::OnEnChangeEditR()
{
		GetCMD();
}

//7
void ASgc_Dlg::OnEnChangeEditCi()
{
		GetCMD();
}

//8
void ASgc_Dlg::OnCbnSelchangeComboOi()
{
	GetCMD();
}

//9
void ASgc_Dlg::OnBnClickedCheckOuts()
{
	GetCMD();
}


void ASgc_Dlg::OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D.GetPos();
	m_Spin_D.SetPos(iTemp);
	m_Edit_D.GetWindowText(strValue);  
	*pResult = 0;
}

//10
void ASgc_Dlg::OnEnChangeEditD()
{
	GetCMD();
}


void ASgc_Dlg::OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT.GetPos();
	m_Spin_TT.SetPos(iTemp);
	m_Edit_TT.GetWindowText(strValue);
	*pResult = 0;
}

//11
void ASgc_Dlg::OnEnChangeEditTt()
{
	GetCMD();
}

//12
void ASgc_Dlg::OnCbnSelchangeComboTm()
{
		GetCMD();
}

//13
void ASgc_Dlg::OnCbnSelchangeComboTr()
{
	GetCMD();
}


void ASgc_Dlg::OnDeltaposSpinLon(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_LondNum = m_LondNum + 0.1;
		CString str;
		str.Format("%06f",m_LondNum);
		m_Edit_Lon.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_LondNum = m_LondNum - 0.1;
		CString str;
		str.Format("%06f",m_LondNum);
		m_Edit_Lon.SetWindowText(str);
	}
	*pResult = 0;
}


