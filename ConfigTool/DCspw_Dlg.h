#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// DCspw_Dlg 对话框

class DCspw_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(DCspw_Dlg)

public:
	DCspw_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DCspw_Dlg();

// 对话框数据
	enum { IDD = IDD_DCspw_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEdit m_Edit_GTDOG;
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	CComboBox m_ComboBox_M;
	CComboBox m_ComboBox_U;
	CComboBox m_ComboBox_I;
	afx_msg void OnCbnSelchangeComboM();
	afx_msg void OnDeltaposSpinMsp(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinIf(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_IF;
	CEdit m_Edit_IF;
	afx_msg void OnDeltaposSpinRi(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_RI;
	CEdit m_Edit_RI;
	afx_msg void OnEnChangeEditIf();
	afx_msg void OnEnChangeEditRi();
	afx_msg void OnEnChangeEditTime();
	CEdit m_Edit_T;
	afx_msg void OnBnClickedCheckRbr();
	CButton m_Check_RBR;
	afx_msg void OnCbnSelchangeComboI();
	afx_msg void OnCbnSelchangeComboU();
	afx_msg void OnDeltaposSpinMspNni(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_NNI;
	afx_msg void OnEnChangeEditNni();
	CEdit m_Edit_NNI;
	afx_msg void OnDeltaposSpinNai(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_NAI;
	CEdit m_Edit_NAI;
	afx_msg void OnEnChangeEditNai();
	afx_msg void OnDeltaposSpinSft(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_SFT;
	CEdit m_Edit_SFT;
	afx_msg void OnEnChangeEditSft();
};
