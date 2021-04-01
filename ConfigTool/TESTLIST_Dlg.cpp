// TESTLIST_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "TESTLIST_Dlg.h"
#include "afxdialogex.h"


// TESTLIST_Dlg 对话框

IMPLEMENT_DYNAMIC(TESTLIST_Dlg, CDialogEx)

TESTLIST_Dlg::TESTLIST_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(TESTLIST_Dlg::IDD, pParent)
{

}

TESTLIST_Dlg::~TESTLIST_Dlg()
{
}

void TESTLIST_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_TestList, m_TestListForm);
}


BEGIN_MESSAGE_MAP(TESTLIST_Dlg, CDialogEx)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_TestList, OnCustomdrawList)
END_MESSAGE_MAP()


// TESTLIST_Dlg 消息处理程序


BOOL TESTLIST_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//SetBackgroundColor(RGB(176,196,222),1);
	// TODO:  在此添加额外的初始化

	m_TestListForm.SetExtendedStyle( LVS_EX_FLATSB | LVS_EX_FULLROWSELECT |LVS_EX_ONECLICKACTIVATE | LVS_EX_GRIDLINES|LVS_EX_TWOCLICKACTIVATE);   
	m_TestListForm.SetBkColor(RGB(255,250,205));
	//m_listcontrol.SetTextBkColor(RGB(255,250,205));
	//m_listcontrol.SetTextColor(RGB(0,0,255));
	m_TestListForm.InsertColumn(0,"NO",LVCFMT_CENTER,35,0);
	m_TestListForm.InsertColumn(1,"TESTITEM",LVCFMT_CENTER,100,0);
	m_TestListForm.InsertColumn(2,"VALUE",LVCFMT_CENTER,360,0);
	m_TestListForm.InsertColumn(3,"LoL",LVCFMT_CENTER,50,0);//70
	m_TestListForm.InsertColumn(4,"UpL",LVCFMT_CENTER,50,0);//70
	m_TestListForm.InsertColumn(5,"Result",LVCFMT_CENTER,65,0);
	CFont font;
	font.CreatePointFont(120,"宋体");
	m_TestListForm.SetFont(&font);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void TESTLIST_Dlg::OnCustomdrawList(NMHDR *pNMHDR, LRESULT *pResult)
{

	NMLVCUSTOMDRAW* pLVCD = reinterpret_cast<NMLVCUSTOMDRAW*>( pNMHDR );
	*pResult = CDRF_DODEFAULT;


	if ( CDDS_PREPAINT == pLVCD->nmcd.dwDrawStage )
	{
		*pResult = CDRF_NOTIFYITEMDRAW;
	}
	else if ( CDDS_ITEMPREPAINT == pLVCD->nmcd.dwDrawStage )
	{
		COLORREF crText,crBk;

		if (m_TestListForm.GetItemText(pLVCD->nmcd.dwItemSpec,5)=="PASS")
		{
			crText = RGB(0,238,0);
			crBk =RGB(255,250,205);
		}
		else
		{
			crText = RGB(255,0,0);
			crBk =RGB(255,250,205);
		}
		pLVCD->clrText = crText;
		pLVCD->clrTextBk = crBk;		
		*pResult = CDRF_NEWFONT;
	}
}