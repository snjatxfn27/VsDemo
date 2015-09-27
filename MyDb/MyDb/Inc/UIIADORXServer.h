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

//字段名定义描述
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
	CString m_sFieldType;   //类型: 字符型  : varchar  文本  : text    字节  : varbinary
							//		ole型   : image    长整型: int     实数型: float
							//		double型: real     短整型: smallint
							//		时间    : datetime
	long	m_nSize;		//长度
	BOOL	m_bIsAllowNull; //不允许空
	BOOL	m_bPrimaryKey;  //主键
};

typedef CArray<CUIITableField,CUIITableField &> Ttable;

class TGADOSRV_API CUIIADORXServer  
{

public:
			 CUIIADORXServer();
	virtual ~CUIIADORXServer();

			//建立连接、连接数据库，打开数据库[access本地]
			//示例 
			//mdb : sDbFileName="DRIVER={Microsoft Access Driver (*.mdb)};"
			//"DBQ=c:\\mydata.mdb;UID=sa;PWD=";

			//xls : Driver={Microsoft Excel Driver (*.xls)};"
			//"DBQ=c:\\mydata.xls;ReadOnly=false;"
	virtual BOOL	InitADOServer(LPCTSTR pszDbFileName);

			//建立连接、连接数据库，打开数据库
			//示例:
			//_bstr_t strCnn("Provider=sqloledb;Data Source=MyServer;"
			//"Initial Catalog=pubs;User Id=sa;Password=;");
			// ConnectOptionEnum OptionEnum = adConnectUnspecified
	virtual BOOL	InitADOServer(LPCTSTR pszConnection,bool bDisplayException, int OptionEnum = -1);

			//建立连接、连接数据库，打开数据库
			//示例:
			//_bstr_t strCnn("DSN=CAPP;UID=sa;PWD="
			// ConnectModeEnum eMode = adModeUnknown,CursorTypeEnum eCursor = adOpenUnspecified
	virtual BOOL	InitADOServer(LPCTSTR pszDSN,LPCTSTR pszUserID,LPCTSTR pszPassword, int eMode = 0, int eCursor = -1);

	virtual BOOL	GetConnection(CString& sConntion);

	virtual void	SetDatabase(LPCTSTR pszDatabase);

	virtual LPCTSTR GetDatabase();

	virtual void	AppendAssocDatabase(LPCTSTR pszKey,LPCTSTR pszAssocDb);

	virtual BOOL	AssocDatabase(LPCTSTR pszKey,CString& sAssocDb);

			//设置登录者的ID
	virtual void	SetLoginID(LPCTSTR pszLoginName);

			//获取登录者的ID
	virtual LPCTSTR GetLoginID();

			//设置登录的组ID
	virtual void	SetGroupID(LPCTSTR pszGroup);
			
			//获取登录的组ID
	virtual LPCTSTR GetGroupID();

	virtual BOOL	CreateOLEDBTable(LPCTSTR pszTableName,Ttable& arFields,LPCTSTR pszsDbName = NULL);

			//创建表及表的字段名
	virtual BOOL	CreateSQLSrvTable(LPCTSTR pszTableName,Ttable& arFields,LPCTSTR pszDbName = NULL);

	virtual BOOL	IsSQLSrvTableExist(LPCTSTR pszTableName,LPCTSTR pszDbName);

			//获取表的结构信息
	virtual BOOL	GetSQLSrvTableStru(LPCTSTR pszTableName,Ttable &arFields,LPCTSTR pszDbName = NULL);

			//获取表的结构信息
	virtual BOOL	GetSQLSrvTableStru(LPCTSTR pszTableName,CStringList &listField,LPCTSTR pszDbName = NULL);

			//获取表的结构信息
	virtual BOOL	GetTableStructInfoEx(LPCTSTR pszTableName,Ttable& arFields);

			//删除数据库中的表
	virtual BOOL	DeleteTable(LPCTSTR pszTableName);
	
