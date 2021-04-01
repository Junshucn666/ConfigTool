#pragma once
#include "afxwin.h"
#include "MyTabBaseDlg.h"

// DCpsdls_Dlg 对话框

class DCpsdls_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(DCpsdls_Dlg)

public:
	DCpsdls_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DCpsdls_Dlg();

// 对话框数据
	enum { IDD = IDD_DCpsdls_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	CComboBox m_ComboBox_M;
	afx_msg void OnCbnSelchangeComboM();
	afx_msg void OnBnClickedCheckSog();
	void GetMSValue();
	void SetMSValue(CString sStrH);
	CButton m_Check_SoG;
	CButton m_Check_Rb1;
	CButton m_Check_Rb2;
	CButton m_Check_Iolkp;
	CButton m_Check_Soi;
	CButton m_Check_Sows;
	CButton m_Check_Sodi;
	CButton m_Check_SoS;
	CButton m_Check_SSR;
	CButton m_Check_Somp;
	CButton m_Check_PEO;
	afx_msg void OnBnClickedCheckRb1();
	afx_msg void OnBnClickedCheckRb2();
	afx_msg void OnBnClickedCheckIolkp();
	afx_msg void OnBnClickedCheckSoi();
	afx_msg void OnBnClickedCheckSows();
	afx_msg void OnBnClickedCheckSodi();
	afx_msg void OnBnClickedCheckSos();
	afx_msg void OnBnClickedCheckSsr();
	afx_msg void OnBnClickedCheckSomp();
	afx_msg void OnBnClickedCheckPeo();
	afx_msg void OnBnClickedCheckca();
	CButton m_Check_Ca;
};
