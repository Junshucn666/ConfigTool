#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "MyTabBaseDlg.h"


// IDSavis_Dlg 对话框

class IDSavis_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(IDSavis_Dlg)

public:
	IDSavis_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~IDSavis_Dlg();

// 对话框数据
	enum { IDD = IDD_IDSavis_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnEnChangeEditSrd();
	afx_msg void OnDeltaposSpinSrd(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinSmv(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_SRD;
	CSpinButtonCtrl m_Spin_SMV;
	CEdit m_Edit_SRD;
	CEdit m_Edit_SMV;
	afx_msg void OnEnChangeEditSmv();
};
