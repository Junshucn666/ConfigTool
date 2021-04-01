// ASrdc_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ASrdc_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
//extern ASrdc_Dlg m_ASrdc_Dlg;
ASrdc_Dlg*	lpASrdc_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////
CArray<CString,CString>g_HList,g_RList,g_CList;

IMPLEMENT_DYNAMIC(ASrdc_Dlg, CDialogEx)

ASrdc_Dlg::ASrdc_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ASrdc_Dlg::IDD, pParent)
{

}

ASrdc_Dlg::~ASrdc_Dlg()
{
}

void ASrdc_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_GTRMD, m_Edit_GTRMD);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_COMBO_OI, m_ComboBox_OI);
	DDX_Control(pDX, IDC_CHECK_OutS, m_Check_OutS);
	DDX_Control(pDX, IDC_SPIN_D, m_Spin_D);
	DDX_Control(pDX, IDC_SPIN_TT, m_Spin_TT);
	DDX_Control(pDX, IDC_EDIT_D, m_Edit_D);
	DDX_Control(pDX, IDC_EDIT_TT, m_Edit_TT);
	DDX_Control(pDX, IDC_EDIT_HS, m_Edit_HS);
	DDX_Control(pDX, IDC_EDIT_HE, m_Edit_HE);
	DDX_Control(pDX, IDC_SPIN_MS, m_Spin_MS);
	DDX_Control(pDX, IDC_SPIN_ME, m_Spin_ME);
	DDX_Control(pDX, IDC_SPIN_RS, m_Spin_RS);
	DDX_Control(pDX, IDC_SPIN_RE, m_Spin_RE);
	DDX_Control(pDX, IDC_EDIT_RS, m_Edit_RS);
	DDX_Control(pDX, IDC_EDIT_RE, m_Edit_RE);
	DDX_Control(pDX, IDC_SPIN_BS, m_Spin_BS);
	DDX_Control(pDX, IDC_SPIN_BE, m_Spin_BE);
	DDX_Control(pDX, IDC_EDIT_BS, m_Edit_BS);
	DDX_Control(pDX, IDC_EDIT_BE, m_Edit_BE);
}


