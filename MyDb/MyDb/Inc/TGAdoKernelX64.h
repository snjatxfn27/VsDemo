#ifndef __TGADOKERNELX64__H__
#define __TGADOKERNELX64__H__

#include "CUIIADOShell.h"

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

 class TGADOSRV_API CTGAdoKernel
{
public:

	CTGAdoKernel();
	~CTGAdoKernel();
	SHORT	InitADOServer(LPCTSTR bstrConnect);
	SHORT	IsDatabaseOpen(void);
	BSTR	GetDatabase(void);
	void	SetDatabase(LPCTSTR bstrDatabase);
	void	GetTableNameArray(CStringArray &arTabls, LPCTSTR pszTableType = _T("TABLE"));
	SHORT	IsSelEmpty(LPCTSTR pszStrSQL);
	SHORT	ExecuteSQL(LPCTSTR pszStrSQL);
	int		GetSelData(LPCTSTR pszStrSQL,CString& sValue);
	int		GetSelData(LPCTSTR pszStrSQL,CStringArray &arStrValue);
	int		GetSelData(LPCTSTR pszStrSQL,CStringArray &arStrValue,int nFr, int nTo);
	int		GetSelData(LPCTSTR pszStrSQL,CStringList &listStrValue,BOOL bMakeLower= TRUE);
	int		GetSelData(LPCTSTR pszStrSQL,CStringList &listStrValue, int nFr, int nTo, BOOL bMakeLower= TRUE);
	int		GetSelData(LPCTSTR pszStrSQL,CUIIValueTable &valueTable,BOOL bUpdateLable = TRUE);
	int		GetSelData(LPCTSTR pszStrSQL,CUIIValueTable &valueTable, int nFr, int nTo, BOOL bUpdateLable = TRUE);
	int		GetSelData(LPCTSTR pszSKey_ValueSQL,CMapStringToString &mapKey_Value);
	short	GetTableStructInfoEx(LPCTSTR pszTableName, Ttable &tbl);
	short	GetSelDataEx(LPCTSTR pszStrSQL, CMapStringToString &mapStr);
	BOOL	CreateOLEDBTable(LPCTSTR pszTableName, Ttable& arFields, LPCTSTR pszDbName = NULL);
	BOOL	GetConnection(CString& sConntion);
	void	BeginTrans();
	void	RollbackTrans();
	void	CommitTrans();
	BOOL	PutPackageToDb(CString& sFile, const CString& sTableName, const CString& sPackageField,CUIIValueTable& table);
	BOOL	OutPackageToFile(CString& sFile, const CString& sSQL, const CString& sPackageField,BOOL bExport = TRUE);
	static	BOOL BrowseForFolder(HWND hWnd, CString& sFolder, LPCTSTR lpszTitle, UINT nFlags);

private:
	CString	GetXmlString(const CStringArray &arStrs, LPCTSTR pName = _T("CStringArray"));
	CString	GetXmlString(const CStringList &liStrs);
	CString	GetXmlString(CUIIValueTable &vaTbl);
	CString	GetXmlString(const CMapStringToString &mapStr);
	CString GetXmlString(Ttable &tblField);

	BOOL	ReadDataFromXml(CStringArray		&arStrs,	const BSTR &bstrXml);
	BOOL	ReadDataFromXml(CStringList			&liStrs,	const BSTR &bstrXml);
	BOOL	ReadDataFromXml(CUIIValueTable		&vaTbl,		const BSTR &bstrXml);
	BOOL	ReadDataFromXml(CMapStringToString	&mapStr,	const BSTR &bstrXml);
	BOOL	ReadDataFromXml(Ttable				&tbl,		const BSTR &bstrXml);
private:
	CUIIADOShell m_shell;
	CString m_sConnect;
};
#endif