#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"


// IAdips_Dlg 对话框

class IAdips_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(IAdips_Dlg)

public:
	IAdips_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~IAdips_Dlg();

// 对话框数据
	enum { IDD = IDD_IAdips_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnEnChangeEditVt();
	afx_msg void OnBnClickedCheckEti();
	CEdit m_Edit_VT;
	CButton m_Check_ETI;
	afx_msg void OnCbnSelchangeComboIts();
	CComboBox m_ComboBox_ITS;
	afx_msg void OnDeltaposSpinVt(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_VT;
};
