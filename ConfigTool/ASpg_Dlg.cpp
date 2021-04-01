// ASpg_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ASpg_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern ASpg_Dlg m_ASpg_Dlg;
ASpg_Dlg*	lpASpg_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
#define dMax 180.0
#define dMin -180.0
////////////
CArray<CString,CString>g_AList,g_BList;

IMPLEMENT_DYNAMIC(ASpg_Dlg, CMyTabBaseDlg)

ASpg_Dlg::ASpg_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(ASpg_Dlg::IDD, pParent)
{
	m_dA1	=0.000000;
	m_dA2	=0.000000;
	m_dA3	=0.000000;
	m_dA4	=0.000000;
	m_dA5	=0.000000;
	m_dA6	=0.000000;
	m_dA7	=0.000000;
	m_dA8	=0.000000;
	m_dA9	=0.000000;
	m_dA10	=0.000000;
	m_dB1	=0.000000;
	m_dB2	=0.000000;
	m_dB3	=0.000000;
	m_dB4	=0.000000;
	m_dB5	=0.000000;
	m_dB6	=0.000000;
	m_dB7	=0.000000;
	m_dB8	=0.000000;
	m_dB9	=0.000000;
	m_dB10	=0.000000;
}

ASpg_Dlg::~ASpg_Dlg()
{
}

void ASpg_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDV_MinMaxDouble(pDX, m_dA1, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dA2, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dA3, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dA4, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dA5, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dA6, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dA7, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dA8, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dA9, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dA10, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dB1, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dB2, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dB3, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dB4, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dB5, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dB6, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dB7, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dB8, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dB9, dMin, dMax);
	DDV_MinMaxDouble(pDX, m_dB10, dMin, dMax);
	DDX_Control(pDX, IDC_COMBO_GI, m_ComboBox_GI);
	DDX_Control(pDX, IDC_COMBO_Mode, m_ComboBox_M);
	DDX_Control(pDX, IDC_SPIN_CI, m_Spin_CI);
	DDX_Control(pDX, IDC_EDIT_CI, m_Edit_CI);
	DDX_Control(pDX, IDC_SPIN_SP, m_Spin_SP);
	DDX_Control(pDX, IDC_SPIN_EP, m_Spin_EP);
	DDX_Control(pDX, IDC_EDIT_SP, m_Edit_SP);
	DDX_Control(pDX, IDC_EDIT_EP, m_Edit_EP);
	DDX_Control(pDX, IDC_EDIT_A1, m_Edit_A1);
	DDX_Control(pDX, IDC_EDIT_A2, m_Edit_A2);
	DDX_Control(pDX, IDC_EDIT_A3, m_Edit_A3);
	DDX_Control(pDX, IDC_EDIT_A4, m_Edit_A4);
	DDX_Control(pDX, IDC_EDIT_A5, m_Edit_A5);
	DDX_Control(pDX, IDC_EDIT_A6, m_Edit_A6);
	DDX_Control(pDX, IDC_EDIT_A7, m_Edit_A7);
	DDX_Control(pDX, IDC_EDIT_A8, m_Edit_A8);
	DDX_Control(pDX, IDC_EDIT_A9, m_Edit_A9);
	DDX_Control(pDX, IDC_EDIT_A10, m_Edit_A10);
	DDX_Control(pDX, IDC_EDIT_B1, m_Edit_B1);
	DDX_Control(pDX, IDC_EDIT_B2, m_Edit_B2);
	DDX_Control(pDX, IDC_EDIT_B3, m_Edit_B3);
	DDX_Control(pDX, IDC_EDIT_B4, m_Edit_B4);
	DDX_Control(pDX, IDC_EDIT_B5, m_Edit_B5);
	DDX_Control(pDX, IDC_EDIT_B6, m_Edit_B6);
	DDX_Control(pDX, IDC_EDIT_B7, m_Edit_B7);
	DDX_Control(pDX, IDC_EDIT_B8, m_Edit_B8);
	DDX_Control(pDX, IDC_EDIT_B9, m_Edit_B9);
	DDX_Control(pDX, IDC_EDIT_B10, m_Edit_B10);
	DDX_Control(pDX, IDC_SPIN_Du, m_Spin_D);
	DDX_Control(pDX, IDC_SPIN_Tog, m_Spin_TT);
	DDX_Control(pDX, IDC_EDIT_DU, m_Edit_D);
	DDX_Control(pDX, IDC_EDIT_Tog, m_Edit_TT);
	DDX_Control(pDX, IDC_COMBO_OI, m_ComboBox_OI);
	DDX_Control(pDX, IDC_CHECK_OutS, m_Check_OutS);
	DDX_Control(pDX, IDC_SPIN_A1, m_Spin_A1);
}


