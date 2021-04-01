#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// PRRfcofri_Dlg 对话框

class PRRfcofri_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(PRRfcofri_Dlg)

public:
	PRRfcofri_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PRRfcofri_Dlg();

// 对话框数据
	enum { IDD = IDD_PRRfcofri_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnCbnSelchangeComboP();
	CComboBox m_ComboBox_P;
	afx_msg void OnCbnSelchangeComboM();
	CComboBox m_ComboBox_M;
	afx_msg void OnCbnSelchangeComboFm();
	CComboBox m_ComboBox_FM;
	afx_msg void OnDeltaposSpinFir(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_FIR;
	CEdit m_Edit_FIR;
	afx_msg void OnEnChangeEditFir();
	afx_msg void OnDeltaposSpinFrd(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_FRD;
	CEdit m_Edit_FRD;
	afx_msg void OnEnChangeEditFrd();
	afx_msg void OnDeltaposSpinFrm(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_FRM;
	CEdit m_Edit_FRM;
	afx_msg void OnEnChangeEditFrm();
	afx_msg void OnDeltaposSpinFir2(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_FIR2;
	CEdit m_Edit_FIR2;
	afx_msg void OnEnChangeEditFir2();
	afx_msg void OnDeltaposSpinCr(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_CR;
	CEdit m_Edit_CR;
	afx_msg void OnEnChangeEditCr();

};
