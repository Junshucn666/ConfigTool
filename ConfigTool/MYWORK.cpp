#include "StdAfx.h"
#include "MYWORK.h"
#include "ConfigTool.h"
#include "ConfigToolDlg.h"
#include "PowerControl.h"
#include "PopMessage_Dlg.h"

BOOL THREAD_WORK=FALSE;
CMYWORK* LPMYWORK;
PopMessage_Dlg m_PopMessageDlg;

extern CConfigToolDlg* lpCConfigToolDlg;
extern CONFIG stu_CONFIG;
extern TESTLIST_Dlg m_TESTLIST_Dlg;
extern DEBUGLOG_Dlg m_DEBUGLOG_Dlg;
extern AllTestItem	 m_TestItem;

extern	SCbsi_Dlg	*lpSCbsi_Dlg	;
extern	SCbsri_Dlg	*lpSCbsri_Dlg	;
extern	SCqss_Dlg	*lpSCqss_Dlg	;
extern	DCgc_Dlg	*lpDCgc_Dlg	;
extern	DCap_Dlg	*lpDCap_Dlg	;
extern	DCspw_Dlg	*lpDCspw_Dlg	;
extern	DCowh_Dlg	*lpDCowh_Dlg	;
extern	DCta_Dlg	*lpDCta_Dlg	;
extern	DCpsdls_Dlg	*lpDCpsdls_Dlg	;
extern	DChrm_Dlg	*lpDChrm_Dlg	;
extern	DCpcs_Dlg	*lpDCpcs_Dlg	;
extern	PRRfri_Dlg	*lpPRRfri_Dlg	;
extern	PRRfcofri_Dlg	*lpPRRfcofri_Dlg	;
extern	ASgc_Dlg	*lpASgc_Dlg	;
extern	AStac_Dlg	*lpAStac_Dlg	;
extern	ASsa_Dlg	*lpASsa_Dlg	;
extern	ASsosa_Dlg	*lpASsosa_Dlg	;
extern	ASeid_Dlg	*lpASeid_Dlg	;
extern	AShbm_Dlg	*lpAShbm_Dlg	;
extern	ASssr_Dlg	*lpASssr_Dlg	;
extern	ASbad_Dlg	*lpASbad_Dlg	;
extern	ASosa_Dlg	*lpASosa_Dlg	;
extern	ASpg_Dlg	*lpASpg_Dlg	;
extern	ASrdc_Dlgnew*	lpASrdc_Dlgnew;
extern	ASsadr_Dlg	*lpASsadr_Dlg	;
extern	ASser_Dlg	*lpASser_Dlg	;
extern	AScd_Dlg	*lpAScd_Dlg	;
extern	IAdops_Dlg	*lpIAdops_Dlg	;
extern	IAepsm_Dlg	*lpIAepsm_Dlg	;
extern	IAdips_Dlg	*lpIAdips_Dlg	;
extern	IAips_Dlg	*lpIAips_Dlg	;
extern	IDSvims_Dlg	*lpIDSvims_Dlg	;
extern	IDSidbvs_Dlg	*lpIDSidbvs_Dlg	;
extern	IDSavis_Dlg	*lpIDSavis_Dlg	;
extern	OSrto_Dlg	*lpOSrto_Dlg	;
extern	OShmc_Dlg	*lpOShmc_Dlg	;
extern	OSwl_Dlg	*lpOSwl_Dlg	;
extern	OSglsc_Dlg	*lpOSglsc_Dlg	;
extern	OSucota_Dlg	*lpOSucota_Dlg	;
extern	OScss_Dlg	*lpOScss_Dlg	;
extern	OSudf_Dlg	*lpOSudf_Dlg	;
extern	OSgs_Dlg	*lpOSgs_Dlg	;
extern	OSer_Dlg	*lpOSer_Dlg	;


HANDLE WorkerThread = 0;

ATCMD m_ATCMD;
ScanPort m_struct_ScanPort;
HANDLE g_hEvent;
BOOL THREAD_POPUPWINDOW=FALSE;
extern ConfigCMD stu_ConfigCMD;

CMYWORK::CMYWORK(void)
{
}

CMYWORK::~CMYWORK(void)
{
}

DWORD WINAPI TestExecutionEngineThread( LPVOID pParam );

DWORD WINAPI TestExecutionEngineThread( LPVOID pParam )
{
	WaitForSingleObject(g_hEvent,INFINITE);//自动重置方式
	int RES=SUCCESS;
	//清零
	float fProgress=0;//进度条清零
	lpCConfigToolDlg->ShowBmp(RUN);
	lpCConfigToolDlg->m_EDIT_Log.SetWindowText("");
	//参数获取td
	ThreadData* td = (ThreadData*) pParam; 
	//读取工具配置信息
	int iTemp= lpCConfigToolDlg->m_ComboBox_Port.GetCurSel();
	if (iTemp==-1)
	{
		THREAD_WORK=FALSE;
		SetEvent(g_hEvent);//执行完成释放CPU
		AfxMessageBox("Please Select COM Port!");
		lpCConfigToolDlg->ShowBmp(READY);
		return 0;
	}
	CString sTemp="",sPort="";
	lpCConfigToolDlg->m_ComboBox_Port.GetLBText(iTemp,sTemp);
	int index1=sTemp.Find("M")+1;
	sPort=sTemp.Right(sTemp.GetLength()-index1).Trim();
	stu_CONFIG.iPhonePort=atoi(sPort);
	//stu_CONFIG.iPhonePort=lpCConfigToolDlg->m_ComboBox_Port.GetCurSel();
	switch(lpCConfigToolDlg->m_ComboBox_BaudRate.GetCurSel())
	{
	case 0 :		stu_CONFIG.iBaudRate=9600;		break;
	case 1 :		stu_CONFIG.iBaudRate=115200;	break;
	default:stu_CONFIG.iBaudRate=115200; break;
	}
	RES=LPMYWORK->WRITE_EXC(td->sCmdstr,td->sReturn);
	SetEvent(g_hEvent);//执行完成释放CPU
	if (!RES)
	{
		lpCConfigToolDlg->ShowBmp(PASS);
	}
	else
	{
		lpCConfigToolDlg->ShowBmp(FAIL);
	};
	return TRUE;
}

static UINT ETM_THREAD(LPVOID LPARAM)
{
	LPMYWORK->ETM_THREAD_EXE();
	return 0;
}

static UINT REBOOT_THREAD(LPVOID LPARAM)
{
	LPMYWORK->REBOOT_THREAD_EXE();
	return 0;
}

static UINT Button_THREAD(LPVOID LPARAM)
{
	LPMYWORK->Button_THREAD_EXE();
	return 0;
}

static UINT PopupWindow_THREAD(LPVOID LPARAM)
{
	PopupWindowParam* __param=(PopupWindowParam*)LPARAM;
	m_PopMessageDlg.sShowText=__param->lpszText;
	INT_PTR intPtr=IDCANCEL;
	intPtr=m_PopMessageDlg.DoModal();
	if (intPtr!=IDOK)
	{
		//POPWINDOW_STATE=POPWINDOW_CLOSE;
		THREAD_POPUPWINDOW=FALSE;
		//重启
		/*::PostMessage(AfxGetMainWnd()->m_hWnd,WM_SYSCOMMAND,SC_CLOSE,NULL);
		extern CConfigToolApp theApp;

		TCHAR szAppName[MAX_PATH];
		:: GetModuleFileName(theApp.m_hInstance, szAppName, MAX_PATH);

		CString strAppFullName;
		strAppFullName.Format(_T("%s"),szAppName);


		STARTUPINFO StartInfo;
		PROCESS_INFORMATION procStruct;
		memset(&StartInfo, 0, sizeof(STARTUPINFO));
		StartInfo.cb = sizeof(STARTUPINFO);
		::CreateProcess(
			(LPCTSTR)strAppFullName,
			NULL,
			NULL,
			NULL,
			FALSE,
			NORMAL_PRIORITY_CLASS,
			NULL,
			NULL,
			&StartInfo,
			&procStruct);*/
	}
	return 0;
}

