// DChrm_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "DChrm_Dlg.h"
#include "afxdialogex.h"
///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"
// DCap_Dlg 对话框
extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern DChrm_Dlg m_DChrm_Dlg;
DChrm_Dlg*	lpDChrm_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
////////////



IMPLEMENT_DYNAMIC(DChrm_Dlg, CMyTabBaseDlg)

DChrm_Dlg::DChrm_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(DChrm_Dlg::IDD, pParent)
{

}

DChrm_Dlg::~DChrm_Dlg()
{
}

void DChrm_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_Lth, m_Check_Lth);
	DDX_Control(pDX, IDC_CHECK_DT, m_Check_DT);
	DDX_Control(pDX, IDC_CHECK_PV, m_Check_PV);
	DDX_Control(pDX, IDC_CHECK_FV, m_Check_FV);
	DDX_Control(pDX, IDC_CHECK_DN, m_Check_DN);
	DDX_Control(pDX, IDC_CHECKST, m_Check_ST);
	DDX_Control(pDX, IDC_CHECK_CN, m_Check_CN);
	DDX_Control(pDX, IDC_CHECK_Res, m_Check_Res);
	DDX_Control(pDX, IDC_CHECK_Lth2, m_Check_Lth2);
	DDX_Control(pDX, IDC_CHECK_DT2, m_Check_DT2);
	DDX_Control(pDX, IDC_CHECK_PV2, m_Check_PV2);
	DDX_Control(pDX, IDC_CHECK_FV2, m_Check_FV2);
	DDX_Control(pDX, IDC_CHECK_DN2, m_Check_DN2);
	DDX_Control(pDX, IDC_CHECK_CN2, m_Check_CN2);
	DDX_Control(pDX, IDC_CHECK_UID, m_Check_UID);
	DDX_Control(pDX, IDC_CHECK_ST2, m_Check_ST2);
	DDX_Control(pDX, IDC_CHECK_Sed3, m_Check_Sed3);
	DDX_Control(pDX, IDC_CHECK_Azi3, m_Check_Azi3);
	DDX_Control(pDX, IDC_CHECK_Alt3, m_Check_Alt3);
	DDX_Control(pDX, IDC_CHECK_ND3, m_Check_ND3);
	DDX_Control(pDX, IDC_CHECK_ST3, m_Check_ST3);
	DDX_Control(pDX, IDC_CHECK_CN3, m_Check_CN3);
	DDX_Control(pDX, IDC_CHECK_DN3, m_Check_DN3);
	DDX_Control(pDX, IDC_CHECK_PV3, m_Check_PV3);
	DDX_Control(pDX, IDC_CHECK_FV3, m_Check_FV3);
	DDX_Control(pDX, IDC_CHECK_BL3, m_Check_BL3);
	DDX_Control(pDX, IDC_CHECK_EPSV3, m_Check_EPSV3);
	DDX_Control(pDX, IDC_CHECK_IM3, m_Check_IM3);
	DDX_Control(pDX, IDC_CHECK_Res31, m_Check_Res31);
	DDX_Control(pDX, IDC_CHECK_Res32, m_Check_Res32);
	DDX_Control(pDX, IDC_CHECK_Res33, m_Check_Res33);
	DDX_Control(pDX, IDC_CHECK_DIS3, m_Check_DIS3);
	DDX_Control(pDX, IDC_CHECK_MS3, m_Check_MS3);
	DDX_Control(pDX, IDC_CHECK_GSI3, m_Check_GSI3);
	DDX_Control(pDX, IDC_CHECK_CM3, m_Check_CM3);
	DDX_Control(pDX, IDC_CHECK_TM3, m_Check_TM3);
	DDX_Control(pDX, IDC_CHECK_CHMC3, m_Check_CHMC3);
	DDX_Control(pDX, IDC_CHECK_THMC3, m_Check_THMC3);
	DDX_Control(pDX, IDC_CHECK_Res34, m_Check_Res34);
	DDX_Control(pDX, IDC_CHECK_Res35, m_Check_Res35);
	DDX_Control(pDX, IDC_CHECK_Res36, m_Check_Res36);
	DDX_Control(pDX, IDC_CHECK_Res37, m_Check_Res37);
	DDX_Control(pDX, IDC_CHECK_Res38, m_Check_Res38);
	DDX_Control(pDX, IDC_CHECK_Res39, m_Check_Res39);
	DDX_Control(pDX, IDC_CHECK_Res3a, m_Check_Res3a);
	DDX_Control(pDX, IDC_CHECK_Res3b, m_Check_Res3b);
	DDX_Control(pDX, IDC_CHECK_CA3, m_Check_CA3);
	DDX_Control(pDX, IDC_CHECK_Lth3, m_Check_Lth3);
	DDX_Control(pDX, IDC_CHECK_DT3, m_Check_DT3);
	DDX_Control(pDX, IDC_CHECK_Sed4, m_Check_Sed4);
	DDX_Control(pDX, IDC_CHECK_Azi4, m_Check_Azi4);
	DDX_Control(pDX, IDC_CHECK_Alt4, m_Check_Alt4);
	DDX_Control(pDX, IDC_CHECK_ND4, m_Check_ND4);
	DDX_Control(pDX, IDC_CHECK_ST4, m_Check_ST4);
	DDX_Control(pDX, IDC_CHECK_CN4, m_Check_CN4);
	DDX_Control(pDX, IDC_CHECK_DN4, m_Check_DN4);
	DDX_Control(pDX, IDC_CHECK_Lth4, m_Check_Lth4);
	DDX_Control(pDX, IDC_CHECK_DT4, m_Check_DT4);
	DDX_Control(pDX, IDC_CHECK_PV4, m_Check_PV4);
	DDX_Control(pDX, IDC_CHECK_FV4, m_Check_FV4);
	DDX_Control(pDX, IDC_CHECK_BL4, m_Check_BL4);
	DDX_Control(pDX, IDC_CHECK_EPSV4, m_Check_EPSV4);
	DDX_Control(pDX, IDC_CHECK_IM4, m_Check_IM4);
	DDX_Control(pDX, IDC_CHECK_Res41, m_Check_Res41);
	DDX_Control(pDX, IDC_CHECK_Res42, m_Check_Res42);
	DDX_Control(pDX, IDC_CHECK_Res43, m_Check_Res43);
	DDX_Control(pDX, IDC_CHECK_DIS4, m_Check_DIS4);
	DDX_Control(pDX, IDC_CHECK_MS4, m_Check_MS4);
	DDX_Control(pDX, IDC_CHECK_GSI4, m_Check_GSI4);
	DDX_Control(pDX, IDC_CHECK_CM4, m_Check_CM4);
	DDX_Control(pDX, IDC_CHECK_TM4, m_Check_TM4);
	DDX_Control(pDX, IDC_CHECK_CHMC4, m_Check_CHMC4);
	DDX_Control(pDX, IDC_CHECK_THMC4, m_Check_THMC4);
	DDX_Control(pDX, IDC_CHECK_Res44, m_Check_Res44);
	DDX_Control(pDX, IDC_CHECK_Res45, m_Check_Res45);
	DDX_Control(pDX, IDC_CHECK_Res46, m_Check_Res46);
	DDX_Control(pDX, IDC_CHECK_Res47, m_Check_Res47);
	DDX_Control(pDX, IDC_CHECK_Res48, m_Check_Res48);
	DDX_Control(pDX, IDC_CHECK_Res49, m_Check_Res49);
	DDX_Control(pDX, IDC_CHECK_Res4a, m_Check_Res4a);
	DDX_Control(pDX, IDC_CHECK_Res4b, m_Check_Res4b);
	DDX_Control(pDX, IDC_CHECK_CA4, m_Check_CA4);
	DDX_Control(pDX, IDC_CHECK_Lth5, m_Check_Lth5);
	DDX_Control(pDX, IDC_CHECK_DN5, m_Check_DN5);
	DDX_Control(pDX, IDC_CHECK_DT5, m_Check_DT5);
	DDX_Control(pDX, IDC_CHECK_PV5, m_Check_PV5);
	DDX_Control(pDX, IDC_CHECK_FV5, m_Check_FV5);
	DDX_Control(pDX, IDC_CHECK_ST5, m_Check_ST5);
	DDX_Control(pDX, IDC_CHECK_CN5, m_Check_CN5);
	DDX_Control(pDX, IDC_CHECK_EIM5, m_Check_EIM5);
	DDX_Control(pDX, IDC_CHECK_VER5, m_Check_VER5);
	DDX_Control(pDX, IDC_CHECK_IOS5, m_Check_IOS5);
	DDX_Control(pDX, IDC_CHECK_GPS5, m_Check_GPS5);
	DDX_Control(pDX, IDC_CHECK_BAT5, m_Check_BAT5);
	DDX_Control(pDX, IDC_CHECK_CID5, m_Check_CID5);
	DDX_Control(pDX, IDC_CHECK_CSQ5, m_Check_CSQ5);
	DDX_Control(pDX, IDC_CHECK_TMZ5, m_Check_TMZ5);
	DDX_Control(pDX, IDC_CHECK_Res5, m_Check_Res5);
	DDX_Control(pDX, IDC_CHECK_CA5, m_Check_CA5);
	DDX_Control(pDX, IDC_CHECK_Lth6, m_Check_Lth6);
	DDX_Control(pDX, IDC_CHECK_DN6, m_Check_DN6);
	DDX_Control(pDX, IDC_CHECK_DT6, m_Check_DT6);
	DDX_Control(pDX, IDC_CHECK_PV6, m_Check_PV6);
	DDX_Control(pDX, IDC_CHECK_FV6, m_Check_FV6);
	DDX_Control(pDX, IDC_CHECK_CN6, m_Check_CN6);
	DDX_Control(pDX, IDC_CHECK_Res61, m_Check_Res61);
	DDX_Control(pDX, IDC_CHECK_Res62, m_Check_Res62);
	DDX_Control(pDX, IDC_CHECK_Res63, m_Check_Res63);
	DDX_Control(pDX, IDC_CHECK_Res64, m_Check_Res64);
	DDX_Control(pDX, IDC_CHECK_Res65, m_Check_Res65);
	DDX_Control(pDX, IDC_CHECK_Res66, m_Check_Res66);
	DDX_Control(pDX, IDC_CHECK_Res67, m_Check_Res67);
	DDX_Control(pDX, IDC_CHECK_Res68, m_Check_Res68);
	DDX_Control(pDX, IDC_CHECK_Res69, m_Check_Res69);
	DDX_Control(pDX, IDC_CHECK_CA6, m_Check_CA6);
	DDX_Control(pDX, IDC_CHECK_ST6, m_Check_ST6);
	DDX_Control(pDX, IDC_CHECK_Lth7, m_Check_Lth7);
	DDX_Control(pDX, IDC_CHECK_DT7, m_Check_DT7);
	DDX_Control(pDX, IDC_CHECK_PV7, m_Check_PV7);
	DDX_Control(pDX, IDC_CHECK_FV7, m_Check_FV7);
	DDX_Control(pDX, IDC_CHECK_DN7, m_Check_DN7);
	DDX_Control(pDX, IDC_CHECK_ST7, m_Check_ST7);
	DDX_Control(pDX, IDC_CHECK_CN7, m_Check_CN7);
	DDX_Control(pDX, IDC_CHECK_CA7, m_Check_CA7);
}


