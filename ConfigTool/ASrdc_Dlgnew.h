#pragma once
#include "MyTabBaseDlg.h"
#include "afxcmn.h"
#include "afxbutton.h"
#include "afxwin.h"

// ASrdc_Dlgnew �Ի���

class ASrdc_Dlgnew : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(ASrdc_Dlgnew)

public:
	ASrdc_Dlgnew(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ASrdc_Dlgnew();

// �Ի�������
	enum { IDD = IDD_ASrdc_Dlgnew };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void ReSize(UINT nType, int cx, int cy);
	CTabCtrl m_Table_rdc;
	void HideAllWND();
	afx_msg void OnBnClickedMfcbuttonPage();
	CFont *m_pFont;//�����µ�����
	CMFCButton m_MFCBUTTON_Page;
	CComboBox m_ComboBox_M;
	CComboBox m_ComboBox_OI;
	CSpinButtonCtrl m_Spin_D;
	CSpinButtonCtrl m_Spin_TT;
	afx_msg void OnCbnSelchangeComboM();
	afx_msg void OnCbnSelchangeComboOi();
	void GetCMD();
	BOOL UpdataPage(CString sStr);
	CButton m_Check_OutS;
	CEdit m_Edit_D;
	CEdit m_Edit_TT;
	afx_msg void OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCheckOuts();
	afx_msg void OnEnChangeEditD();
	afx_msg void OnEnChangeEditTt();
	void GetHValue();
	void GetC20Value();
	void GetR100Value();
};
