// OSwl_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "OSwl_Dlg.h"
#include "afxdialogex.h"

///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern OSwl_Dlg m_OSwl_Dlg;
OSwl_Dlg*	lpOSwl_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////

IMPLEMENT_DYNAMIC(OSwl_Dlg, CMyTabBaseDlg)

OSwl_Dlg::OSwl_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(OSwl_Dlg::IDD, pParent)
{

}

OSwl_Dlg::~OSwl_Dlg()
{
}

void OSwl_Dlg::DoDataExchange(CDataExchange* pDX)
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
	DDX_Control(pDX, IDC_EDIT_N4, m_Edit_N4);
	DDX_Control(pDX, IDC_EDIT_N5, m_Edit_N5);
	DDX_Control(pDX, IDC_EDIT_N6, m_Edit_N6);
	DDX_Control(pDX, IDC_EDIT_N7, m_Edit_N7);
	DDX_Control(pDX, IDC_EDIT_N8, m_Edit_N8);
	DDX_Control(pDX, IDC_EDIT_N9, m_Edit_N9);
	DDX_Control(pDX, IDC_EDIT_N10, m_Edit_N10);
}


BEGIN_MESSAGE_MAP(OSwl_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_N, &OSwl_Dlg::OnCbnSelchangeComboN)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MS, &OSwl_Dlg::OnDeltaposSpinMs)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ME, &OSwl_Dlg::OnDeltaposSpinMe)
	ON_EN_CHANGE(IDC_EDIT_MS, &OSwl_Dlg::OnEnChangeEditMs)
	ON_EN_CHANGE(IDC_EDIT_ME, &OSwl_Dlg::OnEnChangeEditMe)
	ON_EN_CHANGE(IDC_EDIT_N1, &OSwl_Dlg::OnEnChangeEditN1)
	ON_EN_CHANGE(IDC_EDIT_N2, &OSwl_Dlg::OnEnChangeEditN2)
	ON_EN_CHANGE(IDC_EDIT_N3, &OSwl_Dlg::OnEnChangeEditN3)
	ON_EN_CHANGE(IDC_EDIT_N4, &OSwl_Dlg::OnEnChangeEditN4)
	ON_EN_CHANGE(IDC_EDIT_N5, &OSwl_Dlg::OnEnChangeEditN5)
	ON_EN_CHANGE(IDC_EDIT_N6, &OSwl_Dlg::OnEnChangeEditN6)
	ON_EN_CHANGE(IDC_EDIT_N7, &OSwl_Dlg::OnEnChangeEditN7)
	ON_EN_CHANGE(IDC_EDIT_N8, &OSwl_Dlg::OnEnChangeEditN8)
	ON_EN_CHANGE(IDC_EDIT_N9, &OSwl_Dlg::OnEnChangeEditN9)
	ON_EN_CHANGE(IDC_EDIT_N10, &OSwl_Dlg::OnEnChangeEditN10)
END_MESSAGE_MAP()


// OSwl_Dlg 消息处理程序