BEGIN_MESSAGE_MAP(ASpg_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_GI, &ASpg_Dlg::OnCbnSelchangeComboGi)
	ON_CBN_SELCHANGE(IDC_COMBO_Mode, &ASpg_Dlg::OnCbnSelchangeComboMode)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_CI, &ASpg_Dlg::OnDeltaposSpinCi)
	ON_EN_CHANGE(IDC_EDIT_CI, &ASpg_Dlg::OnEnChangeEditCi)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_SP, &ASpg_Dlg::OnDeltaposSpinSp)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_EP, &ASpg_Dlg::OnDeltaposSpinEp)
	ON_EN_CHANGE(IDC_EDIT_SP, &ASpg_Dlg::OnEnChangeEditSp)
	ON_EN_CHANGE(IDC_EDIT_EP, &ASpg_Dlg::OnEnChangeEditEp)
	ON_CBN_SELCHANGE(IDC_COMBO_OI, &ASpg_Dlg::OnCbnSelchangeComboOi)
	ON_BN_CLICKED(IDC_CHECK_OutS, &ASpg_Dlg::OnBnClickedCheckOuts)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Du, &ASpg_Dlg::OnDeltaposSpinDu)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Tog, &ASpg_Dlg::OnDeltaposSpinTog)
	ON_EN_CHANGE(IDC_EDIT_DU, &ASpg_Dlg::OnEnChangeEditDu)
	ON_EN_CHANGE(IDC_EDIT_Tog, &ASpg_Dlg::OnEnChangeEditTog)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_A1, &ASpg_Dlg::OnDeltaposSpinA1)
	ON_EN_CHANGE(IDC_EDIT_A1, &ASpg_Dlg::OnEnChangeEditA1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_B1, &ASpg_Dlg::OnDeltaposSpinB1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_A2, &ASpg_Dlg::OnDeltaposSpinA2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_B2, &ASpg_Dlg::OnDeltaposSpinB2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_A3, &ASpg_Dlg::OnDeltaposSpinA3)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_B3, &ASpg_Dlg::OnDeltaposSpinB3)
	ON_EN_CHANGE(IDC_EDIT_A4, &ASpg_Dlg::OnEnChangeEditA4)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_A4, &ASpg_Dlg::OnDeltaposSpinA4)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_B4, &ASpg_Dlg::OnDeltaposSpinB4)
	ON_EN_CHANGE(IDC_EDIT_A5, &ASpg_Dlg::OnEnChangeEditA5)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_A5, &ASpg_Dlg::OnDeltaposSpinA5)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_B5, &ASpg_Dlg::OnDeltaposSpinB5)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_A6, &ASpg_Dlg::OnDeltaposSpinA6)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_B6, &ASpg_Dlg::OnDeltaposSpinB6)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_A7, &ASpg_Dlg::OnDeltaposSpinA7)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_B7, &ASpg_Dlg::OnDeltaposSpinB7)
	ON_EN_CHANGE(IDC_EDIT_A8, &ASpg_Dlg::OnEnChangeEditA8)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_A8, &ASpg_Dlg::OnDeltaposSpinA8)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_B8, &ASpg_Dlg::OnDeltaposSpinB8)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_A9, &ASpg_Dlg::OnDeltaposSpinA9)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_B9, &ASpg_Dlg::OnDeltaposSpinB9)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_A10, &ASpg_Dlg::OnDeltaposSpinA10)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_B10, &ASpg_Dlg::OnDeltaposSpinB10)
	ON_EN_CHANGE(IDC_EDIT_B1, &ASpg_Dlg::OnEnChangeEditB1)
	ON_EN_CHANGE(IDC_EDIT_A2, &ASpg_Dlg::OnEnChangeEditA2)
	ON_EN_CHANGE(IDC_EDIT_B2, &ASpg_Dlg::OnEnChangeEditB2)
	ON_EN_CHANGE(IDC_EDIT_A3, &ASpg_Dlg::OnEnChangeEditA3)
	ON_EN_CHANGE(IDC_EDIT_B3, &ASpg_Dlg::OnEnChangeEditB3)
	ON_EN_CHANGE(IDC_EDIT_B4, &ASpg_Dlg::OnEnChangeEditB4)
	ON_EN_CHANGE(IDC_EDIT_B5, &ASpg_Dlg::OnEnChangeEditB5)
	ON_EN_CHANGE(IDC_EDIT_A6, &ASpg_Dlg::OnEnChangeEditA6)
	ON_EN_CHANGE(IDC_EDIT_B6, &ASpg_Dlg::OnEnChangeEditB6)
	ON_EN_CHANGE(IDC_EDIT_A7, &ASpg_Dlg::OnEnChangeEditA7)
	ON_EN_CHANGE(IDC_EDIT_B7, &ASpg_Dlg::OnEnChangeEditB7)
	ON_EN_CHANGE(IDC_EDIT_B8, &ASpg_Dlg::OnEnChangeEditB8)
	ON_EN_CHANGE(IDC_EDIT_A9, &ASpg_Dlg::OnEnChangeEditA9)
	ON_EN_CHANGE(IDC_EDIT_B9, &ASpg_Dlg::OnEnChangeEditB9)
	ON_EN_CHANGE(IDC_EDIT_A10, &ASpg_Dlg::OnEnChangeEditA10)
	ON_EN_CHANGE(IDC_EDIT_B10, &ASpg_Dlg::OnEnChangeEditB10)
