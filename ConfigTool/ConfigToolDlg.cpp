
// ConfigToolDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "afxdialogex.h"
#include "ConfigTool.h"
#include "ConfigToolDlg.h"
#include "afxmenubutton.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(lib,"ExcelOperate_DLL")

//类实例
CMYWORK	m_MYWORK;
CDevHound	m_DevHound;
AllTestItem	 m_TestItem;
CMdbControl		m_MdbControl;
BOOL MYTHREAD_WORK;
//////////////////
SCbsi_Dlg m_SCbsi_Dlg;
SCbsri_Dlg m_SCbsri_Dlg;
SCqss_Dlg m_SCqss_Dlg;
//////////////////
DCgc_Dlg m_DCgc_Dlg;
DCap_Dlg m_DCap_Dlg;
DCspw_Dlg m_DCspw_Dlg;
DCowh_Dlg m_DCowh_Dlg;
DCta_Dlg m_DCta_Dlg;
DCpsdls_Dlg m_DCpsdls_Dlg;
DChrm_Dlg m_DChrm_Dlg;
DCpcs_Dlg m_DCpcs_Dlg;
PRRfri_Dlg	m_PRRfri_Dlg	;
PRRfcofri_Dlg	m_PRRfcofri_Dlg	;
ASgc_Dlg	m_ASgc_Dlg	;
AStac_Dlg	m_AStac_Dlg	;
ASsa_Dlg	m_ASsa_Dlg	;
ASsosa_Dlg	m_ASsosa_Dlg	;
ASeid_Dlg	m_ASeid_Dlg	;
AShbm_Dlg	m_AShbm_Dlg	;
ASssr_Dlg	m_ASssr_Dlg	;
ASbad_Dlg	m_ASbad_Dlg	;
ASosa_Dlg	m_ASosa_Dlg	;
ASpg_Dlg	m_ASpg_Dlg	;
ASrdc_Dlgnew	m_ASrdc_Dlg	;
ASsadr_Dlg	m_ASsadr_Dlg	;
ASser_Dlg	m_ASser_Dlg	;
AScd_Dlg	m_AScd_Dlg	;
IAdops_Dlg	m_IAdops_Dlg	;
IAepsm_Dlg	m_IAepsm_Dlg	;
IAdips_Dlg	m_IAdips_Dlg	;
IAips_Dlg	m_IAips_Dlg	;
IDSvims_Dlg	m_IDSvims_Dlg	;
IDSidbvs_Dlg	m_IDSidbvs_Dlg	;
IDSavis_Dlg	m_IDSavis_Dlg	;
OSrto_Dlg	m_OSrto_Dlg	;
OShmc_Dlg	m_OShmc_Dlg	;
OSwl_Dlg	m_OSwl_Dlg	;
OSglsc_Dlg	m_OSglsc_Dlg	;
OSucota_Dlg	m_OSucota_Dlg	;
OScss_Dlg	m_OScss_Dlg	;
OSudf_Dlg	m_OSudf_Dlg	;
OSgs_Dlg	m_OSgs_Dlg	;
OSer_Dlg	m_OSer_Dlg	;
//全局
CConfigToolDlg* lpCConfigToolDlg;
int g_CSelTab;
int g_Status=1; //改变状态框颜色使用
bool InitSize=false;
CRect  m_rect;   //用于保存原对话框大小
BOOL bTabNoNeedResize=FALSE;

int g_iWidth=18;//控制宽度
int g_iBUTWidth=22;
CImage g_LogoImage;
CRect g_LogoRect;  //控件矩形对象

//struct成员对象变量
CONFIG	stu_CONFIG;
ConfigCMD stu_ConfigCMD;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CConfigToolDlg 对话框

CConfigToolDlg::CConfigToolDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CConfigToolDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_HY);
}

void CConfigToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_LOG, m_Table);
	DDX_Control(pDX, IDC_COMBO_PORT, m_ComboBox_Port);
	DDX_Control(pDX, IDC_COMBO_BRATE, m_ComboBox_BaudRate);
	DDX_Control(pDX, IDC_STATIC_STATUS, m_STATIC_Status);
	DDX_Control(pDX, IDC_EDIT_Log, m_EDIT_Log);
	DDX_Control(pDX, IDC_MFCBUTTON_ETM, m_MFCBUTTON_ETM);
	DDX_Control(pDX, IDC_MFCBUTTON_BSI, m_MFCBUTTON_BSI);
	DDX_Control(pDX, IDC_MFCBUTTON_BSRI, m_MFCBUTTON_BRSI);
	DDX_Control(pDX, IDC_MFCBUTTON_QSS, m_MFCBUTTON_QSS);
	DDX_Control(pDX, IDC_MFCBUTTON_DCgc, m_MFCBUTTON_DCgc);
	DDX_Control(pDX, IDC_MFCBUTTON_DCap, m_MFCBUTTON_DCap);
	DDX_Control(pDX, IDC_MFCBUTTON_DCspw, m_MFCBUTTON_DCspw);
	DDX_Control(pDX, IDC_MFCBUTTON_DCowh, m_MFCBUTTON_DCowh);
	DDX_Control(pDX, IDC_MFCBUTTON_DCta, m_MFCBUTTON_DCta);
	DDX_Control(pDX, IDC_MFCBUTTON_DCpsdls, m_MFCBUTTON_DCpsdls);
	DDX_Control(pDX, IDC_MFCBUTTON_DChrm, m_MFCBUTTON_DChrm);
	DDX_Control(pDX, IDC_MFCBUTTON_DCpcs, m_MFCBUTTON_DCpcs);
	DDX_Control(pDX, IDC_MFCBUTTON_PRRfri, m_MFCBUTTON_PRRfri);
	DDX_Control(pDX, IDC_MFCBUTTON_PRRfcofri, m_MFCBUTTON_PRRfcofri);
	DDX_Control(pDX, IDC_MFCBUTTON_ASgc, m_MFCBUTTON_ASgc);
	DDX_Control(pDX, IDC_MFCBUTTON_AStac, m_MFCBUTTON_AStac);
	DDX_Control(pDX, IDC_MFCBUTTON_ASsa, m_MFCBUTTON_ASsa);
	DDX_Control(pDX, IDC_MFCBUTTON_ASsosa, m_MFCBUTTON_ASsosa);
	DDX_Control(pDX, IDC_MFCBUTTON_ASeid, m_MFCBUTTON_ASeid);
	DDX_Control(pDX, IDC_MFCBUTTON_AShbm, m_MFCBUTTON_AShbm);
	DDX_Control(pDX, IDC_MFCBUTTON_ASssr, m_MFCBUTTON_ASssr);
	DDX_Control(pDX, IDC_MFCBUTTON_ASbad, m_MFCBUTTON_ASbad);
	DDX_Control(pDX, IDC_MFCBUTTON_ASosa, m_MFCBUTTON_ASosa);
	DDX_Control(pDX, IDC_MFCBUTTON_ASpg, m_MFCBUTTON_ASpg);
	DDX_Control(pDX, IDC_MFCBUTTON_ASrdc, m_MFCBUTTON_ASrdc);
	DDX_Control(pDX, IDC_MFCBUTTON_ASsadr, m_MFCBUTTON_ASsadr);
	DDX_Control(pDX, IDC_MFCBUTTON_ASser, m_MFCBUTTON_ASser);
	DDX_Control(pDX, IDC_MFCBUTTON_AScd, m_MFCBUTTON_AScd);
	DDX_Control(pDX, IDC_STATIC_Item, m_Static_Item);
	DDX_Control(pDX, IDC_MFCBUTTON_IAdops, m_MFCBUTTON_IAdops);
	DDX_Control(pDX, IDC_MFCBUTTON_IAepsm, m_MFCBUTTON_IAepsm);
	DDX_Control(pDX, IDC_MFCBUTTON_IAdips, m_MFCBUTTON_IAdips);
	DDX_Control(pDX, IDC_MFCBUTTON_IAips, m_MFCBUTTON_IAips);
	DDX_Control(pDX, IDC_MFCBUTTON_IDSvims, m_MFCBUTTON_IDSvims);
	DDX_Control(pDX, IDC_MFCBUTTON_IDSidbvs, m_MFCBUTTON_IDSidbvs);
	DDX_Control(pDX, IDC_MFCBUTTON_IDSavis, m_MFCBUTTON_IDSavis);
	DDX_Control(pDX, IDC_MFCBUTTON_OSrto, m_MFCBUTTON_OSrto);
	DDX_Control(pDX, IDC_MFCBUTTON_OShmc, m_MFCBUTTON_OShmc);
	DDX_Control(pDX, IDC_MFCBUTTON_OSwl, m_MFCBUTTON_OSwl);
	DDX_Control(pDX, IDC_MFCBUTTON_OSglsc, m_MFCBUTTON_OSglsc);
	DDX_Control(pDX, IDC_MFCBUTTON_OSucota, m_MFCBUTTON_OSucota);
	DDX_Control(pDX, IDC_MFCBUTTON_OScss, m_MFCBUTTON_OScss);
	DDX_Control(pDX, IDC_MFCBUTTON_OSudf, m_MFCBUTTON_OSudf);
	DDX_Control(pDX, IDC_MFCBUTTON_OSgs, m_MFCBUTTON_OSgs);
	DDX_Control(pDX, IDC_MFCBUTTON_OSer, m_MFCBUTTON_OSer);
	DDX_Control(pDX, IDC_MFCBUTTON_OL, m_MFCBUTTON_OL);
	DDX_Control(pDX, IDC_MFCBUTTON_SC, m_MFCBUTTON_SC);
	DDX_Control(pDX, IDC_MFCBUTTON_DC, m_MFCBUTTON_DC);
	DDX_Control(pDX, IDC_MFCBUTTON_PRR, m_MFCBUTTON_PRR);
	DDX_Control(pDX, IDC_MFCBUTTON_AS, m_MFCBUTTON_AS);
	DDX_Control(pDX, IDC_MFCBUTTON_IA, m_MFCBUTTON_IA);
	DDX_Control(pDX, IDC_MFCBUTTON_IDS, m_MFCBUTTON_IDS);
	DDX_Control(pDX, IDC_MFCBUTTON_OS, m_MFCBUTTON_OS);
	DDX_Control(pDX, IDC_MFCBUTTON_SAC, m_MFCBUTTON_SAC);
	DDX_Control(pDX, IDC_MFCBUTTON_SaveAC, m_MFCBUTTON_SaveAC);
	DDX_Control(pDX, IDC_MFCMENUBUTTON_RAC, m_Menubutton_RAC);
	DDX_Control(pDX, IDC_STATIC_Logo, m_Static_Logo);
}

BEGIN_MESSAGE_MAP(CConfigToolDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_LOG, &CConfigToolDlg::OnTcnSelchangeTabLog)
	ON_CBN_SELCHANGE(IDC_COMBO_PORT, &CConfigToolDlg::OnCbnSelchangeComboPort)
	ON_CBN_SELCHANGE(IDC_COMBO_BRATE, &CConfigToolDlg::OnCbnSelchangeComboBrate)
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_MFCBUTTON_SC, &CConfigToolDlg::OnBnClickedButtonServerConnection)
	ON_BN_CLICKED(IDC_MFCBUTTON_DC, &CConfigToolDlg::OnBnClickedButtonDc)
	ON_BN_CLICKED(IDC_MFCBUTTON_PRR, &CConfigToolDlg::OnBnClickedButtonPrr)
	ON_BN_CLICKED(IDC_MFCBUTTON_AS, &CConfigToolDlg::OnBnClickedButtonAs)
	ON_BN_CLICKED(IDC_MFCBUTTON_IA, &CConfigToolDlg::OnBnClickedButtonIa)
	ON_BN_CLICKED(IDC_MFCBUTTON_IDS, &CConfigToolDlg::OnBnClickedButtonIds)
	ON_BN_CLICKED(IDC_MFCBUTTON_OS, &CConfigToolDlg::OnBnClickedButtonOs)
	ON_BN_CLICKED(IDC_MFCBUTTON_BSI, &CConfigToolDlg::OnBnClickedMfcbuttonBsi)
	ON_BN_CLICKED(IDC_MFCBUTTON_ETM, &CConfigToolDlg::OnBnClickedMfcbuttonEtm)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_MFCBUTTON_BSRI, &CConfigToolDlg::OnBnClickedMfcbuttonBsri)
	ON_BN_CLICKED(IDC_MFCBUTTON_QSS, &CConfigToolDlg::OnBnClickedMfcbuttonQss)
	ON_BN_CLICKED(IDC_MFCBUTTON_DCgc, &CConfigToolDlg::OnBnClickedMfcbuttonDcgc)
	ON_BN_CLICKED(IDC_MFCBUTTON_DCap, &CConfigToolDlg::OnBnClickedMfcbuttonDcap)
	ON_BN_CLICKED(IDC_MFCBUTTON_DCspw, &CConfigToolDlg::OnBnClickedMfcbuttonDcspw)
	ON_BN_CLICKED(IDC_MFCBUTTON_DCowh, &CConfigToolDlg::OnBnClickedMfcbuttonDcowh)
	ON_BN_CLICKED(IDC_MFCBUTTON_DCta, &CConfigToolDlg::OnBnClickedMfcbuttonDcta)
	ON_BN_CLICKED(IDC_MFCBUTTON_DCpsdls, &CConfigToolDlg::OnBnClickedMfcbuttonDcpsdls)
	ON_BN_CLICKED(IDC_MFCBUTTON_DChrm, &CConfigToolDlg::OnBnClickedMfcbuttonDchrm)
	ON_BN_CLICKED(IDC_MFCBUTTON_DCpcs, &CConfigToolDlg::OnBnClickedMfcbuttonDcpcs)
	ON_BN_CLICKED(IDC_MFCBUTTON_PRRfri, &CConfigToolDlg::OnBnClickedMfcbuttonPrrfri)
	ON_BN_CLICKED(IDC_MFCBUTTON_PRRfcofri, &CConfigToolDlg::OnBnClickedMfcbuttonPrrfcofri)
	ON_BN_CLICKED(IDC_MFCBUTTON_ASgc, &CConfigToolDlg::OnBnClickedMfcbuttonAsgc)
	ON_BN_CLICKED(IDC_MFCBUTTON_AStac, &CConfigToolDlg::OnBnClickedMfcbuttonAstac)
	ON_BN_CLICKED(IDC_MFCBUTTON_ASsa, &CConfigToolDlg::OnBnClickedMfcbuttonAssa)
	ON_BN_CLICKED(IDC_MFCBUTTON_ASsosa, &CConfigToolDlg::OnBnClickedMfcbuttonAssosa)
	ON_BN_CLICKED(IDC_MFCBUTTON_ASeid, &CConfigToolDlg::OnBnClickedMfcbuttonAseid)
	ON_BN_CLICKED(IDC_MFCBUTTON_AShbm, &CConfigToolDlg::OnBnClickedMfcbuttonAshbm)
	ON_BN_CLICKED(IDC_MFCBUTTON_ASssr, &CConfigToolDlg::OnBnClickedMfcbuttonAsssr)
	ON_BN_CLICKED(IDC_MFCBUTTON_ASbad, &CConfigToolDlg::OnBnClickedMfcbuttonAsbad)
	ON_BN_CLICKED(IDC_MFCBUTTON_ASosa, &CConfigToolDlg::OnBnClickedMfcbuttonAsosa)
	ON_BN_CLICKED(IDC_MFCBUTTON_ASpg, &CConfigToolDlg::OnBnClickedMfcbuttonAspg)
	ON_BN_CLICKED(IDC_MFCBUTTON_ASrdc, &CConfigToolDlg::OnBnClickedMfcbuttonAsrdc)
	ON_BN_CLICKED(IDC_MFCBUTTON_ASsadr, &CConfigToolDlg::OnBnClickedMfcbuttonAssadr)
	ON_BN_CLICKED(IDC_MFCBUTTON_ASser, &CConfigToolDlg::OnBnClickedMfcbuttonAsser)
	ON_BN_CLICKED(IDC_MFCBUTTON_AScd, &CConfigToolDlg::OnBnClickedMfcbuttonAscd)
	ON_BN_CLICKED(IDC_MFCBUTTON_IAdops, &CConfigToolDlg::OnBnClickedMfcbuttonIadops)
	ON_BN_CLICKED(IDC_MFCBUTTON_IAepsm, &CConfigToolDlg::OnBnClickedMfcbuttonIaepsm)
	ON_BN_CLICKED(IDC_MFCBUTTON_IAdips, &CConfigToolDlg::OnBnClickedMfcbuttonIadips)
	ON_BN_CLICKED(IDC_MFCBUTTON_IAips, &CConfigToolDlg::OnBnClickedMfcbuttonIaips)
	ON_BN_CLICKED(IDC_MFCBUTTON_IDSvims, &CConfigToolDlg::OnBnClickedMfcbuttonIdsvims)
	ON_BN_CLICKED(IDC_MFCBUTTON_IDSidbvs, &CConfigToolDlg::OnBnClickedMfcbuttonIdsidbvs)
	ON_BN_CLICKED(IDC_MFCBUTTON_IDSavis, &CConfigToolDlg::OnBnClickedMfcbuttonIdsavis)
	ON_BN_CLICKED(IDC_MFCBUTTON_OSrto, &CConfigToolDlg::OnBnClickedMfcbuttonOsrto)
	ON_BN_CLICKED(IDC_MFCBUTTON_OShmc, &CConfigToolDlg::OnBnClickedMfcbuttonOshmc)
	ON_BN_CLICKED(IDC_MFCBUTTON_OSwl, &CConfigToolDlg::OnBnClickedMfcbuttonOswl)
	ON_BN_CLICKED(IDC_MFCBUTTON_OSglsc, &CConfigToolDlg::OnBnClickedMfcbuttonOsglsc)
	ON_BN_CLICKED(IDC_MFCBUTTON_OSucota, &CConfigToolDlg::OnBnClickedMfcbuttonOsucota)
	ON_BN_CLICKED(IDC_MFCBUTTON_OScss, &CConfigToolDlg::OnBnClickedMfcbuttonOscss)
	ON_BN_CLICKED(IDC_MFCBUTTON_OSudf, &CConfigToolDlg::OnBnClickedMfcbuttonOsudf)
	ON_BN_CLICKED(IDC_MFCBUTTON_OSgs, &CConfigToolDlg::OnBnClickedMfcbuttonOsgs)
	ON_BN_CLICKED(IDC_MFCBUTTON_OSer, &CConfigToolDlg::OnBnClickedMfcbuttonOser)
	ON_BN_CLICKED(IDC_MFCBUTTON_OL, &CConfigToolDlg::OnBnClickedMfcbuttonOl)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON_RAC, &CConfigToolDlg::OnBnClickedMfcmenubuttonRac)
	ON_BN_CLICKED(IDC_MFCBUTTON_SAC, &CConfigToolDlg::OnBnClickedMfcbuttonSac)
	ON_BN_CLICKED(IDC_MFCBUTTON_SaveAC, &CConfigToolDlg::OnBnClickedMfcbuttonSaveac)
