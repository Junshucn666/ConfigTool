#pragma once
#include "afxwin.h"
#include "afxbutton.h"


// MyBaseSample �Ի���

class MyBaseSample : public CDialogEx
{
	DECLARE_DYNAMIC(MyBaseSample)

public:
	MyBaseSample(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyBaseSample();

// �Ի�������
	enum { IDD = IDD_DIALOG_MyBaseSample };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnEnChangeEditGtcmd();
	afx_msg void OnBnClickedButtonRead();
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnBnClickedOk();
	CEdit m_Edit_GTCMD;
	CMFCButton m_Button_Read;
	CMFCButton m_Button_Send;
};