BEGIN_MESSAGE_MAP(DChrm_Dlg, CMyTabBaseDlg)
	ON_BN_CLICKED(IDC_CHECK_Lth, &DChrm_Dlg::OnBnClickedCheckLth)
	ON_BN_CLICKED(IDC_CHECK_DT, &DChrm_Dlg::OnBnClickedCheckDt)
	ON_BN_CLICKED(IDC_CHECK_PV, &DChrm_Dlg::OnBnClickedCheckPv)
	ON_BN_CLICKED(IDC_CHECK_FV, &DChrm_Dlg::OnBnClickedCheckFv)
	ON_BN_CLICKED(IDC_CHECK_DN, &DChrm_Dlg::OnBnClickedCheckDn)
	ON_BN_CLICKED(IDC_CHECKST, &DChrm_Dlg::OnBnClickedCheckst)
	ON_BN_CLICKED(IDC_CHECK_CN, &DChrm_Dlg::OnBnClickedCheckCn)
	ON_BN_CLICKED(IDC_CHECK_Res, &DChrm_Dlg::OnBnClickedCheckRes)
	ON_BN_CLICKED(IDC_CHECK_Lth2, &DChrm_Dlg::OnBnClickedCheckLth2)
	ON_BN_CLICKED(IDC_CHECK_DT2, &DChrm_Dlg::OnBnClickedCheckDt2)
	ON_BN_CLICKED(IDC_CHECK_PV2, &DChrm_Dlg::OnBnClickedCheckPv2)
	ON_BN_CLICKED(IDC_CHECK_FV2, &DChrm_Dlg::OnBnClickedCheckFv2)
	ON_BN_CLICKED(IDC_CHECK_DN2, &DChrm_Dlg::OnBnClickedCheckDn2)
	ON_BN_CLICKED(IDC_CHECK_ST2, &DChrm_Dlg::OnBnClickedCheckSt2)
	ON_BN_CLICKED(IDC_CHECK_CN2, &DChrm_Dlg::OnBnClickedCheckCn2)
	ON_BN_CLICKED(IDC_CHECK_UID, &DChrm_Dlg::OnBnClickedCheckUid)
	ON_BN_CLICKED(IDC_CHECK_Sed3, &DChrm_Dlg::OnBnClickedCheckSed3)
	ON_BN_CLICKED(IDC_CHECK_CA3, &DChrm_Dlg::OnBnClickedCheckCa3)
	ON_BN_CLICKED(IDC_CHECK_Azi3, &DChrm_Dlg::OnBnClickedCheckAzi3)
	ON_BN_CLICKED(IDC_CHECK_Alt3, &DChrm_Dlg::OnBnClickedCheckAlt3)
	ON_BN_CLICKED(IDC_CHECK_ND3, &DChrm_Dlg::OnBnClickedCheckNd3)
	ON_BN_CLICKED(IDC_CHECK_ST3, &DChrm_Dlg::OnBnClickedCheckSt3)
	ON_BN_CLICKED(IDC_CHECK_CN3, &DChrm_Dlg::OnBnClickedCheckCn3)
	ON_BN_CLICKED(IDC_CHECK_DN3, &DChrm_Dlg::OnBnClickedCheckDn3)
	ON_BN_CLICKED(IDC_CHECK_Lth3, &DChrm_Dlg::OnBnClickedCheckLth3)
	ON_BN_CLICKED(IDC_CHECK_DT3, &DChrm_Dlg::OnBnClickedCheckDt3)
	ON_BN_CLICKED(IDC_CHECK_PV3, &DChrm_Dlg::OnBnClickedCheckPv3)
	ON_BN_CLICKED(IDC_CHECK_FV3, &DChrm_Dlg::OnBnClickedCheckFv3)
	ON_BN_CLICKED(IDC_CHECK_BL3, &DChrm_Dlg::OnBnClickedCheckBl3)
	ON_BN_CLICKED(IDC_CHECK_EPSV3, &DChrm_Dlg::OnBnClickedCheckEpsv3)
	ON_BN_CLICKED(IDC_CHECK_IM3, &DChrm_Dlg::OnBnClickedCheckIm3)
	ON_BN_CLICKED(IDC_CHECK_Res31, &DChrm_Dlg::OnBnClickedCheckRes31)
	ON_BN_CLICKED(IDC_CHECK_Res32, &DChrm_Dlg::OnBnClickedCheckRes32)
	ON_BN_CLICKED(IDC_CHECK_Res33, &DChrm_Dlg::OnBnClickedCheckRes33)
	ON_BN_CLICKED(IDC_CHECK_DIS3, &DChrm_Dlg::OnBnClickedCheckDis3)
	ON_BN_CLICKED(IDC_CHECK_MS3, &DChrm_Dlg::OnBnClickedCheckMs3)
	ON_BN_CLICKED(IDC_CHECK_GSI3, &DChrm_Dlg::OnBnClickedCheckGsi3)
	ON_BN_CLICKED(IDC_CHECK_CM3, &DChrm_Dlg::OnBnClickedCheckCm3)
	ON_BN_CLICKED(IDC_CHECK_TM3, &DChrm_Dlg::OnBnClickedCheckTm3)
	ON_BN_CLICKED(IDC_CHECK_CHMC3, &DChrm_Dlg::OnBnClickedCheckChmc3)
	ON_BN_CLICKED(IDC_CHECK_THMC3, &DChrm_Dlg::OnBnClickedCheckThmc3)
	ON_BN_CLICKED(IDC_CHECK_Res34, &DChrm_Dlg::OnBnClickedCheckRes34)
	ON_BN_CLICKED(IDC_CHECK_Res35, &DChrm_Dlg::OnBnClickedCheckRes35)
	ON_BN_CLICKED(IDC_CHECK_Res36, &DChrm_Dlg::OnBnClickedCheckRes36)
	ON_BN_CLICKED(IDC_CHECK_Res37, &DChrm_Dlg::OnBnClickedCheckRes37)
	ON_BN_CLICKED(IDC_CHECK_Res38, &DChrm_Dlg::OnBnClickedCheckRes38)
	ON_BN_CLICKED(IDC_CHECK_Res39, &DChrm_Dlg::OnBnClickedCheckRes39)
	ON_BN_CLICKED(IDC_CHECK_Res3a, &DChrm_Dlg::OnBnClickedCheckRes3a)
	ON_BN_CLICKED(IDC_CHECK_Res3b, &DChrm_Dlg::OnBnClickedCheckRes3b)
	ON_BN_CLICKED(IDC_CHECK_Sed4, &DChrm_Dlg::OnBnClickedCheckSed4)
	ON_BN_CLICKED(IDC_CHECK_Azi4, &DChrm_Dlg::OnBnClickedCheckAzi4)
	ON_BN_CLICKED(IDC_CHECK_Alt4, &DChrm_Dlg::OnBnClickedCheckAlt4)
	ON_BN_CLICKED(IDC_CHECK_ND4, &DChrm_Dlg::OnBnClickedCheckNd4)
	ON_BN_CLICKED(IDC_CHECK_ST4, &DChrm_Dlg::OnBnClickedCheckSt4)
	ON_BN_CLICKED(IDC_CHECK_CN4, &DChrm_Dlg::OnBnClickedCheckCn4)
	ON_BN_CLICKED(IDC_CHECK_DN4, &DChrm_Dlg::OnBnClickedCheckDn4)
	ON_BN_CLICKED(IDC_CHECK_Lth4, &DChrm_Dlg::OnBnClickedCheckLth4)
	ON_BN_CLICKED(IDC_CHECK_DT4, &DChrm_Dlg::OnBnClickedCheckDt4)
	ON_BN_CLICKED(IDC_CHECK_PV4, &DChrm_Dlg::OnBnClickedCheckPv4)
	ON_BN_CLICKED(IDC_CHECK_FV4, &DChrm_Dlg::OnBnClickedCheckFv4)
	ON_BN_CLICKED(IDC_CHECK_BL4, &DChrm_Dlg::OnBnClickedCheckBl4)
	ON_BN_CLICKED(IDC_CHECK_EPSV4, &DChrm_Dlg::OnBnClickedCheckEpsv4)
	ON_BN_CLICKED(IDC_CHECK_IM4, &DChrm_Dlg::OnBnClickedCheckIm4)
	ON_BN_CLICKED(IDC_CHECK_Res41, &DChrm_Dlg::OnBnClickedCheckRes41)
	ON_BN_CLICKED(IDC_CHECK_Res42, &DChrm_Dlg::OnBnClickedCheckRes42)
	ON_BN_CLICKED(IDC_CHECK_Res43, &DChrm_Dlg::OnBnClickedCheckRes43)
	ON_BN_CLICKED(IDC_CHECK_DIS4, &DChrm_Dlg::OnBnClickedCheckDis4)
	ON_BN_CLICKED(IDC_CHECK_MS4, &DChrm_Dlg::OnBnClickedCheckMs4)
	ON_BN_CLICKED(IDC_CHECK_GSI4, &DChrm_Dlg::OnBnClickedCheckGsi4)
	ON_BN_CLICKED(IDC_CHECK_CM4, &DChrm_Dlg::OnBnClickedCheckCm4)
	ON_BN_CLICKED(IDC_CHECK_TM4, &DChrm_Dlg::OnBnClickedCheckTm4)
	ON_BN_CLICKED(IDC_CHECK_CHMC4, &DChrm_Dlg::OnBnClickedCheckChmc4)
	ON_BN_CLICKED(IDC_CHECK_THMC4, &DChrm_Dlg::OnBnClickedCheckThmc4)
	ON_BN_CLICKED(IDC_CHECK_Res44, &DChrm_Dlg::OnBnClickedCheckRes44)
	ON_BN_CLICKED(IDC_CHECK_Res45, &DChrm_Dlg::OnBnClickedCheckRes45)
	ON_BN_CLICKED(IDC_CHECK_Res46, &DChrm_Dlg::OnBnClickedCheckRes46)
	ON_BN_CLICKED(IDC_CHECK_Res47, &DChrm_Dlg::OnBnClickedCheckRes47)
	ON_BN_CLICKED(IDC_CHECK_Res48, &DChrm_Dlg::OnBnClickedCheckRes48)
	ON_BN_CLICKED(IDC_CHECK_Res49, &DChrm_Dlg::OnBnClickedCheckRes49)
	ON_BN_CLICKED(IDC_CHECK_Res4a, &DChrm_Dlg::OnBnClickedCheckRes4a)
	ON_BN_CLICKED(IDC_CHECK_Res4b, &DChrm_Dlg::OnBnClickedCheckRes4b)
	ON_BN_CLICKED(IDC_CHECK_CA4, &DChrm_Dlg::OnBnClickedCheckCa4)
	ON_BN_CLICKED(IDC_CHECK_Lth5, &DChrm_Dlg::OnBnClickedCheckLth5)
	ON_BN_CLICKED(IDC_CHECK_DN5, &DChrm_Dlg::OnBnClickedCheckDn5)
	ON_BN_CLICKED(IDC_CHECK_DT5, &DChrm_Dlg::OnBnClickedCheckDt5)
	ON_BN_CLICKED(IDC_CHECK_PV5, &DChrm_Dlg::OnBnClickedCheckPv5)
	ON_BN_CLICKED(IDC_CHECK_FV5, &DChrm_Dlg::OnBnClickedCheckFv5)
	ON_BN_CLICKED(IDC_CHECK_ST5, &DChrm_Dlg::OnBnClickedCheckSt5)
	ON_BN_CLICKED(IDC_CHECK_CN5, &DChrm_Dlg::OnBnClickedCheckCn5)
	ON_BN_CLICKED(IDC_CHECK_EIM5, &DChrm_Dlg::OnBnClickedCheckEim5)
	ON_BN_CLICKED(IDC_CHECK_VER5, &DChrm_Dlg::OnBnClickedCheckVer5)
	ON_BN_CLICKED(IDC_CHECK_IOS5, &DChrm_Dlg::OnBnClickedCheckIos5)
	ON_BN_CLICKED(IDC_CHECK_GPS5, &DChrm_Dlg::OnBnClickedCheckGps5)
	ON_BN_CLICKED(IDC_CHECK_BAT5, &DChrm_Dlg::OnBnClickedCheckBat5)
	ON_BN_CLICKED(IDC_CHECK_CID5, &DChrm_Dlg::OnBnClickedCheckCid5)
	ON_BN_CLICKED(IDC_CHECK_CSQ5, &DChrm_Dlg::OnBnClickedCheckCsq5)
	ON_BN_CLICKED(IDC_CHECK_TMZ5, &DChrm_Dlg::OnBnClickedCheckTmz5)
	ON_BN_CLICKED(IDC_CHECK_Res5, &DChrm_Dlg::OnBnClickedCheckRes5)
	ON_BN_CLICKED(IDC_CHECK_CA5, &DChrm_Dlg::OnBnClickedCheckCa5)
	ON_BN_CLICKED(IDC_CHECK_Lth6, &DChrm_Dlg::OnBnClickedCheckLth6)
	ON_BN_CLICKED(IDC_CHECK_DN6, &DChrm_Dlg::OnBnClickedCheckDn6)
	ON_BN_CLICKED(IDC_CHECK_DT6, &DChrm_Dlg::OnBnClickedCheckDt6)
	ON_BN_CLICKED(IDC_CHECK_PV6, &DChrm_Dlg::OnBnClickedCheckPv6)
	ON_BN_CLICKED(IDC_CHECK_FV6, &DChrm_Dlg::OnBnClickedCheckFv6)
	ON_BN_CLICKED(IDC_CHECK_ST6, &DChrm_Dlg::OnBnClickedCheckSt6)
	ON_BN_CLICKED(IDC_CHECK_CN6, &DChrm_Dlg::OnBnClickedCheckCn6)
	ON_BN_CLICKED(IDC_CHECK_Res62, &DChrm_Dlg::OnBnClickedCheckRes62)
	ON_BN_CLICKED(IDC_CHECK_Res61, &DChrm_Dlg::OnBnClickedCheckRes61)
	ON_BN_CLICKED(IDC_CHECK_Res63, &DChrm_Dlg::OnBnClickedCheckRes63)
	ON_BN_CLICKED(IDC_CHECK_Res64, &DChrm_Dlg::OnBnClickedCheckRes64)
	ON_BN_CLICKED(IDC_CHECK_Res65, &DChrm_Dlg::OnBnClickedCheckRes65)
	ON_BN_CLICKED(IDC_CHECK_Res66, &DChrm_Dlg::OnBnClickedCheckRes66)
	ON_BN_CLICKED(IDC_CHECK_Res67, &DChrm_Dlg::OnBnClickedCheckRes67)
	ON_BN_CLICKED(IDC_CHECK_Res68, &DChrm_Dlg::OnBnClickedCheckRes68)
	ON_BN_CLICKED(IDC_CHECK_Res69, &DChrm_Dlg::OnBnClickedCheckRes69)
	ON_BN_CLICKED(IDC_CHECK_CA6, &DChrm_Dlg::OnBnClickedCheckCa6)
	ON_BN_CLICKED(IDC_CHECK_Lth7, &DChrm_Dlg::OnBnClickedCheckLth7)
	ON_BN_CLICKED(IDC_CHECK_DT7, &DChrm_Dlg::OnBnClickedCheckDt7)
	ON_BN_CLICKED(IDC_CHECK_PV7, &DChrm_Dlg::OnBnClickedCheckPv7)
	ON_BN_CLICKED(IDC_CHECK_FV7, &DChrm_Dlg::OnBnClickedCheckFv7)
	ON_BN_CLICKED(IDC_CHECK_DN7, &DChrm_Dlg::OnBnClickedCheckDn7)
	ON_BN_CLICKED(IDC_CHECK_ST7, &DChrm_Dlg::OnBnClickedCheckSt7)
	ON_BN_CLICKED(IDC_CHECK_CN7, &DChrm_Dlg::OnBnClickedCheckCn7)
	ON_BN_CLICKED(IDC_CHECK_CA7, &DChrm_Dlg::OnBnClickedCheckCa7)
	END_MESSAGE_MAP()

