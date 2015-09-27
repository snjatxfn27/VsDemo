#pragma once
#include "Inc/TGAdo.h"
#include "afxwin.h"

// CAddBookTo �Ի���

class CAddBookTo : public CDialog
{
	DECLARE_DYNAMIC(CAddBookTo)

public:
	CAddBookTo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddBookTo();

// �Ի�������
	enum { IDD = IDD_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void CloseAdoServer(CUIIADORXServer*& pAdo);
	CUIIADORXServer* OpenAdoServer(LPCTSTR pszDbPathName);
	CString m_csName;
	CString m_csMoney;
	CString m_csAuton;
	CString m_csNum;
	CString m_csPress;
	CString m_csNumTo;
};
