#pragma once
#include "afxwin.h"


// EquipmentSet �Ի���

class EquipmentSet : public CDialogEx
{
	DECLARE_DYNAMIC(EquipmentSet)

public:
	EquipmentSet(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~EquipmentSet();

// �Ի�������
	enum { IDD = IDD_DIALOG_Para };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_PowerType;
	CComboBox m_PowerBoard;
	CComboBox m_PowerAddress;
	virtual BOOL OnInitDialog();
	bool GetConfigFromFile();
	bool PutConfigToPage();
	bool PutPageToConfig();
	bool SaveConfigToFile();
	afx_msg void OnBnClickedOk();
};