// DChrm_Dlg 消息处理程序


BOOL DChrm_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lpDChrm_Dlg=&m_DChrm_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_DChrm_Dlg;
	m_iWhoamI=GTHRM;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[GTHRM].sCmdstr);
	                             //AT+GTHRM=HYIoT,,,7F,FEFFFF,FEFFFF,2F7F,FF,7F,7F,,,0018$
	////
	m_Check_Lth.SetCheck(1);
	m_Check_DT.SetCheck(1);
	m_Check_PV.SetCheck(1);
	m_Check_FV.SetCheck(1);
	m_Check_DN.SetCheck(1);
	m_Check_ST.SetCheck(1);
	m_Check_CN.SetCheck(1);
	m_Check_Res.SetCheck(1);
	//
	m_Check_Sed3	.SetCheck(1);
	m_Check_Azi3	.SetCheck(1);
	m_Check_Alt3	.SetCheck(1);
	m_Check_ND3	.SetCheck(1);
	m_Check_ST3	.SetCheck(1);
	m_Check_CN3	.SetCheck(1);
	m_Check_DN3	.SetCheck(1);
	m_Check_PV3	.SetCheck(1);
	m_Check_FV3	.SetCheck(1);
	m_Check_BL3	.SetCheck(1);
	m_Check_EPSV3	.SetCheck(1);
	m_Check_IM3	.SetCheck(1);
	m_Check_Res31	.SetCheck(0);
	m_Check_Res32	.SetCheck(0);
	m_Check_Res33	.SetCheck(0);
	m_Check_DIS3	.SetCheck(1);
	m_Check_MS3	.SetCheck(1);
	m_Check_GSI3	.SetCheck(1);
	m_Check_CM3	.SetCheck(1);
	m_Check_TM3	.SetCheck(1);
	m_Check_CHMC3	.SetCheck(1);
	m_Check_THMC3	.SetCheck(1);
	m_Check_Res34	.SetCheck(0);
	m_Check_Res35	.SetCheck(0);
	m_Check_Res36	.SetCheck(0);
	m_Check_Res37	.SetCheck(0);
	m_Check_Res38	.SetCheck(0);
	m_Check_Res39	.SetCheck(0);
	m_Check_Res3a	.SetCheck(0);
	m_Check_Res3b	.SetCheck(0);
	m_Check_Lth3.SetCheck(1);
	m_Check_DT3.SetCheck(1);
	//
	m_Check_Sed4	.SetCheck(1);
	m_Check_Azi4	.SetCheck(1);
	m_Check_Alt4	.SetCheck(1);
	m_Check_ND4	.SetCheck(1);
	m_Check_ST4	.SetCheck(1);
	m_Check_CN4	.SetCheck(1);
	m_Check_DN4	.SetCheck(1);
	m_Check_PV4	.SetCheck(1);
	m_Check_FV4	.SetCheck(1);
	m_Check_BL4	.SetCheck(1);
	m_Check_EPSV4	.SetCheck(1);
	m_Check_IM4	.SetCheck(1);
	m_Check_Res41	.SetCheck(0);
	m_Check_Res42	.SetCheck(0);
	m_Check_Res43	.SetCheck(0);
	m_Check_DIS4	.SetCheck(1);
	m_Check_MS4	.SetCheck(1);
	m_Check_GSI4	.SetCheck(1);
	m_Check_CM4	.SetCheck(1);
	m_Check_TM4	.SetCheck(1);
	m_Check_CHMC4	.SetCheck(1);
	m_Check_THMC4	.SetCheck(1);
	m_Check_Res44	.SetCheck(0);
	m_Check_Res45	.SetCheck(0);
	m_Check_Res46	.SetCheck(0);
	m_Check_Res47	.SetCheck(0);
	m_Check_Res48	.SetCheck(0);
	m_Check_Res49	.SetCheck(0);
	m_Check_Res4a	.SetCheck(0);
	m_Check_Res4b	.SetCheck(0);
	m_Check_Lth4.SetCheck(1);
	m_Check_DT4.SetCheck(1);
	//
	m_Check_Lth5	.SetCheck(1);
	m_Check_DN5	.SetCheck(1);
	m_Check_DT5	.SetCheck(1);
	m_Check_PV5	.SetCheck(1);
	m_Check_FV5	.SetCheck(1);
	m_Check_ST5	.SetCheck(1);
	m_Check_CN5	.SetCheck(1);
	m_Check_EIM5	.SetCheck(0);
	m_Check_VER5	.SetCheck(1);
	m_Check_IOS5	.SetCheck(1);
	m_Check_GPS5	.SetCheck(1);
	m_Check_BAT5	.SetCheck(1);
	m_Check_CID5	.SetCheck(1);
	m_Check_CSQ5	.SetCheck(1);
	m_Check_TMZ5	.SetCheck(1);
	m_Check_Res5	.SetCheck(0);
	//
	m_Check_Lth6	.SetCheck(1);
	m_Check_DN6	.SetCheck(1);
	m_Check_DT6	.SetCheck(1);
	m_Check_PV6	.SetCheck(1);
	m_Check_FV6	.SetCheck(1);
	m_Check_ST6	.SetCheck(1);
	m_Check_CN6	.SetCheck(1);
	m_Check_Res61	.SetCheck(0);
	m_Check_Res62	.SetCheck(0);
	m_Check_Res63	.SetCheck(0);
	m_Check_Res64	.SetCheck(0);
	m_Check_Res65	.SetCheck(0);
	m_Check_Res66	.SetCheck(0);
	m_Check_Res67	.SetCheck(0);
	m_Check_Res68	.SetCheck(0);
	m_Check_Res69	.SetCheck(0);
	//
	m_Check_Lth7	.SetCheck(1);
	m_Check_DT7	.SetCheck(1);
	m_Check_PV7	.SetCheck(1);
	m_Check_FV7	.SetCheck(1);
	m_Check_DN7	.SetCheck(1);
	m_Check_ST7	.SetCheck(1);
	m_Check_CN7	.SetCheck(1);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString DChrm_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

