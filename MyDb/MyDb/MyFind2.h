#pragma once
#include "Inc/TGAdo.h"

// CMyFind2 对话框

class CMyFind2 : public CDialog
{
	DECLARE_DYNAMIC(CMyFind2)

public:
	CMyFind2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyFind2();

// 对话框数据
	enum { IDD = IDD_MyFind };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void CloseAdoServer(CUIIADORXServer*& pAdo);
	CUIIADORXServer* OpenAdoServer(LPCTSTR pszDbPathName);
	virtual BOOL OnInitDialog();
	int m_flag;

	afx_msg void OnBnClickedOk2();
	CString m_csName;
	CString m_csNumber;
	afx_msg void OnBnClickedRadioXs();
	afx_msg void OnBnClickedRadioGl();
};
