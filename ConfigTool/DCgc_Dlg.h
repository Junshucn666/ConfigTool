#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// DCgc_Dlg 对话框

class DCgc_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(DCgc_Dlg)

public:
	DCgc_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DCgc_Dlg();

// 对话框数据
	enum { IDD = IDD_DCgc_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	CComboBox m_ComboBox_PSM;
	CComboBox m_ComboBox_IM;
	CComboBox m_ComboBox_BBCM;
	CComboBox m_ComboBox_SR;
	afx_msg void OnDeltaposSpinMsp(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCheckCmca();
	CButton m_Check_CMs;
	afx_msg void OnBnClickedCheckCms();
	CButton m_Check_CMca;
	CButton m_CHECK_CMa;
	CButton m_CHECK_CMal;
	CButton m_CHECK_CMcind;
	CButton m_CHECK_CMm;
	CButton m_CHECK_CMst;
	CButton m_CHECK_CMdn;
	CButton m_Check_EMna;
	CButton m_Check_EMfa;
	CButton m_Check_EMpn;
	CButton m_Check_EMpf;
	CButton m_Check_EMr1;
	CButton m_Check_EMpl;
	CButton m_Check_EMtc;
	CButton m_Check_EMtc2;
	CButton m_Check_EMtt;
	CButton m_Check_EMr2;
	CButton m_Check_EMdp;
	CButton m_Check_EMnl;
	CButton m_Check_EMgf;
	CButton m_Check_EMgl;
	CButton m_Check_EMca;
	afx_msg void OnBnClickedCheckEmca();
	CEdit m_Edit_DN;
	afx_msg void OnEnChangeEditDn();
	CEdit m_Edit_NP;
	afx_msg void OnEnChangeEditNp();
	CEdit m_Edit_OIM;
	CSpinButtonCtrl m_Spin_OIM;
	afx_msg void OnEnChangeEditOim();
	CButton m_Check_OE;
	afx_msg void OnBnClickedCheckOe();
	afx_msg void OnCbnSelchangeComboPsm();
	afx_msg void OnCbnSelchangeComboIm();
	afx_msg void OnCbnSelchangeComboBbcm();
	afx_msg void OnCbnSelchangeComboSr();
	CButton m_Check_LO;
	afx_msg void OnBnClickedCheckLo();
	afx_msg void OnBnClickedCheckSd();
	void GetCMValue();
	void SetCMValue(CString sStrH);
	void GetEMValue();
	void SetEMValue(CString sStrH);
	afx_msg void OnBnClickedCheckCma();
	afx_msg void OnBnClickedCheckCmal();
	afx_msg void OnBnClickedCheckCmcind();
	afx_msg void OnBnClickedCheckCmm();
	afx_msg void OnBnClickedCheckCmst();
	afx_msg void OnBnClickedCheckCmdn();
	afx_msg void OnBnClickedCheckEmna();
	afx_msg void OnBnClickedCheckEmfa();
	afx_msg void OnBnClickedCheckEmpn();
	afx_msg void OnBnClickedCheckEmpf();
	afx_msg void OnBnClickedCheckEmr1();
	afx_msg void OnBnClickedCheckEmpl();
	afx_msg void OnBnClickedCheckEmtc();
	afx_msg void OnBnClickedCheckEmtc2();
	afx_msg void OnBnClickedCheckEmtt();
	afx_msg void OnBnClickedCheckEmr2();
	afx_msg void OnBnClickedCheckEmdp();
	afx_msg void OnBnClickedCheckEmnl();
	afx_msg void OnBnClickedCheckEmgf();
	afx_msg void OnBnClickedCheckEmgl();
	afx_msg void OnBnClickedCheckIre();
	CButton m_Check_IRE;
	CSpinButtonCtrl m_Spin_IRI;
	afx_msg void OnDeltaposSpinMspIri(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_Edit_IRI;
	afx_msg void OnEnChangeEditIri();
	afx_msg void OnDeltaposSpinGlt(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_GLT;
	CEdit m_Edit_GLT;
	afx_msg void OnEnChangeEditGlt();
	afx_msg void OnEnChangeEditGtcfg();
	afx_msg void OnDeltaposSpinOim(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeComboA();
	CComboBox m_ComboBox_A;
};
