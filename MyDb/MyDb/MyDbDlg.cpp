
// MyDbDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyDb.h"
#include "MyDbDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMyDbDlg �Ի���




CMyDbDlg::CMyDbDlg(CWnd* pParent /*=NULL*/)
: CDialog(CMyDbDlg::IDD, pParent)
, m_csBookName(_T(""))
, m_csZhuoZheName(_T(""))
, m_csNum(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDbDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_BookName, m_csBookName);
	DDX_Text(pDX, IDC_EDT_BookName2, m_csZhuoZheName);
	DDX_Control(pDX, IDC_LST_OutData, m_lstOutData);
	DDX_Text(pDX, IDC_EDT_BookName3, m_csNum);
	DDX_Control(pDX, IDC_STATIC1, m_static1);
}

BEGIN_MESSAGE_MAP(CMyDbDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CMyDbDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUT_Slete, &CMyDbDlg::OnBnClickedButSlete)
	ON_BN_CLICKED(IDC_BUT_Slete2, &CMyDbDlg::OnBnClickedButSlete2)
	ON_BN_CLICKED(IDC_BUT_JY2, &CMyDbDlg::OnBnClickedButJy2)
	ON_BN_CLICKED(IDC_BUT_JY, &CMyDbDlg::OnBnClickedButJy)
	ON_BN_CLICKED(IDC_BUT_JY3, &CMyDbDlg::OnBnClickedButJy3)
	ON_BN_CLICKED(IDC_BUT_GH, &CMyDbDlg::OnBnClickedButGh)
	ON_BN_CLICKED(IDC_BUT_TJ, &CMyDbDlg::OnBnClickedButTj)
	ON_BN_CLICKED(IDC_BUT_SY, &CMyDbDlg::OnBnClickedButSy)
	ON_BN_CLICKED(IDC_BUT_Slete3, &CMyDbDlg::OnBnClickedButSlete3)
	ON_NOTIFY(NM_CLICK, IDC_LST_OutData, &CMyDbDlg::OnNMClickLstOutdata)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUT_TJ2, &CMyDbDlg::OnBnClickedButTj2)
	ON_BN_CLICKED(IDC_BUT_SY2, &CMyDbDlg::OnBnClickedButSy2)
END_MESSAGE_MAP()


// CMyDbDlg ��Ϣ�������

BOOL CMyDbDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	m_lstOutData.DeleteAllItems();
	m_lstOutData.SetExtendedStyle(	LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_lstOutData.InsertColumn(0,_T("����"),LVCFMT_LEFT,100);
	m_lstOutData.InsertColumn(1,_T("����"),LVCFMT_LEFT,100);
	m_lstOutData.InsertColumn(2,_T("������"),LVCFMT_LEFT,80);
	m_lstOutData.InsertColumn(3,_T("�۸�"),LVCFMT_LEFT,50);
	m_lstOutData.InsertColumn(4,_T("���"),LVCFMT_LEFT,50);
	m_lstOutData.InsertColumn(5,_T("����"),LVCFMT_LEFT,50);

	TCHAR tcPath[MAX_PATH];
	GetModuleFileName(NULL,tcPath,_MAX_PATH);
	CString csPath =tcPath;
	csPath = csPath.Left(csPath.ReverseFind('\\'));
	m_sqlName = csPath ;\
		m_sqlName += "\\Data.mdb";

	m_bLongin = false;

	CFont font;
	font.CreateFont(120,120,0,0,FW_BLACK,FALSE,FALSE,
		FALSE,GB2312_CHARSET,OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,
		FIXED_PITCH|FF_MODERN, _T("���Ŀ���"));
	m_static1.SetFont(&font);
	font.DeleteObject();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMyDbDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMyDbDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMyDbDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMyDbDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}
CUIIADORXServer* CMyDbDlg::OpenAdoServer(LPCTSTR pszDbPathName)
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
void CMyDbDlg::CloseAdoServer(CUIIADORXServer*& pAdo)
{
	if(NULL != pAdo)
	{
		delete pAdo;
		pAdo = NULL;
	}
}
void CMyDbDlg::ShowList()
{

}
void CMyDbDlg::OnBnClickedButSlete()
{
	UpdateData();

	if (m_csBookName.GetLength()==0 )
	{
		MessageBox(_T("�ֶβ���Ϊ��"),_T("��ʾ"));
		return;
	}
	m_lstOutData.DeleteAllItems();
	int Isqlnum ;
	CUIIADORXServer *SqlServer;
	SqlServer=OpenAdoServer(m_sqlName);
	if (SqlServer==NULL)
		return ;
	else
	{
		CStringList csTrlist;
		CString csStrsql;

		csStrsql.Format(_T("select * from bookdata where BookName='%s'"),m_csBookName);
		Isqlnum= SqlServer->GetSelData(csStrsql,csTrlist);
		CloseAdoServer(SqlServer);
		Isqlnum=(double)Isqlnum/(double)6;
		CString csOut;
		POSITION rPos;
		rPos = csTrlist.GetHeadPosition();

		for (int i = 0; i < Isqlnum; i++)
		{
			int row = m_lstOutData.GetItemCount();
			m_lstOutData.InsertItem(row ,_T(""));

			for (int j=0;j<6;j++)
			{
				csOut=csTrlist.GetNext(rPos);
				m_lstOutData.SetItemText(row,j,csOut);	
			}
		}
	}

}


