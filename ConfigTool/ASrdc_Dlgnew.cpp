// ASrdc_Dlgnew.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ASrdc_Dlgnew.h"
#include "afxdialogex.h"
#include "ConfigToolDlg.h"
#include "ASrdc_Dlgone.h"
#include "ASrdc_Dlgtwo.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
ASrdc_Dlgnew*	lpASrdc_Dlgnew;
extern ASrdc_Dlgone*	lpASrdc_Dlgone;
extern ASrdc_Dlgtwo*	lpASrdc_Dlgtwo;
//extern ASrdc_Dlgnew m_ASrdc_Dlg;
ASrdc_Dlgone	m_ASrdc_Dlgone;
ASrdc_Dlgtwo	m_ASrdc_Dlgtwo;
// ASrdc_Dlgnew 对话框
//全局变量
int g_CSelTab_rdc;
CArray<CString,CString>g_HListone,g_RListtwo,g_CListone;
CString g_sKREMValue,g_sUREMValue;

IMPLEMENT_DYNAMIC(ASrdc_Dlgnew, CMyTabBaseDlg)

ASrdc_Dlgnew::ASrdc_Dlgnew(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(ASrdc_Dlgnew::IDD, pParent)
{

}

ASrdc_Dlgnew::~ASrdc_Dlgnew()
{
}

void ASrdc_Dlgnew::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_rdc, m_Table_rdc);
	DDX_Control(pDX, IDC_MFCBUTTON_Page, m_MFCBUTTON_Page);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_COMBO_OI, m_ComboBox_OI);
	DDX_Control(pDX, IDC_SPIN_D, m_Spin_D);
	DDX_Control(pDX, IDC_SPIN_TT, m_Spin_TT);
	DDX_Control(pDX, IDC_CHECK_OutS, m_Check_OutS);
	DDX_Control(pDX, IDC_EDIT_D, m_Edit_D);
	DDX_Control(pDX, IDC_EDIT_TT, m_Edit_TT);
}


BEGIN_MESSAGE_MAP(ASrdc_Dlgnew, CMyTabBaseDlg)
	ON_BN_CLICKED(IDC_MFCBUTTON_Page, &ASrdc_Dlgnew::OnBnClickedMfcbuttonPage)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &ASrdc_Dlgnew::OnCbnSelchangeComboM)
	ON_CBN_SELCHANGE(IDC_COMBO_OI, &ASrdc_Dlgnew::OnCbnSelchangeComboOi)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D, &ASrdc_Dlgnew::OnDeltaposSpinD)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT, &ASrdc_Dlgnew::OnDeltaposSpinTt)
	ON_BN_CLICKED(IDC_CHECK_OutS, &ASrdc_Dlgnew::OnBnClickedCheckOuts)
	ON_EN_CHANGE(IDC_EDIT_D, &ASrdc_Dlgnew::OnEnChangeEditD)
	ON_EN_CHANGE(IDC_EDIT_TT, &ASrdc_Dlgnew::OnEnChangeEditTt)
END_MESSAGE_MAP()


// ASrdc_Dlgnew 消息处理程序

