
// ConfigToolDlg.h : 头文件
//

#pragma once

#include "MYWORK.h"
#include "afxwin.h"
#include "resource.h"
#include "afxcmn.h"
#include "TESTLIST_Dlg.h"
#include "DEBUGLOG_Dlg.h"
#include "afxbutton.h"
#include "ExcelOperate_DLL.h"
#include "DevHound.h"
#include "COMMON.h"
#include "MdbControl.h"
#include "tlhelp32.h"// 杀进程函数用的
#include "SCbsi_Dlg.h"//
#include "SCbsri_Dlg.h"//
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
#include "ASrdc_Dlgnew.h"
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

extern	SCbsi_Dlg m_SCbsi_Dlg;		
extern	SCbsri_Dlg m_SCbsri_Dlg;		
extern	SCqss_Dlg m_SCqss_Dlg;		
//////////////////		
extern	DCgc_Dlg m_DCgc_Dlg;		
extern	DCap_Dlg m_DCap_Dlg;		
extern	DCspw_Dlg m_DCspw_Dlg;		
extern	DCowh_Dlg m_DCowh_Dlg;		
extern	DCta_Dlg m_DCta_Dlg;		
extern	DCpsdls_Dlg m_DCpsdls_Dlg;		
extern	DChrm_Dlg m_DChrm_Dlg;		
extern	DCpcs_Dlg m_DCpcs_Dlg;		
extern	PRRfri_Dlg	m_PRRfri_Dlg	;
extern	PRRfcofri_Dlg	m_PRRfcofri_Dlg	;
extern	ASgc_Dlg	m_ASgc_Dlg	;
extern	AStac_Dlg	m_AStac_Dlg	;
extern	ASsa_Dlg	m_ASsa_Dlg	;
extern	ASsosa_Dlg	m_ASsosa_Dlg	;
extern	ASeid_Dlg	m_ASeid_Dlg	;
extern	AShbm_Dlg	m_AShbm_Dlg	;
extern	ASssr_Dlg	m_ASssr_Dlg	;
extern	ASbad_Dlg	m_ASbad_Dlg	;
extern	ASosa_Dlg	m_ASosa_Dlg	;
extern	ASpg_Dlg	m_ASpg_Dlg	;
extern	ASrdc_Dlgnew	m_ASrdc_Dlg	;
extern	ASsadr_Dlg	m_ASsadr_Dlg	;
extern	ASser_Dlg	m_ASser_Dlg	;
extern	AScd_Dlg	m_AScd_Dlg	;
extern	IAdops_Dlg	m_IAdops_Dlg	;
extern	IAepsm_Dlg	m_IAepsm_Dlg	;
extern	IAdips_Dlg	m_IAdips_Dlg	;
extern	IAips_Dlg	m_IAips_Dlg	;
extern	IDSvims_Dlg	m_IDSvims_Dlg	;
extern	IDSidbvs_Dlg	m_IDSidbvs_Dlg	;
extern	IDSavis_Dlg	m_IDSavis_Dlg	;
extern	OSrto_Dlg	m_OSrto_Dlg	;
extern	OShmc_Dlg	m_OShmc_Dlg	;
extern	OSwl_Dlg	m_OSwl_Dlg	;
extern	OSglsc_Dlg	m_OSglsc_Dlg	;
extern	OSucota_Dlg	m_OSucota_Dlg	;
extern	OScss_Dlg	m_OScss_Dlg	;
extern	OSudf_Dlg	m_OSudf_Dlg	;
extern	OSgs_Dlg	m_OSgs_Dlg	;
extern	OSer_Dlg	m_OSer_Dlg	;

