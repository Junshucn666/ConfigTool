// DCta_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "DCta_Dlg.h"
#include "afxdialogex.h"

///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"
// DCap_Dlg 对话框
extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern DCta_Dlg m_DCta_Dlg;
DCta_Dlg*	lpDCta_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(DCta_Dlg, CMyTabBaseDlg)

DCta_Dlg::DCta_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(DCta_Dlg::IDD, pParent)
{

}

DCta_Dlg::~DCta_Dlg()
{
}

void DCta_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_S, m_ComboBox_S);
	DDX_Control(pDX, IDC_CHECK_DS, m_Check_DS);
	DDX_Control(pDX, IDC_SPIN_HO, m_Spin_HO);
	DDX_Control(pDX, IDC_EDIT_HO, m_Edit_HO);
	DDX_Control(pDX, IDC_SPIN_MO, m_Spin_MO);
	DDX_Control(pDX, IDC_EDIT_MO, m_Edit_MO);
	DDX_Control(pDX, IDC_EDIT_UT, m_Edit_UT);
}


BEGIN_MESSAGE_MAP(DCta_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_S, &DCta_Dlg::OnCbnSelchangeComboS)
	ON_BN_CLICKED(IDC_CHECK_DS, &DCta_Dlg::OnBnClickedCheckDs)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_HO, &DCta_Dlg::OnDeltaposSpinHo)
	ON_EN_CHANGE(IDC_EDIT_HO, &DCta_Dlg::OnEnChangeEditHo)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MO, &DCta_Dlg::OnDeltaposSpinMo)
	ON_EN_CHANGE(IDC_EDIT_MO, &DCta_Dlg::OnEnChangeEditMo)
	ON_EN_CHANGE(IDC_EDIT_UT, &DCta_Dlg::OnEnChangeEditUt)
END_MESSAGE_MAP()


// DCta_Dlg 消息处理程序


BOOL DCta_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpDCta_Dlg=&m_DCta_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_DCta_Dlg;
	m_iWhoamI=GTTMA;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTTMA].sCmdstr);

	SetDlgItemText(IDC_EDIT_HO,"0");
	m_Spin_HO.SetBuddy(GetDlgItem(IDC_EDIT_HO)); //得到指向编辑框的窗口指针
	m_Spin_HO.SetRange(0,12);

	SetDlgItemText(IDC_EDIT_MO,"0");
	m_Spin_MO.SetBuddy(GetDlgItem(IDC_EDIT_MO)); //得到指向编辑框的窗口指针
	m_Spin_MO.SetRange(0,59);

	m_ComboBox_S.InsertString(0,"+");
	m_ComboBox_S.InsertString(1,"-");
	m_ComboBox_S.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString DCta_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL DCta_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>5)
	{
		if (ValueList.GetAt(1)=="+")
		{
			m_ComboBox_S.SetCurSel(0);
		}
		if (ValueList.GetAt(1)=="-")
		{
			m_ComboBox_S.SetCurSel(1);
		}
		OnCbnSelchangeComboS();

		m_Check_DS.SetCheck(atoi(ValueList.GetAt(4)));
		OnBnClickedCheckDs();
		m_Edit_HO.SetWindowText(ValueList.GetAt(2));
		m_Edit_MO.SetWindowText(ValueList.GetAt(3));
		m_Edit_UT.SetWindowText(ValueList.GetAt(5));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}
//2
void DCta_Dlg::OnCbnSelchangeComboS()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_S.GetCurSel();
	if (iTemp)
	{
		sStr.Format("-");
	}
	else
	{
		sStr.Format("+");
	}
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//5
void DCta_Dlg::OnBnClickedCheckDs()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_DS.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,4,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void DCta_Dlg::OnDeltaposSpinHo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_HO.GetPos();
	m_Spin_HO.SetPos(iTemp);
	m_Edit_HO.GetWindowText(strValue);  
	*pResult = 0;
}

//3
void DCta_Dlg::OnEnChangeEditHo()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_HO.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=UpdataCMD(sStr,2,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void DCta_Dlg::OnDeltaposSpinMo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_MO.GetPos();
	m_Spin_MO.SetPos(iTemp);
	m_Edit_MO.GetWindowText(strValue);  
	*pResult = 0;
}

//4
void DCta_Dlg::OnEnChangeEditMo()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_MO.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=UpdataCMD(sStr,3,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//6
void DCta_Dlg::OnEnChangeEditUt()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_UT.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=UpdataCMD(sStr,5,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}