BOOL ASrdc_Dlgnew::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	// TODO:  在此添加额外的初始化
	lpASrdc_Dlgnew=&m_ASrdc_Dlg;//窗口寻址
	m_lpMyTabBaseDlg=&m_ASrdc_Dlg;
	m_iWhoamI=GTRMD;
	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTRMD].sCmdstr);

	m_ComboBox_M.InsertString(0,"0: Disable this function.");
	m_ComboBox_M.InsertString(1,"1: Enable this function.");
	m_ComboBox_M.SetCurSel(0);

	m_ComboBox_OI.InsertString(0,"0");
	m_ComboBox_OI.InsertString(1,"1");
	m_ComboBox_OI.InsertString(2,"2");
	m_ComboBox_OI.SetCurSel(0);

	SetDlgItemText(IDC_EDIT_D,"0");
	m_Spin_D.SetBuddy(GetDlgItem(IDC_EDIT_D)); //得到指向编辑框的窗口指针
	m_Spin_D.SetRange(0,255);
	SetDlgItemText(IDC_EDIT_TT,"0");
	m_Spin_TT.SetBuddy(GetDlgItem(IDC_EDIT_TT)); //得到指向编辑框的窗口指针
	m_Spin_TT.SetRange(0,255);

	m_ASrdc_Dlgone.Create(	IDD_ASrdc_DlgOne , &m_Table_rdc);
	m_ASrdc_Dlgtwo.Create(	IDD_ASrdc_DlgTwo , &m_Table_rdc);

	SetDlgItemText(IDC_MFCBUTTON_Page,"Last Page");
	OnBnClickedMfcbuttonPage();

	m_pFont = new CFont;
	m_pFont->CreateFont(16,							 // 字体高度
		0,							 // 字体宽度
		0,							 // 字体倾斜角
		0,							 // 字体倾斜角
		FW_BOLD,				         // 字体的粗细
		TRUE,						 // 字体是否为斜体
		TRUE,						 // 字体是否有下划线
		0,							 // 字体是否有删除线
		ANSI_CHARSET,				         // 字体使用的字符集
		OUT_DEFAULT_PRECIS,		     	                 // 指定如何选择合适的字体
		CLIP_DEFAULT_PRECIS,    		                 // 确定裁剪的精度
		DEFAULT_QUALITY,			                 // 怎么样跟选择的字体相符合
		DEFAULT_PITCH | FF_SWISS,	                         // 间距标志和属性标志
		_T("Arial"));				         // 字体的名称
	m_MFCBUTTON_Page.SetFont(m_pFont,FALSE);
	m_MFCBUTTON_Page.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_Page.SetTextColor(RGB(0,0,205));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void ASrdc_Dlgnew::ReSize(UINT nType, int cx, int cy)
{
	if (m_listRect.GetCount() > 0)  
	{  
		CRect dlgNow;  
		lpCConfigToolDlg->m_Table.GetWindowRect(&dlgNow);//主窗口Tab的大小
		POSITION pos = m_listRect.GetHeadPosition();//第一个保存的是对话框的Rect  

		CRect dlgSaved;  
		dlgSaved = m_listRect.GetNext(pos);  
		ScreenToClient(dlgNow);  

		double x = dlgNow.Width() * 1.0 / dlgSaved.Width();//根据当前和之前保存的对话框的宽高求比例  
		double y = dlgNow.Height()  *1.0/ dlgSaved.Height();  
		ClientToScreen(dlgNow);  

		CRect childSaved;  

		CWnd* pWnd = GetWindow(GW_CHILD);  
		while(pWnd)  
		{  
			childSaved = m_listRect.GetNext(pos);//依次获取子窗体的Rect  
			childSaved.left = (long)(dlgNow.left + (childSaved.left - dlgSaved.left)*x);//根据比例调整控件上下左右距离对话框的距离  
			childSaved.right = (long)(dlgNow.right + (childSaved.right - dlgSaved.right)*x);  
			childSaved.top = (long)(dlgNow.top + (childSaved.top - dlgSaved.top)*y);  
			childSaved.bottom = (long)(dlgNow.bottom + (childSaved.bottom - dlgSaved.bottom)*y);  
			if(pWnd->IsKindOf(RUNTIME_CLASS(CComboBox))) childSaved.bottom = childSaved.bottom+100;//判断是否为ComboBox类型
			ScreenToClient(childSaved);  
			pWnd->MoveWindow(childSaved);  
			pWnd = pWnd->GetNextWindow();  
		}  
	}

	CRect rectabnow; //当前Tab的尺寸传给子对话框
	m_Table_rdc.GetClientRect(&rectabnow);	
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;

	m_ASrdc_Dlgone.ReSize(0,tab_nWidth,tab_nHeight);
	m_ASrdc_Dlgtwo.ReSize(0,tab_nWidth,tab_nHeight);
	m_ASrdc_Dlgone.MoveWindow(&rectabnow);
	m_ASrdc_Dlgtwo.MoveWindow(&rectabnow);

	//if (m_ASrdc_Dlgone.IsWindowVisible())	m_ASrdc_Dlgone.ReSize(0,tab_nWidth,tab_nHeight);
	//if (m_ASrdc_Dlgtwo.IsWindowVisible())	m_ASrdc_Dlgtwo.ReSize(0,tab_nWidth,tab_nHeight);
	//if (m_ASrdc_Dlgone.IsWindowVisible())	m_ASrdc_Dlgone.MoveWindow(&rectabnow);
	//if (m_ASrdc_Dlgtwo.IsWindowVisible())	m_ASrdc_Dlgtwo.MoveWindow(&rectabnow);
}

void ASrdc_Dlgnew::HideAllWND()
{
	// TODO: 在此添加控件通知处理程序代码
	//隐藏其他所有窗口
	m_ASrdc_Dlgone.ShowWindow(FALSE);
	m_ASrdc_Dlgtwo.ShowWindow(FALSE);
}

void ASrdc_Dlgnew::OnBnClickedMfcbuttonPage()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sTemp="";
	if (GetDlgItemText(IDC_MFCBUTTON_Page,sTemp),sTemp=="Last Page")
	{
		SetDlgItemText(IDC_MFCBUTTON_Page,"Next Page");
		CRect rectabnow;
		m_Table_rdc.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
		int tab_nWidth = rectabnow.right-rectabnow.left;
		int tab_nHeight = rectabnow.bottom-rectabnow.top;
		m_ASrdc_Dlgone.ReSize(0,tab_nWidth,tab_nHeight);
		m_ASrdc_Dlgone.MoveWindow(&rectabnow);
		HideAllWND();	//隐藏其他所有窗口
		m_ASrdc_Dlgone.ShowWindow(TRUE);	//显示需要的窗口
		m_Table_rdc.SetCurSel(0);	//设置默认窗口
		g_CSelTab_rdc = 0;	
	}
	else
	{
		SetDlgItemText(IDC_MFCBUTTON_Page,"Last Page");
		CRect rectabnow;
		m_Table_rdc.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
		int tab_nWidth = rectabnow.right-rectabnow.left;
		int tab_nHeight = rectabnow.bottom-rectabnow.top;
		m_ASrdc_Dlgtwo.ReSize(0,tab_nWidth,tab_nHeight);
		m_ASrdc_Dlgtwo.MoveWindow(&rectabnow);
		HideAllWND();	//隐藏其他所有窗口
		m_ASrdc_Dlgtwo.ShowWindow(TRUE);	//显示需要的窗口
		m_Table_rdc.SetCurSel(0);	//设置默认窗口
		g_CSelTab_rdc = 0;
	}

}

