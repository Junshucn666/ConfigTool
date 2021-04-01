#pragma once
#include "MYWORK.h"
#include "COMMON.h"
#include "ATCMD.h"
#include "TESTLIST_Dlg.h"
#include "DEBUGLOG_Dlg.h"
#include "SCbsi_Dlg.h"
#include "SCbsri_Dlg.h"
#include "SCqss_Dlg.h"
#include "DCgc_Dlg.h"
#include "DCap_Dlg.h"
#include "DCspw_Dlg.h"
#include "DCowh_Dlg.h"
#include "DCta_Dlg.h"
#include "DCpsdls_Dlg.h"
#include "DChrm_Dlg.h"
#include "DCpcs_Dlg.h"
#include "PRRfri_Dlg.h"
#include "PRRfcofri_Dlg.h"
#include "ASgc_Dlg.h"
#include "AStac_Dlg.h"
#include "ASsa_Dlg.h"
#include "ASsosa_Dlg.h"
#include "ASeid_Dlg.h"
#include "AShbm_Dlg.h"
#include "ASssr_Dlg.h"
#include "ASbad_Dlg.h"
#include "ASosa_Dlg.h"
#include "ASpg_Dlg.h"
#include "ASrdc_Dlg.h"
#include "ASsadr_Dlg.h"
#include "ASser_Dlg.h"
#include "AScd_Dlg.h"
#include "IAdops_Dlg.h"
#include "IAepsm_Dlg.h"
#include "IAdips_Dlg.h"
#include "IAips_Dlg.h"
#include "IDSvims_Dlg.h"
#include "IDSidbvs_Dlg.h"
#include "IDSavis_Dlg.h"
#include "OSrto_Dlg.h"
#include "OShmc_Dlg.h"
#include "OSwl_Dlg.h"
#include "OSglsc_Dlg.h"
#include "OSucota_Dlg.h"
#include "OScss_Dlg.h"
#include "OSudf_Dlg.h"
#include "OSgs_Dlg.h"
#include "OSer_Dlg.h"

class CMYWORK
{
public:
	CMYWORK(void);
	~CMYWORK(void);
public:
	void Thread_EenterTestMode_START();
	void Thread_Reboot_START();
	void Button_ThreadStart();
	void PopupWindow_START(CString txt);
	void PopupWindowEnd();
	void ETM_THREAD_EXE();
	void REBOOT_THREAD_EXE();
	void Button_THREAD_EXE();
    int ETM_EXC();
	int REBOOT_EXC();
    int WRITE_EXC(CString sCmdstr,CString &sReturn);
	int READFromDevice_EXC();
	int CHECK_EXC();
	int SendFromDevice_EXC();
	int SaveFromPage_EXC();
	int ReadFromFile_EXC();
	bool PHONE_Read_DefValue(CString &sStrDebug,CString &sReceivedata);
	BOOL PHONE_Write_DefValue(CString sDefValue, CString &sStrDebug);
	bool PHONE_DefValue_Compare(CString sDefVal,CString sRawVal,CString sFullVal,CString sAleVal);
	bool PHONE_Write_Trans(REPINF *pHRepInf,REPINF *pSRepInf,REPINF *pTRepInf);
	BOOL CHECK_ATPORT_INSERT_WITH_ONTIME(int TimeOut_s,int OnTime_s);
	bool ENTER_FACTTEST(CString &sReceiveData);
	BOOL PHONE_Read_BSN(CString &sStrDebug);
	BOOL TEST_READ_MCUIMEI(CString &sStrDebug);
	bool CheckNumberType(CString Number);
	BOOL PHONE_Read_CUSTOMSN(CString &sStrDebug);
	bool TEST_AT(CString sStrDebug,CString &sReceivedata);
	BOOL INIT_POWER();
	BOOL OPEN_POWER(CString Volt);
	void BsToHex(CString sHDefaultB,CString &sHDefaultH,int iLth);
	void BsToHex2Bit(CString sHDefaultB,CString &sHDefaultH);
	void HexToBs(CString sHex,CString &sBs);
	BOOL PHONE_Write_FullValue(CString sDefValue, CString &sStrDebug);
	bool PHONE_Read_FULLValue(CString &sDefValue,CString &sReceivedata);
	bool PHONE_Read_RAWValue(CString &sStrDebug,CString &sReceivedata);
	BOOL PHONE_Write_RAWValue(CString sDefValue, CString &sStrDebug);
	bool PHONE_Read_ALEValue(CString &sStrDebug,CString &sReceivedata);
	BOOL PHONE_Write_ALEValue(CString sDefValue, CString &sStrDebug);
	bool FIND_GSMOFF(CString &sReceiveData);
	bool REBOOT_CHECK(CString &sReceiveData);
	bool LOOP_REBOOT(CString &sReceiveData);
	void CmdSend_Thread_Start(ThreadData *stu_ThreadData);
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	CString UnUpdataCMD(CString sChildstr,int iPos,CString sParestr);
    void HexToBsStr(CString sStrH,CString &sBs, int iBit);
};

