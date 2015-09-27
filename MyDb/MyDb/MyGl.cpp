// MyGl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyDb.h"
#include "MyGl.h"


// CMyGl �Ի���

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


// CMyGl ��Ϣ�������
CUIIADORXServer* CMyGl::OpenAdoServer(LPCTSTR pszDbPathName)
{
	// ���ݿ������ַ���
	CString sConStr;
	sConStr.Format(_T("DRIVER={Microsoft Access Driver (*.mdb)};DBQ=%s;UID='';PWD=''"), pszDbPathName);
	::CoInitialize(NULL);

	CUIIADORXServer* pAdo = new CUIIADORXServer;
	if(!pAdo->InitADOServer(sConStr))
	{
		delete pAdo;
		pAdo = NULL;
		CString sMsg;
		sMsg.Format(_T("%s ���ݿ�����ʧ�ܣ�"), pszDbPathName);
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CMyGl::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CMyGl::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
