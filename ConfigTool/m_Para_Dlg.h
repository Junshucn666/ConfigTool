#pragma once


// m_Para_Dlg �Ի���

class m_Para_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(m_Para_Dlg)

public:
	m_Para_Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~m_Para_Dlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_Para };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
