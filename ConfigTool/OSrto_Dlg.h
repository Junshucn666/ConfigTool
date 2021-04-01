#pragma once
#include "afxwin.h"
#include "MyTabBaseDlg.h"


// OSrto_Dlg 对话框

class OSrto_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(OSrto_Dlg)

public:
	OSrto_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~OSrto_Dlg();

// 对话框数据
	enum { IDD = IDD_OSrto_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnBnClickedOk();
	afx_msg void OnCbnSelchangeComboRm();
	afx_msg void OnCbnSelchangeComboSc();
	CComboBox m_ComboBox_SC;
	CComboBox m_ComboBox_OD;
	afx_msg void OnCbnSelchangeComboOd();
};