END_MESSAGE_MAP()

// CConfigToolDlg 消息处理程序

BOOL CConfigToolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 将“关于...”菜单项添加到系统菜单中。
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	// TODO: 在此添加额外的初始化代码
	lpCConfigToolDlg=this;
	SetWindowText("ConfigTool_V2.04_20210401");
	this->SetBackgroundColor(RGB(176,196,222),1);
	GetConfigFromFile();//读取配置文件信息
	/////////////ServerConnection页面
	m_SCbsi_Dlg.Create(IDD_SCbsi_Dlg, &m_Table);//表格地址与窗口对应
	m_SCbsri_Dlg.Create(IDD_SCbsri_Dlg, &m_Table);
	m_SCqss_Dlg.Create(IDD_SCqss_Dlg, &m_Table);
	/////////////////////////////
	m_DCgc_Dlg.Create(IDD_DCgc_Dlg, &m_Table);//表格地址与窗口对应
	m_DCap_Dlg.Create(IDD_DCap_Dlg, &m_Table);
	m_DCspw_Dlg.Create(IDD_DCspw_Dlg, &m_Table);
	m_DCowh_Dlg.Create(IDD_DCowh_Dlg, &m_Table);//表格地址与窗口对应
	m_DCta_Dlg.Create(IDD_DCta_Dlg, &m_Table);
	m_DCpsdls_Dlg.Create(IDD_DCpsdls_Dlg, &m_Table);
	m_DChrm_Dlg.Create(IDD_DChrm_Dlg, &m_Table);
	m_DCpcs_Dlg.Create(IDD_DCpcs_Dlg, &m_Table);
	/////////////
	m_PRRfri_Dlg.Create(IDD_PRRfri_Dlg,&m_Table);
	m_PRRfcofri_Dlg.Create(	IDD_PRRfcofri_Dlg,&m_Table);
	m_ASgc_Dlg.Create(	IDD_ASgc_Dlg	, &m_Table);
	m_AStac_Dlg.Create(	IDD_AStac_Dlg	, &m_Table);
	m_ASsa_Dlg.Create(	IDD_ASsa_Dlg	, &m_Table);
	m_ASsosa_Dlg.Create(	IDD_ASsosa_Dlg	, &m_Table);
	m_ASeid_Dlg.Create(	IDD_ASeid_Dlg	, &m_Table);
	m_AShbm_Dlg.Create(	IDD_AShbm_Dlg	, &m_Table);
	m_ASssr_Dlg.Create(	IDD_ASssr_Dlg	, &m_Table);
	m_ASbad_Dlg.Create(	IDD_ASbad_Dlg	, &m_Table);
	m_ASosa_Dlg.Create(	IDD_ASosa_Dlg	, &m_Table);
	m_ASpg_Dlg.Create(	IDD_ASpg_Dlg	, &m_Table);
	m_ASrdc_Dlg.Create(	IDD_ASrdc_Dlgnew	, &m_Table);
	m_ASsadr_Dlg.Create(	IDD_ASsadr_Dlg	, &m_Table);
	m_ASser_Dlg.Create(	IDD_ASser_Dlg	, &m_Table);
	m_AScd_Dlg.Create(	IDD_AScd_Dlg	, &m_Table);
	m_IAdops_Dlg.Create(	IDD_IAdops_Dlg	, &m_Table);
	m_IAepsm_Dlg.Create(	IDD_IAepsm_Dlg	, &m_Table);
	m_IAdips_Dlg.Create(	IDD_IAdips_Dlg	, &m_Table);
	m_IAips_Dlg.Create(	IDD_IAips_Dlg	, &m_Table);
	m_IDSvims_Dlg.Create(	IDD_IDSvims_Dlg	, &m_Table);
	m_IDSidbvs_Dlg.Create(	IDD_IDSidbvs_Dlg	, &m_Table);
	m_IDSavis_Dlg.Create(	IDD_IDSavis_Dlg	, &m_Table);
	m_OSrto_Dlg.Create(	IDD_OSrto_Dlg	, &m_Table);
	m_OShmc_Dlg.Create(	IDD_OShmc_Dlg	, &m_Table);
	m_OSwl_Dlg.Create(	IDD_OSwl_Dlg	, &m_Table);
	m_OSglsc_Dlg.Create(	IDD_OSglsc_Dlg	, &m_Table);
	m_OSucota_Dlg.Create(	IDD_OSucota_Dlg	, &m_Table);
	m_OScss_Dlg.Create(	IDD_OScss_Dlg	, &m_Table);
	m_OSudf_Dlg.Create(	IDD_OSudf_Dlg	, &m_Table);
	m_OSgs_Dlg.Create(	IDD_OSgs_Dlg	, &m_Table);
	m_OSer_Dlg.Create(	IDD_OSer_Dlg	, &m_Table);
	//加载工具页面

	BUTStyle();

	//fontStaticItem.CreatePointFont(93,"粗体");
	m_pFont = new CFont;
	m_pFont->CreateFont(16,							 // 字体高度
		0,							 // 字体宽度
		0,							 // 字体倾斜角
		0,							 // 字体倾斜角
		FW_BOLD,				         // 字体的粗细
		FALSE,						 // 字体是否为斜体
		FALSE,						 // 字体是否有下划线
		0,							 // 字体是否有删除线
		ANSI_CHARSET,				         // 字体使用的字符集
		OUT_DEFAULT_PRECIS,		     	                 // 指定如何选择合适的字体
		CLIP_DEFAULT_PRECIS,    		                 // 确定裁剪的精度
		DEFAULT_QUALITY,			                 // 怎么样跟选择的字体相符合
		DEFAULT_PITCH | FF_SWISS,	                         // 间距标志和属性标志
		_T("Arial"));				         // 字体的名称
	m_Static_Item.SetFont(m_pFont,FALSE);
	stu_CONFIG.sExeFilePath=GetExeFilePath();
	//////////////
	m_ComboBox_BaudRate.InsertString(0,"9600");
	m_ComboBox_BaudRate.InsertString(1,"115200");
	GetTestItem();//读取各个设定参数
	GetComPort();//读取各个设定参数
	//m_ComboBox_Port.SetCurSel(stu_CONFIG.iPhonePort);
	m_ComboBox_BaudRate.SetCurSel(stu_CONFIG.iBaudRate);
	Statusfont.CreatePointFont(200,"黑体");
	////////////////
	ShowBmp(READY);	
	
	CMenu* pMenu = new CMenu;
	pMenu->LoadMenu(IDR_MENU1);
	m_Menubutton_RAC.m_hMenu = pMenu->GetSubMenu(0)->GetSafeHmenu();
	SetDlgItemText(IDC_MFCBUTTON_OL,"OPEN LOG");

	OnBnClickedButtonServerConnection();
	OnBnClickedMfcbuttonBsi();
	GetClientRect(&m_rect);  //获取对话框的大小
	InitSize=true;
	KeepIniSize();/////////保留窗体原始数据//////////
	CheckPicture();	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CConfigToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。


void CConfigToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		CDialog::UpdateWindow(); //更新windows窗口  
		CheckPicture();     //重绘图片函数

	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CConfigToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#pragma region SystemMethod

void CConfigToolDlg::CheckPicture()
{	
	CString strPath="",LogoPath="";	
	CRect rectPicture;   //图片矩形对象
	strPath=lpCConfigToolDlg->GetExeFilePath();
	LogoPath=strPath+"Logo.jpg";
	//加载图片
	if (PathFileExists(LogoPath))
	{	
		g_LogoImage.Load(LogoPath);//装载路径下图片信息到图片类 
		KeyPicShow();
	}
}

void CConfigToolDlg::KeyPicShow()
{
	//获得控件的区域对象,获得显示控件的DC 
	m_Static_Logo.GetClientRect(&g_LogoRect);   
	CDC* pLogoDC = m_Static_Logo.GetWindowDC();  
	//解决颜色失真
	::SetStretchBltMode(*pLogoDC, HALFTONE);//HALFTONE：將要删掉的像素跟周围的中和起來,(相当于PS的那个模糊工具)
	::SetBrushOrgEx(*pLogoDC, 0, 0, NULL);
	g_LogoImage.StretchBlt(*pLogoDC, 20, 132, 140, 198, SRCCOPY);//坐标无效不知道原因
	//绘图
	g_LogoImage.Draw( pLogoDC ->m_hDC,g_LogoRect);  
	g_LogoImage.Destroy();
}

void CConfigToolDlg::KeepIniSize()
{
	CRect rect;  
	m_listRect.RemoveAll();
	GetWindowRect(&rect); 
	m_listRect.AddTail(rect);//对话框的区域  
	CWnd* pReWnd = GetWindow(GW_CHILD);//获取子窗体  
	while(pReWnd)  
	{  
		pReWnd->GetWindowRect(rect);//子窗体的区域  
		m_listRect.AddTail(rect);   //CList<CRect,CRect> m_listRect成员变量  
		pReWnd = pReWnd->GetNextWindow();//取下一个子窗体  
	}  
}

bool CConfigToolDlg::GetConfigFromFile()
{
	CString sReadFileTemp;
	CString sConfigFilePath=lpCConfigToolDlg->GetExeFilePath()+"config.ini";

	/*工具配置*/
	GetPrivateProfileString("CONFIG","TestSelection","",sReadFileTemp.GetBuffer(MAX_PATH),MAX_PATH,sConfigFilePath);
	sReadFileTemp.ReleaseBuffer();
	stu_CONFIG.iTestSelection=atoi(sReadFileTemp);

	GetPrivateProfileString("CONFIG","COMPORT","",sReadFileTemp.GetBuffer(MAX_PATH),MAX_PATH,sConfigFilePath);
	sReadFileTemp.ReleaseBuffer();
	stu_CONFIG.iPhonePort=atoi(sReadFileTemp);

	GetPrivateProfileString("CONFIG","BaudRate","",sReadFileTemp.GetBuffer(MAX_PATH),MAX_PATH,sConfigFilePath);
	sReadFileTemp.ReleaseBuffer();
	stu_CONFIG.iBaudRate=atoi(sReadFileTemp);

	for (int i=0;i<44;i++)
	{
		CString sTemp="";
		sTemp.Format("%d",i);
		stu_ConfigCMD.tdReadCmds[i].iIndex=i;
		stu_ConfigCMD.tdWriteCmds[i].iIndex=i;
		GetPrivateProfileString("CONFIG",sTemp,"",sReadFileTemp.GetBuffer(MAX_PATH),MAX_PATH,sConfigFilePath);
		sReadFileTemp.ReleaseBuffer();
		stu_ConfigCMD.tdReadCmds[i].sName=sReadFileTemp;
		stu_ConfigCMD.tdWriteCmds[i].sName=sReadFileTemp;
	}

	sConfigFilePath=lpCConfigToolDlg->GetExeFilePath()+"ConfigReadCMD.ini";
	for (int i=0;i<44;i++)
	{
		CString sTemp="";
		sTemp.Format("%d",i);
		GetPrivateProfileString("CONFIGREAD",sTemp,"",sReadFileTemp.GetBuffer(MAX_PATH),MAX_PATH,sConfigFilePath);
		sReadFileTemp.ReleaseBuffer();
		stu_ConfigCMD.tdReadCmds[i].sCmdstr=sReadFileTemp;
	}

	sConfigFilePath=lpCConfigToolDlg->GetExeFilePath()+"ConfigWriteCMD.ini";
	for (int i=0;i<44;i++)
	{
		CString sTemp="";
		sTemp.Format("%d",i);
		GetPrivateProfileString("CONFIGWRITE",sTemp,"",sReadFileTemp.GetBuffer(MAX_PATH),MAX_PATH,sConfigFilePath);
		sReadFileTemp.ReleaseBuffer();
		stu_ConfigCMD.tdWriteCmds[i].sCmdstr=sReadFileTemp;
	}

	return true;
}

