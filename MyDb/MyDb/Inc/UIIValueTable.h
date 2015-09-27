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

#ifndef __UIIVALUETABLE_H__
#define __UIIVALUETABLE_H__

#ifndef  __UIIVALUERECORD_H__
#include "UIIValueRecord.h"
#endif

class TGADOSRV_API CUIIValueTable : public CObject  
{

	DECLARE_SERIAL(CUIIValueTable);

public:

	CUIIValueTable();
	CUIIValueTable(const CUIIValueTable& valueTable);
	virtual ~CUIIValueTable();

public:

	void SetLableRecord(CUIIValueRecord &lableRecord);
	void SetLableRecord(CStringArray & arLable);

	void GetLableRecord(CUIIValueRecord &lableRecord);
	void GetLableRecord(CStringArray & arLable);

	void SetLableIIRecord(CUIIValueRecord &lableRecord);
	void SetLableIIRecord(CStringArray & arLable);

	void GetLableIIRecord(CUIIValueRecord &lableRecord);
	void GetLableIIRecord(CStringArray & arLable);

	void SetLableIIIRecord(CUIIValueRecord &lableRecord);
	void SetLableIIIRecord(CStringArray & arLable);

	void GetLableIIIRecord(CUIIValueRecord &lableRecord);
	void GetLableIIIRecord(CStringArray & arLable);

	void SetValueRecord(int nIndex,CUIIValueRecord &valueRecord);
	void SetValueRecord(int nIndex,CStringArray& arValue);

	void SetLineXRecord(CStringArray& arXData);
	void SetLineXRecord(CUIIValueRecord &valueRecord);

	void GetLineXRecord(CStringArray& arXData);

	void InsertValueRecord(int nIndex,CUIIValueRecord &valueRecord);
	void InsertValueRecord(int nIndex,CStringArray& arValue);

	void GetValueRecord(int nIndex,CUIIValueRecord &valueRecord);
	void GetValueRecord(int nIndex,CStringArray & arValue);

	void SetValueRecord(CString sFirstCode,CUIIValueRecord &valueRecord);
	void GetValueRecord(CString sFirstCode,CUIIValueRecord &valueRecord);
	
	void AddValueRecord(CUIIValueRecord &valueRecord);
	void AddValueRecord(CStringArray &arValue);

	void RemoveRecordByLable(CString sValue,int nIndex = 0);
	void RemoveRecordByIndex(int nIndex);

	void RenameRecordTextVlue(int nIndexText,CString sTextValue,CString sAcordText);
	void RenameRecordTextVlue(int nIndexText,CString sTextValue);

	//逆矩正取值
	void GetReverseValueRecord(int nIndex,CStringArray& arValues);

	BOOL HasThisRecordByName(CString sFirstValue);

	int  GetTableLogicSize();
	int  GetFieldCount();

	CUIIValueTable& operator =(const CUIIValueTable &valueTable);

	void ShowToListCtrl(CListCtrl * pListCtrl,int nImage = -1);

	void RemoveAll(BOOL bRemoveLable = FALSE);

public:

	virtual void Serialize( CArchive& ar );

private:

	CUIIValueRecord		m_LableRecord;		//标题
	CUIIValueRecord		m_LableIIRecord;	//第二标题
	CUIIValueRecord		m_LableIIIRecord;	//第三标题

	CUIIValueRecord		m_rcLineXRecord;	//行记录的扩展数据
	TTUIIValueRecord	m_arValueRecord;	//记录
};

#ifndef __AFXTEMPL_H__
#include <afxtempl.h>
#endif

typedef CArray<CUIIValueTable,CUIIValueTable&> TTCUIIValueTable;
#endif