void CMYWORK::ETM_THREAD_EXE()
{
	int RES=SUCCESS;
	//清零
	float fProgress=0;//进度条清零
	lpCConfigToolDlg->ShowBmp(RUN);
	//读取工具配置信息
	CString sTemp="",sPort="";
	int iTemp= lpCConfigToolDlg->m_ComboBox_Port.GetCurSel();
	if (iTemp==-1)
	{
		THREAD_WORK=FALSE;
		AfxMessageBox("Please Select COM Port!");
		lpCConfigToolDlg->ShowBmp(READY);
		return;
	}
	lpCConfigToolDlg->m_ComboBox_Port.GetLBText(iTemp,sTemp);
	int index1=sTemp.Find("M")+1;
	sPort=sTemp.Right(sTemp.GetLength()-index1).Trim();
	stu_CONFIG.iPhonePort=atoi(sPort);
	//stu_CONFIG.iPhonePort=lpCConfigToolDlg->m_ComboBox_Port.GetCurSel();
	switch(lpCConfigToolDlg->m_ComboBox_BaudRate.GetCurSel())
	{
	case 0 :		stu_CONFIG.iBaudRate=9600;		break;
	case 1 :		stu_CONFIG.iBaudRate=115200;	break;
	default:stu_CONFIG.iBaudRate=115200; break;
	}
	RES=LPMYWORK->ETM_EXC();
	if (!RES)
	{
		lpCConfigToolDlg->ShowBmp(PASS);
		lpCConfigToolDlg->m_MFCBUTTON_ETM.SetFaceColor(RGB(0,255,0),1);
	}
	else
	{
		lpCConfigToolDlg->ShowBmp(FAIL);
	};
}

void CMYWORK::REBOOT_THREAD_EXE()
{
	int RES=SUCCESS;
	//清零
	float fProgress=0;//进度条清零
	lpCConfigToolDlg->ShowBmp(RUN);
	//读取工具配置信息
	CString sTemp="",sPort="";
	int iTemp= lpCConfigToolDlg->m_ComboBox_Port.GetCurSel();
	if (iTemp==-1)
	{
		THREAD_WORK=FALSE;
		AfxMessageBox("Please Select COM Port!");
		lpCConfigToolDlg->ShowBmp(READY);
		return;
	}
	lpCConfigToolDlg->m_ComboBox_Port.GetLBText(iTemp,sTemp);
	int index1=sTemp.Find("M")+1;
	sPort=sTemp.Right(sTemp.GetLength()-index1).Trim();
	stu_CONFIG.iPhonePort=atoi(sPort);
	//stu_CONFIG.iPhonePort=lpCConfigToolDlg->m_ComboBox_Port.GetCurSel();
	switch(lpCConfigToolDlg->m_ComboBox_BaudRate.GetCurSel())
	{
	case 0 :		stu_CONFIG.iBaudRate=9600;		break;
	case 1 :		stu_CONFIG.iBaudRate=115200;	break;
	default:stu_CONFIG.iBaudRate=115200; break;
	}
	RES=LPMYWORK->REBOOT_EXC();
	if (!RES)
	{
		lpCConfigToolDlg->ShowBmp(PASS);
		lpCConfigToolDlg->m_MFCBUTTON_ETM.SetFaceColor(RGB(176,196,222),1);

	}
	else
	{
		lpCConfigToolDlg->ShowBmp(FAIL);
	};
}

void CMYWORK::Button_THREAD_EXE()
{
	int RES=TEST_FAIL;
	//清零
	float fProgress=0;//进度条清零
	lpCConfigToolDlg->ShowBmp(RUN);
	//读取工具配置信息
	CString sTemp="",sPort="";
	int iTemp= lpCConfigToolDlg->m_ComboBox_Port.GetCurSel();
	if (iTemp==-1)
	{
		THREAD_WORK=FALSE;
		AfxMessageBox("Please Select COM Port!");
		lpCConfigToolDlg->ShowBmp(READY);
		return;
	}
	lpCConfigToolDlg->m_ComboBox_Port.GetLBText(iTemp,sTemp);
	int index1=sTemp.Find("M")+1;
	sPort=sTemp.Right(sTemp.GetLength()-index1).Trim();
	stu_CONFIG.iPhonePort=atoi(sPort);
	//stu_CONFIG.iPhonePort=lpCConfigToolDlg->m_ComboBox_Port.GetCurSel();
	switch(lpCConfigToolDlg->m_ComboBox_BaudRate.GetCurSel())
	{
	case 0 :		stu_CONFIG.iBaudRate=9600;		break;
	case 1 :		stu_CONFIG.iBaudRate=115200;	break;
	default:stu_CONFIG.iBaudRate=115200; break;
	}
	if (ReadFromDevice==stu_CONFIG.iTestSelection) {
		RES=LPMYWORK->READFromDevice_EXC();
	}	
	else if(SendFromDevice==stu_CONFIG.iTestSelection) {
		RES=LPMYWORK->SendFromDevice_EXC();
	}
	else if(SaveFromPage==stu_CONFIG.iTestSelection) {
		RES=LPMYWORK->SaveFromPage_EXC();
	}
	else if(ReadFromFile==stu_CONFIG.iTestSelection) {
		RES=LPMYWORK->ReadFromFile_EXC();
	}

	if (!RES)
	{
		lpCConfigToolDlg->ShowBmp(PASS);
	}
	else
	{
		THREAD_WORK=FALSE;
		lpCConfigToolDlg->ShowBmp(FAIL);
	};
}

void CMYWORK::CmdSend_Thread_Start(ThreadData *stu_ThreadData)
{
	if (!THREAD_WORK)
	{
		THREAD_WORK=TRUE;
		DWORD tid = 0;
		WorkerThread = CreateThread(NULL,0,TestExecutionEngineThread,stu_ThreadData,0,&tid);
	}
	else
	{
		AfxMessageBox("ConfigTool Is Running");
	}
}

void CMYWORK::Thread_EenterTestMode_START()
{
	if (!THREAD_WORK)
	{
		THREAD_WORK=TRUE;
		AfxBeginThread(ETM_THREAD,this,THREAD_PRIORITY_NORMAL,0,0,NULL);	

	}
	else
	{
		AfxMessageBox("ConfigTool Is Running");
	}
}

void CMYWORK::Thread_Reboot_START()
{
	if (!THREAD_WORK)
	{
		THREAD_WORK=TRUE;
		AfxBeginThread(REBOOT_THREAD,this,THREAD_PRIORITY_NORMAL,0,0,NULL);	

	}
	else
	{
		AfxMessageBox("ConfigTool Is Running");
	}
}

void CMYWORK::Button_ThreadStart()
{
	if (!THREAD_WORK)
	{
		THREAD_WORK=TRUE;
		AfxBeginThread(Button_THREAD,this,THREAD_PRIORITY_NORMAL,0,0,NULL);	

	}
	else
	{
		AfxMessageBox("ConfigTool Is Running");
	}
}

void CMYWORK::PopupWindow_START(CString txt)
{
	if (!THREAD_POPUPWINDOW)
	{
		THREAD_POPUPWINDOW=TRUE;
		pPopupWindowParam _param=new PopupWindowParam;
		_param->lpszText=txt;
		AfxBeginThread(PopupWindow_THREAD,_param);	//增加随机数线程
	}
}

void CMYWORK::PopupWindowEnd()
{
	//如果进程存在并且运行状态
	if (THREAD_POPUPWINDOW)
	{
		THREAD_POPUPWINDOW=FALSE;

		m_PopMessageDlg.ExitShow();
		Sleep(100);
	}

}

int CMYWORK::ETM_EXC()
{
	CString sReceiveData="";
	int RES=SUCCESS;
	float fProgress=0;//进度条清零
	const char *cBin = "";
	UINT iValue=0;  
	char c[20]={0}; 
	char b[33]={0};
	char bs[33]={0};
	////////////////////////////////////////////
	if (!CHECK_ATPORT_INSERT_WITH_ONTIME(30,3))
	{
		RES=WRITE_FAIL;
		goto TESTEND;
	}

	if (!ENTER_FACTTEST(sReceiveData))
	{
		RES=WRITE_FAIL;
		goto TESTEND;
	}
TESTEND:	
	THREAD_WORK=FALSE;
	return RES;
}

int CMYWORK::REBOOT_EXC()
{
	CString sReceiveData="";
	int RES=SUCCESS;
	////////////////////////////////////////////
	if (!CHECK_ATPORT_INSERT_WITH_ONTIME(30,3))
	{
		RES=WRITE_FAIL;
		goto TESTEND;
	}
	if (!REBOOT_CHECK(sReceiveData))
	{
		RES=WRITE_FAIL;
		goto TESTEND;
	}
TESTEND:	
	THREAD_WORK=FALSE;
	return RES;
}

