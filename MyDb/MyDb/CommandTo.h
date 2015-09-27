#pragma once
#include "afxwin.h"


// CCommandTo 对话框

class CCommandTo : public CDialog
{
	DECLARE_DYNAMIC(CCommandTo)

public:
	CCommandTo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCommandTo();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_Cmmand;
};
