#pragma once
#include "Inc/TGAdo.h"

// CLogIn �Ի���

class CLogIn : public CDialog
{
	DECLARE_DYNAMIC(CLogIn)

public:
	CLogIn(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLogIn();

// �Ի�������
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_csName;
	CString m_csPassword;
	void CloseAdoServer(CUIIADORXServer*& pAdo);
	CUIIADORXServer* OpenAdoServer(LPCTSTR pszDbPathName);
	afx_msg void OnBnClickedRadioXs();
	int m_flag;
	afx_msg void OnBnClickedRadioGl();
	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedButZc();
	afx_msg void OnBnClickedButZh();
};
