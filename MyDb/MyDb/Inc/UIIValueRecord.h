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

#ifndef __UIIVALUERECORD_H__
#define __UIIVALUERECORD_H__

class TGADOSRV_API CUIIValueRecord : public CObject 
{
	DECLARE_SERIAL(CUIIValueRecord);

public:
			CUIIValueRecord();
			CUIIValueRecord(const CUIIValueRecord& valueRecord);
	virtual ~CUIIValueRecord();

public:

	void	SetLableValueAr(CStringArray &strArValue);
	void	GetLableValueAr(CStringArray &strArValue);

	BOOL	GetValue(int nIndex,CString& sText);

	int		GetLableLogicSize();

	CUIIValueRecord& operator =(const CUIIValueRecord &dataSrc);

	void	RemoveAll();

public:

	virtual void	Serialize( CArchive& ar );

private:

	CStringArray m_strArValue;
};

#ifndef __AFXTEMPL_H__
#include <afxtempl.h>
#endif

typedef CArray<CUIIValueRecord,CUIIValueRecord&> TTUIIValueRecord;
#endif