void ASrdc_Dlgnew::GetCMD()
{
	CArray<CString,CString>CmdList;
	int iTemp=0;
	CString sNewCmd="";	CString sStr="";
	CString s1	="",s2	="",s3	="",s4	="",s5	="",s6	="",s7	="",s8	="",s9="";
	GetHValue();
	GetC20Value();
	GetR100Value();
	CmdList.InsertAt(1,"AT+GTRMD=HYIoT");
	iTemp=m_ComboBox_M.GetCurSel();
	if (iTemp==-1) iTemp=0;
	s2.Format("%d",iTemp);
	CmdList.InsertAt(2,s2);
	CmdList.InsertAt(3,"");
	CmdList.InsertAt(4,"");
	CmdList.InsertAt(5,"");
	CmdList.InsertAt(6,"");
	CmdList.Append(g_HListone);
	CmdList.Add("");
	CmdList.Add("");
	CmdList.Append(g_RListtwo);
	CmdList.Add("");
	CmdList.Add("");
	CmdList.Append(g_CListone);
	CmdList.Add("");
	CmdList.Add("");
	CmdList.Add(g_sKREMValue);
	CmdList.Add("");
	CmdList.Add("");
	CmdList.Add(g_sUREMValue);
	CmdList.Add("");
	CmdList.Add("");
	CmdList.Add("");
	CmdList.Add("");
	iTemp=m_ComboBox_OI.GetCurSel();
	if (iTemp==-1) iTemp=0;
	sStr.Format("%d",iTemp);
	CmdList.Add(sStr);
	iTemp=m_Check_OutS.GetCheck();
	sStr.Format("%d",iTemp);
	CmdList.Add(sStr);
	m_Edit_D.GetWindowText(sStr);
	CmdList.Add(sStr);
	m_Edit_TT.GetWindowText(sStr);
	CmdList.Add(sStr);
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

BOOL ASrdc_Dlgnew::UpdataPage(CString sStr)
{   //位置iPos是从0开始的
	CString sNewCmd="",sRight="",sLeft="",sTemp="";
	CArray<CString,CString>ValueList;
	CArray<CString,CString>NumberList;	
	int index1=0,index2=0;
	sTemp=sStr;//准备分割
	for (int i=0;i<1080;i++)
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
	if (ValueList.GetSize()>7)
	{
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboM();
		////////一定先END再Start才行//////////////////////
		lpASrdc_Dlgone->m_Edit_HE.SetWindowText(ValueList.GetAt(7));
		Sleep(100);
		lpASrdc_Dlgone->m_Edit_HS.SetWindowText(ValueList.GetAt(6));
		Sleep(100);
		int iHStart,iHEnd,iHSPosition;
		iHStart= atoi(ValueList.GetAt(6));
		iHEnd=atoi(ValueList.GetAt(7));
		iHSPosition=7+1;//HEnd+1,H第一个数据位置,
		//////////////生产H列表/////////标号从1开始不是从0开始
		NumberList.RemoveAll();
		for (int p=0;p<=(iHEnd-iHStart);p++)
		{
			NumberList.InsertAt((iHStart+p),ValueList.GetAt(8+p));
		}
		/////////////////////////////////////
		if (iHStart<=1&&	iHEnd>=1	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_H1	,NumberList.GetAt(1));
		if (iHStart<=2&&	iHEnd>=2	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_H2	,NumberList.GetAt(2));
		if (iHStart<=3&&	iHEnd>=3	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_H3	,NumberList.GetAt(3));
		if (iHStart<=4&&	iHEnd>=4	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_H4	,NumberList.GetAt(4));
		if (iHStart<=5&&	iHEnd>=5	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_H5	,NumberList.GetAt(5));
		if (iHStart<=6&&	iHEnd>=6	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_H6	,NumberList.GetAt(6));
		if (iHStart<=7&&	iHEnd>=7	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_H7	,NumberList.GetAt(7));
		if (iHStart<=8&&	iHEnd>=8	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_H8	,NumberList.GetAt(8));
		if (iHStart<=9&&	iHEnd>=9	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_H9	,NumberList.GetAt(9));
		if (iHStart<=10&&	iHEnd>=10	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_H10	,NumberList.GetAt(10));
		////////一定先END再Start才行//////////////////////
		lpASrdc_Dlgtwo->m_Edit_RE.SetWindowText(ValueList.GetAt(8+(iHEnd-iHStart+1)+1+2));//REND的位置
		Sleep(100);
		lpASrdc_Dlgtwo->m_Edit_RS.SetWindowText(ValueList.GetAt(8+(iHEnd-iHStart+1)+2));//RStart的位置
		Sleep(100);
		int iRStart,iREnd,iRSPosition;
		iRStart= atoi(ValueList.GetAt(8+(iHEnd-iHStart+1)+2));
		iREnd=atoi(ValueList.GetAt(8+(iHEnd-iHStart+1)+2+1));
		iRSPosition=8+(iHEnd-iHStart+1)+2+1+1;//REnd+1,R第一个数据位置,
		//////////////生产R列表/////////标号从1开始不是从0开始
		NumberList.RemoveAll();
		for (int p=0;p<=(iREnd-iRStart);p++)
		{//iRSPosition是第一个个数据的位置
			NumberList.InsertAt((iRStart+p),ValueList.GetAt(iRSPosition+p));
		}
		/////////////////////////////////////
		if (iRStart<=1&&	iREnd>=1)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R1	,NumberList.GetAt(1));
		if (iRStart<=2&&	iREnd>=2)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R2	,NumberList.GetAt(2));
		if (iRStart<=3&&	iREnd>=3)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R3	,NumberList.GetAt(3));
		if (iRStart<=4&&	iREnd>=4)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R4	,NumberList.GetAt(4));
		if (iRStart<=5&&	iREnd>=5)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R5	,NumberList.GetAt(5));
		if (iRStart<=6&&	iREnd>=6)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R6	,NumberList.GetAt(6));
		if (iRStart<=7&&	iREnd>=7)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R7	,NumberList.GetAt(7));
		if (iRStart<=8&&	iREnd>=8)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R8	,NumberList.GetAt(8));
		if (iRStart<=9&&	iREnd>=9)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R9	,NumberList.GetAt(9));
		if (iRStart<=10&&	iREnd>=10)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R10	,NumberList.GetAt(10));
		if (iRStart<=11&&	iREnd>=11)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R11	,NumberList.GetAt(11));
		if (iRStart<=12&&	iREnd>=12)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R12	,NumberList.GetAt(12));
		if (iRStart<=13&&	iREnd>=13)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R13	,NumberList.GetAt(13));
		if (iRStart<=14&&	iREnd>=14)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R14	,NumberList.GetAt(14));
		if (iRStart<=15&&	iREnd>=15)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R15	,NumberList.GetAt(15));
		if (iRStart<=16&&	iREnd>=16)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R16	,NumberList.GetAt(16));
		if (iRStart<=17&&	iREnd>=17)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R17	,NumberList.GetAt(17));
		if (iRStart<=18&&	iREnd>=18)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R18	,NumberList.GetAt(18));
		if (iRStart<=19&&	iREnd>=19)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R19	,NumberList.GetAt(19));
		if (iRStart<=20&&	iREnd>=20)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R20	,NumberList.GetAt(20));
		if (iRStart<=21&&	iREnd>=21)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R21	,NumberList.GetAt(21));
		if (iRStart<=22&&	iREnd>=22)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R22	,NumberList.GetAt(22));
		if (iRStart<=23&&	iREnd>=23)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R23	,NumberList.GetAt(23));
		if (iRStart<=24&&	iREnd>=24)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R24	,NumberList.GetAt(24));
		if (iRStart<=25&&	iREnd>=25)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R25	,NumberList.GetAt(25));
		if (iRStart<=26&&	iREnd>=26)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R26	,NumberList.GetAt(26));
		if (iRStart<=27&&	iREnd>=27)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R27	,NumberList.GetAt(27));
		if (iRStart<=28&&	iREnd>=28)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R28	,NumberList.GetAt(28));
		if (iRStart<=29&&	iREnd>=29)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R29	,NumberList.GetAt(29));
		if (iRStart<=30&&	iREnd>=30)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R30	,NumberList.GetAt(30));
		if (iRStart<=31&&	iREnd>=31)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R31	,NumberList.GetAt(31));
		if (iRStart<=32&&	iREnd>=32)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R32	,NumberList.GetAt(32));
		if (iRStart<=33&&	iREnd>=33)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R33	,NumberList.GetAt(33));
		if (iRStart<=34&&	iREnd>=34)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R34	,NumberList.GetAt(34));
		if (iRStart<=35&&	iREnd>=35)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R35	,NumberList.GetAt(35));
		if (iRStart<=36&&	iREnd>=36)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R36	,NumberList.GetAt(36));
		if (iRStart<=37&&	iREnd>=37)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R37	,NumberList.GetAt(37));
		if (iRStart<=38&&	iREnd>=38)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R38	,NumberList.GetAt(38));
		if (iRStart<=39&&	iREnd>=39)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R39	,NumberList.GetAt(39));
		if (iRStart<=40&&	iREnd>=40)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R40	,NumberList.GetAt(40));
		if (iRStart<=41&&	iREnd>=41)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R41	,NumberList.GetAt(41));
		if (iRStart<=42&&	iREnd>=42)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R42	,NumberList.GetAt(42));
		if (iRStart<=43&&	iREnd>=43)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R43	,NumberList.GetAt(43));
		if (iRStart<=44&&	iREnd>=44)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R44	,NumberList.GetAt(44));
		if (iRStart<=45&&	iREnd>=45)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R45	,NumberList.GetAt(45));
		if (iRStart<=46&&	iREnd>=46)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R46	,NumberList.GetAt(46));
		if (iRStart<=47&&	iREnd>=47)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R47	,NumberList.GetAt(47));
		if (iRStart<=48&&	iREnd>=48)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R48	,NumberList.GetAt(48));
		if (iRStart<=49&&	iREnd>=49)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R49	,NumberList.GetAt(49));
		if (iRStart<=50&&	iREnd>=50)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R50	,NumberList.GetAt(50));
		if (iRStart<=51&&	iREnd>=51)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R51	,NumberList.GetAt(51));
		if (iRStart<=52&&	iREnd>=52)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R52	,NumberList.GetAt(52));
		if (iRStart<=53&&	iREnd>=53)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R53	,NumberList.GetAt(53));
		if (iRStart<=54&&	iREnd>=54)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R54	,NumberList.GetAt(54));
		if (iRStart<=55&&	iREnd>=55)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R55	,NumberList.GetAt(55));
		if (iRStart<=56&&	iREnd>=56)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R56	,NumberList.GetAt(56));
		if (iRStart<=57&&	iREnd>=57)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R57	,NumberList.GetAt(57));
		if (iRStart<=58&&	iREnd>=58)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R58	,NumberList.GetAt(58));
		if (iRStart<=59&&	iREnd>=59)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R59	,NumberList.GetAt(59));
		if (iRStart<=60&&	iREnd>=60)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R60	,NumberList.GetAt(60));
		if (iRStart<=61&&	iREnd>=61)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R61	,NumberList.GetAt(61));
		if (iRStart<=62&&	iREnd>=62)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R62	,NumberList.GetAt(62));
		if (iRStart<=63&&	iREnd>=63)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R63	,NumberList.GetAt(63));
		if (iRStart<=64&&	iREnd>=64)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R64	,NumberList.GetAt(64));
		if (iRStart<=65&&	iREnd>=65)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R65	,NumberList.GetAt(65));
		if (iRStart<=66&&	iREnd>=66)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R66	,NumberList.GetAt(66));
		if (iRStart<=67&&	iREnd>=67)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R67	,NumberList.GetAt(67));
		if (iRStart<=68&&	iREnd>=68)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R68	,NumberList.GetAt(68));
		if (iRStart<=69&&	iREnd>=69)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R69	,NumberList.GetAt(69));
		if (iRStart<=70&&	iREnd>=70)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R70	,NumberList.GetAt(70));
		if (iRStart<=71&&	iREnd>=71)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R71	,NumberList.GetAt(71));
		if (iRStart<=72&&	iREnd>=72)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R72	,NumberList.GetAt(72));
		if (iRStart<=73&&	iREnd>=73)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R73	,NumberList.GetAt(73));
		if (iRStart<=74&&	iREnd>=74)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R74	,NumberList.GetAt(74));
		if (iRStart<=75&&	iREnd>=75)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R75	,NumberList.GetAt(75));
		if (iRStart<=76&&	iREnd>=76)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R76	,NumberList.GetAt(76));
		if (iRStart<=77&&	iREnd>=77)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R77	,NumberList.GetAt(77));
		if (iRStart<=78&&	iREnd>=78)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R78	,NumberList.GetAt(78));
		if (iRStart<=79&&	iREnd>=79)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R79	,NumberList.GetAt(79));
		if (iRStart<=80&&	iREnd>=80)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R80	,NumberList.GetAt(80));
		if (iRStart<=81&&	iREnd>=81)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R81	,NumberList.GetAt(81));
		if (iRStart<=82&&	iREnd>=82)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R82	,NumberList.GetAt(82));
		if (iRStart<=83&&	iREnd>=83)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R83	,NumberList.GetAt(83));
		if (iRStart<=84&&	iREnd>=84)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R84	,NumberList.GetAt(84));
		if (iRStart<=85&&	iREnd>=85)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R85	,NumberList.GetAt(85));
		if (iRStart<=86&&	iREnd>=86)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R86	,NumberList.GetAt(86));
		if (iRStart<=87&&	iREnd>=87)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R87	,NumberList.GetAt(87));
		if (iRStart<=88&&	iREnd>=88)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R88	,NumberList.GetAt(88));
		if (iRStart<=89&&	iREnd>=89)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R89	,NumberList.GetAt(89));
		if (iRStart<=90&&	iREnd>=90)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R90	,NumberList.GetAt(90));
		if (iRStart<=91&&	iREnd>=91)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R91	,NumberList.GetAt(91));
		if (iRStart<=92&&	iREnd>=92)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R92	,NumberList.GetAt(92));
		if (iRStart<=93&&	iREnd>=93)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R93	,NumberList.GetAt(93));
		if (iRStart<=94&&	iREnd>=94)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R94	,NumberList.GetAt(94));
		if (iRStart<=95&&	iREnd>=95)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R95	,NumberList.GetAt(95));
		if (iRStart<=96&&	iREnd>=96)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R96	,NumberList.GetAt(96));
		if (iRStart<=97&&	iREnd>=97)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R97	,NumberList.GetAt(97));
		if (iRStart<=98&&	iREnd>=98)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R98	,NumberList.GetAt(98));
		if (iRStart<=99&&	iREnd>=99)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R99	,NumberList.GetAt(99));
		if (iRStart<=100&&	iREnd>=100)	lpASrdc_Dlgtwo->	SetDlgItemText(IDC_EDIT_R100	,NumberList.GetAt(100));

		////////一定先END再Start才行//////////////////////
		lpASrdc_Dlgone->m_Edit_BE.SetWindowText(ValueList.GetAt(iRSPosition+(iREnd-iRStart+1)+1+2));
		Sleep(100);
		lpASrdc_Dlgone->m_Edit_BS.SetWindowText(ValueList.GetAt(iRSPosition+(iREnd-iRStart+1)+2));
		Sleep(100);
		int iBStart,iBEnd,iBSPosition;
		iBStart= atoi(ValueList.GetAt(iRSPosition+(iREnd-iRStart+1)+2));
		iBEnd=atoi(ValueList.GetAt(iRSPosition+(iREnd-iRStart+1)+2+1));
		iBSPosition=iRSPosition+(iREnd-iRStart+1)+2+1+1;//BEnd+1,B第一个数据位置,
		//////////////生产R列表/////////标号从1开始不是从0开始
		NumberList.RemoveAll();
		for (int p=0;p<=(iBEnd-iBStart);p++)
		{//iRSPosition是第一个个数据的位置
			NumberList.InsertAt((iBStart+p),ValueList.GetAt(iBSPosition+p));
		}
		/////////////////////////////////////
		if (iBStart<=1&&	iBEnd>=1	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C1	,NumberList.GetAt(1));
		if (iBStart<=2&&	iBEnd>=2	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C2	,NumberList.GetAt(2));
		if (iBStart<=3&&	iBEnd>=3	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C3	,NumberList.GetAt(3));
		if (iBStart<=4&&	iBEnd>=4	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C4	,NumberList.GetAt(4));
		if (iBStart<=5&&	iBEnd>=5	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C5	,NumberList.GetAt(5));
		if (iBStart<=6&&	iBEnd>=6	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C6	,NumberList.GetAt(6));
		if (iBStart<=7&&	iBEnd>=7	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C7	,NumberList.GetAt(7));
		if (iBStart<=8&&	iBEnd>=8	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C8	,NumberList.GetAt(8));
		if (iBStart<=9&&	iBEnd>=9	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C9	,NumberList.GetAt(9));
		if (iBStart<=10&&	iBEnd>=10	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C10	,NumberList.GetAt(10));
		if (iBStart<=11&&	iBEnd>=11	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C11	,NumberList.GetAt(11));
		if (iBStart<=12&&	iBEnd>=12	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C12	,NumberList.GetAt(12));
		if (iBStart<=13&&	iBEnd>=13	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C13	,NumberList.GetAt(13));
		if (iBStart<=14&&	iBEnd>=14	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C14	,NumberList.GetAt(14));
		if (iBStart<=15&&	iBEnd>=15	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C15	,NumberList.GetAt(15));
		if (iBStart<=16&&	iBEnd>=16	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C16	,NumberList.GetAt(16));
		if (iBStart<=17&&	iBEnd>=17	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C17	,NumberList.GetAt(17));
		if (iBStart<=18&&	iBEnd>=18	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C18	,NumberList.GetAt(18));
		if (iBStart<=19&&	iBEnd>=19	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C19	,NumberList.GetAt(19));
		if (iBStart<=20&&	iBEnd>=20	) lpASrdc_Dlgone->SetDlgItemText(IDC_EDIT_C20	,NumberList.GetAt(20));
		////////////////////////获取Foot部分///////////
		int iSize=0;
		iSize=ValueList.GetSize()-1;

		lpASrdc_Dlgone->SetKREMValue(ValueList.GetAt(iSize-14));
		lpASrdc_Dlgone->SetUREMValue(ValueList.GetAt(iSize-11));

		m_ComboBox_OI.SetCurSel(atoi(ValueList.GetAt(iSize-6)));
		OnCbnSelchangeComboOi();
		m_Check_OutS.SetCheck(atoi(ValueList.GetAt(iSize-5)));
		OnBnClickedCheckOuts();
		m_Edit_D.SetWindowText(ValueList.GetAt(iSize-4));
		m_Edit_TT.SetWindowText(ValueList.GetAt(iSize-3));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
}