BOOL DChrm_Dlg::UpdataPage(CString sStr)
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
	//m_Edit_APN.SetWindowText(ValueList.GetAt(1));
	//m_Edit_UserName.SetWindowText(ValueList.GetAt(2));
	//m_Edit_Password.SetWindowText(ValueList.GetAt(3));
	//m_Edit_BAPN.SetWindowText(ValueList.GetAt(4));
	//m_Edit_BUserName.SetWindowText(ValueList.GetAt(5));
	//m_Edit_BPassword.SetWindowText(ValueList.GetAt(6));
	return TRUE;
}

//4
void DChrm_Dlg::GetAMValue()
{
	int iB0=0,iB1=0,iB2=0,iB3=0,iB4=0,iB5=0,iB6=0,iB7=0;
	CString sStrB="",sStrH="",sCmd="",sNewCmd="";
	iB0=m_Check_Lth.GetCheck();
	iB1=m_Check_DT.GetCheck();
	iB2=m_Check_PV.GetCheck();
	iB3=m_Check_FV.GetCheck();
	iB4=m_Check_DN.GetCheck();
	iB5=m_Check_ST.GetCheck();
	iB6=m_Check_CN.GetCheck();
	iB7=m_Check_Res.GetCheck();
	sStrB.Format("%d%d%d%d%d%d%d",iB7,iB6,iB5,iB4,iB3,iB2,iB1,iB0);
	m_MYWORK.BsToHex2Bit(sStrB,sStrH);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStrH,3,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}