BEGIN_MESSAGE_MAP(ASrdc_Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_Read, &ASrdc_Dlg::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_Send, &ASrdc_Dlg::OnBnClickedButtonSend)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &ASrdc_Dlg::OnCbnSelchangeComboM)
	ON_BN_CLICKED(IDOK, &ASrdc_Dlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT_HS, &ASrdc_Dlg::OnEnChangeEditHs)
	ON_CBN_SELCHANGE(IDC_COMBO_OI, &ASrdc_Dlg::OnCbnSelchangeComboOi)
	ON_BN_CLICKED(IDC_CHECK_OutS, &ASrdc_Dlg::OnBnClickedCheckOuts)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_D, &ASrdc_Dlg::OnDeltaposSpinD)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TT, &ASrdc_Dlg::OnDeltaposSpinTt)
	ON_EN_CHANGE(IDC_EDIT_D, &ASrdc_Dlg::OnEnChangeEditD)
	ON_EN_CHANGE(IDC_EDIT_TT, &ASrdc_Dlg::OnEnChangeEditTt)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MS, &ASrdc_Dlg::OnDeltaposSpinMs)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ME, &ASrdc_Dlg::OnDeltaposSpinMe)
	ON_EN_CHANGE(IDC_EDIT_HE, &ASrdc_Dlg::OnEnChangeEditHe)
	ON_EN_CHANGE(IDC_EDIT_RE, &ASrdc_Dlg::OnEnChangeEditRe)
	ON_EN_CHANGE(IDC_EDIT_RS, &ASrdc_Dlg::OnEnChangeEditRs)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_RS, &ASrdc_Dlg::OnDeltaposSpinRs)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_RE, &ASrdc_Dlg::OnDeltaposSpinRe)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_BS, &ASrdc_Dlg::OnDeltaposSpinBs)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_BE, &ASrdc_Dlg::OnDeltaposSpinBe)
	ON_EN_CHANGE(IDC_EDIT_BS, &ASrdc_Dlg::OnEnChangeEditBs)
	ON_EN_CHANGE(IDC_EDIT_BE, &ASrdc_Dlg::OnEnChangeEditBe)
	ON_EN_CHANGE(IDC_EDIT_H1, &ASrdc_Dlg::OnEnChangeEditH1)
	ON_EN_CHANGE(IDC_EDIT_H2, &ASrdc_Dlg::OnEnChangeEditH2)
	ON_EN_CHANGE(IDC_EDIT_H3, &ASrdc_Dlg::OnEnChangeEditH3)
	ON_EN_CHANGE(IDC_EDIT_H4, &ASrdc_Dlg::OnEnChangeEditH4)
	ON_EN_CHANGE(IDC_EDIT_H5, &ASrdc_Dlg::OnEnChangeEditH5)
	ON_EN_CHANGE(IDC_EDIT_H6, &ASrdc_Dlg::OnEnChangeEditH6)
	ON_EN_CHANGE(IDC_EDIT_H7, &ASrdc_Dlg::OnEnChangeEditH7)
	ON_EN_CHANGE(IDC_EDIT_H8, &ASrdc_Dlg::OnEnChangeEditH8)
	ON_EN_CHANGE(IDC_EDIT_H9, &ASrdc_Dlg::OnEnChangeEditH9)
	ON_EN_CHANGE(IDC_EDIT_H10, &ASrdc_Dlg::OnEnChangeEditH10)
	ON_EN_CHANGE(IDC_EDIT_R1, &ASrdc_Dlg::OnEnChangeEditR1)
	ON_EN_CHANGE(IDC_EDIT_R2, &ASrdc_Dlg::OnEnChangeEditR2)
	ON_EN_CHANGE(IDC_EDIT_R3, &ASrdc_Dlg::OnEnChangeEditR3)
	ON_EN_CHANGE(IDC_EDIT_R4, &ASrdc_Dlg::OnEnChangeEditR4)
	ON_EN_CHANGE(IDC_EDIT_R5, &ASrdc_Dlg::OnEnChangeEditR5)
	ON_EN_CHANGE(IDC_EDIT_R6, &ASrdc_Dlg::OnEnChangeEditR6)
	ON_EN_CHANGE(IDC_EDIT_R7, &ASrdc_Dlg::OnEnChangeEditR7)
	ON_EN_CHANGE(IDC_EDIT_R8, &ASrdc_Dlg::OnEnChangeEditR8)
	ON_EN_CHANGE(IDC_EDIT_R9, &ASrdc_Dlg::OnEnChangeEditR9)
	ON_EN_CHANGE(IDC_EDIT_R10, &ASrdc_Dlg::OnEnChangeEditR10)
	ON_EN_CHANGE(IDC_EDIT_R11, &ASrdc_Dlg::OnEnChangeEditR11)
	ON_EN_CHANGE(IDC_EDIT_R12, &ASrdc_Dlg::OnEnChangeEditR12)
	ON_EN_CHANGE(IDC_EDIT_R13, &ASrdc_Dlg::OnEnChangeEditR13)
	ON_EN_CHANGE(IDC_EDIT_R14, &ASrdc_Dlg::OnEnChangeEditR14)
	ON_EN_CHANGE(IDC_EDIT_R15, &ASrdc_Dlg::OnEnChangeEditR15)
	ON_EN_CHANGE(IDC_EDIT_R16, &ASrdc_Dlg::OnEnChangeEditR16)
	ON_EN_CHANGE(IDC_EDIT_R17, &ASrdc_Dlg::OnEnChangeEditR17)
	ON_EN_CHANGE(IDC_EDIT_R18, &ASrdc_Dlg::OnEnChangeEditR18)
	ON_EN_CHANGE(IDC_EDIT_R19, &ASrdc_Dlg::OnEnChangeEditR19)
	ON_EN_CHANGE(IDC_EDIT_R20, &ASrdc_Dlg::OnEnChangeEditR20)
	ON_EN_CHANGE(IDC_EDIT_R21, &ASrdc_Dlg::OnEnChangeEditR21)
	ON_EN_CHANGE(IDC_EDIT_R22, &ASrdc_Dlg::OnEnChangeEditR22)
	ON_EN_CHANGE(IDC_EDIT_R23, &ASrdc_Dlg::OnEnChangeEditR23)
	ON_EN_CHANGE(IDC_EDIT_R24, &ASrdc_Dlg::OnEnChangeEditR24)
	ON_EN_CHANGE(IDC_EDIT_R25, &ASrdc_Dlg::OnEnChangeEditR25)
	ON_EN_CHANGE(IDC_EDIT_R26, &ASrdc_Dlg::OnEnChangeEditR26)
	ON_EN_CHANGE(IDC_EDIT_R27, &ASrdc_Dlg::OnEnChangeEditR27)
	ON_EN_CHANGE(IDC_EDIT_R28, &ASrdc_Dlg::OnEnChangeEditR28)
	ON_EN_CHANGE(IDC_EDIT_R29, &ASrdc_Dlg::OnEnChangeEditR29)
	ON_EN_CHANGE(IDC_EDIT_R30, &ASrdc_Dlg::OnEnChangeEditR30)
	ON_EN_CHANGE(IDC_EDIT_R31, &ASrdc_Dlg::OnEnChangeEditR31)
	ON_EN_CHANGE(IDC_EDIT_R32, &ASrdc_Dlg::OnEnChangeEditR32)
	ON_EN_CHANGE(IDC_EDIT_R33, &ASrdc_Dlg::OnEnChangeEditR33)
	ON_EN_CHANGE(IDC_EDIT_R34, &ASrdc_Dlg::OnEnChangeEditR34)
	ON_EN_CHANGE(IDC_EDIT_R35, &ASrdc_Dlg::OnEnChangeEditR35)
	ON_EN_CHANGE(IDC_EDIT_R36, &ASrdc_Dlg::OnEnChangeEditR36)
	ON_EN_CHANGE(IDC_EDIT_R37, &ASrdc_Dlg::OnEnChangeEditR37)
	ON_EN_CHANGE(IDC_EDIT_R38, &ASrdc_Dlg::OnEnChangeEditR38)
	ON_EN_CHANGE(IDC_EDIT_R39, &ASrdc_Dlg::OnEnChangeEditR39)
	ON_EN_CHANGE(IDC_EDIT_R40, &ASrdc_Dlg::OnEnChangeEditR40)
	ON_EN_CHANGE(IDC_EDIT_R41, &ASrdc_Dlg::OnEnChangeEditR41)
	ON_EN_CHANGE(IDC_EDIT_R42, &ASrdc_Dlg::OnEnChangeEditR42)
	ON_EN_CHANGE(IDC_EDIT_R43, &ASrdc_Dlg::OnEnChangeEditR43)
	ON_EN_CHANGE(IDC_EDIT_R44, &ASrdc_Dlg::OnEnChangeEditR44)
	ON_EN_CHANGE(IDC_EDIT_R45, &ASrdc_Dlg::OnEnChangeEditR45)
	ON_EN_CHANGE(IDC_EDIT_R46, &ASrdc_Dlg::OnEnChangeEditR46)
	ON_EN_CHANGE(IDC_EDIT_R47, &ASrdc_Dlg::OnEnChangeEditR47)
	ON_EN_CHANGE(IDC_EDIT_R48, &ASrdc_Dlg::OnEnChangeEditR48)
	ON_EN_CHANGE(IDC_EDIT_R49, &ASrdc_Dlg::OnEnChangeEditR49)
	ON_EN_CHANGE(IDC_EDIT_R50, &ASrdc_Dlg::OnEnChangeEditR50)
	ON_EN_CHANGE(IDC_EDIT_R51, &ASrdc_Dlg::OnEnChangeEditR51)
	ON_EN_CHANGE(IDC_EDIT_R52, &ASrdc_Dlg::OnEnChangeEditR52)
	ON_EN_CHANGE(IDC_EDIT_R53, &ASrdc_Dlg::OnEnChangeEditR53)
	ON_EN_CHANGE(IDC_EDIT_R54, &ASrdc_Dlg::OnEnChangeEditR54)
	ON_EN_CHANGE(IDC_EDIT_R55, &ASrdc_Dlg::OnEnChangeEditR55)
	ON_EN_CHANGE(IDC_EDIT_R56, &ASrdc_Dlg::OnEnChangeEditR56)
	ON_EN_CHANGE(IDC_EDIT_R57, &ASrdc_Dlg::OnEnChangeEditR57)
	ON_EN_CHANGE(IDC_EDIT_R58, &ASrdc_Dlg::OnEnChangeEditR58)
	ON_EN_CHANGE(IDC_EDIT_R59, &ASrdc_Dlg::OnEnChangeEditR59)
	ON_EN_CHANGE(IDC_EDIT_R60, &ASrdc_Dlg::OnEnChangeEditR60)
	ON_EN_CHANGE(IDC_EDIT_R61, &ASrdc_Dlg::OnEnChangeEditR61)
	ON_EN_CHANGE(IDC_EDIT_R62, &ASrdc_Dlg::OnEnChangeEditR62)
	ON_EN_CHANGE(IDC_EDIT_R63, &ASrdc_Dlg::OnEnChangeEditR63)
	ON_EN_CHANGE(IDC_EDIT_R64, &ASrdc_Dlg::OnEnChangeEditR64)
	ON_EN_CHANGE(IDC_EDIT_R65, &ASrdc_Dlg::OnEnChangeEditR65)
	ON_EN_CHANGE(IDC_EDIT_R66, &ASrdc_Dlg::OnEnChangeEditR66)
	ON_EN_CHANGE(IDC_EDIT_R67, &ASrdc_Dlg::OnEnChangeEditR67)
	ON_EN_CHANGE(IDC_EDIT_R68, &ASrdc_Dlg::OnEnChangeEditR68)
	ON_EN_CHANGE(IDC_EDIT_R69, &ASrdc_Dlg::OnEnChangeEditR69)
	ON_EN_CHANGE(IDC_EDIT_R70, &ASrdc_Dlg::OnEnChangeEditR70)
	ON_EN_CHANGE(IDC_EDIT_R71, &ASrdc_Dlg::OnEnChangeEditR71)
	ON_EN_CHANGE(IDC_EDIT_R72, &ASrdc_Dlg::OnEnChangeEditR72)
	ON_EN_CHANGE(IDC_EDIT_R73, &ASrdc_Dlg::OnEnChangeEditR73)
	ON_EN_CHANGE(IDC_EDIT_R74, &ASrdc_Dlg::OnEnChangeEditR74)
	ON_EN_CHANGE(IDC_EDIT_R75, &ASrdc_Dlg::OnEnChangeEditR75)
	ON_EN_CHANGE(IDC_EDIT_R76, &ASrdc_Dlg::OnEnChangeEditR76)
	ON_EN_CHANGE(IDC_EDIT_R77, &ASrdc_Dlg::OnEnChangeEditR77)
	ON_EN_CHANGE(IDC_EDIT_R78, &ASrdc_Dlg::OnEnChangeEditR78)
	ON_EN_CHANGE(IDC_EDIT_R79, &ASrdc_Dlg::OnEnChangeEditR79)
	ON_EN_CHANGE(IDC_EDIT_R80, &ASrdc_Dlg::OnEnChangeEditR80)
	ON_EN_CHANGE(IDC_EDIT_R81, &ASrdc_Dlg::OnEnChangeEditR81)
	ON_EN_CHANGE(IDC_EDIT_R82, &ASrdc_Dlg::OnEnChangeEditR82)
	ON_EN_CHANGE(IDC_EDIT_R83, &ASrdc_Dlg::OnEnChangeEditR83)
	ON_EN_CHANGE(IDC_EDIT_R84, &ASrdc_Dlg::OnEnChangeEditR84)
	ON_EN_CHANGE(IDC_EDIT_R85, &ASrdc_Dlg::OnEnChangeEditR85)
	ON_EN_CHANGE(IDC_EDIT_R86, &ASrdc_Dlg::OnEnChangeEditR86)
	ON_EN_CHANGE(IDC_EDIT_R87, &ASrdc_Dlg::OnEnChangeEditR87)
	ON_EN_CHANGE(IDC_EDIT_R88, &ASrdc_Dlg::OnEnChangeEditR88)
	ON_EN_CHANGE(IDC_EDIT_R89, &ASrdc_Dlg::OnEnChangeEditR89)
	ON_EN_CHANGE(IDC_EDIT_R90, &ASrdc_Dlg::OnEnChangeEditR90)
	ON_EN_CHANGE(IDC_EDIT_R91, &ASrdc_Dlg::OnEnChangeEditR91)
	ON_EN_CHANGE(IDC_EDIT_R92, &ASrdc_Dlg::OnEnChangeEditR92)
	ON_EN_CHANGE(IDC_EDIT_R93, &ASrdc_Dlg::OnEnChangeEditR93)
	ON_EN_CHANGE(IDC_EDIT_R94, &ASrdc_Dlg::OnEnChangeEditR94)
	ON_EN_CHANGE(IDC_EDIT_R95, &ASrdc_Dlg::OnEnChangeEditR95)
	ON_EN_CHANGE(IDC_EDIT_R96, &ASrdc_Dlg::OnEnChangeEditR96)
	ON_EN_CHANGE(IDC_EDIT_R97, &ASrdc_Dlg::OnEnChangeEditR97)
	ON_EN_CHANGE(IDC_EDIT_R98, &ASrdc_Dlg::OnEnChangeEditR98)
	ON_EN_CHANGE(IDC_EDIT_R99, &ASrdc_Dlg::OnEnChangeEditR99)
	ON_EN_CHANGE(IDC_EDIT_R100, &ASrdc_Dlg::OnEnChangeEditR100)
	ON_EN_CHANGE(IDC_EDIT_C1, &ASrdc_Dlg::OnEnChangeEditC1)
	ON_EN_CHANGE(IDC_EDIT_C3, &ASrdc_Dlg::OnEnChangeEditC3)
	ON_EN_CHANGE(IDC_EDIT_C5, &ASrdc_Dlg::OnEnChangeEditC5)
	ON_EN_CHANGE(IDC_EDIT_C7, &ASrdc_Dlg::OnEnChangeEditC7)
	ON_EN_CHANGE(IDC_EDIT_C9, &ASrdc_Dlg::OnEnChangeEditC9)
	ON_EN_CHANGE(IDC_EDIT_C11, &ASrdc_Dlg::OnEnChangeEditC11)
	ON_EN_CHANGE(IDC_EDIT_C13, &ASrdc_Dlg::OnEnChangeEditC13)
	ON_EN_CHANGE(IDC_EDIT_C15, &ASrdc_Dlg::OnEnChangeEditC15)
	ON_EN_CHANGE(IDC_EDIT_C17, &ASrdc_Dlg::OnEnChangeEditC17)
	ON_EN_CHANGE(IDC_EDIT_C19, &ASrdc_Dlg::OnEnChangeEditC19)
	ON_EN_CHANGE(IDC_EDIT_C2, &ASrdc_Dlg::OnEnChangeEditC2)
	ON_EN_CHANGE(IDC_EDIT_C4, &ASrdc_Dlg::OnEnChangeEditC4)
	ON_EN_CHANGE(IDC_EDIT_C6, &ASrdc_Dlg::OnEnChangeEditC6)
	ON_EN_CHANGE(IDC_EDIT_C8, &ASrdc_Dlg::OnEnChangeEditC8)
	ON_EN_CHANGE(IDC_EDIT_C10, &ASrdc_Dlg::OnEnChangeEditC10)
	ON_EN_CHANGE(IDC_EDIT_C12, &ASrdc_Dlg::OnEnChangeEditC12)
	ON_EN_CHANGE(IDC_EDIT_C14, &ASrdc_Dlg::OnEnChangeEditC14)
	ON_EN_CHANGE(IDC_EDIT_C16, &ASrdc_Dlg::OnEnChangeEditC16)
	ON_EN_CHANGE(IDC_EDIT_C18, &ASrdc_Dlg::OnEnChangeEditC18)
	ON_EN_CHANGE(IDC_EDIT_C20, &ASrdc_Dlg::OnEnChangeEditC20)
	ON_EN_CHANGE(IDC_EDIT_GTRMD, &ASrdc_Dlg::OnEnChangeEditGtrmd)
	END_MESSAGE_MAP()


