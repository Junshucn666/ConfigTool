#pragma once
#include "afxwin.h"
#include "MyTabBaseDlg.h"


// IDSvims_Dlg �Ի���

class IDSvims_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(IDSvims_Dlg)

public:
	IDSvims_Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~IDSvims_Dlg();

// �Ի�������
	enum { IDD = IDD_IDSvims_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnCbnSelchangeComboVim();
	CComboBox m_ComboBox_VIM;
};
