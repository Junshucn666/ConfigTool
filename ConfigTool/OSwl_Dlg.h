#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"


// OSwl_Dlg 对话框

class OSwl_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(OSwl_Dlg)

public:
	OSwl_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~OSwl_Dlg();

// 对话框数据
	enum { IDD = IDD_OSwl_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnCbnSelchangeComboN();
	CComboBox m_ComboBox_N;
	afx_msg void OnDeltaposSpinMs(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_Ms;
	CSpinButtonCtrl m_Spin_ME;
	CEdit m_Edit_MS;
	CEdit m_Edit_ME;
	afx_msg void OnDeltaposSpinMe(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEditMs();
	afx_msg void OnEnChangeEditMe();
	CEdit m_Edit_N1;
	CEdit m_Edit_N2;
	CEdit m_Edit_N3;
	CEdit m_Edit_N4;
	CEdit m_Edit_N5;
	CEdit m_Edit_N6;
	CEdit m_Edit_N7;
	CEdit m_Edit_N8;
	CEdit m_Edit_N9;
	CEdit m_Edit_N10;
	afx_msg void OnEnChangeEditN1();
	afx_msg void OnEnChangeEditN2();
	afx_msg void OnEnChangeEditN3();
	afx_msg void OnEnChangeEditN4();
	afx_msg void OnEnChangeEditN5();
	afx_msg void OnEnChangeEditN6();
	afx_msg void OnEnChangeEditN7();
	afx_msg void OnEnChangeEditN8();
	afx_msg void OnEnChangeEditN9();
	afx_msg void OnEnChangeEditN10();

};