// ASrdc_Dlg 消息处理程序


BOOL ASrdc_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//lpASrdc_Dlg=&m_ASrdc_Dlg;//窗口寻址
	SetDlgItemText(IDC_EDIT_GTRMD,stu_ConfigCMD.tdWriteCmds[GTRMD].sCmdstr);

	m_ComboBox_M.InsertString(0,"0: Disable this function.");
	m_ComboBox_M.InsertString(1,"1: Enable this function.");
	m_ComboBox_M.SetCurSel(0);

	m_ComboBox_OI.InsertString(0,"0");
	m_ComboBox_OI.InsertString(1,"1");
	m_ComboBox_OI.InsertString(2,"2");
	m_ComboBox_OI.SetCurSel(0);
	///////////////
	SetDlgItemText(IDC_EDIT_HS,"1");
	m_Spin_MS.SetBuddy(GetDlgItem(IDC_EDIT_HS)); //得到指向编辑框的窗口指针
	m_Spin_MS.SetRange(1,10);
	/////////////////
	SetDlgItemText(IDC_EDIT_HE,"1");
	m_Spin_ME.SetBuddy(GetDlgItem(IDC_EDIT_HE)); //得到指向编辑框的窗口指针
	m_Spin_ME.SetRange(1,10);
	/////////////////
	SetDlgItemText(IDC_EDIT_RS,"1");
	m_Spin_RS.SetBuddy(GetDlgItem(IDC_EDIT_RS)); //得到指向编辑框的窗口指针
	m_Spin_RS.SetRange(1,100);
	/////////////////
	SetDlgItemText(IDC_EDIT_RE,"1");
	m_Spin_RE.SetBuddy(GetDlgItem(IDC_EDIT_RE)); //得到指向编辑框的窗口指针
	m_Spin_RE.SetRange(1,100);
	/////////////////
	SetDlgItemText(IDC_EDIT_BS,"1");
	m_Spin_BS.SetBuddy(GetDlgItem(IDC_EDIT_BS)); //得到指向编辑框的窗口指针
	m_Spin_BS.SetRange(1,20);
	/////////////////
	SetDlgItemText(IDC_EDIT_BE,"1");
	m_Spin_BE.SetBuddy(GetDlgItem(IDC_EDIT_BE)); //得到指向编辑框的窗口指针
	m_Spin_BE.SetRange(1,20);
	/////////////////
	SetDlgItemText(IDC_EDIT_D,"0");
	m_Spin_D.SetBuddy(GetDlgItem(IDC_EDIT_D)); //得到指向编辑框的窗口指针
	m_Spin_D.SetRange(0,255);
	SetDlgItemText(IDC_EDIT_TT,"0");
	m_Spin_TT.SetBuddy(GetDlgItem(IDC_EDIT_TT)); //得到指向编辑框的窗口指针
	m_Spin_TT.SetRange(0,255);
	///////////////
	CWnd *pWnd;
	pWnd = GetDlgItem( IDC_EDIT_GTRMD );
	pWnd->SetWindowPos( NULL,13,499,542,26,SWP_NOZORDER );
	pWnd = GetDlgItem( IDC_BUTTON_Read );    
	pWnd->SetWindowPos( NULL,565,493,75,33,SWP_NOZORDER );   
	pWnd = GetDlgItem( IDC_BUTTON_Send );    
	pWnd->SetWindowPos( NULL,647,493,75,33,SWP_NOZORDER ); 

	SetBackgroundColor(RGB(176,196,222));
	 
	/////////////////////////////
	CRect rect;  
	//GetWindowRect(&rect); 
	lpCConfigToolDlg->m_Table.GetWindowRect(&rect);  
	m_listRect.AddTail(rect);//对话框的区域  
	CWnd* pReWnd = GetWindow(GW_CHILD);//获取子窗体  
	while(pReWnd)  
	{  
		pReWnd->GetWindowRect(rect);//子窗体的区域  
		m_listRect.AddTail(rect);           //CList<CRect,CRect> m_listRect成员变量  
		pReWnd = pReWnd->GetNextWindow();//取下一个子窗体  
	}  
	///////////////////////////////////////////
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

static UINT ThreadManager_SEND_THREAD(LPVOID LPARAM)//线程
{
	ThreadData* stu_Threaddata;
	stu_Threaddata=(ThreadData*)LPARAM;
	///////////////////////////////
	g_hEvent=CreateEvent(NULL,FALSE,FALSE,NULL);//自动重置方式
	SetEvent(g_hEvent);//设置事件有效，等待子线程Waitfor
	////////////////////////
	m_MYWORK.CmdSend_Thread_Start(stu_Threaddata);
	////////////////等待线程结果////////////
	Sleep(3000);//让出CPU,让子线程Waitfor
	WaitForSingleObject(g_hEvent,INFINITE);//等待子线程的SetEvent
	SetEvent(g_hEvent);
	CloseHandle(g_hEvent);
	//////////////////////////////////
	CString stemp= stu_Threaddata->sReturn;
	//lpSCbsi_Dlg->m_Edit_GTBSI.GetWindowText(stemp);
	MYTHREAD_WORK=FALSE;//释放按钮
	return 0;
}

