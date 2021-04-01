// OSudf_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "OSudf_Dlg.h"
#include "afxdialogex.h"


///////
#include "ConfigToolDlg.h"
#include "MYWORK.h"

extern CConfigToolDlg*	lpCConfigToolDlg;
extern CMYWORK	m_MYWORK;
extern HANDLE g_hEvent;
extern BOOL MYTHREAD_WORK;
extern OSudf_Dlg m_OSudf_Dlg;
OSudf_Dlg*	lpOSudf_Dlg;
 
extern ConfigCMD stu_ConfigCMD;
CString g_sInputIDMask="000000000",g_sInzizoMask="00000";
CString g_sOutzizoMask="00000",g_sInpeoMask="00000";
CString g_sOutpeoMask="00000",g_sStocmdIDMask="00000000";
CArray<CButton*,CButton* > g_arrInputIDMasklp,g_arrInzizoMasklp;
CArray<CButton*,CButton* > g_arrOutzizoMasklp,g_arrStocmdIDMasklp;
CArray<CButton*,CButton* > g_arrInpeoMasklp,g_arrOutpeoMasklp;
////////////

IMPLEMENT_DYNAMIC(OSudf_Dlg, CMyTabBaseDlg)

OSudf_Dlg::OSudf_Dlg(CWnd* pParent /*=NULL*/)
	: CMyTabBaseDlg(OSudf_Dlg::IDD, pParent)
{

}

OSudf_Dlg::~OSudf_Dlg()
{
}

void OSudf_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CMyTabBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_M, m_ComboBox_M);
	DDX_Control(pDX, IDC_COMBO_GI, m_ComboBox_GI);
	DDX_Control(pDX, IDC_COMBO_SA, m_ComboBox_SA);
	DDX_Control(pDX, IDC_SPIN_DT, m_Spin_DT);
	DDX_Control(pDX, IDC_EDIT_DT, m_Edit_DT);
	DDX_Control(pDX, IDC_CHECK_CA8, m_Check_InputIDMaskCheckall);
	DDX_Control(pDX, IDC_CHECK_Cca, m_Check_InzizoMaskCheckall);
	DDX_Control(pDX, IDC_CHECK_Dca, m_Check_OutzizoMaskCheckall);
	DDX_Control(pDX, IDC_CHECK_Eca, m_Check_ECheckall);
	DDX_Control(pDX, IDC_CHECK_Fca, m_Check_FCheckall);
	DDX_Control(pDX, IDC_CHECK_Gca, m_Check_GCheckall);
}