END_MESSAGE_MAP()


// ASpg_Dlg 消息处理程序


BOOL ASpg_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	// TODO:  在此添加额外的初始化
	lpASpg_Dlg=&m_ASpg_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_ASpg_Dlg;
	m_iWhoamI=GTPEO;
	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTPEO].sCmdstr);

	for (int i=0;i<20;i++)
	{
		CString str="";
		str.Format("%d",i);
		m_ComboBox_GI.InsertString(i,str);
	}
	m_ComboBox_GI.SetCurSel(0);

	m_ComboBox_M.InsertString(0,"0: Disable the Geo-Fence function.");
	m_ComboBox_M.InsertString(1,"1: Entering the zone. The report will be generated only when the terminal enters the Geo-Fence");
	m_ComboBox_M.InsertString(2,"2: Exiting the zone. The report will be generated only when the terminal exits from the Geo-Fence.");
	m_ComboBox_M.InsertString(3,"3: Both entering and exiting.");
	m_ComboBox_M.SetCurSel(0);

	SetDlgItemText(IDC_EDIT_CI,"0");
	m_Spin_CI.SetBuddy(GetDlgItem(IDC_EDIT_CI)); //得到指向编辑框的窗口指针
	m_Spin_CI.SetRange32(5,86400);
	
	SetDlgItemText(IDC_EDIT_SP,"1");
	m_Spin_SP.SetBuddy(GetDlgItem(IDC_EDIT_SP)); //得到指向编辑框的窗口指针
	m_Spin_SP.SetRange(1,8);
	
	SetDlgItemText(IDC_EDIT_EP,"3");
	m_Spin_EP.SetBuddy(GetDlgItem(IDC_EDIT_EP)); //得到指向编辑框的窗口指针
	m_Spin_EP.SetRange(3,10);
	/////////////////
	/////////////////
	m_ComboBox_OI.InsertString(0,"0");
	m_ComboBox_OI.InsertString(1,"1");
	m_ComboBox_OI.InsertString(2,"2");
	m_ComboBox_OI.SetCurSel(0);
	///////////////
	SetDlgItemText(IDC_EDIT_DU,"0");
	m_Spin_D.SetBuddy(GetDlgItem(IDC_EDIT_DU)); //得到指向编辑框的窗口指针
	m_Spin_D.SetRange(0,255);

	SetDlgItemText(IDC_EDIT_Tog,"0");
	m_Spin_TT.SetBuddy(GetDlgItem(IDC_EDIT_Tog)); //得到指向编辑框的窗口指针
	m_Spin_TT.SetRange(0,255);
	/////////////////
	SetDlgItemText(IDC_EDIT_A1,	"0.000000");
	SetDlgItemText(IDC_EDIT_A2,	"0.000000");
	SetDlgItemText(IDC_EDIT_A3,	"0.000000");
	SetDlgItemText(IDC_EDIT_A4,	"0.000000");
	SetDlgItemText(IDC_EDIT_A5,	"0.000000");
	SetDlgItemText(IDC_EDIT_A6,	"0.000000");
	SetDlgItemText(IDC_EDIT_A7,	"0.000000");
	SetDlgItemText(IDC_EDIT_A8,	"0.000000");
	SetDlgItemText(IDC_EDIT_A9,	"0.000000");
	SetDlgItemText(IDC_EDIT_A10,"0.000000");
	SetDlgItemText(IDC_EDIT_B1,	"0.000000");
	SetDlgItemText(IDC_EDIT_B2,	"0.000000");
	SetDlgItemText(IDC_EDIT_B3,	"0.000000");
	SetDlgItemText(IDC_EDIT_B4,	"0.000000");
	SetDlgItemText(IDC_EDIT_B5,	"0.000000");
	SetDlgItemText(IDC_EDIT_B6,	"0.000000");
	SetDlgItemText(IDC_EDIT_B7,	"0.000000");
	SetDlgItemText(IDC_EDIT_B8,	"0.000000");
	SetDlgItemText(IDC_EDIT_B9,	"0.000000");
	SetDlgItemText(IDC_EDIT_B10,"0.000000");

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString ASpg_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
{   //位置iPos是从0开始的
	CString sNewCmd="",sRight="",sLeft="",sTemp="",sFinalCMD="";
	CArray<CString,CString>ValueList,HeadList,FootList;
	int index1=0,index2=0;
	sTemp=sParestr;//准备分割旧命令
	for (int i=0;i<100;i++)
	{
		index1=sTemp.Find(",");
		if (-1==index1)//最后的部分
		{	
			ValueList.Add(sLeft);
			break;
		}
		sRight=sTemp.Left(index1).Trim();//截取有用的
		index2=index1+1;
		sLeft=sTemp.Right(sTemp.GetLength()-index2).Trim();
		sTemp=sLeft;
		ValueList.Add(sRight);
	}
	for (int i=0;i<ValueList.GetSize();i++)//重新组合成新命令
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
	/////////////////////////////////////////////////////////////////
	sTemp=sNewCmd;	///二次分割,获取前5个部分加最后
	for (int i=0;i<5;i++)
	{
		index1=sTemp.Find(",");
		sRight=sTemp.Left(index1).Trim();//截取有用的
		index2=index1+1;
		sLeft=sTemp.Right(sTemp.GetLength()-index2).Trim();
		sTemp=sLeft;
		HeadList.Add(sRight);
	}
	////////////////////////获取Foot部分///////////
	int iSize=0;
	iSize=ValueList.GetSize()-1;
	CString sFootCmd="";
	for (int i=iSize,j=0;i>=0;i--,j++)
	{
		if (iSize==i)
		{
			sFootCmd=ValueList.GetAt(i);
		}
		else
		{
			if (j==10)
			{
				break;
			}
			else
			{
				sFootCmd=ValueList.GetAt(i)+","+sFootCmd;
			}
		}
	}
	/////////////////////////////////////
	int iStart=	atoi(HeadList.GetAt(3));
	int iEnd =atoi(HeadList.GetAt(4));
	//获取所有的Number进入二维数组NumberList
	GetListValue();
	//控制iStart的值，同时改变号码列表
	if (iStart>(iEnd-2))
	{
		CString str="";
		iEnd=iStart+2;
		str.Format("%d",iEnd);
		m_Edit_EP.SetWindowText(str);//Start不可以大于(End-2)
		HeadList.GetAt(4)=str;//改变END的值
		sFinalCMD=HeadList.GetAt(0)+","+HeadList.GetAt(1)+","+HeadList.GetAt(2)+","+HeadList.GetAt(3)+","+HeadList.GetAt(4);
		sFinalCMD=sFinalCMD+","+g_AList.GetAt(iEnd)+","+g_BList.GetAt(iEnd);
		sFinalCMD=sFinalCMD+","+sFootCmd;
	}
	if (iStart==iEnd)
	{
		sFinalCMD=HeadList.GetAt(0)+","+HeadList.GetAt(1)+","+HeadList.GetAt(2)+","+HeadList.GetAt(3)+","+HeadList.GetAt(4);
		sFinalCMD=sFinalCMD+","+g_AList.GetAt(iEnd)+","+g_BList.GetAt(iEnd);
		sFinalCMD=sFinalCMD+","+sFootCmd;

	}
	if (iStart<iEnd)
	{
		sFinalCMD=HeadList.GetAt(0)+","+HeadList.GetAt(1)+","+HeadList.GetAt(2)+","+HeadList.GetAt(3)+","+HeadList.GetAt(4);
		for (int i=0;i<=(iEnd-iStart);i++)
		{
			sFinalCMD=sFinalCMD+","+g_AList.GetAt(iStart+i)+","+g_BList.GetAt(iStart+i);
		}
		sFinalCMD=sFinalCMD+","+sFootCmd;
	}

	return sFinalCMD;
}

