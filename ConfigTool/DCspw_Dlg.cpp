// DCspw_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "DCspw_Dlg.h"
#include "afxdialogex.h"

///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"
// DCap_Dlg 对话框
extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern DCspw_Dlg m_DCspw_Dlg;
DCspw_Dlg*	lpDCspw_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(DCspw_Dlg, CMyTabBaseDlg)

DCspw_Dlg::DCspw_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(DCspw_Dlg::IDD, pParent)
{

}

DCspw_Dlg::~DCspw_Dlg()
{
}

void DCspw_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_COMBO_U, m_ComboBox_U);
	DDX_Control(pDX, IDC_COMBO_I, m_ComboBox_I);
	DDX_Control(pDX, IDC_SPIN_IF, m_Spin_IF);
	DDX_Control(pDX, IDC_EDIT_IF, m_Edit_IF);
	DDX_Control(pDX, IDC_SPIN_RI, m_Spin_RI);
	DDX_Control(pDX, IDC_EDIT_RI, m_Edit_RI);
	DDX_Control(pDX, IDC_EDIT_Time, m_Edit_T);
	DDX_Control(pDX, IDC_CHECK_RBR, m_Check_RBR);
	DDX_Control(pDX, IDC_SPIN_MSP_NNI, m_Spin_NNI);
	DDX_Control(pDX, IDC_EDIT_NNI, m_Edit_NNI);
	DDX_Control(pDX, IDC_SPIN_NAI, m_Spin_NAI);
	DDX_Control(pDX, IDC_EDIT_NAI, m_Edit_NAI);
	DDX_Control(pDX, IDC_SPIN_SFT, m_Spin_SFT);
	DDX_Control(pDX, IDC_EDIT_SFT, m_Edit_SFT);
}


BEGIN_MESSAGE_MAP(DCspw_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &DCspw_Dlg::OnCbnSelchangeComboM)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_IF, &DCspw_Dlg::OnDeltaposSpinIf)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_RI, &DCspw_Dlg::OnDeltaposSpinRi)
	ON_EN_CHANGE(IDC_EDIT_IF, &DCspw_Dlg::OnEnChangeEditIf)
	ON_EN_CHANGE(IDC_EDIT_RI, &DCspw_Dlg::OnEnChangeEditRi)
	ON_EN_CHANGE(IDC_EDIT_Time, &DCspw_Dlg::OnEnChangeEditTime)
	ON_BN_CLICKED(IDC_CHECK_RBR, &DCspw_Dlg::OnBnClickedCheckRbr)
	ON_CBN_SELCHANGE(IDC_COMBO_I, &DCspw_Dlg::OnCbnSelchangeComboI)
	ON_CBN_SELCHANGE(IDC_COMBO_U, &DCspw_Dlg::OnCbnSelchangeComboU)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MSP_NNI, &DCspw_Dlg::OnDeltaposSpinMspNni)
	ON_EN_CHANGE(IDC_EDIT_NNI, &DCspw_Dlg::OnEnChangeEditNni)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_NAI, &DCspw_Dlg::OnDeltaposSpinNai)
	ON_EN_CHANGE(IDC_EDIT_NAI, &DCspw_Dlg::OnEnChangeEditNai)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_SFT, &DCspw_Dlg::OnDeltaposSpinSft)
	ON_EN_CHANGE(IDC_EDIT_SFT, &DCspw_Dlg::OnEnChangeEditSft)
END_MESSAGE_MAP()


// DCspw_Dlg 消息处理程序


BOOL DCspw_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpDCspw_Dlg=&m_DCspw_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_DCspw_Dlg;
	m_iWhoamI=GTDOG;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTDOG].sCmdstr);
	                             //AT+GTDOG=HYIoT,1,,1,0130,,1,1,,60, ,,0011$
	SetDlgItemText(IDC_EDIT_IF,"60");
	m_Spin_IF.SetBuddy(GetDlgItem(IDC_EDIT_IF)); //得到指向编辑框的窗口指针
	m_Spin_IF.SetRange(10,120);
	SetDlgItemText(IDC_EDIT_RI,"7");
	m_Spin_RI.SetBuddy(GetDlgItem(IDC_EDIT_RI)); //得到指向编辑框的窗口指针
	m_Spin_RI.SetRange(1,30);
	SetDlgItemText(IDC_EDIT_NNI,"480");
	m_Spin_NNI.SetBuddy(GetDlgItem(IDC_EDIT_NNI)); //得到指向编辑框的窗口指针
	m_Spin_NNI.SetRange(5,1440);
	SetDlgItemText(IDC_EDIT_NAI,"480");
	m_Spin_NAI.SetBuddy(GetDlgItem(IDC_EDIT_NAI)); //得到指向编辑框的窗口指针
	m_Spin_NAI.SetRange(5,1440);
	SetDlgItemText(IDC_EDIT_SFT,"480");
	m_Spin_SFT.SetBuddy(GetDlgItem(IDC_EDIT_SFT)); //得到指向编辑框的窗口指针
	m_Spin_SFT.SetRange(5,1440);
	SetDlgItemText(IDC_EDIT_Time,"0200");
	////////////////////////////////
	m_ComboBox_M.InsertString(0,"Disable this function");
	m_ComboBox_M.InsertString(1,"Reboot periodically according to the <Tnterval>and<Time>Seetting");
	m_ComboBox_M.InsertString(2,"Reboot when ignition on");
	m_ComboBox_M.SetCurSel(1);
	////////////////////////////////
	m_ComboBox_U.InsertString(0,"0:Unit is day");
	m_ComboBox_U.InsertString(1,"1:Unit is hour");
	m_ComboBox_U.SetCurSel(0);
	m_ComboBox_I.InsertString(0,"0");
	m_ComboBox_I.InsertString(1,"1");
	m_ComboBox_I.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


