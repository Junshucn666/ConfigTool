#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"


// IAepsm_Dlg 对话框

class IAepsm_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(IAepsm_Dlg)

public:
	IAepsm_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~IAepsm_Dlg();

// 对话框数据
	enum { IDD = IDD_IAepsm_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnCbnSelchangeComboM();
	CComboBox m_ComboBox_M;
	afx_msg void OnDeltaposSpinMt1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinSp(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinDt(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinMt2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinMvt(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_MT1;
	CSpinButtonCtrl m_Spin_MT2;
	CSpinButtonCtrl m_Spin_SP;
	CSpinButtonCtrl m_Spin_DT;
	CSpinButtonCtrl m_Spin_MVT;
	CEdit m_Edit_MT1;
	CEdit m_Edit_MT2;
	CEdit m_Edit_SP;
	CEdit m_Edit_DT;
	CEdit m_Edit_MVT;
	afx_msg void OnEnChangeEditSp();
	afx_msg void OnEnChangeEditMt1();
	afx_msg void OnEnChangeEditDt();
	afx_msg void OnEnChangeEditMvt();
	afx_msg void OnEnChangeEditMt2();
	afx_msg void OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeComboOi();
	afx_msg void OnBnClickedCheckOuts();
	afx_msg void OnEnChangeEditD();
	afx_msg void OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditTt();
	CComboBox m_ComboBox_OI;
	CButton m_Check_OutS;
	CSpinButtonCtrl m_Spin_D;
	CSpinButtonCtrl m_Spin_TT;
	CEdit m_Edit_D;
	CEdit m_Edit_TT;
	afx_msg void OnCbnSelchangeComboSwf();
	afx_msg void OnBnClickedCheckSwf();
	CButton m_Check_SWF;
	CComboBox m_ComboBox_SWF;
};