BEGIN_MESSAGE_MAP(OSudf_Dlg, CMyTabBaseDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_M, &OSudf_Dlg::OnCbnSelchangeComboM)
	ON_CBN_SELCHANGE(IDC_COMBO_GI, &OSudf_Dlg::OnCbnSelchangeComboGi)
	ON_CBN_SELCHANGE(IDC_COMBO_SA, &OSudf_Dlg::OnCbnSelchangeComboSa)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_DT, &OSudf_Dlg::OnDeltaposSpinDt)
	ON_EN_CHANGE(IDC_EDIT_DT, &OSudf_Dlg::OnEnChangeEditDt)
	ON_BN_CLICKED(IDC_CHECK_B0, &OSudf_Dlg::OnBnClickedCheckB0)
	ON_BN_CLICKED(IDC_CHECK_B1, &OSudf_Dlg::OnBnClickedCheckB1)
	ON_BN_CLICKED(IDC_CHECK_B2, &OSudf_Dlg::OnBnClickedCheckB2)
	ON_BN_CLICKED(IDC_CHECK_B3, &OSudf_Dlg::OnBnClickedCheckB3)
	ON_BN_CLICKED(IDC_CHECK_B4, &OSudf_Dlg::OnBnClickedCheckB4)
	ON_BN_CLICKED(IDC_CHECK_B5, &OSudf_Dlg::OnBnClickedCheckB5)
	ON_BN_CLICKED(IDC_CHECK_B6, &OSudf_Dlg::OnBnClickedCheckB6)
	ON_BN_CLICKED(IDC_CHECK_B7, &OSudf_Dlg::OnBnClickedCheckB7)
	ON_BN_CLICKED(IDC_CHECK_B8, &OSudf_Dlg::OnBnClickedCheckB8)
	ON_BN_CLICKED(IDC_CHECK_B9, &OSudf_Dlg::OnBnClickedCheckB9)
	ON_BN_CLICKED(IDC_CHECK_B10, &OSudf_Dlg::OnBnClickedCheckB10)
	ON_BN_CLICKED(IDC_CHECK_B11, &OSudf_Dlg::OnBnClickedCheckB11)
	ON_BN_CLICKED(IDC_CHECK_B12, &OSudf_Dlg::OnBnClickedCheckB12)
	ON_BN_CLICKED(IDC_CHECK_B13, &OSudf_Dlg::OnBnClickedCheckB13)
	ON_BN_CLICKED(IDC_CHECK_B14, &OSudf_Dlg::OnBnClickedCheckB14)
	ON_BN_CLICKED(IDC_CHECK_B15, &OSudf_Dlg::OnBnClickedCheckB15)
	ON_BN_CLICKED(IDC_CHECK_B16, &OSudf_Dlg::OnBnClickedCheckB16)
	ON_BN_CLICKED(IDC_CHECK_B17, &OSudf_Dlg::OnBnClickedCheckB17)
	ON_BN_CLICKED(IDC_CHECK_B18, &OSudf_Dlg::OnBnClickedCheckB18)
	ON_BN_CLICKED(IDC_CHECK_B19, &OSudf_Dlg::OnBnClickedCheckB19)
	ON_BN_CLICKED(IDC_CHECK_B20, &OSudf_Dlg::OnBnClickedCheckB20)
	ON_BN_CLICKED(IDC_CHECK_B21, &OSudf_Dlg::OnBnClickedCheckB21)
	ON_BN_CLICKED(IDC_CHECK_B22, &OSudf_Dlg::OnBnClickedCheckB22)
	ON_BN_CLICKED(IDC_CHECK_B23, &OSudf_Dlg::OnBnClickedCheckB23)
	ON_BN_CLICKED(IDC_CHECK_B24, &OSudf_Dlg::OnBnClickedCheckB24)
	ON_BN_CLICKED(IDC_CHECK_B25, &OSudf_Dlg::OnBnClickedCheckB25)
	ON_BN_CLICKED(IDC_CHECK_B26, &OSudf_Dlg::OnBnClickedCheckB26)
	ON_BN_CLICKED(IDC_CHECK_B27, &OSudf_Dlg::OnBnClickedCheckB27)
	ON_BN_CLICKED(IDC_CHECK_B28, &OSudf_Dlg::OnBnClickedCheckB28)
	ON_BN_CLICKED(IDC_CHECK_B29, &OSudf_Dlg::OnBnClickedCheckB29)
	ON_BN_CLICKED(IDC_CHECK_B30, &OSudf_Dlg::OnBnClickedCheckB30)
	ON_BN_CLICKED(IDC_CHECK_B31, &OSudf_Dlg::OnBnClickedCheckB31)
	ON_BN_CLICKED(IDC_CHECK_B32, &OSudf_Dlg::OnBnClickedCheckB32)
	ON_BN_CLICKED(IDC_CHECK_B33, &OSudf_Dlg::OnBnClickedCheckB33)
	ON_BN_CLICKED(IDC_CHECK_B34, &OSudf_Dlg::OnBnClickedCheckB34)
	ON_BN_CLICKED(IDC_CHECK_B35, &OSudf_Dlg::OnBnClickedCheckB35)
	ON_BN_CLICKED(IDC_CHECK_CA8, &OSudf_Dlg::OnBnClickedCheckCa8)
	ON_BN_CLICKED(IDC_CHECK_C0, &OSudf_Dlg::OnBnClickedCheckC0)
	ON_BN_CLICKED(IDC_CHECK_C1, &OSudf_Dlg::OnBnClickedCheckC1)
	ON_BN_CLICKED(IDC_CHECK_C2, &OSudf_Dlg::OnBnClickedCheckC2)
	ON_BN_CLICKED(IDC_CHECK_C3, &OSudf_Dlg::OnBnClickedCheckC3)
	ON_BN_CLICKED(IDC_CHECK_C4, &OSudf_Dlg::OnBnClickedCheckC4)
	ON_BN_CLICKED(IDC_CHECK_C5, &OSudf_Dlg::OnBnClickedCheckC5)
	ON_BN_CLICKED(IDC_CHECK_C6, &OSudf_Dlg::OnBnClickedCheckC6)
	ON_BN_CLICKED(IDC_CHECK_C7, &OSudf_Dlg::OnBnClickedCheckC7)
	ON_BN_CLICKED(IDC_CHECK_C8, &OSudf_Dlg::OnBnClickedCheckC8)
	ON_BN_CLICKED(IDC_CHECK_C9, &OSudf_Dlg::OnBnClickedCheckC9)
	ON_BN_CLICKED(IDC_CHECK_C10, &OSudf_Dlg::OnBnClickedCheckC10)
	ON_BN_CLICKED(IDC_CHECK_C11, &OSudf_Dlg::OnBnClickedCheckC11)
	ON_BN_CLICKED(IDC_CHECK_C12, &OSudf_Dlg::OnBnClickedCheckC12)
	ON_BN_CLICKED(IDC_CHECK_C13, &OSudf_Dlg::OnBnClickedCheckC13)
	ON_BN_CLICKED(IDC_CHECK_C14, &OSudf_Dlg::OnBnClickedCheckC14)
	ON_BN_CLICKED(IDC_CHECK_C15, &OSudf_Dlg::OnBnClickedCheckC15)
	ON_BN_CLICKED(IDC_CHECK_C16, &OSudf_Dlg::OnBnClickedCheckC16)
	ON_BN_CLICKED(IDC_CHECK_C17, &OSudf_Dlg::OnBnClickedCheckC17)
	ON_BN_CLICKED(IDC_CHECK_C18, &OSudf_Dlg::OnBnClickedCheckC18)
	ON_BN_CLICKED(IDC_CHECK_C19, &OSudf_Dlg::OnBnClickedCheckC19)
	ON_BN_CLICKED(IDC_CHECK_Cca, &OSudf_Dlg::OnBnClickedCheckCca)
	ON_BN_CLICKED(IDC_CHECK_Dca, &OSudf_Dlg::OnBnClickedCheckDca)
	ON_BN_CLICKED(IDC_CHECK_Eca, &OSudf_Dlg::OnBnClickedCheckEca)
	ON_BN_CLICKED(IDC_CHECK_Fca, &OSudf_Dlg::OnBnClickedCheckFca)
	ON_BN_CLICKED(IDC_CHECK_Gca, &OSudf_Dlg::OnBnClickedCheckGca)
	ON_BN_CLICKED(IDC_CHECK_D0, &OSudf_Dlg::OnBnClickedCheckD0)
	ON_BN_CLICKED(IDC_CHECK_D1, &OSudf_Dlg::OnBnClickedCheckD1)
	ON_BN_CLICKED(IDC_CHECK_D2, &OSudf_Dlg::OnBnClickedCheckD2)
	ON_BN_CLICKED(IDC_CHECK_D3, &OSudf_Dlg::OnBnClickedCheckD3)
	ON_BN_CLICKED(IDC_CHECK_D4, &OSudf_Dlg::OnBnClickedCheckD4)
	ON_BN_CLICKED(IDC_CHECK_D5, &OSudf_Dlg::OnBnClickedCheckD5)
	ON_BN_CLICKED(IDC_CHECK_D6, &OSudf_Dlg::OnBnClickedCheckD6)
	ON_BN_CLICKED(IDC_CHECK_D7, &OSudf_Dlg::OnBnClickedCheckD7)
	ON_BN_CLICKED(IDC_CHECK_D8, &OSudf_Dlg::OnBnClickedCheckD8)
	ON_BN_CLICKED(IDC_CHECK_D9, &OSudf_Dlg::OnBnClickedCheckD9)
	ON_BN_CLICKED(IDC_CHECK_D10, &OSudf_Dlg::OnBnClickedCheckD10)
	ON_BN_CLICKED(IDC_CHECK_D11, &OSudf_Dlg::OnBnClickedCheckD11)
	ON_BN_CLICKED(IDC_CHECK_D12, &OSudf_Dlg::OnBnClickedCheckD12)
	ON_BN_CLICKED(IDC_CHECK_D13, &OSudf_Dlg::OnBnClickedCheckD13)
	ON_BN_CLICKED(IDC_CHECK_D14, &OSudf_Dlg::OnBnClickedCheckD14)
	ON_BN_CLICKED(IDC_CHECK_D15, &OSudf_Dlg::OnBnClickedCheckD15)
	ON_BN_CLICKED(IDC_CHECK_D16, &OSudf_Dlg::OnBnClickedCheckD16)
	ON_BN_CLICKED(IDC_CHECK_D17, &OSudf_Dlg::OnBnClickedCheckD17)
	ON_BN_CLICKED(IDC_CHECK_D18, &OSudf_Dlg::OnBnClickedCheckD18)
	ON_BN_CLICKED(IDC_CHECK_D19, &OSudf_Dlg::OnBnClickedCheckD19)
	ON_BN_CLICKED(IDC_CHECK_E0, &OSudf_Dlg::OnBnClickedCheckE0)
	ON_BN_CLICKED(IDC_CHECK_E1, &OSudf_Dlg::OnBnClickedCheckE1)
	ON_BN_CLICKED(IDC_CHECK_E2, &OSudf_Dlg::OnBnClickedCheckE2)
	ON_BN_CLICKED(IDC_CHECK_E3, &OSudf_Dlg::OnBnClickedCheckE3)
	ON_BN_CLICKED(IDC_CHECK_E4, &OSudf_Dlg::OnBnClickedCheckE4)
	ON_BN_CLICKED(IDC_CHECK_E5, &OSudf_Dlg::OnBnClickedCheckE5)
	ON_BN_CLICKED(IDC_CHECK_E6, &OSudf_Dlg::OnBnClickedCheckE6)
	ON_BN_CLICKED(IDC_CHECK_E7, &OSudf_Dlg::OnBnClickedCheckE7)
	ON_BN_CLICKED(IDC_CHECK_E8, &OSudf_Dlg::OnBnClickedCheckE8)
	ON_BN_CLICKED(IDC_CHECK_E9, &OSudf_Dlg::OnBnClickedCheckE9)
	ON_BN_CLICKED(IDC_CHECK_E10, &OSudf_Dlg::OnBnClickedCheckE10)
	ON_BN_CLICKED(IDC_CHECK_E11, &OSudf_Dlg::OnBnClickedCheckE11)
	ON_BN_CLICKED(IDC_CHECK_E12, &OSudf_Dlg::OnBnClickedCheckE12)
	ON_BN_CLICKED(IDC_CHECK_E13, &OSudf_Dlg::OnBnClickedCheckE13)
	ON_BN_CLICKED(IDC_CHECK_E14, &OSudf_Dlg::OnBnClickedCheckE14)
	ON_BN_CLICKED(IDC_CHECK_E15, &OSudf_Dlg::OnBnClickedCheckE15)
	ON_BN_CLICKED(IDC_CHECK_E16, &OSudf_Dlg::OnBnClickedCheckE16)
	ON_BN_CLICKED(IDC_CHECK_E17, &OSudf_Dlg::OnBnClickedCheckE17)
	ON_BN_CLICKED(IDC_CHECK_E18, &OSudf_Dlg::OnBnClickedCheckE18)
	ON_BN_CLICKED(IDC_CHECK_E19, &OSudf_Dlg::OnBnClickedCheckE19)
	ON_BN_CLICKED(IDC_CHECK_F0, &OSudf_Dlg::OnBnClickedCheckF0)
	ON_BN_CLICKED(IDC_CHECK_F1, &OSudf_Dlg::OnBnClickedCheckF1)
	ON_BN_CLICKED(IDC_CHECK_F2, &OSudf_Dlg::OnBnClickedCheckF2)
	ON_BN_CLICKED(IDC_CHECK_F3, &OSudf_Dlg::OnBnClickedCheckF3)
	ON_BN_CLICKED(IDC_CHECK_F4, &OSudf_Dlg::OnBnClickedCheckF4)
	ON_BN_CLICKED(IDC_CHECK_F5, &OSudf_Dlg::OnBnClickedCheckF5)
	ON_BN_CLICKED(IDC_CHECK_F6, &OSudf_Dlg::OnBnClickedCheckF6)
	ON_BN_CLICKED(IDC_CHECK_F7, &OSudf_Dlg::OnBnClickedCheckF7)
	ON_BN_CLICKED(IDC_CHECK_F8, &OSudf_Dlg::OnBnClickedCheckF8)
	ON_BN_CLICKED(IDC_CHECK_F9, &OSudf_Dlg::OnBnClickedCheckF9)
	ON_BN_CLICKED(IDC_CHECK_F10, &OSudf_Dlg::OnBnClickedCheckF10)
	ON_BN_CLICKED(IDC_CHECK_F11, &OSudf_Dlg::OnBnClickedCheckF11)
	ON_BN_CLICKED(IDC_CHECK_F12, &OSudf_Dlg::OnBnClickedCheckF12)
	ON_BN_CLICKED(IDC_CHECK_F13, &OSudf_Dlg::OnBnClickedCheckF13)
	ON_BN_CLICKED(IDC_CHECK_F14, &OSudf_Dlg::OnBnClickedCheckF14)
	ON_BN_CLICKED(IDC_CHECK_F15, &OSudf_Dlg::OnBnClickedCheckF15)
	ON_BN_CLICKED(IDC_CHECK_F16, &OSudf_Dlg::OnBnClickedCheckF16)
	ON_BN_CLICKED(IDC_CHECK_F17, &OSudf_Dlg::OnBnClickedCheckF17)
	ON_BN_CLICKED(IDC_CHECK_F18, &OSudf_Dlg::OnBnClickedCheckF18)
	ON_BN_CLICKED(IDC_CHECK_F19, &OSudf_Dlg::OnBnClickedCheckF19)
	ON_BN_CLICKED(IDC_CHECK_G0, &OSudf_Dlg::OnBnClickedCheckG0)
	ON_BN_CLICKED(IDC_CHECK_G1, &OSudf_Dlg::OnBnClickedCheckG1)
	ON_BN_CLICKED(IDC_CHECK_G2, &OSudf_Dlg::OnBnClickedCheckG2)
	ON_BN_CLICKED(IDC_CHECK_G3, &OSudf_Dlg::OnBnClickedCheckG3)
	ON_BN_CLICKED(IDC_CHECK_G4, &OSudf_Dlg::OnBnClickedCheckG4)
	ON_BN_CLICKED(IDC_CHECK_G5, &OSudf_Dlg::OnBnClickedCheckG5)
	ON_BN_CLICKED(IDC_CHECK_G6, &OSudf_Dlg::OnBnClickedCheckG6)
	ON_BN_CLICKED(IDC_CHECK_G7, &OSudf_Dlg::OnBnClickedCheckG7)
	ON_BN_CLICKED(IDC_CHECK_G8, &OSudf_Dlg::OnBnClickedCheckG8)
	ON_BN_CLICKED(IDC_CHECK_G9, &OSudf_Dlg::OnBnClickedCheckG9)
	ON_BN_CLICKED(IDC_CHECK_G10, &OSudf_Dlg::OnBnClickedCheckG10)
	ON_BN_CLICKED(IDC_CHECK_G11, &OSudf_Dlg::OnBnClickedCheckG11)
	ON_BN_CLICKED(IDC_CHECK_G12, &OSudf_Dlg::OnBnClickedCheckG12)
	ON_BN_CLICKED(IDC_CHECK_G13, &OSudf_Dlg::OnBnClickedCheckG13)
	ON_BN_CLICKED(IDC_CHECK_G14, &OSudf_Dlg::OnBnClickedCheckG14)
	ON_BN_CLICKED(IDC_CHECK_G15, &OSudf_Dlg::OnBnClickedCheckG15)
	ON_BN_CLICKED(IDC_CHECK_G16, &OSudf_Dlg::OnBnClickedCheckG16)
	ON_BN_CLICKED(IDC_CHECK_G17, &OSudf_Dlg::OnBnClickedCheckG17)
	ON_BN_CLICKED(IDC_CHECK_G18, &OSudf_Dlg::OnBnClickedCheckG18)
	ON_BN_CLICKED(IDC_CHECK_G19, &OSudf_Dlg::OnBnClickedCheckG19)
	ON_BN_CLICKED(IDC_CHECK_G20, &OSudf_Dlg::OnBnClickedCheckG20)
	ON_BN_CLICKED(IDC_CHECK_G21, &OSudf_Dlg::OnBnClickedCheckG21)
	ON_BN_CLICKED(IDC_CHECK_G22, &OSudf_Dlg::OnBnClickedCheckG22)
	ON_BN_CLICKED(IDC_CHECK_G23, &OSudf_Dlg::OnBnClickedCheckG23)
	ON_BN_CLICKED(IDC_CHECK_G24, &OSudf_Dlg::OnBnClickedCheckG24)
	ON_BN_CLICKED(IDC_CHECK_G25, &OSudf_Dlg::OnBnClickedCheckG25)
	ON_BN_CLICKED(IDC_CHECK_G26, &OSudf_Dlg::OnBnClickedCheckG26)
	ON_BN_CLICKED(IDC_CHECK_G27, &OSudf_Dlg::OnBnClickedCheckG27)
	ON_BN_CLICKED(IDC_CHECK_G28, &OSudf_Dlg::OnBnClickedCheckG28)
	ON_BN_CLICKED(IDC_CHECK_G29, &OSudf_Dlg::OnBnClickedCheckG29)
	ON_BN_CLICKED(IDC_CHECK_G30, &OSudf_Dlg::OnBnClickedCheckG30)
	ON_BN_CLICKED(IDC_CHECK_G31, &OSudf_Dlg::OnBnClickedCheckG31)
	END_MESSAGE_MAP()