//5
void DChrm_Dlg::GetRMValue()
{
	int iB0=0,iB1=0,iB2=0,iB3=0,iB4=0,iB5=0,iB6=0,iB7=0;
	int iB8=0,iB9=0,iB10=0,iB11=0,iB12=0,iB13=0,iB14=0,iB15=0;
	int iB16=0,iB17=0,iB18=0,iB19=0,iB20=0,iB21=0,iB22=0,iB23=0;
	int iB24=0,iB25=0,iB26=0,iB27=0,iB28=0,iB29=0,iB30=0,iB31=0;
	CString sStrB="",sStrH="",sCmd="",sNewCmd="";
	iB0=m_Check_Sed3.GetCheck();
	iB1=m_Check_Azi3.GetCheck();
	iB2=m_Check_Alt3.GetCheck();
	iB3=m_Check_ND3.GetCheck();
	iB4=m_Check_ST3.GetCheck();
	iB5=m_Check_CN3.GetCheck();
	iB6=m_Check_DN3.GetCheck();
	iB7=m_Check_Lth3.GetCheck();
	iB8=m_Check_DT3.GetCheck();
	iB9=m_Check_PV3.GetCheck();
	iB10=m_Check_FV3.GetCheck();
	iB11=m_Check_BL3.GetCheck();
	iB12=m_Check_EPSV3.GetCheck();
	iB13=m_Check_IM3.GetCheck();
	iB14=m_Check_Res31.GetCheck();
	iB15=m_Check_Res32.GetCheck();
	iB16=m_Check_Res33.GetCheck();
	iB17=m_Check_DIS3.GetCheck();
	iB18=m_Check_MS3.GetCheck();
	iB19=m_Check_GSI3.GetCheck();
	iB20=m_Check_CM3.GetCheck();
	iB21=m_Check_TM3.GetCheck();
	iB22=m_Check_CHMC3.GetCheck();
	iB23=m_Check_THMC3.GetCheck();
	iB24=m_Check_Res34.GetCheck();
	iB25=m_Check_Res35.GetCheck();
	iB26=m_Check_Res36.GetCheck();
	iB27=m_Check_Res37.GetCheck();
	iB28=m_Check_Res38.GetCheck();
	iB29=m_Check_Res39.GetCheck();
	iB30=m_Check_Res3a.GetCheck();
	iB31=m_Check_Res3b.GetCheck();
	sStrB.Format("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d"
		,iB31,iB30,iB29,iB28,iB27,iB26,iB25,iB24
		,iB23,iB22,iB21,iB20,iB19,iB18,iB17,iB16
		,iB15,iB14,iB13,iB12,iB11,iB10,iB9,iB8
		,iB7,iB6,iB5,iB4,iB3,iB2,iB1,iB0);
	m_MYWORK.BsToHex(sStrB,sStrH,8);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStrH,4,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}
