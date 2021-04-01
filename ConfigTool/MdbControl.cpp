// MdbControl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MdbControl.h"
#include "afxcmn.h"
#include "afxwin.h"


_ConnectionPtr m_pConnection;
_RecordsetPtr m_pRecordset;

// CMdbControl

IMPLEMENT_DYNAMIC(CMdbControl, CWnd)

CMdbControl::CMdbControl()
{

}

CMdbControl::~CMdbControl()
{
}


BEGIN_MESSAGE_MAP(CMdbControl, CWnd)
END_MESSAGE_MAP()



// CMdbControl ��Ϣ�������


bool CMdbControl::OpenDatabase(CString FilePath,CString PASSWORD,CString &ErrCode)
{

	// ��ʼ��COM,����ADO���ӵȲ���
	
	try                 
	{ 
		// �򿪱���Access��
		HRESULT hr = 0;
		CoInitialize(NULL); 
		hr = m_pConnection.CreateInstance("ADODB.Connection");///���� Connection ����
		if(SUCCEEDED(hr))
		{
			CString str;
			if (PASSWORD!="")
			{
				str.Format("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;Persist Security Info=False;Jet OLEDB:Database Password=%s",FilePath,PASSWORD);
			}
			else
			{
				str.Format("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;Persist Security Info=False",FilePath);
			}
			


			m_pConnection->Open(str.GetBuffer(str.GetLength()),TEXT(""),TEXT(""),adModeUnknown);
			str.ReleaseBuffer(str.GetLength());
		}
		else
		{
			ErrCode="���� Connection ����ʧ��!";
			return FALSE;
		}
	}
	catch(_com_error e)
	{
		ErrCode="���ݿ�����ʧ�ܣ���ȷ��·��!";
		return FALSE;
	}

	try
	{
		if (m_pRecordset==NULL)
		{
			m_pRecordset.CreateInstance("ADODB.Recordset");
		}		
	}
	catch(...)
	{
		ErrCode="����CreateInstance����ʧ��";
		return FALSE;
	}
	return true;
}

bool CMdbControl::DeleteTable(CString TableName,CString &ErrCode)
{

	try
	{	
		CString Table;
		Table.Format(TEXT("DELETE * FROM %s"),TableName);
		OutputDebugString(TEXT("DEBUG: ") + Table);
		m_pRecordset->Open(Table.GetBuffer(Table.GetLength()),                // ɾ�����������ֶ�
			m_pConnection.GetInterfacePtr(),  // ��ȡ��ӿ��IDispatchָ��
			adOpenDynamic,
			adLockOptimistic,
			adCmdText);
		Table.ReleaseBuffer(Table.GetLength());
		return true;
	}
	catch(...)
	{
		ErrCode.Format(TEXT("ɾ����%s����δ֪�Ĵ���"),TableName);
		return false;
	}

}

bool CMdbControl::DeleteTableItem(CString TableName,CString FieldName,CString FieldValue,CString &ErrCode)

{
	CString Table="";
	try
	{	
		Table.Format(TEXT("DELETE * FROM  %s  WHERE  %s='%s'"),TableName,FieldName,FieldValue);
		m_pRecordset->Open(Table.GetBuffer(Table.GetLength()),                // ɾ�����������ֶ�
			m_pConnection.GetInterfacePtr(),  // ��ȡ��ӿ��IDispatchָ��
			adOpenDynamic,
			adLockOptimistic,
			adCmdText);
		Table.ReleaseBuffer(Table.GetLength());
		m_pRecordset->Close();
		return true;
	}
	catch(...)
	{
		ErrCode.Format("ִ�� %s����δ֪�Ĵ���",Table);
		return false;
	}
}

bool CMdbControl::DeleteTableItem(CString TableName,CString FieldName1,CString FieldValue1,CString FieldName2,CString FieldValue2,CString &ErrCode)

{
	CString Table="";
	try
	{	
		Table.Format(TEXT("DELETE * FROM %s  WHERE  %s='%s'  AND %s='%s'"),TableName,FieldName1,FieldValue1,FieldName2,FieldValue2);
		m_pRecordset->Open(Table.GetBuffer(Table.GetLength()),                // ɾ�����������ֶ�
			m_pConnection.GetInterfacePtr(),  // ��ȡ��ӿ��IDispatchָ��
			adOpenDynamic,
			adLockOptimistic,
			adCmdText);
		Table.ReleaseBuffer(Table.GetLength());
		//m_pRecordset->Close();
		return true;
	}
	catch(...)
	{
		ErrCode.Format("ִ�� %s����δ֪�Ĵ���",Table);
		return false;
	}
}

bool CMdbControl::DeleteTableItem(CString TableName,CString FieldName1,CString FieldValue1,CString FieldName2,CString FieldValue2,CString FieldName3,CString FieldValue3,CString &ErrCode)

{
	CString Table="";
	try
	{	
		Table.Format(TEXT("DELETE * FROM  %s  WHERE %s='%s' AND %s='%s'  AND %s='%s'"),TableName,FieldName1,FieldValue1,FieldName2,FieldValue2,FieldName3,FieldValue3);
		m_pRecordset->Open(Table.GetBuffer(Table.GetLength()),                // ɾ�����������ֶ�
			m_pConnection.GetInterfacePtr(),  // ��ȡ��ӿ��IDispatchָ��
			adOpenDynamic,
			adLockOptimistic,
			adCmdText);
		Table.ReleaseBuffer(Table.GetLength());
		m_pRecordset->Close();
		return true;
	}
	catch(...)
	{
		ErrCode.Format("ִ�� %s����δ֪�Ĵ���",Table);
		return false;
	}
}

