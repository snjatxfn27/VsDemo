#pragma once

#include "Inc/TGAdo.h"
// CRegister 对话框

class CRegister : public CDialog
{
	DECLARE_DYNAMIC(CRegister)

public:
	CRegister(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRegister();

// 对话框数据
	enum { IDD = IDD_Register };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	void CloseAdoServer(CUIIADORXServer*& pAdo);
	CUIIADORXServer* OpenAdoServer(LPCTSTR pszDbPathName);
	CString m_csName;
	CString m_csPassword;
	CString m_csNumber;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	int m_flag;

	afx_msg void OnBnClickedRadioXs();
	afx_msg void OnBnClickedRadioGl();
	CString m_csPasswordTo;
	CString m_csNameTo;
	CString m_csMojar;
};
