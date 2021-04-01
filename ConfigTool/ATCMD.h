#pragma once
#include "ComPortEx.h"

class ATCMD
{
public:
	ATCMD(void);
	~ATCMD(void);
public:
	BOOL KeySendAtCommond(int comport,int baudrate,CString WriteData_String,CString &ReadData_String,CString &ReadKeyValue,DWORD TimeOut_s,CString &ERRCODE);
	BOOL ReadDataOnly(int comport,int baudrate,CString &ReadData_String,DWORD TimeOut_s,CString &ERRCODE);
	BOOL SendCommondOnly(int comport,int baudrate,CString WriteData_String,CString &ReadData_String,float TimeOut_s,CString &ERRCODE);
};