// OSudf_Dlg 消息处理程序


BOOL OSudf_Dlg::OnInitDialog()
{
	CMyTabBaseDlg::OnInitDialog();
	lpOSudf_Dlg=&m_OSudf_Dlg;//窗口寻址
	m_lpMyTabBaseDlg = &m_OSudf_Dlg;
	m_iWhoamI=GTUDF;

	SetDlgItemText(IDC_EDIT_GTCMD,stu_ConfigCMD.tdWriteCmds[m_iWhoamI].sCmdstr);
	// TODO:  在此添加额外的初始化
	m_ComboBox_M.InsertString(0,"0: Disable the group");
	m_ComboBox_M.InsertString(1,"1: Enable the group.");
	m_ComboBox_M.InsertString(2,"2: Delete the group");
	m_ComboBox_M.SetCurSel(0);
	///////////////
	m_ComboBox_SA.InsertString(0,"0: Do not send acknowledgement message when the stored command is executed.");
	m_ComboBox_SA.InsertString(1,"1: Send acknowledgement message when the stored command is executed");
	m_ComboBox_SA.SetCurSel(0);
	///////////////
	for (int i=0;i<32;i++)
	{
		CString str="";
		str.Format("%d",i);
		m_ComboBox_GI.InsertString(i,str);
	}
	m_ComboBox_GI.SetCurSel(0);

	SetDlgItemText(IDC_EDIT_DT,"0");
	m_Spin_DT.SetBuddy(GetDlgItem(IDC_EDIT_DT)); //得到指向编辑框的窗口指针
	m_Spin_DT.SetRange32(0,86400);
	GetMask();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void OSudf_Dlg::GetMask()
{
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B0));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B1));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B2));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B3));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B4));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B5));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B6));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B7));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B8));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B9));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B10));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B11));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B12));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B13));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B14));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B15));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B16));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B17));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B18));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B19));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B20));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B21));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B22));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B23));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B24));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B25));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B26));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B27));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B28));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B29));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B30));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B31));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B32));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B33));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B34));
	g_arrInputIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_B35));

	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C0));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C1));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C2));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C3));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C4));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C5));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C6));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C7));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C8));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C9));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C10));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C11));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C12));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C13));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C14));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C15));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C16));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C17));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C18));
	g_arrInzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_C19));

	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D0));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D1));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D2));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D3));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D4));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D5));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D6));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D7));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D8));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D9));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D10));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D11));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D12));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D13));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D14));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D15));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D16));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D17));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D18));
	g_arrOutzizoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_D19));

	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E0));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E1));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E2));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E3));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E4));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E5));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E6));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E7));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E8));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E9));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E10));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E11));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E12));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E13));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E14));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E15));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E16));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E17));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E18));
	g_arrInpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_E19));

	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F0));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F1));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F2));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F3));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F4));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F5));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F6));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F7));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F8));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F9));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F10));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F11));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F12));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F13));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F14));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F15));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F16));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F17));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F18));
	g_arrOutpeoMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_F19));


	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G0));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G1));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G2));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G3));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G4));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G5));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G6));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G7));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G8));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G9));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G10));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G11));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G12));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G13));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G14));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G15));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G16));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G17));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G18));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G19));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G20));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G21));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G22));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G23));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G24));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G25));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G26));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G27));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G28));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G29));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G30));
	g_arrStocmdIDMasklp.Add((CButton*)GetDlgItem(	IDC_CHECK_G31));

}

