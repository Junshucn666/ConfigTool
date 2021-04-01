#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "MyTabBaseDlg.h"


// IDSidbvs_Dlg 对话框

class IDSidbvs_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(IDSidbvs_Dlg)

public:
	IDSidbvs_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~IDSidbvs_Dlg();

// 对话框数据
	enum { IDD = IDD_IDSidbvs_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnEnChangeEditIov();
	afx_msg void OnDeltaposSpinIov(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_IoV;
	CSpinButtonCtrl m_Spin_Vo;
	CSpinButtonCtrl m_Spin_D;
	CSpinButtonCtrl m_Spin_IN;
	CSpinButtonCtrl m_Spin_IF;
	afx_msg void OnDeltaposSpinVo(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinIn(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinIf(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_Edit_IoV;
	CEdit m_Edit_Vo;
	CEdit m_Edit_D;
	CEdit m_Edit_IN;
	CEdit m_Edit_IF;
	afx_msg void OnEnChangeEditIn();
	afx_msg void OnEnChangeEditIf();
};
