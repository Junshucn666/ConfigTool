#pragma once


// m_Para_Dlg 对话框

class m_Para_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(m_Para_Dlg)

public:
	m_Para_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~m_Para_Dlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_Para };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