void CConfigToolDlg::OutPutDebugLog(CString sLog)
{
	int index=0,ChinesIndex=0,MaxOutPutCharLen=100;
	BYTE GetChar[100]={NULL};
	int LogLength=0;
	CString message="",sTime="";
	bool Loop=true;
	CString templog="";
	//SaveCurrentRunLog(sLog,"a",false);
	m_EDIT_Log.GetWindowText(templog);
	m_EDIT_Log.SetWindowText(templog+sLog+"\r\n");
	index=m_EDIT_Log.GetLineCount();
	m_EDIT_Log.LineScroll(index, 0);
}

CString CConfigToolDlg::GetExeFilePath()
{
	CString filepath="";
	GetModuleFileName(NULL,filepath.GetBuffer(MAX_PATH+1),MAX_PATH);
	filepath.ReleaseBuffer();
	int length=filepath.GetLength();
	int index=filepath.ReverseFind('\\');
	filepath=filepath.Left(index+1);
	return filepath;
}
void CConfigToolDlg::SaveOntimeDebugLog(CString log,CString WriteType)
{
	int index=0;
	int ilength=0;
	CString sLogPath="",sTime="",Mylog="";
	FILE* fp;
	errno_t err;
	CTime time = CTime::GetCurrentTime();
	sTime = time.Format("%Y-%m-%d_%H-%M-%S");  

	Mylog.Format("%s :\t%s\n",sTime,log);
	sLogPath=stu_CONFIG.sExeFilePath+"OnTimeLog\\";
	if(!PathFileExists(sLogPath))//文件夹不存在则创建
	{
		CreateDirectory(sLogPath,NULL);
	}
	sLogPath=sLogPath+"OntimeDebugLog.txt";
	//fp=fopen(sLogPath,WriteType);
	err=fopen_s(&fp,sLogPath,WriteType);
	if (err!=0)
	{
		MessageBox("RUNLOG保存路径打开失败！","提示",MB_OK);
		//return false;
	}
	fwrite(Mylog,Mylog.GetLength(),1,fp);
	fclose(fp);
	return;
}

void CConfigToolDlg::OnCbnSelchangeComboPort()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sWriteFileTemp;
	CString sConfigFilePath=lpCConfigToolDlg->GetExeFilePath()+"config.ini";
	int iSelection=m_ComboBox_Port.GetCurSel();
	sWriteFileTemp.Format("%d",iSelection);
	WritePrivateProfileString("CONFIG","COMPORT",sWriteFileTemp,sConfigFilePath);
}

void CConfigToolDlg::OnCbnSelchangeComboBrate()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sWriteFileTemp;
	CString sConfigFilePath=lpCConfigToolDlg->GetExeFilePath()+"config.ini";
	int iSelection=m_ComboBox_BaudRate.GetCurSel();
	sWriteFileTemp.Format("%d",iSelection);
	WritePrivateProfileString("CONFIG","BaudRate",sWriteFileTemp,sConfigFilePath);
}

void CConfigToolDlg::ShowBmp(int sw)
{
	switch(sw)
	{
	case 1:
		g_Status=1;
		SetDlgItemText(IDC_STATIC_STATUS,"READY");
		m_STATIC_Status.SetFont(&Statusfont);
		break;
	case 2:
		g_Status=2;
		SetDlgItemText(IDC_STATIC_STATUS,"RUN");
		m_STATIC_Status.SetFont(&Statusfont);
		break;
	case 3:
		g_Status=3;
		SetDlgItemText(IDC_STATIC_STATUS,"PASS");
		m_STATIC_Status.SetFont(&Statusfont);
		break;
	case 4:
		g_Status=4;
		SetDlgItemText(IDC_STATIC_STATUS,"FAIL");
		m_STATIC_Status.SetFont(&Statusfont);
		break;
	}

}

HBRUSH CConfigToolDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if(pWnd->GetDlgCtrlID()==IDC_STATIC_STATUS)
	{
		switch(g_Status)
		{
		case	READY:	
			//pDC->SetTextColor(RGB(255,255,255));//设置字体颜色：
			pDC->SetTextColor(RGB(0,0,0));//设置字体颜色：
			pDC->SetBkMode(TRANSPARENT);//设置背景模式：这里设置为透明
			return (HBRUSH)::CreateSolidBrush(RGB(179,238,58));//设置文本框底色：（通过返回画刷改变底色）
			break;

		case	RUN:
			pDC->SetTextColor(RGB(0,0,0));
			pDC->SetBkMode(TRANSPARENT);
			return (HBRUSH)::CreateSolidBrush(RGB(255,255,0));
			break;

		case	PASS:
			pDC->SetTextColor(RGB(0,0,0));
			pDC->SetBkMode(TRANSPARENT);
			return (HBRUSH)::CreateSolidBrush(RGB(0,255,0));
			break;

		case	FAIL:
			pDC->SetTextColor(RGB(0,0,0));
			pDC->SetBkMode(TRANSPARENT);
			return (HBRUSH)::CreateSolidBrush(RGB(255,0,0));
			break;
		}

	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

void CConfigToolDlg::ShowInfo(CString sINFO)
{
	SetDlgItemText(IDC_STATIC_Infor,sINFO);
}

BOOL CConfigToolDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN)  
	{  
		switch(pMsg->wParam)  
		{  
		case VK_RETURN:  
			return TRUE;  

		case VK_ESCAPE:  
			return TRUE;  

		default:  
			break;  
		}  
	}  
	return CDialogEx::PreTranslateMessage(pMsg);
}

#pragma endregion

//kill进程from名字
BOOL CConfigToolDlg::KillProcessFromName(CString strProcessName)
{
	//创建进程快照(TH32CS_SNAPPROCESS表示创建所有进程的快照)
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	//PROCESSENTRY32进程快照的结构体
	PROCESSENTRY32 pe;
	//实例化后使用Process32First获取第一个快照的进程前必做的初始化操作
	pe.dwSize = sizeof(PROCESSENTRY32);
	//下面的IF效果同:
	//if(hProcessSnap == INVALID_HANDLE_VALUE)   无效的句柄
	if(!Process32First(hSnapShot,&pe))
	{
		return FALSE;
	}
	//将字符串转换为小写
	strProcessName.MakeLower();
	//如果句柄有效  则一直获取下一个句柄循环下去
	while (Process32Next(hSnapShot,&pe))
	{
		//pe.szExeFile获取当前进程的可执行文件名称
		CString scTmp = pe.szExeFile;
		//将可执行文件名称所有英文字母修改为小写
		scTmp.MakeLower();
		//比较当前进程的可执行文件名称和传递进来的文件名称是否相同
		//相同的话Compare返回0
		if(!scTmp.Compare(strProcessName))
		{
			//从快照进程中获取该进程的PID(即任务管理器中的PID)
			DWORD dwProcessID = pe.th32ProcessID;
			HANDLE hProcess = ::OpenProcess(PROCESS_TERMINATE,FALSE,dwProcessID);
			::TerminateProcess(hProcess,0);
			CloseHandle(hProcess);
			return TRUE;
		}
		scTmp.ReleaseBuffer();
	}
	strProcessName.ReleaseBuffer();
	return FALSE;
}

void CConfigToolDlg::enumUsbPort(ScanPort *lpScanPort)
{
	int Portnum=0,PortIndex=0;
	CString PortName="";
	vector<T_DEV_INFO> vPortInfo_SerialPort;
	vector<T_DEV_INFO> vPortInfo_MODEM;

	for (int i=0;i<20;i++)
	{
		lpScanPort->portinfo_scan[i].iPortNumber=0;
		lpScanPort->portinfo_scan[i].sPortName="";
	}

	m_DevHound.ScanPort(vPortInfo_SerialPort,TYPE_DT_PORT);

	for (int i=0;i<(int)vPortInfo_SerialPort.size();i++)
	{
		lpScanPort->portinfo_scan[i].iPortNumber=vPortInfo_SerialPort[i].nPortNum;
		lpScanPort->portinfo_scan[i].sPortName=vPortInfo_SerialPort[i].szDescription;
		PortIndex++;
	}

	m_DevHound.ScanPort(vPortInfo_MODEM,TYPE_DT_MODEM);

	for (int i=0;i<(int)vPortInfo_MODEM.size();i++)
	{
		lpScanPort->portinfo_scan[i+PortIndex].iPortNumber=vPortInfo_MODEM[i].nPortNum;
		lpScanPort->portinfo_scan[i+PortIndex].sPortName=vPortInfo_MODEM[i].szDescription;
	}

}

void CConfigToolDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString sTime="",sTotalTime="";
	int iTime=0;

	sTotalTime.Format("%02d",nIDEvent);
	//GetDlgItemText(IDC_STATIC_CountDown,sTime);

	if (sTime=="")
	{
		sTime=sTotalTime;
	}
	else
	{
		iTime=atoi(sTime)-1;
		sTime.Format("%02d",iTime);

	}
	//SetDlgItemText(IDC_STATIC_CountDown,sTime);
	if (sTime=="00") KillTimer(nIDEvent);	

	CDialogEx::OnTimer(nIDEvent);
}

void CConfigToolDlg::On32771()
{
	// TODO: 在此添加命令处理程序代码
	//m_EquipmentSet.DoModal();
}

void CConfigToolDlg::clear(unsigned char *pta, int size )//会造成Cstring内存泄漏
{
	while(size>0)
	{
		*pta++ = 0;
		size --;
	}
}

bool CConfigToolDlg::SaveTestLog(CString SN,int iErrCode)
{
	//int index=0;
	//int ilength=0;
	//CString slog="",getchar="",sLogPath="",sErrCode="",sTime="",sindex="",sGetText="",sLOG="";
	//FILE* fp;


	//OutPutDebugLog("------------------------------------------------------------------------");
	//OutPutDebugLog("Save Run Log ...");
	//OutPutDebugLog("------------------------------------------------------------------------"); 
	//
	//CTime time = CTime::GetCurrentTime();
	//sTime = time.Format("%Y-%m-%d_%H-%M-%S");  
	////sLogPath=stu_CONFIG.sLogPath+"RunLOG\\";
	//sLogPath=stu_CONFIG.sExeFilePath + "RunLOG\\";
	//if (SN=="") SN="DummaySN";
	//if(!PathFileExists(sLogPath))
	//{
	//	if(!CreateDirectory(sLogPath,NULL))
	//	{
	//		OutPutDebugLog("CreateDirectory Fail:"+sLogPath);
	//		return false;  
	//	}
	//}
	//if (iErrCode==0)
	//{
	//	sLogPath=sLogPath+"\\"+SN+"_"+sTime+"_PASS"+".txt";
	//}
	//else
	//{
	//	//sErrCode.Format("%s",cErrCode[iErrCode]);
	//	sLogPath=sLogPath+SN+"_"+sTime+"_FAIL_"+sErrCode+".txt";
	//}
	//index=m_DEBUGLOG_Dlg.m_DebugLogForm.GetCount();
	//for (int i=0;i<index;i++)
	//{
	//	getchar="";
	//	m_DEBUGLOG_Dlg.m_DebugLogForm.GetText(i,getchar);
	//	itoa(i,sindex.GetBuffer(MAX_PATH),10);
	//	sindex.ReleaseBuffer();
	//	getchar=sindex+".\t"+getchar+"\n";
	//	slog=slog+getchar;
	//}

	//fp=fopen(sLogPath,"w");
	//if(fp==NULL)
	//{
	//	OutPutDebugLog("Open Log Path Fail: "+sLogPath);
	//	return false;
	//}
	//fwrite(slog,slog.GetLength(),1,fp);
	//fclose(fp);
	//OutPutDebugLog("Save Run Log Success: "+sLogPath);
	return true;
}

bool CConfigToolDlg::GetComPort()
{
	ScanPort stu_ScanPort;
	enumUsbPort(&stu_ScanPort);
	CString Number;
	for (int k=0;k<20;k++)
	{
		if (stu_ScanPort.portinfo_scan[k].iPortNumber==0)
		{
			break;
		}
		else
		{
			Number.Format("COM%d",stu_ScanPort.portinfo_scan[k].iPortNumber);
			m_ComboBox_Port.InsertString(k,Number);
		}
	}
	return true;
}

bool CConfigToolDlg::GetTestItem()
{
	CString sOutput="",Message="",ConfigPath="",ReadBuffer="",sTemp="";
	ConfigPath=stu_CONFIG.sExeFilePath+"TestItem.mdb";
	m_TestItem.bGetTestItemSuccess=false;
	m_TestItem.TestIndex=0;
	CArray<CString,CString>TestItem;
	CArray<CString,CString>TestValue;
	if(!m_MdbControl.OpenDatabase(ConfigPath,"HY888",sOutput))
	{
		Message.Format("打开测试项配置文件失败:%s",sOutput);
		MessageBox(Message,"错误",MB_OK);
		return false;
	}
	if (!ReadColumn("TestParameter","Check_Item",TestItem))
	{
		m_MdbControl.CloseDatebase(sOutput);
		return false;
	}
	if (!ReadColumn("TestParameter","VALUE",TestValue))
	{
		m_MdbControl.CloseDatebase(sOutput);
		return false;
	}
	for (int i=0;i<TestItem.GetSize();i++)
	{
		sTemp=TestItem.GetAt(i);
		if(sTemp.CompareNoCase("CHECK_VMAXBATT")==0)
		{
			m_TestItem.sVMaxBatt=TestValue.GetAt(i);
			if (""==m_TestItem.sVMaxBatt) MessageBox("读取sVMaxBatt失败");
		}
		if(sTemp.CompareNoCase("CHECK_VMINBATT")==0)
		{
			m_TestItem.sVMinBatt=TestValue.GetAt(i);
			if (""==m_TestItem.sVMinBatt) MessageBox("读取sVMaxBatt失败");
		}
		if(sTemp.CompareNoCase("CHECK_PowONTime")==0)
		{
			m_TestItem.sPowOnTime=TestValue.GetAt(i);
			if (""==m_TestItem.sVMinBatt) MessageBox("读取sVMaxBatt失败");
		}
		
	}
	if(!m_MdbControl.CloseDatebase(sOutput))
	{
		MessageBox("关闭配置文件失败！","错误",MB_OK);
		return false;
	}
	m_TestItem.bGetTestItemSuccess=true;
	return true;
}

bool CConfigToolDlg::ReadColumn(CString TableName,CString FieldName,CArray<CString,CString>&ReadData)
{
	CArray<CString,CString>ReadBuffer;
	CString Message="",ErrCode="";
	ReadBuffer.SetSize(0);
	if (!m_MdbControl.ReadDatebase(TableName,FieldName,ReadBuffer,ErrCode))
	{
		Message.Format("读取 %s 失败:%s",FieldName,ErrCode);
		MessageBox(Message,"错误",MB_OK);
		return false;
	}
	else
	{
		if (ReadBuffer.GetSize()!=0)
		{
			ReadData.Copy(ReadBuffer);
		}
		else
		{
			ErrCode="No Data";
			Message.Format("读取 %s 失败:%s",FieldName,ErrCode);
			MessageBox(Message,"错误",MB_OK);
			return false;
		}
	}
	return true;
}

