#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// ASpg_Dlg 对话框

class ASpg_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(ASpg_Dlg)

public:
	ASpg_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ASpg_Dlg();

// 对话框数据
	enum { IDD = IDD_ASpg_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnCbnSelchangeComboGi();
	afx_msg void OnCbnSelchangeComboMode();
	CComboBox m_ComboBox_GI;
	CComboBox m_ComboBox_M;
	afx_msg void OnDeltaposSpinCi(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditCi();
	CSpinButtonCtrl m_Spin_CI;
	CEdit m_Edit_CI;
	afx_msg void OnDeltaposSpinSp(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinEp(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_SP;
	CSpinButtonCtrl m_Spin_EP;
	void GetListValue();
	CEdit m_Edit_SP;
	CEdit m_Edit_EP;
	CEdit m_Edit_A1;
	CEdit m_Edit_A2;
	CEdit m_Edit_A3;
	CEdit m_Edit_A4;
	CEdit m_Edit_A5;
	CEdit m_Edit_A6;
	CEdit m_Edit_A7;
	CEdit m_Edit_A8;
	CEdit m_Edit_A9;
	CEdit m_Edit_A10;
	CEdit m_Edit_B1;
	CEdit m_Edit_B2;
	CEdit m_Edit_B3;
	CEdit m_Edit_B4;
	CEdit m_Edit_B5;
	CEdit m_Edit_B6;
	CEdit m_Edit_B7;
	CEdit m_Edit_B8;
	CEdit m_Edit_B9;
	CEdit m_Edit_B10;
	afx_msg void OnEnChangeEditSp();
	afx_msg void OnEnChangeEditEp();
	afx_msg void OnCbnSelchangeComboOi();
	afx_msg void OnBnClickedCheckOuts();
	afx_msg void OnDeltaposSpinDu(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinTog(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditDu();
	afx_msg void OnEnChangeEditTog();
	CSpinButtonCtrl m_Spin_D;
	CSpinButtonCtrl m_Spin_TT;
	CEdit m_Edit_D;
	CEdit m_Edit_TT;
	CComboBox m_ComboBox_OI;
	CButton m_Check_OutS;
	afx_msg void OnDeltaposSpinA1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditA1();
	CSpinButtonCtrl m_Spin_A1;
	double  m_dA1;
	double  m_dA2;
	double  m_dA3;
	double  m_dA4;
	double  m_dA5;
	double  m_dA6;
	double  m_dA7;
	double  m_dA8;
	double  m_dA9;
	double  m_dA10;
	double  m_dB1;
	double  m_dB2;
	double  m_dB3;
	double  m_dB4;
	double  m_dB5;
	double  m_dB6;
	double  m_dB7;
	double  m_dB8;
	double  m_dB9;
	double  m_dB10;

	afx_msg void OnDeltaposSpinB1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinA2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinB2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinA3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinB3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditA4();
	afx_msg void OnDeltaposSpinA4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinB4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditA5();
	afx_msg void OnDeltaposSpinA5(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinB5(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinA6(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinB6(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinA7(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinB7(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditA8();
	afx_msg void OnDeltaposSpinA8(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinB8(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinA9(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinB9(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinA10(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinB10(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditB1();
	afx_msg void OnEnChangeEditA2();
	afx_msg void OnEnChangeEditB2();
	afx_msg void OnEnChangeEditA3();
	afx_msg void OnEnChangeEditB3();
	afx_msg void OnEnChangeEditB4();
	afx_msg void OnEnChangeEditB5();
	afx_msg void OnEnChangeEditA6();
	afx_msg void OnEnChangeEditB6();
	afx_msg void OnEnChangeEditA7();
	afx_msg void OnEnChangeEditB7();
	afx_msg void OnEnChangeEditB8();
	afx_msg void OnEnChangeEditA9();
	afx_msg void OnEnChangeEditB9();
	afx_msg void OnEnChangeEditA10();
	afx_msg void OnEnChangeEditB10();
};
