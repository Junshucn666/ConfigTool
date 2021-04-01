#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// ASsosa_Dlg 对话框

class ASsosa_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(ASsosa_Dlg)

public:
	ASsosa_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ASsosa_Dlg();

// 对话框数据
	enum { IDD = IDD_ASsosa_Dlg };

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
	afx_msg void OnCbnSelchangeComboDoi();
	CComboBox m_ComboBox_DOI;
	afx_msg void OnCbnSelchangeComboOi();
	CComboBox m_ComboBox_OI;
	afx_msg void OnBnClickedCheckOuts();
	CButton m_Check_OutS;
	afx_msg void OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditD();
	CSpinButtonCtrl m_Spin_D;
	CEdit m_Edit_D;
	CSpinButtonCtrl m_Spin_TT;
	afx_msg void OnEnChangeEditTt();
	CEdit m_Edit_TT;
	afx_msg void OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult);
};
