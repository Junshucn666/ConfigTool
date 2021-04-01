#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// ASosa_Dlg 对话框

class ASosa_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(ASosa_Dlg)

public:
	ASosa_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ASosa_Dlg();

// 对话框数据
	enum { IDD = IDD_ASosa_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnCbnSelchangeComboMode();
	CComboBox m_ComboBox_M;
	afx_msg void OnEnChangeEditAt1();
	afx_msg void OnDeltaposSpinSt1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditSt1();
	afx_msg void OnDeltaposSpinV1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditV1();
	afx_msg void OnDeltaposSpinAt1(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_ST1;
	CSpinButtonCtrl m_Spin_ST2;
	CSpinButtonCtrl m_Spin_ST3;
	CSpinButtonCtrl m_Spin_ST4;
	CEdit m_Edit_ST1;
	CEdit m_Edit_ST2;
	CEdit m_Edit_ST3;
	CEdit m_Edit_ST4;
	CSpinButtonCtrl m_Spin_V1;
	CSpinButtonCtrl m_Spin_V2;
	CSpinButtonCtrl m_Spin_V3;
	CSpinButtonCtrl m_Spin_V4;
	CEdit m_Edit_V1;
	CEdit m_Edit_V2;
	CEdit m_Edit_V3;
	CEdit m_Edit_V4;
	CSpinButtonCtrl m_Spin_AT1;
	CSpinButtonCtrl m_Spin_AT2;
	CSpinButtonCtrl m_Spin_AT3;
	CSpinButtonCtrl m_Spin_AT4;
	CEdit m_Edit_AT1;
	CEdit m_Edit_AT2;
	CEdit m_Edit_AT3;
	CEdit m_Edit_AT4;
	afx_msg void OnDeltaposSpinSt2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditSt2();
	afx_msg void OnDeltaposSpinV2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditV2();
	afx_msg void OnDeltaposSpinAt2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditAt2();
	afx_msg void OnDeltaposSpinSt3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditSt3();
	afx_msg void OnDeltaposSpinV3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditV3();
	afx_msg void OnDeltaposSpinAt3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditAt3();
	afx_msg void OnDeltaposSpinSt4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditSt4();
	afx_msg void OnDeltaposSpinV4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditV4();
	afx_msg void OnDeltaposSpinAt4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditAt4();
};