void CConfigToolDlg::BUTStyle()
{
	//按钮显示
	FButton_startfont.CreatePointFont(86,"Verdana");
	//FButton_startfont.CreatePointFont(98,"Calibri");
	m_MFCBUTTON_BSI.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_BSI.SetTextColor(RGB(0,0,205));

	m_MFCBUTTON_BRSI.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_BRSI.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_QSS.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_QSS.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_DCgc.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_DCgc.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_DCap.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_DCap.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_DCspw.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_DCspw.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_DCowh.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_DCowh.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_DCta.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_DCta.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_DCpsdls	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_DCpsdls	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_DChrm.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_DChrm.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_DCpcs.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_DCpcs.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_PRRfri.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_PRRfri.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_PRRfcofri.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_PRRfcofri.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_ASgc	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_AStac	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_ASsa	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_ASsosa	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_ASeid	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_AShbm	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_ASssr	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_ASbad	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_ASosa	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_ASpg	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_ASrdc	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_ASsadr	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_ASser	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_AScd	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_ASgc	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_AStac	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_ASsa	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_ASsosa	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_ASeid	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_AShbm	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_ASssr	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_ASbad	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_ASosa	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_ASpg	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_ASrdc	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_ASsadr	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_ASser	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_AScd	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_IAdops	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_IAepsm	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_IAdips	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_IAips	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_IAdops	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_IAepsm	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_IAdips	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_IAips	.SetTextColor(RGB(0,0,205));

	m_MFCBUTTON_IDSvims	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_IDSidbvs	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_IDSavis	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_IDSvims	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_IDSidbvs	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_IDSavis	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_OSrto	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_OShmc	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_OSwl	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_OSglsc	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_OSucota	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_OScss	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_OSudf	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_OSgs	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_OSer	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_OSrto	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_OShmc	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_OSwl	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_OSglsc	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_OSucota	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_OScss	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_OSudf	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_OSgs	.SetTextColor(RGB(0,0,205));
	m_MFCBUTTON_OSer	.SetTextColor(RGB(0,0,205));

	m_MFCBUTTON_BSI.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_BRSI.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_QSS	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_DCgc	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_DCap	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_DCspw	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_DCowh	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_DCta	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_DCpsdls	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_DChrm	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_DCpcs	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_PRRfri	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_PRRfcofri	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_ASgc	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_AStac	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_ASsa	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_ASsosa	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_ASeid	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_AShbm	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_ASssr	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_ASbad	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_ASosa	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_ASpg	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_ASrdc	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_ASsadr	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_ASser	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_AScd	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_IAdops	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_IAepsm	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_IAdips	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_IAips	.SetFont(&FButton_startfont,1);

	m_MFCBUTTON_IDSvims	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_IDSidbvs	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_IDSavis	.SetFont(&FButton_startfont,1);


	m_MFCBUTTON_OSrto	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_OShmc	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_OSwl	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_OSglsc	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_OSucota	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_OScss	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_OSudf	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_OSgs	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_OSer	.SetFont(&FButton_startfont,1);


	m_MFCBUTTON_ETM	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_SaveAC	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_SAC	.SetFont(&FButton_startfont,1);
	m_Menubutton_RAC.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_OL	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_SC	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_DC	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_PRR	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_AS	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_IA	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_IDS	.SetFont(&FButton_startfont,1);
	m_MFCBUTTON_OS	.SetFont(&FButton_startfont,1);


	m_MFCBUTTON_ETM	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_SaveAC	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_SAC	.SetFaceColor(RGB(176,196,222),1);
	m_Menubutton_RAC	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_OL	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_SC	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_DC	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_PRR	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_AS	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_IA	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_IDS	.SetFaceColor(RGB(176,196,222),1);
	m_MFCBUTTON_OS	.SetFaceColor(RGB(176,196,222),1);


}

void CConfigToolDlg::AUTOSIZEITEM()
{
	CStatic  *temp=(CStatic*)GetDlgItem(IDC_STATIC_Item);  
	CRect   rect;  
	CSize   size(0,0);  
	temp->GetWindowRect(&rect);  

	ScreenToClient(&rect);  
	CClientDC   dc(temp);  
	CFont   *pOldFont=dc.SelectObject(temp->GetFont());  
	CString   str;  
	temp->GetWindowText(str);  
	if(::GetTextExtentPoint32((HDC)dc,str,str.GetLength(),&size))  
	{  
		rect.right=rect.left+size.cx;  
		rect.bottom=rect.top+size.cy;  
		CRect   rectItemdes;  
		GetDlgItem(IDC_STATIC_ItemDes)->GetWindowRect(&rectItemdes);
		ScreenToClient(&rectItemdes);
		rectItemdes.left=rect.right+5;
		rectItemdes.top=rect.top+1;
		rectItemdes.bottom=rect.bottom;
		GetDlgItem(IDC_STATIC_ItemDes)->MoveWindow(rectItemdes);
	}  
	else  
	{
		temp->SetWindowText("GetTextExtentPoint32   fail   to   get   the   size   of   text!");  
	}
	temp->MoveWindow(rect);  
	dc.SelectObject(pOldFont); 
	AUTOSIZETABTOP();
}

void CConfigToolDlg::AUTOSIZETABTOP()
{
	CRect rectItem,rectTab;
	GetDlgItem(IDC_STATIC_Item)->GetWindowRect(&rectItem);//标题的位置
	ScreenToClient(&rectItem);
	GetDlgItem(IDC_TAB_LOG)->GetWindowRect(&rectTab);	//Tab的位置微调
	ScreenToClient(&rectTab);
	rectTab.top=rectItem.bottom+3;
	GetDlgItem(IDC_TAB_LOG)->MoveWindow(&rectTab);	//TAB位置在标题下3
}

void CConfigToolDlg::HideAllWND()
{
	// TODO: 在此添加控件通知处理程序代码
	//隐藏其他所有窗口
	m_SCbsi_Dlg.ShowWindow(FALSE);
	m_SCbsri_Dlg.ShowWindow(FALSE);
	m_SCqss_Dlg.ShowWindow(FALSE);
	m_DCgc_Dlg.ShowWindow(FALSE);
	m_DCap_Dlg.ShowWindow(FALSE);
	m_DCspw_Dlg.ShowWindow(FALSE);
	m_DCowh_Dlg.ShowWindow(FALSE);
	m_DCta_Dlg.ShowWindow(FALSE);
	m_DCpsdls_Dlg.ShowWindow(FALSE);
	m_DChrm_Dlg.ShowWindow(FALSE);
	m_DCpcs_Dlg.ShowWindow(FALSE);
	///////
	m_PRRfri_Dlg.ShowWindow(FALSE);
	m_PRRfcofri_Dlg.ShowWindow(FALSE);
	m_ASgc_Dlg.ShowWindow(FALSE);
	m_AStac_Dlg.ShowWindow(FALSE);
	m_ASsa_Dlg.ShowWindow(FALSE);
	m_ASsosa_Dlg.ShowWindow(FALSE);
	m_ASeid_Dlg.ShowWindow(FALSE);
	m_AShbm_Dlg.ShowWindow(FALSE);
	m_ASssr_Dlg.ShowWindow(FALSE);
	m_ASbad_Dlg.ShowWindow(FALSE);
	m_ASosa_Dlg.ShowWindow(FALSE);
	m_ASpg_Dlg.ShowWindow(FALSE);
	m_ASrdc_Dlg.ShowWindow(FALSE);
	m_ASsadr_Dlg.ShowWindow(FALSE);
	m_ASser_Dlg.ShowWindow(FALSE);
	m_AScd_Dlg.ShowWindow(FALSE);
	m_IAdops_Dlg.ShowWindow(FALSE);
	m_IAepsm_Dlg.ShowWindow(FALSE);
	m_IAdips_Dlg.ShowWindow(FALSE);
	m_IAips_Dlg.ShowWindow(FALSE);
	m_IDSvims_Dlg.ShowWindow(FALSE);
	m_IDSidbvs_Dlg.ShowWindow(FALSE);
	m_IDSavis_Dlg.ShowWindow(FALSE);
	m_OSrto_Dlg.ShowWindow(FALSE);
	m_OShmc_Dlg.ShowWindow(FALSE);
	m_OSwl_Dlg.ShowWindow(FALSE);
	m_OSglsc_Dlg.ShowWindow(FALSE);
	m_OSucota_Dlg.ShowWindow(FALSE);
	m_OScss_Dlg.ShowWindow(FALSE);
	m_OSudf_Dlg.ShowWindow(FALSE);
	m_OSgs_Dlg.ShowWindow(FALSE);
	m_OSer_Dlg.ShowWindow(FALSE);
}

void CConfigToolDlg::HideAllItem()
{
	// TODO: 在此添加控件通知处理程序代码
	//隐藏其他所有窗口
	GetDlgItem(IDC_MFCBUTTON_BSI)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MFCBUTTON_BSRI)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MFCBUTTON_QSS)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_MFCBUTTON_DCgc)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MFCBUTTON_DCap)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MFCBUTTON_DCspw)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MFCBUTTON_DCowh)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MFCBUTTON_DCta)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MFCBUTTON_DCpsdls)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MFCBUTTON_DChrm)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MFCBUTTON_DCpcs)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_MFCBUTTON_PRRfcofri)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MFCBUTTON_PRRfri)->ShowWindow(SW_HIDE);

	GetDlgItem(	IDC_MFCBUTTON_ASgc	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_AStac	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_ASsa	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_ASsosa	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_ASeid	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_AShbm	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_ASssr	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_ASbad	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_ASosa	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_ASpg	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_ASrdc	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_ASsadr	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_ASser	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_AScd	)->ShowWindow(SW_HIDE);

	GetDlgItem(	IDC_MFCBUTTON_IAdops	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_IAepsm	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_IAdips	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_IAips	)->ShowWindow(SW_HIDE);

	GetDlgItem(	IDC_MFCBUTTON_IDSvims	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_IDSidbvs	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_IDSavis	)->ShowWindow(SW_HIDE);

	GetDlgItem(	IDC_MFCBUTTON_OSrto	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_OShmc	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_OSwl	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_OSglsc	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_OSucota	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_OScss	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_OSudf	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_OSgs	)->ShowWindow(SW_HIDE);
	GetDlgItem(	IDC_MFCBUTTON_OSer	)->ShowWindow(SW_HIDE);

}

void CConfigToolDlg::OnBnClickedButtonServerConnection()
{
	CString sStr="";
	HideAllItem();//先隐藏其他项子按钮
	//再显示本项子按钮
	GetDlgItem(IDC_MFCBUTTON_BSI)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MFCBUTTON_BSRI)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MFCBUTTON_QSS)->ShowWindow(SW_SHOW);
	
	CRect recthead,rectfoot;
	CRect rectSC,rectSCBSI,rectSCBSRI,rectQSS;
	CRect rectDC;
	CRect rectPRR;
	CRect rectAS;
	CRect rectIA;
	CRect rectIDS;
	CRect rectOS;
	
	GetDlgItem(IDC_STATIC_3)->GetWindowRect(&recthead);
	ScreenToClient(&recthead);
	GetDlgItem(IDC_STATIC_STATUS)->GetWindowRect(&rectfoot);
	ScreenToClient(&rectfoot);
	//sc
	GetDlgItem(IDC_MFCBUTTON_SC)->GetWindowRect(&rectSC);
	SetDlgItemText(IDC_MFCBUTTON_SC,"Configuration -");
	ScreenToClient(&rectSC);
	rectSC.top=recthead.top+10;
	rectSC.bottom=rectSC.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_SC)->MoveWindow(rectSC); 
	//bsi
	GetDlgItem(IDC_MFCBUTTON_BSI)->GetWindowRect(&rectSCBSI);
	ScreenToClient(&rectSCBSI);
	rectSCBSI.top=rectSC.bottom;
	rectSCBSI.bottom=rectSCBSI.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_BSI)->MoveWindow(rectSCBSI); 
	//bsri
	GetDlgItem(IDC_MFCBUTTON_BSRI)->GetWindowRect(&rectSCBSRI);
	ScreenToClient(&rectSCBSRI);
	rectSCBSRI.top=rectSCBSI.bottom;
	rectSCBSRI.bottom=rectSCBSRI.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_BSRI)->MoveWindow(rectSCBSRI); 
	//qss
	GetDlgItem(IDC_MFCBUTTON_QSS)->GetWindowRect(&rectQSS);
	ScreenToClient(&rectQSS);
	rectQSS.top=rectSCBSRI.bottom;
	rectQSS.bottom=rectQSS.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_QSS)->MoveWindow(rectQSS); 

	//os
	GetDlgItem(IDC_MFCBUTTON_OS)->GetWindowRect(&rectOS);
	ScreenToClient(&rectOS);
	rectOS.bottom=rectfoot.top-3;
	rectOS.top=rectOS.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_OS)->MoveWindow(rectOS,TRUE);	
	SetDlgItemText(IDC_MFCBUTTON_OS,"Other Setting +");
	//ids
	GetDlgItem(IDC_MFCBUTTON_IDS)->GetWindowRect(&rectIDS);
	ScreenToClient(&rectIDS);
	rectIDS.bottom=rectOS.top;
	rectIDS.top=rectIDS.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_IDS)->MoveWindow(rectIDS,TRUE);
	SetDlgItemText(IDC_MFCBUTTON_IDS,"Ignition Detection Settings +");
	//ia
	GetDlgItem(IDC_MFCBUTTON_IA)->GetWindowRect(&rectIA);
	ScreenToClient(&rectIA);
	rectIA.bottom=rectIDS.top;
	rectIA.top=rectIA.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_IA)->MoveWindow(rectIA,TRUE);
	SetDlgItemText(IDC_MFCBUTTON_IA,"IO Application +");
	//as
	GetDlgItem(IDC_MFCBUTTON_AS)->GetWindowRect(&rectAS);
	ScreenToClient(&rectAS);
	rectAS.bottom=rectIA.top;
	rectAS.top=rectAS.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_AS)->MoveWindow(rectAS); 
	SetDlgItemText(IDC_MFCBUTTON_AS,"Alarm Settings +");
	//Prr
	GetDlgItem(IDC_MFCBUTTON_PRR)->GetWindowRect(&rectPRR);
	ScreenToClient(&rectPRR);
	rectPRR.bottom=rectAS.top;
	rectPRR.top=rectPRR.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_PRR)->MoveWindow(rectPRR); 
	SetDlgItemText(IDC_MFCBUTTON_PRR,"Position Settings +");
	//dc
	GetDlgItem(IDC_MFCBUTTON_DC)->GetWindowRect(&rectDC);
	ScreenToClient(&rectDC);
	rectDC.bottom=rectPRR.top;
	rectDC.top=rectDC.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_DC)->MoveWindow(rectDC); 
	SetDlgItemText(IDC_MFCBUTTON_DC,"Device Settings +");
	KeepIniSize();
}

