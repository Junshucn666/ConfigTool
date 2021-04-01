#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// AShbm_Dlg 对话框

class AShbm_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(AShbm_Dlg)

public:
	AShbm_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AShbm_Dlg();

// 对话框数据
	enum { IDD = IDD_AShbm_Dlg };

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
	afx_msg void OnDeltaposSpinAt1(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_AT1;
	CEdit m_Edit_AT1;
	afx_msg void OnDeltaposSpinAt2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinAt3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinAt4(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_Edit_AT2;
	CEdit m_Edit_AT3;
	CEdit m_Edit_AT4;
	CSpinButtonCtrl m_Spin_AT2;
	CSpinButtonCtrl m_Spin_AT3;
	CSpinButtonCtrl m_Spin_AT4;
	afx_msg void OnDeltaposSpinBt1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinBt2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinBt3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinBt4(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_BT1;
	CSpinButtonCtrl m_Spin_BT2;
	CSpinButtonCtrl m_Spin_BT3;
	CSpinButtonCtrl m_Spin_BT4;
	CEdit m_Edit_BT1;
	CEdit m_Edit_BT2;
	CEdit m_Edit_BT3;
	CEdit m_Edit_BT4;
	afx_msg void OnEnChangeEditAt1();
	afx_msg void OnEnChangeEditAt2();
	afx_msg void OnEnChangeEditAt3();
	afx_msg void OnEnChangeEditAt4();
	afx_msg void OnEnChangeEditBt1();
	afx_msg void OnEnChangeEditBt2();
	afx_msg void OnEnChangeEditBt3();
	afx_msg void OnEnChangeEditBt4();
	afx_msg void OnDeltaposSpinHad(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinHbd(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_HBD;
	CSpinButtonCtrl m_Spin_HAD;
	CEdit m_Edit_HBD;
	CEdit m_Edit_HAD;
	afx_msg void OnEnChangeEditHad();
	afx_msg void OnEnChangeEditHbd();
	afx_msg void OnCbnSelchangeComboOi();
	afx_msg void OnBnClickedCheckOuts();
	afx_msg void OnEnChangeEditD();
	afx_msg void OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditTt();
	CSpinButtonCtrl m_Spin_D;
	CSpinButtonCtrl m_Spin_TT;
	CEdit m_Edit_TT;
	CEdit m_Edit_D;
	CButton m_Check_OutS;
	CComboBox m_ComboBox_OI;
};
