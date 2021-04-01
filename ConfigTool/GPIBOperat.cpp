// GPIBOperat.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GPIBOperat.h"
#include "ni488.h"

extern CConfigToolDlg* lpCConfigToolDlg;

// GPIBOperat

IMPLEMENT_DYNAMIC(GPIBOperat, CWnd)

GPIBOperat::GPIBOperat()
{

}

GPIBOperat::~GPIBOperat()
{
}


BEGIN_MESSAGE_MAP(GPIBOperat, CWnd)
END_MESSAGE_MAP()



// GPIBOperat ��Ϣ�������



bool GPIBOperat::OpenDevices(int &hDevroot,int iBoard,int iAddress,CString &EquipmentName)
{
	hDevroot=ibdev(iBoard,iAddress,0,11,1,0);//�򿪲���ʼ���豸
	ibclr(hDevroot);//�˺�����ָ��������������,ʹ�������ܴ��ڳ�ʼ����״̬

	if (!GPIBWrite(hDevroot,"*IDN?"))
	{
		return false;
	}
	else
	{
		if(!GPIBRead(hDevroot,EquipmentName))
		{
			return false;
		}
	}

	return true;
}

bool GPIBOperat::CloseDevices(int hDevroot)
{
	ibonl(hDevroot,0);//�ýӿڰ����߻�����
	hDevroot=0;
	return true;
}

bool GPIBOperat::GPIBWrite(int hDevroot,CString sWriteBuffer)
{
	CString DebugString="";
	char PutBuffer[200];
	memset(PutBuffer,NULL,sizeof(PutBuffer));
	memcpy(PutBuffer,sWriteBuffer,sWriteBuffer.GetLength());

	DebugString.Format("DEBUG: GPIB_WRITE %d : %s",hDevroot,sWriteBuffer);
	OutputDebugString(DebugString);
	DebugString.Format("GPIB: GPIB_WRITE %d : %s",hDevroot,sWriteBuffer);
	lpCConfigToolDlg->OutPutDebugLog(DebugString);

	ibwrt(hDevroot,PutBuffer,strlen(PutBuffer));
	if (ibsta&ERR)
	{
		return false;
	}
	return true;
}

bool GPIBOperat::GPIBRead(int hDevroot,CString &GetBuffer)
{
	CString DebugString="";
	char getchar[300];
	memset(getchar,NULL,sizeof(getchar));
	ibrd(hDevroot,getchar,sizeof(getchar));
	if (ibsta&ERR)
	{
		return false;
	}
	GetBuffer=getchar;
	DebugString.Format("DEBUG: GPIB_READ %d : %s",hDevroot,GetBuffer);
	OutputDebugString(DebugString);
	DebugString.Format("GPIB: GPIB_READ %d : %s",hDevroot,GetBuffer);
	lpCConfigToolDlg->OutPutDebugLog(DebugString);
	return true;
}