static UINT ThreadManager_READ_THREAD(LPVOID LPARAM)//线程
{
	ThreadData* stu_Threaddata;
	stu_Threaddata=(ThreadData*)LPARAM;
	///////////////////////////////
	g_hEvent=CreateEvent(NULL,FALSE,FALSE,NULL);//自动重置方式
	SetEvent(g_hEvent);//设置事件有效，等待子线程Waitfor
	////////////////////////
	m_MYWORK.CmdSend_Thread_Start(stu_Threaddata);
	////////////////等待线程结果////////////
	Sleep(3000);//让出CPU,让子线程Waitfor
	WaitForSingleObject(g_hEvent,INFINITE);//等待子线程的SetEvent
	SetEvent(g_hEvent);
	CloseHandle(g_hEvent);
	MYTHREAD_WORK=FALSE;//释放按钮
	//////////////////////////////////
	if (stu_Threaddata->sReturn.Find("GTRMD")==-1) return 0;
	lpASrdc_Dlg->UpdataPage(stu_Threaddata->sReturn);
	return 0;
}

void ASrdc_Dlg::OnBnClickedButtonRead()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!MYTHREAD_WORK)
	{
		MYTHREAD_WORK=TRUE;
		ThreadData *stu_Threaddata =new ThreadData;
		stu_Threaddata->sCmdstr="AT+CONFIG?GTRMD";
		stu_Threaddata->sReturn="";
		AfxBeginThread(ThreadManager_READ_THREAD,stu_Threaddata,THREAD_PRIORITY_NORMAL,0,0,NULL);	
	}
	else
	{
		AfxMessageBox("ConfigTool IS RUNNING");
	}
}

void ASrdc_Dlg::OnBnClickedButtonSend()
{
	if (!MYTHREAD_WORK)
	{
		MYTHREAD_WORK=TRUE;
		CString sCMD="";
		m_Edit_GTRMD.GetWindowText(sCMD);
		ThreadData *stu_Threaddata =new ThreadData;
		stu_Threaddata->sCmdstr.Format("AT+CONFIG=%s",sCMD);
		stu_Threaddata->sReturn="";
		AfxBeginThread(ThreadManager_SEND_THREAD,stu_Threaddata,THREAD_PRIORITY_NORMAL,0,0,NULL);	
	}
	else
	{
		AfxMessageBox("ConfigTool IS RUNNING");
	}
}

void ASrdc_Dlg::GetCMD()
{
	CArray<CString,CString>CmdList;
	int iTemp=0;
	CString sNewCmd="";	CString sStr="";
	CString s1	="",s2	="",s3	="",s4	="",s5	="",s6	="",s7	="",s8	="",s9="";
	GetHValue();
	GetR100Value();
	GetC20Value();
	CmdList.InsertAt(1,"AT+GTRMD=HYIoT");
	iTemp=m_ComboBox_M.GetCurSel();
	if (iTemp==-1) iTemp=0;
	s2.Format("%d",iTemp);
	CmdList.InsertAt(2,s2);
	CmdList.InsertAt(3,"");
	CmdList.InsertAt(4,"");
	CmdList.InsertAt(5,"");
	CmdList.InsertAt(6,"");
	CmdList.Append(g_HList);
	CmdList.Add("");
	CmdList.Add("");
	CmdList.Append(g_RList);
	CmdList.Add("");
	CmdList.Add("");
	CmdList.Append(g_CList);
	CmdList.Add("");
	CmdList.Add("");
	CmdList.Add("7FFF");
	CmdList.Add("");
	CmdList.Add("");
	CmdList.Add("7FFF");
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
	m_Edit_GTRMD.SetWindowText(sNewCmd);
}

void ASrdc_Dlg::GetHValue()
{
	CString sH1="",sH2="",sH3="",sH4="",sH5="",sH6="",sH7="",sH8="",sH9="",sH10="";
	CString sStart="",sEnd="";
	CArray<CString,CString>TempList;
	//必须先清空
	g_HList.RemoveAll();
	m_Edit_HS.GetWindowText(sStart);
	m_Edit_HE.GetWindowText(sEnd);
	GetDlgItemText(IDC_EDIT_H1,sH1);
	GetDlgItemText(IDC_EDIT_H2,	sH2);
	GetDlgItemText(IDC_EDIT_H3,	sH3);
	GetDlgItemText(IDC_EDIT_H4,	sH4);
	GetDlgItemText(IDC_EDIT_H5,	sH5);
	GetDlgItemText(IDC_EDIT_H6,	sH6);
	GetDlgItemText(IDC_EDIT_H7,	sH7);
	GetDlgItemText(IDC_EDIT_H8,	sH8);
	GetDlgItemText(IDC_EDIT_H9,	sH9);
	GetDlgItemText(IDC_EDIT_H10,sH10);
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
	g_HList.Add(sStart);
	g_HList.Add(sEnd);
	for (int p=0;p<=(atoi(sEnd)-atoi(sStart));p++)
	{
		g_HList.Add(TempList.GetAt(atoi(sStart)+p));
	}
}

void ASrdc_Dlg::GetC20Value()
{
	CString sC1="",	sC2="",	sC3="",	sC4="",	sC5="",	sC6="",	sC7="",	sC8="",	sC9="",	sC10="";
	CString sC11="",	sC12="",	sC13="",	sC14="",	sC15="",	sC16="",	sC17="",	sC18="",	sC19="",	sC20="";
	CString sStart="",sEnd="";
	CArray<CString,CString>TempList;
	//必须先清空
	g_CList.RemoveAll();
	m_Edit_BS.GetWindowText(sStart);
	m_Edit_BE.GetWindowText(sEnd);
	GetDlgItemText(IDC_EDIT_C1,	sC1);
	GetDlgItemText(IDC_EDIT_C2,	sC2);
	GetDlgItemText(IDC_EDIT_C3,	sC3);
	GetDlgItemText(IDC_EDIT_C4,	sC4);
	GetDlgItemText(IDC_EDIT_C5,	sC5);
	GetDlgItemText(IDC_EDIT_C6,	sC6);
	GetDlgItemText(IDC_EDIT_C7,	sC7);
	GetDlgItemText(IDC_EDIT_C8,	sC8);
	GetDlgItemText(IDC_EDIT_C9,	sC9);
	GetDlgItemText(IDC_EDIT_C10,	sC10);
	GetDlgItemText(IDC_EDIT_C11,	sC11);
	GetDlgItemText(IDC_EDIT_C12,	sC12);
	GetDlgItemText(IDC_EDIT_C13,	sC13);
	GetDlgItemText(IDC_EDIT_C14,	sC14);
	GetDlgItemText(IDC_EDIT_C15,	sC15);
	GetDlgItemText(IDC_EDIT_C16,	sC16);
	GetDlgItemText(IDC_EDIT_C17,	sC17);
	GetDlgItemText(IDC_EDIT_C18,	sC18);
	GetDlgItemText(IDC_EDIT_C19,	sC19);
	GetDlgItemText(IDC_EDIT_C20,	sC20);
	TempList.InsertAt(1,	sC1);
	TempList.InsertAt(2,	sC2);
	TempList.InsertAt(3,	sC3);
	TempList.InsertAt(4,	sC4);
	TempList.InsertAt(5,	sC5);
	TempList.InsertAt(6,	sC6);
	TempList.InsertAt(7,	sC7);
	TempList.InsertAt(8,	sC8);
	TempList.InsertAt(9,	sC9);
	TempList.InsertAt(10,	sC10);
	TempList.InsertAt(11,	sC11);
	TempList.InsertAt(12,	sC12);
	TempList.InsertAt(13,	sC13);
	TempList.InsertAt(14,	sC14);
	TempList.InsertAt(15,	sC15);
	TempList.InsertAt(16,	sC16);
	TempList.InsertAt(17,	sC17);
	TempList.InsertAt(18,	sC18);
	TempList.InsertAt(19,	sC19);
	TempList.InsertAt(20,	sC20);
	//////////////生产C列表/////////标号从1开始不是从0开始
	g_CList.Add(sStart);
	g_CList.Add(sEnd);
	for (int p=0;p<=(atoi(sEnd)-atoi(sStart));p++)
	{
		g_CList.Add(TempList.GetAt(atoi(sStart)+p));
	}
}