void ASpg_Dlg::GetListValue()
{
	CString sA1="",sA2="",sA3="",sA4="",sA5="",sA6="",sA7="",sA8="",sA9="",sA10="";
	CString sB1="",sB2="",sB3="",sB4="",sB5="",sB6="",sB7="",sB8="",sB9="",sB10="";
	m_Edit_A1	.GetWindowText(	sA1);
	m_Edit_A2	.GetWindowText(	sA2);
	m_Edit_A3	.GetWindowText(	sA3);
	m_Edit_A4	.GetWindowText(	sA4);
	m_Edit_A5	.GetWindowText(	sA5);
	m_Edit_A6	.GetWindowText(	sA6);
	m_Edit_A7	.GetWindowText(	sA7);
	m_Edit_A8	.GetWindowText(	sA8);
	m_Edit_A9	.GetWindowText(	sA9);
	m_Edit_A10	.GetWindowText(	sA10);
	m_Edit_B1	.GetWindowText(	sB1);
	m_Edit_B2	.GetWindowText(	sB2);
	m_Edit_B3	.GetWindowText(	sB3);
	m_Edit_B4	.GetWindowText(	sB4);
	m_Edit_B5	.GetWindowText(	sB5);
	m_Edit_B6	.GetWindowText(	sB6);
	m_Edit_B7	.GetWindowText(	sB7);
	m_Edit_B8	.GetWindowText(	sB8);
	m_Edit_B9	.GetWindowText(	sB9);
	m_Edit_B10	.GetWindowText(	sB10);
	g_AList.InsertAt(1,	sA1);
	g_AList.InsertAt(2,	sA2);
	g_AList.InsertAt(3,	sA3);
	g_AList.InsertAt(4,	sA4);
	g_AList.InsertAt(5,	sA5);
	g_AList.InsertAt(6,	sA6);
	g_AList.InsertAt(7,	sA7);
	g_AList.InsertAt(8,	sA8);
	g_AList.InsertAt(9,	sA9);
	g_AList.InsertAt(10,sA10);
	g_BList.InsertAt(1,	sB1);
	g_BList.InsertAt(2,	sB2);
	g_BList.InsertAt(3,	sB3);
	g_BList.InsertAt(4,	sB4);
	g_BList.InsertAt(5,	sB5);
	g_BList.InsertAt(6,	sB6);
	g_BList.InsertAt(7,	sB7);
	g_BList.InsertAt(8,	sB8);
	g_BList.InsertAt(9,	sB9);
	g_BList.InsertAt(10,	sB10);
	//NumberList.Add(sNumber1);
	//m_Edit_N2.GetWindowText(sNumber2);
	//NumberList.Add(sNumber2);
	//m_Edit_N3.GetWindowText(sNumber3);
	//NumberList.Add(sNumber3);
}

