#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// DCta_Dlg 对话框

class DCta_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(DCta_Dlg)

public:
	DCta_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DCta_Dlg();

// 对话框数据
	enum { IDD = IDD_DCta_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	CComboBox m_ComboBox_S;
	afx_msg void OnCbnSelchangeComboS();
	afx_msg void OnBnClickedCheckDs();
	CButton m_Check_DS;
	afx_msg void OnDeltaposSpinHo(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_HO;
	CEdit m_Edit_HO;
	afx_msg void OnEnChangeEditHo();
	afx_msg void OnDeltaposSpinMo(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_MO;
	CEdit m_Edit_MO;
	afx_msg void OnEnChangeEditMo();
	afx_msg void OnEnChangeEditUt();
	CEdit m_Edit_UT;
};