void ASrdc_Dlg::GetR100Value()
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
	g_RList.RemoveAll();
	m_Edit_RS.GetWindowText(sStart);
	m_Edit_RE.GetWindowText(sEnd);
	GetDlgItemText(IDC_EDIT_R1,	sR1);
	GetDlgItemText(IDC_EDIT_R2,	sR2);
	GetDlgItemText(IDC_EDIT_R3,	sR3);
	GetDlgItemText(IDC_EDIT_R4,	sR4);
	GetDlgItemText(IDC_EDIT_R5,	sR5);
	GetDlgItemText(IDC_EDIT_R6,	sR6);
	GetDlgItemText(IDC_EDIT_R7,	sR7);
	GetDlgItemText(IDC_EDIT_R8,	sR8);
	GetDlgItemText(IDC_EDIT_R9,	sR9);
	GetDlgItemText(IDC_EDIT_R10,	sR10);
	GetDlgItemText(IDC_EDIT_R11,	sR11);
	GetDlgItemText(IDC_EDIT_R12,	sR12);
	GetDlgItemText(IDC_EDIT_R13,	sR13);
	GetDlgItemText(IDC_EDIT_R14,	sR14);
	GetDlgItemText(IDC_EDIT_R15,	sR15);
	GetDlgItemText(IDC_EDIT_R16,	sR16);
	GetDlgItemText(IDC_EDIT_R17,	sR17);
	GetDlgItemText(IDC_EDIT_R18,	sR18);
	GetDlgItemText(IDC_EDIT_R19,	sR19);
	GetDlgItemText(IDC_EDIT_R20,	sR20);
	GetDlgItemText(IDC_EDIT_R21,	sR21);
	GetDlgItemText(IDC_EDIT_R22,	sR22);
	GetDlgItemText(IDC_EDIT_R23,	sR23);
	GetDlgItemText(IDC_EDIT_R24,	sR24);
	GetDlgItemText(IDC_EDIT_R25,	sR25);
	GetDlgItemText(IDC_EDIT_R26,	sR26);
	GetDlgItemText(IDC_EDIT_R27,	sR27);
	GetDlgItemText(IDC_EDIT_R28,	sR28);
	GetDlgItemText(IDC_EDIT_R29,	sR29);
	GetDlgItemText(IDC_EDIT_R30,	sR30);
	GetDlgItemText(IDC_EDIT_R31,	sR31);
	GetDlgItemText(IDC_EDIT_R32,	sR32);
	GetDlgItemText(IDC_EDIT_R33,	sR33);
	GetDlgItemText(IDC_EDIT_R34,	sR34);
	GetDlgItemText(IDC_EDIT_R35,	sR35);
	GetDlgItemText(IDC_EDIT_R36,	sR36);
	GetDlgItemText(IDC_EDIT_R37,	sR37);
	GetDlgItemText(IDC_EDIT_R38,	sR38);
	GetDlgItemText(IDC_EDIT_R39,	sR39);
	GetDlgItemText(IDC_EDIT_R40,	sR40);
	GetDlgItemText(IDC_EDIT_R41,	sR41);
	GetDlgItemText(IDC_EDIT_R42,	sR42);
	GetDlgItemText(IDC_EDIT_R43,	sR43);
	GetDlgItemText(IDC_EDIT_R44,	sR44);
	GetDlgItemText(IDC_EDIT_R45,	sR45);
	GetDlgItemText(IDC_EDIT_R46,	sR46);
	GetDlgItemText(IDC_EDIT_R47,	sR47);
	GetDlgItemText(IDC_EDIT_R48,	sR48);
	GetDlgItemText(IDC_EDIT_R49,	sR49);
	GetDlgItemText(IDC_EDIT_R50,	sR50);
	GetDlgItemText(IDC_EDIT_R51,	sR51);
	GetDlgItemText(IDC_EDIT_R52,	sR52);
	GetDlgItemText(IDC_EDIT_R53,	sR53);
	GetDlgItemText(IDC_EDIT_R54,	sR54);
	GetDlgItemText(IDC_EDIT_R55,	sR55);
	GetDlgItemText(IDC_EDIT_R56,	sR56);
	GetDlgItemText(IDC_EDIT_R57,	sR57);
	GetDlgItemText(IDC_EDIT_R58,	sR58);
	GetDlgItemText(IDC_EDIT_R59,	sR59);
	GetDlgItemText(IDC_EDIT_R60,	sR60);
	GetDlgItemText(IDC_EDIT_R61,	sR61);
	GetDlgItemText(IDC_EDIT_R62,	sR62);
	GetDlgItemText(IDC_EDIT_R63,	sR63);
	GetDlgItemText(IDC_EDIT_R64,	sR64);
	GetDlgItemText(IDC_EDIT_R65,	sR65);
	GetDlgItemText(IDC_EDIT_R66,	sR66);
	GetDlgItemText(IDC_EDIT_R67,	sR67);
	GetDlgItemText(IDC_EDIT_R68,	sR68);
	GetDlgItemText(IDC_EDIT_R69,	sR69);
	GetDlgItemText(IDC_EDIT_R70,	sR70);
	GetDlgItemText(IDC_EDIT_R71,	sR71);
	GetDlgItemText(IDC_EDIT_R72,	sR72);
	GetDlgItemText(IDC_EDIT_R73,	sR73);
	GetDlgItemText(IDC_EDIT_R74,	sR74);
	GetDlgItemText(IDC_EDIT_R75,	sR75);
	GetDlgItemText(IDC_EDIT_R76,	sR76);
	GetDlgItemText(IDC_EDIT_R77,	sR77);
	GetDlgItemText(IDC_EDIT_R78,	sR78);
	GetDlgItemText(IDC_EDIT_R79,	sR79);
	GetDlgItemText(IDC_EDIT_R80,	sR80);
	GetDlgItemText(IDC_EDIT_R81,	sR81);
	GetDlgItemText(IDC_EDIT_R82,	sR82);
	GetDlgItemText(IDC_EDIT_R83,	sR83);
	GetDlgItemText(IDC_EDIT_R84,	sR84);
	GetDlgItemText(IDC_EDIT_R85,	sR85);
	GetDlgItemText(IDC_EDIT_R86,	sR86);
	GetDlgItemText(IDC_EDIT_R87,	sR87);
	GetDlgItemText(IDC_EDIT_R88,	sR88);
	GetDlgItemText(IDC_EDIT_R89,	sR89);
	GetDlgItemText(IDC_EDIT_R90,	sR90);
	GetDlgItemText(IDC_EDIT_R91,	sR91);
	GetDlgItemText(IDC_EDIT_R92,	sR92);
	GetDlgItemText(IDC_EDIT_R93,	sR93);
	GetDlgItemText(IDC_EDIT_R94,	sR94);
	GetDlgItemText(IDC_EDIT_R95,	sR95);
	GetDlgItemText(IDC_EDIT_R96,	sR96);
	GetDlgItemText(IDC_EDIT_R97,	sR97);
	GetDlgItemText(IDC_EDIT_R98,	sR98);
	GetDlgItemText(IDC_EDIT_R99,	sR99);
	GetDlgItemText(IDC_EDIT_R100,	sR100);
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
	g_RList.Add(sStart);
	g_RList.Add(sEnd);
	for (int p=0;p<=(atoi(sEnd)-atoi(sStart));p++)
	{
		g_RList.Add(TempList.GetAt(atoi(sStart)+p));
	}
}