BOOL ASpg_Dlg::UpdataPage(CString sStr)
{   //位置iPos是从0开始的
	CString sNewCmd="",sRight="",sLeft="",sTemp="";
	CArray<CString,CString>ValueList;
	CArray<CString,CString>NumberList;	
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
	if (ValueList.GetSize()>10)
	{
		m_ComboBox_GI.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboGi();
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(2)));
		OnCbnSelchangeComboMode();
		////////////////////////获取Foot部分///////////
		int iSize=0;
		iSize=ValueList.GetSize()-1;
		m_Edit_CI.SetWindowText(ValueList.GetAt(iSize-9));
		m_ComboBox_OI.SetCurSel(atoi(ValueList.GetAt(iSize-8)));
		OnCbnSelchangeComboOi();
		m_Check_OutS.SetCheck(atoi(ValueList.GetAt(iSize-7)));
		OnBnClickedCheckOuts();
		m_Edit_D.SetWindowText(ValueList.GetAt(iSize-6));
		m_Edit_TT.SetWindowText(ValueList.GetAt(iSize-5));
		/////////////////////////////////////////////////////
		m_Edit_SP.SetWindowText(ValueList.GetAt(3));
		Sleep(100);
		m_Edit_EP.SetWindowText(ValueList.GetAt(4));
		Sleep(100);
		int iStart,iEnd;
		iStart= atoi(ValueList.GetAt(3));
		iEnd=atoi(ValueList.GetAt(4));
		//////////////生产Number列表/////////标号从1开始不是从0开始
		g_AList.RemoveAll();
		g_BList.RemoveAll();
		for (int p=0,t=0;p<=(iEnd-iStart);p++,t++)
		{
			g_AList.InsertAt((iStart+p),ValueList.GetAt(5+t));
			t=t+1;
			g_BList.InsertAt((iStart+p),ValueList.GetAt(5+t));
		}
		/////////////////////////////////////////
		if (iStart<=1&&iEnd>=1)
		{
			m_Edit_A1.SetWindowText(g_AList.GetAt(1));
			m_Edit_B1.SetWindowText(g_BList.GetAt(1));
		}
		if (iStart<=2&&iEnd>=2)
		{
			m_Edit_A2.SetWindowText(g_AList.GetAt(2));
			m_Edit_B2.SetWindowText(g_BList.GetAt(2));
		}
		if (iStart<=3&&iEnd>=3)
		{
			m_Edit_A3.SetWindowText(g_AList.GetAt(3));
			m_Edit_B3.SetWindowText(g_BList.GetAt(3));
		}
		if (iStart<=4&&iEnd>=4)
		{
			m_Edit_A4.SetWindowText(g_AList.GetAt(4));
			m_Edit_B4.SetWindowText(g_BList.GetAt(4));
		}
		if (iStart<=5&&iEnd>=5)
		{
			m_Edit_A5.SetWindowText(g_AList.GetAt(5));
			m_Edit_B5.SetWindowText(g_BList.GetAt(5));
		}
		if (iStart<=6&&iEnd>=6)
		{
			m_Edit_A6.SetWindowText(g_AList.GetAt(6));
			m_Edit_B6.SetWindowText(g_BList.GetAt(6));
		}
		if (iStart<=7&&iEnd>=7)
		{
			m_Edit_A7.SetWindowText(g_AList.GetAt(7));
			m_Edit_B7.SetWindowText(g_BList.GetAt(7));
		}		
		if (iStart<=8&&iEnd>=8)
		{
			m_Edit_A8.SetWindowText(g_AList.GetAt(8));
			m_Edit_B8.SetWindowText(g_BList.GetAt(8));
		}
		if (iStart<=9&&iEnd>=9)
		{
			m_Edit_A9.SetWindowText(g_AList.GetAt(9));
			m_Edit_B9.SetWindowText(g_BList.GetAt(9));
		}
		if (iStart<=10&&iEnd>=10)
		{
			m_Edit_A10.SetWindowText(g_AList.GetAt(10));
			m_Edit_B10.SetWindowText(g_BList.GetAt(10));
		}

		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}

