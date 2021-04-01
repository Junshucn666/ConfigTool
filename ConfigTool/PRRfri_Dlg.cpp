// PRRfri_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "PRRfri_Dlg.h"
#include "afxdialogex.h"

///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern PRRfri_Dlg m_PRRfri_Dlg;
PRRfri_Dlg*	lpPRRfri_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(PRRfri_Dlg, CMyTabBaseDlg)

PRRfri_Dlg::PRRfri_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(PRRfri_Dlg::IDD, pParent)
{

}

PRRfri_Dlg::~PRRfri_Dlg()
{
}

void PRRfri_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_CHECK_DNF, m_Check_DNF);
	DDX_Control(pDX, IDC_CHECK_PE, m_Check_PE);
	DDX_Control(pDX, IDC_EDIT_ST, m_Edit_ST);
	DDX_Control(pDX, IDC_EDIT_ET, m_Edit_ET);
	DDX_Control(pDX, IDC_SPIN_SI, m_Spin_SI);
	DDX_Control(pDX, IDC_EDIT_SI, m_Edit_SI);
	DDX_Control(pDX, IDC_SPIN_D, m_Spin_D);
	DDX_Control(pDX, IDC_EDIT_D, m_Edit_D);
	DDX_Control(pDX, IDC_SPIN_M, m_Spin_M);
	DDX_Control(pDX, IDC_EDIT_M, m_Edit_M);
	DDX_Control(pDX, IDC_SPIN_CR, m_Spin_CR);
	DDX_Control(pDX, IDC_EDIT_CR, m_Edit_CR);
	DDX_Control(pDX, IDC_SPIN_IRI, m_Spin_IRI);
	DDX_Control(pDX, IDC_EDIT_IRI, m_Edit_IRI);
	DDX_Control(pDX, IDC_SPIN_ARI, m_Spin_ARI);
	DDX_Control(pDX, IDC_EDIT_ARI, m_Edit_ARI);
}


BEGIN_MESSAGE_MAP(PRRfri_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &PRRfri_Dlg::OnCbnSelchangeComboM)
	ON_BN_CLICKED(IDC_CHECK_DNF, &PRRfri_Dlg::OnBnClickedCheckDnf)
	ON_BN_CLICKED(IDC_CHECK_PE, &PRRfri_Dlg::OnBnClickedCheckPe)
	ON_EN_CHANGE(IDC_EDIT_ST, &PRRfri_Dlg::OnEnChangeEditSt)
	ON_EN_CHANGE(IDC_EDIT_ET, &PRRfri_Dlg::OnEnChangeEditEt)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_SI, &PRRfri_Dlg::OnDeltaposSpinSi)
	ON_EN_CHANGE(IDC_EDIT_SI, &PRRfri_Dlg::OnEnChangeEditSi)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_IRI, &PRRfri_Dlg::OnDeltaposSpinIri)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D, &PRRfri_Dlg::OnDeltaposSpinD)
	ON_EN_CHANGE(IDC_EDIT_D, &PRRfri_Dlg::OnEnChangeEditD)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_M, &PRRfri_Dlg::OnDeltaposSpinM)
	ON_EN_CHANGE(IDC_EDIT_M, &PRRfri_Dlg::OnEnChangeEditM)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_CR, &PRRfri_Dlg::OnDeltaposSpinCr)
	ON_EN_CHANGE(IDC_EDIT_CR, &PRRfri_Dlg::OnEnChangeEditCr)
	ON_EN_CHANGE(IDC_EDIT_IRI, &PRRfri_Dlg::OnEnChangeEditIri)
	ON_EN_CHANGE(IDC_EDIT_ARI, &PRRfri_Dlg::OnEnChangeEditAri)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ARI, &PRRfri_Dlg::OnDeltaposSpinAri)
END_MESSAGE_MAP()


// PRRfri_Dlg 消息处理程序