BOOL OSwl_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpOSwl_Dlg=&m_OSwl_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_OSwl_Dlg;
	m_iWhoamI=GTWLT;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTWLT].sCmdstr);
	// TODO:  在此添加额外的初始化
	m_ComboBox_N.InsertString(0,"0: Do not return SMS to original number, ignore the Request Position message received and no matter whether the original number is in the <White Number List> or <Direct Number List> or not.");
	m_ComboBox_N.InsertString(1,"1: Do not filter the original number. It will return SMS to the original number as long as it receives Request Position message via SMS");
	m_ComboBox_N.InsertString(2,"2: Filter the original number. If the original number isn’t in <White Number List> or <Direct Number List>, it won’t return an SMS to the incoming number even if the device receives Request Position message via SMS");
	m_ComboBox_N.SetCurSel(1);

	SetDlgItemText(IDC_EDIT_MS,"1");
	m_Spin_Ms.SetBuddy(GetDlgItem(IDC_EDIT_MS)); //得到指向编辑框的窗口指针
	m_Spin_Ms.SetRange(1,10);

	SetDlgItemText(IDC_EDIT_ME,"1");
	m_Spin_ME.SetBuddy(GetDlgItem(IDC_EDIT_ME)); //得到指向编辑框的窗口指针
	m_Spin_ME.SetRange(1,10);

	///////////////////////////////////////////
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString OSwl_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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
	for (int i=0;i<ValueList.GetSize();i++)//重新组合为新命令
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
	sTemp=sNewCmd;	///二次分割,获取前4个部分加最后sleft
	for (int i=0;i<4;i++)
	{
		index1=sTemp.Find(",");
		//if (-1==index1)
		//{	
		//	ValueList.Add(sLeft);
		//	break;
		//}
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
	m_Edit_N4.GetWindowText(sNumber4);
	NumberList.Add(sNumber4);
	m_Edit_N5.GetWindowText(sNumber5);
	NumberList.Add(sNumber5);
	m_Edit_N6.GetWindowText(sNumber6);
	NumberList.Add(sNumber6);
	m_Edit_N7.GetWindowText(sNumber7);
	NumberList.Add(sNumber7);
	m_Edit_N8.GetWindowText(sNumber8);
	NumberList.Add(sNumber8);
	m_Edit_N9.GetWindowText(sNumber9);
	NumberList.Add(sNumber9);
	m_Edit_N10.GetWindowText(sNumber10);
	NumberList.Add(sNumber10);
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
		sFinalCMD=sFinalCMD+","+NumberList.GetAt(iStart-1);
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

BOOL OSwl_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>8)
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
		NumberList.RemoveAll();
		//////////////生产Number列表/////////标号从1开始不是从0开始
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
		if (iStart<=4&&iEnd>=4)
		{
			//NumberList.InsertAt(4,ValueList.GetAt(7)); //第一个Number
			m_Edit_N4.SetWindowText(NumberList.GetAt(4));
		}
		if (iStart<=5&&iEnd>=5)
		{
			//NumberList.InsertAt(5,ValueList.GetAt(8)); //第一个Number
			m_Edit_N5.SetWindowText(NumberList.GetAt(5));
		}
		if (iStart<=6&&iEnd>=6)
		{
			//NumberList.InsertAt(6,ValueList.GetAt(9)); //第一个Number
			m_Edit_N6.SetWindowText(NumberList.GetAt(6));
		}
		if (iStart<=7&&iEnd>=7)
		{
			//NumberList.InsertAt(7,ValueList.GetAt(10)); //第一个Number
			m_Edit_N7.SetWindowText(NumberList.GetAt(7));
		}		
		if (iStart<=8&&iEnd>=8)
		{
			//NumberList.InsertAt(8,ValueList.GetAt(11)); //第一个Number
			m_Edit_N8.SetWindowText(NumberList.GetAt(8));
		}
		if (iStart<=9&&iEnd>=9)
		{
			//NumberList.InsertAt(9,ValueList.GetAt(12)); //第一个Number
			m_Edit_N9.SetWindowText(NumberList.GetAt(9));
		}
		if (iStart<=10&&iEnd>=10)
		{
			//NumberList.InsertAt(10,ValueList.GetAt(13)); //第一个Number
			m_Edit_N10.SetWindowText(NumberList.GetAt(10));
		}
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
	
}

void OSwl_Dlg::OnCbnSelchangeComboN()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_N.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}


void OSwl_Dlg::OnDeltaposSpinMs(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_Ms.GetPos();
	m_Spin_Ms.SetPos(iTemp);
	m_Edit_MS.GetWindowText(strValue); 
	*pResult = 0;
}


void OSwl_Dlg::OnDeltaposSpinMe(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_ME.GetPos();
	m_Spin_ME.SetPos(iTemp);
	m_Edit_ME.GetWindowText(strValue);  
	*pResult = 0;
}





void OSwl_Dlg::OnEnChangeEditMs()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_MS.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=UpdataCMD(sStr,2,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void OSwl_Dlg::OnEnChangeEditMe()
{
	CString sStr="",sCMD="",sNewCMD="";
	m_Edit_ME.GetWindowText(sStr);
	m_Edit_GTCMD.GetWindowText(sCMD);
	sNewCMD=UpdataCMD(sStr,3,sCMD);
	m_Edit_GTCMD.SetWindowText(sNewCMD);
}


void OSwl_Dlg::OnEnChangeEditN1()
{
	CString sStart="",sEnd="",sStr="";
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
		CString sCMD="",sNewCMD="";
		m_Edit_N1.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(5-atoi(sStart)),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}


void OSwl_Dlg::OnEnChangeEditN2()
{
	CString sStart="",sEnd="",sStr="";
	m_Edit_N2.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_N2.SetWindowText("");
		return;
	}

	m_Edit_MS.GetWindowText(sStart);
	m_Edit_ME.GetWindowText(sEnd);
	if ((atoi(sStart)<=2)&&(atoi(sEnd)>=2))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_N2.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,(6-atoi(sStart)),sCMD);//确定位置，Start越大位置越近
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}