CString ASrdc_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL ASrdc_Dlg::UpdataPage(CString sStr)
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
		m_Edit_HE.SetWindowText(ValueList.GetAt(7));
		Sleep(100);
		m_Edit_HS.SetWindowText(ValueList.GetAt(6));
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
		if (iHStart<=1&&	iHEnd>=1	) SetDlgItemText(IDC_EDIT_H1	,NumberList.GetAt(1));
		if (iHStart<=2&&	iHEnd>=2	) SetDlgItemText(IDC_EDIT_H2	,NumberList.GetAt(2));
		if (iHStart<=3&&	iHEnd>=3	) SetDlgItemText(IDC_EDIT_H3	,NumberList.GetAt(3));
		if (iHStart<=4&&	iHEnd>=4	) SetDlgItemText(IDC_EDIT_H4	,NumberList.GetAt(4));
		if (iHStart<=5&&	iHEnd>=5	) SetDlgItemText(IDC_EDIT_H5	,NumberList.GetAt(5));
		if (iHStart<=6&&	iHEnd>=6	) SetDlgItemText(IDC_EDIT_H6	,NumberList.GetAt(6));
		if (iHStart<=7&&	iHEnd>=7	) SetDlgItemText(IDC_EDIT_H7	,NumberList.GetAt(7));
		if (iHStart<=8&&	iHEnd>=8	) SetDlgItemText(IDC_EDIT_H8	,NumberList.GetAt(8));
		if (iHStart<=9&&	iHEnd>=9	) SetDlgItemText(IDC_EDIT_H9	,NumberList.GetAt(9));
		if (iHStart<=10&&	iHEnd>=10	) SetDlgItemText(IDC_EDIT_H10	,NumberList.GetAt(10));
		////////一定先END再Start才行//////////////////////
		m_Edit_RE.SetWindowText(ValueList.GetAt(8+(iHEnd-iHStart+1)+1+2));//REND的位置
		Sleep(100);
		m_Edit_RS.SetWindowText(ValueList.GetAt(8+(iHEnd-iHStart+1)+2));//RStart的位置
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
		if (iRStart<=1&&	iREnd>=1	) SetDlgItemText(IDC_EDIT_R1	,NumberList.GetAt(1));
		if (iRStart<=2&&	iREnd>=2	) SetDlgItemText(IDC_EDIT_R2	,NumberList.GetAt(2));
		if (iRStart<=3&&	iREnd>=3	) SetDlgItemText(IDC_EDIT_R3	,NumberList.GetAt(3));
		if (iRStart<=4&&	iREnd>=4	) SetDlgItemText(IDC_EDIT_R4	,NumberList.GetAt(4));
		if (iRStart<=5&&	iREnd>=5	) SetDlgItemText(IDC_EDIT_R5	,NumberList.GetAt(5));
		if (iRStart<=6&&	iREnd>=6	) SetDlgItemText(IDC_EDIT_R6	,NumberList.GetAt(6));
		if (iRStart<=7&&	iREnd>=7	) SetDlgItemText(IDC_EDIT_R7	,NumberList.GetAt(7));
		if (iRStart<=8&&	iREnd>=8	) SetDlgItemText(IDC_EDIT_R8	,NumberList.GetAt(8));
		if (iRStart<=9&&	iREnd>=9	) SetDlgItemText(IDC_EDIT_R9	,NumberList.GetAt(9));
		if (iRStart<=10&&	iREnd>=10	) SetDlgItemText(IDC_EDIT_R10	,NumberList.GetAt(10));
		if (iRStart<=11&&	iREnd>=11	) SetDlgItemText(IDC_EDIT_R11	,NumberList.GetAt(11));
		if (iRStart<=12&&	iREnd>=12	) SetDlgItemText(IDC_EDIT_R12	,NumberList.GetAt(12));
		if (iRStart<=13&&	iREnd>=13	) SetDlgItemText(IDC_EDIT_R13	,NumberList.GetAt(13));
		if (iRStart<=14&&	iREnd>=14	) SetDlgItemText(IDC_EDIT_R14	,NumberList.GetAt(14));
		if (iRStart<=15&&	iREnd>=15	) SetDlgItemText(IDC_EDIT_R15	,NumberList.GetAt(15));
		if (iRStart<=16&&	iREnd>=16	) SetDlgItemText(IDC_EDIT_R16	,NumberList.GetAt(16));
		if (iRStart<=17&&	iREnd>=17	) SetDlgItemText(IDC_EDIT_R17	,NumberList.GetAt(17));
		if (iRStart<=18&&	iREnd>=18	) SetDlgItemText(IDC_EDIT_R18	,NumberList.GetAt(18));
		if (iRStart<=19&&	iREnd>=19	) SetDlgItemText(IDC_EDIT_R19	,NumberList.GetAt(19));
		if (iRStart<=20&&	iREnd>=20	) SetDlgItemText(IDC_EDIT_R20	,NumberList.GetAt(20));
		if (iRStart<=21&&	iREnd>=21	) SetDlgItemText(IDC_EDIT_R21	,NumberList.GetAt(21));
		if (iRStart<=22&&	iREnd>=22	) SetDlgItemText(IDC_EDIT_R22	,NumberList.GetAt(22));
		if (iRStart<=23&&	iREnd>=23	) SetDlgItemText(IDC_EDIT_R23	,NumberList.GetAt(23));
		if (iRStart<=24&&	iREnd>=24	) SetDlgItemText(IDC_EDIT_R24	,NumberList.GetAt(24));
		if (iRStart<=25&&	iREnd>=25	) SetDlgItemText(IDC_EDIT_R25	,NumberList.GetAt(25));
		if (iRStart<=26&&	iREnd>=26	) SetDlgItemText(IDC_EDIT_R26	,NumberList.GetAt(26));
		if (iRStart<=27&&	iREnd>=27	) SetDlgItemText(IDC_EDIT_R27	,NumberList.GetAt(27));
		if (iRStart<=28&&	iREnd>=28	) SetDlgItemText(IDC_EDIT_R28	,NumberList.GetAt(28));
		if (iRStart<=29&&	iREnd>=29	) SetDlgItemText(IDC_EDIT_R29	,NumberList.GetAt(29));
		if (iRStart<=30&&	iREnd>=30	) SetDlgItemText(IDC_EDIT_R30	,NumberList.GetAt(30));
		if (iRStart<=31&&	iREnd>=31	) SetDlgItemText(IDC_EDIT_R31	,NumberList.GetAt(31));
		if (iRStart<=32&&	iREnd>=32	) SetDlgItemText(IDC_EDIT_R32	,NumberList.GetAt(32));
		if (iRStart<=33&&	iREnd>=33	) SetDlgItemText(IDC_EDIT_R33	,NumberList.GetAt(33));
		if (iRStart<=34&&	iREnd>=34	) SetDlgItemText(IDC_EDIT_R34	,NumberList.GetAt(34));
		if (iRStart<=35&&	iREnd>=35	) SetDlgItemText(IDC_EDIT_R35	,NumberList.GetAt(35));
		if (iRStart<=36&&	iREnd>=36	) SetDlgItemText(IDC_EDIT_R36	,NumberList.GetAt(36));
		if (iRStart<=37&&	iREnd>=37	) SetDlgItemText(IDC_EDIT_R37	,NumberList.GetAt(37));
		if (iRStart<=38&&	iREnd>=38	) SetDlgItemText(IDC_EDIT_R38	,NumberList.GetAt(38));
		if (iRStart<=39&&	iREnd>=39	) SetDlgItemText(IDC_EDIT_R39	,NumberList.GetAt(39));
		if (iRStart<=40&&	iREnd>=40	) SetDlgItemText(IDC_EDIT_R40	,NumberList.GetAt(40));
		if (iRStart<=41&&	iREnd>=41	) SetDlgItemText(IDC_EDIT_R41	,NumberList.GetAt(41));
		if (iRStart<=42&&	iREnd>=42	) SetDlgItemText(IDC_EDIT_R42	,NumberList.GetAt(42));
		if (iRStart<=43&&	iREnd>=43	) SetDlgItemText(IDC_EDIT_R43	,NumberList.GetAt(43));
		if (iRStart<=44&&	iREnd>=44	) SetDlgItemText(IDC_EDIT_R44	,NumberList.GetAt(44));
		if (iRStart<=45&&	iREnd>=45	) SetDlgItemText(IDC_EDIT_R45	,NumberList.GetAt(45));
		if (iRStart<=46&&	iREnd>=46	) SetDlgItemText(IDC_EDIT_R46	,NumberList.GetAt(46));
		if (iRStart<=47&&	iREnd>=47	) SetDlgItemText(IDC_EDIT_R47	,NumberList.GetAt(47));
		if (iRStart<=48&&	iREnd>=48	) SetDlgItemText(IDC_EDIT_R48	,NumberList.GetAt(48));
		if (iRStart<=49&&	iREnd>=49	) SetDlgItemText(IDC_EDIT_R49	,NumberList.GetAt(49));
		if (iRStart<=50&&	iREnd>=50	) SetDlgItemText(IDC_EDIT_R50	,NumberList.GetAt(50));
		if (iRStart<=51&&	iREnd>=51	) SetDlgItemText(IDC_EDIT_R51	,NumberList.GetAt(51));
		if (iRStart<=52&&	iREnd>=52	) SetDlgItemText(IDC_EDIT_R52	,NumberList.GetAt(52));
		if (iRStart<=53&&	iREnd>=53	) SetDlgItemText(IDC_EDIT_R53	,NumberList.GetAt(53));
		if (iRStart<=54&&	iREnd>=54	) SetDlgItemText(IDC_EDIT_R54	,NumberList.GetAt(54));
		if (iRStart<=55&&	iREnd>=55	) SetDlgItemText(IDC_EDIT_R55	,NumberList.GetAt(55));
		if (iRStart<=56&&	iREnd>=56	) SetDlgItemText(IDC_EDIT_R56	,NumberList.GetAt(56));
		if (iRStart<=57&&	iREnd>=57	) SetDlgItemText(IDC_EDIT_R57	,NumberList.GetAt(57));
		if (iRStart<=58&&	iREnd>=58	) SetDlgItemText(IDC_EDIT_R58	,NumberList.GetAt(58));
		if (iRStart<=59&&	iREnd>=59	) SetDlgItemText(IDC_EDIT_R59	,NumberList.GetAt(59));
		if (iRStart<=60&&	iREnd>=60	) SetDlgItemText(IDC_EDIT_R60	,NumberList.GetAt(60));
		if (iRStart<=61&&	iREnd>=61	) SetDlgItemText(IDC_EDIT_R61	,NumberList.GetAt(61));
		if (iRStart<=62&&	iREnd>=62	) SetDlgItemText(IDC_EDIT_R62	,NumberList.GetAt(62));
		if (iRStart<=63&&	iREnd>=63	) SetDlgItemText(IDC_EDIT_R63	,NumberList.GetAt(63));
		if (iRStart<=64&&	iREnd>=64	) SetDlgItemText(IDC_EDIT_R64	,NumberList.GetAt(64));
		if (iRStart<=65&&	iREnd>=65	) SetDlgItemText(IDC_EDIT_R65	,NumberList.GetAt(65));
		if (iRStart<=66&&	iREnd>=66	) SetDlgItemText(IDC_EDIT_R66	,NumberList.GetAt(66));
		if (iRStart<=67&&	iREnd>=67	) SetDlgItemText(IDC_EDIT_R67	,NumberList.GetAt(67));
		if (iRStart<=68&&	iREnd>=68	) SetDlgItemText(IDC_EDIT_R68	,NumberList.GetAt(68));
		if (iRStart<=69&&	iREnd>=69	) SetDlgItemText(IDC_EDIT_R69	,NumberList.GetAt(69));
		if (iRStart<=70&&	iREnd>=70	) SetDlgItemText(IDC_EDIT_R70	,NumberList.GetAt(70));
		if (iRStart<=71&&	iREnd>=71	) SetDlgItemText(IDC_EDIT_R71	,NumberList.GetAt(71));
		if (iRStart<=72&&	iREnd>=72	) SetDlgItemText(IDC_EDIT_R72	,NumberList.GetAt(72));
		if (iRStart<=73&&	iREnd>=73	) SetDlgItemText(IDC_EDIT_R73	,NumberList.GetAt(73));
		if (iRStart<=74&&	iREnd>=74	) SetDlgItemText(IDC_EDIT_R74	,NumberList.GetAt(74));
		if (iRStart<=75&&	iREnd>=75	) SetDlgItemText(IDC_EDIT_R75	,NumberList.GetAt(75));
		if (iRStart<=76&&	iREnd>=76	) SetDlgItemText(IDC_EDIT_R76	,NumberList.GetAt(76));
		if (iRStart<=77&&	iREnd>=77	) SetDlgItemText(IDC_EDIT_R77	,NumberList.GetAt(77));
		if (iRStart<=78&&	iREnd>=78	) SetDlgItemText(IDC_EDIT_R78	,NumberList.GetAt(78));
		if (iRStart<=79&&	iREnd>=79	) SetDlgItemText(IDC_EDIT_R79	,NumberList.GetAt(79));
		if (iRStart<=80&&	iREnd>=80	) SetDlgItemText(IDC_EDIT_R80	,NumberList.GetAt(80));
		if (iRStart<=81&&	iREnd>=81	) SetDlgItemText(IDC_EDIT_R81	,NumberList.GetAt(81));
		if (iRStart<=82&&	iREnd>=82	) SetDlgItemText(IDC_EDIT_R82	,NumberList.GetAt(82));
		if (iRStart<=83&&	iREnd>=83	) SetDlgItemText(IDC_EDIT_R83	,NumberList.GetAt(83));
		if (iRStart<=84&&	iREnd>=84	) SetDlgItemText(IDC_EDIT_R84	,NumberList.GetAt(84));
		if (iRStart<=85&&	iREnd>=85	) SetDlgItemText(IDC_EDIT_R85	,NumberList.GetAt(85));
		if (iRStart<=86&&	iREnd>=86	) SetDlgItemText(IDC_EDIT_R86	,NumberList.GetAt(86));
		if (iRStart<=87&&	iREnd>=87	) SetDlgItemText(IDC_EDIT_R87	,NumberList.GetAt(87));
		if (iRStart<=88&&	iREnd>=88	) SetDlgItemText(IDC_EDIT_R88	,NumberList.GetAt(88));
		if (iRStart<=89&&	iREnd>=89	) SetDlgItemText(IDC_EDIT_R89	,NumberList.GetAt(89));
		if (iRStart<=90&&	iREnd>=90	) SetDlgItemText(IDC_EDIT_R90	,NumberList.GetAt(90));
		if (iRStart<=91&&	iREnd>=91	) SetDlgItemText(IDC_EDIT_R91	,NumberList.GetAt(91));
		if (iRStart<=92&&	iREnd>=92	) SetDlgItemText(IDC_EDIT_R92	,NumberList.GetAt(92));
		if (iRStart<=93&&	iREnd>=93	) SetDlgItemText(IDC_EDIT_R93	,NumberList.GetAt(93));
		if (iRStart<=94&&	iREnd>=94	) SetDlgItemText(IDC_EDIT_R94	,NumberList.GetAt(94));
		if (iRStart<=95&&	iREnd>=95	) SetDlgItemText(IDC_EDIT_R95	,NumberList.GetAt(95));
		if (iRStart<=96&&	iREnd>=96	) SetDlgItemText(IDC_EDIT_R96	,NumberList.GetAt(96));
		if (iRStart<=97&&	iREnd>=97	) SetDlgItemText(IDC_EDIT_R97	,NumberList.GetAt(97));
		if (iRStart<=98&&	iREnd>=98	) SetDlgItemText(IDC_EDIT_R98	,NumberList.GetAt(98));
		if (iRStart<=99&&	iREnd>=99	) SetDlgItemText(IDC_EDIT_R99	,NumberList.GetAt(99));
		if (iRStart<=100&&	iREnd>=100	) SetDlgItemText(IDC_EDIT_R100	,NumberList.GetAt(100));
		////////一定先END再Start才行//////////////////////
		m_Edit_BE.SetWindowText(ValueList.GetAt(iRSPosition+(iREnd-iRStart+1)+1+2));
		Sleep(100);
		m_Edit_BS.SetWindowText(ValueList.GetAt(iRSPosition+(iREnd-iRStart+1)+2));
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
		if (iBStart<=1&&	iBEnd>=1	) SetDlgItemText(IDC_EDIT_C1	,NumberList.GetAt(1));
		if (iBStart<=2&&	iBEnd>=2	) SetDlgItemText(IDC_EDIT_C2	,NumberList.GetAt(2));
		if (iBStart<=3&&	iBEnd>=3	) SetDlgItemText(IDC_EDIT_C3	,NumberList.GetAt(3));
		if (iBStart<=4&&	iBEnd>=4	) SetDlgItemText(IDC_EDIT_C4	,NumberList.GetAt(4));
		if (iBStart<=5&&	iBEnd>=5	) SetDlgItemText(IDC_EDIT_C5	,NumberList.GetAt(5));
		if (iBStart<=6&&	iBEnd>=6	) SetDlgItemText(IDC_EDIT_C6	,NumberList.GetAt(6));
		if (iBStart<=7&&	iBEnd>=7	) SetDlgItemText(IDC_EDIT_C7	,NumberList.GetAt(7));
		if (iBStart<=8&&	iBEnd>=8	) SetDlgItemText(IDC_EDIT_C8	,NumberList.GetAt(8));
		if (iBStart<=9&&	iBEnd>=9	) SetDlgItemText(IDC_EDIT_C9	,NumberList.GetAt(9));
		if (iBStart<=10&&	iBEnd>=10	) SetDlgItemText(IDC_EDIT_C10	,NumberList.GetAt(10));
		if (iBStart<=11&&	iBEnd>=11	) SetDlgItemText(IDC_EDIT_C11	,NumberList.GetAt(11));
		if (iBStart<=12&&	iBEnd>=12	) SetDlgItemText(IDC_EDIT_C12	,NumberList.GetAt(12));
		if (iBStart<=13&&	iBEnd>=13	) SetDlgItemText(IDC_EDIT_C13	,NumberList.GetAt(13));
		if (iBStart<=14&&	iBEnd>=14	) SetDlgItemText(IDC_EDIT_C14	,NumberList.GetAt(14));
		if (iBStart<=15&&	iBEnd>=15	) SetDlgItemText(IDC_EDIT_C15	,NumberList.GetAt(15));
		if (iBStart<=16&&	iBEnd>=16	) SetDlgItemText(IDC_EDIT_C16	,NumberList.GetAt(16));
		if (iBStart<=17&&	iBEnd>=17	) SetDlgItemText(IDC_EDIT_C17	,NumberList.GetAt(17));
		if (iBStart<=18&&	iBEnd>=18	) SetDlgItemText(IDC_EDIT_C18	,NumberList.GetAt(18));
		if (iBStart<=19&&	iBEnd>=19	) SetDlgItemText(IDC_EDIT_C19	,NumberList.GetAt(19));
		if (iBStart<=20&&	iBEnd>=20	) SetDlgItemText(IDC_EDIT_C20	,NumberList.GetAt(20));
		////////////////////////获取Foot部分///////////
		int iSize=0;
		iSize=ValueList.GetSize()-1;
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