int CMYWORK::WRITE_EXC(CString sCmdstr,CString &sReceiveData)
{
	int RES=SUCCESS;
	float fProgress=0;//进度条清零
	const char *cBin = "";
	UINT iValue=0;  
	char c[20]={0}; 
	char b[33]={0};
	char bs[33]={0};
	////////////////////////////////////////////
	if (!CHECK_ATPORT_INSERT_WITH_ONTIME(30,3))
	{
		RES=WRITE_FAIL;
		goto TESTEND;
	}
	if (!TEST_AT(sCmdstr,sReceiveData))
	{
		RES=WRITE_FAIL;
		goto TESTEND;
	}
	
TESTEND:	
	THREAD_WORK=FALSE;
	return RES;
}

int CMYWORK::READFromDevice_EXC()
{
	CString sReceiveData="";
	int RES=SUCCESS;
	////////////////////////////////////////////
	if (!CHECK_ATPORT_INSERT_WITH_ONTIME(30,3))
	{
		RES=WRITE_FAIL;
		goto TESTEND;
	}
	for (int i=0;i<43;i++)
	{
		if (!TEST_AT(stu_ConfigCMD.tdReadCmds[i].sCmdstr,stu_ConfigCMD.tdReadCmds[i].sReturn))
		{
			RES=WRITE_FAIL;
			goto TESTEND;
		}
	}
	try
	{
		if (stu_ConfigCMD.tdReadCmds[	GTBSI	].sReturn.Find("GTBSI")==-1) RES=WRITE_FAIL;else 	lpSCbsi_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTBSI	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTSRI	].sReturn.Find("GTSRI")==-1) RES=WRITE_FAIL;else 	lpSCbsri_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTSRI	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTQSS	].sReturn.Find("GTQSS")==-1) RES=WRITE_FAIL;else	lpSCqss_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTQSS	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTCFG	].sReturn.Find("GTCFG")==-1) RES=WRITE_FAIL;else	lpDCgc_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTCFG	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTPIN	].sReturn.Find("GTPIN")==-1) RES=WRITE_FAIL;else	lpDCap_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTPIN	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTDOG	].sReturn.Find("GTDOG")==-1) RES=WRITE_FAIL;else	lpDCspw_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTDOG	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTOWH	].sReturn.Find("GTOWH")==-1) RES=WRITE_FAIL;else	lpDCowh_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTOWH	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTTMA	].sReturn.Find("GTTMA")==-1) RES=WRITE_FAIL;else	lpDCta_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTTMA	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTPDS	].sReturn.Find("GTPDS")==-1) RES=WRITE_FAIL;else	lpDCpsdls_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTPDS	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTHRM	].sReturn.Find("GTHRM")==-1) RES=WRITE_FAIL;else	lpDChrm_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTHRM	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTPCS	].sReturn.Find("GTPCS")==-1) RES=WRITE_FAIL;else	lpDCpcs_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTPCS	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTFRI	].sReturn.Find("GTFRI")==-1) RES=WRITE_FAIL;else	lpPRRfri_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTFRI	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTFFC	].sReturn.Find("GTFFC")==-1) RES=WRITE_FAIL;else	lpPRRfcofri_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTFFC	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTGEO	].sReturn.Find("GTGEO")==-1) RES=WRITE_FAIL;else	lpASgc_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTGEO	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTTOW	].sReturn.Find("GTTOW")==-1) RES=WRITE_FAIL;else	lpAStac_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTTOW	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTSPD	].sReturn.Find("GTSPD")==-1) RES=WRITE_FAIL;else	lpASsa_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTSPD	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTSOS	].sReturn.Find("GTSOS")==-1) RES=WRITE_FAIL;else	lpASsosa_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTSOS	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTIDL	].sReturn.Find("GTIDL")==-1) RES=WRITE_FAIL;else	lpASeid_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTIDL	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTHBM	].sReturn.Find("GTHBM")==-1) RES=WRITE_FAIL;else	lpAShbm_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTHBM	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTSSR	].sReturn.Find("GTSSR")==-1) RES=WRITE_FAIL;else	lpASssr_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTSSR	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTBZA	].sReturn.Find("GTBZA")==-1) RES=WRITE_FAIL;else	lpASbad_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTBZA	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTSPA	].sReturn.Find("GTSPA")==-1) RES=WRITE_FAIL;else	lpASosa_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[GTSPA].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTPEO	].sReturn.Find("GTPEO")==-1) RES=WRITE_FAIL;else	lpASpg_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTPEO	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTRMD	].sReturn.Find("GTRMD")==-1) RES=WRITE_FAIL;else	lpASrdc_Dlgnew	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTRMD	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTSDS	].sReturn.Find("GTSDS")==-1) RES=WRITE_FAIL;else	lpASsadr_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTSDS	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTSTP	].sReturn.Find("GTSTP")==-1) RES=WRITE_FAIL;else	lpASser_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTSTP	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTCRA	].sReturn.Find("GTCRA")==-1) RES=WRITE_FAIL;else	lpAScd_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTCRA	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTOUT	].sReturn.Find("GTOUT")==-1) RES=WRITE_FAIL;else	lpIAdops_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTOUT	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTEPS	].sReturn.Find("GTEPS")==-1) RES=WRITE_FAIL;else	lpIAepsm_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTEPS	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTDIS	].sReturn.Find("GTDIS")==-1) RES=WRITE_FAIL;else	lpIAdips_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTDIS	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTIOB	].sReturn.Find("GTIOB")==-1) RES=WRITE_FAIL;else	lpIAips_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTIOB	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTVMS	].sReturn.Find("GTVMS")==-1) RES=WRITE_FAIL;else	lpIDSvims_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTVMS	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTVVS	].sReturn.Find("GTVVS")==-1) RES=WRITE_FAIL;else	lpIDSidbvs_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTVVS	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTAVS	].sReturn.Find("GTAVS")==-1) RES=WRITE_FAIL;else	lpIDSavis_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTAVS	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTRTO	].sReturn.Find("GTRTO")==-1) RES=WRITE_FAIL;else	lpOSrto_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTRTO	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTHMC	].sReturn.Find("GTHMC")==-1) RES=WRITE_FAIL;else	lpOShmc_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTHMC	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTWLT	].sReturn.Find("GTWLT")==-1) RES=WRITE_FAIL;else	lpOSwl_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTWLT	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTGLM	].sReturn.Find("GTGLM")==-1) RES=WRITE_FAIL;else	lpOSglsc_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTGLM	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTUPC	].sReturn.Find("GTUPC")==-1) RES=WRITE_FAIL;else	lpOSucota_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTUPC	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTCMD	].sReturn.Find("GTCMD")==-1) RES=WRITE_FAIL;else	lpOScss_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTCMD	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTUDF	].sReturn.Find("GTUDF")==-1) RES=WRITE_FAIL;else	lpOSudf_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTUDF	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTASC	].sReturn.Find("GTASC")==-1) RES=WRITE_FAIL;else	lpOSgs_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTASC	].sReturn);
		if (stu_ConfigCMD.tdReadCmds[	GTEMR	].sReturn.Find("GTEMR")==-1) RES=WRITE_FAIL;else	lpOSer_Dlg	->UpdataPage(stu_ConfigCMD.tdReadCmds[	GTEMR	].sReturn);
	}
	catch (...)
	{
		AfxMessageBox("Error Happend,Please Contact Engineer!");
		THREAD_WORK=FALSE;
		return WRITE_FAIL;
	}
TESTEND:	
	THREAD_WORK=FALSE;
	return RES;
}

int CMYWORK::SendFromDevice_EXC()
{
	CString sReceiveData="";
	int RES=SUCCESS;
	////////////////////////////////////////////
	if (!CHECK_ATPORT_INSERT_WITH_ONTIME(30,3))
	{
		RES=WRITE_FAIL;
		goto TESTEND;
	}
	for (int i=0;i<43;i++)
	{
		CString sCmdstr="";
		sCmdstr.Format("AT+CONFIG=%s",stu_ConfigCMD.tdWriteCmds[i].sCmdstr);
		if (!TEST_AT(sCmdstr,stu_ConfigCMD.tdWriteCmds[i].sReturn))
		{
			RES=WRITE_FAIL;
			goto TESTEND;
		}
		Sleep(1000);
	}

	
TESTEND:	
	THREAD_WORK=FALSE;
	return RES;
}