void ASrdc_Dlgnew::OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D.GetPos();
	m_Spin_D.SetPos(iTemp);
	m_Edit_D.GetWindowText(strValue);  
	*pResult = 0;
}

void ASrdc_Dlgnew::OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT.GetPos();
	m_Spin_TT.SetPos(iTemp);
	m_Edit_TT.GetWindowText(strValue);  
	*pResult = 0;
}

void ASrdc_Dlgnew::GetHValue()
{
	CString sH1="",sH2="",sH3="",sH4="",sH5="",sH6="",sH7="",sH8="",sH9="",sH10="";
	CString sStart="",sEnd="";
	CArray<CString,CString>TempList;
	//必须先清空
	g_HListone.RemoveAll();
	if (lpASrdc_Dlgone==NULL) return;//启动窗口第一次lpASrdc_Dlgone是空的
	lpASrdc_Dlgone->m_Edit_HS.GetWindowText(sStart);
	lpASrdc_Dlgone->m_Edit_HE.GetWindowText(sEnd);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_H1,sH1);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_H2,	sH2);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_H3,	sH3);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_H4,	sH4);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_H5,	sH5);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_H6,	sH6);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_H7,	sH7);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_H8,	sH8);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_H9,	sH9);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_H10,sH10);
	TempList.InsertAt(1,	sH1);
	TempList.InsertAt(2,	sH2);
	TempList.InsertAt(3,	sH3);
	TempList.InsertAt(4,	sH4);
	TempList.InsertAt(5,	sH5);
	TempList.InsertAt(6,	sH6);
	TempList.InsertAt(7,	sH7);
	TempList.InsertAt(8,	sH8);
	TempList.InsertAt(9,	sH9);
	TempList.InsertAt(10,sH10);
	//////////////生产H列表/////////标号从1开始不是从0开始
	g_HListone.Add(sStart);
	g_HListone.Add(sEnd);
	for (int p=0;p<=(atoi(sEnd)-atoi(sStart));p++)
	{
		g_HListone.Add(TempList.GetAt(atoi(sStart)+p));
	}
}

