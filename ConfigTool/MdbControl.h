#pragma once

#import ".\msado15(2007).dll" no_namespace rename("EOF","adoEOF")
// CMdbControl

class CMdbControl : public CWnd
{
	DECLARE_DYNAMIC(CMdbControl)

public:
	CMdbControl();
	virtual ~CMdbControl();



	/****************************************************************
	* ��������MDB���ݿ��ļ�
	* FilePath���ļ�·����
	* PASSWORD�����ݿ��ļ����룬�������븳������
	* ErrCode (ִ��ʧ�ܷ���ʧ����Ϣ��
	*****************************************************************/
	bool OpenDatabase(CString FilePath,CString PASSWORD,CString &ErrCode);

	/****************************************************************
	* ������ɾ��������������
	* TableName��������
	* ErrCode (ִ��ʧ�ܷ���ʧ����Ϣ��
	*****************************************************************/
	bool DeleteTable(CString TableName,CString &ErrCode);

	/****************************************************************
	* ������ɾ�������ض���-1������
	* TableName��������
	* FieldName��̧ͷ����
	* FieldValue���ض�����Ϣ��
	* ErrCode (ִ��ʧ�ܷ���ʧ����Ϣ��
	*****************************************************************/
	bool DeleteTableItem(CString TableName,CString FieldName,CString FieldValue,CString &ErrCode);

	/****************************************************************
	* ������ɾ�������ض���-2������
	* TableName��������
	* FieldName1��̧ͷ��1��
	* FieldValue1���ض�����Ϣ1��
	* FieldName2��̧ͷ��2��
	* FieldValue2���ض�����Ϣ2��
	* ErrCode (ִ��ʧ�ܷ���ʧ����Ϣ��
	*****************************************************************/
	bool DeleteTableItem(CString TableName,CString FieldName1,CString FieldValue1,CString FieldName2,CString FieldValue2,CString &ErrCode);

	/****************************************************************
	* ������ɾ�������ض���-3������
	* TableName��������
	* FieldName1��̧ͷ��1��
	* FieldValue1���ض�����Ϣ1��
	* FieldName2��̧ͷ��2��
	* FieldValue2���ض�����Ϣ2��
	* FieldName3��̧ͷ��3��
	* FieldValue3���ض�����Ϣ3��
	* ErrCode (ִ��ʧ�ܷ���ʧ����Ϣ��
	*****************************************************************/
	bool DeleteTableItem(CString TableName,CString FieldName1,CString FieldValue1,CString FieldName2,CString FieldValue2,CString FieldName3,CString FieldValue3,CString &ErrCode);


	/****************************************************************
	* �������½�һ�� - ���� AddDatebase������������ʱ���ȵ���AddLine����
	* TableName��������
	* ErrCode (ִ��ʧ�ܷ���ʧ����Ϣ��
	*****************************************************************/
	bool AddLine(CString TableName,CString &ErrCode);

	/****************************************************************
	* ������д������- ���������ظ�����
	* FieldName��̧ͷ����
	* FielValue��д��ֵ��
	* ErrCode (ִ��ʧ�ܷ���ʧ����Ϣ��
	*****************************************************************/
	bool AddDatebase(CString FieldName,CString FielValue,CString &ErrCode);

	/****************************************************************
	* ��������ȡ����-��ɸѡ����
	* TableName��������
	* FieldName��̧ͷ����
	* ReadBuffer����ȡ���ݱ��棩
	* ErrCode (ִ��ʧ�ܷ���ʧ����Ϣ��
	*****************************************************************/
	bool ReadDatebase(CString TableName,CString FieldName,CArray<CString,CString>&ReadBuffer,CString &ErrCode);

	/****************************************************************
	* ��������ȡ����-��ɸѡ����
	* TableName��������
	* FieldName��̧ͷ����
	* ConditionFieldName������̧ͷ����
	* SearchCondition��������
	* ReadBuffer����ȡ���ݱ��棩
	* ErrCode (ִ��ʧ�ܷ���ʧ����Ϣ��
	*****************************************************************/
	bool ReadDatebase(CString TableName,CString FieldName,CString ConditionFieldName,CString SearchCondition,CArray<CString,CString>&ReadBuffer,CString &ErrCode);

	/****************************************************************
	* �������ر�MDB���ݿ��ļ�
	* ErrCode (ִ��ʧ�ܷ���ʧ����Ϣ��
	*****************************************************************/
	bool CloseDatebase(CString &ErrCode);



protected:
	DECLARE_MESSAGE_MAP()
};


