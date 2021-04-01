#pragma once
#include "afxwin.h"
#include "resource.h"


// TESTLIST_Dlg 对话框

class TESTLIST_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(TESTLIST_Dlg)

public:
	TESTLIST_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TESTLIST_Dlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_TestList };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_TestListForm;
	virtual BOOL OnInitDialog();
	void OnCustomdrawList(NMHDR *pNMHDR, LRESULT *pResult);
};