void CConfigToolDlg::OnBnClickedButtonDc()
{
	CString sStr="";
	HideAllItem();//先隐藏其他项子按钮
	//再显示本项子按钮
	GetDlgItem(IDC_MFCBUTTON_DCgc)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MFCBUTTON_DCap)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MFCBUTTON_DCspw)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MFCBUTTON_DCowh)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MFCBUTTON_DCta)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MFCBUTTON_DCpsdls)->ShowWindow(SW_SHOW);
	//GetDlgItem(IDC_MFCBUTTON_DChrm)->ShowWindow(SW_SHOW);
	//GetDlgItem(IDC_MFCBUTTON_DCpcs)->ShowWindow(SW_SHOW);

	CRect rectSC;
	CRect rectDC,rectDCgc,rectDCap,rectDCspw,rectDCowh,rectDCta,rectDCpsdls,rectDChrm,rectDCpcs;
	CRect rectPRR;
	CRect rectAS;
	CRect rectIA;
	CRect rectIDS;
	CRect rectOS;
	CRect recthead,rectfoot;
	GetDlgItem(IDC_STATIC_3)->GetWindowRect(&recthead);
	ScreenToClient(&recthead);
	GetDlgItem(IDC_STATIC_STATUS)->GetWindowRect(&rectfoot);
	ScreenToClient(&rectfoot);
	//sc
	GetDlgItem(IDC_MFCBUTTON_SC)->GetWindowRect(&rectSC);
	SetDlgItemText(IDC_MFCBUTTON_SC,"Configuration +");
	ScreenToClient(&rectSC);
	rectSC.top=recthead.top+10;
	rectSC.bottom=rectSC.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_SC)->MoveWindow(rectSC); 
	//dc
	GetDlgItem(IDC_MFCBUTTON_DC)->GetWindowRect(&rectDC);
	ScreenToClient(&rectDC);
	rectDC.top=rectSC.bottom;
	rectDC.bottom=rectDC.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_DC)->MoveWindow(rectDC); 
	SetDlgItemText(IDC_MFCBUTTON_DC,"Device Settings -");
	//rectDCgc
	GetDlgItem(IDC_MFCBUTTON_DCgc)->GetWindowRect(&rectDCgc);
	ScreenToClient(&rectDCgc);
	rectDCgc.top=rectDC.bottom;
	rectDCgc.bottom=rectDCgc.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_DCgc)->MoveWindow(rectDCgc); 
	//rectDCgc
	GetDlgItem(IDC_MFCBUTTON_DCap)->GetWindowRect(&rectDCap);
	ScreenToClient(&rectDCap);
	rectDCap.top=rectDCgc.bottom;
	rectDCap.bottom=rectDCap.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_DCap)->MoveWindow(rectDCap); 
	//rectDCspw
	GetDlgItem(IDC_MFCBUTTON_DCspw)->GetWindowRect(&rectDCspw);
	ScreenToClient(&rectDCspw);
	rectDCspw.top=rectDCap.bottom;
	rectDCspw.bottom=rectDCspw.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_DCspw)->MoveWindow(rectDCspw); 
	//rectDCowh
	GetDlgItem(IDC_MFCBUTTON_DCowh)->GetWindowRect(&rectDCowh);
	ScreenToClient(&rectDCowh);
	rectDCowh.top=rectDCspw.bottom;
	rectDCowh.bottom=rectDCowh.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_DCowh)->MoveWindow(rectDCowh); 
	//rectDCta
	GetDlgItem(IDC_MFCBUTTON_DCta)->GetWindowRect(&rectDCta);
	ScreenToClient(&rectDCta);
	rectDCta.top=rectDCowh.bottom;
	rectDCta.bottom=rectDCta.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_DCta)->MoveWindow(rectDCta); 
	//rectDCpsdls
	GetDlgItem(IDC_MFCBUTTON_DCpsdls)->GetWindowRect(&rectDCpsdls);
	ScreenToClient(&rectDCpsdls);
	rectDCpsdls.top=rectDCta.bottom;
	rectDCpsdls.bottom=rectDCpsdls.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_DCpsdls)->MoveWindow(rectDCpsdls); 
	////rectDChrm
	//GetDlgItem(IDC_MFCBUTTON_DChrm)->GetWindowRect(&rectDChrm);
	//ScreenToClient(&rectDChrm);
	//rectDChrm.top=rectDCpsdls.bottom;
	//rectDChrm.bottom=rectDChrm.top+g_iWidth;
	//GetDlgItem(IDC_MFCBUTTON_DChrm)->MoveWindow(rectDChrm); 
	//rectDCpcs
	GetDlgItem(IDC_MFCBUTTON_DCpcs)->GetWindowRect(&rectDCpcs);
	ScreenToClient(&rectDCpcs);
	rectDCpcs.top=rectDCpsdls.bottom;
	rectDCpcs.bottom=rectDCpcs.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_DCpcs)->MoveWindow(rectDCpcs);


	//os
	GetDlgItem(IDC_MFCBUTTON_OS)->GetWindowRect(&rectOS);
	ScreenToClient(&rectOS);
	rectOS.bottom=rectfoot.top-3;
	rectOS.top=rectOS.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_OS)->MoveWindow(rectOS,TRUE);	
	SetDlgItemText(IDC_MFCBUTTON_OS,"Other Setting +");
	//ids
	GetDlgItem(IDC_MFCBUTTON_IDS)->GetWindowRect(&rectIDS);
	ScreenToClient(&rectIDS);
	rectIDS.bottom=rectOS.top;
	rectIDS.top=rectIDS.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_IDS)->MoveWindow(rectIDS,TRUE);
	SetDlgItemText(IDC_MFCBUTTON_IDS,"Ignition Detection Settings +");
	//ia
	GetDlgItem(IDC_MFCBUTTON_IA)->GetWindowRect(&rectIA);
	ScreenToClient(&rectIA);
	rectIA.bottom=rectIDS.top;
	rectIA.top=rectIA.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_IA)->MoveWindow(rectIA,TRUE);
	SetDlgItemText(IDC_MFCBUTTON_IA,"IO Application +");
	//as
	GetDlgItem(IDC_MFCBUTTON_AS)->GetWindowRect(&rectAS);
	ScreenToClient(&rectAS);
	rectAS.bottom=rectIA.top;
	rectAS.top=rectAS.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_AS)->MoveWindow(rectAS); 
	SetDlgItemText(IDC_MFCBUTTON_AS,"Alarm Settings +");
	//Prr
	GetDlgItem(IDC_MFCBUTTON_PRR)->GetWindowRect(&rectPRR);
	ScreenToClient(&rectPRR);
	rectPRR.bottom=rectAS.top;
	rectPRR.top=rectPRR.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_PRR)->MoveWindow(rectPRR); 
	SetDlgItemText(IDC_MFCBUTTON_PRR,"Position Settings +");
	KeepIniSize();
}

void CConfigToolDlg::OnBnClickedButtonPrr()
{
	CString sStr="";
	HideAllItem();//先隐藏其他项子按钮
	//再显示本项子按钮
	GetDlgItem(IDC_MFCBUTTON_PRRfri)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MFCBUTTON_PRRfcofri)->ShowWindow(SW_SHOW);
	CRect rectSC;
	CRect rectDC;
	CRect rectPRR,rectPRRfri,rectPRRfcofri;
	CRect rectAS;
	CRect rectIA;
	CRect rectIDS;
	CRect rectOS;
	CRect recthead,rectfoot;
	GetDlgItem(IDC_STATIC_3)->GetWindowRect(&recthead);
	ScreenToClient(&recthead);
	GetDlgItem(IDC_STATIC_STATUS)->GetWindowRect(&rectfoot);
	ScreenToClient(&rectfoot);
	//sc
	GetDlgItem(IDC_MFCBUTTON_SC)->GetWindowRect(&rectSC);
	SetDlgItemText(IDC_MFCBUTTON_SC,"Configuration +");
	ScreenToClient(&rectSC);
	rectSC.top=recthead.top+10;
	rectSC.bottom=rectSC.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_SC)->MoveWindow(rectSC); 
	//dc
	GetDlgItem(IDC_MFCBUTTON_DC)->GetWindowRect(&rectDC);
	ScreenToClient(&rectDC);
	rectDC.top=rectSC.bottom;
	rectDC.bottom=rectDC.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_DC)->MoveWindow(rectDC); 
	SetDlgItemText(IDC_MFCBUTTON_DC,"Device Settings +");
	//prr
	GetDlgItem(IDC_MFCBUTTON_PRR)->GetWindowRect(&rectPRR);
	ScreenToClient(&rectPRR);
	rectPRR.top=rectDC.bottom;
	rectPRR.bottom=rectPRR.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_PRR)->MoveWindow(rectPRR); 
	SetDlgItemText(IDC_MFCBUTTON_PRR,"Position Settings -");
	//rectPRRfri
	GetDlgItem(IDC_MFCBUTTON_PRRfri)->GetWindowRect(&rectPRRfri);
	ScreenToClient(&rectPRRfri);
	rectPRRfri.top=rectPRR.bottom;
	rectPRRfri.bottom=rectPRRfri.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_PRRfri)->MoveWindow(rectPRRfri); 
	//rectPRRfcofri
	GetDlgItem(IDC_MFCBUTTON_PRRfcofri)->GetWindowRect(&rectPRRfcofri);
	ScreenToClient(&rectPRRfcofri);
	rectPRRfcofri.top=rectPRRfri.bottom;
	rectPRRfcofri.bottom=rectPRRfcofri.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_PRRfcofri)->MoveWindow(rectPRRfcofri); 

	//os
	GetDlgItem(IDC_MFCBUTTON_OS)->GetWindowRect(&rectOS);
	ScreenToClient(&rectOS);
	rectOS.bottom=rectfoot.top-3;
	rectOS.top=rectOS.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_OS)->MoveWindow(rectOS,TRUE);	
	SetDlgItemText(IDC_MFCBUTTON_OS,"Other Setting +");
	//ids
	GetDlgItem(IDC_MFCBUTTON_IDS)->GetWindowRect(&rectIDS);
	ScreenToClient(&rectIDS);
	rectIDS.bottom=rectOS.top;
	rectIDS.top=rectIDS.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_IDS)->MoveWindow(rectIDS,TRUE);
	SetDlgItemText(IDC_MFCBUTTON_IDS,"Ignition Detection Settings +");
	//ia
	GetDlgItem(IDC_MFCBUTTON_IA)->GetWindowRect(&rectIA);
	ScreenToClient(&rectIA);
	rectIA.bottom=rectIDS.top;
	rectIA.top=rectIA.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_IA)->MoveWindow(rectIA,TRUE);
	SetDlgItemText(IDC_MFCBUTTON_IA,"IO Application +");
	//as
	GetDlgItem(IDC_MFCBUTTON_AS)->GetWindowRect(&rectAS);
	ScreenToClient(&rectAS);
	rectAS.bottom=rectIA.top;
	rectAS.top=rectAS.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_AS)->MoveWindow(rectAS); 
	SetDlgItemText(IDC_MFCBUTTON_AS,"Alarm Settings +");
	KeepIniSize();

}

