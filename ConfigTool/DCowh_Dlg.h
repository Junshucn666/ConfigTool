#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// DCowh_Dlg 对话框

class DCowh_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(DCowh_Dlg)

public:
	DCowh_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DCowh_Dlg();

// 对话框数据
	enum { IDD = IDD_DCowh_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	CComboBox m_ComboBox_M;
	CComboBox m_ComboBox_D;
	CComboBox m_ComboBox_O;
	afx_msg void OnBnClickedCheck22();
	afx_msg void OnCbnSelchangeComboM();
	CButton m_Check_Mon;
	CButton m_Check_Tue;
	CButton m_Check_Wed;
	CButton m_Check_Thu;
	CButton m_Check_Fri;
	CButton m_Check_Sat;
	CButton m_Check_Sun;
	CButton m_Check_ca;
	afx_msg void OnBnClickedCheckMon();
	void GetDoWValue();
	void SetDoWValue(CString sStrH);
	afx_msg void OnBnClickedCheckTue();
	afx_msg void OnBnClickedCheckWed();
	afx_msg void OnBnClickedCheckThu();
	afx_msg void OnBnClickedCheckFri();
	afx_msg void OnBnClickedCheckSat();
	afx_msg void OnBnClickedCheckSun();
	afx_msg void OnBnClickedCheckca();
	afx_msg void OnEnChangeEditWhs1();
	CEdit m_Edit_WHS1;
	CEdit m_Edit_WHS2;
	CEdit m_Edit_WHE1;
	CEdit m_Edit_WHE2;
	afx_msg void OnEnChangeEditWhs2();
	afx_msg void OnEnChangeEditWhe1();
	afx_msg void OnEnChangeEditWhe2();
	afx_msg void OnCbnSelchangeComboD();
	afx_msg void OnCbnSelchangeComboO();
	afx_msg void OnBnClickedCheckOs();
	CButton m_Check_OS;
	afx_msg void OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_D;
	CEdit m_Edit_D;
	afx_msg void OnEnChangeEditD();
	afx_msg void OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_TT;
	CEdit m_Edit_TT;
	afx_msg void OnEnChangeEditTt();
};
