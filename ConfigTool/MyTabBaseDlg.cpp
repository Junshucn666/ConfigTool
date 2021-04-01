// MyTabBaseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ConfigToolDlg.h"
#include "MyTabBaseDlg.h"
#include "afxdialogex.h"
#include "COMMON.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern ConfigCMD stu_ConfigCMD;
extern CMYWORK	m_MYWORK;
extern BOOL MYTHREAD_WORK;
extern HANDLE g_hEvent;
// CMyTabBaseDlg �Ի���
IMPLEMENT_DYNAMIC(CMyTabBaseDlg, CDialogEx)

CMyTabBaseDlg::CMyTabBaseDlg(UINT nIDTemplate,CWnd* pParent /*=NULL*/)
	: CDialogEx(nIDTemplate, pParent)
{

}

CMyTabBaseDlg::~CMyTabBaseDlg()
{
}

void CMyTabBaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_GTCMD, m_Edit_GTCMD);
	DDX_Control(pDX, IDC_BUTTON_Read, m_Button_Read);
	DDX_Control(pDX, IDC_BUTTON_Send, m_Button_Send);
}


BEGIN_MESSAGE_MAP(CMyTabBaseDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_GTCMD, &CMyTabBaseDlg::OnEnChangeEditGtcmd)
	ON_BN_CLICKED(IDC_BUTTON_Send, &CMyTabBaseDlg::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDC_BUTTON_Read, &CMyTabBaseDlg::OnBnClickedButtonRead)
END_MESSAGE_MAP()


// CMyTabBaseDlg ��Ϣ�������


BOOL CMyTabBaseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CWnd *pWnd;
	pWnd = GetDlgItem( IDC_EDIT_GTCMD );
	pWnd->SetWindowPos( NULL,13,499,542,26,SWP_NOZORDER );
	pWnd = GetDlgItem( IDC_BUTTON_Read );    
	pWnd->SetWindowPos( NULL,565,493,75,33,SWP_NOZORDER );   
	pWnd = GetDlgItem( IDC_BUTTON_Send );    
	pWnd->SetWindowPos( NULL,647,493,75,33,SWP_NOZORDER );

	FButton_startfont.CreatePointFont(86,"Verdana");
    m_Button_Read.SetFont(&FButton_startfont,1);
	m_Button_Send.SetFont(&FButton_startfont,1);
	m_Button_Read.SetFaceColor(RGB(176,196,222),1);
	m_Button_Send.SetFaceColor(RGB(176,196,222),1);

	SetBackgroundColor(RGB(176,196,222));
	/////////////////////////////
	CRect rect;   
	lpCConfigToolDlg->m_Table.GetWindowRect(&rect);  
	m_listRect.AddTail(rect);//�Ի��������  
	CWnd* pReWnd = GetWindow(GW_CHILD);//��ȡ�Ӵ���  
	while(pReWnd)  
	{  
		pReWnd->GetWindowRect(rect);//�Ӵ��������  
		m_listRect.AddTail(rect);           //CList<CRect,CRect> m_listRect��Ա����  
		pReWnd = pReWnd->GetNextWindow();//ȡ��һ���Ӵ���  
	}  
	///////////////////////////////////////////
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CMyTabBaseDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	//AfxMessageBox("Base");
	//CDialogEx::OnOK();
}


static UINT ThreadManager_READ_THREAD(LPVOID LPARAM)//�߳�
{
	ThreadData* stu_Threaddata;
	stu_Threaddata=(ThreadData*)LPARAM;
	///////////////////////////////
	g_hEvent=CreateEvent(NULL,FALSE,FALSE,NULL);//�Զ����÷�ʽ
	SetEvent(g_hEvent);//�����¼���Ч���ȴ����߳�Waitfor
	////////////////////////
	m_MYWORK.CmdSend_Thread_Start(stu_Threaddata);
	////////////////�ȴ��߳̽��////////////
	Sleep(3000);//�ó�CPU,�����߳�Waitfor
	WaitForSingleObject(g_hEvent,INFINITE);//�ȴ����̵߳�SetEvent
	SetEvent(g_hEvent);
	CloseHandle(g_hEvent);
	MYTHREAD_WORK=FALSE;//�ͷŰ�ť
	//////////////////////////////////
	stu_Threaddata->lpMyTabBaseDlg->ReadResCheck(stu_Threaddata->sReturn);
	return 0;
}

BOOL CMyTabBaseDlg::ReadResCheck(CString sRes)
{
	if (sRes.Find(stu_ConfigCMD.tdReadCmds[m_iWhoamI].sName)==-1) return 0;
	else {
		stu_ConfigCMD.tdReadCmds[m_iWhoamI].sReturn=sRes;
		UpdataPage(stu_ConfigCMD.tdReadCmds[m_iWhoamI].sReturn);
		return 0;
	}
}

