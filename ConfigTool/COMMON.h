#pragma once
#include "MyTabBaseDlg.h"

#define RETURN_IF_FALSE(a)   \
	do {                     \
	bool _result = (a);  \
	if (_result != true) \
	return false;    \
	} while (0)

enum
{
	READY=1,
	RUN=2,
	PASS=3,
	FAIL=4
};


enum
{
	SUCCESS,
	WRITE_FAIL,
	CHECK_FAIL,
	TEST_FAIL
};

enum
{
	Agilent,
	KEITHLEY,
};

typedef enum
{
	PCBA_MMI=0,
	ASSY_MMI=1,
	PACK_CHECK=2,
	QA_ASSY_MMI=3,
	PACK_WRITE=4,
}STATION;

enum
{
	GTBSI	,
	GTSRI	,
	GTQSS	,
	GTCFG	,
	GTPIN	,
	GTDOG	,
	GTOWH	,
	GTTMA	,
	GTPDS	,
	GTHRM	,
	GTPCS	,
	GTFRI	,
	GTFFC	,
	GTGEO	,
	GTTOW	,
	GTSPD	,
	GTSOS	,
	GTIDL	,
	GTHBM	,
	GTSSR	,
	GTBZA	,
	GTSPA	,
	GTPEO	,
	GTRMD	,
	GTSDS	,
	GTSTP	,
	GTCRA	,
	GTOUT	,
	GTEPS	,
	GTDIS	,
	GTIOB	,
	GTVMS	,
	GTVVS	,
	GTAVS	,
	GTRTO	,
	GTHMC	,
	GTWLT	,
	GTGLM	,
	GTUPC	,
	GTCMD	,
	GTUDF	,
	GTASC	,
	GTEMR	,
};

enum
{
	ReadFromDevice,
	SendFromDevice,
	SaveFromPage,
	ReadFromFile,
};

typedef struct
{
	int iPowerType;
	int iPowerBoard;
	int iPowerAddress;

	int iPhonePort;
	int iBaudRate;
	int iTestSelection;

	CString TotalNumber;
	CString PASSNumber;
	CString FailNumber;
	CString sExeFilePath;
	CString sConfigPath;
	CString sLogPath;
	CString sFIXTUREIDPR;
	CString sDatabasePath;
	CString sDefaultExcelPath;
	CString sCFGExcelPath;
}CONFIG;

typedef struct
{
	CString sDefaultHex;
	CString sRAWHex;
	CString sFulllHex;
	CString sAlertHex;

}REPORTDATA;

typedef struct
{
	CString ATCommond;
	CString TargetReturnValue;
	CString ATQuery;
	CString TimeOut;
	CString Default;
	CString RAW;
	CString Fulll;
	CString Alert;
	CString Name;
	BOOL	ENABLE;
	int TestIndex;
}TestList;

typedef struct
{
	TestList	m_TestList[200];
	CString     sCFGVersion;
	int			TestItemNum;
	int			TestIndex;
	int			MultipleTestNum;
	bool		GetTestListSuccess;
	bool		StopFlag;
	bool		RunState;
}EXCELTestItem;



struct REPINF
{
	CString sName;
	CString sDefaultB;
	CString sDefaultH;
};

typedef struct 
{
	int iPortNumber;
	CString sPortName;
}PortInfo_scsn;

typedef struct 
{
	PortInfo_scsn portinfo_scan[20];
}ScanPort;

typedef struct
{

	CString sVMaxBatt;
	CString sVMinBatt;
	CString sPowOnTime;
	bool bcurrent;
	bool bwritesn;
	bool breadsn;
	bool bcreg;
	bool bcgreg;

	bool bGetTestItemSuccess;
	int		TestIndex;

}AllTestItem;

typedef struct
{
	int iIndex;
	CString sName;
	CString sCmdstr;
	CString sReturn;
	CMyTabBaseDlg*	lpMyTabBaseDlg;

}ThreadData;

typedef struct
{
	ThreadData	tdWriteCmds[50];
	ThreadData	tdReadCmds[50];
}ConfigCMD;

typedef struct PopupWindowParam
{
	CString lpszText;
	UINT nType;
	UINT nIDHelp;
	PopupWindowParam()
	{
		lpszText="³õÊ¼µ¯¿ò";
		nType=MB_OK;
		nIDHelp=0;
	}

}*pPopupWindowParam;