#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "MyTabBaseDlg.h"

// AStac_Dlg 对话框

class AStac_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(AStac_Dlg)

public:
	AStac_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AStac_Dlg();

// 对话框数据
	enum { IDD = IDD_AStac_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnDeltaposSpinEott(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_Eott;
	CEdit m_Edit_Eott;
	afx_msg void OnBnClickedCheckTe();
	CButton m_Check_TE;
	afx_msg void OnEnChangeEditGttow();
	afx_msg void OnEnChangeEditEott();
	afx_msg void OnDeltaposSpinFtd(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_FTD;
	CEdit m_Edit_FTD;
	afx_msg void OnEnChangeEditFtd();
	afx_msg void OnDeltaposSpinTi(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_TI;
	CEdit m_Edit_TI;
	afx_msg void OnEnChangeEditTi();
	afx_msg void OnCbnSelchangeComboToi();
	CComboBox m_ComboBox_TOI;
	afx_msg void OnBnClickedCheckTos();
	CButton m_Check_TOS;
	afx_msg void OnDeltaposSpinTod(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_TOD;
	CEdit m_Edit_TOD;
	afx_msg void OnEnChangeEditTod();
	afx_msg void OnDeltaposSpinTott(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_TOTT;
	CEdit m_Edit_TOTT;
	afx_msg void OnEnChangeEditTott();
	afx_msg void OnDeltaposSpinRd(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_RD;
	CEdit m_Edit_RD;
	afx_msg void OnEnChangeEditRd();
	afx_msg void OnDeltaposSpinMd(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_MD;
	CEdit m_Edit_MD;
	afx_msg void OnEnChangeEditMd();
	afx_msg void OnCbnSelchangeComboMt();
	CComboBox m_ComboBox_MT;
};
