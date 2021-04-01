#pragma once
#include "afxwin.h"
#include "MyTabBaseDlg.h"


// IDSvims_Dlg 对话框

class IDSvims_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(IDSvims_Dlg)

public:
	IDSvims_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~IDSvims_Dlg();

// 对话框数据
	enum { IDD = IDD_IDSvims_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnCbnSelchangeComboVim();
	CComboBox m_ComboBox_VIM;
};