CString DCspw_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL DCspw_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>11)
	{
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboM();

		m_Edit_IF.SetWindowText(ValueList.GetAt(2));
		m_Edit_RI.SetWindowText(ValueList.GetAt(3));
		m_Edit_T.SetWindowText(ValueList.GetAt(4));

		m_ComboBox_U.SetCurSel(atoi(ValueList.GetAt(8)));
		OnCbnSelchangeComboU();
		m_ComboBox_I.SetCurSel(atoi(ValueList.GetAt(7)));
		OnCbnSelchangeComboI();

		m_Check_RBR.SetCheck(atoi(ValueList.GetAt(6)));
		OnBnClickedCheckRbr();

		m_Edit_NNI.SetWindowText(ValueList.GetAt(9));
		m_Edit_NAI.SetWindowText(ValueList.GetAt(10));
		m_Edit_SFT.SetWindowText(ValueList.GetAt(11));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}
//2
void DCspw_Dlg::OnCbnSelchangeComboM()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_M.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void DCspw_Dlg::OnDeltaposSpinIf(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString strValue="";
	int i=0;
	i=m_Spin_IF.GetPos();
	m_Spin_IF.SetPos(i);
	m_Edit_IF.GetWindowText(strValue);                 //得到编辑框中的内容
	*pResult = 0;
}

void DCspw_Dlg::OnDeltaposSpinRi(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_RI.GetPos();
	m_Spin_RI.SetPos(iTemp);
	m_Edit_RI.GetWindowText(strValue);   
	*pResult = 0;
}

//3
void DCspw_Dlg::OnEnChangeEditIf()
{
	CString sStr="",sCmd="",sNewCmd="";
	m_Edit_IF.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,2,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//4
void DCspw_Dlg::OnEnChangeEditRi()
{
	CString sStr="",sCmd="",sNewCmd="";
	m_Edit_RI.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,3,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//5
void DCspw_Dlg::OnEnChangeEditTime()
{
	CString sStr="",sCmd="",sNewCmd="";
	m_Edit_T.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,4,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//7
void DCspw_Dlg::OnBnClickedCheckRbr()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_RBR.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,6,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//8
void DCspw_Dlg::OnCbnSelchangeComboI()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_I.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,7,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//9
void DCspw_Dlg::OnCbnSelchangeComboU()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_U.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,8,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//10
void DCspw_Dlg::OnDeltaposSpinMspNni(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_NNI.GetPos();
	m_Spin_NNI.SetPos(iTemp);
	m_Edit_NNI.GetWindowText(strValue);   
	*pResult = 0;
}

//10
void DCspw_Dlg::OnEnChangeEditNni()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_NNI.GetWindowText(sStr);
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

void DCspw_Dlg::OnDeltaposSpinNai(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_NAI.GetPos();
	m_Spin_NAI.SetPos(iTemp);
	m_Edit_NAI.GetWindowText(strValue);  
	*pResult = 0;
}

//11
void DCspw_Dlg::OnEnChangeEditNai()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_NAI.GetWindowText(sStr);
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
	sNewCmd=UpdataCMD(strDigit,10,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void DCspw_Dlg::OnDeltaposSpinSft(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_SFT.GetPos();
	m_Spin_SFT.SetPos(iTemp);
	m_Edit_SFT.GetWindowText(strValue);  
	*pResult = 0;
}

//12
void DCspw_Dlg::OnEnChangeEditSft()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_SFT.GetWindowText(sStr);
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
	sNewCmd=UpdataCMD(strDigit,11,sCmd);//第6个
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

