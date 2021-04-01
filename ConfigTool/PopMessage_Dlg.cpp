// PopMessage_Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "PopMessage_Dlg.h"
#include "afxdialogex.h"
#include "ConfigToolDlg.h"

extern CConfigToolDlg* lpCConfigToolDlg;
CImage g_KeyImage;
CRect g_KeyRect;  //�ؼ����ζ���

IMPLEMENT_DYNAMIC(PopMessage_Dlg, CDialogEx)

PopMessage_Dlg::PopMessage_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(PopMessage_Dlg::IDD, pParent)
{
	cfont_showmsg.CreatePointFont(130,"Verdana");
}

PopMessage_Dlg::~PopMessage_Dlg()
{
}

void PopMessage_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_Msg, m_static_showmsg);
	DDX_Control(pDX, IDC_STATIC_Key, m_CStatic_Key);
}


BEGIN_MESSAGE_MAP(PopMessage_Dlg, CDialogEx)
	ON_WM_CTLCOLOR()
//	ON_WM_PAINT()
ON_WM_PAINT()
END_MESSAGE_MAP()


// PopMessage_Dlg ��Ϣ�������
BOOL PopMessage_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_static_showmsg.SetWindowText(this->sShowText);
	m_static_showmsg.SetFont(&cfont_showmsg);
	SetBackgroundColor(RGB(176,196,222),1);
	CheckPicture();	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void PopMessage_Dlg::ExitShow()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(IDOK);    //�رմ��� 
	CDialog::OnClose(); 
}


BOOL PopMessage_Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���

	return CDialogEx::PreTranslateMessage(pMsg);
}


HBRUSH PopMessage_Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if(pWnd->GetDlgCtrlID()==IDC_STATIC_Msg)
	{
		pDC->SetTextColor(RGB(0,0,205));//����������ɫ��
		pDC->SetBkMode(TRANSPARENT);//���ñ���ģʽ����������Ϊ͸��
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}

void PopMessage_Dlg::CheckPicture()
{	
	CString strPath="",MainPath="",SubPath="";	
	CRect rectPicture;   //ͼƬ���ζ���
	strPath=lpCConfigToolDlg->GetExeFilePath();
	MainPath=strPath+"main.jpg";
	//����ͼƬ
	if (PathFileExists(MainPath))
	{	
		g_KeyImage.Load(MainPath);//װ��·����ͼƬ��Ϣ��ͼƬ�� 
		KeyPicShow();
	}
}

void PopMessage_Dlg::KeyPicShow()
{
	//��ÿؼ����������,�����ʾ�ؼ���DC 
	m_CStatic_Key.GetClientRect(&g_KeyRect);   
	CDC* pKeyDC = m_CStatic_Key.GetWindowDC();  
	//�����ɫʧ��
	::SetStretchBltMode(*pKeyDC, HALFTONE);//HALFTONE����Ҫɾ�������ظ���Χ���к�����,(�൱��PS���Ǹ�ģ������)
	::SetBrushOrgEx(*pKeyDC, 0, 0, NULL);
	g_KeyImage.StretchBlt(*pKeyDC, 20, 132, 140, 198, SRCCOPY);//������Ч��֪��ԭ��
	//��ͼ
	g_KeyImage.Draw( pKeyDC ->m_hDC,g_KeyRect);  
	g_KeyImage.Destroy();
}



void PopMessage_Dlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CDialogEx::OnPaint();
	CDialog::UpdateWindow(); //����windows����  
	CheckPicture();     //�ػ�ͼƬ����   
}