int CMYWORK::SaveFromPage_EXC()
{
	int RES=SUCCESS;
	HWND m_hWnd;
	char szPath[MAX_PATH];     //存放选择的目录路径 
	CString sPath="",sHead="",sTemp="";
	FILE* fp;
	m_hWnd=AfxGetMainWnd()->m_hWnd;
	ZeroMemory(szPath, sizeof(szPath));  
	BROWSEINFO bi;   
	bi.hwndOwner = m_hWnd;				// 父窗口句柄
	bi.pidlRoot = NULL;					// 要显示的文件夹的根(Root)
	bi.pszDisplayName = szPath;			// 保存被选取的文件夹路径的缓冲区
	bi.lpszTitle = "FILE PATH";// 显示位于对话框左上部的标题   
	bi.ulFlags = BIF_RETURNONLYFSDIRS;	// 指定对话框的外观和功能的标志
	bi.lpfn = NULL;						// 处理事件的回调函数
	bi.lParam = 0;						// 应用程序传给回调函数的参数
	bi.iImage = 0;						// 保存被选取的文件夹的图片索引
	//弹出选择目录对话框
	LPITEMIDLIST lp = SHBrowseForFolder(&bi);  
	if(lp && SHGetPathFromIDList(lp, szPath))   
	{
		sPath.Format("%s",szPath);
		if (sPath.Right(1)!='\\')
		{
			sPath=sPath+"\\";
		}
	}
	else   
	{
		AfxMessageBox("UNKOW PATH");   
		RES=WRITE_FAIL;
		goto TESTEND;
	}
	sPath=sPath+"SaveAllData.txt";
	//置空文件先
	sTemp="";
	fp=fopen(sPath,"w");
	fwrite(sTemp,sTemp.GetLength(),1,fp);
	fclose(fp);
	//增加头
	sHead="[SAVEALLDATA]\n";
	fp=fopen(sPath,"a");
	fwrite(sHead,sHead.GetLength(),1,fp);
	fclose(fp);
	for (int i=0;i<43;i++)
	{
		CString sCmdstr="";
		sCmdstr.Format("%d=%s\n",i,stu_ConfigCMD.tdWriteCmds[i].sCmdstr);
		fp=fopen(sPath,"a");
		fwrite(sCmdstr,sCmdstr.GetLength(),1,fp);
		fclose(fp);
	}
TESTEND:	
	THREAD_WORK=FALSE;
	return RES;
}

int CMYWORK::ReadFromFile_EXC()
{
	int RES=SUCCESS;
	CString strPath="",sReadFileTemp="";
	CString FileName="",FileExt="",FileTitle="";
	if (strPath=="")
	{
		strPath="C:\\";
	}
	else
	{
		strPath=strPath+"\\";
	}

	CFileDialog file(TRUE,NULL,strPath,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("ReadDataFromFile|*.txt|All|*.*|"),AfxGetMainWnd());
	if(file.DoModal()==2)
	{
		RES=WRITE_FAIL;
		goto TESTEND;
	}
	FileName=file.GetPathName(); 
	for (int i=0;i<44;i++)
	{
		CString sTemp="";
		sTemp.Format("%d",i);
		GetPrivateProfileString("SAVEALLDATA",sTemp,"",sReadFileTemp.GetBuffer(MAX_PATH),MAX_PATH,FileName);
		sReadFileTemp.ReleaseBuffer();
		stu_ConfigCMD.tdWriteCmds[i].sCmdstr=sReadFileTemp;
	}
	try
	{
		if (stu_ConfigCMD.tdWriteCmds[GTBSI].sCmdstr.Find("GTBSI")!=-1)     lpSCbsi_Dlg->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTBSI	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTSRI	].sCmdstr.Find("GTSRI")!=-1)    lpSCbsri_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTSRI	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTQSS	].sCmdstr.Find("GTQSS")!=-1)	lpSCqss_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTQSS	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTCFG	].sCmdstr.Find("GTCFG")!=-1)    lpDCgc_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTCFG	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTPIN	].sCmdstr.Find("GTPIN")!=-1) 	lpDCap_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTPIN	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTDOG	].sCmdstr.Find("GTDOG")!=-1) 	lpDCspw_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTDOG	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTOWH	].sCmdstr.Find("GTOWH")!=-1) 	lpDCowh_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTOWH	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTTMA	].sCmdstr.Find("GTTMA")!=-1) 	lpDCta_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTTMA	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTPDS	].sCmdstr.Find("GTPDS")!=-1)	lpDCpsdls_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTPDS	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTHRM	].sCmdstr.Find("GTHRM")!=-1) 	lpDChrm_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTHRM	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTPCS	].sCmdstr.Find("GTPCS")!=-1) 	lpDCpcs_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTPCS	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTFRI	].sCmdstr.Find("GTFRI")!=-1) 	lpPRRfri_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTFRI	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTFFC	].sCmdstr.Find("GTFFC")!=-1) 	lpPRRfcofri_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTFFC	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTGEO	].sCmdstr.Find("GTGEO")!=-1) 	lpASgc_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTGEO	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTTOW	].sCmdstr.Find("GTTOW")!=-1) 	lpAStac_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTTOW	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTSPD	].sCmdstr.Find("GTSPD")!=-1) 	lpASsa_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTSPD	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTSOS	].sCmdstr.Find("GTSOS")!=-1) 	lpASsosa_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTSOS	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTIDL	].sCmdstr.Find("GTIDL")!=-1) 	lpASeid_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTIDL	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTHBM	].sCmdstr.Find("GTHBM")!=-1) 	lpAShbm_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTHBM	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTSSR	].sCmdstr.Find("GTSSR")!=-1) 	lpASssr_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTSSR	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTBZA	].sCmdstr.Find("GTBZA")!=-1) 	lpASbad_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTBZA	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTSPA	].sCmdstr.Find("GTSPA")!=-1) 	lpASosa_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[GTSPA].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTPEO	].sCmdstr.Find("GTPEO")!=-1) 	lpASpg_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTPEO	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTRMD	].sCmdstr.Find("GTRMD")!=-1) 	lpASrdc_Dlgnew	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTRMD	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTSDS	].sCmdstr.Find("GTSDS")!=-1) 	lpASsadr_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTSDS	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTSTP	].sCmdstr.Find("GTSTP")!=-1) 	lpASser_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTSTP	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTCRA	].sCmdstr.Find("GTCRA")!=-1) 	lpAScd_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTCRA	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTOUT	].sCmdstr.Find("GTOUT")!=-1)	lpIAdops_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTOUT	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTEPS	].sCmdstr.Find("GTEPS")!=-1) 	lpIAepsm_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTEPS	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTDIS	].sCmdstr.Find("GTDIS")!=-1) 	lpIAdips_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTDIS	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTIOB	].sCmdstr.Find("GTIOB")!=-1) 	lpIAips_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTIOB	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTVMS	].sCmdstr.Find("GTVMS")!=-1) 	lpIDSvims_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTVMS	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTVVS	].sCmdstr.Find("GTVVS")!=-1) 	lpIDSidbvs_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTVVS	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTAVS	].sCmdstr.Find("GTAVS")!=-1) 	lpIDSavis_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTAVS	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTRTO	].sCmdstr.Find("GTRTO")!=-1) 	lpOSrto_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTRTO	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTHMC	].sCmdstr.Find("GTHMC")!=-1) 	lpOShmc_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTHMC	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTWLT	].sCmdstr.Find("GTWLT")!=-1) 	lpOSwl_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTWLT	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTGLM	].sCmdstr.Find("GTGLM")!=-1) 	lpOSglsc_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTGLM	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTUPC	].sCmdstr.Find("GTUPC")!=-1)	lpOSucota_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTUPC	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTCMD	].sCmdstr.Find("GTCMD")!=-1)	lpOScss_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTCMD	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTUDF	].sCmdstr.Find("GTUDF")!=-1) 	lpOSudf_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTUDF	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTASC	].sCmdstr.Find("GTASC")!=-1) 	lpOSgs_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTASC	].sCmdstr);
		if (stu_ConfigCMD.tdWriteCmds[GTEMR	].sCmdstr.Find("GTEMR")!=-1) 	lpOSer_Dlg	->UpdataPage(stu_ConfigCMD.tdWriteCmds[	GTEMR].sCmdstr);
	}
	catch (...)
	{
		AfxMessageBox("Error Happend,Please Contact Engineer!");
		THREAD_WORK=FALSE;
		return WRITE_FAIL;
	}

TESTEND:	
	THREAD_WORK=FALSE;
	return RES;
}

