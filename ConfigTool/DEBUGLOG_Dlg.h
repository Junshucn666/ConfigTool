#pragma once
#include "afxwin.h"


// DEBUGLOG_Dlg �Ի���

class DEBUGLOG_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(DEBUGLOG_Dlg)

public:
	DEBUGLOG_Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DEBUGLOG_Dlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_DebugLog };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_DebugLogForm;
};
