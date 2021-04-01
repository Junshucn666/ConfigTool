#pragma once
#include "afxwin.h"


// EquipmentSet 对话框

class EquipmentSet : public CDialogEx
{
	DECLARE_DYNAMIC(EquipmentSet)

public:
	EquipmentSet(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~EquipmentSet();

// 对话框数据
	enum { IDD = IDD_DIALOG_Para };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
