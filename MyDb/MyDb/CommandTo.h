#pragma once
#include "afxwin.h"


// CCommandTo �Ի���

class CCommandTo : public CDialog
{
	DECLARE_DYNAMIC(CCommandTo)

public:
	CCommandTo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCommandTo();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_Cmmand;
};
