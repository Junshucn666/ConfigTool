#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"

// ASsa_Dlg �Ի���

class ASsa_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(ASsa_Dlg)

public:
	ASsa_Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ASsa_Dlg();

// �Ի�������
	enum { IDD = IDD_ASsa_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	BOOL UpdataPage(CString sStr);
	void GetCMD();
	afx_msg void OnCbnSelchangeComboM();
	CComboBox m_ComboBox_M;
	afx_msg void OnDeltaposSpinMs(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_MS;
	CEdit m_Edit_MS;
	afx_msg void OnEnChangeEditMs();
	afx_msg void OnDeltaposSpinV(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_V;
	CEdit m_Edit_V;
	afx_msg void OnDeltaposSpinMaxs(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_MaxS;
	CEdit m_Edit_MaxS;
	afx_msg void OnEnChangeEditMaxs();
	afx_msg void OnEnChangeEditV();
	afx_msg void OnDeltaposSpinSi(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_SI;
	CEdit m_Edit_SI;
	afx_msg void OnEnChangeEditSi();
	afx_msg void OnCbnSelchangeComboOi();
	CComboBox m_ComboBox_OI;
	afx_msg void OnBnClickedCheckOuts();
	CButton m_Check_OS;
	afx_msg void OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_D;
	CEdit m_Edit_D;
	afx_msg void OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_TT;
	CEdit m_Edit_TT;
	afx_msg void OnEnChangeEditD();
	afx_msg void OnEnChangeEditTt();
};
