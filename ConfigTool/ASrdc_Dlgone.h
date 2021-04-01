#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// ASrdc_Dlgone 对话框

class ASrdc_Dlgone : public CDialogEx
{
	DECLARE_DYNAMIC(ASrdc_Dlgone)

public:
	ASrdc_Dlgone(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ASrdc_Dlgone();

// 对话框数据
	enum { IDD = IDD_ASrdc_DlgOne };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void ReSize(UINT nType, int cx, int cy);
	CList<CRect,CRect&> m_listRect;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedCheckEmna();
	void GetKREMValue();
	void SetKREMValue(CString sStrH);
	void GetUREMValue();
	void SetUREMValue(CString sStrH);
	CButton m_Check_B0;
	CButton m_Check_B1;
	CButton m_Check_B2;
	CButton m_Check_B3;
	CButton m_Check_B4;
	CButton m_Check_B5;
	CButton m_Check_B6;
	CButton m_Check_B7;
	CButton m_Check_B8;
	CButton m_Check_B9;
	CButton m_Check_B10;
	CButton m_Check_B11;
	CButton m_Check_B12;
	CButton m_Check_B13;
	CButton m_Check_B14;
	CButton m_Check_U0;
	CButton m_Check_U1;
	CButton m_Check_U2;
	CButton m_Check_U3;
	CButton m_Check_U4;
	CButton m_Check_U5;
	CButton m_Check_U6;
	CButton m_Check_U7;
	CButton m_Check_U8;
	CButton m_Check_U9;
	CButton m_Check_U10;
	CButton m_Check_U11;
	CButton m_Check_U12;
	CButton m_Check_U13;
	CButton m_Check_U14;
	CEdit m_Edit_HS;
	CEdit m_Edit_HE;
	afx_msg void OnDeltaposSpinMs(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinMe(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_MS;
	CSpinButtonCtrl m_Spin_ME;
	afx_msg void OnBnClickedCheckB0();
	afx_msg void OnBnClickedCheckB6();
	afx_msg void OnBnClickedCheckB12();
	afx_msg void OnBnClickedCheckB1();
	afx_msg void OnBnClickedCheckB7();
	afx_msg void OnBnClickedCheckB2();
	afx_msg void OnBnClickedCheckB8();
	afx_msg void OnBnClickedCheckB13();
	afx_msg void OnBnClickedCheckB3();
	afx_msg void OnBnClickedCheckB9();
	afx_msg void OnBnClickedCheckB14();
	afx_msg void OnBnClickedCheckB4();
	afx_msg void OnBnClickedCheckB10();
	afx_msg void OnBnClickedCheckB5();
	afx_msg void OnBnClickedCheckB11();
	afx_msg void OnBnClickedCheckEmca();
	CButton m_Check_EMca;
	afx_msg void OnBnClickedCheckU0();
	afx_msg void OnBnClickedCheckU6();
	afx_msg void OnBnClickedCheckU12();
	afx_msg void OnBnClickedCheckU1();
	afx_msg void OnBnClickedCheckU7();
	afx_msg void OnBnClickedCheckU2();
	afx_msg void OnBnClickedCheckU8();
	afx_msg void OnBnClickedCheckU13();
	afx_msg void OnBnClickedCheckU3();
	afx_msg void OnBnClickedCheckU9();
	afx_msg void OnBnClickedCheckU14();
	afx_msg void OnBnClickedCheckU4();
	afx_msg void OnBnClickedCheckU10();
	afx_msg void OnBnClickedCheckU5();
	afx_msg void OnBnClickedCheckU11();
	afx_msg void OnBnClickedCheckEmca2();
	CButton m_Check_EMca2;
	afx_msg void OnEnChangeEditHs();
	afx_msg void OnEnChangeEditHe();
	afx_msg void OnEnChangeEditH1();
	afx_msg void OnEnChangeEditH2();
	afx_msg void OnEnChangeEditH3();
	afx_msg void OnEnChangeEditH4();
	afx_msg void OnEnChangeEditH5();
	afx_msg void OnEnChangeEditH6();
	afx_msg void OnEnChangeEditH7();
	afx_msg void OnEnChangeEditH8();
	afx_msg void OnEnChangeEditH9();
	afx_msg void OnEnChangeEditH10();
	CEdit m_Edit_BS;
	CEdit m_Edit_BE;
	afx_msg void OnDeltaposSpinBs(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinBe(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_BS;
	CSpinButtonCtrl m_Spin_BE;
	afx_msg void OnEnChangeEditBs();
	afx_msg void OnEnChangeEditBe();
	afx_msg void OnEnChangeEditC1();
	afx_msg void OnEnChangeEditC3();
	afx_msg void OnEnChangeEditC2();
	afx_msg void OnEnChangeEditC5();
	afx_msg void OnEnChangeEditC4();
	afx_msg void OnEnChangeEditC6();
	afx_msg void OnEnChangeEditC7();
	afx_msg void OnEnChangeEditC8();
	afx_msg void OnEnChangeEditC9();
	afx_msg void OnEnChangeEditC10();
	afx_msg void OnEnChangeEditC11();
	afx_msg void OnEnChangeEditC12();
	afx_msg void OnEnChangeEditC13();
	afx_msg void OnEnChangeEditC14();
	afx_msg void OnEnChangeEditC15();
	afx_msg void OnEnChangeEditC16();
	afx_msg void OnEnChangeEditC17();
	afx_msg void OnEnChangeEditC18();
	afx_msg void OnEnChangeEditC19();
	afx_msg void OnEnChangeEditC20();
};