BOOL CMYWORK::CHECK_ATPORT_INSERT_WITH_ONTIME(int TimeOut_s,int OnTime_s)
{
	clock_t start,stop;
	float fScanTime;
	int index=0;
	lpCConfigToolDlg->OutPutDebugLog("--CHECK AT PORT INSERT--");
	for (int i=0;i<20;i++)//置空
	{
		m_struct_ScanPort.portinfo_scan[i].iPortNumber=0;
		m_struct_ScanPort.portinfo_scan[i].sPortName="";
	}
	start=clock();
	while(1)
	{
		stop=clock();
		fScanTime=(float)(stop-start)/CLOCKS_PER_SEC;
		if(fScanTime>TimeOut_s)
		{
			lpCConfigToolDlg->OutPutDebugLog("CHECK AT PORT INSERT TIME OUT");
			return FALSE;
		}

		lpCConfigToolDlg->enumUsbPort(&m_struct_ScanPort);

		for (int k=0;k<20;k++)
		{
			if (m_struct_ScanPort.portinfo_scan[k].iPortNumber==stu_CONFIG.iPhonePort)
			{
				index++;
				break;
			}
			else
			{
				if (k==19)
				{
					index=0;
				}
			}
		}

		if (index==OnTime_s)
		{
			lpCConfigToolDlg->OutPutDebugLog("CHECK AT PORT INSERT SUCCESS");
			return TRUE;
		}
		Sleep(1000);
	}

	return TRUE;
}

bool CMYWORK::ENTER_FACTTEST(CString &sReceiveData)
{
	PopupWindow_START("Press Reboot Button On The Debug Board");
	lpCConfigToolDlg->OutPutDebugLog("--Please Reboot Or Power On!--");
	CString Commond="",sRes="",ERRINFO="",sStrDebug="";
	clock_t start,stop;
	float fScanTime,Timeout_s=20;
	int iTime=30;
	lpCConfigToolDlg->SetTimer(iTime,1000,NULL);
	lpCConfigToolDlg->ShowInfo("请打开开关开机进入工厂模式!(Please Reboot Or Power On)");
	start=clock();//计时开始毫秒为单位
	do 
	{
		stop=clock();
		fScanTime=(float)(stop-start)/CLOCKS_PER_SEC;
		if(fScanTime>Timeout_s)
		{
			PopupWindowEnd();
			lpCConfigToolDlg->ShowInfo("等待超时!");
			return false;
		}
		if (sReceiveData.Find("OK")!=-1) break;
		if (sReceiveData!="") lpCConfigToolDlg->OutPutDebugLog(sReceiveData);
		m_ATCMD.ReadDataOnly(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,sReceiveData,30,ERRINFO);
		if (sReceiveData!="") lpCConfigToolDlg->OutPutDebugLog(sReceiveData);
		if (sReceiveData.Find("power on")!=-1)//For Godi
		//if (sReceiveData.Find("Power On")!=-1) //For Beacon
		{			
			CString sATcmd="AT+FACTTEST",sKeyValue="OK";//For Godi
			//CString sATcmd="AT+FACTEST=1",sKeyValue="OK";//For Beacon
			Sleep(500);
			if (!m_ATCMD.KeySendAtCommond(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,sATcmd,sRes,sKeyValue,3,sStrDebug)) goto FAIL;
			for (int i = 0;i<3;i++)
			{  
				if (sRes.Find("OK")==-1)
				{
					if (i==2) goto FAIL;
					continue;
				}
				else
				{
					
					lpCConfigToolDlg->ShowInfo("进入工厂模式成功!");
					lpCConfigToolDlg->KillTimer(iTime);
					lpCConfigToolDlg->SetDlgItemText(IDC_MFCBUTTON_ETM,"Save to Device");	
					//lpCConfigToolDlg->SetDlgItemText(IDC_STATIC_CountDown,"");
					PopupWindowEnd();
					return true;	
				}
				Sleep(500);
			}
FAIL:
			lpCConfigToolDlg->OutPutDebugLog(sStrDebug);
			PopupWindowEnd();
			return FALSE;
		}
	} while (1);
	return false;
}

bool CMYWORK::PHONE_Read_DefValue(CString &sDefValue,CString &sReceivedata)
{
	lpCConfigToolDlg->OutPutDebugLog("-----------------------------DefValue TEST---------------------------");
	CString sATcmd="AT+DEFREPFD?",sKeyValue="OK",sStrDebug;
	int index1=0;
	if (!m_ATCMD.KeySendAtCommond(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,sATcmd,sReceivedata,sKeyValue,3,sStrDebug)) goto FAIL;
	for (int i = 0;i<3;i++)
	{  
		if (sReceivedata.Find("OK")==-1)
		{
			if (i==2) goto FAIL;
			continue;
		}
		else
		{
			index1=sReceivedata.Find("?")+1;
			sStrDebug=sReceivedata.Right(sReceivedata.GetLength()-index1).Trim();
			index1=sStrDebug.Find("OK");
			sDefValue=sStrDebug.Left(index1).Trim();
			int i=sDefValue.GetLength();			
			if (32!=i) goto FAIL;
			else 
			{
				sDefValue=sDefValue.Left(24).Trim();
				return true;	
			}
		}
		Sleep(500);
	}
FAIL:
	lpCConfigToolDlg->OutPutDebugLog(sStrDebug);
	return FALSE;
}

bool CMYWORK::PHONE_Read_RAWValue(CString &sRawValue,CString &sReceivedata)
{
	lpCConfigToolDlg->OutPutDebugLog("-----------------------------Read RawValue TEST---------------------------");
	CString sATcmd="AT+RAWREPFD?",sKeyValue="OK",sStrDebug;
	int index1=0;
	if (!m_ATCMD.KeySendAtCommond(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,sATcmd,sReceivedata,sKeyValue,3,sStrDebug)) goto FAIL;
	for (int i = 0;i<3;i++)
	{  
		if (sReceivedata.Find("OK")==-1)
		{
			if (i==2) goto FAIL;
			continue;
		}
		else
		{
			index1=sReceivedata.Find("?")+1;
			sStrDebug=sReceivedata.Right(sReceivedata.GetLength()-index1).Trim();
			index1=sStrDebug.Find("OK");
			sRawValue=sStrDebug.Left(index1).Trim();
			int i=sRawValue.GetLength();			
			if (32!=i) goto FAIL;
			else 
			{
				sRawValue=sRawValue.Left(24).Trim();
				return true;	
			}
		}
		Sleep(500);
	}
FAIL:
	lpCConfigToolDlg->OutPutDebugLog(sStrDebug);
	return FALSE;
}

bool CMYWORK::PHONE_Read_ALEValue(CString &sAleValue,CString &sReceivedata)
{
	lpCConfigToolDlg->OutPutDebugLog("-----------------------------Read AleValue TEST---------------------------");
	CString sATcmd="AT+ALERTREPFD?",sKeyValue="OK",sStrDebug;
	int index1=0;
	if (!m_ATCMD.KeySendAtCommond(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,sATcmd,sReceivedata,sKeyValue,3,sStrDebug)) goto FAIL;
	for (int i = 0;i<3;i++)
	{  
		if (sReceivedata.Find("OK")==-1)
		{
			if (i==2) goto FAIL;
			continue;
		}
		else
		{
			index1=sReceivedata.Find("?")+1;
			sStrDebug=sReceivedata.Right(sReceivedata.GetLength()-index1).Trim();
			index1=sStrDebug.Find("OK");
			sAleValue=sStrDebug.Left(index1).Trim();
			int i=sAleValue.GetLength();			
			if (32!=i) goto FAIL;
			else 
			{
				sAleValue=sAleValue.Left(24).Trim();
				return true;	
			}
		}
		Sleep(500);
	}
FAIL:
	lpCConfigToolDlg->OutPutDebugLog(sStrDebug);
	return FALSE;
}

bool CMYWORK::PHONE_Read_FULLValue(CString &sFullValue,CString &sReceivedata)
{
	lpCConfigToolDlg->OutPutDebugLog("-----------------------------READ FULLValue TEST---------------------------");
	CString sATcmd="AT+FULLREPFD?",sKeyValue="OK",sStrDebug;
	int index1=0;
	if (!m_ATCMD.KeySendAtCommond(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,sATcmd,sReceivedata,sKeyValue,3,sStrDebug)) goto FAIL;
	for (int i = 0;i<3;i++)
	{  
		if (sReceivedata.Find("OK")==-1)
		{
			if (i==2) goto FAIL;
			continue;
		}
		else
		{
			index1=sReceivedata.Find("?")+1;
			sStrDebug=sReceivedata.Right(sReceivedata.GetLength()-index1).Trim();
			index1=sStrDebug.Find("OK");
			sFullValue=sStrDebug.Left(index1).Trim();
			int i=sFullValue.GetLength();			
			if (32!=sFullValue.GetLength()) goto FAIL;
			else 
			{
				sFullValue=sFullValue.Left(24).Trim();
				return true;	
			}
		}
		Sleep(500);
	}
FAIL:
	lpCConfigToolDlg->OutPutDebugLog(sStrDebug);

	return FALSE;

}