void ASrdc_Dlg::OnCbnSelchangeComboM()
{
GetCMD();
}


void ASrdc_Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void ASrdc_Dlg::OnEnChangeEditHs()
{
	CString sStart="",sEnd="";
	m_Edit_HS.GetWindowText(sStart);
	m_Edit_HE.GetWindowText(sEnd);
	if (atoi(sStart)>atoi(sEnd))
	{
		m_Edit_HE.SetWindowText(sStart);
	}
    GetCMD();
}

void ASrdc_Dlg::OnEnChangeEditHe()
{
	CString sStart="",sEnd="";
	m_Edit_HS.GetWindowText(sStart);
	m_Edit_HE.GetWindowText(sEnd);
	if (atoi(sStart)>atoi(sEnd))
	{
		m_Edit_HS.SetWindowText(sEnd);
	}
	GetCMD();
}

void ASrdc_Dlg::OnCbnSelchangeComboOi()
{
   GetCMD();
}


void ASrdc_Dlg::OnBnClickedCheckOuts()
{
   GetCMD();
}


void ASrdc_Dlg::OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_D.GetPos();
	m_Spin_D.SetPos(iTemp);
	m_Edit_D.GetWindowText(strValue);  
	*pResult = 0;
}


void ASrdc_Dlg::OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_TT.GetPos();
	m_Spin_TT.SetPos(iTemp);
	m_Edit_TT.GetWindowText(strValue);  
	*pResult = 0;
}


