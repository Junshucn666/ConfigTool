#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// DCpcs_Dlg 对话框

class DCpcs_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(DCpcs_Dlg)

public:
	DCpcs_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DCpcs_Dlg();

// 对话框数据
	enum { IDD = IDD_DCpcs_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	void GetCMD();
	BOOL UpdataPage(CString sStr);
	afx_msg void OnBnClickedCheckEpd();
	CButton m_Check_EPD;
	afx_msg void OnDeltaposSpinTd(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_TD;
	CEdit m_Edit_TD;
	afx_msg void OnEnChangeEditTd();
};