extern ConfigCMD stu_ConfigCMD;
extern CMYWORK	m_MYWORK;
extern BOOL MYTHREAD_WORK;
// CConfigToolDlg 对话框
class CConfigToolDlg : public CDialogEx
{
// 构造
public:
	CConfigToolDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ConfigTool_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
protected:
	CFont fontStaticItem;
	CFont *m_pFont;//创建新的字体
public:
	CTabCtrl m_Table;
	CDialogEx* m_pDialog_Log[20];
	void OutPutDebugLog(CString sLog);
	void SaveOntimeDebugLog(CString log,CString WriteType);
	bool GetConfigFromFile();
	CString GetExeFilePath();
	afx_msg void OnTcnSelchangeTabLog(NMHDR *pNMHDR, LRESULT *pResult);
	CComboBox m_ComboBox_Port;
	CComboBox m_ComboBox_BaudRate;
	CMFCButton m_MFCBUTTON_START;
	CFont FButton_startfont;//状态框字体，不能设全局重画会丢失
	afx_msg void OnBnClickedButtonServerConnection();
	bool GetTestItem_CFG2Sheet();
	void enumUsbPort(ScanPort *lpScanPort);
	afx_msg void OnCbnSelchangeComboPort();
	afx_msg void OnCbnSelchangeComboBrate();
	CStatic m_STATIC_Status;
	void ShowBmp(int sw);
	void ShowInfo(CString sINFO);
	CFont Statusfont;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void On32771();
	BOOL KillProcessFromName(CString strProcessName);
	void clear(unsigned char *pta, int size );
	bool SaveTestLog(CString SN,int iErrCode);
	bool GetTestItem();
	bool GetComPort();
	bool ReadColumn(CString TableName,CString FieldName,CArray<CString,CString>&ReadData);
	CEdit m_EDIT_Log;
	afx_msg void OnBnClickedButtonSc();
	afx_msg void OnBnClickedButtonDc();
	void AUTOSIZEITEM();
	void AUTOSIZETABTOP();
	void HideAllWND();
	void HideAllItem();
	void BUTStyle();
	afx_msg void OnBnClickedButtonPrr();
	afx_msg void OnBnClickedButtonAs();
	afx_msg void OnBnClickedButtonIa();
	afx_msg void OnBnClickedButtonIds();
	afx_msg void OnBnClickedButtonOs();
	afx_msg void OnBnClickedMfcbuttonEtm();
	CMFCButton m_MFCBUTTON_ETM;
	afx_msg void OnSize(UINT nType, int cx, int cy);
    //void ChangeSize(UINT nID, int x, int y);
	afx_msg void OnBnClickedMfcbuttonBsi();
	CMFCButton m_MFCBUTTON_BSI;
	CMFCButton m_MFCBUTTON_BRSI;
	CMFCButton m_MFCBUTTON_QSS;
	CMFCButton m_MFCBUTTON_DCgc;
	afx_msg void OnBnClickedMfcbuttonBsri();
	afx_msg void OnBnClickedMfcbuttonQss();
	afx_msg void OnBnClickedMfcbuttonDcgc();
	CMFCButton m_MFCBUTTON_DCap;
	CMFCButton m_MFCBUTTON_DCspw;
	CMFCButton m_MFCBUTTON_DCowh;
	CMFCButton m_MFCBUTTON_DCta;
	CMFCButton m_MFCBUTTON_DCpsdls;
	CMFCButton m_MFCBUTTON_DChrm;
	CMFCButton m_MFCBUTTON_DCpcs;
	afx_msg void OnBnClickedMfcbuttonDcap();
	afx_msg void OnBnClickedMfcbuttonDcspw();
	afx_msg void OnBnClickedMfcbuttonDcowh();
	afx_msg void OnBnClickedMfcbuttonDcta();
	afx_msg void OnBnClickedMfcbuttonDcpsdls();
	afx_msg void OnBnClickedMfcbuttonDchrm();
	afx_msg void OnBnClickedMfcbuttonDcpcs();
	CMFCButton m_MFCBUTTON_PRRfri;
	CMFCButton m_MFCBUTTON_PRRfcofri;
	afx_msg void OnBnClickedMfcbuttonPrrfri();
	afx_msg void OnBnClickedMfcbuttonPrrfcofri();
	CMFCButton m_MFCBUTTON_ASgc;
	CMFCButton m_MFCBUTTON_AStac;
	CMFCButton m_MFCBUTTON_ASsa;
	CMFCButton m_MFCBUTTON_ASsosa;
	CMFCButton m_MFCBUTTON_ASeid;
	CMFCButton m_MFCBUTTON_AShbm;
	CMFCButton m_MFCBUTTON_ASssr;
	CMFCButton m_MFCBUTTON_ASbad;
	CMFCButton m_MFCBUTTON_ASosa;
	CMFCButton m_MFCBUTTON_ASpg;
	CMFCButton m_MFCBUTTON_ASrdc;
	CMFCButton m_MFCBUTTON_ASsadr;
	CMFCButton m_MFCBUTTON_ASser;
	CMFCButton m_MFCBUTTON_AScd;
	afx_msg void OnBnClickedMfcbuttonAsgc();
	afx_msg void OnBnClickedMfcbuttonAstac();
	afx_msg void OnBnClickedMfcbuttonAssa();
	afx_msg void OnBnClickedMfcbuttonAssosa();
	afx_msg void OnBnClickedMfcbuttonAseid();
	afx_msg void OnBnClickedMfcbuttonAshbm();
	afx_msg void OnBnClickedMfcbuttonAsssr();
	afx_msg void OnBnClickedMfcbuttonAsbad();
	afx_msg void OnBnClickedMfcbuttonAsosa();
	afx_msg void OnBnClickedMfcbuttonAspg();
	afx_msg void OnBnClickedMfcbuttonAsrdc();
	afx_msg void OnBnClickedMfcbuttonAssadr();
	afx_msg void OnBnClickedMfcbuttonAsser();
	afx_msg void OnBnClickedMfcbuttonAscd();
	CStatic m_Static_Item;
	CMFCButton m_MFCBUTTON_IAdops;
	CMFCButton m_MFCBUTTON_IAepsm;
	CMFCButton m_MFCBUTTON_IAdips;
	CMFCButton m_MFCBUTTON_IAips;
	afx_msg void OnBnClickedMfcbuttonIadops();
	afx_msg void OnBnClickedMfcbuttonIaepsm();
	afx_msg void OnBnClickedMfcbuttonIadips();
	afx_msg void OnBnClickedMfcbuttonIaips();
	afx_msg void OnBnClickedMfcbuttonIdsvims();
	afx_msg void OnBnClickedMfcbuttonIdsidbvs();
	afx_msg void OnBnClickedMfcbuttonIdsavis();
	CMFCButton m_MFCBUTTON_IDSvims;
	CMFCButton m_MFCBUTTON_IDSidbvs;
	CMFCButton m_MFCBUTTON_IDSavis;
	CMFCButton m_MFCBUTTON_OSrto;
	CMFCButton m_MFCBUTTON_OShmc;
	CMFCButton m_MFCBUTTON_OSwl;
	CMFCButton m_MFCBUTTON_OSglsc;
	CMFCButton m_MFCBUTTON_OSucota;
	CMFCButton m_MFCBUTTON_OScss;
	CMFCButton m_MFCBUTTON_OSudf;
	CMFCButton m_MFCBUTTON_OSgs;
	CMFCButton m_MFCBUTTON_OSer;
	afx_msg void OnBnClickedMfcbuttonOsrto();
	afx_msg void OnBnClickedMfcbuttonOshmc();
	afx_msg void OnBnClickedMfcbuttonOswl();
	afx_msg void OnBnClickedMfcbuttonOsglsc();
	afx_msg void OnBnClickedMfcbuttonOsucota();
	afx_msg void OnBnClickedMfcbuttonOscss();
	afx_msg void OnBnClickedMfcbuttonOsudf();
	afx_msg void OnBnClickedMfcbuttonOsgs();
	afx_msg void OnBnClickedMfcbuttonOser();
	afx_msg void OnBnClickedMfcbuttonOl();
	CMFCButton m_MFCBUTTON_OL;
	CMFCButton m_MFCBUTTON_SC;
	CMFCButton m_MFCBUTTON_DC;
	CMFCButton m_MFCBUTTON_PRR;
	CMFCButton m_MFCBUTTON_AS;
	CMFCButton m_MFCBUTTON_IA;
	CMFCButton m_MFCBUTTON_IDS;
	CMFCButton m_MFCBUTTON_OS;
	CMFCButton m_MFCBUTTON_SAC;
	CMFCButton m_MFCBUTTON_SaveAC;
	afx_msg void OnBnClickedMfcmenubuttonRac();
	CMFCMenuButton m_Menubutton_RAC;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CList<CRect,CRect&> m_listRect;
	void KeepIniSize();
	void CheckPicture();
	void KeyPicShow();
	afx_msg void OnBnClickedMfcbuttonSac();
	CStatic m_Static_Logo;
	afx_msg void OnBnClickedMfcbuttonSaveac();
};
