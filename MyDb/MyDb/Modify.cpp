// Modify.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyDb.h"
#include "Modify.h"


// CModify �Ի���

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


// CModify ��Ϣ�������
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
			MessageBox(_T("���벻��ȷ"),_T("��ʾ"));
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
				MessageBox(_T("�����޸ĳɹ�"),_T("��ʾ"));
				OnOK();
			}
			else
				MessageBox(_T("����ʧ��"),_T("��ʾ"));
		}
}
