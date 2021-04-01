#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// AScd_Dlg 对话框

class AScd_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(AScd_Dlg)

public:
	AScd_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AScd_Dlg();

// 对话框数据
	enum { IDD = IDD_AScd_Dlg };

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
	afx_msg void OnDeltaposSpinS(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinGb(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinGa(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinGb2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinGa2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeComboGs();
	CComboBox m_ComboBox_GS;
	CSpinButtonCtrl m_Spin_S;
	CSpinButtonCtrl m_Spin_GB;
	CSpinButtonCtrl m_Spin_GA;
	CSpinButtonCtrl m_Spin_GB2;
	CSpinButtonCtrl m_Spin_GA2;
	CEdit m_Edit_S;
	CEdit m_Edit_GB;
	CEdit m_Edit_GA;
	CEdit m_Edit_GB2;
	CEdit m_Edit_GA2;
	afx_msg void OnEnChangeEditS();
	afx_msg void OnEnChangeEditGb();
	afx_msg void OnEnChangeEditGa();
	afx_msg void OnEnChangeEditGb2();
	afx_msg void OnEnChangeEditGa2();
	afx_msg void OnCbnSelchangeComboOi();
	afx_msg void OnBnClickedCheckOuts();
	afx_msg void OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditD();
	afx_msg void OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditTt();
	CComboBox m_ComboBox_OI;
	CButton m_Check_OutS;
	CSpinButtonCtrl m_Spin_D;
	CSpinButtonCtrl m_Spin_TT;
	CEdit m_Edit_D;
	CEdit m_Edit_TT;
};
