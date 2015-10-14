
// MyDbDlg.h : 头文件
//

#pragma once
#include "Inc/TGAdo.h"
#include "afxcmn.h"
#include "afxwin.h"

// CMyDbDlg 对话框
class CMyDbDlg : public CDialog
{
// 构造
public:
	CMyDbDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MYDB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CUIIADORXServer* OpenAdoServer(LPCTSTR pszDbPathName);
	void CloseAdoServer(CUIIADORXServer*& pAdo);
	CString m_csName; //账号
	CString m_csPassword;
	void ShowList();
	afx_msg void OnBnClickedButSlete();
	afx_msg void OnBnClickedButSlete2();
	afx_msg void OnBnClickedButJy2();
	afx_msg void OnBnClickedButJy();
	afx_msg void OnBnClickedButJy3();
	afx_msg void OnBnClickedButGh();
	afx_msg void OnBnClickedButTj();
	afx_msg void OnBnClickedButSy();
	CString m_csBookName;
	CString m_csZhuoZheName;
	CListCtrl m_lstOutData;
	CString m_sqlName;
	CString m_csNum;
	afx_msg void OnBnClickedButSlete3();
	afx_msg void OnNMClickLstOutdata(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_csSelectBookName; //书名
	CString m_csSelectName; //人名
	CString m_csSelectNum; 
	CString m_csSelectFlag;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CStatic m_static1;
	afx_msg void OnBnClickedButTj2();
	afx_msg void OnBnClickedButSy2();
	bool m_bLongin;
	void GetData(CString strName, CString strFlag);
	BOOL bGuanli;
};