CString OSudf_Dlg::UpdataCMD(CString sChildstr,int iPos,CString sParestr)
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

void OSudf_Dlg::GetCMD()
{
	CArray<CString,CString>CmdList;
	int iTemp=0;
	CString sNewCmd="";	CString sStr="",sHead="";
	CString s1="",s2	="",s3	="",s4	="",s5	="",s6	="",s7	="",s8	="",s9="";

	sHead.Format("AT+%s=HYIoT",stu_ConfigCMD.tdWriteCmds[m_iWhoamI].sName);
	CmdList.InsertAt(1,sHead);
	iTemp=m_ComboBox_M.GetCurSel();
	if (iTemp==-1) iTemp=0;
	s2.Format("%d",iTemp);
	CmdList.InsertAt(2,s2);

	iTemp=m_ComboBox_GI.GetCurSel();
	if (iTemp==-1) iTemp=0;
	s3.Format("%d",iTemp);
	CmdList.InsertAt(3,s3);

	CmdList.InsertAt(4,g_sInputIDMask);

	m_Edit_DT.GetWindowText(s5);
	CmdList.InsertAt(5,s5);

	CmdList.InsertAt(6,g_sInzizoMask);
	CmdList.InsertAt(7,g_sOutzizoMask);

	CmdList.InsertAt(8,g_sStocmdIDMask);

	iTemp=m_ComboBox_SA.GetCurSel();
	if (iTemp==-1) iTemp=0;
	s9.Format("%d",iTemp);
	CmdList.InsertAt(9,s9);

	CmdList.InsertAt(10,g_sInpeoMask);
	CmdList.InsertAt(11,g_sOutpeoMask);

	CmdList.InsertAt(12,"");	
	CmdList.InsertAt(13,"");
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

BOOL OSudf_Dlg::UpdataPage(CString sStr)
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
	if (ValueList.GetSize()>8)
	{
		m_ComboBox_M.SetCurSel(atoi(ValueList.GetAt(1)));
		OnCbnSelchangeComboM();
		m_ComboBox_GI.SetCurSel(atoi(ValueList.GetAt(2)));
		OnCbnSelchangeComboGi();
		m_ComboBox_SA.SetCurSel(atoi(ValueList.GetAt(8)));
		OnCbnSelchangeComboSa();
		m_Edit_DT.SetWindowText(ValueList.GetAt(4));
		SetInputIDMask(ValueList.GetAt(3));
		SetInzizoMask(ValueList.GetAt(5));
		SetOutzizoMask(ValueList.GetAt(6));
		SetStocmdIDMask(ValueList.GetAt(7));
		SetInpeoMask(ValueList.GetAt(9));
		SetOutpeoMask(ValueList.GetAt(10));
		return TRUE;
	} 
	else
	{
		AfxMessageBox("Data Error");
		return FALSE;
	}
}

