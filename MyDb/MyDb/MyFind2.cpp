// MyFind2.cpp : 实现文件
//

#include "stdafx.h"
#include "MyDb.h"
#include "MyFind2.h"


// CMyFind2 对话框

IMPLEMENT_DYNAMIC(CMyFind2, CDialog)

CMyFind2::CMyFind2(CWnd* pParent /*=NULL*/)
	: CDialog(CMyFind2::IDD, pParent)
	, m_csName(_T(""))
	, m_csNumber(_T(""))
{

}

CMyFind2::~CMyFind2()
{
}

void CMyFind2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_ZH, m_csName);
	DDX_Text(pDX, IDC_EDT_MM, m_csNumber);
}


BEGIN_MESSAGE_MAP(CMyFind2, CDialog)
	ON_BN_CLICKED(IDOK2, &CMyFind2::OnBnClickedOk2)
	ON_BN_CLICKED(IDC_RADIO_XS, &CMyFind2::OnBnClickedRadioXs)
	ON_BN_CLICKED(IDC_RADIO_GL, &CMyFind2::OnBnClickedRadioGl)
END_MESSAGE_MAP()


// CMyFind2 消息处理程序
BOOL CMyFind2::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_flag =0;

	((CButton *)GetDlgItem(IDC_RADIO_XS))->SetCheck(TRUE);


	return TRUE;
}
CUIIADORXServer* CMyFind2::OpenAdoServer(LPCTSTR pszDbPathName)
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
void CMyFind2::CloseAdoServer(CUIIADORXServer*& pAdo)
{
	if(NULL != pAdo)
	{
		delete pAdo;
		pAdo = NULL;
	}
}
void CMyFind2::OnBnClickedOk2()
{
	UpdateData();

	if (m_csName.GetLength()==0 || m_csNumber.GetLength()==0)
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
		CStringArray csTrlist;
		CString csStrsql;

		csStrsql.Format(_T("select * from login where Name='%s' and  Number='%s' and Flag=%d"),m_csName,m_csNumber,m_flag);
		Isqlnum= SqlServer->GetSelData(csStrsql,csTrlist);
		CloseAdoServer(SqlServer);

		if (Isqlnum == 0)
			MessageBox(_T("账号不存在或学号错误"),_T("提示"));		
		else{
				
			MessageBox(_T("密码为：")+csTrlist[1]);
		}
			
	}

}

void CMyFind2::OnBnClickedRadioXs()
{
	m_flag =0;
}

void CMyFind2::OnBnClickedRadioGl()
{
	m_flag =1;
}
