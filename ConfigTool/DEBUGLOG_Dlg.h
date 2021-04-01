#pragma once
#include "afxwin.h"


// DEBUGLOG_Dlg 对话框

class DEBUGLOG_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(DEBUGLOG_Dlg)

public:
	DEBUGLOG_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DEBUGLOG_Dlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_DebugLog };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_DebugLogForm;
};