void ASpg_Dlg::OnCbnSelchangeComboGi()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_GI.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void ASpg_Dlg::OnCbnSelchangeComboMode()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_M.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,2,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void ASpg_Dlg::OnDeltaposSpinCi(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_CI.GetPos();
	m_Spin_CI.SetPos(iTemp);
	m_Edit_CI.GetWindowText(strValue);  
	*pResult = 0;
}


void ASpg_Dlg::OnEnChangeEditCi()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_CI.GetWindowText(sStr);
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
	sNewCmd=m_MYWORK.UnUpdataCMD(strDigit,9,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void ASpg_Dlg::OnDeltaposSpinSp(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_SP.GetPos();
	m_Spin_SP.SetPos(iTemp);
	m_Edit_SP.GetWindowText(strValue);  
	*pResult = 0;
}


void ASpg_Dlg::OnDeltaposSpinEp(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_EP.GetPos();
	m_Spin_EP.SetPos(iTemp);
	m_Edit_EP.GetWindowText(strValue);  
	*pResult = 0;
}


void ASpg_Dlg::OnEnChangeEditSp()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_SP.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=UpdataCMD(sStr,3,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void ASpg_Dlg::OnEnChangeEditEp()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_EP.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=UpdataCMD(sStr,4,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void ASpg_Dlg::OnCbnSelchangeComboOi()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_OI.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UnUpdataCMD(sStr,8,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void ASpg_Dlg::OnBnClickedCheckOuts()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_OutS.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UnUpdataCMD(sStr,7,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void ASpg_Dlg::OnDeltaposSpinDu(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D.GetPos();
	m_Spin_D.SetPos(iTemp);
	m_Edit_D.GetWindowText(strValue);  
	*pResult = 0;
}


void ASpg_Dlg::OnDeltaposSpinTog(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT.GetPos();
	m_Spin_TT.SetPos(iTemp);
	m_Edit_TT.GetWindowText(strValue);  
	*pResult = 0;
}


void ASpg_Dlg::OnEnChangeEditDu()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_D.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UnUpdataCMD(sStr,6,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

void ASpg_Dlg::OnEnChangeEditTog()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_TT.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=m_MYWORK.UnUpdataCMD(sStr,5,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

void ASpg_Dlg::OnDeltaposSpinA1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dA1 = m_dA1 + 0.1;
		CString str;
		str.Format("%06f",m_dA1);
		m_Edit_A1.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dA1 = m_dA1 - 0.1;
		CString str;
		str.Format("%06f",m_dA1);
		m_Edit_A1.SetWindowText(str);
	}
	*pResult = 0;
}

void ASpg_Dlg::OnDeltaposSpinB1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dB1 = m_dB1 + 0.1;
		CString str;
		str.Format("%06f",m_dB1);
		m_Edit_B1.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dB1 = m_dB1 - 0.1;
		CString str;
		str.Format("%06f",m_dB1);
		m_Edit_B1.SetWindowText(str);
	}
	*pResult = 0;
}

void ASpg_Dlg::OnDeltaposSpinA2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dA2 = m_dA2 + 0.1;
		CString str;
		str.Format("%06f",m_dA2);
		m_Edit_A2.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dA2 = m_dA2 - 0.1;
		CString str;
		str.Format("%06f",m_dA2);
		m_Edit_A2.SetWindowText(str);
	}
	*pResult = 0;
}

void ASpg_Dlg::OnDeltaposSpinB2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dB2 = m_dB2 + 0.1;
		CString str;
		str.Format("%06f",m_dB2);
		m_Edit_B2.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dB2 = m_dB2 - 0.1;
		CString str;
		str.Format("%06f",m_dB2);
		m_Edit_B2.SetWindowText(str);
	}
	*pResult = 0;
}

void ASpg_Dlg::OnDeltaposSpinA3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dA3 = m_dA3 + 0.1;
		CString str;
		str.Format("%06f",m_dA3);
		m_Edit_A3.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dA3 = m_dA3 - 0.1;
		CString str;
		str.Format("%06f",m_dA3);
		m_Edit_A3.SetWindowText(str);
	}
	*pResult = 0;
}

void ASpg_Dlg::OnDeltaposSpinB3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dB3 = m_dB3 + 0.1;
		CString str;
		str.Format("%06f",m_dB3);
		m_Edit_B3.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dB3 = m_dB3 - 0.1;
		CString str;
		str.Format("%06f",m_dB3);
		m_Edit_B3.SetWindowText(str);
	}
	*pResult = 0;
}

void ASpg_Dlg::OnDeltaposSpinA4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dA4 = m_dA4 + 0.1;
		CString str;
		str.Format("%06f",m_dA4);
		m_Edit_A4.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dA4 = m_dA4 - 0.1;
		CString str;
		str.Format("%06f",m_dA4);
		m_Edit_A4.SetWindowText(str);
	}
	*pResult = 0;
}

