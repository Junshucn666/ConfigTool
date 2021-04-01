// EquipmentSet.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "EquipmentSet.h"
#include "afxdialogex.h"
#include "ConfigToolDlg.h"

extern CConfigToolDlg* lpCConfigToolDlg;
extern CONFIG stu_CONFIG;

// EquipmentSet 对话框

IMPLEMENT_DYNAMIC(EquipmentSet, CDialogEx)

EquipmentSet::EquipmentSet(CWnd* pParent /*=NULL*/)
	: CDialogEx(EquipmentSet::IDD, pParent)
{

}

EquipmentSet::~EquipmentSet()
{
}

void EquipmentSet::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_Type, m_PowerType);
	DDX_Control(pDX, IDC_COMBO_PowerBoard, m_PowerBoard);
	DDX_Control(pDX, IDC_COMBO_Addr, m_PowerAddress);
}


BEGIN_MESSAGE_MAP(EquipmentSet, CDialogEx)
	ON_BN_CLICKED(IDOK, &EquipmentSet::OnBnClickedOk)
END_MESSAGE_MAP()


// EquipmentSet 消息处理程序


BOOL EquipmentSet::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	/*电源设置*/
	m_PowerType.InsertString(0,"Agilent");
	m_PowerType.InsertString(1,"KEITHLEY");
	m_PowerType.SetCurSel(0);

	m_PowerBoard.InsertString(0,"0");
	m_PowerBoard.InsertString(1,"1");
	m_PowerBoard.SetCurSel(0);

	for (int i=0;i<21;i++)
	{
		CString sAddress;
		sAddress.Format("%d",i);
		m_PowerAddress.InsertString(i,sAddress);
	}
	m_PowerAddress.SetCurSel(5);
	GetConfigFromFile();
	PutConfigToPage();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

bool EquipmentSet::GetConfigFromFile()
{
	CString sReadFileTemp;
	CString sConfigFilePath=lpCConfigToolDlg->GetExeFilePath()+"config.ini";
	/*电源设置*/
	GetPrivateProfileString("CONFIG","PowerType","0",sReadFileTemp.GetBuffer(MAX_PATH),MAX_PATH,sConfigFilePath);
	sReadFileTemp.ReleaseBuffer();
	stu_CONFIG.iPowerType=atoi(sReadFileTemp);
	GetPrivateProfileString("CONFIG","PowerAddress","",sReadFileTemp.GetBuffer(MAX_PATH),MAX_PATH,sConfigFilePath);
	sReadFileTemp.ReleaseBuffer();
	stu_CONFIG.iPowerAddress=atoi(sReadFileTemp);
	GetPrivateProfileString("CONFIG","PowerBoard","",sReadFileTemp.GetBuffer(MAX_PATH),MAX_PATH,sConfigFilePath);
	sReadFileTemp.ReleaseBuffer();
	stu_CONFIG.iPowerBoard=atoi(sReadFileTemp);
	return true;
}
//变量到控件，SetCurSel，SetCheck，SetWindowText
bool EquipmentSet::PutConfigToPage()
{
	CString strTemp;
	/*电源设置*/
	m_PowerType.SetCurSel(stu_CONFIG.iPowerType);
	m_PowerBoard.SetCurSel(stu_CONFIG.iPowerBoard);
	m_PowerAddress.SetCurSel(stu_CONFIG.iPowerAddress);
	
	return true;
}
//控件到变量GetDlgItemText,GetCurSel,GetCheck,GetWindowText
bool EquipmentSet::PutPageToConfig()
{
	CString strTemp;
	/*电源设置*/
	stu_CONFIG.iPowerType=m_PowerType.GetCurSel();
	stu_CONFIG.iPowerBoard=m_PowerBoard.GetCurSel();
	stu_CONFIG.iPowerAddress=m_PowerAddress.GetCurSel();

	return true;
}
//变量到文件WritePrivateProfileString
bool EquipmentSet::SaveConfigToFile()
{
	CString sWriteFileTemp;
	CString sConfigFilePath=lpCConfigToolDlg->GetExeFilePath()+"config.ini";	
	/*电源设置*/
	sWriteFileTemp.Format("%d",stu_CONFIG.iPowerType);
	WritePrivateProfileString("CONFIG","PowerType",sWriteFileTemp,sConfigFilePath);
	sWriteFileTemp.Format("%d",stu_CONFIG.iPowerAddress);
	WritePrivateProfileString("CONFIG","PowerAddress",sWriteFileTemp,sConfigFilePath);
	sWriteFileTemp.Format("%d",stu_CONFIG.iPowerBoard);
	WritePrivateProfileString("CONFIG","PowerBoard",sWriteFileTemp,sConfigFilePath);

	return true;
}


void EquipmentSet::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	PutPageToConfig();
	SaveConfigToFile();
	CDialogEx::OnOK();
}