void CConfigToolDlg::OnBnClickedButtonAs()
{
	CString sStr="";
	HideAllItem();//先隐藏其他项子按钮
	//再显示本项子按钮
	GetDlgItem(	IDC_MFCBUTTON_ASgc	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_AStac	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_ASsa	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_ASsosa	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_ASeid	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_AShbm	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_ASssr	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_ASbad	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_ASosa	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_ASpg	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_ASrdc	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_ASsadr	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_ASser	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_AScd	)->ShowWindow(SW_SHOW);

	CRect rectSC;
	CRect rectDC;
	CRect rectPRR;
	CRect rectAS,rectASgc,	rectAStac,	rectASsa,	rectASsosa,	rectASeid,	rectAShbm,	rectASssr,	rectASbad,	rectASosa,	rectASpg,	rectASrdc,	rectASsadr,	rectASser,	rectAScd;
	CRect rectIA;
	CRect rectIDS;
	CRect rectOS;
	CRect recthead,rectfoot;
	GetDlgItem(IDC_STATIC_3)->GetWindowRect(&recthead);
	ScreenToClient(&recthead);
	GetDlgItem(IDC_STATIC_STATUS)->GetWindowRect(&rectfoot);
	ScreenToClient(&rectfoot);
	//sc
	GetDlgItem(IDC_MFCBUTTON_SC)->GetWindowRect(&rectSC);
	SetDlgItemText(IDC_MFCBUTTON_SC,"Configuration +");
	ScreenToClient(&rectSC);
	rectSC.top=recthead.top+10;
	rectSC.bottom=rectSC.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_SC)->MoveWindow(rectSC); 
	//dc
	GetDlgItem(IDC_MFCBUTTON_DC)->GetWindowRect(&rectDC);
	ScreenToClient(&rectDC);
	rectDC.top=rectSC.bottom;
	rectDC.bottom=rectDC.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_DC)->MoveWindow(rectDC); 
	SetDlgItemText(IDC_MFCBUTTON_PRR,"Position Settings +");
	//prr
	GetDlgItem(IDC_MFCBUTTON_PRR)->GetWindowRect(&rectPRR);
	ScreenToClient(&rectPRR);
	rectPRR.top=rectDC.bottom;
	rectPRR.bottom=rectPRR.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_PRR)->MoveWindow(rectPRR); 
	SetDlgItemText(IDC_MFCBUTTON_PRR,"Position Settings +"); 
	//as
	GetDlgItem(IDC_MFCBUTTON_AS)->GetWindowRect(&rectAS);
	ScreenToClient(&rectAS);
	rectAS.top=rectPRR.bottom;
	rectAS.bottom=rectAS.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_AS)->MoveWindow(rectAS); 
	SetDlgItemText(IDC_MFCBUTTON_AS,"Alarm Settings -");
	//rectASgc
	GetDlgItem(IDC_MFCBUTTON_ASgc)->GetWindowRect(&rectASgc);
	ScreenToClient(&rectASgc);
	rectASgc.top=rectAS.bottom;
	rectASgc.bottom=rectASgc.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_ASgc)->MoveWindow(rectASgc); 
	//rectAStac
	GetDlgItem(IDC_MFCBUTTON_AStac)->GetWindowRect(&rectAStac);
	ScreenToClient(&rectAStac);
	rectAStac.top=rectASgc.bottom;
	rectAStac.bottom=rectAStac.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_AStac)->MoveWindow(rectAStac);
	//rectASsa
	GetDlgItem(IDC_MFCBUTTON_ASsa)->GetWindowRect(&rectASsa);
	ScreenToClient(&rectASsa);
	rectASsa.top=rectAStac.bottom;
	rectASsa.bottom=rectASsa.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_ASsa)->MoveWindow(rectASsa);
	//rectASsosa
	GetDlgItem(IDC_MFCBUTTON_ASsosa)->GetWindowRect(&rectASsosa);
	ScreenToClient(&rectASsosa);
	rectASsosa.top=rectASsa.bottom;
	rectASsosa.bottom=rectASsosa.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_ASsosa)->MoveWindow(rectASsosa);
	//rectASeid
	GetDlgItem(IDC_MFCBUTTON_ASeid)->GetWindowRect(&rectASeid);
	ScreenToClient(&rectASeid);
	rectASeid.top=rectASsosa.bottom;
	rectASeid.bottom=rectASeid.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_ASeid)->MoveWindow(rectASeid);
	//rectAShbm
	GetDlgItem(IDC_MFCBUTTON_AShbm)->GetWindowRect(&rectAShbm);
	ScreenToClient(&rectAShbm);
	rectAShbm.top=rectASeid.bottom;
	rectAShbm.bottom=rectAShbm.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_AShbm)->MoveWindow(rectAShbm);
	//rectASssr
	GetDlgItem(IDC_MFCBUTTON_ASssr)->GetWindowRect(&rectASssr);
	ScreenToClient(&rectASssr);
	rectASssr.top=rectAShbm.bottom;
	rectASssr.bottom=rectASssr.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_ASssr)->MoveWindow(rectASssr);
	//rectASbad
	GetDlgItem(IDC_MFCBUTTON_ASbad)->GetWindowRect(&rectASbad);
	ScreenToClient(&rectASbad);
	rectASbad.top=rectASssr.bottom;
	rectASbad.bottom=rectASbad.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_ASbad)->MoveWindow(rectASbad);
	//rectASosa
	GetDlgItem(IDC_MFCBUTTON_ASosa)->GetWindowRect(&rectASosa);
	ScreenToClient(&rectASosa);
	rectASosa.top=rectASbad.bottom;
	rectASosa.bottom=rectASosa.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_ASosa)->MoveWindow(rectASosa);
	//rectASpg
	GetDlgItem(IDC_MFCBUTTON_ASpg)->GetWindowRect(&rectASpg);
	ScreenToClient(&rectASpg);
	rectASpg.top=rectASosa.bottom;
	rectASpg.bottom=rectASpg.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_ASpg)->MoveWindow(rectASpg);
	//rectASrdc
	GetDlgItem(IDC_MFCBUTTON_ASrdc)->GetWindowRect(&rectASrdc);
	ScreenToClient(&rectASrdc);
	rectASrdc.top=rectASpg.bottom;
	rectASrdc.bottom=rectASrdc.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_ASrdc)->MoveWindow(rectASrdc);
	//rectASsadr
	GetDlgItem(IDC_MFCBUTTON_ASsadr)->GetWindowRect(&rectASsadr);
	ScreenToClient(&rectASsadr);
	rectASsadr.top=rectASrdc.bottom;
	rectASsadr.bottom=rectASsadr.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_ASsadr)->MoveWindow(rectASsadr);
	//rectASser
	GetDlgItem(IDC_MFCBUTTON_ASser)->GetWindowRect(&rectASser);
	ScreenToClient(&rectASser);
	rectASser.top=rectASsadr.bottom;
	rectASser.bottom=rectASser.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_ASser)->MoveWindow(rectASser);
	//rectAScd
	GetDlgItem(IDC_MFCBUTTON_AScd)->GetWindowRect(&rectAScd);
	ScreenToClient(&rectAScd);
	rectAScd.top=rectASser.bottom;
	rectAScd.bottom=rectAScd.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_AScd)->MoveWindow(rectAScd);

	//os
	GetDlgItem(IDC_MFCBUTTON_OS)->GetWindowRect(&rectOS);
	ScreenToClient(&rectOS);
	rectOS.bottom=rectfoot.top-3;
	rectOS.top=rectOS.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_OS)->MoveWindow(rectOS,TRUE);	
	SetDlgItemText(IDC_MFCBUTTON_OS,"Other Setting +");
	//ids
	GetDlgItem(IDC_MFCBUTTON_IDS)->GetWindowRect(&rectIDS);
	ScreenToClient(&rectIDS);
	rectIDS.bottom=rectOS.top;
	rectIDS.top=rectIDS.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_IDS)->MoveWindow(rectIDS,TRUE);
	SetDlgItemText(IDC_MFCBUTTON_IDS,"Ignition Detection Settings +");
	//ia
	GetDlgItem(IDC_MFCBUTTON_IA)->GetWindowRect(&rectIA);
	ScreenToClient(&rectIA);
	rectIA.bottom=rectIDS.top;
	rectIA.top=rectIA.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_IA)->MoveWindow(rectIA,TRUE);
	SetDlgItemText(IDC_MFCBUTTON_IA,"IO Application +");
	KeepIniSize();
}

void CConfigToolDlg::OnBnClickedButtonIa()
{
	CString sStr="";
	HideAllItem();//先隐藏其他项子按钮
	//再显示本项子按钮
	GetDlgItem(	IDC_MFCBUTTON_IAdops	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_IAepsm	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_IAdips	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_IAips	)->ShowWindow(SW_SHOW);

	CRect rectSC;
	CRect rectDC;
	CRect rectPRR;
	CRect rectAS;
	CRect rectIA,rectIAdops,rectIAepsm,	rectIAdips,	rectIAips;
	CRect rectIDS;
	CRect rectOS;
	CRect recthead,rectfoot;
	GetDlgItem(IDC_STATIC_3)->GetWindowRect(&recthead);
	ScreenToClient(&recthead);
	GetDlgItem(IDC_STATIC_STATUS)->GetWindowRect(&rectfoot);
	ScreenToClient(&rectfoot);
	//sc
	GetDlgItem(IDC_MFCBUTTON_SC)->GetWindowRect(&rectSC);
	SetDlgItemText(IDC_MFCBUTTON_SC,"Configuration +");
	ScreenToClient(&rectSC);
	rectSC.top=recthead.top+10;
	rectSC.bottom=rectSC.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_SC)->MoveWindow(rectSC); 
	//dc
	GetDlgItem(IDC_MFCBUTTON_DC)->GetWindowRect(&rectDC);
	ScreenToClient(&rectDC);
	rectDC.top=rectSC.bottom;
	rectDC.bottom=rectDC.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_DC)->MoveWindow(rectDC); 
	SetDlgItemText(IDC_MFCBUTTON_PRR,"Position Settings +");
	//prr
	GetDlgItem(IDC_MFCBUTTON_PRR)->GetWindowRect(&rectPRR);
	ScreenToClient(&rectPRR);
	rectPRR.top=rectDC.bottom;
	rectPRR.bottom=rectPRR.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_PRR)->MoveWindow(rectPRR); 
	SetDlgItemText(IDC_MFCBUTTON_PRR,"Position Settings +"); 
	//as
	GetDlgItem(IDC_MFCBUTTON_AS)->GetWindowRect(&rectAS);
	ScreenToClient(&rectAS);
	rectAS.top=rectPRR.bottom;
	rectAS.bottom=rectAS.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_AS)->MoveWindow(rectAS); 
	SetDlgItemText(IDC_MFCBUTTON_AS,"Alarm Settings +");
	//ia
	GetDlgItem(IDC_MFCBUTTON_IA)->GetWindowRect(&rectIA);
	ScreenToClient(&rectIA);
	rectIA.top=rectAS.bottom;
	rectIA.bottom=rectIA.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_IA)->MoveWindow(rectIA,TRUE);
	SetDlgItemText(IDC_MFCBUTTON_IA,"IO Application -");

	//rectIAdops
	GetDlgItem(IDC_MFCBUTTON_IAdops)->GetWindowRect(&rectIAdops);
	ScreenToClient(&rectIAdops);
	rectIAdops.top=rectIA.bottom;
	rectIAdops.bottom=rectIAdops.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_IAdops)->MoveWindow(rectIAdops);
	//rectIAepsm
	GetDlgItem(IDC_MFCBUTTON_IAepsm)->GetWindowRect(&rectIAepsm);
	ScreenToClient(&rectIAepsm);
	rectIAepsm.top=rectIAdops.bottom;
	rectIAepsm.bottom=rectIAepsm.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_IAepsm)->MoveWindow(rectIAepsm);
	//rectIAdips
	GetDlgItem(IDC_MFCBUTTON_IAdips)->GetWindowRect(&rectIAdips);
	ScreenToClient(&rectIAdips);
	rectIAdips.top=rectIAepsm.bottom;
	rectIAdips.bottom=rectIAdips.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_IAdips)->MoveWindow(rectIAdips);
	//rectIAips
	GetDlgItem(IDC_MFCBUTTON_IAips)->GetWindowRect(&rectIAips);
	ScreenToClient(&rectIAips);
	rectIAips.top=rectIAdips.bottom;
	rectIAips.bottom=rectIAips.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_IAips)->MoveWindow(rectIAips);

	//os
	GetDlgItem(IDC_MFCBUTTON_OS)->GetWindowRect(&rectOS);
	ScreenToClient(&rectOS);
	rectOS.bottom=rectfoot.top-3;
	rectOS.top=rectOS.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_OS)->MoveWindow(rectOS,TRUE);	
	SetDlgItemText(IDC_MFCBUTTON_OS,"Other Setting +");
	//ids
	GetDlgItem(IDC_MFCBUTTON_IDS)->GetWindowRect(&rectIDS);
	ScreenToClient(&rectIDS);
	rectIDS.bottom=rectOS.top;
	rectIDS.top=rectIDS.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_IDS)->MoveWindow(rectIDS,TRUE);
	SetDlgItemText(IDC_MFCBUTTON_IDS,"Ignition Detection Settings +");
	KeepIniSize();
}

void CConfigToolDlg::OnBnClickedButtonIds()
{
	CString sStr="";
	HideAllItem();//先隐藏其他项子按钮
	//再显示本项子按钮
	GetDlgItem(	IDC_MFCBUTTON_IDSvims	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_IDSidbvs	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_IDSavis	)->ShowWindow(SW_SHOW);
	CRect rectSC;
	CRect rectDC;
	CRect rectPRR;
	CRect rectAS;
	CRect rectIA;
	CRect rectIDS,rectIDSvims,rectIDSidbvs,rectIDSavis;
	CRect rectOS;
	CRect recthead,rectfoot;
	GetDlgItem(IDC_STATIC_3)->GetWindowRect(&recthead);
	ScreenToClient(&recthead);
	GetDlgItem(IDC_STATIC_STATUS)->GetWindowRect(&rectfoot);
	ScreenToClient(&rectfoot);
	//sc
	GetDlgItem(IDC_MFCBUTTON_SC)->GetWindowRect(&rectSC);
	SetDlgItemText(IDC_MFCBUTTON_SC,"Configuration +");
	ScreenToClient(&rectSC);
	rectSC.top=recthead.top+10;
	rectSC.bottom=rectSC.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_SC)->MoveWindow(rectSC); 
	//dc
	GetDlgItem(IDC_MFCBUTTON_DC)->GetWindowRect(&rectDC);
	ScreenToClient(&rectDC);
	rectDC.top=rectSC.bottom;
	rectDC.bottom=rectDC.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_DC)->MoveWindow(rectDC); 
	SetDlgItemText(IDC_MFCBUTTON_PRR,"Position Settings +");
	//prr
	GetDlgItem(IDC_MFCBUTTON_PRR)->GetWindowRect(&rectPRR);
	ScreenToClient(&rectPRR);
	rectPRR.top=rectDC.bottom;
	rectPRR.bottom=rectPRR.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_PRR)->MoveWindow(rectPRR); 
	SetDlgItemText(IDC_MFCBUTTON_PRR,"Position Settings +"); 
	//as
	GetDlgItem(IDC_MFCBUTTON_AS)->GetWindowRect(&rectAS);
	ScreenToClient(&rectAS);
	rectAS.top=rectPRR.bottom;
	rectAS.bottom=rectAS.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_AS)->MoveWindow(rectAS); 
	SetDlgItemText(IDC_MFCBUTTON_AS,"Alarm Settings +");
	//ia
	GetDlgItem(IDC_MFCBUTTON_IA)->GetWindowRect(&rectIA);
	ScreenToClient(&rectIA);
	rectIA.top=rectAS.bottom;
	rectIA.bottom=rectIA.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_IA)->MoveWindow(rectIA,TRUE);
	SetDlgItemText(IDC_MFCBUTTON_IA,"IO Application +");
	//ids
	GetDlgItem(IDC_MFCBUTTON_IDS)->GetWindowRect(&rectIDS);
	ScreenToClient(&rectIDS);
	rectIDS.top=rectIA.bottom;
	rectIDS.bottom=rectIDS.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_IDS)->MoveWindow(rectIDS,TRUE);
	SetDlgItemText(IDC_MFCBUTTON_IDS,"Ignition Detection Settings -");
	//rectIDSvims
	GetDlgItem(IDC_MFCBUTTON_IDSvims)->GetWindowRect(&rectIDSvims);
	ScreenToClient(&rectIDSvims);
	rectIDSvims.top=rectIDS.bottom;
	rectIDSvims.bottom=rectIDSvims.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_IDSvims)->MoveWindow(rectIDSvims);
	//rectIDSidbvs
	GetDlgItem(IDC_MFCBUTTON_IDSidbvs)->GetWindowRect(&rectIDSidbvs);
	ScreenToClient(&rectIDSidbvs);
	rectIDSidbvs.top=rectIDSvims.bottom;
	rectIDSidbvs.bottom=rectIDSidbvs.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_IDSidbvs)->MoveWindow(rectIDSidbvs);
	//rectIDSavis
	GetDlgItem(IDC_MFCBUTTON_IDSavis)->GetWindowRect(&rectIDSavis);
	ScreenToClient(&rectIDSavis);
	rectIDSavis.top=rectIDSidbvs.bottom;
	rectIDSavis.bottom=rectIDSavis.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_IDSavis)->MoveWindow(rectIDSavis);

	//os
	GetDlgItem(IDC_MFCBUTTON_OS)->GetWindowRect(&rectOS);
	ScreenToClient(&rectOS);
	rectOS.bottom=rectfoot.top-3;
	rectOS.top=rectOS.bottom-g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_OS)->MoveWindow(rectOS,TRUE);	
	SetDlgItemText(IDC_MFCBUTTON_OS,"Other Setting +");
	KeepIniSize();
}

