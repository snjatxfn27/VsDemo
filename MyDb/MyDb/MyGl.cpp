// MyGl.cpp : 实现文件
//

#include "stdafx.h"
#include "MyDb.h"
#include "MyGl.h"


// CMyGl 对话框

IMPLEMENT_DYNAMIC(CMyGl, CDialog)

CMyGl::CMyGl(CWnd* pParent /*=NULL*/)
	: CDialog(CMyGl::IDD, pParent)
{

}

CMyGl::~CMyGl()
{
}

void CMyGl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_bookname);
	DDX_Text(pDX, IDC_EDIT2, m_name);
}


BEGIN_MESSAGE_MAP(CMyGl, CDialog)
	ON_BN_CLICKED(IDOK, &CMyGl::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyGl::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyGl::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMyGl::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyGl::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMyGl 消息处理程序
CUIIADORXServer* CMyGl::OpenAdoServer(LPCTSTR pszDbPathName)
{
	// 数据库连接字符串
	CString sConStr;
	sConStr.Format(_T("DRIVER={Microsoft Access Driver (*.mdb)};DBQ=%s;UID='';PWD=''"), pszDbPathName);
	::CoInitialize(NULL);

	CUIIADORXServer* pAdo = new CUIIADORXServer;
	if(!pAdo->InitADOServer(sConStr))
	{
		delete pAdo;
		pAdo = NULL;
		CString sMsg;
		sMsg.Format(_T("%s 数据库连接失败！"), pszDbPathName);
		AfxMessageBox(sMsg);
		return NULL;
	}
	return pAdo;
}
void CMyGl::CloseAdoServer(CUIIADORXServer*& pAdo)
{
	if(NULL != pAdo)
	{
		delete pAdo;
		pAdo = NULL;
	}
}
void CMyGl::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}
#include "AddBookTo.h"
void CMyGl::OnBnClickedButton1()
{
	CAddBookTo dlg;
	dlg.DoModal();
}

void CMyGl::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CMyGl::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CMyGl::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
}