void ASpg_Dlg::OnDeltaposSpinB4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dB4 = m_dB4 + 0.1;
		CString str;
		str.Format("%06f",m_dB4);
		m_Edit_B4.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dB4 = m_dB4 - 0.1;
		CString str;
		str.Format("%06f",m_dB4);
		m_Edit_B4.SetWindowText(str);
	}
	*pResult = 0;
}

void ASpg_Dlg::OnDeltaposSpinA5(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dA5 = m_dA5 + 0.1;
		CString str;
		str.Format("%06f",m_dA5);
		m_Edit_A5.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dA5 = m_dA5 - 0.1;
		CString str;
		str.Format("%06f",m_dA5);
		m_Edit_A5.SetWindowText(str);
	}
	*pResult = 0;
}

void ASpg_Dlg::OnDeltaposSpinB5(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dB5 = m_dB5 + 0.1;
		CString str;
		str.Format("%06f",m_dB5);
		m_Edit_B5.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dB5 = m_dB5 - 0.1;
		CString str;
		str.Format("%06f",m_dB5);
		m_Edit_B5.SetWindowText(str);
	}
	*pResult = 0;
}

void ASpg_Dlg::OnDeltaposSpinA6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dA6 = m_dA6 + 0.1;
		CString str;
		str.Format("%06f",m_dA6);
		m_Edit_A6.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dA6 = m_dA6 - 0.1;
		CString str;
		str.Format("%06f",m_dA6);
		m_Edit_A6.SetWindowText(str);
	}
	*pResult = 0;
}

void ASpg_Dlg::OnDeltaposSpinB6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dB6 = m_dB6 + 0.1;
		CString str;
		str.Format("%06f",m_dB6);
		m_Edit_B6.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dB6 = m_dB6 - 0.1;
		CString str;
		str.Format("%06f",m_dB6);
		m_Edit_B6.SetWindowText(str);
	}
	*pResult = 0;
}

void ASpg_Dlg::OnDeltaposSpinA7(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dA7 = m_dA7 + 0.1;
		CString str;
		str.Format("%06f",m_dA7);
		m_Edit_A7.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dA7 = m_dA7 - 0.1;
		CString str;
		str.Format("%06f",m_dA7);
		m_Edit_A7.SetWindowText(str);
	}
	*pResult = 0;
}

void ASpg_Dlg::OnDeltaposSpinB7(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dB7 = m_dB7 + 0.1;
		CString str;
		str.Format("%06f",m_dB7);
		m_Edit_B7.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dB7 = m_dB7 - 0.1;
		CString str;
		str.Format("%06f",m_dB7);
		m_Edit_B7.SetWindowText(str);
	}
	*pResult = 0;
}




void ASpg_Dlg::OnDeltaposSpinA8(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dA8 = m_dA8 + 0.1;
		CString str;
		str.Format("%06f",m_dA8);
		m_Edit_A8.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dA8 = m_dA8 - 0.1;
		CString str;
		str.Format("%06f",m_dA8);
		m_Edit_A8.SetWindowText(str);
	}
	*pResult = 0;
}


void ASpg_Dlg::OnDeltaposSpinB8(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dB8 = m_dB8 + 0.1;
		CString str;
		str.Format("%06f",m_dB8);
		m_Edit_B8.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dB8 = m_dB8 - 0.1;
		CString str;
		str.Format("%06f",m_dB8);
		m_Edit_B8.SetWindowText(str);
	}
	*pResult = 0;
}


void ASpg_Dlg::OnDeltaposSpinA9(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dA9 = m_dA9 + 0.1;
		CString str;
		str.Format("%06f",m_dA9);
		m_Edit_A9.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dA9 = m_dA9 - 0.1;
		CString str;
		str.Format("%06f",m_dA9);
		m_Edit_A9.SetWindowText(str);
	}
	*pResult = 0;
}


void ASpg_Dlg::OnDeltaposSpinB9(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dB9 = m_dB9 + 0.1;
		CString str;
		str.Format("%06f",m_dB9);
		m_Edit_B9.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dB9 = m_dB9 - 0.1;
		CString str;
		str.Format("%06f",m_dB9);
		m_Edit_B9.SetWindowText(str);
	}
	*pResult = 0;
}


void ASpg_Dlg::OnDeltaposSpinA10(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dA10 = m_dA10 + 0.1;
		CString str;
		str.Format("%06f",m_dA10);
		m_Edit_A10.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dA10 = m_dA10 - 0.1;
		CString str;
		str.Format("%06f",m_dA10);
		m_Edit_A10.SetWindowText(str);
	}
	*pResult = 0;
}


void ASpg_Dlg::OnDeltaposSpinB10(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_dB10 = m_dB10 + 0.1;
		CString str;
		str.Format("%06f",m_dB10);
		m_Edit_B10.SetWindowText(str);
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_dB10 = m_dB10 - 0.1;
		CString str;
		str.Format("%06f",m_dB10);
		m_Edit_B10.SetWindowText(str);
	}
	*pResult = 0;
}

