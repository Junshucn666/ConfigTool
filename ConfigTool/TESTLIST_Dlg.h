#pragma once
#include "afxwin.h"
#include "resource.h"


// TESTLIST_Dlg �Ի���

class TESTLIST_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(TESTLIST_Dlg)

public:
	TESTLIST_Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TESTLIST_Dlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_TestList };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_TestListForm;
	virtual BOOL OnInitDialog();
	void OnCustomdrawList(NMHDR *pNMHDR, LRESULT *pResult);
};
