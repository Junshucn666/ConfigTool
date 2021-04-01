#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// ASrdc_Dlg 对话框

class ASrdc_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(ASrdc_Dlg)

public:
	ASrdc_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ASrdc_Dlg();

// 对话框数据
	enum { IDD = IDD_ASrdc_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonRead();
	afx_msg void OnBnClickedButtonSend();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	void GetCMD();
	void GetHValue();
	void GetR100Value();
	void GetC20Value();
	BOOL UpdataPage(CString sStr);
	afx_msg void OnCbnSelchangeComboM();
	afx_msg void OnBnClickedOk();
	CEdit m_Edit_GTRMD;
	afx_msg void OnEnChangeEditHs();
	CComboBox m_ComboBox_M;
	afx_msg void OnCbnSelchangeComboOi();
	afx_msg void OnBnClickedCheckOuts();
	afx_msg void OnDeltaposSpinD(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinTt(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditD();
	afx_msg void OnEnChangeEditTt();
	CComboBox m_ComboBox_OI;
	CButton m_Check_OutS;
	CSpinButtonCtrl m_Spin_D;
	CSpinButtonCtrl m_Spin_TT;
	CEdit m_Edit_D;
	CEdit m_Edit_TT;
	CEdit m_Edit_HS;
	CEdit m_Edit_HE;
	afx_msg void OnDeltaposSpinMs(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinMe(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_MS;
	CSpinButtonCtrl m_Spin_ME;
	afx_msg void OnEnChangeEditHe();
	afx_msg void OnEnChangeEditRe();
	afx_msg void OnEnChangeEditRs();
	afx_msg void OnDeltaposSpinRs(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinRe(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_RS;
	CSpinButtonCtrl m_Spin_RE;
	CEdit m_Edit_RS;
	CEdit m_Edit_RE;
	afx_msg void OnDeltaposSpinBs(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinBe(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_BS;
	CSpinButtonCtrl m_Spin_BE;
	CEdit m_Edit_BS;
	CEdit m_Edit_BE;
	afx_msg void OnEnChangeEditBs();
	afx_msg void OnEnChangeEditBe();
	afx_msg void OnEnChangeEditH1();
	afx_msg void OnEnChangeEditH2();
	afx_msg void OnEnChangeEditH3();
	afx_msg void OnEnChangeEditH4();
	afx_msg void OnEnChangeEditH5();
	afx_msg void OnEnChangeEditH6();
	afx_msg void OnEnChangeEditH7();
	afx_msg void OnEnChangeEditH8();
	afx_msg void OnEnChangeEditH9();
	afx_msg void OnEnChangeEditH10();
	afx_msg void OnEnChangeEditR1();
	afx_msg void OnEnChangeEditR2();
	afx_msg void OnEnChangeEditR3();
	afx_msg void OnEnChangeEditR4();
	afx_msg void OnEnChangeEditR5();
	afx_msg void OnEnChangeEditR6();
	afx_msg void OnEnChangeEditR7();
	afx_msg void OnEnChangeEditR8();
	afx_msg void OnEnChangeEditR9();
	afx_msg void OnEnChangeEditR10();
	afx_msg void OnEnChangeEditR11();
	afx_msg void OnEnChangeEditR12();
	afx_msg void OnEnChangeEditR13();
	afx_msg void OnEnChangeEditR14();
	afx_msg void OnEnChangeEditR15();
	afx_msg void OnEnChangeEditR16();
	afx_msg void OnEnChangeEditR17();
	afx_msg void OnEnChangeEditR18();
	afx_msg void OnEnChangeEditR19();
	afx_msg void OnEnChangeEditR20();
	afx_msg void OnEnChangeEditR21();
	afx_msg void OnEnChangeEditR22();
	afx_msg void OnEnChangeEditR23();
	afx_msg void OnEnChangeEditR24();
	afx_msg void OnEnChangeEditR25();
	afx_msg void OnEnChangeEditR26();
	afx_msg void OnEnChangeEditR27();
	afx_msg void OnEnChangeEditR28();
	afx_msg void OnEnChangeEditR29();
	afx_msg void OnEnChangeEditR30();
	afx_msg void OnEnChangeEditR31();
	afx_msg void OnEnChangeEditR32();
	afx_msg void OnEnChangeEditR33();
	afx_msg void OnEnChangeEditR34();
	afx_msg void OnEnChangeEditR35();
	afx_msg void OnEnChangeEditR36();
	afx_msg void OnEnChangeEditR37();
	afx_msg void OnEnChangeEditR38();
	afx_msg void OnEnChangeEditR39();
	afx_msg void OnEnChangeEditR40();
	afx_msg void OnEnChangeEditR41();
	afx_msg void OnEnChangeEditR42();
	afx_msg void OnEnChangeEditR43();
	afx_msg void OnEnChangeEditR44();
	afx_msg void OnEnChangeEditR45();
	afx_msg void OnEnChangeEditR46();
	afx_msg void OnEnChangeEditR47();
	afx_msg void OnEnChangeEditR48();
	afx_msg void OnEnChangeEditR49();
	afx_msg void OnEnChangeEditR50();
	afx_msg void OnEnChangeEditR51();
	afx_msg void OnEnChangeEditR52();
	afx_msg void OnEnChangeEditR53();
	afx_msg void OnEnChangeEditR54();
	afx_msg void OnEnChangeEditR55();
	afx_msg void OnEnChangeEditR56();
	afx_msg void OnEnChangeEditR57();
	afx_msg void OnEnChangeEditR58();
	afx_msg void OnEnChangeEditR59();
	afx_msg void OnEnChangeEditR60();
	afx_msg void OnEnChangeEditR61();
	afx_msg void OnEnChangeEditR62();
	afx_msg void OnEnChangeEditR63();
	afx_msg void OnEnChangeEditR64();
	afx_msg void OnEnChangeEditR65();
	afx_msg void OnEnChangeEditR66();
	afx_msg void OnEnChangeEditR67();
	afx_msg void OnEnChangeEditR68();
	afx_msg void OnEnChangeEditR69();
	afx_msg void OnEnChangeEditR70();
	afx_msg void OnEnChangeEditR71();
	afx_msg void OnEnChangeEditR72();
	afx_msg void OnEnChangeEditR73();
	afx_msg void OnEnChangeEditR74();
	afx_msg void OnEnChangeEditR75();
	afx_msg void OnEnChangeEditR76();
	afx_msg void OnEnChangeEditR77();
	afx_msg void OnEnChangeEditR78();
	afx_msg void OnEnChangeEditR79();
	afx_msg void OnEnChangeEditR80();
	afx_msg void OnEnChangeEditR81();
	afx_msg void OnEnChangeEditR82();
	afx_msg void OnEnChangeEditR83();
	afx_msg void OnEnChangeEditR84();
	afx_msg void OnEnChangeEditR85();
	afx_msg void OnEnChangeEditR86();
	afx_msg void OnEnChangeEditR87();
	afx_msg void OnEnChangeEditR88();
	afx_msg void OnEnChangeEditR89();
	afx_msg void OnEnChangeEditR90();
	afx_msg void OnEnChangeEditR91();
	afx_msg void OnEnChangeEditR92();
	afx_msg void OnEnChangeEditR93();
	afx_msg void OnEnChangeEditR94();
	afx_msg void OnEnChangeEditR95();
	afx_msg void OnEnChangeEditR96();
	afx_msg void OnEnChangeEditR97();
	afx_msg void OnEnChangeEditR98();
	afx_msg void OnEnChangeEditR99();
	afx_msg void OnEnChangeEditR100();
	afx_msg void OnEnChangeEditC1();
	afx_msg void OnEnChangeEditC3();
	afx_msg void OnEnChangeEditC5();
	afx_msg void OnEnChangeEditC7();
	afx_msg void OnEnChangeEditC9();
	afx_msg void OnEnChangeEditC11();
	afx_msg void OnEnChangeEditC13();
	afx_msg void OnEnChangeEditC15();
	afx_msg void OnEnChangeEditC17();
	afx_msg void OnEnChangeEditC19();
	afx_msg void OnEnChangeEditC2();
	afx_msg void OnEnChangeEditC4();
	afx_msg void OnEnChangeEditC6();
	afx_msg void OnEnChangeEditC8();
	afx_msg void OnEnChangeEditC10();
	afx_msg void OnEnChangeEditC12();
	afx_msg void OnEnChangeEditC14();
	afx_msg void OnEnChangeEditC16();
	afx_msg void OnEnChangeEditC18();
	afx_msg void OnEnChangeEditC20();
	void ReSize(UINT nType, int cx, int cy);
	void ChangeSize(UINT nID, int x, int y);
	CRect  m_rect_tab;   //用于保存原对话框大小
	CList<CRect,CRect&> m_listRect;
	afx_msg void OnEnChangeEditGtrmd();
};
