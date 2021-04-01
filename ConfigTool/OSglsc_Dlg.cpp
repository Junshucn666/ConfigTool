// OSglsc_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "OSglsc_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern OSglsc_Dlg m_OSglsc_Dlg;
OSglsc_Dlg*	lpOSglsc_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(OSglsc_Dlg, CMyTabBaseDlg)

OSglsc_Dlg::OSglsc_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(OSglsc_Dlg::IDD, pParent)
{

}

OSglsc_Dlg::~OSglsc_Dlg()
{
}

void OSglsc_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_N, m_ComboBox_N);
	DDX_Control(pDX, IDC_SPIN_MS, m_Spin_Ms);
	DDX_Control(pDX, IDC_SPIN_ME, m_Spin_ME);
	DDX_Control(pDX, IDC_EDIT_MS, m_Edit_MS);
	DDX_Control(pDX, IDC_EDIT_ME, m_Edit_ME);
	DDX_Control(pDX, IDC_EDIT_N1, m_Edit_N1);
	DDX_Control(pDX, IDC_EDIT_N2, m_Edit_N2);
	DDX_Control(pDX, IDC_EDIT_N3, m_Edit_N3);
}


BEGIN_MESSAGE_MAP(OSglsc_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_N, &OSglsc_Dlg::OnCbnSelchangeComboN)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MS, &OSglsc_Dlg::OnDeltaposSpinMs)
	ON_EN_CHANGE(IDC_EDIT_ME, &OSglsc_Dlg::OnEnChangeEditMe)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ME, &OSglsc_Dlg::OnDeltaposSpinMe)
	ON_EN_CHANGE(IDC_EDIT_MS, &OSglsc_Dlg::OnEnChangeEditMs)
	ON_EN_CHANGE(IDC_EDIT_N1, &OSglsc_Dlg::OnEnChangeEditN1)
	ON_EN_CHANGE(IDC_EDIT_N2, &OSglsc_Dlg::OnEnChangeEditN2)
	ON_EN_CHANGE(IDC_EDIT_N3, &OSglsc_Dlg::OnEnChangeEditN3)
END_MESSAGE_MAP()


// OSglsc_Dlg 消息处理程序

BOOL OSglsc_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpOSglsc_Dlg=&m_OSglsc_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_OSglsc_Dlg;
	m_iWhoamI=GTGLM;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTGLM].sCmdstr);
	// TODO:  在此添加额外的初始化
	m_ComboBox_N.InsertString(0,"0: Do not send an SMS with Google link to the number in the <Direct Number List> for SOS and GEO events and PEO events.");
	m_ComboBox_N.InsertString(1,"1: Send an SMS with Google link to the number in the <Direct Number List> for SOS event in the Google hyperlink.");
	m_ComboBox_N.InsertString(2,"2: Send an SMS with Google link to the number in the <Direct Number List> for GEO event and PEO events in the Google hyperlink.");
	m_ComboBox_N.InsertString(3,"3: Send an SMS with Google link to the number in the <Direct Number List> for SOS and GEO event and PEO events in the Google hyperlink.");
	m_ComboBox_N.SetCurSel(1);

	SetDlgItemText(IDC_EDIT_MS,"1");
	m_Spin_Ms.SetBuddy(GetDlgItem(IDC_EDIT_MS)); //得到指向编辑框的窗口指针
	m_Spin_Ms.SetRange(1,3);

	SetDlgItemText(IDC_EDIT_ME,"1");
	m_Spin_ME.SetBuddy(GetDlgItem(IDC_EDIT_ME)); //得到指向编辑框的窗口指针
	m_Spin_ME.SetRange(1,3);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


CString OSglsc_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
{   //位置iPos是从0开始的
	CString sNewCmd="",sRight="",sLeft="",sTemp="",sFinalCMD="";
	CString sNumber1="",sNumber2="",sNumber3="",sNumber4="",sNumber5="",sNumber6="",sNumber7="",sNumber8="",sNumber9="",sNumber10="";
	CArray<CString,CString>ValueList,NewValueList;
	CArray<CString,CString>NumberList;
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
	sTemp=sNewCmd;	///二次分割,获取前4个部分加最后
	for (int i=0;i<4;i++)
	{
		index1=sTemp.Find(",");
		sRight=sTemp.Left(index1).Trim();//截取有用的
		index2=index1+1;
		sLeft=sTemp.Right(sTemp.GetLength()-index2).Trim();
		sTemp=sLeft;
		NewValueList.Add(sRight);
	}
	int iStart=	atoi(NewValueList.GetAt(2));
	int iEnd =atoi(NewValueList.GetAt(3));
	//获取所有的Number进入二维数组NumberList
	m_Edit_N1.GetWindowText(sNumber1);
	NumberList.Add(sNumber1);
	m_Edit_N2.GetWindowText(sNumber2);
	NumberList.Add(sNumber2);
	m_Edit_N3.GetWindowText(sNumber3);
	NumberList.Add(sNumber3);
	//控制iStart的值，同时改变号码列表
	if (iStart>iEnd)
	{
		CString str="";
		str.Format("%d",iEnd);
		m_Edit_MS.SetWindowText(str);
		NewValueList.GetAt(2)=str;
		sFinalCMD=NewValueList.GetAt(0)+","+NewValueList.GetAt(1)+","+NewValueList.GetAt(2)+","+NewValueList.GetAt(3);
		sFinalCMD=sFinalCMD+","+NumberList.GetAt(iEnd-1);
		sFinalCMD=sFinalCMD+",,,,,FFFF$";
	}
	if (iStart==iEnd)
	{
		sFinalCMD=NewValueList.GetAt(0)+","+NewValueList.GetAt(1)+","+NewValueList.GetAt(2)+","+NewValueList.GetAt(3);
		sFinalCMD=sFinalCMD+","+NumberList.GetAt(iEnd-1);
		sFinalCMD=sFinalCMD+",,,,,FFFF$";

	}
	if (iStart<iEnd)
	{
		sFinalCMD=NewValueList.GetAt(0)+","+NewValueList.GetAt(1)+","+NewValueList.GetAt(2)+","+NewValueList.GetAt(3);
		for (int i=0;i<=(iEnd-iStart);i++)
		{
			sFinalCMD=sFinalCMD+","+NumberList.GetAt(iStart-1+i);
		}
		sFinalCMD=sFinalCMD+",,,,,FFFF$";
	}

	return sFinalCMD;
}