BOOL CMYWORK::PHONE_Write_DefValue(CString sDefValue, CString &sStrDebug)
{
	lpCConfigToolDlg->OutPutDebugLog("-----------------------------WRITE  DefValue TEST---------------------------");
	CString Commond="",sReceiveData="",ERRINFO="",sSN="";
	int index1=0;
	CString keyValue="OK";
	Commond.Format("AT+DEFREPFD=%s",sDefValue);
	//if (!CheckNumberType(CUSTOMSN)) goto FAIL;	
	if (!m_ATCMD.KeySendAtCommond(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,Commond,sReceiveData,keyValue,3,ERRINFO)) goto FAIL;
	for (int i = 0;i<3;i++)
	{
		if (sReceiveData.Find("OK")==-1)
		{
			if (i==2) goto FAIL;
			continue;
		}
		else
		{
			index1=sReceiveData.Find("=")+1;
			sStrDebug=sReceiveData.Right(sReceiveData.GetLength()-index1).Trim();
			if (sStrDebug.Find("OK")==-1) goto FAIL;	
			else
			{
				index1=sStrDebug.Find("OK");
				sDefValue=sStrDebug.Left(index1).Trim();
				if (!PHONE_Read_DefValue(sSN,sStrDebug)) goto FAIL;
				if (sSN.Find(sDefValue)!=-1) return true;
				else goto FAIL;
			}
		}
		Sleep(500);
	}		
FAIL:
	lpCConfigToolDlg->OutPutDebugLog(sStrDebug);
	return FALSE;
}

BOOL CMYWORK::PHONE_Write_RAWValue(CString sRawValue, CString &sStrDebug)
{
	lpCConfigToolDlg->OutPutDebugLog("-----------------------------WRITE  RAWValue TEST---------------------------");
	CString Commond="",sReceiveData="",ERRINFO="",sSN="";
	int index1=0;
	CString keyValue="OK";
	Commond.Format("AT+RAWREPFD=%s",sRawValue);
	if (!m_ATCMD.KeySendAtCommond(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,Commond,sReceiveData,keyValue,3,ERRINFO)) goto FAIL;
	for (int i = 0;i<3;i++)
	{
		if (sReceiveData.Find("OK")==-1)
		{
			if (i==2) goto FAIL;
			continue;
		}
		else
		{
			index1=sReceiveData.Find("=")+1;
			sStrDebug=sReceiveData.Right(sReceiveData.GetLength()-index1).Trim();
			if (sStrDebug.Find("OK")==-1) goto FAIL;	
			else
			{
				index1=sStrDebug.Find("OK");
				sRawValue=sStrDebug.Left(index1).Trim();
				if (!PHONE_Read_RAWValue(sSN,sStrDebug)) goto FAIL;
				if (sSN.Find(sRawValue)!=-1) return true;
				else goto FAIL;
			}
		}
		Sleep(500);
	}		
FAIL:
	lpCConfigToolDlg->OutPutDebugLog(sStrDebug);
	return FALSE;
}

BOOL CMYWORK::PHONE_Write_ALEValue(CString sAleValue, CString &sStrDebug)
{
	lpCConfigToolDlg->OutPutDebugLog("-----------------------------WRITE  ALEValue TEST---------------------------");
	CString Commond="",sReceiveData="",ERRINFO="",sSN="";
	int index1=0;
	CString keyValue="OK";
	Commond.Format("AT+ALERTREPFD=%s",sAleValue);
	if (!m_ATCMD.KeySendAtCommond(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,Commond,sReceiveData,keyValue,3,ERRINFO)) goto FAIL;
	for (int i = 0;i<3;i++)
	{
		if (sReceiveData.Find("OK")==-1)
		{
			if (i==2) goto FAIL;
			continue;
		}
		else
		{
			index1=sReceiveData.Find("=")+1;
			sStrDebug=sReceiveData.Right(sReceiveData.GetLength()-index1).Trim();
			if (sStrDebug.Find("OK")==-1) goto FAIL;	
			else
			{
				index1=sStrDebug.Find("OK");
				sAleValue=sStrDebug.Left(index1).Trim();
				if (!PHONE_Read_ALEValue(sSN,sStrDebug)) goto FAIL;
				if (sSN.Find(sAleValue)!=-1) return true;
				else goto FAIL;
			}
		}
		Sleep(500);
	}		
FAIL:
	lpCConfigToolDlg->OutPutDebugLog(sStrDebug);
	return FALSE;
}

BOOL CMYWORK::PHONE_Write_FullValue(CString sValue, CString &sStrDebug)
{
	lpCConfigToolDlg->OutPutDebugLog("-----------------------------WRITE  FullValue TEST---------------------------");
	CString Commond="",sReceiveData="",ERRINFO="",sSN="";
	int index1=0;
	CString keyValue="OK";
	Commond.Format("AT+FULLREPFD=%s",sValue);
	//if (!CheckNumberType(CUSTOMSN)) goto FAIL;	
	if (!m_ATCMD.KeySendAtCommond(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,Commond,sReceiveData,keyValue,3,ERRINFO)) goto FAIL;
	for (int i = 0;i<3;i++)
	{
		if (sReceiveData.Find("OK")==-1)
		{
			if (i==2) goto FAIL;
			continue;
		}
		else
		{
			index1=sReceiveData.Find("=")+1;
			sStrDebug=sReceiveData.Right(sReceiveData.GetLength()-index1).Trim();
			if (sStrDebug.Find("OK")==-1) goto FAIL;	
			else
			{
				index1=sStrDebug.Find("OK");
				sValue=sStrDebug.Left(index1).Trim();
				if (!PHONE_Read_FULLValue(sSN,sStrDebug)) goto FAIL;
				if (sSN.Find(sValue)!=-1) return true;
				else goto FAIL;
			}
		}
		Sleep(500);
	}		
FAIL:
	lpCConfigToolDlg->OutPutDebugLog(sStrDebug);
	return FALSE;
}

bool CMYWORK::PHONE_Write_Trans(REPINF *pHRepInf,REPINF *pSRepInf,REPINF *pTRepInf)
{	
	
	return true;

}

BOOL CMYWORK::PHONE_Read_BSN(CString &sStrDebug)//主板SN
{
	lpCConfigToolDlg->OutPutDebugLog("-----------------------------READ BSN TEST---------------------------");
	CString sATcmd="AT+BSN?",sKeyValue="BSN",sReceivedata="";
	int index1=0;
	if (!m_ATCMD.KeySendAtCommond(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,sATcmd,sReceivedata,sKeyValue,3,sStrDebug)) goto FAIL;
	for (int i = 0;i<3;i++)
	{  
		if (sReceivedata.Find("BSN")==-1)
		{
			if (i==2) goto FAIL;
			continue;
		}
		else
		{
			index1=sReceivedata.Find("?")+1;
			sStrDebug=sReceivedata.Right(sReceivedata.GetLength()-index1).Trim();	
			if (sStrDebug.Find("OK")==-1) goto FAIL;
			else 
			{
				index1=sStrDebug.Find("OK");
				sStrDebug=sStrDebug.Left(index1).Trim();
				return true;
			}			
		}
		Sleep(500);
	}
FAIL:
	lpCConfigToolDlg->OutPutDebugLog(sStrDebug);
	return FALSE;
}

BOOL CMYWORK::TEST_READ_MCUIMEI(CString &sStrDebug)
{
	lpCConfigToolDlg->OutPutDebugLog("-----------------------------READ MCUIMEI TEST---------------------------");
	CString sATcmd="AT+MCUIMEI?",sKeyValue="OK",sReceivedata="";
	int index1=0;
	if (!m_ATCMD.KeySendAtCommond(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,sATcmd,sReceivedata,sKeyValue,3,sStrDebug)) goto FAIL;
	for (int i = 0;i<3;i++)
	{  
		if (sReceivedata.Find("OK")==-1)
		{
			if (i==2) goto FAIL;
			continue;
		}
		else
		{
			index1=sReceivedata.Find("?")+1;
			sStrDebug=sReceivedata.Right(sReceivedata.GetLength()-index1).Trim();	
			if (sStrDebug.Find("OK")==-1) goto FAIL;
			else 
			{
				index1=sStrDebug.Find("OK");
				sStrDebug=sStrDebug.Left(index1).Trim();	
				if (!CheckNumberType(sStrDebug)) goto FAIL;	
				return true;
			}			
		}
		Sleep(500);
	}
FAIL:
	lpCConfigToolDlg->OutPutDebugLog(sStrDebug);
	return FALSE;
}

