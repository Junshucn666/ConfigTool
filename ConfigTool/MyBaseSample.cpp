// MyBaseSample.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "MyBaseSample.h"
#include "afxdialogex.h"


// MyBaseSample �Ի���

IMPLEMENT_DYNAMIC(MyBaseSample, CDialogEx)

MyBaseSample::MyBaseSample(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyBaseSample::IDD, pParent)
{

}

MyBaseSample::~MyBaseSample()
{
}

void MyBaseSample::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_GTCMD, m_Edit_GTCMD);
	DDX_Control(pDX, IDC_BUTTON_Read, m_Button_Read);
	DDX_Control(pDX, IDC_BUTTON_Send, m_Button_Send);
}


BEGIN_MESSAGE_MAP(MyBaseSample, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_GTCMD, &MyBaseSample::OnEnChangeEditGtcmd)
	ON_BN_CLICKED(IDC_BUTTON_Read, &MyBaseSample::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_Send, &MyBaseSample::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDOK, &MyBaseSample::OnBnClickedOk)
END_MESSAGE_MAP()


// MyBaseSample ��Ϣ�������

BOOL MyBaseSample::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetBackgroundColor(RGB(176,196,222));
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void MyBaseSample::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	//AfxMessageBox("Base");
	//CDialogEx::OnOK();
}

void MyBaseSample::OnEnChangeEditGtcmd()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void MyBaseSample::OnBnClickedButtonRead()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void MyBaseSample::OnBnClickedButtonSend()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void MyBaseSample::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