void ASrdc_Dlg::OnEnChangeEditD()
{
   GetCMD();
}


void ASrdc_Dlg::OnEnChangeEditTt()
{
   GetCMD();
}


void ASrdc_Dlg::OnDeltaposSpinMs(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_MS.GetPos();
	m_Spin_MS.SetPos(iTemp);
	m_Edit_HS.GetWindowText(strValue);  
	*pResult = 0;
}


void ASrdc_Dlg::OnDeltaposSpinMe(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_ME.GetPos();
	m_Spin_ME.SetPos(iTemp);
	m_Edit_HE.GetWindowText(strValue);  
	*pResult = 0;
}

void ASrdc_Dlg::OnEnChangeEditRe()
{
	CString sStart="",sEnd="";
	m_Edit_RS.GetWindowText(sStart);
	m_Edit_RE.GetWindowText(sEnd);
	if (atoi(sStart)>atoi(sEnd))
	{
		m_Edit_RS.SetWindowText(sEnd);
	}
	GetCMD();
}


void ASrdc_Dlg::OnEnChangeEditRs()
{
	CString sStart="",sEnd="";
	m_Edit_RS.GetWindowText(sStart);
	m_Edit_RE.GetWindowText(sEnd);
	if (atoi(sStart)>atoi(sEnd))
	{
		m_Edit_RE.SetWindowText(sStart);
	}
	GetCMD();
}


void ASrdc_Dlg::OnDeltaposSpinRs(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_RS.GetPos();
	m_Spin_RS.SetPos(iTemp);
	m_Edit_RS.GetWindowText(strValue);  
	*pResult = 0;
}


void ASrdc_Dlg::OnDeltaposSpinRe(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_RE.GetPos();
	m_Spin_RE.SetPos(iTemp);
	m_Edit_RE.GetWindowText(strValue);  
	*pResult = 0;
}


void ASrdc_Dlg::OnDeltaposSpinBs(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_BS.GetPos();
	m_Spin_BS.SetPos(iTemp);
	m_Edit_BS.GetWindowText(strValue);  
	*pResult = 0;
}


void ASrdc_Dlg::OnDeltaposSpinBe(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_BE.GetPos();
	m_Spin_BE.SetPos(iTemp);
	m_Edit_BE.GetWindowText(strValue);  
	*pResult = 0;
}


void ASrdc_Dlg::OnEnChangeEditBs()
{
	CString sStart="",sEnd="";
	m_Edit_BS.GetWindowText(sStart);
	m_Edit_BE.GetWindowText(sEnd);
	if (atoi(sStart)>atoi(sEnd))
	{
		m_Edit_BE.SetWindowText(sStart);
	}
	GetCMD();
}


void ASrdc_Dlg::OnEnChangeEditBe()
{
	CString sStart="",sEnd="";
	m_Edit_BS.GetWindowText(sStart);
	m_Edit_BE.GetWindowText(sEnd);
	if (atoi(sStart)>atoi(sEnd))
	{
		m_Edit_BS.SetWindowText(sEnd);
	}
	GetCMD();
}


void ASrdc_Dlg::OnEnChangeEditH1()
{
	GetCMD();
}


void ASrdc_Dlg::OnEnChangeEditH2()
{
	GetCMD();
}


void ASrdc_Dlg::OnEnChangeEditH3()
{
	GetCMD();
}


void ASrdc_Dlg::OnEnChangeEditH4()
{
	GetCMD();
}


void ASrdc_Dlg::OnEnChangeEditH5()
{
	GetCMD();
}


void ASrdc_Dlg::OnEnChangeEditH6()
{
	GetCMD();
}


void ASrdc_Dlg::OnEnChangeEditH7()
{
	GetCMD();
}


void ASrdc_Dlg::OnEnChangeEditH8()
{
	GetCMD();
}


void ASrdc_Dlg::OnEnChangeEditH9()
{
	GetCMD();
}


void ASrdc_Dlg::OnEnChangeEditH10()
{
	GetCMD();
}


void ASrdc_Dlg::OnEnChangeEditR1() 
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR10()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR11()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR12()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR13()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR14()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR15()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR16()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR17()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR18()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR19()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR20()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR21()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR22()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR23()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR24()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR25()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR26()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR27()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR28()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR29()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR30()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR31()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR32()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR33()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR34()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR35()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR36()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR37()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR38()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR39()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR40()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR41()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR42()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR43()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR44()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR45()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR46()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR47()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR48()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR49()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR50()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR51()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR52()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR53()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR54()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR55()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR56()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR57()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR58()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR59()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR60()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR61()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR62()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR63()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR64()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR65()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR66()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR67()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR68()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR69()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR70()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR71()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR72()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR73()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR74()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR75()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR76()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR77()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR78()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR79()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR80()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR81()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR82()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR83()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR84()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR85()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR86()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR87()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR88()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR89()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR90()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR91()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR92()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR93()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR94()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR95()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR96()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR97()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR98()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR99()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditR100()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC11()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC13()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC15()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC17()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC19()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC10()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC12()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC14()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC16()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC18()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::OnEnChangeEditC20()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
		GetCMD();
	// TODO:  在此添加控件通知处理程序代码
}


void ASrdc_Dlg::ReSize(UINT nType, int cx, int cy)
{
	if (m_listRect.GetCount() > 0)  
	{  
		CRect dlgNow;  
		lpCConfigToolDlg->m_Table.GetWindowRect(&dlgNow);  
		//GetWindowRect(&dlgNow);  
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
}

void ASrdc_Dlg::ChangeSize(UINT nID, int x, int y)  //nID为控件ID，x,y分别为对话框的当前长和宽
{
	CWnd *pWnd;
	pWnd=GetDlgItem(nID); 
	if(pWnd!=NULL)     //判断是否为空，因为在窗口创建的时候也会调用OnSize函数，但是此时各个控件还没有创建，Pwnd为空
	{
		CRect rec; 
		pWnd->GetWindowRect(&rec);  //获取控件变化前的大小
		ScreenToClient(&rec);   //将控件大小装换位在对话框中的区域坐标
		rec.left=rec.left*x/m_rect_tab.Width();  //按照比例调整空间的新位置
		rec.top=rec.top*y/m_rect_tab.Height();
		rec.bottom=rec.bottom*y/m_rect_tab.Height();
		rec.right=rec.right*x/m_rect_tab.Width();

		if(pWnd->IsKindOf(RUNTIME_CLASS(CComboBox))) rec.bottom = rec.bottom+100;//判断是否为ComboBox类型

		pWnd->MoveWindow(rec);   //伸缩控件
	}
}


void ASrdc_Dlg::OnEnChangeEditGtrmd()
{
	CString sTemp="";
	m_Edit_GTRMD.GetWindowText(sTemp);
	if (sTemp!=stu_ConfigCMD.tdWriteCmds[GTRMD].sCmdstr) stu_ConfigCMD.tdWriteCmds[GTRMD].sCmdstr=sTemp;
}
