// Modify.cpp : 实现文件
//

#include "stdafx.h"
#include "MyDb.h"
#include "Modify.h"


// CModify 对话框

IMPLEMENT_DYNAMIC(CModify, CDialog)

CModify::CModify(CWnd* pParent /*=NULL*/)
: CDialog(CModify::IDD, pParent)
{

}

CModify::~CModify()
{
}

void CModify::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_csname);
	DDX_Text(pDX, IDC_EDIT3, m_csmima);
	DDX_Text(pDX, IDC_EDIT5, m_csmimato);
	DDX_Text(pDX, IDC_EDIT4, m_csnumber);
	DDX_Text(pDX, IDC_EDIT6, m_csnameto);
	DDX_Text(pDX, IDC_EDIT7, m_cszhuanye);
}


BEGIN_MESSAGE_MAP(CModify, CDialog)
	ON_BN_CLICKED(IDOK, &CModify::OnBnClickedOk)
END_MESSAGE_MAP()


// CModify 消息处理程序
BOOL CModify::OnInitDialog()
{
	CDialog::OnInitDialog();

	TCHAR tcPath[MAX_PATH];
	GetModuleFileName(NULL,tcPath,_MAX_PATH);
	CString csPath =tcPath;
	csPath = csPath.Left(csPath.ReverseFind('\\'));
	CString sqlName = csPath + "\\Data.mdb";
	int Isqlnum;

	CUIIADORXServer *SqlServer;
	SqlServer=OpenAdoServer(sqlName);
	if (SqlServer==NULL)
		return FALSE;
	else
	{
		CStringArray csTrlist;
		CString csStrsql;

		csStrsql.Format(_T("select * from login where Name='%s' "),m_csname);
	
		Isqlnum= SqlServer->GetSelData(csStrsql,csTrlist);
		if (Isqlnum > 0)
		{

			m_csmima = csTrlist[1];
			m_csmimato =m_csmima;
			m_csnumber = csTrlist[3];
			m_cszhuanye = csTrlist[4];
			m_csnameto = csTrlist[5];
		}
	}
	UpdateData(FALSE);
	return TRUE;
}
CUIIADORXServer* CModify::OpenAdoServer(LPCTSTR pszDbPathName)
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
void CModify::CloseAdoServer(CUIIADORXServer*& pAdo)
{
	if(NULL != pAdo)
	{
		delete pAdo;
		pAdo = NULL;
	}
}
void CModify::OnBnClickedOk()
{
		UpdateData();
		if (m_csmima != m_csmimato||m_csmima.GetLength()==0||m_csmimato.GetLength()==0)
		{
			MessageBox(_T("密码不正确"),_T("提示"));
			return;
		}

		TCHAR tcPath[MAX_PATH];
		GetModuleFileName(NULL,tcPath,_MAX_PATH);
		CString csPath =tcPath;
		csPath = csPath.Left(csPath.ReverseFind('\\'));
		CString sqlName = csPath + "\\Data.mdb";
		CUIIADORXServer *SqlServer;
		SqlServer=OpenAdoServer(sqlName);
		if (SqlServer==NULL)
			return ;
		else
		{
			CString csStrsql;

			csStrsql.Format(_T("update [login]  set [Password]='%s' where	[Name]='%s'"),m_csmima,m_csname);
			int isql= SqlServer->ExecuteSQL(csStrsql);
			if(isql){
				MessageBox(_T("密码修改成功"),_T("提示"));
				OnOK();
			}
			else
				MessageBox(_T("密码失败"),_T("提示"));
		}
}
