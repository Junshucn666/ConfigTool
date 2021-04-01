#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "MyTabBaseDlg.h"


// OSgs_Dlg 对话框

class OSgs_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(OSgs_Dlg)

public:
	OSgs_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~OSgs_Dlg();

// 对话框数据
	enum { IDD = IDD_OSgs_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnDeltaposSpinBs(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_BS;
	CSpinButtonCtrl m_Spin_DS;
	CSpinButtonCtrl m_Spin_DH;
	CEdit m_Edit_BS;
	CEdit m_Edit_DS;
	CEdit m_Edit_DH;
	afx_msg void OnDeltaposSpinDs(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinDh(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditBs();
	afx_msg void OnEnChangeEditDs();
	afx_msg void OnEnChangeEditDh();
	afx_msg void OnCbnSelchangeComboOi();
	afx_msg void OnBnClickedCheckOuts();
	afx_msg void OnEnChangeEditD();
	afx_msg void OnEnChangeEditTt();
	afx_msg void OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult);
	CComboBox m_ComboBox_OI;
	CEdit m_Edit_TT;
	CEdit m_Edit_D;
	CButton m_Check_OutS;
	CSpinButtonCtrl m_Spin_D;
	CSpinButtonCtrl m_Spin_TT;
};