bool CMYWORK::CheckNumberType(CString Number)
{
	CString sCheckPrefix;
	CString sOutput="";
	if (Number.IsEmpty())
	{
		lpCConfigToolDlg->OutPutDebugLog("Number is null");
		return false;
	}	
	else
	{
		TCHAR NV_Data[30] = {0};
		memcpy(NV_Data, Number, Number.GetLength());
		for(int i=0;i<Number.GetLength();i++)
		{
			if(!((NV_Data[i] >= '0' && NV_Data[i] <= '9')))
			{
				lpCConfigToolDlg->OutPutDebugLog("存在非法字符");
				return false;
			}
		}
	}

	return true;
}

BOOL CMYWORK::PHONE_Read_CUSTOMSN(CString &sStrDebug)
{
	lpCConfigToolDlg->OutPutDebugLog("-----------------------------READ CUSTOMER SN TEST---------------------------");
	CString sATcmd="AT+CUSTOMSN?",sKeyValue="OK",sReceivedata="";
	int index1=0;
	if (!m_ATCMD.KeySendAtCommond(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,sATcmd,sReceivedata,sKeyValue,3,sStrDebug)) goto FAIL;
	for (int i = 0;i<3;i++)
	{  
		if (sReceivedata.Find("OK")==-1)
		{
			if (i==2) goto FAIL;
			continue;
		}
		else
		{
			index1=sReceivedata.Find("?")+1;
			sStrDebug=sReceivedata.Right(sReceivedata.GetLength()-index1).Trim();	
			if (sStrDebug.Find("OK")==-1) goto FAIL;
			else 
			{
				index1=sStrDebug.Find("OK");
				sStrDebug=sStrDebug.Left(index1).Trim();	
				//if (!CheckNumberType(sStrDebug)) goto FAIL;	
				return true;
			}			
		}
		Sleep(500);
	}
FAIL:
	lpCConfigToolDlg->OutPutDebugLog(sStrDebug);
	return FALSE;
}

bool CMYWORK::TEST_AT(CString sStrCMD,CString &sReceivedata)
{
	lpCConfigToolDlg->OutPutDebugLog("--AT TEST--");
	CString sKeyValue="OK",sStrDebug="";
	sReceivedata="";
	int index1=0;
	if (!m_ATCMD.KeySendAtCommond(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,sStrCMD,sReceivedata,sKeyValue,25,sStrDebug)) goto FAIL;
	for (int i = 0;i<3;i++)
	{  
		if (sReceivedata.Find("OK")==-1)
		{
			if (i==2) goto FAIL;
			continue;
		}
		else
		{
			/*index1=sReceivedata.Find("?")+1;
			sStrDebug=sReceivedata.Right(sReceivedata.GetLength()-index1).Trim();
			index1=sStrDebug.Find("OK");
			sStrDebug=sStrDebug.Left(index1).Trim();*/
			//m_MMIDATA.sSEQ=sStrDebug;
			return true;	
		}
		Sleep(500);
	}
FAIL:
	lpCConfigToolDlg->OutPutDebugLog(sStrDebug);
	return FALSE;
}

BOOL CMYWORK::INIT_POWER() 
{
	//CString ERRINFO="";
	//lpCConfigToolDlg->OutPutDebugLog("INIT POWER");
	//if (!m_PowerControl.OpenEqupment(ERRINFO))
	//{
	//	lpCConfigToolDlg->OutPutDebugLog(ERRINFO);
	//	lpCConfigToolDlg->OutPutTestList("OpenEqupmentFAIL",ERRINFO,"","",false,1);
	//	return FALSE;
	//}
	//if (!m_PowerControl.RST())
	//{
	//	lpCConfigToolDlg->OutPutDebugLog("INIT POWER FAIL");
	//	lpCConfigToolDlg->OutPutTestList("RSTFAIL","","","",false,1);
	//	return FALSE;
	//}
	////m_PowerControl.CloseEqupment();
	return TRUE;
}

BOOL CMYWORK::OPEN_POWER(CString Volt) 
{
	/*CString ERRINFO="";
	lpCConfigToolDlg->OutPutDebugLog("OPEN POWER");
	if (!m_PowerControl.OpenEqupment(ERRINFO))
	{
		lpCConfigToolDlg->OutPutDebugLog(ERRINFO);
		return FALSE;
	}
	if (!m_PowerControl.OpenBattery(Volt))
	{
		lpCConfigToolDlg->OutPutDebugLog("Set Volt Fail");
		return FALSE;
	}
	m_PowerControl.CloseEqupment();*/
	return TRUE;
}

void CMYWORK::BsToHex(CString sHDefaultB,CString &sHDefaultH,int iLth)
{
	char *stopstring; 
	const char *cBin = (LPSTR)(LPCTSTR)sHDefaultB; 
	UINT iValue;  
	iValue =strtoul(cBin, &stopstring, 2); //转换成无符号的长整型数(unsigned long),一定要是无符号的
	char c[36]; 
	sprintf_s(c, "%x", iValue); 
	CString  str(c); 
	if (1==iLth)
	{
		sHDefaultH.Format("%s",str);
		sHDefaultH.MakeUpper();
	}
	if (2==iLth)
	{
		sHDefaultH.Format("%02s",str);
		sHDefaultH.MakeUpper();
	}
	if (4==iLth)
	{
		sHDefaultH.Format("%04s",str);
		sHDefaultH.MakeUpper();
	}
	if (5==iLth)
	{
		sHDefaultH.Format("%05s",str);
		sHDefaultH.MakeUpper();
	}
	if (8==iLth)
	{
		sHDefaultH.Format("%08s",str);
		sHDefaultH.MakeUpper();
	}
}

void CMYWORK::BsToHex2Bit(CString sHDefaultB,CString &sHDefaultH)
{
	char *stopstring; 
	const char *cBin = (LPSTR)(LPCTSTR)sHDefaultB; 
	UINT iValue;  
	iValue =strtoul(cBin, &stopstring, 2); //转换成无符号的长整型数(unsigned long),一定要是无符号的
	char c[20]; 
	sprintf_s(c, "%x", iValue); 
	CString  str(c); 
	sHDefaultH.Format("%02s",str);
	sHDefaultH.MakeUpper();
}

void CMYWORK::HexToBs(CString sValueHex,CString &sBs)
{
	CString sHHex="",sSHex="",sTHex="",sStrDebug="";
	char cHbs[33]={0};
	char cSbs[33]={0};
	char cTbs[33]={0};
	char cBS[97]={0};
	char *stopstring; 
	const char *cBin = "";
	UINT iValue=0;  
	char c[20]={0}; 
	char b[33]={0};
	char bs[33]={0};

	sHHex=sValueHex.Left(8);
	sSHex=sValueHex.Mid(8,8);
	sTHex=sValueHex.Mid(16,8);

	cBin = (LPSTR)(LPCTSTR)sHHex;
	iValue =strtoul(cBin, &stopstring, 16); //把const char *cBin按16进制转为10无符号长整型进制
	//ltoa(iValue,b,2);
	_ultoa_s(iValue,b,2);
	sprintf_s(cHbs,"%032s",b);
	sStrDebug.Format("%s,%s",sHHex,cHbs);

	cBin = (LPSTR)(LPCTSTR)sSHex;
	iValue =strtoul(cBin, &stopstring, 16); //把const char *cBin按16进制转为10无符号长整型进制
	//ltoa(iValue,b,2);
	_ultoa_s(iValue,b,2);
	sprintf_s(cSbs,"%032s",b);
	sStrDebug.Format("%s,%s",sSHex,cSbs);

	cBin = (LPSTR)(LPCTSTR)sTHex;
	iValue =strtoul(cBin, &stopstring, 16); //把const char *cBin按16进制转为10无符号长整型进制
	//ltoa(iValue,b,2);
	_ultoa_s(iValue,b,2);
	sprintf_s(cTbs,"%032s",b);

	//lpCConfigToolDlg->OutPutTestList(sHHex,cHbs,"","",true,1);
	//lpCConfigToolDlg->OutPutTestList(sSHex,cSbs,"","",true,1);
	//lpCConfigToolDlg->OutPutTestList(sTHex,cTbs,"","",true,1);

	strcat_s(cBS,cHbs);
	strcat_s(cBS,cSbs);
	strcat_s(cBS,cTbs);

	sBs.Format("%s",cBS);
}

