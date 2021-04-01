#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"


// ASbad_Dlg 对话框

class ASbad_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(ASbad_Dlg)

public:
	ASbad_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ASbad_Dlg();

// 对话框数据
	enum { IDD = IDD_ASbad_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnEnChangeEditD1();
	afx_msg void OnCbnSelchangeComboOi();
	CComboBox m_ComboBox_OI;
	afx_msg void OnBnClickedCheckOs1();
	afx_msg void OnDeltaposSpinD1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinTt1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditTt1();
	CButton m_Check_OS1;
	CButton m_Check_OS2;
	CButton m_Check_OS3;
	CButton m_Check_OS4;
	CSpinButtonCtrl m_Spin_D1;
	CSpinButtonCtrl m_Spin_D2;
	CSpinButtonCtrl m_Spin_D3;
	CSpinButtonCtrl m_Spin_D4;
	CEdit m_Edit_D1;
	CEdit m_Edit_D2;
	CEdit m_Edit_D3;
	CEdit m_Edit_D4;
	CSpinButtonCtrl m_Spin_TT1;
	CSpinButtonCtrl m_Spin_TT2;
	CSpinButtonCtrl m_Spin_TT3;
	CSpinButtonCtrl m_Spin_TT4;
	CEdit m_Edit_TT1;
	CEdit m_Edit_TT2;
	CEdit m_Edit_TT3;
	CEdit m_Edit_TT4;
	afx_msg void OnBnClickedCheckOs2();
	afx_msg void OnDeltaposSpinD2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditD2();
	afx_msg void OnDeltaposSpinTt2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditTt2();
	afx_msg void OnBnClickedCheckOs3();
	afx_msg void OnDeltaposSpinD3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditD3();
	afx_msg void OnEnChangeEditTt3();
	afx_msg void OnDeltaposSpinTt3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCheckOs4();
	afx_msg void OnDeltaposSpinD4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditD4();
	afx_msg void OnDeltaposSpinTt4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditTt4();
};