//6
void DChrm_Dlg::GetEMValue()
{
	int iB0=0,iB1=0,iB2=0,iB3=0,iB4=0,iB5=0,iB6=0,iB7=0;
	int iB8=0,iB9=0,iB10=0,iB11=0,iB12=0,iB13=0,iB14=0,iB15=0;
	int iB16=0,iB17=0,iB18=0,iB19=0,iB20=0,iB21=0,iB22=0,iB23=0;
	int iB24=0,iB25=0,iB26=0,iB27=0,iB28=0,iB29=0,iB30=0,iB31=0;
	CString sStrB="",sStrH="",sCmd="",sNewCmd="";
	iB0=m_Check_Sed4.GetCheck();
	iB1=m_Check_Azi4.GetCheck();
	iB2=m_Check_Alt4.GetCheck();
	iB3=m_Check_ND4.GetCheck();
	iB4=m_Check_ST4.GetCheck();
	iB5=m_Check_CN4.GetCheck();
	iB6=m_Check_DN4.GetCheck();
	iB7=m_Check_Lth4.GetCheck();
	iB8=m_Check_DT4.GetCheck();
	iB9=m_Check_PV4.GetCheck();
	iB10=m_Check_FV4.GetCheck();
	iB11=m_Check_BL4.GetCheck();
	iB12=m_Check_EPSV4.GetCheck();
	iB13=m_Check_IM4.GetCheck();
	iB14=m_Check_Res41.GetCheck();
	iB15=m_Check_Res42.GetCheck();
	iB16=m_Check_Res43.GetCheck();
	iB17=m_Check_DIS4.GetCheck();
	iB18=m_Check_MS4.GetCheck();
	iB19=m_Check_GSI4.GetCheck();
	iB20=m_Check_CM4.GetCheck();
	iB21=m_Check_TM4.GetCheck();
	iB22=m_Check_CHMC4.GetCheck();
	iB23=m_Check_THMC4.GetCheck();
	iB24=m_Check_Res44.GetCheck();
	iB25=m_Check_Res45.GetCheck();
	iB26=m_Check_Res46.GetCheck();
	iB27=m_Check_Res47.GetCheck();
	iB28=m_Check_Res48.GetCheck();
	iB29=m_Check_Res49.GetCheck();
	iB30=m_Check_Res4a.GetCheck();
	iB31=m_Check_Res4b.GetCheck();
	sStrB.Format("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d"
		,iB31,iB30,iB29,iB28,iB27,iB26,iB25,iB24
		,iB23,iB22,iB21,iB20,iB19,iB18,iB17,iB16
		,iB15,iB14,iB13,iB12,iB11,iB10,iB9,iB8
		,iB7,iB6,iB5,iB4,iB3,iB2,iB1,iB0);
	m_MYWORK.BsToHex(sStrB,sStrH,8);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStrH,5,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}
//7
void DChrm_Dlg::GetIMValue()
{
	int iB0=0,iB1=0,iB2=0,iB3=0,iB4=0,iB5=0,iB6=0,iB7=0;
	int iB8=0,iB9=0,iB10=0,iB11=0,iB12=0,iB13=0,iB14=0,iB15=0;
	CString sStrB="",sStrH="",sCmd="",sNewCmd="";
	iB0=	m_Check_Lth5	.GetCheck();
	iB1=	m_Check_DN5	.GetCheck();
	iB2=	m_Check_DT5	.GetCheck();
	iB3=	m_Check_PV5	.GetCheck();
	iB4=	m_Check_FV5	.GetCheck();
	iB5=	m_Check_ST5	.GetCheck();
	iB6=	m_Check_CN5	.GetCheck();
	iB7=	m_Check_EIM5	.GetCheck();
	iB8=	m_Check_VER5	.GetCheck();
	iB9=	m_Check_IOS5	.GetCheck();
	iB10=	m_Check_GPS5	.GetCheck();
	iB11=	m_Check_BAT5	.GetCheck();
	iB12=	m_Check_CID5	.GetCheck();
	iB13=	m_Check_CSQ5	.GetCheck();
	iB14=	m_Check_TMZ5	.GetCheck();
	iB15=	m_Check_Res5	.GetCheck();
	sStrB.Format("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
		      iB15,iB14,iB13,iB12,iB11,iB10,iB9,iB8,
			  iB7,iB6,iB5,iB4,iB3,iB2,iB1,iB0);
	m_MYWORK.BsToHex(sStrB,sStrH,8);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStrH,6,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}
//8
void DChrm_Dlg::GetHMValue()
{
	int iB0=0,iB1=0,iB2=0,iB3=0,iB4=0,iB5=0,iB6=0,iB7=0;
	CString sStrB="",sStrH="",sCmd="",sNewCmd="";
	iB0=m_Check_Lth2.GetCheck();
	iB1=m_Check_DT2.GetCheck();
	iB2=m_Check_PV2.GetCheck();
	iB3=m_Check_FV2.GetCheck();
	iB4=m_Check_DN2.GetCheck();
	iB5=m_Check_ST2.GetCheck();
	iB6=m_Check_CN2.GetCheck();
	iB7=m_Check_UID.GetCheck();
	sStrB.Format("%d%d%d%d%d%d%d",iB7,iB6,iB5,iB4,iB3,iB2,iB1,iB0);
	m_MYWORK.BsToHex2Bit(sStrB,sStrH);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStrH,7,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}
//9
void DChrm_Dlg::GetDMValue()
{
	int iB0=0,iB1=0,iB2=0,iB3=0,iB4=0,iB5=0,iB6=0,iB7=0;
	CString sStrB="",sStrH="",sCmd="",sNewCmd="";
	iB0=m_Check_Lth7.GetCheck();
	iB1=	m_Check_DT7	.GetCheck();
	iB2=	m_Check_PV7	.GetCheck();
	iB3=	m_Check_FV7	.GetCheck();
	iB4=	m_Check_DN7	.GetCheck();
	iB5=	m_Check_ST7	.GetCheck();
	iB6=	m_Check_CN7	.GetCheck();
	sStrB.Format("%d%d%d%d%d%d%d",iB6,iB5,iB4,iB3,iB2,iB1,iB0);
	m_MYWORK.BsToHex(sStrB,sStrH,8);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStrH,8,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}
