#pragma once
#include "Inc/TGAdo.h"
#include "afxwin.h"

// CMyGl �Ի���

class CMyGl : public CDialog
{
	DECLARE_DYNAMIC(CMyGl)

public:
	CMyGl(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyGl();

// �Ի�������
	enum { IDD = IDD_GL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	void CloseAdoServer(CUIIADORXServer*& pAdo);
	CUIIADORXServer* OpenAdoServer(LPCTSTR pszDbPathName);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	CString m_bookname;
	CString m_name;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
};
