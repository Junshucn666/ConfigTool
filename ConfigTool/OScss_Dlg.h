#pragma once
#include "afxwin.h"
#include "MyTabBaseDlg.h"


// OScss_Dlg 对话框

class OScss_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(OScss_Dlg)

public:
	OScss_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~OScss_Dlg();

// 对话框数据
	enum { IDD = IDD_OScss_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnBnClickedOk();
	afx_msg void OnCbnSelchangeComboMode();
	CComboBox m_ComboBox_M;
	afx_msg void OnCbnSelchangeComboSi();
	CComboBox m_ComboBox_SI;
	afx_msg void OnEnChangeEditC();
	CEdit m_Edit_C;
};