void OSudf_Dlg::OnCbnSelchangeComboM()
{
	GetCMD();
	//CString sStr="",sCmd="",sNewCmd="";
	//int iTemp=0;
	//iTemp=m_ComboBox_M.GetCurSel();
	//sStr.Format("%d",iTemp);
	//m_Edit_GTCMD.GetWindowText(sCmd);
	//sNewCmd=m_MYWORK.UpdataCMD(sStr,1,sCmd);
	//m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void OSudf_Dlg::OnCbnSelchangeComboGi()
{
	GetCMD();
	//CString sStr="",sCmd="",sNewCmd="";
	//int iTemp=0;
	//iTemp=m_ComboBox_GI.GetCurSel();
	//sStr.Format("%d",iTemp);
	//m_Edit_GTCMD.GetWindowText(sCmd);
	//sNewCmd=m_MYWORK.UpdataCMD(sStr,2,sCmd);
	//m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void OSudf_Dlg::GetInputIDMask()
{
	CString sStrB="",sStrB2="",sStrH="",sStrH2="",sTemp="";
	for (int i=0;i<g_arrInputIDMasklp.GetSize();i++)
	{
		if (i>=0&&i<32)
		{
			int iTemp=0;
			CString sStr="";
			iTemp=g_arrInputIDMasklp.GetAt(i)->GetCheck();
			sStr.Format("%d",iTemp);
			sStrB=sStr+sStrB;
		}
		if (i>31)
		{
			int iTemp=0;
			CString sStr="";
			iTemp=g_arrInputIDMasklp.GetAt(i)->GetCheck();
			sStr.Format("%d",iTemp);
			sStrB2=sStr+sStrB2;
		}
	}
	m_MYWORK.BsToHex(sStrB,sStrH,8);
	m_MYWORK.BsToHex(sStrB2,sStrH2,1);
	g_sInputIDMask=sStrH2+sStrH;
	GetCMD();
}

void OSudf_Dlg::SetInputIDMask(CString sStrH)
{
	CString sFootBit="",sHeadBit="",sTemp="",sHeadByte="",sFootByte="";
	//前一位
	sHeadByte=sStrH.Left(1).Trim();
	sFootByte=sStrH.Right(sStrH.GetLength()-1).Trim();
	m_MYWORK.HexToBsStr(sFootByte,sFootBit,32);
	m_MYWORK.HexToBsStr(sHeadByte,sHeadBit,4);
	for (int i=0;i<g_arrInputIDMasklp.GetSize();i++)
	{
		if (i>=0&&i<32)
		{
			CString sStr="";
			sStr.Format("%c",sFootBit[i]);
			int j=atoi(sStr);
			g_arrInputIDMasklp.GetAt(g_arrInputIDMasklp.GetSize()-1-i)->SetCheck(j);
		}
		if (i>31)
		{
			CString sStr="";
			sStr.Format("%c",sHeadBit[i-32]);
			int j=atoi(sStr);
			g_arrInputIDMasklp.GetAt(g_arrInputIDMasklp.GetSize()-1-i)->SetCheck(j);
		}
	}
	GetInputIDMask();
}

void OSudf_Dlg::GetInzizoMask()
{
	CString sStrB="",sStrH="",sTemp="";
	for (int i=0;i<g_arrInzizoMasklp.GetSize();i++)
	{
		int iTemp=0;
		CString sStr="";
		iTemp=g_arrInzizoMasklp.GetAt(i)->GetCheck();
		sStr.Format("%d",iTemp);
		sStrB=sStr+sStrB;
	}
	m_MYWORK.BsToHex(sStrB,sStrH,5);
	g_sInzizoMask=sStrH;
	GetCMD();
}

void OSudf_Dlg::SetInzizoMask(CString sStrH)
{
	CString sStrB="",sTemp="";
	m_MYWORK.HexToBsStr(sStrH,sStrB,20);
	for (int i=0;i<g_arrInzizoMasklp.GetSize();i++)
	{
		CString sStr="";
		sStr.Format("%c",sStrB[i]);
		int j=atoi(sStr);
		g_arrInzizoMasklp.GetAt(g_arrInzizoMasklp.GetSize()-1-i)->SetCheck(j);
	}
	GetInzizoMask();
}

void OSudf_Dlg::GetOutzizoMask()
{
	CString sStrB="",sStrH="",sTemp="";
	for (int i=0;i<g_arrOutzizoMasklp.GetSize();i++)
	{
		int iTemp=0;
		CString sStr="";
		iTemp=g_arrOutzizoMasklp.GetAt(i)->GetCheck();
		sStr.Format("%d",iTemp);
		sStrB=sStr+sStrB;
	}
	m_MYWORK.BsToHex(sStrB,sStrH,5);
	g_sOutzizoMask=sStrH;
	GetCMD();
}

void OSudf_Dlg::SetOutzizoMask(CString sStrH)
{
	CString sStrB="",sTemp="";
	m_MYWORK.HexToBsStr(sStrH,sStrB,20);
	for (int i=0;i<g_arrOutzizoMasklp.GetSize();i++)
	{
		CString sStr="";
		sStr.Format("%c",sStrB[i]);
		int j=atoi(sStr);
		g_arrOutzizoMasklp.GetAt(g_arrOutzizoMasklp.GetSize()-1-i)->SetCheck(j);
	}
	GetOutzizoMask();
}

void OSudf_Dlg::GetInpeoMask()
{
	CString sStrB="",sStrH="",sTemp="";
	for (int i=0;i<g_arrInpeoMasklp.GetSize();i++)
	{
		int iTemp=0;
		CString sStr="";
		iTemp=g_arrInpeoMasklp.GetAt(i)->GetCheck();
		sStr.Format("%d",iTemp);
		sStrB=sStr+sStrB;
	}
	m_MYWORK.BsToHex(sStrB,sStrH,5);
	g_sInpeoMask=sStrH;
	GetCMD();
}

void OSudf_Dlg::SetInpeoMask(CString sStrH)
{
	CString sStrB="",sTemp="";
	m_MYWORK.HexToBsStr(sStrH,sStrB,20);
	for (int i=0;i<g_arrInpeoMasklp.GetSize();i++)
	{
		CString sStr="";
		sStr.Format("%c",sStrB[i]);
		int j=atoi(sStr);
		g_arrInpeoMasklp.GetAt(g_arrInpeoMasklp.GetSize()-1-i)->SetCheck(j);
	}
	GetInpeoMask();
}

void OSudf_Dlg::GetOutpeoMask()
{
	CString sStrB="",sStrH="",sTemp="";
	for (int i=0;i<g_arrOutpeoMasklp.GetSize();i++)
	{
		int iTemp=0;
		CString sStr="";
		iTemp=g_arrOutpeoMasklp.GetAt(i)->GetCheck();
		sStr.Format("%d",iTemp);
		sStrB=sStr+sStrB;
	}
	m_MYWORK.BsToHex(sStrB,sStrH,5);
	g_sOutpeoMask=sStrH;
	GetCMD();
}

void OSudf_Dlg::SetOutpeoMask(CString sStrH)
{
	CString sStrB="",sTemp="";
	m_MYWORK.HexToBsStr(sStrH,sStrB,20);
	for (int i=0;i<g_arrOutpeoMasklp.GetSize();i++)
	{
		CString sStr="";
		sStr.Format("%c",sStrB[i]);
		int j=atoi(sStr);
		g_arrOutpeoMasklp.GetAt(g_arrOutpeoMasklp.GetSize()-1-i)->SetCheck(j);
	}
	GetOutpeoMask();
}

void OSudf_Dlg::GetStocmdIDMask()
{
	CString sStrB="",sStrH="",sTemp="";
	for (int i=0;i<g_arrStocmdIDMasklp.GetSize();i++)
	{
		int iTemp=0;
		CString sStr="";
		iTemp=g_arrStocmdIDMasklp.GetAt(i)->GetCheck();
		sStr.Format("%d",iTemp);
		sStrB=sStr+sStrB;
	}
	m_MYWORK.BsToHex(sStrB,sStrH,8);
	g_sStocmdIDMask=sStrH;
	GetCMD();
}

void OSudf_Dlg::SetStocmdIDMask(CString sStrH)
{
	CString sStrB="",sTemp="";
	m_MYWORK.HexToBsStr(sStrH,sStrB,32);
	for (int i=0;i<g_arrStocmdIDMasklp.GetSize();i++)
	{
		CString sStr="";
		sStr.Format("%c",sStrB[i]);
		int j=atoi(sStr);
		g_arrStocmdIDMasklp.GetAt(g_arrStocmdIDMasklp.GetSize()-1-i)->SetCheck(j);
	}
	GetStocmdIDMask();
}


void OSudf_Dlg::OnCbnSelchangeComboSa()
{
	CString sStr="",sCmd="",sNewCmd="";
	int iTemp=0;
	iTemp=m_ComboBox_SA.GetCurSel();
	sStr.Format("%d",iTemp);
	m_Edit_GTCMD.GetWindowText(sCmd);
	sNewCmd=m_MYWORK.UpdataCMD(sStr,8,sCmd);
	m_Edit_GTCMD.SetWindowText(sNewCmd);
}

void OSudf_Dlg::OnDeltaposSpinDt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CString strValue="";
	int iTemp=0;
	iTemp=m_Spin_DT.GetPos();
	m_Spin_DT.SetPos(iTemp);
	m_Edit_DT.GetWindowText(strValue);  
	*pResult = 0;
}

void OSudf_Dlg::OnEnChangeEditDt()
{
	GetCMD();
}

void OSudf_Dlg::OnBnClickedCheckB0()
{
	GetInputIDMask();
}

void OSudf_Dlg::OnBnClickedCheckB1()
{
GetInputIDMask();
}

void OSudf_Dlg::OnBnClickedCheckB2()
{
GetInputIDMask();
}

void OSudf_Dlg::OnBnClickedCheckB3()
{
GetInputIDMask();
}

void OSudf_Dlg::OnBnClickedCheckB4()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB5()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB6()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB7()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB8()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB9()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB10()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB11()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB12()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB13()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB14()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB15()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB16()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB17()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB18()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB19()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB20()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB21()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB22()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB23()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB24()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB25()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB26()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB27()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB28()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB29()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB30()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB31()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB32()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB33()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB34()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckB35()
{
GetInputIDMask();
}


void OSudf_Dlg::OnBnClickedCheckCa8()
{
	int iTemp=0;
	iTemp=m_Check_InputIDMaskCheckall.GetCheck();
	if (iTemp)
	{
		for (int i=0;i<g_arrInputIDMasklp.GetSize();i++)
		{
			g_arrInputIDMasklp.GetAt(i)->SetCheck(1);
		}
	}
	else
	{
		for (int i=0;i<g_arrInputIDMasklp.GetSize();i++)
		{
			g_arrInputIDMasklp.GetAt(i)->SetCheck(0);
		}
	}
	GetInputIDMask();
}



void OSudf_Dlg::OnBnClickedCheckC0()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC1()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC2()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC3()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC4()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC5()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC6()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC7()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC8()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC9()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC10()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC11()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC12()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC13()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC14()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC15()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC16()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC17()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC18()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckC19()
{
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckCca()
{
	int iTemp=0;
	iTemp=m_Check_InzizoMaskCheckall.GetCheck();
	if (iTemp)
	{
		for (int i=0;i<g_arrInzizoMasklp.GetSize();i++)
		{
			g_arrInzizoMasklp.GetAt(i)->SetCheck(1);
		}
	}
	else
	{
		for (int i=0;i<g_arrInzizoMasklp.GetSize();i++)
		{
			g_arrInzizoMasklp.GetAt(i)->SetCheck(0);
		}
	}
GetInzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckDca()
{
	int iTemp=0;
	iTemp=m_Check_OutzizoMaskCheckall.GetCheck();
	if (iTemp)
	{
		for (int i=0;i<g_arrOutzizoMasklp.GetSize();i++)
		{
			g_arrOutzizoMasklp.GetAt(i)->SetCheck(1);
		}
	}
	else
	{
		for (int i=0;i<g_arrOutzizoMasklp.GetSize();i++)
		{
			g_arrOutzizoMasklp.GetAt(i)->SetCheck(0);
		}
	}
	GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckEca()
{
	int iTemp=0;
	iTemp=m_Check_ECheckall.GetCheck();
	if (iTemp)
	{
		for (int i=0;i<g_arrInpeoMasklp.GetSize();i++)
		{
			g_arrInpeoMasklp.GetAt(i)->SetCheck(1);
		}
	}
	else
	{
		for (int i=0;i<g_arrInpeoMasklp.GetSize();i++)
		{
			g_arrInpeoMasklp.GetAt(i)->SetCheck(0);
		}
	}
	GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckFca()
{
	int iTemp=0;
	iTemp=m_Check_FCheckall.GetCheck();
	if (iTemp)
	{
		for (int i=0;i<g_arrOutpeoMasklp.GetSize();i++)
		{
			g_arrOutpeoMasklp.GetAt(i)->SetCheck(1);
		}
	}
	else
	{
		for (int i=0;i<g_arrOutpeoMasklp.GetSize();i++)
		{
			g_arrOutpeoMasklp.GetAt(i)->SetCheck(0);
		}
	}
	GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckGca()
{
	int iTemp=0;
	iTemp=m_Check_GCheckall.GetCheck();
	if (iTemp)
	{
		for (int i=0;i<g_arrStocmdIDMasklp.GetSize();i++)
		{
			g_arrStocmdIDMasklp.GetAt(i)->SetCheck(1);
		}
	}
	else
	{
		for (int i=0;i<g_arrStocmdIDMasklp.GetSize();i++)
		{
			g_arrStocmdIDMasklp.GetAt(i)->SetCheck(0);
		}
	}
	GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckD0()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD1()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD2()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD3()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD4()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD5()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD6()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD7()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD8()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD9()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD10()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD11()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD12()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD13()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD14()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD15()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD16()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD17()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD18()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckD19()
{
GetOutzizoMask();
}


void OSudf_Dlg::OnBnClickedCheckE0()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE1()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE2()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE3()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE4()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE5()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE6()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE7()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE8()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE9()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE10()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE11()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE12()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE13()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE14()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE15()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE16()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE17()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE18()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckE19()
{
GetInpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF0()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF1()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF2()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF3()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF4()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF5()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF6()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF7()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF8()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF9()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF10()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF11()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF12()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF13()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF14()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF15()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF16()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF17()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF18()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckF19()
{
GetOutpeoMask();
}


void OSudf_Dlg::OnBnClickedCheckG0()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG1()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG2()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG3()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG4()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG5()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG6()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG7()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG8()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG9()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG10()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG11()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG12()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG13()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG14()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG15()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG16()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG17()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG18()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG19()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG20()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG21()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG22()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG23()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG24()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG25()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG26()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG27()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG28()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG29()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG30()
{
GetStocmdIDMask();
}


void OSudf_Dlg::OnBnClickedCheckG31()
{
GetStocmdIDMask();
}