void CConfigToolDlg::OnBnClickedButtonOs()
{
	CString sStr="";
	HideAllItem();//先隐藏其他项子按钮
	//再显示本项子按钮
	GetDlgItem(	IDC_MFCBUTTON_OSrto	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_OShmc	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_OSwl	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_OSglsc	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_OSucota	)->ShowWindow(SW_SHOW);
	//GetDlgItem(	IDC_MFCBUTTON_OScss	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_OSudf	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_OSgs	)->ShowWindow(SW_SHOW);
	GetDlgItem(	IDC_MFCBUTTON_OSer	)->ShowWindow(SW_SHOW);
	CRect rectSC;
	CRect rectDC;
	CRect rectPRR;
	CRect rectAS;
	CRect rectIA;
	CRect rectIDS;
	CRect rectOS,rectOSrto,	rectOShmc,	rectOSwl,rectOSglsc,rectOSucota,rectOScss,rectOSudf,rectOSgs,rectOSer;
	CRect recthead,rectfoot;
	GetDlgItem(IDC_STATIC_3)->GetWindowRect(&recthead);
	ScreenToClient(&recthead);
	GetDlgItem(IDC_STATIC_STATUS)->GetWindowRect(&rectfoot);
	ScreenToClient(&rectfoot);
	//sc
	GetDlgItem(IDC_MFCBUTTON_SC)->GetWindowRect(&rectSC);
	SetDlgItemText(IDC_MFCBUTTON_SC,"Configuration +");
	ScreenToClient(&rectSC);
	rectSC.top=recthead.top+10;
	rectSC.bottom=rectSC.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_SC)->MoveWindow(rectSC); 
	//dc
	GetDlgItem(IDC_MFCBUTTON_DC)->GetWindowRect(&rectDC);
	ScreenToClient(&rectDC);
	rectDC.top=rectSC.bottom;
	rectDC.bottom=rectDC.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_DC)->MoveWindow(rectDC); 
	SetDlgItemText(IDC_MFCBUTTON_PRR,"Position Settings +");
	//prr
	GetDlgItem(IDC_MFCBUTTON_PRR)->GetWindowRect(&rectPRR);
	ScreenToClient(&rectPRR);
	rectPRR.top=rectDC.bottom;
	rectPRR.bottom=rectPRR.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_PRR)->MoveWindow(rectPRR); 
	SetDlgItemText(IDC_MFCBUTTON_PRR,"Position Settings +"); 
	//as
	GetDlgItem(IDC_MFCBUTTON_AS)->GetWindowRect(&rectAS);
	ScreenToClient(&rectAS);
	rectAS.top=rectPRR.bottom;
	rectAS.bottom=rectAS.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_AS)->MoveWindow(rectAS); 
	SetDlgItemText(IDC_MFCBUTTON_AS,"Alarm Settings +");
	//ia
	GetDlgItem(IDC_MFCBUTTON_IA)->GetWindowRect(&rectIA);
	ScreenToClient(&rectIA);
	rectIA.top=rectAS.bottom;
	rectIA.bottom=rectIA.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_IA)->MoveWindow(rectIA,TRUE);
	SetDlgItemText(IDC_MFCBUTTON_IA,"IO Application +");
	//ids
	GetDlgItem(IDC_MFCBUTTON_IDS)->GetWindowRect(&rectIDS);
	ScreenToClient(&rectIDS);
	rectIDS.top=rectIA.bottom;
	rectIDS.bottom=rectIDS.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_IDS)->MoveWindow(rectIDS,TRUE);
	SetDlgItemText(IDC_MFCBUTTON_IDS,"Ignition Detection Settings +");
	//os
	GetDlgItem(IDC_MFCBUTTON_OS)->GetWindowRect(&rectOS);
	ScreenToClient(&rectOS);
	rectOS.top=rectIDS.bottom;
	rectOS.bottom=rectOS.top+g_iBUTWidth;
	GetDlgItem(IDC_MFCBUTTON_OS)->MoveWindow(rectOS,TRUE);	
	SetDlgItemText(IDC_MFCBUTTON_OS,"Other Setting -");
	//rectOSrto
	GetDlgItem(IDC_MFCBUTTON_OSrto)->GetWindowRect(&rectOSrto);
	ScreenToClient(&rectOSrto);
	rectOSrto.top=rectOS.bottom;
	rectOSrto.bottom=rectOSrto.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_OSrto)->MoveWindow(rectOSrto);
	//rectOShmc
	GetDlgItem(IDC_MFCBUTTON_OShmc)->GetWindowRect(&rectOShmc);
	ScreenToClient(&rectOShmc);
	rectOShmc.top=rectOSrto.bottom;
	rectOShmc.bottom=rectOShmc.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_OShmc)->MoveWindow(rectOShmc);
	//rectOSwl
	GetDlgItem(IDC_MFCBUTTON_OSwl)->GetWindowRect(&rectOSwl);
	ScreenToClient(&rectOSwl);
	rectOSwl.top=rectOShmc.bottom;
	rectOSwl.bottom=rectOSwl.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_OSwl)->MoveWindow(rectOSwl);
	//rectOSglsc
	GetDlgItem(IDC_MFCBUTTON_OSglsc)->GetWindowRect(&rectOSglsc);
	ScreenToClient(&rectOSglsc);
	rectOSglsc.top=rectOSwl.bottom;
	rectOSglsc.bottom=rectOSglsc.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_OSglsc)->MoveWindow(rectOSglsc);
	//rectOSucota
	GetDlgItem(IDC_MFCBUTTON_OSucota)->GetWindowRect(&rectOSucota);
	ScreenToClient(&rectOSucota);
	rectOSucota.top=rectOSglsc.bottom;
	rectOSucota.bottom=rectOSucota.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_OSucota)->MoveWindow(rectOSucota);
	//rectOScss
	//GetDlgItem(IDC_MFCBUTTON_OScss)->GetWindowRect(&rectOScss);
	//ScreenToClient(&rectOScss);
	//rectOScss.top=rectOSucota.bottom;
	//rectOScss.bottom=rectOScss.top+g_iWidth;
	//GetDlgItem(IDC_MFCBUTTON_OScss)->MoveWindow(rectOScss);
	//rectOSudf
	GetDlgItem(IDC_MFCBUTTON_OSudf)->GetWindowRect(&rectOSudf);
	ScreenToClient(&rectOSudf);
	rectOSudf.top=rectOSucota.bottom;
	rectOSudf.bottom=rectOSudf.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_OSudf)->MoveWindow(rectOSudf);
	//rectOSgs
	GetDlgItem(IDC_MFCBUTTON_OSgs)->GetWindowRect(&rectOSgs);
	ScreenToClient(&rectOSgs);
	rectOSgs.top=rectOSudf.bottom;
	rectOSgs.bottom=rectOSgs.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_OSgs)->MoveWindow(rectOSgs);
	//rectOSer
	GetDlgItem(IDC_MFCBUTTON_OSer)->GetWindowRect(&rectOSer);
	ScreenToClient(&rectOSer);
	rectOSer.top=rectOSgs.bottom;
	rectOSer.bottom=rectOSer.top+g_iWidth;
	GetDlgItem(IDC_MFCBUTTON_OSer)->MoveWindow(rectOSer);
	KeepIniSize();
}

void CConfigToolDlg::OnBnClickedMfcbuttonEtm()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sTemp="";
	if (GetDlgItemText(IDC_MFCBUTTON_ETM,sTemp),sTemp=="Connect Device")
	{
		m_MYWORK.Thread_EenterTestMode_START();
	}
	else
	{
		m_MYWORK.Thread_Reboot_START();
	}
}

void CConfigToolDlg::OnBnClickedMfcbuttonBsi()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_SCbsi_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
	m_SCbsi_Dlg	.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_SCbsi_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;	
	SetDlgItemText(IDC_STATIC_Item,"Bearer Settings");
	AUTOSIZEITEM();	//确定好标题的位置
	SetDlgItemText(IDC_STATIC_Item,"Bearer Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure the parameters for network connection.");
}

void CConfigToolDlg::OnBnClickedMfcbuttonBsri()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_SCbsri_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_SCbsri_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_SCbsri_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;	
	SetDlgItemText(IDC_STATIC_Item,"Backend Server Register Information");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Backend Server Register Information");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure where and how to report all the messages.");

}

void CConfigToolDlg::OnBnClickedMfcbuttonQss()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_SCqss_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_SCqss_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_SCqss_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Quick Start Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Quick Start Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure the parameeters of network connection and backend server information in one command.");

}

void CConfigToolDlg::OnBnClickedMfcbuttonDcgc()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_DCgc_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_DCgc_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_DCgc_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;	
	SetDlgItemText(IDC_STATIC_Item,"Global Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Global Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure the global parameters.");

}

void CConfigToolDlg::OnBnClickedMfcbuttonDcap()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_DCap_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_DCap_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_DCap_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;	
	SetDlgItemText(IDC_STATIC_Item,"Auto Unlock PIN");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Auto Unlock PIN");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure the auto unlock pin of unit.");
}

void CConfigToolDlg::OnBnClickedMfcbuttonDcspw()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_DCspw_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_DCspw_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_DCspw_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Device Watchdog");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Device Watchdog");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to reboot unit in a time based manner or upon ignition.");
}

void CConfigToolDlg::OnBnClickedMfcbuttonDcowh()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_DCowh_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_DCowh_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_DCowh_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Outside Working Hour");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Outside Working Hour");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to define the working hour and the working mode to protect the whereabout privacy");
}

void CConfigToolDlg::OnBnClickedMfcbuttonDcta()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_DCta_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_DCta_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_DCta_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Time Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Time Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to adjust the local time of unit");
}

void CConfigToolDlg::OnBnClickedMfcbuttonDcpsdls()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_DCpsdls_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_DCpsdls_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_DCpsdls_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Preserve Device State");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Preserve Device State");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to Preserve Device State for terminal.");
}


void CConfigToolDlg::OnBnClickedMfcbuttonDchrm()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_DChrm_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_DChrm_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_DChrm_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Hex Reort Mark");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Hex Reort Mark");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to set five kinds of hex report mask.");
}


void CConfigToolDlg::OnBnClickedMfcbuttonDcpcs()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_DCpcs_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_DCpcs_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_DCpcs_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"PPP Connection Setting");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"PPP Connection Setting");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to set the PPP connection behavior.");
}


void CConfigToolDlg::OnBnClickedMfcbuttonPrrfri()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_PRRfri_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_PRRfri_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_PRRfri_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Fixed Report Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Fixed Report Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure the parameters of scheduled report ");
}


void CConfigToolDlg::OnBnClickedMfcbuttonPrrfcofri()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_PRRfcofri_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_PRRfcofri_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_PRRfcofri_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Change Fixed Report");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Change Fixed Report");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to change the parameters of fixed report");
}

void CConfigToolDlg::OnBnClickedMfcbuttonAsgc()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_ASgc_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_ASgc_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_ASgc_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Geo-Fence Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Geo-Fence Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure the parameters of Geo-fence.");
}


void CConfigToolDlg::OnBnClickedMfcbuttonAstac()
{

	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_AStac_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_AStac_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_AStac_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Tow Alarm Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Tow Alarm Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure the parameters of tow alarm.");
}


void CConfigToolDlg::OnBnClickedMfcbuttonAssa()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_ASsa_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_ASsa_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_ASsa_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Speed Alarm Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Speed Alarm Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure how to initiate a Speed Alarm Settings based on specified speed range.");
}


void CConfigToolDlg::OnBnClickedMfcbuttonAssosa()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_ASsosa_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_ASsosa_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_ASsosa_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"SOS Alarm Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"SOS Alarm Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure emergency actions triggered bty specified input port.");
}


void CConfigToolDlg::OnBnClickedMfcbuttonAseid()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_ASeid_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_ASeid_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_ASeid_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Engine Idling Detection ");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Engine Idling Detection ");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to detect excessive idling of the engine.");
}


void CConfigToolDlg::OnBnClickedMfcbuttonAshbm()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_AShbm_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_AShbm_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_AShbm_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Driving Behavior Monitoring");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Driving Behavior Monitoring");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to monitor the harsh behavior of driving with GPS and motion sensor.");
}


void CConfigToolDlg::OnBnClickedMfcbuttonAsssr()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_ASssr_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_ASssr_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_ASssr_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Vehicle Status");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Vehicle Status");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to detect the status of vehicle(start or stop status).");
}


void CConfigToolDlg::OnBnClickedMfcbuttonAsbad()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_ASbad_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_ASbad_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_ASbad_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Buzzer Alarm Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Buzzer Alarm Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to set buzzer alarm.");
}


void CConfigToolDlg::OnBnClickedMfcbuttonAsosa()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_ASosa_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_ASosa_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_ASosa_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Overspeed Alarm Settings Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Overspeed Alarm Settings Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to set the speed thresholds and binding one alarm type for buzzer alarm.");
}


void CConfigToolDlg::OnBnClickedMfcbuttonAspg()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_ASpg_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_ASpg_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_ASpg_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Polygon Geo-Fence Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Polygon Geo-Fence Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure the parameters of Polygon Geo-Fence Settings.");
}


void CConfigToolDlg::OnBnClickedMfcbuttonAsrdc()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_ASrdc_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_ASrdc_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_ASrdc_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Roaming Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Roaming Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure the GSM roaming detection parameters.");
}


void CConfigToolDlg::OnBnClickedMfcbuttonAssadr()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_ASsadr_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_ASsadr_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_ASsadr_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Start and Drive Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Start and Drive Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure the parameters for start nd drive report.");
}

void CConfigToolDlg::OnBnClickedMfcbuttonAsser()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_ASser_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_ASser_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_ASser_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Stop Event Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Stop Event Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure the parameters for the Stop Event Settings.");
}

void CConfigToolDlg::OnBnClickedMfcbuttonAscd()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_AScd_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_AScd_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_AScd_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Crash Detection Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Crash Detection Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure the parameter for crash deetection.");
}

void CConfigToolDlg::OnBnClickedMfcbuttonIadops()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_IAdops_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_IAdops_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_IAdops_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Digital Output Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Digital Output Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to produce specified waveform from the digital output port.");
}

void CConfigToolDlg::OnBnClickedMfcbuttonIaepsm()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_IAepsm_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_IAepsm_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_IAepsm_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"External Power Supply Monitoring Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"External Power Supply Monitoring Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure the parameters of external power supply moniroting.");
}

void CConfigToolDlg::OnBnClickedMfcbuttonIadips()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_IAdips_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_IAdips_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_IAdips_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Digital Input Port Setting");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Digital Input Port Setting");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure the parameters of 4 input ports.");
}

void CConfigToolDlg::OnBnClickedMfcbuttonIaips()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_IAips_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_IAips_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_IAips_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Input/Output Port Binding");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Input/Output Port Binding");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure the specific output port action triggered by input port.");
}

void CConfigToolDlg::OnBnClickedMfcbuttonIdsvims()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_IDSvims_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_IDSvims_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_IDSvims_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Virtual Ingintion Mode Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Virtual Ingintion Mode Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure the virtual ignition mode.");
}

void CConfigToolDlg::OnBnClickedMfcbuttonIdsidbvs()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_IDSidbvs_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_IDSidbvs_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_IDSidbvs_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Voltage Virtual Ignition Setting");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Voltage Virtual Ignition Setting");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure parameters for checking ignition state by voltage.");
}

void CConfigToolDlg::OnBnClickedMfcbuttonIdsavis()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_IDSavis_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_IDSavis_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_IDSavis_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Accelerometer Virtual Ignition Setting");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Accelerometer Virtual Ignition Setting");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure parameters for checking ignition state by accelerometer.");
}

void CConfigToolDlg::OnBnClickedMfcbuttonOsrto()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_OSrto_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_OSrto_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_OSrto_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Real Time Operation Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Real Time Operation Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to retrieve information from the terminal or control the terminal to execute certain actions.");
}

void CConfigToolDlg::OnBnClickedMfcbuttonOshmc()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_OShmc_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_OShmc_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_OShmc_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Hour Meter Counter Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Hour Meter Counter Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to count time spent when ignition on.");
}

void CConfigToolDlg::OnBnClickedMfcbuttonOswl()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_OSwl_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_OSwl_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_OSwl_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"White Number List Configuration");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"White Number List Configuration");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to set white number list table.");
}

void CConfigToolDlg::OnBnClickedMfcbuttonOsglsc()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_OSglsc_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_OSglsc_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_OSglsc_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Google Link SMS Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Google Link SMS Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure whether to send SMS with google link for SOS and GEO event");
}

