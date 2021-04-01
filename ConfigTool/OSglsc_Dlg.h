#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"


// OSglsc_Dlg 对话框

class OSglsc_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(OSglsc_Dlg)

public:
	OSglsc_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~OSglsc_Dlg();

// 对话框数据
	enum { IDD = IDD_OSglsc_Dlg };

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
	CSpinButtonCtrl m_Spin_Ms;
	CSpinButtonCtrl m_Spin_ME;
	afx_msg void OnBnClickedOk();
	afx_msg void OnDeltaposSpinMs(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditMe();
	afx_msg void OnDeltaposSpinMe(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditMs();
	CEdit m_Edit_MS;
	CEdit m_Edit_ME;
	afx_msg void OnEnChangeEditN1();
	afx_msg void OnEnChangeEditN2();
	afx_msg void OnEnChangeEditN3();
	CEdit m_Edit_N1;
	CEdit m_Edit_N2;
	CEdit m_Edit_N3;
};