void ASrdc_Dlgnew::GetC20Value()
{
	CString sC1="",	sC2="",	sC3="",	sC4="",	sC5="",	sC6="",	sC7="",	sC8="",	sC9="",	sC10="";
	CString sC11="",	sC12="",	sC13="",	sC14="",	sC15="",	sC16="",	sC17="",	sC18="",	sC19="",	sC20="";
	CString sStart="",sEnd="";
	CArray<CString,CString>TempList;
	//必须先清空
	g_CListone.RemoveAll();
	if (lpASrdc_Dlgone==NULL) return;//启动窗口第一次lpASrdc_Dlgone是空的
	lpASrdc_Dlgone->m_Edit_BS.GetWindowText(sStart);
	lpASrdc_Dlgone->m_Edit_BE.GetWindowText(sEnd);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C1,	sC1);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C2,	sC2);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C3,	sC3);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C4,	sC4);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C5,	sC5);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C6,	sC6);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C7,	sC7);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C8,	sC8);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C9,	sC9);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C10,sC10);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C11,sC11);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C12,sC12);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C13,sC13);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C14,sC14);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C15,sC15);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C16,sC16);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C17,sC17);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C18,sC18);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C19,sC19);
	lpASrdc_Dlgone->GetDlgItemText(IDC_EDIT_C20,sC20);
	TempList.InsertAt(1,sC1);
	TempList.InsertAt(2,sC2);
	TempList.InsertAt(3,sC3);
	TempList.InsertAt(4,sC4);
	TempList.InsertAt(5,sC5);
	TempList.InsertAt(6,sC6);
	TempList.InsertAt(7,sC7);
	TempList.InsertAt(8,sC8);
	TempList.InsertAt(9,sC9);
	TempList.InsertAt(10,sC10);
	TempList.InsertAt(11,sC11);
	TempList.InsertAt(12,sC12);
	TempList.InsertAt(13,sC13);
	TempList.InsertAt(14,sC14);
	TempList.InsertAt(15,sC15);
	TempList.InsertAt(16,sC16);
	TempList.InsertAt(17,sC17);
	TempList.InsertAt(18,sC18);
	TempList.InsertAt(19,sC19);
	TempList.InsertAt(20,sC20);
	//////////////生产C列表/////////标号从1开始不是从0开始
	g_CListone.Add(sStart);
	g_CListone.Add(sEnd);
	for (int p=0;p<=(atoi(sEnd)-atoi(sStart));p++)
	{
		g_CListone.Add(TempList.GetAt(atoi(sStart)+p));
	}
}

