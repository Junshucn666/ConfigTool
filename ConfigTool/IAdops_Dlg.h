#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"


// IAdops_Dlg 对话框

class IAdops_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(IAdops_Dlg)

public:
	IAdops_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~IAdops_Dlg();

// 对话框数据
	enum { IDD = IDD_IAdops_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnBnClickedCheckOuts1();
	afx_msg void OnDeltaposSpinD1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditD1();
	afx_msg void OnDeltaposSpinTt1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditTt1();
	CButton m_Check_OutS1;
	CButton m_Check_OutS2;
	CSpinButtonCtrl m_Spin_D1;
	CSpinButtonCtrl m_Spin_D2;
	CSpinButtonCtrl m_Spin_TT2;
	CSpinButtonCtrl m_Spin_TT1;
	CEdit m_Edit_D1;
	CEdit m_Edit_D2;
	CEdit m_Edit_TT1;
	CEdit m_Edit_TT2;
	afx_msg void OnDeltaposSpinD2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditD2();
	afx_msg void OnBnClickedCheckOuts2();
	afx_msg void OnDeltaposSpinTt2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditTt2();
	afx_msg void OnBnClickedCheckO1();
	void GetOuValue();
	CButton m_Check_O1;
	CButton m_Check_O2;
	afx_msg void OnBnClickedCheckO2();
	afx_msg void OnDeltaposSpinL1(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_L1;
	CSpinButtonCtrl m_Spin_L2;
	CEdit m_Edit_L1;
	CEdit m_Edit_L2;
	afx_msg void OnDeltaposSpinL2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditL1();
	afx_msg void OnEnChangeEditL2();
	afx_msg void OnBnClickedOk();
	void SetOuValue(CString sStrH);
};
