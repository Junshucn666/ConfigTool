#pragma once
#include "afxwin.h"
#include "MyTabBaseDlg.h"


// OShmc_Dlg 对话框

class OShmc_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(OShmc_Dlg)

public:
	OShmc_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~OShmc_Dlg();

// 对话框数据
	enum { IDD = IDD_OShmc_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnBnClickedCheckH();
	CButton m_Check_H;
	afx_msg void OnEnChangeEditI();
	CEdit m_Edit_I;
};