bool CMdbControl::AddLine(CString TableName,CString &ErrCode)
{
	/////�򿪱�//////////

	try
	{	
		CString Table;
		Table.Format("SELECT * FROM %s",TableName);
		m_pRecordset->Open(Table.GetBuffer(Table.GetLength()),                // ��ѯDemoTable���������ֶ�
			m_pConnection.GetInterfacePtr(),  // ��ȡ��ӿ��IDispatchָ��
			adOpenDynamic,
			adLockOptimistic,
			adCmdText);
		Table.ReleaseBuffer(Table.GetLength());
	}
	catch(...)
	{
		ErrCode.Format("��ѯ��%s����δ֪�Ĵ���",TableName);
		return false;
	}
	////////////////

	try
	{
		if (m_pRecordset!=NULL)
		{
			m_pRecordset->AddNew();
			m_pRecordset->Update();
			return true;
		}
		else
		{
			ErrCode="����г���δ֪����";
			return false;
		}
	}
	catch(...)
	{
		ErrCode="����г���δ֪����";
		return false;
	}
}

bool CMdbControl::AddDatebase(CString FieldName,CString FielValue,CString &ErrCode)
{
	try
	{

		m_pRecordset->PutCollect(FieldName.GetBuffer(FieldName.GetLength()),FielValue.GetBuffer(FielValue.GetLength()));
		m_pRecordset->Update();

		FieldName.ReleaseBuffer(FieldName.GetLength());
		FielValue.ReleaseBuffer(FielValue.GetLength());
		return true;
	}

	catch(...)
	{
		ErrCode="�����ֶγ���δ֪�Ĵ���,������ȷ���ֶ��Ƿ����";
		return false;
	}
}

bool CMdbControl::ReadDatebase(CString TableName,CString FieldName,CArray<CString,CString>&ReadBuffer,CString &ErrCode)
{
	CString Table="";
	try
	{		
		Table.Format("SELECT * FROM  %s",TableName);
		m_pRecordset->Open(Table.GetBuffer(Table.GetLength()),// ��ѯDemoTable���������ֶ�
							m_pConnection.GetInterfacePtr(),  // ��ȡ��ӿ��IDispatchָ��
							adOpenDynamic,
							adLockOptimistic,
							adCmdText);

		Table.ReleaseBuffer(Table.GetLength());
	}
	catch(...)
	{
		ErrCode.Format("ִ��%s����δ֪�Ĵ���",Table);
		return false;
	}
	////////////////////////////////////////////

	_variant_t var;
	try
	{
		if(!m_pRecordset->BOF)
			m_pRecordset->MoveFirst();
		else
		{
			CString str;
			ErrCode.Format("%s��������Ϊ�գ�",TableName);
			m_pRecordset->Close();
			return true;	
			//return false;
		}

		while(!m_pRecordset->adoEOF)
		{
			var = m_pRecordset->GetCollect(FieldName.GetBuffer(FieldName.GetLength()));
			FieldName.ReleaseBuffer(FieldName.GetLength());
			if(var.vt != VT_NULL)
			{
				ReadBuffer.Add((CString)var);
			}
			
			m_pRecordset->MoveNext();
		}
		m_pRecordset->Close();
		return true;	
	}

	catch(...)
	{
		ErrCode.Format("��ȡ�ֶ�%s����δ֪�Ĵ���",FieldName);
		return false;
	}
}

bool CMdbControl::ReadDatebase(CString TableName,CString FieldName,CString ConditionFieldName,CString SearchCondition,CArray<CString,CString>&ReadBuffer,CString &ErrCode)
{
	CString Table="";

	try
	{		
		Table.Format("SELECT * FROM %s WHERE %s='%s'",TableName,ConditionFieldName,SearchCondition);
		m_pRecordset->Open(Table.GetBuffer(Table.GetLength()),                // ��ѯDemoTable���������ֶ�
			m_pConnection.GetInterfacePtr(),  // ��ȡ��ӿ��IDispatchָ��
			adOpenDynamic,
			adLockOptimistic,
			adCmdText);

		Table.ReleaseBuffer(Table.GetLength());
	}
	catch(...)
	{
		ErrCode.Format("ִ��%s����δ֪�Ĵ���",Table);
		return false;
	}
	////////////////////////////////////////////

	_variant_t var;
	try
	{
		if(!m_pRecordset->BOF)
			m_pRecordset->MoveFirst();
		else
		{
			CString str;
			ErrCode.Format("%s��������Ϊ�գ�",TableName);
			m_pRecordset->Close();
			return true;	
		}

		while(!m_pRecordset->adoEOF)
		{
			var = m_pRecordset->GetCollect(FieldName.GetBuffer(FieldName.GetLength()));
			FieldName.ReleaseBuffer(FieldName.GetLength());
			if(var.vt != VT_NULL)
			{
				ReadBuffer.Add((CString)var);
			}

			m_pRecordset->MoveNext();
		}
		m_pRecordset->Close();
		return true;	
	}

	catch(...)
	{
		ErrCode.Format("��ȡ�ֶ�%s����δ֪�Ĵ���",FieldName);
		return false;
	}
}

bool CMdbControl::CloseDatebase(CString &ErrCode)
{

	try
	{
		if(m_pConnection==NULL)
		{
			return true;
		}

		if(m_pConnection->State)
		{
			if(m_pRecordset->State)
			{
				m_pRecordset->Close();
			}

			m_pConnection->Close();
		}

		if(m_pRecordset!=NULL)
		{
			m_pRecordset.Release();
			m_pRecordset=NULL;
		}

		m_pConnection.Release();
		m_pConnection=NULL;
	}

	catch(_com_error e)
	{
		ErrCode="�Ͽ����ݿ�����ʧ��";
		return FALSE;
	}
	return true;
}