void CConfigToolDlg::OnBnClickedMfcbuttonOsucota()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_OSucota_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_OSucota_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_OSucota_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"OTA Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"OTA Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to send control command. ");
}

void CConfigToolDlg::OnBnClickedMfcbuttonOscss()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_OScss_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_OScss_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_OScss_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Command String Storage");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Command String Storage");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to store the commands which will be used by the command AT+GTUDP");
}

void CConfigToolDlg::OnBnClickedMfcbuttonOsudf()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_OSudf_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_OSudf_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_OSudf_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"User Defined Function Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"User Defined Function Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to bind input event and stored commands. ");
}

void CConfigToolDlg::OnBnClickedMfcbuttonOsgs()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_OSgs_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_OSgs_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_OSgs_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"G-Sensor Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"G-Sensor Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to define the condition for calibration the directions of accelerometer. ");
}

void CConfigToolDlg::OnBnClickedMfcbuttonOser()
{
	CRect rectabnow;
	m_Table.GetClientRect(&rectabnow);	//rs是你对话框要放置的位置
	int tab_nWidth = rectabnow.right-rectabnow.left;
	int tab_nHeight = rectabnow.bottom-rectabnow.top;
	m_OSer_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
	m_OSer_Dlg.MoveWindow(&rectabnow);
	HideAllWND();	//隐藏其他所有窗口
	m_OSer_Dlg.ShowWindow(TRUE);	//显示需要的窗口
	m_Table.SetCurSel(0);	//设置默认窗口
	g_CSelTab = 0;
	SetDlgItemText(IDC_STATIC_Item,"Emergency Settings");
	AUTOSIZEITEM();
	SetDlgItemText(IDC_STATIC_Item,"Emergency Settings");
	SetDlgItemText(IDC_STATIC_ItemDes,"is used to configure the parameters for emergency relese.");
}

void CConfigToolDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	// TODO: 在此处添加消息处理程序代码
	if(nType!=SIZE_MINIMIZED &&InitSize)  
	{
		if (m_listRect.GetCount() > 0)  
		{  
			CRect dlgNow;  
			GetWindowRect(&dlgNow);  
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
				childSaved.top = (long)((long)(dlgNow.top + (childSaved.top - dlgSaved.top)*y));  
				childSaved.bottom =(long)((long)(dlgNow.bottom + (childSaved.bottom - dlgSaved.bottom)*y));  
				if(pWnd->IsKindOf(RUNTIME_CLASS(CComboBox))) childSaved.bottom = childSaved.bottom+100;//判断是否为ComboBox类型
				ScreenToClient(childSaved);  
				pWnd->MoveWindow(childSaved);  
				pWnd = pWnd->GetNextWindow();  
			}  
		}

		AUTOSIZEITEM();//解决静态框残影的问题
		CRect rectabnow; //当前Tab的尺寸传给子对话框
		m_Table.GetClientRect(&rectabnow);	
		int tab_nWidth = rectabnow.right-rectabnow.left;
		int tab_nHeight = rectabnow.bottom-rectabnow.top;
		if (m_SCbsi_Dlg.IsWindowVisible())
		{
			m_SCbsi_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
			m_SCbsi_Dlg	.MoveWindow(&rectabnow);
		}

		if (	m_SCbsri_Dlg.IsWindowVisible())	m_SCbsri_Dlg.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_SCqss_Dlg	.IsWindowVisible())	m_SCqss_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_DCgc_Dlg	.IsWindowVisible())	m_DCgc_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_DCap_Dlg	.IsWindowVisible())	m_DCap_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_DCspw_Dlg	.IsWindowVisible())	m_DCspw_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_DCowh_Dlg	.IsWindowVisible())	m_DCowh_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_DCta_Dlg	.IsWindowVisible())	m_DCta_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_DCpsdls_Dlg	.IsWindowVisible())	m_DCpsdls_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_DChrm_Dlg	.IsWindowVisible())	m_DChrm_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_DCpcs_Dlg	.IsWindowVisible())	m_DCpcs_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_PRRfri_Dlg	.IsWindowVisible())	m_PRRfri_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_PRRfcofri_Dlg	.IsWindowVisible())	m_PRRfcofri_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_ASgc_Dlg	.IsWindowVisible())	m_ASgc_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_AStac_Dlg	.IsWindowVisible())	m_AStac_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_ASsa_Dlg	.IsWindowVisible())	m_ASsa_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_ASsosa_Dlg	.IsWindowVisible())	m_ASsosa_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_ASeid_Dlg	.IsWindowVisible())	m_ASeid_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_AShbm_Dlg	.IsWindowVisible())	m_AShbm_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_ASssr_Dlg	.IsWindowVisible())	m_ASssr_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_ASbad_Dlg	.IsWindowVisible())	m_ASbad_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_ASosa_Dlg	.IsWindowVisible())	m_ASosa_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_ASpg_Dlg	.IsWindowVisible())	m_ASpg_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_ASrdc_Dlg	.IsWindowVisible())	m_ASrdc_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_ASsadr_Dlg	.IsWindowVisible())	m_ASsadr_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_ASser_Dlg	.IsWindowVisible())	m_ASser_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_AScd_Dlg	.IsWindowVisible())	m_AScd_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_IAdops_Dlg	.IsWindowVisible())	m_IAdops_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_IAepsm_Dlg	.IsWindowVisible())	m_IAepsm_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_IAdips_Dlg	.IsWindowVisible())	m_IAdips_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_IAips_Dlg	.IsWindowVisible())	m_IAips_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_IDSvims_Dlg	.IsWindowVisible())	m_IDSvims_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_IDSidbvs_Dlg	.IsWindowVisible())	m_IDSidbvs_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_IDSavis_Dlg	.IsWindowVisible())	m_IDSavis_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_OSrto_Dlg	.IsWindowVisible())	m_OSrto_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_OShmc_Dlg	.IsWindowVisible())	m_OShmc_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_OSwl_Dlg	.IsWindowVisible())	m_OSwl_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_OSglsc_Dlg	.IsWindowVisible())	m_OSglsc_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_OSucota_Dlg	.IsWindowVisible())	m_OSucota_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_OScss_Dlg	.IsWindowVisible())	m_OScss_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_OSudf_Dlg	.IsWindowVisible())	m_OSudf_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_OSgs_Dlg	.IsWindowVisible())	m_OSgs_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);
		if (	m_OSer_Dlg	.IsWindowVisible())	m_OSer_Dlg	.ReSize(0,tab_nWidth,tab_nHeight);


		if (	m_SCbsri_Dlg	.IsWindowVisible())	m_SCbsri_Dlg	.MoveWindow(&rectabnow);
		if (	m_SCqss_Dlg	.IsWindowVisible())	m_SCqss_Dlg	.MoveWindow(&rectabnow);
		if (	m_DCgc_Dlg	.IsWindowVisible())	m_DCgc_Dlg	.MoveWindow(&rectabnow);
		if (	m_DCap_Dlg	.IsWindowVisible())	m_DCap_Dlg	.MoveWindow(&rectabnow);
		if (	m_DCspw_Dlg	.IsWindowVisible())	m_DCspw_Dlg	.MoveWindow(&rectabnow);
		if (	m_DCowh_Dlg	.IsWindowVisible())	m_DCowh_Dlg	.MoveWindow(&rectabnow);
		if (	m_DCta_Dlg	.IsWindowVisible())	m_DCta_Dlg	.MoveWindow(&rectabnow);
		if (	m_DCpsdls_Dlg	.IsWindowVisible())	m_DCpsdls_Dlg	.MoveWindow(&rectabnow);
		if (	m_DChrm_Dlg	.IsWindowVisible())	m_DChrm_Dlg	.MoveWindow(&rectabnow);
		if (	m_DCpcs_Dlg	.IsWindowVisible())	m_DCpcs_Dlg	.MoveWindow(&rectabnow);
		if (	m_PRRfri_Dlg	.IsWindowVisible())	m_PRRfri_Dlg	.MoveWindow(&rectabnow);
		if (	m_PRRfcofri_Dlg	.IsWindowVisible())	m_PRRfcofri_Dlg	.MoveWindow(&rectabnow);
		if (	m_ASgc_Dlg	.IsWindowVisible())	m_ASgc_Dlg	.MoveWindow(&rectabnow);
		if (	m_AStac_Dlg	.IsWindowVisible())	m_AStac_Dlg	.MoveWindow(&rectabnow);
		if (	m_ASsa_Dlg	.IsWindowVisible())	m_ASsa_Dlg	.MoveWindow(&rectabnow);
		if (	m_ASsosa_Dlg	.IsWindowVisible())	m_ASsosa_Dlg	.MoveWindow(&rectabnow);
		if (	m_ASeid_Dlg	.IsWindowVisible())	m_ASeid_Dlg	.MoveWindow(&rectabnow);
		if (	m_AShbm_Dlg	.IsWindowVisible())	m_AShbm_Dlg	.MoveWindow(&rectabnow);
		if (	m_ASssr_Dlg	.IsWindowVisible())	m_ASssr_Dlg	.MoveWindow(&rectabnow);
		if (	m_ASbad_Dlg	.IsWindowVisible())	m_ASbad_Dlg	.MoveWindow(&rectabnow);
		if (	m_ASosa_Dlg	.IsWindowVisible())	m_ASosa_Dlg	.MoveWindow(&rectabnow);
		if (	m_ASpg_Dlg	.IsWindowVisible())	m_ASpg_Dlg	.MoveWindow(&rectabnow);
		if (	m_ASrdc_Dlg	.IsWindowVisible())	m_ASrdc_Dlg	.MoveWindow(&rectabnow);
		if (	m_ASsadr_Dlg	.IsWindowVisible())	m_ASsadr_Dlg	.MoveWindow(&rectabnow);
		if (	m_ASser_Dlg	.IsWindowVisible())	m_ASser_Dlg	.MoveWindow(&rectabnow);
		if (	m_AScd_Dlg	.IsWindowVisible())	m_AScd_Dlg	.MoveWindow(&rectabnow);
		if (	m_IAdops_Dlg	.IsWindowVisible())	m_IAdops_Dlg	.MoveWindow(&rectabnow);
		if (	m_IAepsm_Dlg	.IsWindowVisible())	m_IAepsm_Dlg	.MoveWindow(&rectabnow);
		if (	m_IAdips_Dlg	.IsWindowVisible())	m_IAdips_Dlg	.MoveWindow(&rectabnow);
		if (	m_IAips_Dlg	.IsWindowVisible())	m_IAips_Dlg	.MoveWindow(&rectabnow);
		if (	m_IDSvims_Dlg	.IsWindowVisible())	m_IDSvims_Dlg	.MoveWindow(&rectabnow);
		if (	m_IDSidbvs_Dlg	.IsWindowVisible())	m_IDSidbvs_Dlg	.MoveWindow(&rectabnow);
		if (	m_IDSavis_Dlg	.IsWindowVisible())	m_IDSavis_Dlg	.MoveWindow(&rectabnow);
		if (	m_OSrto_Dlg	.IsWindowVisible())	m_OSrto_Dlg	.MoveWindow(&rectabnow);
		if (	m_OShmc_Dlg	.IsWindowVisible())	m_OShmc_Dlg	.MoveWindow(&rectabnow);
		if (	m_OSwl_Dlg	.IsWindowVisible())	m_OSwl_Dlg	.MoveWindow(&rectabnow);
		if (	m_OSglsc_Dlg	.IsWindowVisible())	m_OSglsc_Dlg	.MoveWindow(&rectabnow);
		if (	m_OSucota_Dlg	.IsWindowVisible())	m_OSucota_Dlg	.MoveWindow(&rectabnow);
		if (	m_OScss_Dlg	.IsWindowVisible())	m_OScss_Dlg	.MoveWindow(&rectabnow);
		if (	m_OSudf_Dlg	.IsWindowVisible())	m_OSudf_Dlg	.MoveWindow(&rectabnow);
		if (	m_OSgs_Dlg	.IsWindowVisible())	m_OSgs_Dlg	.MoveWindow(&rectabnow);
		if (	m_OSer_Dlg	.IsWindowVisible())	m_OSer_Dlg	.MoveWindow(&rectabnow);
	}
	
}

void CConfigToolDlg::OnBnClickedMfcbuttonOl()
{
	CRect rectDlg,rectTab;
	CString sTemp="";
	CRect rectLog;
	if (GetDlgItemText(IDC_MFCBUTTON_OL,sTemp),sTemp=="OPEN LOG")
	{
		SetDlgItemText(IDC_MFCBUTTON_OL,"CLOSE LOG");
		GetDlgItem(IDC_EDIT_Log)->ShowWindow(SW_SHOW);
		//log的位置
		GetDlgItem(IDC_EDIT_Log)->GetWindowRect(&rectLog);
		ScreenToClient(&rectLog);
		//目前的对话框实际大小
		GetWindowRect(&rectDlg);
		ScreenToClient(&rectDlg);
		//Tab的位置
		GetDlgItem(IDC_TAB_LOG)->GetWindowRect(&rectTab);
		ScreenToClient(&rectTab);
		//LOG位置在对话框底部，左右TAB对其
		rectLog.bottom=rectDlg.bottom-10;
		rectLog.left=rectTab.left;
		rectLog.right=rectTab.right;
		//减少Tab的长度
		rectTab.bottom=rectLog.top-3;
		//移动
		GetDlgItem(IDC_EDIT_Log)->MoveWindow(rectLog); 
		GetDlgItem(IDC_TAB_LOG)->MoveWindow(&rectTab);
		//
		KeepIniSize();
		OnSize(SIZE_RESTORED, m_rect.Width(), m_rect.Height());
	}
	else
	{
		SetDlgItemText(IDC_MFCBUTTON_OL,"OPEN LOG");
		GetDlgItem(IDC_EDIT_Log)->ShowWindow(SW_HIDE);
		//目前的对话框实际大小
		GetWindowRect(&rectDlg);
		ScreenToClient(&rectDlg);
		//Tab的位置
		GetDlgItem(IDC_TAB_LOG)->GetWindowRect(&rectTab);
		ScreenToClient(&rectTab);
		//增加Tab的长度
		rectTab.bottom=rectDlg.bottom-10;
		//移动
		GetDlgItem(IDC_TAB_LOG)->MoveWindow(&rectTab);
		KeepIniSize();
		OnSize(SIZE_RESTORED, m_rect.Width(), m_rect.Height());
	}
}

void CConfigToolDlg::OnBnClickedMfcmenubuttonRac()
{
	if(m_Menubutton_RAC.m_nMenuResult == ID_X_D)
	{
		stu_CONFIG.iTestSelection=ReadFromDevice;
		m_MYWORK.Button_ThreadStart();
	}
	else if(m_Menubutton_RAC.m_nMenuResult == ID_X_F)
	{
		stu_CONFIG.iTestSelection=ReadFromFile;
		m_MYWORK.Button_ThreadStart();
	}
}

void CConfigToolDlg::OnBnClickedMfcbuttonSac()
{
	stu_CONFIG.iTestSelection=SendFromDevice;
	m_MYWORK.Button_ThreadStart();
}

void CConfigToolDlg::OnBnClickedMfcbuttonSaveac()
{
	stu_CONFIG.iTestSelection=SaveFromPage;
	m_MYWORK.Button_ThreadStart();
}