			//删除数据库中的若干表
	virtual BOOL	DeleteTable(CStringArray& arTableNames);

			//删除表中若干字段名
	virtual BOOL	DeleteTableFields(LPCTSTR pszTableName,CStringArray& arFields,LPCTSTR pszDbName);

			//删除表中字段
	virtual BOOL	DeleteTableFields(LPCTSTR pszTableName,LPCTSTR pszFields,LPCTSTR pszDbName);

			//向表中增加若干字段名
	virtual BOOL	AppendTableFields(LPCTSTR pszTableName,Ttable &arFields,LPCTSTR pszDbName);

			//向表中增加字段
	virtual BOOL	AppendTableFields(LPCTSTR pszTableName, CUIITableField& arFields,LPCTSTR pszDbName);

			//获得一个数值
	virtual int		GetSelData(LPCTSTR pszStrSQL,CString& sValue);

			//把获得相应的信息填到数组中
	virtual int		GetSelData(LPCTSTR pszStrSQL,CStringArray &arStrValue);
	virtual int     GetSelData(LPCTSTR pszStrSQL,CStringArray &arStrValue,int nFr, int nTo);

			//是否是空选择集
	virtual BOOL	IsSelEmpty(LPCTSTR pszStrSQL);
			
			//把获得相应的信息填到链表中
	virtual int		GetSelData(LPCTSTR pszStrSQL,CStringList &listStrValue,BOOL bMakeLower= TRUE);
	virtual int		GetSelData(LPCTSTR pszStrSQL,CStringList &listStrValue, int nFr, int nTo, BOOL bMakeLower= TRUE);

			//选取多个字段，把获得相应的信息填到'表'对象中
	virtual int		GetSelData(LPCTSTR pszStrSQL,CUIIValueTable &valueTable,BOOL bUpdateLable = TRUE);
	virtual int		GetSelData(LPCTSTR pszStrSQL,CUIIValueTable &valueTable, int nFr, int nTo, BOOL bUpdateLable = TRUE);

			//选取一个作为Key,和一个作为Value的SQL,取的记录添到map中
	virtual int		GetSelData(LPCTSTR pszSKey_ValueSQL,CMapStringToString &mapKey_Value);

			//选取一行,获得Field到对应数据的映射
	virtual int		GetSelDataEx(LPCTSTR pszSelectSQL,CMapStringToString &mapFieldToValue);

			//把获得相应的信息填到vResults中
	virtual int		GetSelData(LPCTSTR pszStrSQL,_variant_t &vResults,long &lAdoRow,long &lAdoCol);

			//获得数据库中所有的表名
	virtual void	GetSQLSrvTableNames(CStringList& listTables,LPCTSTR pszDbName);

			//获得数据库中所有的表名
	virtual void	GetSQLSrvTableNames(CStringArray& arTables,LPCTSTR pszDbName);

			//获得数据库中所有的表名
	virtual void	GetTableNameArray(CStringArray& arTables,LPCTSTR pszTableType = _T("TABLE"));

			//获得数据库中所有的表名
	virtual void	GetOLDBTableNameList(CStringList &listTables,LPCTSTR pszTableType = _T("TABLE"));

			//获得数据库中所有的表名
	virtual void	GetOLDBTableNameArray(CStringArray &arTables,LPCTSTR pszTableType = _T("TABLE"));

			//执行SQL语句[如 删除，追加，更新]
	virtual BOOL	ExecuteSQL(LPCTSTR pszStrSQL);

			//判断数据库是否成功打开
	virtual BOOL	IsDatabaseOpen();

			//取得连接数据库指针
			// _ConnectionPtr pConnect(pDistch);
	virtual IDispatch* GetConnectionPtr();

	virtual void BeginTrans();

	virtual void RollbackTrans();

	virtual void CommitTrans();

private:
	
	LPVOID	m_pImp;
};

#endif //AFX_UIIADORXSERVER_H__0D757B27_D77D_4FF7_B950_1FAC5E23F668__INCLUDED_