BOOL PRRfri_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	// TODO:  在此添加额外的初始化
	lpPRRfri_Dlg=&m_PRRfri_Dlg;//窗口寻址
	m_lpMyTabBaseDlg=&m_PRRfri_Dlg;
	m_iWhoamI=GTFRI;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTFRI].sCmdstr);
	SetDlgItemText(IDC_EDIT_ST,"0000");
	SetDlgItemText(IDC_EDIT_ET,"0000");
	///////////////
	m_ComboBox_M.InsertString(0,"0:Disable this function.");
	m_ComboBox_M.InsertString(1,"1:Fixed Timing Report.");
	m_ComboBox_M.InsertString(2,"2:Fixed Distance Report");
	m_ComboBox_M.InsertString(3,"3:Fixed Mileage Report");
	m_ComboBox_M.InsertString(4,"4:Optimum Report.");
	m_ComboBox_M.InsertString(5,"5:Fixed Time or Mileage Report");
	m_ComboBox_M.SetCurSel(0);
	//////////////////////////////////////////////////////////////////////////
	m_Check_DNF.SetCheck(1);
	m_Check_PE.SetCheck(1);
	////
	SetDlgItemText(IDC_EDIT_SI,"30");
	m_Spin_SI.SetBuddy(GetDlgItem(IDC_EDIT_SI)); //得到指向编辑框的窗口指针
	m_Spin_SI.SetRange32(5,86400);

	SetDlgItemText(IDC_EDIT_D,"1000");
	m_Spin_D.SetBuddy(GetDlgItem(IDC_EDIT_D)); //得到指向编辑框的窗口指针
	m_Spin_D.SetRange32(50,65535);

	SetDlgItemText(IDC_EDIT_M,"1000");
	m_Spin_M.SetBuddy(GetDlgItem(IDC_EDIT_M)); //得到指向编辑框的窗口指针
	m_Spin_M.SetRange32(50,65535);

	SetDlgItemText(IDC_EDIT_CR,"0");
	m_Spin_CR.SetBuddy(GetDlgItem(IDC_EDIT_CR)); //得到指向编辑框的窗口指针
	m_Spin_CR.SetRange(0,180);

	SetDlgItemText(IDC_EDIT_IRI,"600");
	m_Spin_IRI.SetBuddy(GetDlgItem(IDC_EDIT_IRI)); //得到指向编辑框的窗口指针
	m_Spin_IRI.SetRange32(5,86400);

	SetDlgItemText(IDC_EDIT_ARI,"0");
	m_Spin_ARI.SetBuddy(GetDlgItem(IDC_EDIT_ARI)); //得到指向编辑框的窗口指针
	m_Spin_ARI.SetRange32(5,90000);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


CString PRRfri_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL PRRfri_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>14)
	{
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboM();

		m_Edit_SI.SetWindowText(ValueList.GetAt(8));
		m_Edit_IRI.SetWindowText(ValueList.GetAt(13));
		m_Edit_ARI.SetWindowText(ValueList.GetAt(14));
		m_Edit_ST.SetWindowText(ValueList.GetAt(5));
		m_Edit_ET.SetWindowText(ValueList.GetAt(6));
		m_Edit_D.SetWindowText(ValueList.GetAt(9));
		m_Edit_M.SetWindowText(ValueList.GetAt(10));
		m_Edit_CR.SetWindowText(ValueList.GetAt(12));

		m_Check_PE.SetCheck(atoi(ValueList.GetAt(4)));
		OnBnClickedCheckPe();

		m_Check_DNF.SetCheck(atoi(ValueList.GetAt(2)));
		OnBnClickedCheckDnf();
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}

void PRRfri_Dlg::OnCbnSelchangeComboM()
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
void PRRfri_Dlg::OnBnClickedCheckDnf()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_DNF.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,2,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//5
void PRRfri_Dlg::OnBnClickedCheckPe()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_Check_PE.GetCheck();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStr,4,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//6
void PRRfri_Dlg::OnEnChangeEditSt()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_ST.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=UpdataCMD(sStr,5,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}

//7
void PRRfri_Dlg::OnEnChangeEditEt()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_ET.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=UpdataCMD(sStr,6,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void PRRfri_Dlg::OnDeltaposSpinSi(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_SI.GetPos();
	m_Spin_SI.SetPos(iTemp);
	m_Edit_SI.GetWindowText(strValue);  
	*pResult = 0;
}

//9
void PRRfri_Dlg::OnEnChangeEditSi()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_SI.GetWindowText(sStr);
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
	sNewCmd=UpdataCMD(strDigit,8,sCmd);//第6个
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void PRRfri_Dlg::OnDeltaposSpinIri(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_IRI.GetPos();
	m_Spin_IRI.SetPos(iTemp);
	m_Edit_IRI.GetWindowText(strValue);  
	*pResult = 0;
}


void PRRfri_Dlg::OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult)
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
void PRRfri_Dlg::OnEnChangeEditD()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_D.GetWindowText(sStr);
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
	sNewCmd=UpdataCMD(strDigit,9,sCmd);//第6个
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void PRRfri_Dlg::OnDeltaposSpinM(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_M.GetPos();
	m_Spin_M.SetPos(iTemp);
	m_Edit_M.GetWindowText(strValue);  
	*pResult = 0;
}

//11
void PRRfri_Dlg::OnEnChangeEditM()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_M.GetWindowText(sStr);
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


void PRRfri_Dlg::OnDeltaposSpinCr(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_CR.GetPos();
	m_Spin_CR.SetPos(iTemp);
	m_Edit_CR.GetWindowText(strValue);  
	*pResult = 0;
}

//13
void PRRfri_Dlg::OnEnChangeEditCr()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_CR.GetWindowText(sStr);
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
	sNewCmd=UpdataCMD(strDigit,12,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//14
void PRRfri_Dlg::OnEnChangeEditIri()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
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
	sNewCmd=UpdataCMD(strDigit,13,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

//15
void PRRfri_Dlg::OnEnChangeEditAri()
{
	CString sStr="",sCmd="",sNewCmd="",strDigit="";
	int i=0;
	m_Edit_ARI.GetWindowText(sStr);
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


void PRRfri_Dlg::OnDeltaposSpinAri(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_ARI.GetPos();
	m_Spin_ARI.SetPos(iTemp);
	m_Edit_ARI.GetWindowText(strValue);  
	*pResult = 0;
}
