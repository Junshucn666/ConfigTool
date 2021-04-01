#pragma once
#include "afxwin.h"
#include "MyTabBaseDlg.h"

// DCap_Dlg �Ի���

class DCap_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(DCap_Dlg)

public:
	DCap_Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DCap_Dlg();

// �Ի�������
	enum { IDD = IDD_DCap_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnBnClickedCheckEaup();
	CButton m_Check_EAUP;
	afx_msg void OnEnChangeEditUp();
	CEdit m_Edit_UP;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
};
