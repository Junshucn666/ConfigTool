#pragma once

// CMyTabBaseDlg 对话框

class CMyTabBaseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMyTabBaseDlg)

public:
	CMyTabBaseDlg(UINT nIDTemplate,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyTabBaseDlg();

// 对话框数据
	//enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
    CFont FButton_startfont;//状态框字体，不能设全局重画会丢失
	CList<CRect,CRect&> m_listRect;
};