static UINT ThreadManager_SEND_THREAD(LPVOID LPARAM)//�߳�
{
	ThreadData* stu_Threaddata;
	stu_Threaddata=(ThreadData*)LPARAM;
	///////////////////////////////
	g_hEvent=CreateEvent(NULL,FALSE,FALSE,NULL);//�Զ����÷�ʽ
	SetEvent(g_hEvent);//�����¼���Ч���ȴ����߳�Waitfor
	////////////////////////
	m_MYWORK.CmdSend_Thread_Start(stu_Threaddata);
	////////////////�ȴ��߳̽��////////////
	Sleep(3000);//�ó�CPU,�����߳�Waitfor
	WaitForSingleObject(g_hEvent,INFINITE);//�ȴ����̵߳�SetEvent
	SetEvent(g_hEvent);
	CloseHandle(g_hEvent);
	//////////////////////////////////
	stu_Threaddata->lpMyTabBaseDlg->WriteResSave(stu_Threaddata->sReturn);
	MYTHREAD_WORK=FALSE;//�ͷŰ�ť
	return 0;
}

BOOL CMyTabBaseDlg::WriteResSave(CString sRes)
{
	stu_ConfigCMD.tdWriteCmds[m_iWhoamI].sReturn= sRes;
	return 0;
	
}

void CMyTabBaseDlg::OnBnClickedButtonRead()
{
	if (!MYTHREAD_WORK)
	{
		MYTHREAD_WORK=TRUE;
		ThreadData *stu_Threaddata =new ThreadData;
		stu_Threaddata->sCmdstr=stu_ConfigCMD.tdReadCmds[m_iWhoamI].sCmdstr;
		stu_Threaddata->sReturn="";
		stu_Threaddata->lpMyTabBaseDlg=m_lpMyTabBaseDlg;
		AfxBeginThread(ThreadManager_READ_THREAD,stu_Threaddata,THREAD_PRIORITY_NORMAL,0,0,NULL);	
	}
	else
	{
		AfxMessageBox("ConfigTool IS RUNNING");
	}
}

BOOL CMyTabBaseDlg::UpdataPage(CString sStr)
{   //λ��iPos�Ǵ�0��ʼ��
	AfxMessageBox("I am Base");
	return TRUE;
}


void CMyTabBaseDlg::OnBnClickedButtonSend()
{
	DoSendWork();
}

void CMyTabBaseDlg::DoSendWork()
{
	if (!MYTHREAD_WORK)
	{
		MYTHREAD_WORK=TRUE;
		CString sCMD="";
		m_Edit_GTCMD.GetWindowText(sCMD);
		ThreadData *stu_Threaddata =new ThreadData;
		stu_Threaddata->sCmdstr.Format("AT+CONFIG=%s",sCMD);
		stu_Threaddata->sReturn="";
		stu_Threaddata->lpMyTabBaseDlg=m_lpMyTabBaseDlg;
		AfxBeginThread(ThreadManager_SEND_THREAD,stu_Threaddata,THREAD_PRIORITY_NORMAL,0,0,NULL);
	}
	else
	{
		AfxMessageBox("ConfigTool IS RUNNING");
	}
}

void CMyTabBaseDlg::OnEnChangeEditGtcmd()
{
		CString sTemp="";
		m_Edit_GTCMD.GetWindowText(sTemp);
		if (sTemp!=stu_ConfigCMD.tdWriteCmds[m_iWhoamI].sCmdstr) stu_ConfigCMD.tdWriteCmds[m_iWhoamI].sCmdstr=sTemp;
}


void CMyTabBaseDlg::ReSize(UINT nType, int cx, int cy)
{
	if (m_listRect.GetCount() > 0)  
	{  
		CRect dlgNow;  
		lpCConfigToolDlg->m_Table.GetWindowRect(&dlgNow);  
		//GetWindowRect(&dlgNow);  
		POSITION pos = m_listRect.GetHeadPosition();//��һ��������ǶԻ����Rect  

		CRect dlgSaved;  
		dlgSaved = m_listRect.GetNext(pos);  
		ScreenToClient(dlgNow);  

		double x = dlgNow.Width() * 1.0 / dlgSaved.Width();//���ݵ�ǰ��֮ǰ����ĶԻ���Ŀ�������  
		double y = dlgNow.Height()  *1.0/ dlgSaved.Height();  
		ClientToScreen(dlgNow);  

		CRect childSaved;  

		CWnd* pWnd = GetWindow(GW_CHILD);  
		while(pWnd)  
		{  
			childSaved = m_listRect.GetNext(pos);//���λ�ȡ�Ӵ����Rect  
			childSaved.left = (long)(dlgNow.left + (childSaved.left - dlgSaved.left)*x);//���ݱ��������ؼ��������Ҿ���Ի���ľ���  
			childSaved.right = (long)(dlgNow.right + (childSaved.right - dlgSaved.right)*x);  
			childSaved.top = (long)(dlgNow.top + (childSaved.top - dlgSaved.top)*y);  
			childSaved.bottom = (long)(dlgNow.bottom + (childSaved.bottom - dlgSaved.bottom)*y);  
			if(pWnd->IsKindOf(RUNTIME_CLASS(CComboBox))) childSaved.bottom = childSaved.bottom+100;//�ж��Ƿ�ΪComboBox����
			ScreenToClient(childSaved);  
			pWnd->MoveWindow(childSaved);  
			pWnd = pWnd->GetNextWindow();  
		}  
	}
}

