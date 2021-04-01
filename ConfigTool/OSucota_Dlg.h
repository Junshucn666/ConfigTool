#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"


// OSucota_Dlg 对话框

class OSucota_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(OSucota_Dlg)

public:
	OSucota_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~OSucota_Dlg();

// 对话框数据
	enum { IDD = IDD_OSucota_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnCbnSelchangeComboMr();
	CComboBox m_ComboBox_MR;
	afx_msg void OnEnChangeEditDt();
	afx_msg void OnDeltaposSpinTd(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_TD;
	CEdit m_Edit_TD;
	afx_msg void OnBnClickedCheckRe();
	CButton m_Check_RE;
	afx_msg void OnDeltaposSpinTd2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinUi(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_UI;
	afx_msg void OnEnChangeEditUi();
	CEdit m_Edit_UI;
	afx_msg void OnEnChangeEditDu();
	CEdit m_Edit_DU;
	afx_msg void OnCbnSelchangeComboM();
	CComboBox m_ComboBox_M;
};
