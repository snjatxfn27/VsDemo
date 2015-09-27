#if !defined(AFX_UIIADORXSERVER_H__0D757B27_D77D_4FF7_B950_1FAC5E23F668__INCLUDED_)
#define AFX_UIIADORXSERVER_H__0D757B27_D77D_4FF7_B950_1FAC5E23F668__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef  __UIIVALUETABLE_H__
#include "UIIValueTable.h"
#endif

#ifndef __AFXTEMPL_H__
#include <afxtempl.h>
#endif

#include <comdef.h>

//�ֶ�����������
class TGADOSRV_API CUIITableField
{
public:

	CUIITableField()
	{
		m_sFieldName = "";
		m_sFieldType = "";
		m_nSize = 0;
		m_bIsAllowNull = TRUE;
		m_bPrimaryKey = FALSE;
	}
	CUIITableField(const CUIITableField& dataSrc)
	{
		m_sFieldName = dataSrc.m_sFieldName;
		m_sFieldType = dataSrc.m_sFieldType;
		m_nSize = dataSrc.m_nSize;
		m_bIsAllowNull = dataSrc.m_bIsAllowNull;
		m_bPrimaryKey = dataSrc.m_bPrimaryKey;
	}

	virtual ~CUIITableField(){}

	CUIITableField& operator = (const CUIITableField &dataSrc)
	{
		m_sFieldName = dataSrc.m_sFieldName;
		m_sFieldType = dataSrc.m_sFieldType;
		m_nSize = dataSrc.m_nSize;
		m_bIsAllowNull = dataSrc.m_bIsAllowNull;
		m_bPrimaryKey = dataSrc.m_bPrimaryKey;
		return *this;
	}

public:

	CString m_sFieldName;
	CString m_sFieldType;   //����: �ַ���  : varchar  �ı�  : text    �ֽ�  : varbinary
							//		ole��   : image    ������: int     ʵ����: float
							//		double��: real     ������: smallint
							//		ʱ��    : datetime
	long	m_nSize;		//����
	BOOL	m_bIsAllowNull; //�������
	BOOL	m_bPrimaryKey;  //����
};

typedef CArray<CUIITableField,CUIITableField &> Ttable;

class TGADOSRV_API CUIIADORXServer  
{

public:
			 CUIIADORXServer();
	virtual ~CUIIADORXServer();

			//�������ӡ��������ݿ⣬�����ݿ�[access����]
			//ʾ�� 
			//mdb : sDbFileName="DRIVER={Microsoft Access Driver (*.mdb)};"
			//"DBQ=c:\\mydata.mdb;UID=sa;PWD=";

			//xls : Driver={Microsoft Excel Driver (*.xls)};"
			//"DBQ=c:\\mydata.xls;ReadOnly=false;"
	virtual BOOL	InitADOServer(LPCTSTR pszDbFileName);

			//�������ӡ��������ݿ⣬�����ݿ�
			//ʾ��:
			//_bstr_t strCnn("Provider=sqloledb;Data Source=MyServer;"
			//"Initial Catalog=pubs;User Id=sa;Password=;");
			// ConnectOptionEnum OptionEnum = adConnectUnspecified
	virtual BOOL	InitADOServer(LPCTSTR pszConnection,bool bDisplayException, int OptionEnum = -1);

			//�������ӡ��������ݿ⣬�����ݿ�
			//ʾ��:
			//_bstr_t strCnn("DSN=CAPP;UID=sa;PWD="
			// ConnectModeEnum eMode = adModeUnknown,CursorTypeEnum eCursor = adOpenUnspecified
	virtual BOOL	InitADOServer(LPCTSTR pszDSN,LPCTSTR pszUserID,LPCTSTR pszPassword, int eMode = 0, int eCursor = -1);

	virtual BOOL	GetConnection(CString& sConntion);

	virtual void	SetDatabase(LPCTSTR pszDatabase);

	virtual LPCTSTR GetDatabase();

	virtual void	AppendAssocDatabase(LPCTSTR pszKey,LPCTSTR pszAssocDb);

	virtual BOOL	AssocDatabase(LPCTSTR pszKey,CString& sAssocDb);

			//���õ�¼�ߵ�ID
	virtual void	SetLoginID(LPCTSTR pszLoginName);

			//��ȡ��¼�ߵ�ID
	virtual LPCTSTR GetLoginID();

			//���õ�¼����ID
	virtual void	SetGroupID(LPCTSTR pszGroup);
			
			//��ȡ��¼����ID
	virtual LPCTSTR GetGroupID();

	virtual BOOL	CreateOLEDBTable(LPCTSTR pszTableName,Ttable& arFields,LPCTSTR pszsDbName = NULL);

			//����������ֶ���
	virtual BOOL	CreateSQLSrvTable(LPCTSTR pszTableName,Ttable& arFields,LPCTSTR pszDbName = NULL);

	virtual BOOL	IsSQLSrvTableExist(LPCTSTR pszTableName,LPCTSTR pszDbName);

