//--------------------------------------------------------------------------------
// = 版权
//       Copyright(c) 2000 
//		 All rights reserved
// = 作者(S)
//       李夫银
// = 版本
//       Version1.0 
// = 日期
//		 2002.7.20
// = 修改日志
//		
//--------------------------------------------------------------------------------
#ifndef _UIIPACKAGEDBOPER_H__
#define _UIIPACKAGEDBOPER_H__

#ifndef _WIN64
#include "UIIValueTable.h"
#else
#include "TGAdoKernelX64.h"
#endif
#include "comdef.h"

class CUIIADORXServer;
class CTGAdoKernel;
class TGADOSRV_API CUIIPackageDbOper 
{
public:
			 CUIIPackageDbOper();
	virtual ~CUIIPackageDbOper();

public:

	void SetDbSrv(CUIIADORXServer * pDbSrv){m_pDbsrv = pDbSrv;}

	BOOL PutPackageToDb(CString& sFile, const CString& sTableName, const CString& sPackageField,CUIIValueTable& table);

	BOOL OutPackageToFile(CString& sFile, const CString& sSQL, const CString& sPackageField,BOOL bExport = TRUE);
	
protected:

	BOOL GetConvertValue(_variant_t& variant,CString& sValue,CString& sType);

	BOOL MakeVariantFromFile(VARIANT& vtArray,CString& sFile);

	BOOL MakeFileFromVariant(CString& sFile,VARIANT& vtArray,long lDataSize);

protected:
	CUIIADORXServer *m_pDbsrv;
};

#endif
