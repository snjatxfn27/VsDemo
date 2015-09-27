// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard
#ifndef __UIIADOSHELL__H__
#define __UIIADOSHELL__H__

//#import "../inc/ado/UIIADOShell.tlb" no_namespace
// CUIIADOShell wrapper class

class CUIIADOShell : public COleDispatchDriver
{
public:
	CUIIADOShell(){} // Calls COleDispatchDriver default constructor
	CUIIADOShell(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CUIIADOShell(const CUIIADOShell& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IUIIADOShell methods
public:
	short InitADOServer(LPCTSTR bstrConnect)
	{
		short result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_I2, (void*)&result, parms, bstrConnect);
		return result;
	}
	short IsDatabaseOpen(LPCTSTR sMdb)
	{
		short result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_I2, (void*)&result, parms, sMdb);
		return result;
	}
	CString GetDatabase(LPCTSTR sMdb)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, sMdb);
		return result;
	}
	void SetDatabase(LPCTSTR sMdb, LPCTSTR bstrDatabase)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, sMdb, bstrDatabase);
	}
	void GetTableNameArray(LPCTSTR sMdb, BSTR * pszarTables, LPCTSTR pszTableType)
	{
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_BSTR ;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, sMdb, pszarTables, pszTableType);
	}
	short IsSelEmpty(LPCTSTR sMdb, LPCTSTR pszStrSQL)
	{
		short result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_I2, (void*)&result, parms, sMdb, pszStrSQL);
		return result;
	}
	short ExecuteSQL(LPCTSTR sMdb, LPCTSTR pszStrSQL)
	{
		short result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_I2, (void*)&result, parms, sMdb, pszStrSQL);
		return result;
	}
	short GetSelData(LPCTSTR sMdb, LPCTSTR pszStrSQL, BSTR * bstrXmlRes, short nMethordId, short bUpdateLable)
	{
		short result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PBSTR VTS_I2 VTS_I2 ;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_I2, (void*)&result, parms, sMdb, pszStrSQL, bstrXmlRes, nMethordId, bUpdateLable);
		return result;
	}
	void Close(LPCTSTR sMdb)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, sMdb);
	}
	short GetTableStructInfoEx(LPCTSTR sMdb, LPCTSTR pszTableName, BSTR *bstrXmlRes )
	{
		short result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PBSTR;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_I2, (void*)&result, parms, sMdb, pszTableName, bstrXmlRes);
		return result;
	}
	short GetSelDataEx(LPCTSTR sMdb, LPCTSTR pszStrSQL, BSTR *bstrXmlRes )
	{
		short result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PBSTR;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_I2, (void*)&result, parms, sMdb, pszStrSQL, bstrXmlRes);
		return result;
	}
	short CreateOLEDBTable(LPCTSTR sMdb, LPCTSTR pszTableName, LPCTSTR pszFields, LPCTSTR pszDbName)
	{
		short result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_I2, (void*)&result, parms, sMdb, pszTableName, pszFields, pszDbName);
		return result;
	}

	short GetConnection(LPCTSTR sMdb, BSTR* sConntion)
	{
		short result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_I2, (void*)&result, parms, sMdb, sConntion);
		return result;
	}
	void BeginTrans(LPCTSTR sMdb)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms, sMdb);
	}
	void RollbackTrans(LPCTSTR sMdb)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, sMdb);
	}
	void CommitTrans(LPCTSTR sMdb)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_EMPTY, NULL, parms, sMdb);
	}
	short PutPackageToDb(LPCTSTR sMdb, BSTR* sFile, LPCTSTR sTableName, LPCTSTR sPackageField, BSTR* table)
	{
		short result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_BSTR VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_I2, (void*)&result, parms, sMdb, sFile, sTableName, sPackageField, table/**/);
		return result;
	}
	short OutPackageToFile(LPCTSTR sMdb, BSTR* sFile, LPCTSTR sSQL, LPCTSTR sPackageField, short bExport)
	{
		short result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_BSTR VTS_BSTR VTS_I2;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_I2, (void*)&result, parms, sMdb, sFile, sSQL, sPackageField, bExport);
		return result;
	}

	// IUIIADOShell properties
public:

};

#endif