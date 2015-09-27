//--------------------------------------------------------------------------------
// = ��Ȩ
//       Copyright(c) 2000 
//		 All rights reserved
// = ����(S)
//       �����
// = �汾
//       Version1.0 
// = ����
//		 2002.7.20
// = �޸���־
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

	//�����ȡֵ
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

	CUIIValueRecord		m_LableRecord;		//����
	CUIIValueRecord		m_LableIIRecord;	//�ڶ�����
	CUIIValueRecord		m_LableIIIRecord;	//��������

	CUIIValueRecord		m_rcLineXRecord;	//�м�¼����չ����
	TTUIIValueRecord	m_arValueRecord;	//��¼
};

#ifndef __AFXTEMPL_H__
#include <afxtempl.h>
#endif

typedef CArray<CUIIValueTable,CUIIValueTable&> TTCUIIValueTable;
#endif
