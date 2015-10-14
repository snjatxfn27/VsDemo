
// MyDbDlg.h : ͷ�ļ�
//

#pragma once
#include "Inc/TGAdo.h"
#include "afxcmn.h"
#include "afxwin.h"

// CMyDbDlg �Ի���
class CMyDbDlg : public CDialog
{
// ����
public:
	CMyDbDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MYDB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CUIIADORXServer* OpenAdoServer(LPCTSTR pszDbPathName);
	void CloseAdoServer(CUIIADORXServer*& pAdo);
	CString m_csName; //�˺�
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
	CString m_csSelectBookName; //����
	CString m_csSelectName; //����
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