bool CMYWORK::FIND_GSMOFF(CString &sReceiveData)
{
	lpCConfigToolDlg->OutPutDebugLog("---------------------------WAIT GSMOFF---------------------------");
	CString Commond="",sRes="",ERRINFO="",sStrDebug="";
	clock_t start,stop;
	float fScanTime,Timeout_s=20;
	int iTime=30;
	//lpCConfigToolDlg->SetTimer(iTime,1000,NULL);
	lpCConfigToolDlg->ShowInfo("WAIT GSMOFF!");
	start=clock();//计时开始毫秒为单位
	do 
	{
		stop=clock();
		fScanTime=(float)(stop-start)/CLOCKS_PER_SEC;
		if (sReceiveData.Find("power on")!=-1) break;
		if (sReceiveData!="") lpCConfigToolDlg->OutPutDebugLog(sReceiveData);
		m_ATCMD.ReadDataOnly(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,sReceiveData,30,ERRINFO);
		if (sReceiveData!="") lpCConfigToolDlg->OutPutDebugLog(sReceiveData);
		if (sReceiveData.Find("Gsm Power Off")!=-1)//For Godi
		{			
			if (!REBOOT_CHECK(sStrDebug)) goto FAIL;
            continue;
FAIL:
			lpCConfigToolDlg->OutPutDebugLog(sStrDebug);
			return FALSE;
		}
		else
		{
			if (sReceiveData.Find("power on")!=-1) continue;
			sReceiveData="";
		}
	} while (1);
	return false;
}

bool CMYWORK::LOOP_REBOOT(CString &sReceiveData)
{
	lpCConfigToolDlg->OutPutDebugLog("---------------------------LOOP_REBOOT---------------------------");
	CString Commond="",sRes="",ERRINFO="",sStrDebug="";
	clock_t start,stop;
	float fScanTime,Timeout_s=900;
	int iTime=0;
	sReceiveData="";
	//lpCConfigToolDlg->SetTimer(iTime,1000,NULL);
	lpCConfigToolDlg->ShowInfo("LOOP_REBOOT!");
	start=clock();//计时开始毫秒为单位
	do 
	{
		if (sReceiveData.Find("power on")!=-1) 
		{   
			iTime++;
			CTime time = CTime::GetCurrentTime();
			CString sTime = time.Format("%Y-%m-%d_%H-%M-%S");  
			sStrDebug.Format("%s发现重启第%d次",sTime,iTime);
			lpCConfigToolDlg->OutPutDebugLog(sStrDebug);
			if (iTime>=3) break;		
		}
		if (sReceiveData!="") lpCConfigToolDlg->OutPutDebugLog(sReceiveData);
		m_ATCMD.ReadDataOnly(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,sReceiveData,30,ERRINFO);
		if (sReceiveData!="") lpCConfigToolDlg->OutPutDebugLog(sReceiveData);
		//检查时间
		stop=clock();
		fScanTime=(float)(stop-start)/CLOCKS_PER_SEC;
		sStrDebug.Format("%f",fScanTime);
		lpCConfigToolDlg->OutPutDebugLog(sStrDebug);
		if(fScanTime>Timeout_s)
		{			
			if (!REBOOT_CHECK(sStrDebug)) goto FAIL;
			start=clock();//计时开始毫秒为单位
			iTime=0;
			continue;
FAIL:
			lpCConfigToolDlg->OutPutDebugLog(sStrDebug);
			return FALSE;
		}
		else
		{
			if (sReceiveData.Find("power on")!=-1) continue;
			sReceiveData="";
		}
	} while (1);
	return false;
}

bool CMYWORK::REBOOT_CHECK(CString &sReceiveData)
{
	lpCConfigToolDlg->OutPutDebugLog("---------------------------REBOOT AND CHECK---------------------------");
	CString Commond="",sRes="",ERRINFO="",sStrDebug="";
	CString sATcmd="AT+REBOOT",sKeyValue="OK";
	clock_t start,stop;
	float fScanTime,Timeout_s=15;
	lpCConfigToolDlg->ShowInfo("重启中!");
	if (!m_ATCMD.SendCommondOnly(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,sATcmd,sRes,1,sStrDebug)) goto FAIL;
	start=clock();//计时开始毫秒为单位
	do 
	{
		stop=clock();
		fScanTime=(float)(stop-start)/CLOCKS_PER_SEC;
		if(fScanTime>Timeout_s)
		{
			lpCConfigToolDlg->ShowInfo("等待超时，重启没有成功!");
			return false;
		}
		if (sReceiveData.Find("OK")!=-1) break;
		if (sReceiveData!="") lpCConfigToolDlg->OutPutDebugLog(sReceiveData);
		m_ATCMD.ReadDataOnly(stu_CONFIG.iPhonePort,stu_CONFIG.iBaudRate,sReceiveData,30,ERRINFO);
		if (sReceiveData!="") lpCConfigToolDlg->OutPutDebugLog(sReceiveData);
		if (sReceiveData.Find("power on")!=-1)
		{			
			Sleep(500);
			lpCConfigToolDlg->OutPutDebugLog("Save Success!");
			lpCConfigToolDlg->SetDlgItemText(IDC_MFCBUTTON_ETM,"Connect Device");	
			return true;	
FAIL:
			lpCConfigToolDlg->OutPutDebugLog(sStrDebug);
			return FALSE;
		}
		else
		{
			sReceiveData="";
		}
	} while (1);
	return false;
}

CString CMYWORK::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
{   //位置iPos是从0开始的
	CString sNewCmd="",sRight="",sLeft="",sTemp="";
	CArray<CString,CString>ValueList;
	int index1=0,index2=0;
	sTemp=sParestr;//准备分割
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

CString CMYWORK::UnUpdataCMD(CString sChildstr,int iPos,CString sParestr)
{   //位置iPos是从0开始的
	CString sNewCmd="",sRight="",sLeft="",sTemp="";
	CArray<CString,CString>ValueList;
	int index1=0,index2=0;
	sTemp=sParestr;//准备分割
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
	int iSize=0;
	iSize=ValueList.GetSize()-1;
	for (int i=iSize,j=0;i>=0;i--,j++)
	{
		if (iSize==i)
		{
			sNewCmd=ValueList.GetAt(i);
		}
		else
		{
			if (j==iPos)
			{
				sNewCmd=sChildstr+","+sNewCmd;
			}
			else
			{
				sNewCmd=ValueList.GetAt(i)+","+sNewCmd;
			}
		}
	}
	return sNewCmd;
}

void CMYWORK::HexToBsStr(CString sStrH,CString &sBs, int iBit)
{
	const char *cBin = "";
	UINT iValue=0;  
	char b[33]={0};
	char bs[33]={0};
	char *stopstring; 
	char cHbs[33]={0};
	cBin = (LPSTR)(LPCTSTR)sStrH;
	iValue =strtoul(cBin, &stopstring, 16); //把const char *cBin按16进制转为10无符号长整型进制
	//ltoa(iValue,b,2);
	_ultoa_s(iValue,b,2);
	if (iBit==2)
	{
	  sprintf_s(cHbs,"%02s",b);
	}
    else if (iBit==4)
    {
		sprintf_s(cHbs,"%04s",b);
    }
	else if (iBit==7)
	{
		sprintf_s(cHbs,"%07s",b);
	}
	else if (iBit==8)
	{
		sprintf_s(cHbs,"%08s",b);
	}
	else if (iBit==11)
	{
		sprintf_s(cHbs,"%011s",b);
	}
	else if (iBit==14)
	{
		sprintf_s(cHbs,"%014s",b);
	}
	else if (iBit==15)
	{
		sprintf_s(cHbs,"%015s",b);
	}
	else if (iBit==16)
	{
		sprintf_s(cHbs,"%016s",b);
	}
	else if (iBit==20)
	{
		sprintf_s(cHbs,"%020s",b);
	}
	else if (iBit==32)
	{
		sprintf_s(cHbs,"%032s",b);
	}
	sBs.Format("%s",cHbs);
}