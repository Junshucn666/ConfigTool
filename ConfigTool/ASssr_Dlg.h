#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// ASssr_Dlg 对话框

class ASssr_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(ASssr_Dlg)

public:
	ASssr_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ASssr_Dlg();

// 对话框数据
	enum { IDD = IDD_ASssr_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnCbnSelchangeComboM();
	CComboBox m_ComboBox_M;
	afx_msg void OnDeltaposSpinStop(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinStart(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinSs(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinLs(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_Stop;
	CSpinButtonCtrl m_Spin_Start;
	CSpinButtonCtrl m_Spin_SS;
	CSpinButtonCtrl m_Spin_LS;
	CEdit m_Edit_Stop;
	CEdit m_Edit_Start;
	CEdit m_Edit_SS;
	CEdit m_Edit_LS;
	afx_msg void OnEnChangeEditStop();
	afx_msg void OnEnChangeEditStart();
	afx_msg void OnEnChangeEditSs();
	afx_msg void OnEnChangeEditLs();
	afx_msg void OnCbnSelchangeComboTu();
	CComboBox m_ComboBox_TU;
};