BOOL OSglsc_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>3)
	{
		m_ComboBox_N.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboN();
		////////一定先END再Start才行//////////////////////
		m_Edit_ME.SetWindowText(ValueList.GetAt(3));
		Sleep(100);
		m_Edit_MS.SetWindowText(ValueList.GetAt(2));
		Sleep(100);
		int iStart,iEnd;
		iStart= atoi(ValueList.GetAt(2));
		iEnd=atoi(ValueList.GetAt(3));
		//////////////生产Number列表/////////标号从1开始不是从0开始
		NumberList.RemoveAll();
		for (int p=0;p<=(iEnd-iStart);p++)
		{
			NumberList.InsertAt((iStart+p),ValueList.GetAt(4+p));
		}
		/////////////////////////////////////
		if (iStart<=1&&iEnd>=1)
		{
			//NumberList.InsertAt(1,ValueList.GetAt(4)); //第一个Number
			m_Edit_N1.SetWindowText(NumberList.GetAt(1));
		}
		if (iStart<=2&&iEnd>=2)
		{
			//NumberList.InsertAt(2,ValueList.GetAt(5)); //第一个Number
			m_Edit_N2.SetWindowText(NumberList.GetAt(2));
		}
		if (iStart<=3&&iEnd>=3)
		{
			//NumberList.InsertAt(3,ValueList.GetAt(6)); //第一个Number
			m_Edit_N3.SetWindowText(NumberList.GetAt(3));
		}

		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}


void OSglsc_Dlg::OnCbnSelchangeComboN()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_N.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}




void OSglsc_Dlg::OnDeltaposSpinMs(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_Ms.GetPos();
	m_Spin_Ms.SetPos(iTemp);
	m_Edit_MS.GetWindowText(strValue); 
	*pResult = 0;
}


void OSglsc_Dlg::OnEnChangeEditMe()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_ME.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=UpdataCMD(sStr,3,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void OSglsc_Dlg::OnDeltaposSpinMe(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_ME.GetPos();
	m_Spin_ME.SetPos(iTemp);
	m_Edit_ME.GetWindowText(strValue);  
	*pResult = 0;
}


void OSglsc_Dlg::OnEnChangeEditMs()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_MS.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=UpdataCMD(sStr,2,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void OSglsc_Dlg::OnEnChangeEditN1()
{
	CString sStart="",sEnd="",sStr="";
	CString sCMD="",sNewCMD="";
	m_Edit_N1.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_N1.SetWindowText("");
		return;
	}

	m_Edit_MS.GetWindowText(sStart);
	m_Edit_ME.GetWindowText(sEnd);
	if ((atoi(sStart)<=1)&&(atoi(sEnd)>=1))
	{
		m_Edit_N1.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,5-atoi(sStart),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}


void OSglsc_Dlg::OnEnChangeEditN2()
{
	CString sStart="",sEnd="",sStr="";
	CString sCMD="",sNewCMD="";

	m_Edit_N2.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_N2.SetWindowText("");
		return;
	}
	///////////
	m_Edit_MS.GetWindowText(sStart);
	m_Edit_ME.GetWindowText(sEnd);
	if ((atoi(sStart)<=2)&&(atoi(sEnd)>=2))
	{
		m_Edit_N2.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,6-atoi(sStart),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}


void OSglsc_Dlg::OnEnChangeEditN3()
{
	CString sStart="",sEnd="",sStr="";
	CString sCMD="",sNewCMD="";

	m_Edit_N3.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_N3.SetWindowText("");
		return;
	}

	m_Edit_MS.GetWindowText(sStart);
	m_Edit_ME.GetWindowText(sEnd);
	if ((atoi(sStart)<=3)&&(atoi(sEnd)>=3))
	{
		m_Edit_N3.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,7-atoi(sStart),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);
	}
}


