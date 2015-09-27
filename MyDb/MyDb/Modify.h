#pragma once
#include "afxwin.h"
#include "Inc/TGAdo.h"
// CModify �Ի���

class CModify : public CDialog
{
	DECLARE_DYNAMIC(CModify)

public:
	CModify(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CModify();

// �Ի�������
	enum { IDD = IDD_Modify };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void CloseAdoServer(CUIIADORXServer*& pAdo);
	CUIIADORXServer* OpenAdoServer(LPCTSTR pszDbPathName);
	virtual BOOL OnInitDialog();

	CString m_csname;
	CString m_csmima;
	CString m_csmimato;
	CString m_csnumber;
	CString m_csnameto;
	CString m_cszhuanye;
};
