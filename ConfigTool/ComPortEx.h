#pragma once

//typedef enum RetCodetag
//{
//	Result_OK=0,					//0		SUCCESS
//	Result_ERROR,					//1		һ�����
//	ERROR_FILENOTEXISTED,			//13	�ļ�������
//	ERROR_FILEOPENFAIL,				//14	���ļ�ʧ��
//	ERROR_FILETOOSMALL,				//15	�ļ����Ȳ���
//	ERROR_FILEREADFAIL,				//16	��ȡ�ļ�ʧ��
//	ERROR_OPENCOMFAIL,				//65	�򿪴���ʧ��
//	ERROR_GETCOMSTATEFAIL,			//66	��ȡ����״̬ʧ��
//	ERROR_SETCOMSTATEFAIL,			//67	���ô���״̬ʧ��
//	ERROR_SETCOMTIMEOUTFAIL,		//68	���ô��ڳ�ʱ״̬ʧ��
//	ERROR_SETCOMMASKFAIL,			//69	����COMMASKʧ��
//	ERROR_SETUPCOMFAIL,				//70	SetupComʧ��
//	ERROR_PURGECOMFAIL,				//71	PurgeComʧ��
//	ERROR_COMNOTOPEN,				//72	����δ��
//	ERROR_SERIALPURGE,				//73	PurgeComʧ��
//	ERROR_CLEARCOMERRORFAIL,		//74	ClearComErrorʧ��
//	ERROR_READCOMFAIL,				//75	��ȡ����ʧ��
//	ERROR_READNOCHAR,				//76	û�дӴ��ڶ���ֵ
//	ERROR_SERIALPORTWRITE,			//77	д����ʧ��
//	ERROR_SERIALWRITEDATA,			//78	δ���򴮿�д��ָ����������
//	ERROR_GETNUMFAIL,				//79	�Ӵ��ڽ��յ��������л�ȡ����ʧ��
//	ERROR_DIOEXCEPTION,				//80	DIO�����쳣
//	ERROR_DIOINITFAIL,				//81	DIO��ʼ��ʧ��
//	
//}RetCode;
// ComPortEx

class ComPortEx : public CWnd
{
	DECLARE_DYNAMIC(ComPortEx)

public:
	ComPortEx();
	virtual ~ComPortEx();
	bool	CommInit(int comport,int baudrate);
	void	CommClose();
	bool	ReadData(BYTE* pBuffer,DWORD iNumberBytesToRead,DWORD* iNumberBytesRead,float Timeout_s);
	bool	WriteData(BYTE* pBuffer,DWORD iNumberBytesToWrite,DWORD* iNumberBytesWritten);
	bool	ComReadString(BYTE *pReadBuffer, DWORD iReadMaxLength, DWORD* piReadLength, DWORD n_Timeout);
	bool	ComWriteString(BYTE *pWriteBuffer,DWORD iWriteMaxLength);

	void	SetReadEvent(HANDLE hEvent);
	void	SetStopEvent(HANDLE hEvent);

	bool	SetDTRStatus(UINT dtrstatus);
	bool	SetRTSStatus(UINT rtsstatus);
	bool	Clear();
	bool	ComWriteRead_HEX(int ComPort,int baudrate, CString WriteData_HEX,CString &ReadData_HEX,CString &ERRCODE);
	bool	ComWriteRead_String(int ComPort,int baudrate,CString WriteData_String,CString &ReadData_String,CString &ERRCODE);
	bool	ComRead_HEX(int ComPort,int baudrate,CString &ReadData_HEX,CString &ERRCODE);


protected:
	DECLARE_MESSAGE_MAP()
	HANDLE	m_hCommPort;
	BOOL	m_bSyncComm;//�Ƿ���ͬ������ͨ��

	OVERLAPPED  m_olWriteOverlapped;//�첽ͨ��ʹ��
	OVERLAPPED  m_olReadOverlapped;//�첽ͨ��ʹ��

	HANDLE	m_hReadEvent;//�첽ͨ��ʹ��
	HANDLE	m_hStopEvent;//�첽ͨ��ʹ��
};


