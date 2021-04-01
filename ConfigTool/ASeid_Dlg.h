#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// ASeid_Dlg 对话框

class ASeid_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(ASeid_Dlg)

public:
	ASeid_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ASeid_Dlg();

// 对话框数据
	enum { IDD = IDD_ASeid_Dlg };

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
	afx_msg void OnDeltaposSpinIdt(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_IDT;
	CEdit m_Edit_IDT;
	afx_msg void OnEnChangeEditIdt();
	afx_msg void OnDeltaposSpinIet(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_IET;
	CEdit m_Edit_IET;
	afx_msg void OnEnChangeEditIet();
	afx_msg void OnCbnSelchangeComboDo();
	CComboBox m_ComboBox_DO;
	afx_msg void OnCbnSelchangeComboOi();
	CComboBox m_ComboBox_OI;
	afx_msg void OnBnClickedCheckOuts();
	CButton m_Check_OutS;
	afx_msg void OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_D;
	CEdit m_Edit_D;
	afx_msg void OnEnChangeEditD();
	afx_msg void OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_TT;
	CEdit m_Edit_TT;
	afx_msg void OnEnChangeEditTt();
};