void ASrdc_Dlgnew::GetR100Value()
{
	CString sR1="",	sR11="",	sR21="",	sR31="",	sR41="",	sR51="",	sR61="",	sR71="",	sR81="",	sR91="";
	CString sR2="",	sR12="",	sR22="",	sR32="",	sR42="",	sR52="",	sR62="",	sR72="",	sR82="",	sR92="";
	CString sR3="",	sR13="",	sR23="",	sR33="",	sR43="",	sR53="",	sR63="",	sR73="",	sR83="",	sR93="";
	CString sR4="",	sR14="",	sR24="",	sR34="",	sR44="",	sR54="",	sR64="",	sR74="",	sR84="",	sR94="";
	CString sR5="",	sR15="",	sR25="",	sR35="",	sR45="",	sR55="",	sR65="",	sR75="",	sR85="",	sR95="";
	CString sR6="",	sR16="",	sR26="",	sR36="",	sR46="",	sR56="",	sR66="",	sR76="",	sR86="",	sR96="";
	CString sR7="",	sR17="",	sR27="",	sR37="",	sR47="",	sR57="",	sR67="",	sR77="",	sR87="",	sR97="";
	CString sR8="",	sR18="",	sR28="",	sR38="",	sR48="",	sR58="",	sR68="",	sR78="",	sR88="",	sR98="";
	CString sR9="",	sR19="",	sR29="",	sR39="",	sR49="",	sR59="",	sR69="",	sR79="",	sR89="",	sR99="";
	CString sR10="",	sR20="",	sR30="",	sR40="",	sR50="",	sR60="",	sR70="",	sR80="",	sR90="",	sR100="";
	CString sStart="",sEnd="";
	CArray<CString,CString>TempList;
	//必须先清空
	g_RListtwo.RemoveAll();
	if (lpASrdc_Dlgtwo==NULL) return;//启动窗口第一次lpASrdc_Dlgone是空的
	lpASrdc_Dlgtwo->m_Edit_RS.GetWindowText(sStart);
	lpASrdc_Dlgtwo->m_Edit_RE.GetWindowText(sEnd);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R1,	sR1);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R2,	sR2);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R3,	sR3);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R4,	sR4);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R5,	sR5);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R6,	sR6);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R7,	sR7);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R8,	sR8);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R9,	sR9);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R10,	sR10);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R11,	sR11);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R12,	sR12);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R13,	sR13);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R14,	sR14);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R15,	sR15);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R16,	sR16);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R17,	sR17);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R18,	sR18);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R19,	sR19);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R20,	sR20);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R21,	sR21);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R22,	sR22);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R23,	sR23);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R24,	sR24);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R25,	sR25);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R26,	sR26);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R27,	sR27);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R28,	sR28);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R29,	sR29);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R30,	sR30);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R31,	sR31);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R32,	sR32);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R33,	sR33);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R34,	sR34);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R35,	sR35);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R36,	sR36);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R37,	sR37);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R38,	sR38);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R39,	sR39);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R40,	sR40);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R41,	sR41);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R42,	sR42);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R43,	sR43);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R44,	sR44);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R45,	sR45);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R46,	sR46);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R47,	sR47);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R48,	sR48);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R49,	sR49);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R50,	sR50);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R51,	sR51);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R52,	sR52);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R53,	sR53);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R54,	sR54);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R55,	sR55);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R56,	sR56);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R57,	sR57);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R58,	sR58);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R59,	sR59);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R60,	sR60);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R61,	sR61);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R62,	sR62);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R63,	sR63);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R64,	sR64);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R65,	sR65);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R66,	sR66);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R67,	sR67);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R68,	sR68);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R69,	sR69);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R70,	sR70);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R71,	sR71);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R72,	sR72);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R73,	sR73);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R74,	sR74);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R75,	sR75);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R76,	sR76);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R77,	sR77);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R78,	sR78);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R79,	sR79);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R80,	sR80);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R81,	sR81);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R82,	sR82);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R83,	sR83);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R84,	sR84);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R85,	sR85);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R86,	sR86);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R87,	sR87);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R88,	sR88);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R89,	sR89);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R90,	sR90);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R91,	sR91);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R92,	sR92);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R93,	sR93);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R94,	sR94);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R95,	sR95);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R96,	sR96);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R97,	sR97);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R98,	sR98);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R99,	sR99);
	lpASrdc_Dlgtwo->GetDlgItemText(IDC_EDIT_R100,	sR100);
	TempList.InsertAt(1,	sR1);
	TempList.InsertAt(2,	sR2);
	TempList.InsertAt(3,	sR3);
	TempList.InsertAt(4,	sR4);
	TempList.InsertAt(5,	sR5);
	TempList.InsertAt(6,	sR6);
	TempList.InsertAt(7,	sR7);
	TempList.InsertAt(8,	sR8);
	TempList.InsertAt(9,	sR9);
	TempList.InsertAt(10,	sR10);
	TempList.InsertAt(11,	sR11);
	TempList.InsertAt(12,	sR12);
	TempList.InsertAt(13,	sR13);
	TempList.InsertAt(14,	sR14);
	TempList.InsertAt(15,	sR15);
	TempList.InsertAt(16,	sR16);
	TempList.InsertAt(17,	sR17);
	TempList.InsertAt(18,	sR18);
	TempList.InsertAt(19,	sR19);
	TempList.InsertAt(20,	sR20);
	TempList.InsertAt(21,	sR21);
	TempList.InsertAt(22,	sR22);
	TempList.InsertAt(23,	sR23);
	TempList.InsertAt(24,	sR24);
	TempList.InsertAt(25,	sR25);
	TempList.InsertAt(26,	sR26);
	TempList.InsertAt(27,	sR27);
	TempList.InsertAt(28,	sR28);
	TempList.InsertAt(29,	sR29);
	TempList.InsertAt(30,	sR30);
	TempList.InsertAt(31,	sR31);
	TempList.InsertAt(32,	sR32);
	TempList.InsertAt(33,	sR33);
	TempList.InsertAt(34,	sR34);
	TempList.InsertAt(35,	sR35);
	TempList.InsertAt(36,	sR36);
	TempList.InsertAt(37,	sR37);
	TempList.InsertAt(38,	sR38);
	TempList.InsertAt(39,	sR39);
	TempList.InsertAt(40,	sR40);
	TempList.InsertAt(41,	sR41);
	TempList.InsertAt(42,	sR42);
	TempList.InsertAt(43,	sR43);
	TempList.InsertAt(44,	sR44);
	TempList.InsertAt(45,	sR45);
	TempList.InsertAt(46,	sR46);
	TempList.InsertAt(47,	sR47);
	TempList.InsertAt(48,	sR48);
	TempList.InsertAt(49,	sR49);
	TempList.InsertAt(50,	sR50);
	TempList.InsertAt(51,	sR51);
	TempList.InsertAt(52,	sR52);
	TempList.InsertAt(53,	sR53);
	TempList.InsertAt(54,	sR54);
	TempList.InsertAt(55,	sR55);
	TempList.InsertAt(56,	sR56);
	TempList.InsertAt(57,	sR57);
	TempList.InsertAt(58,	sR58);
	TempList.InsertAt(59,	sR59);
	TempList.InsertAt(60,	sR60);
	TempList.InsertAt(61,	sR61);
	TempList.InsertAt(62,	sR62);
	TempList.InsertAt(63,	sR63);
	TempList.InsertAt(64,	sR64);
	TempList.InsertAt(65,	sR65);
	TempList.InsertAt(66,	sR66);
	TempList.InsertAt(67,	sR67);
	TempList.InsertAt(68,	sR68);
	TempList.InsertAt(69,	sR69);
	TempList.InsertAt(70,	sR70);
	TempList.InsertAt(71,	sR71);
	TempList.InsertAt(72,	sR72);
	TempList.InsertAt(73,	sR73);
	TempList.InsertAt(74,	sR74);
	TempList.InsertAt(75,	sR75);
	TempList.InsertAt(76,	sR76);
	TempList.InsertAt(77,	sR77);
	TempList.InsertAt(78,	sR78);
	TempList.InsertAt(79,	sR79);
	TempList.InsertAt(80,	sR80);
	TempList.InsertAt(81,	sR81);
	TempList.InsertAt(82,	sR82);
	TempList.InsertAt(83,	sR83);
	TempList.InsertAt(84,	sR84);
	TempList.InsertAt(85,	sR85);
	TempList.InsertAt(86,	sR86);
	TempList.InsertAt(87,	sR87);
	TempList.InsertAt(88,	sR88);
	TempList.InsertAt(89,	sR89);
	TempList.InsertAt(90,	sR90);
	TempList.InsertAt(91,	sR91);
	TempList.InsertAt(92,	sR92);
	TempList.InsertAt(93,	sR93);
	TempList.InsertAt(94,	sR94);
	TempList.InsertAt(95,	sR95);
	TempList.InsertAt(96,	sR96);
	TempList.InsertAt(97,	sR97);
	TempList.InsertAt(98,	sR98);
	TempList.InsertAt(99,	sR99);
	TempList.InsertAt(100,	sR100);
	//////////////生产R列表/////////标号从1开始不是从0开始
	g_RListtwo.Add(sStart);
	g_RListtwo.Add(sEnd);
	for (int p=0;p<=(atoi(sEnd)-atoi(sStart));p++)
	{
		g_RListtwo.Add(TempList.GetAt(atoi(sStart)+p));
	}
}

void ASrdc_Dlgnew::OnBnClickedCheckOuts()
{
	GetCMD();
}

void ASrdc_Dlgnew::OnEnChangeEditD()
{
	GetCMD();
}

void ASrdc_Dlgnew::OnEnChangeEditTt()
{
	GetCMD();
}

void ASrdc_Dlgnew::OnCbnSelchangeComboM()
{
	GetCMD();
}

void ASrdc_Dlgnew::OnCbnSelchangeComboOi()
{
	GetCMD();
}