void ASpg_Dlg::OnEnChangeEditA1()
{
	CString sStr="",sCMD="",sNewCMD="",sNewStr="";
	m_Edit_A1.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_A1.SetWindowText("0.000000");
		return;
	}
	m_dA1=atof(sStr);
	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=1)&&(atoi(sEnd)>=1))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_A1.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(6-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}

void ASpg_Dlg::OnEnChangeEditB1()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_B1.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_B1.SetWindowText("0.000000");
		return;
	}
	m_dB1=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=1)&&(atoi(sEnd)>=1))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_B1.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(7-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}


void ASpg_Dlg::OnEnChangeEditA2()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_A2.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_A2.SetWindowText("0.000000");
		return;
	}
	m_dA2=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=2)&&(atoi(sEnd)>=2))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_A2.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(8-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}


void ASpg_Dlg::OnEnChangeEditB2()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_B2.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_B2.SetWindowText("0.000000");
		return;
	}
	m_dB2=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=2)&&(atoi(sEnd)>=2))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_B2.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(9-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}


void ASpg_Dlg::OnEnChangeEditA3()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_A3.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_A3.SetWindowText("0.000000");
		return;
	}
	m_dA3=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=3)&&(atoi(sEnd)>=3))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_A3.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(10-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}


void ASpg_Dlg::OnEnChangeEditB3()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_B3.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_B3.SetWindowText("0.000000");
		return;
	}
	m_dB3=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=3)&&(atoi(sEnd)>=3))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_B3.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(11-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}


void ASpg_Dlg::OnEnChangeEditA4()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_A4.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_A4.SetWindowText("0.000000");
		return;
	}
	m_dA4=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=4)&&(atoi(sEnd)>=4))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_A4.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(12-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);
	}
}


void ASpg_Dlg::OnEnChangeEditB4()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_B4.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_B4.SetWindowText("0.000000");
		return;
	}
	m_dB4=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=4)&&(atoi(sEnd)>=4))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_B4.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(13-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}

void ASpg_Dlg::OnEnChangeEditA5()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_A5.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_A5.SetWindowText("0.000000");
		return;
	}
	m_dA5=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=5)&&(atoi(sEnd)>=5))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_A5.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(14-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);
	}
}

void ASpg_Dlg::OnEnChangeEditB5()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_B5.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_B5.SetWindowText("0.000000");
		return;
	}
	m_dB5=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=5)&&(atoi(sEnd)>=5))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_B5.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(15-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);
	}
}


void ASpg_Dlg::OnEnChangeEditA6()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_A6.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_A6.SetWindowText("0.000000");
		return;
	}
	m_dA6=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=6)&&(atoi(sEnd)>=6))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_A6.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(16-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);
	}
}


void ASpg_Dlg::OnEnChangeEditB6()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_B6.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_B6.SetWindowText("0.000000");
		return;
	}
	m_dB6=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=6)&&(atoi(sEnd)>=6))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_B6.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(17-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);
	}
}


void ASpg_Dlg::OnEnChangeEditA7()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_A7.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_A7.SetWindowText("0.000000");
		return;
	}
	m_dA7=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=7)&&(atoi(sEnd)>=7))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_A7.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(18-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);
	}
}


void ASpg_Dlg::OnEnChangeEditB7()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_B7.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_B7.SetWindowText("0.000000");
		return;
	}
	m_dB7=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=7)&&(atoi(sEnd)>=7))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_B7.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(19-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);
	}
}


void ASpg_Dlg::OnEnChangeEditA8()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_A8.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_A8.SetWindowText("0.000000");
		return;
	}
	m_dA8=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=8)&&(atoi(sEnd)>=8))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_A8.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(20-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);
	}
}

void ASpg_Dlg::OnEnChangeEditB8()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_B8.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_B8.SetWindowText("0.000000");
		return;
	}
	m_dB8=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=8)&&(atoi(sEnd)>=8))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_B8.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(21-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);
	}
}


void ASpg_Dlg::OnEnChangeEditA9()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_A9.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_A9.SetWindowText("0.000000");
		return;
	}
	m_dA9=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=9)&&(atoi(sEnd)>=9))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_A9.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(22-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);
	}
}


void ASpg_Dlg::OnEnChangeEditB9()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_B9.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_B9.SetWindowText("0.000000");
		return;
	}
	m_dB9=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=9)&&(atoi(sEnd)>=9))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_B9.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(23-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);
	}
}


void ASpg_Dlg::OnEnChangeEditA10()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_A10.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_A10.SetWindowText("0.000000");
		return;
	}
	m_dA10=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=10)&&(atoi(sEnd)>=10))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_A10.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(24-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);
	}
}


void ASpg_Dlg::OnEnChangeEditB10()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_B10.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_B10.SetWindowText("0.000000");
		return;
	}
	m_dB10=atof(sStr);

	CString sStart="",sEnd="";
	m_Edit_SP.GetWindowText(sStart);
	m_Edit_EP.GetWindowText(sEnd);
	if ((atoi(sStart)<=10)&&(atoi(sEnd)>=10))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_B10.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(25-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);
	}
}

