#include "StdAfx.h"
#include "ATCMD.h"
#include "ConfigToolDlg.h"

extern CConfigToolDlg*	lpCConfigToolDlg;

ComPortEx m_ComPortEx;

ATCMD::ATCMD(void)
{
}


ATCMD::~ATCMD(void)
{
}

BOOL ATCMD::KeySendAtCommond(int comport,int baudrate,CString WriteData_String,CString &ReadData_String,CString &ReadKeyValue,DWORD TimeOut_s,CString &ERRCODE)
{
	CString DebugString=TEXT("");
	BYTE strBuffer[MAX_PATH]={0};
	DWORD iWriteMaxLength=0;
	BYTE strSendBuffer[2048]={0};

	////////////////////////////////////////////////////////////////////////////
	int ncount = 0;
	//while (1)
	//{
		if(!m_ComPortEx.CommInit(comport,baudrate))
		{
			ERRCODE.Format("PHONE_AT: OPEN_COMPORT_FAIL  %d",comport);
			return FALSE;
		}

		Sleep(50);
		m_ComPortEx.Clear();

		iWriteMaxLength=WriteData_String.GetLength();
		memcpy(strSendBuffer,WriteData_String,iWriteMaxLength);

		if(!m_ComPortEx.ComWriteString( strSendBuffer,iWriteMaxLength ))
		{
			ERRCODE.Format("PHONE_AT: COMPOR WRITE FAIL  %d",comport);
			m_ComPortEx.CommClose();
			return FALSE;
		}

		DebugString.Format("WRITE %d:%s",comport,WriteData_String);
		lpCConfigToolDlg->OutPutDebugLog(DebugString);

		Sleep(50);
		m_ComPortEx.Clear();
		memset(strSendBuffer,NULL,2048);
		strSendBuffer[0]=0x0D;
		strSendBuffer[1]=0x0A;
		if(!m_ComPortEx.ComWriteString( strSendBuffer,2 ))
		{
			ERRCODE.Format("PHONE_AT: COMPOR WRITE FAIL  %d",comport);
			m_ComPortEx.CommClose();
			return FALSE;
		}
		Sleep(500);

	while (1)
	{
		//读
		BYTE strReadBuffer[2048];
		BYTE strgetBuffer[2048];
		DWORD piReadLength = 0;

		memset(strgetBuffer, '\0', sizeof(strgetBuffer));
		memset(strReadBuffer,'\0', sizeof(strReadBuffer));

		if(!m_ComPortEx.ComReadString(strgetBuffer, 2047,&piReadLength,TimeOut_s))
		{
			ERRCODE.Format("PHONE_AT: COMPOR READ FAIL  %d",comport);
			m_ComPortEx.CommClose();
			return FALSE;
		}
		ReadData_String=strgetBuffer;
		DebugString.Format("READ %d:%s",comport,ReadData_String);
		lpCConfigToolDlg->OutPutDebugLog(DebugString);
		if (ReadData_String.Find(ReadKeyValue)!=-1)
		{
			DebugString.Format("KeyValue \"%s\", Is Matched : %s",ReadKeyValue,ReadData_String);
			lpCConfigToolDlg->OutPutDebugLog(DebugString);
			break;
		}
		else
		{		
			RETURN_IF_FALSE(ReadData_String.Find("ERROR")==-1);
			Sleep(1000);
		}
		if(ncount==3)
		{
			ERRCODE.Format("Can Not Catch The Valid Value");
			m_ComPortEx.CommClose();
			return FALSE;
		}
		ncount++;
	}
	m_ComPortEx.CommClose();
	return TRUE;
}

BOOL ATCMD::ReadDataOnly(int comport,int baudrate,CString &ReadData_String,DWORD TimeOut_s,CString &ERRCODE)
{
	CString DebugString=TEXT("");
	BYTE strBuffer[MAX_PATH]={0};
	DWORD iWriteMaxLength=0;
	BYTE strSendBuffer[MAX_PATH]={0};

	////////////////////////////////////////////////////////////////////////////
	if(!m_ComPortEx.CommInit(comport,baudrate))
	{
		ERRCODE.Format("PHONE_AT: OPEN_COMPORT_FAIL  %d",comport);
		return FALSE;
	}
	Sleep(50);
	m_ComPortEx.Clear();
	//////////////////////////////////////////////////////////////////////////
	//读
	BYTE strReadBuffer[1024];
	BYTE strgetBuffer[1024];
	DWORD piReadLength = 0;

	memset(strgetBuffer, '\0', sizeof(strgetBuffer));
	memset(strReadBuffer,'\0', sizeof(strReadBuffer));

	if(!m_ComPortEx.ComReadString(strgetBuffer, 1023,&piReadLength,TimeOut_s))//TimeOut_s控制读取的时间
	{
		ERRCODE.Format("PHONE_AT: COMPOR READ FAIL  %d",comport);
		m_ComPortEx.CommClose();
		return FALSE;
	}
	ReadData_String=strgetBuffer;

	//	关闭：

	m_ComPortEx.CommClose();

	return TRUE;
}

BOOL ATCMD::SendCommondOnly(int comport,int baudrate,CString WriteData_String,CString &ReadData_String,float TimeOut_s,CString &ERRCODE)
{
	CString DebugString=TEXT("");
	BYTE strBuffer[MAX_PATH]={0};
	DWORD iWriteMaxLength=0;
	BYTE strSendBuffer[MAX_PATH]={0};
	////////////////////////////////////////////////////////////////////////////
	if(!m_ComPortEx.CommInit(comport,baudrate))
	{
		ERRCODE.Format("PHONE_AT: OPEN_COMPORT_FAIL  %d",comport);
		return FALSE;
	}
	Sleep(50);
	m_ComPortEx.Clear();
	iWriteMaxLength=WriteData_String.GetLength();
	memcpy(strSendBuffer,WriteData_String,iWriteMaxLength);
	DebugString.Format("PHONE_AT: COMPORT_WRITE  %d : %s",comport,WriteData_String);
	lpCConfigToolDlg->OutPutDebugLog(DebugString);
	if(!m_ComPortEx.ComWriteString( strSendBuffer,iWriteMaxLength ))
	{
		ERRCODE.Format("PHONE_AT: COMPOR WRITE FAIL  %d",comport);
		m_ComPortEx.CommClose();
		return FALSE;
	}
	Sleep(50);
	m_ComPortEx.Clear();
	memset(strSendBuffer,NULL,260);
	strSendBuffer[0]=0x0D;
	strSendBuffer[1]=0x0A;
	if(!m_ComPortEx.ComWriteString( strSendBuffer,2 ))
	{
		ERRCODE.Format("PHONE_AT: COMPOR WRITE FAIL  %d",comport);
		m_ComPortEx.CommClose();
		return FALSE;
	}
	//	关闭：
	m_ComPortEx.CommClose();
	return TRUE;
}