#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "MyTabBaseDlg.h"


// OSer_Dlg 对话框

class OSer_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(OSer_Dlg)

public:
	OSer_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~OSer_Dlg();

// 对话框数据
	enum { IDD = IDD_OSer_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnDeltaposSpinIt(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinIc(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinEr(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinRa(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_IT;
	CSpinButtonCtrl m_Spin_IC;
	CSpinButtonCtrl m_Spin_ER;
	CSpinButtonCtrl m_Spin_RA;
	CEdit m_Edit_IT;
	CEdit m_Edit_IC;
	CEdit m_Edit_ER;
	CEdit m_Edit_RA;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEditIt();
	afx_msg void OnEnChangeEditIc();
	afx_msg void OnEnChangeEditEr();
	afx_msg void OnEnChangeEditRa();
	afx_msg void OnCbnSelchangeComboNr();
	CComboBox m_ComboBox_NR;
};
