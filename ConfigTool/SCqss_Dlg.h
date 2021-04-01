#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// SCqss_Dlg 对话框

class SCqss_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(SCqss_Dlg)

public:
	SCqss_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SCqss_Dlg();

// 对话框数据
	enum { IDD = IDD_SCqss_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	CComboBox m_ComboBox_qssRM;
	CComboBox m_ComboBox_qssBM;
	CComboBox m_ComboBox_qssSE;
	CComboBox m_ComboBox_qssPF;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnCbnSelchangeComboqssrm();
	afx_msg void OnEnChangeEditApn();
	CEdit m_Edit_APN;
	CEdit m_Edit_UN;
	afx_msg void OnEnChangeEditUsername();
	CEdit m_Edit_PW;
	afx_msg void OnEnChangeEditPassword();
	CEdit m_Edit_qssMSI;
	afx_msg void OnEnChangeEditqssmsi();
	afx_msg void OnDeltaposSpinMsp(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_MSP;
	CEdit m_Edit_MSP;
	afx_msg void OnEnChangeEditqssmsp();
	CEdit m_Edit_BSI;
	afx_msg void OnEnChangeEditqssbsi();
	afx_msg void OnDeltaposSpinBsp(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_BSP;
	CEdit m_Edit_BSP;
	afx_msg void OnEnChangeEditqssbsp();
	CEdit m_Edit_SG;
	afx_msg void OnEnChangeEditqsssg();
	afx_msg void OnDeltaposSpinHi(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_HI;
	afx_msg void OnEnChangeEditHi();
	CEdit m_Edit_HI;
	afx_msg void OnCbnSelchangeComboBm();
	afx_msg void OnCbnSelchangeComboSe();
	afx_msg void OnCbnSelchangeComboPf();
	afx_msg void OnBnClickedCheckSse();
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	CButton m_Check_SSE;
};
