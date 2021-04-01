#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"


// IAips_Dlg 对话框

class IAips_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(IAips_Dlg)

public:
	IAips_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~IAips_Dlg();

// 对话框数据
	enum { IDD = IDD_IAips_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnCbnSelchangeComboIi();
	CComboBox m_ComboBox_II;
	afx_msg void OnBnClickedCheckId1();
	void GetIMValue();
	void GetTMValue();
	void SetIMValue(CString sStrH);
	void SetTMValue(CString sStrH);
	CButton m_Check_ID1;
	CButton m_Check_DI1;
	CButton m_Check_ID2;
	CButton m_Check_DI2;
	afx_msg void OnBnClickedCheckDi1();
	afx_msg void OnBnClickedCheckId2();
	afx_msg void OnBnClickedCheckDi2();

	afx_msg void OnDeltaposSpinSp(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_SP;
	CEdit m_Edit_SP;
	afx_msg void OnEnChangeEditSp();
	afx_msg void OnCbnSelchangeComboOi();
	afx_msg void OnBnClickedCheckOuts();
	afx_msg void OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditTt();
	afx_msg void OnEnChangeEditD();
	CComboBox m_ComboBox_OI;
	CButton m_Check_OutS;
	CSpinButtonCtrl m_Spin_D;
	CEdit m_Edit_D;
	CEdit m_Edit_TT;
	CSpinButtonCtrl m_Spin_TT;
};
