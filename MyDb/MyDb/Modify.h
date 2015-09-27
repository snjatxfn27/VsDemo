#pragma once
#include "afxwin.h"
#include "Inc/TGAdo.h"
// CModify 对话框

class CModify : public CDialog
{
	DECLARE_DYNAMIC(CModify)

public:
	CModify(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CModify();

// 对话框数据
	enum { IDD = IDD_Modify };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
