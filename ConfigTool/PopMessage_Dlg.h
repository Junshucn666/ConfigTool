#pragma once
#include "afxwin.h"


// PopMessage_Dlg �Ի���

class PopMessage_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(PopMessage_Dlg)

public:
	PopMessage_Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PopMessage_Dlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_MSG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
public:
	CFont cfont_showmsg;
	//HBRUSH hbr_showmsg;
	CString sShowText;
	void ExitShow();
	virtual BOOL OnInitDialog();
	void CheckPicture();
	void KeyPicShow();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CStatic m_static_showmsg;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CStatic m_CStatic_Key;
	afx_msg void OnPaint();
};