void CMyDbDlg::OnBnClickedButSlete2()
{
	UpdateData();
	if (m_csZhuoZheName.GetLength()==0 )
	{
		MessageBox(_T("�ֶβ���Ϊ��"),_T("��ʾ"));
		return;
	}

	m_lstOutData.DeleteAllItems();
	int Isqlnum;
	CUIIADORXServer *SqlServer;
	SqlServer=OpenAdoServer(m_sqlName);
	if (SqlServer==NULL)
		return ;
	else
	{

		CStringList csTrlist;
		CString csStrsql;

		csStrsql.Format(_T("select * from bookdata where BookAuthor='%s'"),m_csZhuoZheName);
		Isqlnum= SqlServer->GetSelData(csStrsql,csTrlist);
		CloseAdoServer(SqlServer);
		Isqlnum=(double)Isqlnum/(double)6;
		CString csOut;
		POSITION rPos;
		rPos = csTrlist.GetHeadPosition();

		for (int i = 0; i < Isqlnum; i++)
		{
			int row = m_lstOutData.GetItemCount();
			m_lstOutData.InsertItem(row ,_T(""));

			for (int j=0;j<6;j++)
			{
				csOut=csTrlist.GetNext(rPos);
				m_lstOutData.SetItemText(row,j,csOut);	
			}
		}

	}

}
#include "Modify.h"
void CMyDbDlg::OnBnClickedButJy2()
{
	CModify dlg;
	dlg.m_csname=m_csName;
	dlg.DoModal();
}

	void CMyDbDlg::OnBnClickedButJy()
	{
		if ( m_csName.GetLength()==0)
		{
			MessageBox(_T("��������"),_T("��ʾ"));
			return;
		}

		m_lstOutData.DeleteAllItems();
		CUIIADORXServer *SqlServer;
		SqlServer=OpenAdoServer(m_sqlName);
		if (SqlServer==NULL)
			return ;
		else
		{

			CString csStrsql;
			CStringArray csTrlist;
			csStrsql.Format(_T("select * from bookmessageto where  Name='%s' and Flag='1'"),m_csName);
			int Isqlnum= SqlServer->GetSelData(csStrsql,csTrlist);
			int tt =csTrlist.GetSize();
// 			CString st;
// 			for (int i =0 ;i < tt ;i++)
// 			{
// 				st.Format(_T("%d: %s"),i,csTrlist.GetAt(i));
// 				MessageBox(st);
// 			}
			
			int t =0;
			if (Isqlnum <= 0)
			{
				MessageBox(_T("û�м�¼"),_T("��ʾ"));
				return;
			}
			int sum =1;

			for (int i=0;i<Isqlnum;i++)
			{
				CStringList csTrlistTo;
				csStrsql.Format(_T("select * from bookdata where  BookName='%s'"),csTrlist[sum]);

 				int IsqlnumTo=SqlServer->GetSelData(csStrsql,csTrlistTo);

				IsqlnumTo=(double)IsqlnumTo/(double)6;

				CString csOut;
				POSITION rPos;
				rPos = csTrlistTo.GetHeadPosition();

				for (int i = 0; i < IsqlnumTo; i++)
				{
					int row = m_lstOutData.GetItemCount();
					m_lstOutData.InsertItem(row ,_T(""));

					for (int j=0;j<6;j++)
					{
						csOut=csTrlistTo.GetNext(rPos);
						m_lstOutData.SetItemText(row,j,csOut);	
					}

				}
				sum+=7;
			}

			CloseAdoServer(SqlServer);
		}
	}

