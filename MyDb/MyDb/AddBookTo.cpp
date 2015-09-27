// AddBookTo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyDb.h"
#include "AddBookTo.h"



// CAddBookTo �Ի���

IMPLEMENT_DYNAMIC(CAddBookTo, CDialog)

CAddBookTo::CAddBookTo(CWnd* pParent /*=NULL*/)
	: CDialog(CAddBookTo::IDD, pParent)
	, m_csName(_T(""))
	, m_csNumTo(_T(""))
{

}

CAddBookTo::~CAddBookTo()
{
}

void CAddBookTo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_csName);
	DDX_Text(pDX, IDC_EDIT4, m_csMoney);
	DDX_Text(pDX, IDC_EDIT2, m_csAuton);
	DDX_Text(pDX, IDC_EDIT5, m_csNum);
	DDX_Text(pDX, IDC_EDIT3, m_csPress);
	DDX_Text(pDX, IDC_EDIT6, m_csNumTo);
}


BEGIN_MESSAGE_MAP(CAddBookTo, CDialog)
	ON_BN_CLICKED(IDOK, &CAddBookTo::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddBookTo ��Ϣ�������
CUIIADORXServer* CAddBookTo::OpenAdoServer(LPCTSTR pszDbPathName)
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
void CAddBookTo::CloseAdoServer(CUIIADORXServer*& pAdo)
{
	if(NULL != pAdo)
	{
		delete pAdo;
		pAdo = NULL;
	}
}
void CAddBookTo::OnBnClickedOk()
{
	UpdateData();

	if (m_csName.GetLength()==0 || m_csMoney.GetLength()==0 || m_csAuton.GetLength()==0
		|| m_csNum.GetLength()==0|| m_csPress.GetLength()==0)
	{
		MessageBox(_T("�ֶβ���Ϊ��"),_T("��ʾ"));
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

		csStrsql.Format(_T("select [BookName] from bookdata where BookName='%s' "),m_csName);
		Isqlnum= SqlServer->GetSelData(csStrsql,csTrlist);
		if (Isqlnum == 0){
			csStrsql.Format(_T("insert into bookdata ([BookName], [BookAuthor], [BookMoney], [BookPress],[BookNum],[BookSum]) values ('%s','%s','%s','%s','%s','%s')"),m_csName,m_csAuton,m_csMoney,m_csPress,m_csNumTo,m_csNum);
			int isql =SqlServer->ExecuteSQL(csStrsql);
			CloseAdoServer(SqlServer);
			if (isql)
			{
				MessageBox(_T("��ӳɹ�"),_T("��ʾ"));
				OnOK();
			}

		}
		else
			MessageBox(_T("�鼮�Ѵ���"),_T("��ʾ"));
	}

}
