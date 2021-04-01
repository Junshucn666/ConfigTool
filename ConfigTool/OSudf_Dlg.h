#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MyTabBaseDlg.h"


// OSudf_Dlg 对话框

class OSudf_Dlg : public CMyTabBaseDlg
{
	DECLARE_DYNAMIC(OSudf_Dlg)

public:
	OSudf_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~OSudf_Dlg();

// 对话框数据
	enum { IDD = IDD_OSudf_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString UpdataCMD(CString sChildstr,int iPos,CString sParestr);
	void GetCMD();
	void GetMask();
	BOOL UpdataPage(CString sStr);
	afx_msg void OnCbnSelchangeComboM();
	CComboBox m_ComboBox_M;
	afx_msg void OnCbnSelchangeComboGi();
	afx_msg void OnCbnSelchangeComboSa();
	CComboBox m_ComboBox_GI;
	CComboBox m_ComboBox_SA;
	afx_msg void OnBnClickedOk();
	afx_msg void OnDeltaposSpinDt(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_Spin_DT;
	CEdit m_Edit_DT;
	afx_msg void OnEnChangeEditDt();
	void GetInputIDMask();
	void SetInputIDMask(CString sStrH);
	void SetInzizoMask(CString sStrH);
	void SetOutzizoMask(CString sStrH);
	void SetStocmdIDMask(CString sStrH);
	void SetInpeoMask(CString sStrH);
	void SetOutpeoMask(CString sStrH);
	void GetInzizoMask();
	void GetOutzizoMask();
	void GetInpeoMask();
	void GetOutpeoMask();
	void GetStocmdIDMask();
	afx_msg void OnBnClickedCheckB0();
	afx_msg void OnBnClickedCheckB1();
	afx_msg void OnBnClickedCheckB2();
	afx_msg void OnBnClickedCheckB3();
	afx_msg void OnBnClickedCheckB4();
	afx_msg void OnBnClickedCheckB5();
	afx_msg void OnBnClickedCheckB6();
	afx_msg void OnBnClickedCheckB7();
	afx_msg void OnBnClickedCheckB8();
	afx_msg void OnBnClickedCheckB9();
	afx_msg void OnBnClickedCheckB10();
	afx_msg void OnBnClickedCheckB11();
	afx_msg void OnBnClickedCheckB12();
	afx_msg void OnBnClickedCheckB13();
	afx_msg void OnBnClickedCheckB14();
	afx_msg void OnBnClickedCheckB15();
	afx_msg void OnBnClickedCheckB16();
	afx_msg void OnBnClickedCheckB17();
	afx_msg void OnBnClickedCheckB18();
	afx_msg void OnBnClickedCheckB19();
	afx_msg void OnBnClickedCheckB20();
	afx_msg void OnBnClickedCheckB21();
	afx_msg void OnBnClickedCheckB22();
	afx_msg void OnBnClickedCheckB23();
	afx_msg void OnBnClickedCheckB24();
	afx_msg void OnBnClickedCheckB25();
	afx_msg void OnBnClickedCheckB26();
	afx_msg void OnBnClickedCheckB27();
	afx_msg void OnBnClickedCheckB28();
	afx_msg void OnBnClickedCheckB29();
	afx_msg void OnBnClickedCheckB30();
	afx_msg void OnBnClickedCheckB31();
	afx_msg void OnBnClickedCheckB32();
	afx_msg void OnBnClickedCheckB33();
	afx_msg void OnBnClickedCheckB34();
	afx_msg void OnBnClickedCheckB35();
	afx_msg void OnBnClickedCheckCa8();
	CButton m_Check_InputIDMaskCheckall;
	afx_msg void OnBnClickedCheckC0();
	afx_msg void OnBnClickedCheckC1();
	afx_msg void OnBnClickedCheckC2();
	afx_msg void OnBnClickedCheckC3();
	afx_msg void OnBnClickedCheckC4();
	afx_msg void OnBnClickedCheckC5();
	afx_msg void OnBnClickedCheckC6();
	afx_msg void OnBnClickedCheckC7();
	afx_msg void OnBnClickedCheckC8();
	afx_msg void OnBnClickedCheckC9();
	afx_msg void OnBnClickedCheckC10();
	afx_msg void OnBnClickedCheckC11();
	afx_msg void OnBnClickedCheckC12();
	afx_msg void OnBnClickedCheckC13();
	afx_msg void OnBnClickedCheckC14();
	afx_msg void OnBnClickedCheckC15();
	afx_msg void OnBnClickedCheckC16();
	afx_msg void OnBnClickedCheckC17();
	afx_msg void OnBnClickedCheckC18();
	afx_msg void OnBnClickedCheckC19();
	afx_msg void OnBnClickedCheckCca();
	CButton m_Check_InzizoMaskCheckall;
	afx_msg void OnBnClickedCheckDca();
	CButton m_Check_OutzizoMaskCheckall;
	CButton m_Check_ECheckall;
	CButton m_Check_FCheckall;
	CButton m_Check_GCheckall;
	afx_msg void OnBnClickedCheckEca();
	afx_msg void OnBnClickedCheckFca();
	afx_msg void OnBnClickedCheckGca();
	afx_msg void OnBnClickedCheckD0();
	afx_msg void OnBnClickedCheckD1();
	afx_msg void OnBnClickedCheckD2();
	afx_msg void OnBnClickedCheckD3();
	afx_msg void OnBnClickedCheckD4();
	afx_msg void OnBnClickedCheckD5();
	afx_msg void OnBnClickedCheckD6();
	afx_msg void OnBnClickedCheckD7();
	afx_msg void OnBnClickedCheckD8();
	afx_msg void OnBnClickedCheckD9();
	afx_msg void OnBnClickedCheckD10();
	afx_msg void OnBnClickedCheckD11();
	afx_msg void OnBnClickedCheckD12();
	afx_msg void OnBnClickedCheckD13();
	afx_msg void OnBnClickedCheckD14();
	afx_msg void OnBnClickedCheckD15();
	afx_msg void OnBnClickedCheckD16();
	afx_msg void OnBnClickedCheckD17();
	afx_msg void OnBnClickedCheckD18();
	afx_msg void OnBnClickedCheckD19();
	afx_msg void OnBnClickedCheckE0();
	afx_msg void OnBnClickedCheckE1();
	afx_msg void OnBnClickedCheckE2();
	afx_msg void OnBnClickedCheckE3();
	afx_msg void OnBnClickedCheckE4();
	afx_msg void OnBnClickedCheckE5();
	afx_msg void OnBnClickedCheckE6();
	afx_msg void OnBnClickedCheckE7();
	afx_msg void OnBnClickedCheckE8();
	afx_msg void OnBnClickedCheckE9();
	afx_msg void OnBnClickedCheckE10();
	afx_msg void OnBnClickedCheckE11();
	afx_msg void OnBnClickedCheckE12();
	afx_msg void OnBnClickedCheckE13();
	afx_msg void OnBnClickedCheckE14();
	afx_msg void OnBnClickedCheckE15();
	afx_msg void OnBnClickedCheckE16();
	afx_msg void OnBnClickedCheckE17();
	afx_msg void OnBnClickedCheckE18();
	afx_msg void OnBnClickedCheckE19();
	afx_msg void OnBnClickedCheckF0();
	afx_msg void OnBnClickedCheckF1();
	afx_msg void OnBnClickedCheckF2();
	afx_msg void OnBnClickedCheckF3();
	afx_msg void OnBnClickedCheckF4();
	afx_msg void OnBnClickedCheckF5();
	afx_msg void OnBnClickedCheckF6();
	afx_msg void OnBnClickedCheckF7();
	afx_msg void OnBnClickedCheckF8();
	afx_msg void OnBnClickedCheckF9();
	afx_msg void OnBnClickedCheckF10();
	afx_msg void OnBnClickedCheckF11();
	afx_msg void OnBnClickedCheckF12();
	afx_msg void OnBnClickedCheckF13();
	afx_msg void OnBnClickedCheckF14();
	afx_msg void OnBnClickedCheckF15();
	afx_msg void OnBnClickedCheckF16();
	afx_msg void OnBnClickedCheckF17();
	afx_msg void OnBnClickedCheckF18();
	afx_msg void OnBnClickedCheckF19();
	afx_msg void OnBnClickedCheckG0();
	afx_msg void OnBnClickedCheckG1();
	afx_msg void OnBnClickedCheckG2();
	afx_msg void OnBnClickedCheckG3();
	afx_msg void OnBnClickedCheckG4();
	afx_msg void OnBnClickedCheckG5();
	afx_msg void OnBnClickedCheckG6();
	afx_msg void OnBnClickedCheckG7();
	afx_msg void OnBnClickedCheckG8();
	afx_msg void OnBnClickedCheckG9();
	afx_msg void OnBnClickedCheckG10();
	afx_msg void OnBnClickedCheckG11();
	afx_msg void OnBnClickedCheckG12();
	afx_msg void OnBnClickedCheckG13();
	afx_msg void OnBnClickedCheckG14();
	afx_msg void OnBnClickedCheckG15();
	afx_msg void OnBnClickedCheckG16();
	afx_msg void OnBnClickedCheckG17();
	afx_msg void OnBnClickedCheckG18();
	afx_msg void OnBnClickedCheckG19();
	afx_msg void OnBnClickedCheckG20();
	afx_msg void OnBnClickedCheckG21();
	afx_msg void OnBnClickedCheckG22();
	afx_msg void OnBnClickedCheckG23();
	afx_msg void OnBnClickedCheckG24();
	afx_msg void OnBnClickedCheckG25();
	afx_msg void OnBnClickedCheckG26();
	afx_msg void OnBnClickedCheckG27();
	afx_msg void OnBnClickedCheckG28();
	afx_msg void OnBnClickedCheckG29();
	afx_msg void OnBnClickedCheckG30();
	afx_msg void OnBnClickedCheckG31();
};
