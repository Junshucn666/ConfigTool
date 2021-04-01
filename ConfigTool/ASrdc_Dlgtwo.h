#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// ASrdc_Dlgtwo 对话框

class ASrdc_Dlgtwo : public CDialogEx
{
	DECLARE_DYNAMIC(ASrdc_Dlgtwo)

public:
	ASrdc_Dlgtwo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ASrdc_Dlgtwo();

// 对话框数据
	enum { IDD = IDD_ASrdc_DlgTwo };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void ReSize(UINT nType, int cx, int cy);
	CList<CRect,CRect&> m_listRect;
	CEdit m_Edit_RS;
	CEdit m_Edit_RE;
	afx_msg void OnDeltaposSpinRs(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinRe(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_RS;
	CSpinButtonCtrl m_Spin_RE;
	afx_msg void OnEnChangeEditRs();
	afx_msg void OnEnChangeEditRe();
	afx_msg void OnEnChangeEditR1();
	afx_msg void OnEnChangeEditR2();
	afx_msg void OnEnChangeEditR3();
	afx_msg void OnEnChangeEditR4();
	afx_msg void OnEnChangeEditR5();
	afx_msg void OnEnChangeEditR51();
	afx_msg void OnEnChangeEditR52();
	afx_msg void OnEnChangeEditR53();
	afx_msg void OnEnChangeEditR54();
	afx_msg void OnEnChangeEditR55();
	afx_msg void OnEnChangeEditR6();
	afx_msg void OnEnChangeEditR7();
	afx_msg void OnEnChangeEditR8();
	afx_msg void OnEnChangeEditR9();
	afx_msg void OnEnChangeEditR10();
	afx_msg void OnEnChangeEditR56();
	afx_msg void OnEnChangeEditR57();
	afx_msg void OnEnChangeEditR58();
	afx_msg void OnEnChangeEditR59();
	afx_msg void OnEnChangeEditR60();
};
