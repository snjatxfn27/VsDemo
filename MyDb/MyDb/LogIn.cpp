// LogIn.cpp : 实现文件
//

#include "stdafx.h"
#include "MyDb.h"
#include "LogIn.h"
#include "Register.h"
#include "MyFind2.h"
// CLogIn 对话框

IMPLEMENT_DYNAMIC(CLogIn, CDialog)

CLogIn::CLogIn(CWnd* pParent /*=NULL*/)
: CDialog(CLogIn::IDD, pParent)
, m_csName(_T(""))
, m_csPassword(_T(""))
{
	
}

CLogIn::~CLogIn()
{
}

void CLogIn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_ZH, m_csName);
	DDX_Text(pDX, IDC_EDT_MM, m_csPassword);
}


BEGIN_MESSAGE_MAP(CLogIn, CDialog)
	ON_BN_CLICKED(IDOK, &CLogIn::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO_XS, &CLogIn::OnBnClickedRadioXs)
	ON_BN_CLICKED(IDC_RADIO_GL, &CLogIn::OnBnClickedRadioGl)
	ON_BN_CLICKED(IDC_BUT_ZC, &CLogIn::OnBnClickedButZc)
	ON_BN_CLICKED(IDC_BUT_ZH, &CLogIn::OnBnClickedButZh)
END_MESSAGE_MAP()


// CLogIn 消息处理程序

BOOL CLogIn::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_flag =0;

	((CButton *)GetDlgItem(IDC_RADIO_XS))->SetCheck(TRUE);


	return TRUE;
}
void CLogIn::OnBnClickedOk()
{
	UpdateData();

	if (m_csName.GetLength()==0 || m_csPassword.GetLength()==0)
	{
		MessageBox(_T("账号密码不能为空"),_T("提示"));
		return;
	}
	TCHAR tcPath[MAX_PATH];
	GetModuleFileName(NULL,tcPath,_MAX_PATH);
	CString csPath =tcPath;
	csPath = csPath.Left(csPath.ReverseFind('\\'));
	CString sqlName = csPath + "\\Data.mdb";
	int Isqlnum;

	CUIIADORXServer *SqlServer;
	SqlServer=OpenAdoServer(sqlName);
	if (SqlServer==NULL)
		return ;
	else
	{
		CStringList csTrlist;
		CString csStrsql;

		csStrsql.Format(_T("select * from login where Name='%s' and  Password='%s'and  Flag=%d"),m_csName,m_csPassword,m_flag);
		Isqlnum= SqlServer->GetSelData(csStrsql,csTrlist);
		CloseAdoServer(SqlServer);
		if (Isqlnum == 0)
			MessageBox(_T("账号不存在"),_T("提示"));		
		else
			OnOK();
	}

}
CUIIADORXServer* CLogIn::OpenAdoServer(LPCTSTR pszDbPathName)
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
void CLogIn::CloseAdoServer(CUIIADORXServer*& pAdo)
{
	if(NULL != pAdo)
	{
		delete pAdo;
		pAdo = NULL;
	}
}
void CLogIn::OnBnClickedRadioXs()
{
	m_flag =0;
}

void CLogIn::OnBnClickedRadioGl()
{
	m_flag =1;
}

void CLogIn::OnBnClickedButZc()
{
	CRegister dlg;
	dlg.DoModal();
}

void CLogIn::OnBnClickedButZh()
{
	CMyFind2 dlg;
	dlg.DoModal();
}
