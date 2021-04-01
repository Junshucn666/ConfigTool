#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// ASser_Dlg 对话框

class ASser_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(ASser_Dlg)

public:
	ASser_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ASser_Dlg();

// 对话框数据
	enum { IDD = IDD_ASser_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnDeltaposSpinT1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeComboM();
	CComboBox m_ComboBox_M;
	afx_msg void OnDeltaposSpinT2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinT3(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_T1;
	CSpinButtonCtrl m_Spin_T2;
	CSpinButtonCtrl m_Spin_T3;
	CEdit m_Edit_T1;
	CEdit m_Edit_T2;
	CEdit m_Edit_T3;
	afx_msg void OnEnChangeEditT1();
	afx_msg void OnEnChangeEditT2();
	afx_msg void OnEnChangeEditT3();
};
