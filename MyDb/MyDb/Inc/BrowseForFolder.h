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
#if !defined(AFX_BROWSEFORFOLDER_H__295A882F_12C3_4792_A633_EEC86C37EFDE__INCLUDED_)
#define AFX_BROWSEFORFOLDER_H__295A882F_12C3_4792_A633_EEC86C37EFDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif

class TGADOSRV_API CBrowseForFolder  
{
public:
			 CBrowseForFolder();
	virtual ~CBrowseForFolder();

	static BOOL BrowseForFolder(HWND hWnd,CString& sFolder,LPCTSTR lpszTitle,UINT nFlags);
};

#endif
