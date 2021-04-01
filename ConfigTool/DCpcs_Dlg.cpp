// DCpcs_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "DCpcs_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"
// DCap_Dlg 对话框
extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern DCpcs_Dlg m_DCpcs_Dlg;
DCpcs_Dlg*	lpDCpcs_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(DCpcs_Dlg, CMyTabBaseDlg)

DCpcs_Dlg::DCpcs_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(DCpcs_Dlg::IDD, pParent)
{

}

DCpcs_Dlg::~DCpcs_Dlg()
{
}

void DCpcs_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_EPD, m_Check_EPD);
	DDX_Control(pDX, IDC_SPIN_TD, m_Spin_TD);
	DDX_Control(pDX, IDC_EDIT_TD, m_Edit_TD);
}


BEGIN_MESSAGE_MAP(DCpcs_Dlg, CMyTabBaseDlg)
	ON_BN_CLICKED(IDC_CHECK_EPD, &DCpcs_Dlg::OnBnClickedCheckEpd)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TD, &DCpcs_Dlg::OnDeltaposSpinTd)
	ON_EN_CHANGE(IDC_EDIT_TD, &DCpcs_Dlg::OnEnChangeEditTd)
END_MESSAGE_MAP()


// DCpcs_Dlg 消息处理程序


BOOL DCpcs_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpDCpcs_Dlg=&m_DCpcs_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_DCgc_Dlg;
	m_iWhoamI=GTPCS;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTPCS].sCmdstr);

	SetDlgItemText(IDC_EDIT_TD,"900");
	m_Spin_TD.SetBuddy(GetDlgItem(IDC_EDIT_TD)); //得到指向编辑框的窗口指针
	m_Spin_TD.SetRange32(60,65535);
	m_Check_EPD.SetCheck(1);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString DCpcs_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL DCpcs_Dlg::UpdataPage(CString sStr)
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
		m_Check_EPD.SetCheck(atoi(ValueList.GetAt(1)));
		OnBnClickedCheckEpd();
		m_Edit_TD.SetWindowText(ValueList.GetAt(2));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}

}
//2
void DCpcs_Dlg::OnBnClickedCheckEpd()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_EPD.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void DCpcs_Dlg::OnDeltaposSpinTd(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TD.GetPos();
	m_Spin_TD.SetPos(iTemp);
	m_Edit_TD.GetWindowText(strValue);  
	*pResult = 0;
}

//3
void DCpcs_Dlg::OnEnChangeEditTd()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_TD.GetWindowText(sStr);
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
	sNewCmd=UpdataCMD(strDigit,2,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

