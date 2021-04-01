#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// SCbsri_Dlg 对话框

class SCbsri_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(SCbsri_Dlg)

public:
	SCbsri_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SCbsri_Dlg();

// 对话框数据
	enum { IDD = IDD_SCbsri_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_ComboBox_RM;
	afx_msg void OnCbnSelchangeComboRm();
	CComboBox m_ComboBox_BM;
	CComboBox m_ComboBox_SE;
	CComboBox m_ComboBox_PF;
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnDeltaposSpinMsp(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_Edit_MSP;
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnEnChangeEditMsi();
	CEdit m_Edit_MSI;
	CSpinButtonCtrl m_Spin_MSP;
	afx_msg void OnEnChangeEditMsp();
	CEdit m_Edit_BSI;
	afx_msg void OnEnChangeEditBsi();
	afx_msg void OnDeltaposSpinBsp(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_Edit_BSP;
	CSpinButtonCtrl m_Spin_BSP;
	afx_msg void OnEnChangeEditBsp();
	CEdit m_Edit_SG;
	afx_msg void OnEnChangeEditSg();
	afx_msg void OnDeltaposSpinHi(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_HI;
	CEdit m_Edit_HI;
	afx_msg void OnEnChangeEditHi();
	afx_msg void OnCbnSelchangeComboBm();
	afx_msg void OnCbnSelchangeComboSe();
	afx_msg void OnCbnSelchangeComboPf();
	CButton m_Check_SSE;
	afx_msg void OnBnClickedCheckSse();
	afx_msg void OnEnChangeEditGtsri();
};