void CMyDbDlg::OnBnClickedButJy3()
{



	if (m_csSelectBookName.GetLength()==0 || m_csName.GetLength()==0 || m_csSelectName.GetLength()==0)
	{
		MessageBox(_T("��������"),_T("��ʾ"));
		return;
	}

	if (_wtoi(m_csSelectNum) <= 0)
	{
		MessageBox(_T("û�п��"),_T("��ʾ"));
		return;
	}

	CUIIADORXServer *SqlServer;
	SqlServer=OpenAdoServer(m_sqlName);
	if (SqlServer==NULL)
		return ;
	else
	{

		CString csStrsql;
		CStringArray csTrlist;
		csStrsql.Format(_T("select * from bookmessageto where BookName='%s'and Name='%s'and Flag='1' "),m_csSelectBookName,m_csName);
		int Isqlnum= SqlServer->GetSelData(csStrsql,csTrlist);
		if (Isqlnum > 0)
		{
			MessageBox(_T("�ѽ��鼮"),_T("��ʾ"));
			return;
		}

		csStrsql.Format(_T("insert into bookmessageto ([BookName], [Name], [NameTo], [Flag]) values ('%s','%s','%s','%s')"),m_csSelectBookName,m_csName,m_csSelectName,_T("1"));
		int isql =SqlServer->ExecuteSQL(csStrsql);

		if (isql)
			MessageBox(_T("���ĳɹ�"),_T("��ʾ"));
		else{
			MessageBox(_T("����ʧ��"),_T("��ʾ"));
			return;

		}
		m_csSelectNum.Format(_T("%d"),_wtoi(m_csSelectNum)-1);
		csStrsql.Format(_T("update [bookdata]  set [BookSum]='%s' where	[BookName]='%s'"),m_csSelectNum,m_csSelectBookName);
	
		SqlServer->ExecuteSQL(csStrsql);

		CloseAdoServer(SqlServer);

		m_csSelectBookName = "";
		OnBnClickedButSy();
	}
}

void CMyDbDlg::OnBnClickedButGh()
{

	if (m_csSelectBookName.GetLength()==0 || m_csName.GetLength()==0 || m_csSelectName.GetLength()==0)
	{
		MessageBox(_T("��������"),_T("��ʾ"));
		return;
	}


	CUIIADORXServer *SqlServer;
	SqlServer=OpenAdoServer(m_sqlName);
	if (SqlServer==NULL)
		return ;
	else
	{

		CString csStrsql;
		CStringArray csTrlist;
		csStrsql.Format(_T("select * from bookmessageto where BookName='%s'and Name='%s' and Flag='1'"),m_csSelectBookName,m_csName);
		int Isqlnum= SqlServer->GetSelData(csStrsql,csTrlist);
		if (Isqlnum <= 0)
		{
			MessageBox(_T("û�м�¼"),_T("��ʾ"));
			return;
		}


		csStrsql.Format(_T("update [bookmessageto]  set [Flag]='%s' where	[BookName]='%s' and Name='%s' "),_T("0"),m_csSelectBookName,m_csName);
		int isql=SqlServer->ExecuteSQL(csStrsql);
		if(isql)
			MessageBox(_T("�黹�ɹ�"),_T("��ʾ"));
		else
			MessageBox(_T("�黹ʧ��"),_T("��ʾ"));

		m_csSelectNum.Format(_T("%d"),_wtoi(m_csSelectNum)+1);
		csStrsql.Format(_T("update [bookdata]  set [BookSum]='%s' where	[BookName]='%s'"),m_csSelectNum,m_csSelectBookName);
	
		SqlServer->ExecuteSQL(csStrsql);

		CloseAdoServer(SqlServer);
		m_csSelectBookName = "";

	}
}
#include "AddBookTo.h"
#include "MyGl.h"
void CMyDbDlg::OnBnClickedButTj()
{
	CMyGl dlg;
	dlg.DoModal();
}

void CMyDbDlg::OnBnClickedButSy()
{
	m_lstOutData.DeleteAllItems();
	int Isqlnum;
	CUIIADORXServer *SqlServer;
	SqlServer=OpenAdoServer(m_sqlName);
	if (SqlServer==NULL)
		return ;
	else
	{
		CStringList csTrlist;

		CString csStrsql=_T("select  *  from bookdata");
		Isqlnum=SqlServer->GetSelData(csStrsql,csTrlist);
		CloseAdoServer(SqlServer);
		Isqlnum=(double)Isqlnum/(double)6;

		CString std1;
		POSITION rPos;
		rPos = csTrlist.GetHeadPosition();

		for (int i = 0; i < Isqlnum; i++)
		{
			int row = m_lstOutData.GetItemCount();
			m_lstOutData.InsertItem(row ,_T(""));

			for (int j=0;j<6;j++)
			{
				std1=csTrlist.GetNext(rPos);
				m_lstOutData.SetItemText(row,j,std1);	
			}

		}
	}
}