//10
void DChrm_Dlg::GetCMValue()
{
	int iB0=0,iB1=0,iB2=0,iB3=0,iB4=0,iB5=0,iB6=0,iB7=0;
	int iB8=0,iB9=0,iB10=0,iB11=0,iB12=0,iB13=0,iB14=0,iB15=0;
	CString sStrB="",sStrH="",sCmd="",sNewCmd="";
	iB0=	m_Check_Lth6	.GetCheck();
	iB1=	m_Check_DN6	.GetCheck();
	iB2=	m_Check_DT6	.GetCheck();
	iB3=	m_Check_PV6	.GetCheck();
	iB4=	m_Check_FV6	.GetCheck();
	iB5=	m_Check_ST6	.GetCheck();
	iB6=	m_Check_CN6	.GetCheck();
	iB7=	m_Check_Res61	.GetCheck();
	iB8=	m_Check_Res62	.GetCheck();
	iB9=	m_Check_Res63	.GetCheck();
	iB10=	m_Check_Res64	.GetCheck();
	iB11=	m_Check_Res65	.GetCheck();
	iB12=	m_Check_Res66	.GetCheck();
	iB13=	m_Check_Res67	.GetCheck();
	iB14=	m_Check_Res68	.GetCheck();
	iB15=	m_Check_Res69	.GetCheck();
	sStrB.Format("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
		iB15,iB14,iB13,iB12,iB11,iB10,iB9,iB8,
		iB7,iB6,iB5,iB4,iB3,iB2,iB1,iB0);
	m_MYWORK.BsToHex(sStrB,sStrH,4);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=UpdataCMD(sStrH,9,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void DChrm_Dlg::OnBnClickedCheckLth()
{
	GetAMValue();
}


void DChrm_Dlg::OnBnClickedCheckDt()
{
	GetAMValue();
}


void DChrm_Dlg::OnBnClickedCheckPv()
{
	GetAMValue();
}


void DChrm_Dlg::OnBnClickedCheckFv()
{
	GetAMValue();
}


void DChrm_Dlg::OnBnClickedCheckDn()
{
	GetAMValue();
}


void DChrm_Dlg::OnBnClickedCheckst()
{
	GetAMValue();
}


void DChrm_Dlg::OnBnClickedCheckCn()
{
	GetAMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes()
{
	GetAMValue();
}


void DChrm_Dlg::OnBnClickedCheckLth2()
{
	GetHMValue();
}


void DChrm_Dlg::OnBnClickedCheckDt2()
{
	GetHMValue();
}


void DChrm_Dlg::OnBnClickedCheckPv2()
{
	GetHMValue();
}


void DChrm_Dlg::OnBnClickedCheckFv2()
{
	GetHMValue();
}


void DChrm_Dlg::OnBnClickedCheckDn2()
{
	GetHMValue();
}


void DChrm_Dlg::OnBnClickedCheckSt2()
{
	GetHMValue();
}


void DChrm_Dlg::OnBnClickedCheckCn2()
{
	GetHMValue();
}


void DChrm_Dlg::OnBnClickedCheckUid()
{
	GetHMValue();
}


void DChrm_Dlg::OnBnClickedCheckSed3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckCa3()
{
	int iTemp=0;
	iTemp=m_Check_CA3.GetCheck();
	if (iTemp)
	{
		m_Check_Sed3	.SetCheck(1);
		m_Check_Azi3	.SetCheck(1);
		m_Check_Alt3	.SetCheck(1);
		m_Check_ND3	.SetCheck(1);
		m_Check_ST3	.SetCheck(1);
		m_Check_CN3	.SetCheck(1);
		m_Check_DN3	.SetCheck(1);
		m_Check_PV3	.SetCheck(1);
		m_Check_FV3	.SetCheck(1);
		m_Check_BL3	.SetCheck(1);
		m_Check_EPSV3	.SetCheck(1);
		m_Check_IM3	.SetCheck(1);
		m_Check_Res31	.SetCheck(1);
		m_Check_Res32	.SetCheck(1);
		m_Check_Res33	.SetCheck(1);
		m_Check_DIS3	.SetCheck(1);
		m_Check_MS3	.SetCheck(1);
		m_Check_GSI3	.SetCheck(1);
		m_Check_CM3	.SetCheck(1);
		m_Check_TM3	.SetCheck(1);
		m_Check_CHMC3	.SetCheck(1);
		m_Check_THMC3	.SetCheck(1);
		m_Check_Res34	.SetCheck(1);
		m_Check_Res35	.SetCheck(1);
		m_Check_Res36	.SetCheck(1);
		m_Check_Res37	.SetCheck(1);
		m_Check_Res38	.SetCheck(1);
		m_Check_Res39	.SetCheck(1);
		m_Check_Res3a	.SetCheck(1);
		m_Check_Res3b	.SetCheck(1);
		m_Check_Lth3.SetCheck(1);
		m_Check_DT3.SetCheck(1);

	}
	else
	{
		m_Check_Sed3	.SetCheck(0);
		m_Check_Azi3	.SetCheck(0);
		m_Check_Alt3	.SetCheck(0);
		m_Check_ND3	.SetCheck(0);
		m_Check_ST3	.SetCheck(0);
		m_Check_CN3	.SetCheck(0);
		m_Check_DN3	.SetCheck(0);
		m_Check_PV3	.SetCheck(0);
		m_Check_FV3	.SetCheck(0);
		m_Check_BL3	.SetCheck(0);
		m_Check_EPSV3	.SetCheck(0);
		m_Check_IM3	.SetCheck(0);
		m_Check_Res31	.SetCheck(0);
		m_Check_Res32	.SetCheck(0);
		m_Check_Res33	.SetCheck(0);
		m_Check_DIS3	.SetCheck(0);
		m_Check_MS3	.SetCheck(0);
		m_Check_GSI3	.SetCheck(0);
		m_Check_CM3	.SetCheck(0);
		m_Check_TM3	.SetCheck(0);
		m_Check_CHMC3	.SetCheck(0);
		m_Check_THMC3	.SetCheck(0);
		m_Check_Res34	.SetCheck(0);
		m_Check_Res35	.SetCheck(0);
		m_Check_Res36	.SetCheck(0);
		m_Check_Res37	.SetCheck(0);
		m_Check_Res38	.SetCheck(0);
		m_Check_Res39	.SetCheck(0);
		m_Check_Res3a	.SetCheck(0);
		m_Check_Res3b	.SetCheck(0);
		m_Check_Lth3.SetCheck(0);
		m_Check_DT3.SetCheck(0);

	}
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckAzi3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckAlt3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckNd3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckSt3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckCn3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckDn3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckLth3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckDt3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckPv3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckFv3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckBl3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckEpsv3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckIm3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes31()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes32()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes33()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckDis3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckMs3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckGsi3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckCm3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckTm3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckChmc3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckThmc3()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes34()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes35()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes36()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes37()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes38()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes39()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes3a()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes3b()
{
	GetRMValue();
}


void DChrm_Dlg::OnBnClickedCheckSed4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckAzi4()
{
		GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckAlt4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckNd4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckSt4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckCn4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckDn4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckLth4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckDt4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckPv4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckFv4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckBl4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckEpsv4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckIm4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes41()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes42()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes43()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckDis4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckMs4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckGsi4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckCm4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckTm4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckChmc4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckThmc4()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes44()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes45()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes46()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes47()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes48()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes49()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes4a()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes4b()
{
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckCa4()
{
	int iTemp=0;
	iTemp=m_Check_CA4.GetCheck();
	if (iTemp)
	{
		m_Check_Sed4	.SetCheck(1);
		m_Check_Azi4	.SetCheck(1);
		m_Check_Alt4	.SetCheck(1);
		m_Check_ND4	.SetCheck(1);
		m_Check_ST4	.SetCheck(1);
		m_Check_CN4	.SetCheck(1);
		m_Check_DN4	.SetCheck(1);
		m_Check_PV4	.SetCheck(1);
		m_Check_FV4	.SetCheck(1);
		m_Check_BL4	.SetCheck(1);
		m_Check_EPSV4	.SetCheck(1);
		m_Check_IM4	.SetCheck(1);
		m_Check_Res41	.SetCheck(1);
		m_Check_Res42	.SetCheck(1);
		m_Check_Res43	.SetCheck(1);
		m_Check_DIS4	.SetCheck(1);
		m_Check_MS4	.SetCheck(1);
		m_Check_GSI4	.SetCheck(1);
		m_Check_CM4	.SetCheck(1);
		m_Check_TM4	.SetCheck(1);
		m_Check_CHMC4	.SetCheck(1);
		m_Check_THMC4	.SetCheck(1);
		m_Check_Res44	.SetCheck(1);
		m_Check_Res45	.SetCheck(1);
		m_Check_Res46	.SetCheck(1);
		m_Check_Res47	.SetCheck(1);
		m_Check_Res48	.SetCheck(1);
		m_Check_Res49	.SetCheck(1);
		m_Check_Res4a	.SetCheck(1);
		m_Check_Res4b	.SetCheck(1);
		m_Check_Lth4.SetCheck(1);
		m_Check_DT4.SetCheck(1);

	}
	else
	{
		m_Check_Sed4	.SetCheck(0);
		m_Check_Azi4	.SetCheck(0);
		m_Check_Alt4	.SetCheck(0);
		m_Check_ND4	.SetCheck(0);
		m_Check_ST4	.SetCheck(0);
		m_Check_CN4	.SetCheck(0);
		m_Check_DN4	.SetCheck(0);
		m_Check_PV4	.SetCheck(0);
		m_Check_FV4	.SetCheck(0);
		m_Check_BL4	.SetCheck(0);
		m_Check_EPSV4	.SetCheck(0);
		m_Check_IM4.SetCheck(0);
		m_Check_Res41	.SetCheck(0);
		m_Check_Res42	.SetCheck(0);
		m_Check_Res43	.SetCheck(0);
		m_Check_DIS4	.SetCheck(0);
		m_Check_MS4	.SetCheck(0);
		m_Check_GSI4	.SetCheck(0);
		m_Check_CM4	.SetCheck(0);
		m_Check_TM4	.SetCheck(0);
		m_Check_CHMC4	.SetCheck(0);
		m_Check_THMC4	.SetCheck(0);
		m_Check_Res44	.SetCheck(0);
		m_Check_Res45	.SetCheck(0);
		m_Check_Res46	.SetCheck(0);
		m_Check_Res47	.SetCheck(0);
		m_Check_Res48	.SetCheck(0);
		m_Check_Res49	.SetCheck(0);
		m_Check_Res4a	.SetCheck(0);
		m_Check_Res4b	.SetCheck(0);
		m_Check_Lth4.SetCheck(0);
		m_Check_DT4.SetCheck(0);

	}
	GetEMValue();
}


void DChrm_Dlg::OnBnClickedCheckLth5()
{
	GetIMValue();
}


void DChrm_Dlg::OnBnClickedCheckDn5()
{
	GetIMValue();
}


void DChrm_Dlg::OnBnClickedCheckDt5()
{
	GetIMValue();
}


void DChrm_Dlg::OnBnClickedCheckPv5()
{
	GetIMValue();
}


void DChrm_Dlg::OnBnClickedCheckFv5()
{
	GetIMValue();
}


void DChrm_Dlg::OnBnClickedCheckSt5()
{
	GetIMValue();
}


void DChrm_Dlg::OnBnClickedCheckCn5()
{
	GetIMValue();
}


void DChrm_Dlg::OnBnClickedCheckEim5()
{
	GetIMValue();
}


void DChrm_Dlg::OnBnClickedCheckVer5()
{
	GetIMValue();
}


void DChrm_Dlg::OnBnClickedCheckIos5()
{
	GetIMValue();
}


void DChrm_Dlg::OnBnClickedCheckGps5()
{
	GetIMValue();
}


void DChrm_Dlg::OnBnClickedCheckBat5()
{
	GetIMValue();
}


void DChrm_Dlg::OnBnClickedCheckCid5()
{
	GetIMValue();
}


void DChrm_Dlg::OnBnClickedCheckCsq5()
{
	GetIMValue();
}


void DChrm_Dlg::OnBnClickedCheckTmz5()
{
	GetIMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes5()
{
	GetIMValue();
}


void DChrm_Dlg::OnBnClickedCheckCa5()
{
	int iTemp=0;
	iTemp=m_Check_CA5.GetCheck();
	if (iTemp)
	{
		m_Check_Lth5	.SetCheck(1);
		m_Check_DN5	.SetCheck(1);
		m_Check_DT5	.SetCheck(1);
		m_Check_PV5	.SetCheck(1);
		m_Check_FV5	.SetCheck(1);
		m_Check_ST5	.SetCheck(1);
		m_Check_CN5	.SetCheck(1);
		m_Check_EIM5	.SetCheck(1);
		m_Check_VER5	.SetCheck(1);
		m_Check_IOS5	.SetCheck(1);
		m_Check_GPS5	.SetCheck(1);
		m_Check_BAT5	.SetCheck(1);
		m_Check_CID5	.SetCheck(1);
		m_Check_CSQ5	.SetCheck(1);
		m_Check_TMZ5	.SetCheck(1);
		m_Check_Res5	.SetCheck(1);
	}
	else
	{
		m_Check_Lth5	.SetCheck(0);
		m_Check_DN5	.SetCheck(0);
		m_Check_DT5	.SetCheck(0);
		m_Check_PV5	.SetCheck(0);
		m_Check_FV5	.SetCheck(0);
		m_Check_ST5	.SetCheck(0);
		m_Check_CN5	.SetCheck(0);
		m_Check_EIM5	.SetCheck(0);
		m_Check_VER5	.SetCheck(0);
		m_Check_IOS5	.SetCheck(0);
		m_Check_GPS5	.SetCheck(0);
		m_Check_BAT5	.SetCheck(0);
		m_Check_CID5	.SetCheck(0);
		m_Check_CSQ5	.SetCheck(0);
		m_Check_TMZ5	.SetCheck(0);
		m_Check_Res5	.SetCheck(0);
	}
	GetIMValue();
}


void DChrm_Dlg::OnBnClickedCheckLth6()
{
	GetCMValue();
}


void DChrm_Dlg::OnBnClickedCheckDn6()
{
	GetCMValue();
}


void DChrm_Dlg::OnBnClickedCheckDt6()
{
	GetCMValue();
}


void DChrm_Dlg::OnBnClickedCheckPv6()
{
	GetCMValue();
}


void DChrm_Dlg::OnBnClickedCheckFv6()
{
	GetCMValue();
}


void DChrm_Dlg::OnBnClickedCheckSt6()
{
	GetCMValue();
}


void DChrm_Dlg::OnBnClickedCheckCn6()
{
	GetCMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes62()
{
	GetCMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes61()
{
	GetCMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes63()
{
	GetCMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes64()
{
	GetCMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes65()
{
	GetCMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes66()
{
	GetCMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes67()
{
	GetCMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes68()
{
	GetCMValue();
}


void DChrm_Dlg::OnBnClickedCheckRes69()
{
	GetCMValue();
}


void DChrm_Dlg::OnBnClickedCheckCa6()
{
	int iTemp=0;
	iTemp=m_Check_CA6.GetCheck();
	if (iTemp)
	{
		m_Check_Lth6	.SetCheck(1);
		m_Check_DN6	.SetCheck(1);
		m_Check_DT6	.SetCheck(1);
		m_Check_PV6	.SetCheck(1);
		m_Check_FV6	.SetCheck(1);
		m_Check_ST6	.SetCheck(1);
		m_Check_CN6	.SetCheck(1);
		m_Check_Res61	.SetCheck(1);
		m_Check_Res62	.SetCheck(1);
		m_Check_Res63	.SetCheck(1);
		m_Check_Res64	.SetCheck(1);
		m_Check_Res65	.SetCheck(1);
		m_Check_Res66	.SetCheck(1);
		m_Check_Res67	.SetCheck(1);
		m_Check_Res68	.SetCheck(1);
		m_Check_Res69	.SetCheck(1);
	}
	else
	{
		m_Check_Lth6	.SetCheck(0);
		m_Check_DN6	.SetCheck(0);
		m_Check_DT6	.SetCheck(0);
		m_Check_PV6	.SetCheck(0);
		m_Check_FV6	.SetCheck(0);
		m_Check_ST6	.SetCheck(0);
		m_Check_CN6	.SetCheck(0);
		m_Check_Res61	.SetCheck(0);
		m_Check_Res62	.SetCheck(0);
		m_Check_Res63	.SetCheck(0);
		m_Check_Res64	.SetCheck(0);
		m_Check_Res65	.SetCheck(0);
		m_Check_Res66	.SetCheck(0);
		m_Check_Res67	.SetCheck(0);
		m_Check_Res68	.SetCheck(0);
		m_Check_Res69	.SetCheck(0);
	}
	GetCMValue();
}


void DChrm_Dlg::OnBnClickedCheckLth7()
{
	GetDMValue();
}


void DChrm_Dlg::OnBnClickedCheckDt7()
{
	GetDMValue();
}


void DChrm_Dlg::OnBnClickedCheckPv7()
{
	GetDMValue();
}


void DChrm_Dlg::OnBnClickedCheckFv7()
{
	GetDMValue();
}


void DChrm_Dlg::OnBnClickedCheckDn7()
{
	GetDMValue();
}


void DChrm_Dlg::OnBnClickedCheckSt7()
{
	GetDMValue();
}


void DChrm_Dlg::OnBnClickedCheckCn7()
{
	GetDMValue();
}


void DChrm_Dlg::OnBnClickedCheckCa7()
{
	int iTemp=0;
	iTemp=m_Check_CA7.GetCheck();
	if (iTemp)
	{
		m_Check_Lth7.SetCheck(1);
		m_Check_DT7	.SetCheck(1);
		m_Check_PV7	.SetCheck(1);
		m_Check_FV7	.SetCheck(1);
		m_Check_DN7	.SetCheck(1);
		m_Check_ST7	.SetCheck(1);
		m_Check_CN7	.SetCheck(1);
	}
	else
	{
		m_Check_Lth7.SetCheck(0);
		m_Check_DT7	.SetCheck(0);
		m_Check_PV7	.SetCheck(0);
		m_Check_FV7	.SetCheck(0);
		m_Check_DN7	.SetCheck(0);
		m_Check_ST7	.SetCheck(0);
		m_Check_CN7	.SetCheck(0);
	}
	GetDMValue();
}

