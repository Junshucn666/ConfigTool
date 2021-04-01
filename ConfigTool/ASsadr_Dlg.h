#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// ASsadr_Dlg 对话框

class ASsadr_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(ASsadr_Dlg)

public:
	ASsadr_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ASsadr_Dlg();

// 对话框数据
	enum { IDD = IDD_ASsadr_Dlg };

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
	CComboBox m_ComboBox_DRM;
	afx_msg void OnCbnSelchangeComboDrm();
	afx_msg void OnDeltaposSpinDri(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinDrd(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinDrm(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinMn(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_DRI;
	CSpinButtonCtrl m_Spin_DRD;
	CSpinButtonCtrl m_Spin_DRM;
	CSpinButtonCtrl m_Spin_MN;
	CEdit m_Edit_DRI;
	CEdit m_Edit_DRD;
	CEdit m_Edit_DRM;
	CEdit m_Edit_MN;
	afx_msg void OnEnChangeEditDri();
	afx_msg void OnEnChangeEditDrd();
	afx_msg void OnEnChangeEditDrm();
	afx_msg void OnEnChangeEditMn();
};
