// IDSvims_Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "IDSvims_Dlg.h"
#include "afxdialogex.h"

///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern IDSvims_Dlg m_IDSvims_Dlg;
IDSvims_Dlg*	lpIDSvims_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(IDSvims_Dlg, CMyTabBaseDlg)

IDSvims_Dlg::IDSvims_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(IDSvims_Dlg::IDD, pParent)
{

}

IDSvims_Dlg::~IDSvims_Dlg()
{
}

void IDSvims_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_VIM, m_ComboBox_VIM);
}


BEGIN_MESSAGE_MAP(IDSvims_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_VIM, &IDSvims_Dlg::OnCbnSelchangeComboVim)
END_MESSAGE_MAP()


// IDSvims_Dlg ��Ϣ�������


BOOL IDSvims_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpIDSvims_Dlg=&m_IDSvims_Dlg;//����Ѱַ
	m_lpMyTabBaseDlg = &m_IDSidbvs_Dlg;
	m_iWhoamI=GTVMS;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTVMS].sCmdstr);

	m_ComboBox_VIM.InsertString(0,"0: Disable the function, check ignition state by hardware wire");
	m_ComboBox_VIM.InsertString(1,"2: Check virtual ignition state by accelerometer");
	m_ComboBox_VIM.SetCurSel(1);
	///////////////
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}



CString IDSvims_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
{   //λ��iPos�Ǵ�0��ʼ��
	CString sNewCmd="",sRight="",sLeft="",sTemp="";
	CArray<CString,CString>ValueList;
	int index1=0,index2=0;
	sTemp=sParestr;//׼���ָ�
	for (int i=0;i<20;i++)
	{
		index1=sTemp.Find(",");
		if (-1==index1)
		{	
			ValueList.Add(sLeft);
			break;
		}
		sRight=sTemp.Left(index1).Trim();//��ȡ���õ�
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

BOOL IDSvims_Dlg::UpdataPage(CString sStr)
{   //λ��iPos�Ǵ�0��ʼ��
	CString sNewCmd="",sRight="",sLeft="",sTemp="";
	CArray<CString,CString>ValueList;
	int index1=0,index2=0;
	sTemp=sStr;//׼���ָ�
	for (int i=0;i<20;i++)
	{
		index1=sTemp.Find(",");
		if (-1==index1)
		{	
			ValueList.Add(sLeft);
			break;
		}
		sRight=sTemp.Left(index1).Trim();//��ȡ���õ�
		index2=index1+1;
		sLeft=sTemp.Right(sTemp.GetLength()-index2).Trim();
		sTemp=sLeft;
		ValueList.Add(sRight);;
	}
	if (ValueList.GetSize()>1)
	{
		if (ValueList.GetAt(1)=="0")
		{
			m_ComboBox_VIM.SetCurSel(0);
			OnCbnSelchangeComboVim();
		}
		else if (ValueList.GetAt(1)=="2")
		{
			m_ComboBox_VIM.SetCurSel(1);
			OnCbnSelchangeComboVim();
		}
		//m_Edit_UserName.SetWindowText(ValueList.GetAt(2));
		//m_Edit_Password.SetWindowText(ValueList.GetAt(3));
		//m_Edit_BAPN.SetWindowText(ValueList.GetAt(4));
		//m_Edit_BUserName.SetWindowText(ValueList.GetAt(5));
		//m_Edit_BPassword.SetWindowText(ValueList.GetAt(6));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}

void IDSvims_Dlg::OnCbnSelchangeComboVim()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_VIM.GetCurSel();
	if (iTemp==0)
	{
		sStr="0";
	}
	else if (iTemp==1)
	{
		sStr="2";
	}
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

