#pragma once

// CMyTabBaseDlg �Ի���

class CMyTabBaseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMyTabBaseDlg)

public:
	CMyTabBaseDlg(UINT nIDTemplate,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyTabBaseDlg();

// �Ի�������
	//enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_iWhoamI;
	CMyTabBaseDlg*	m_lpMyTabBaseDlg;
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual afx_msg void OnEnChangeEditGtcmd();
	virtual afx_msg void OnBnClickedButtonSend();
	virtual afx_msg void OnBnClickedButtonRead();
	virtual BOOL UpdataPage(CString sStr);
	virtual void ReSize(UINT nType, int cx, int cy);
	BOOL ReadResCheck(CString sRes);
	BOOL WriteResSave(CString sRes);
	void DoSendWork();
	CEdit m_Edit_GTCMD;
	CMFCButton m_Button_Read;
	CMFCButton m_Button_Send;
    CFont FButton_startfont;//״̬�����壬������ȫ���ػ��ᶪʧ
	CList<CRect,CRect&> m_listRect;
};