			//��ȡ��Ľṹ��Ϣ
	virtual BOOL	GetSQLSrvTableStru(LPCTSTR pszTableName,Ttable &arFields,LPCTSTR pszDbName = NULL);

			//��ȡ��Ľṹ��Ϣ
	virtual BOOL	GetSQLSrvTableStru(LPCTSTR pszTableName,CStringList &listField,LPCTSTR pszDbName = NULL);

			//��ȡ��Ľṹ��Ϣ
	virtual BOOL	GetTableStructInfoEx(LPCTSTR pszTableName,Ttable& arFields);

			//ɾ�����ݿ��еı�
	virtual BOOL	DeleteTable(LPCTSTR pszTableName);
	
			//ɾ�����ݿ��е����ɱ�
	virtual BOOL	DeleteTable(CStringArray& arTableNames);

			//ɾ�����������ֶ���
	virtual BOOL	DeleteTableFields(LPCTSTR pszTableName,CStringArray& arFields,LPCTSTR pszDbName);

			//ɾ�������ֶ�
	virtual BOOL	DeleteTableFields(LPCTSTR pszTableName,LPCTSTR pszFields,LPCTSTR pszDbName);

			//��������������ֶ���
	virtual BOOL	AppendTableFields(LPCTSTR pszTableName,Ttable &arFields,LPCTSTR pszDbName);

			//����������ֶ�
	virtual BOOL	AppendTableFields(LPCTSTR pszTableName, CUIITableField& arFields,LPCTSTR pszDbName);

			//���һ����ֵ
	virtual int		GetSelData(LPCTSTR pszStrSQL,CString& sValue);

			//�ѻ����Ӧ����Ϣ�������
	virtual int		GetSelData(LPCTSTR pszStrSQL,CStringArray &arStrValue);
	virtual int     GetSelData(LPCTSTR pszStrSQL,CStringArray &arStrValue,int nFr, int nTo);

			//�Ƿ��ǿ�ѡ��
	virtual BOOL	IsSelEmpty(LPCTSTR pszStrSQL);
			
			//�ѻ����Ӧ����Ϣ�������
	virtual int		GetSelData(LPCTSTR pszStrSQL,CStringList &listStrValue,BOOL bMakeLower= TRUE);
	virtual int		GetSelData(LPCTSTR pszStrSQL,CStringList &listStrValue, int nFr, int nTo, BOOL bMakeLower= TRUE);

			//ѡȡ����ֶΣ��ѻ����Ӧ����Ϣ�'��'������
	virtual int		GetSelData(LPCTSTR pszStrSQL,CUIIValueTable &valueTable,BOOL bUpdateLable = TRUE);
	virtual int		GetSelData(LPCTSTR pszStrSQL,CUIIValueTable &valueTable, int nFr, int nTo, BOOL bUpdateLable = TRUE);

			//ѡȡһ����ΪKey,��һ����ΪValue��SQL,ȡ�ļ�¼��map��
	virtual int		GetSelData(LPCTSTR pszSKey_ValueSQL,CMapStringToString &mapKey_Value);

			//ѡȡһ��,���Field����Ӧ���ݵ�ӳ��
	virtual int		GetSelDataEx(LPCTSTR pszSelectSQL,CMapStringToString &mapFieldToValue);

			//�ѻ����Ӧ����Ϣ�vResults��
	virtual int		GetSelData(LPCTSTR pszStrSQL,_variant_t &vResults,long &lAdoRow,long &lAdoCol);

			//������ݿ������еı���
	virtual void	GetSQLSrvTableNames(CStringList& listTables,LPCTSTR pszDbName);

			//������ݿ������еı���
	virtual void	GetSQLSrvTableNames(CStringArray& arTables,LPCTSTR pszDbName);

			//������ݿ������еı���
	virtual void	GetTableNameArray(CStringArray& arTables,LPCTSTR pszTableType = _T("TABLE"));

			//������ݿ������еı���
	virtual void	GetOLDBTableNameList(CStringList &listTables,LPCTSTR pszTableType = _T("TABLE"));

			//������ݿ������еı���
	virtual void	GetOLDBTableNameArray(CStringArray &arTables,LPCTSTR pszTableType = _T("TABLE"));

			//ִ��SQL���[�� ɾ����׷�ӣ�����]
	virtual BOOL	ExecuteSQL(LPCTSTR pszStrSQL);

			//�ж����ݿ��Ƿ�ɹ���
	virtual BOOL	IsDatabaseOpen();

			//ȡ���������ݿ�ָ��
			// _ConnectionPtr pConnect(pDistch);
	virtual IDispatch* GetConnectionPtr();

	virtual void BeginTrans();

	virtual void RollbackTrans();

	virtual void CommitTrans();

private:
	
	LPVOID	m_pImp;
};

#endif //AFX_UIIADORXSERVER_H__0D757B27_D77D_4FF7_B950_1FAC5E23F668__INCLUDED_
