// Register.cpp : 实现文件
//

#include "stdafx.h"
#include "MyDb.h"
#include "Register.h"


// CRegister 对话框

IMPLEMENT_DYNAMIC(CRegister, CDialog)

CRegister::CRegister(CWnd* pParent /*=NULL*/)
: CDialog(CRegister::IDD, pParent)
, m_csName(_T(""))
, m_csPassword(_T(""))
, m_csNumber(_T(""))
, m_csPasswordTo(_T(""))
, m_csNameTo(_T(""))
, m_csMojar(_T(""))
{

}

CRegister::~CRegister()
{
}

void CRegister::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_csName);
	DDX_Text(pDX, IDC_EDIT2, m_csPassword);
	DDX_Text(pDX, IDC_EDIT3, m_csNumber);
	DDX_Text(pDX, IDC_EDIT4, m_csPasswordTo);
	DDX_Text(pDX, IDC_EDIT5, m_csNameTo);
	DDX_Text(pDX, IDC_EDIT6, m_csMojar);
}


BEGIN_MESSAGE_MAP(CRegister, CDialog)
	ON_BN_CLICKED(IDOK, &CRegister::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO_XS, &CRegister::OnBnClickedRadioXs)
	ON_BN_CLICKED(IDC_RADIO_GL, &CRegister::OnBnClickedRadioGl)
END_MESSAGE_MAP()


// CRegister 消息处理程序
BOOL CRegister::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_flag =0;

	((CButton *)GetDlgItem(IDC_RADIO_XS))->SetCheck(TRUE);


	return TRUE;
}
CUIIADORXServer* CRegister::OpenAdoServer(LPCTSTR pszDbPathName)
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
void CRegister::CloseAdoServer(CUIIADORXServer*& pAdo)
{
	if(NULL != pAdo)
	{
		delete pAdo;
		pAdo = NULL;
	}
}
#include "CommandTo.h"
void CRegister::OnBnClickedOk()
{
	UpdateData();
	if (m_flag == 1)
	{
		CCommandTo dlg;
		INT_PTR ilog;
		ilog = dlg.DoModal();
		if (ilog == IDCANCEL)
		{
			return;
		}
		if (dlg.m_Cmmand != _T("yangxiaoxu"))
		{
			MessageBox(_T("注册失败"),_T("提示"));
			return;
		}

	}
	if (m_csPassword != m_csPasswordTo)
	{
		MessageBox(_T("密码不一样"),_T("提示"));
		return;
	}
	if (m_csName.GetLength()==0 || m_csPassword.GetLength()==0 || m_csNumber.GetLength()==0
		|| m_csMojar.GetLength()==0|| m_csNameTo.GetLength()==0)
	{
		MessageBox(_T("字段不能为空"),_T("提示"));
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

		csStrsql.Format(_T("select [Name] from login where Name='%s' "),m_csName);
		Isqlnum= SqlServer->GetSelData(csStrsql,csTrlist);
		if (Isqlnum == 0){
			csStrsql.Format(_T("select [Number] from login where Name='%s' "),m_csNumber);
			Isqlnum= SqlServer->GetSelData(csStrsql,csTrlist);
			if (Isqlnum == 0){
			}else
				MessageBox(_T("账号存在或密码错误"),_T("提示"));
			csStrsql.Format(_T("insert into login ([Name], [Password], [Flag], [Number],[Major],[NameTo],[Max],[Current]) values ('%s','%s',%d,'%s','%s','%s','%s','%s')"),m_csName,m_csPassword,m_flag,m_csNumber,m_csMojar,m_csNameTo,_T("5"),_T("0"));

			int isql =SqlServer->ExecuteSQL(csStrsql);
			CloseAdoServer(SqlServer);
			if (isql)
			{
				MessageBox(_T("注册成功"),_T("提示"));
				OnOK();
			}

		}
		else
			MessageBox(_T("账号存在或密码错误"),_T("提示"));
	}

}

void CRegister::OnBnClickedRadioXs()
{
	m_flag = 0;
}

void CRegister::OnBnClickedRadioGl()
{
	m_flag = 1;
}