void OSwl_Dlg::OnEnChangeEditN3()
{
	CString sStart="",sEnd="",sStr="";
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
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_N3.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,7-atoi(sStart),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}


void OSwl_Dlg::OnEnChangeEditN4()
{
	CString sStart="",sEnd="",sStr="";
	m_Edit_N4.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_N4.SetWindowText("");
		return;
	}
	m_Edit_MS.GetWindowText(sStart);
	m_Edit_ME.GetWindowText(sEnd);
	if ((atoi(sStart)<=4)&&(atoi(sEnd)>=4))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_N4.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,8-atoi(sStart),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}


void OSwl_Dlg::OnEnChangeEditN5()
{
	CString sStart="",sEnd="",sStr="";
	m_Edit_N5.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_N5.SetWindowText("");
		return;
	}
	m_Edit_MS.GetWindowText(sStart);
	m_Edit_ME.GetWindowText(sEnd);
	if ((atoi(sStart)<=5)&&(atoi(sEnd)>=5))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_N5.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,9-atoi(sStart),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}


void OSwl_Dlg::OnEnChangeEditN6()
{
	CString sStart="",sEnd="",sStr="";
	m_Edit_N6.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_N6.SetWindowText("");
		return;
	}
	m_Edit_MS.GetWindowText(sStart);
	m_Edit_ME.GetWindowText(sEnd);
	if ((atoi(sStart)<=6)&&(atoi(sEnd)>=6))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_N6.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,10-atoi(sStart),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}


void OSwl_Dlg::OnEnChangeEditN7()
{
	CString sStart="",sEnd="",sStr="";
	m_Edit_N7.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_N7.SetWindowText("");
		return;
	}
	m_Edit_MS.GetWindowText(sStart);
	m_Edit_ME.GetWindowText(sEnd);
	if ((atoi(sStart)<=7)&&(atoi(sEnd)>=7))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_N7.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,11-atoi(sStart),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}


void OSwl_Dlg::OnEnChangeEditN8()
{
	CString sStart="",sEnd="",sStr="";
	m_Edit_N8.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_N8.SetWindowText("");
		return;
	}
	m_Edit_MS.GetWindowText(sStart);
	m_Edit_ME.GetWindowText(sEnd);
	if ((atoi(sStart)<=8)&&(atoi(sEnd)>=8))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_N8.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,12-atoi(sStart),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}


void OSwl_Dlg::OnEnChangeEditN9()
{
	CString sStart="",sEnd="",sStr="";
	m_Edit_N9.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_N9.SetWindowText("");
		return;
	}
	m_Edit_MS.GetWindowText(sStart);
	m_Edit_ME.GetWindowText(sEnd);
	if ((atoi(sStart)<=9)&&(atoi(sEnd)>=9))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_N9.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,13-atoi(sStart),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);

	}
}


void OSwl_Dlg::OnEnChangeEditN10()
{
	CString sStart="",sEnd="",sStr="";
	m_Edit_N10.GetWindowText(sStr);
	if (sStr.Find(",")!=-1)
	{
		AfxMessageBox("Input Error");
		m_Edit_N10.SetWindowText("");
		return;
	}
	m_Edit_MS.GetWindowText(sStart);
	m_Edit_ME.GetWindowText(sEnd);
	if ((atoi(sStart)<=10)&&(atoi(sEnd)>=10))
	{
		CString sStr="",sCMD="",sNewCMD="";
		m_Edit_N10.GetWindowText(sStr);
		m_Edit_GTCMD.GetWindowText(sCMD);
		sNewCMD=m_MYWORK.UpdataCMD(sStr,14-atoi(sStart),sCMD);
		m_Edit_GTCMD.SetWindowText(sNewCMD);
	}
}


