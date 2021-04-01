#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// PRRfri_Dlg 对话框

class PRRfri_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(PRRfri_Dlg)

public:
	PRRfri_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PRRfri_Dlg();

// 对话框数据
	enum { IDD = IDD_PRRfri_Dlg };

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
	CButton m_Check_DNF;
	afx_msg void OnBnClickedCheckDnf();
	afx_msg void OnBnClickedCheckPe();
	CButton m_Check_PE;
	afx_msg void OnEnChangeEditSt();
	CEdit m_Edit_ST;
	afx_msg void OnEnChangeEditEt();
	CEdit m_Edit_ET;
	afx_msg void OnDeltaposSpinSi(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_SI;
	CEdit m_Edit_SI;
	afx_msg void OnEnChangeEditSi();
	afx_msg void OnDeltaposSpinIri(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_D;
	afx_msg void OnEnChangeEditD();
	CEdit m_Edit_D;
	afx_msg void OnDeltaposSpinM(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_M;
	CEdit m_Edit_M;
	afx_msg void OnEnChangeEditM();
	afx_msg void OnDeltaposSpinCr(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_CR;
	CEdit m_Edit_CR;
	afx_msg void OnEnChangeEditCr();
	CSpinButtonCtrl m_Spin_IRI;
	CEdit m_Edit_IRI;
	afx_msg void OnEnChangeEditIri();
	afx_msg void OnEnChangeEditAri();
	afx_msg void OnDeltaposSpinAri(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_ARI;
	CEdit m_Edit_ARI;
};
