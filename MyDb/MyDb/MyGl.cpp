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
	m_nFlag = 2;
}

void CMyGl::OnBnClickedButton2()
{
	UpdateData();
	CStringArray csTrlist;

	if (m_bookname.IsEmpty())
	{
		return;
	}
	TCHAR tcPath[MAX_PATH];
	GetModuleFileName(NULL,tcPath,_MAX_PATH);
	CString csPath =tcPath;
	csPath = csPath.Left(csPath.ReverseFind('\\'));
	CString m_sqlName = csPath ;
	m_sqlName += "\\Data.mdb";
	CUIIADORXServer *SqlServer;
	SqlServer=OpenAdoServer(m_sqlName);
	if (SqlServer==NULL)
		return ;
	else
	{
		CString csStrsql;
		csStrsql.Format(_T("select * from bookdata where  BookName='%s'"),m_bookname);

		int IsqlnumTo=SqlServer->GetSelData(csStrsql,csTrlist);
		if (IsqlnumTo > 0)
		{
			csStrsql.Format(_T("delete * from bookdata where BookName='%s'"),m_bookname);
			BOOL isql =SqlServer->ExecuteSQL(csStrsql);
			m_nFlag = 2;
			MessageBox(_T("删除成功"),_T("提示"));
			OnOK();
		}
		else
		{
			MessageBox(_T("没有记录"),_T("提示"));
		}
	}
}

void CMyGl::OnBnClickedButton4()
{
	UpdateData();
	if (m_name.IsEmpty())
	{
		return;
	}
	m_nFlag = 3;
	m_nFlagTo = _T("0");
	OnOK();
}

void CMyGl::OnBnClickedButton3()
{
	UpdateData();
	if (m_name.IsEmpty())
	{
		return;
	}
	m_nFlag = 4;
	m_nFlagTo = _T("1");

	OnOK();
}

BOOL CMyGl::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_nFlagTo =_T("11");
	m_nFlag =10;
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
