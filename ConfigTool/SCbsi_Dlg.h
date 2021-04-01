#pragma once
#include "afxwin.h"
#include "MyTabBaseDlg.h"

// SCbsi_Dlg 对话框

class SCbsi_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(SCbsi_Dlg)

public:
	SCbsi_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SCbsi_Dlg();

// 对话框数据
	enum { IDD = IDD_SCbsi_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeEditApn();
	CEdit m_Edit_APN;
	afx_msg void OnEnChangeEditUsername();
	CString UpdataCMD(CString sChildstr,int iPos,CString sCmdstr);
	void GetValueNA();
	BOOL UpdataPage(CString sStr);
	void SetNAValue(CString sStrH);
	void GetCMD();
	CEdit m_Edit_UserName;
	CEdit m_Edit_Password;
	CEdit m_Edit_BAPN;
	CEdit m_Edit_BUserName;
	CEdit m_Edit_BPassword;
	afx_msg void OnEnChangeEditPassword();
	afx_msg void OnEnChangeEditbapn();
	afx_msg void OnEnChangeEditBusername();
	afx_msg void OnEnChangeEditBpassword();
	afx_msg void OnCbnSelchangeComboN();
	afx_msg void OnCbnSelchangeComboMa();
	CComboBox m_ComboBox_Ma;
	afx_msg void OnCbnSelchangeComboL();
	CComboBox m_ComboBox_L;
	CComboBox m_ComboBox_N;
	CComboBox m_ComboBox_A;
	afx_msg void OnCbnSelchangeComboA();
};