void CMyDbDlg::OnBnClickedButSlete3()
{
	UpdateData();
	if (m_csNum.GetLength()==0 )
	{
		MessageBox(_T("�ֶβ���Ϊ��"),_T("��ʾ"));
		return;
	}

	m_lstOutData.DeleteAllItems();
	int Isqlnum;
	CUIIADORXServer *SqlServer;
	SqlServer=OpenAdoServer(m_sqlName);
	if (SqlServer==NULL)
		return ;
	else
	{

		CStringList csTrlist;
		CString csStrsql;

		csStrsql.Format(_T("select * from bookdata where BookNum='%s'"),m_csNum);
		Isqlnum= SqlServer->GetSelData(csStrsql,csTrlist);
		CloseAdoServer(SqlServer);
		Isqlnum=(double)Isqlnum/(double)6;
		CString csOut;
		POSITION rPos;
		rPos = csTrlist.GetHeadPosition();

		for (int i = 0; i < Isqlnum; i++)
		{
			int row = m_lstOutData.GetItemCount();
			m_lstOutData.InsertItem(row ,_T(""));

			for (int j=0;j<6;j++)
			{
				csOut=csTrlist.GetNext(rPos);
				m_lstOutData.SetItemText(row,j,csOut);	
			}
		}

	}
}

void CMyDbDlg::OnNMClickLstOutdata(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	for(int i=0; i<m_lstOutData.GetItemCount(); i++) 
	{ 
		if( m_lstOutData.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED ) 
		{ 
			m_csSelectBookName=m_lstOutData.GetItemText(i,0);	
			m_csSelectNum=m_lstOutData.GetItemText(i,5);
		} 
	} 
}

HBRUSH CMyDbDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	if (pWnd->GetDlgCtrlID() == IDC_STATIC1)
     {
         
     } return hbr;
	return hbr;
}
#include "LogIn.h"
void CMyDbDlg::OnBnClickedButTj2()
{
	if (m_bLongin == false)
	{
	
	CLogIn LogInDlg;
	INT_PTR ilog;
	ilog = LogInDlg.DoModal();
	if (ilog == IDCANCEL)
	{
		return;
	}
	m_csName =LogInDlg.m_csName;
	if (m_csName.GetLength()==0)
	{
		return;
	}
	int Isqlnum ;
	CUIIADORXServer *SqlServer;
	SqlServer=OpenAdoServer(m_sqlName);
	if (SqlServer==NULL)
		return ;
	else
	{
		CStringArray csTrlist;
		CString csStrsql;

		csStrsql.Format(_T("select * from login where Name='%s'"),m_csName);
		Isqlnum= SqlServer->GetSelData(csStrsql,csTrlist);
		CloseAdoServer(SqlServer);
		m_csSelectName = csTrlist[5];
		GetDlgItem(IDC_BUT_TJ2)->SetWindowText(_T("�˳���¼"));
		m_bLongin =true;
	}
	}else{
		m_csName = _T("");
		m_csSelectName = _T("");
		GetDlgItem(IDC_BUT_TJ2)->SetWindowText(_T("�û���¼"));
		m_bLongin =false;
	}
}

void CMyDbDlg::OnBnClickedButSy2()
{
	if ( m_csName.GetLength()==0)
	{
		MessageBox(_T("��������"),_T("��ʾ"));
		return;
	}

	m_lstOutData.DeleteAllItems();
	CUIIADORXServer *SqlServer;
	SqlServer=OpenAdoServer(m_sqlName);
	if (SqlServer==NULL)
		return ;
	else
	{

		CString csStrsql;
		CStringArray csTrlist;
		csStrsql.Format(_T("select * from bookmessageto where  Name='%s' and Flag='0'"),m_csName);
		int Isqlnum= SqlServer->GetSelData(csStrsql,csTrlist);
		if (Isqlnum <= 0)
		{
			MessageBox(_T("û�м�¼"),_T("��ʾ"));
			return;
		}
		int sum =1;

		for (int i=0;i<Isqlnum;i++)
		{
			CStringList csTrlistTo;
			csStrsql.Format(_T("select * from bookdata where  BookName='%s'"),csTrlist[sum]);

			int IsqlnumTo=SqlServer->GetSelData(csStrsql,csTrlistTo);

			IsqlnumTo=(double)IsqlnumTo/(double)6;

			CString csOut;
			POSITION rPos;
			rPos = csTrlistTo.GetHeadPosition();

			for (int i = 0; i < IsqlnumTo; i++)
			{
				int row = m_lstOutData.GetItemCount();
				m_lstOutData.InsertItem(row ,_T(""));

				for (int j=0;j<6;j++)
				{
					csOut=csTrlistTo.GetNext(rPos);
					m_lstOutData.SetItemText(row,j,csOut);	
				}

			}
			sum+=7;
		}

		CloseAdoServer(SqlServer);
	}
}
