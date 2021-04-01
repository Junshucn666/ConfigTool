#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// ASgc_Dlg 对话框

class ASgc_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(ASgc_Dlg)

public:
	ASgc_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ASgc_Dlg();

// 对话框数据
	enum { IDD = IDD_ASgc_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持


	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnCbnSelchangeComboGi();
	CComboBox m_ComboBox_GI;
	afx_msg void OnCbnSelchangeComboM();
	CComboBox m_ComboBox_M;
	afx_msg void OnDeltaposSpinLat(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_Lat;
	CEdit m_Edit_Lat;
	afx_msg void OnEnChangeEditLat();
	afx_msg void OnEnChangeEditLon();
	CEdit m_Edit_Lon;
	afx_msg void OnDeltaposSpinR(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_R;
	CEdit m_Edit_R;
	afx_msg void OnDeltaposSpinCi(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_CI;
	CEdit m_Edit_CI;
	afx_msg void OnEnChangeEditR();
	afx_msg void OnEnChangeEditCi();
	afx_msg void OnCbnSelchangeComboOi();
	CComboBox m_ComboBox_OI;
	afx_msg void OnBnClickedCheckOuts();
	CButton m_Check_OutS;
	afx_msg void OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_D;
	CEdit m_Edit_D;
	afx_msg void OnEnChangeEditD();
	afx_msg void OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_TT;
	CEdit m_Edit_TT;
	afx_msg void OnEnChangeEditTt();
	afx_msg void OnCbnSelchangeComboTm();
	CComboBox m_ComboBox_TM;
	afx_msg void OnCbnSelchangeComboTr();
	CComboBox m_ComboBox_TR;
	afx_msg void OnDeltaposSpinLon(NMHDR *pNMHDR, LRESULT *pResult);
	double m_LotdNum;
	double m_LondNum;
};
