
// MyDbDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyDb.h"
#include "MyDbDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
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


// CMyDbDlg 对话框




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


// CMyDbDlg 消息处理程序

BOOL CMyDbDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	m_lstOutData.DeleteAllItems();
	m_lstOutData.SetExtendedStyle(	LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_lstOutData.InsertColumn(0,_T("书名"),LVCFMT_LEFT,100);
	m_lstOutData.InsertColumn(1,_T("作者"),LVCFMT_LEFT,100);
	m_lstOutData.InsertColumn(2,_T("出版社"),LVCFMT_LEFT,80);
	m_lstOutData.InsertColumn(3,_T("价格"),LVCFMT_LEFT,50);
	m_lstOutData.InsertColumn(4,_T("编号"),LVCFMT_LEFT,50);
	m_lstOutData.InsertColumn(5,_T("数量"),LVCFMT_LEFT,50);

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
		FIXED_PITCH|FF_MODERN, _T("华文楷体"));
	m_static1.SetFont(&font);
	font.DeleteObject();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMyDbDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMyDbDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMyDbDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}
CUIIADORXServer* CMyDbDlg::OpenAdoServer(LPCTSTR pszDbPathName)
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
		MessageBox(_T("字段不能为空"),_T("提示"));
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
		MessageBox(_T("字段不能为空"),_T("提示"));
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
			MessageBox(_T("参数错误"),_T("提示"));
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
				MessageBox(_T("没有记录"),_T("提示"));
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
		MessageBox(_T("参数错误"),_T("提示"));
		return;
	}

	if (_wtoi(m_csSelectNum) <= 0)
	{
		MessageBox(_T("没有库存"),_T("提示"));
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
			MessageBox(_T("已借书籍"),_T("提示"));
			return;
		}

		csStrsql.Format(_T("insert into bookmessageto ([BookName], [Name], [NameTo], [Flag]) values ('%s','%s','%s','%s')"),m_csSelectBookName,m_csName,m_csSelectName,_T("1"));
		int isql =SqlServer->ExecuteSQL(csStrsql);

		if (isql)
			MessageBox(_T("借阅成功"),_T("提示"));
		else{
			MessageBox(_T("借阅失败"),_T("提示"));
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
		MessageBox(_T("参数错误"),_T("提示"));
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
			MessageBox(_T("没有记录"),_T("提示"));
			return;
		}


		csStrsql.Format(_T("update [bookmessageto]  set [Flag]='%s' where	[BookName]='%s' and Name='%s' "),_T("0"),m_csSelectBookName,m_csName);
		int isql=SqlServer->ExecuteSQL(csStrsql);
		if(isql)
			MessageBox(_T("归还成功"),_T("提示"));
		else
			MessageBox(_T("归还失败"),_T("提示"));

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
		MessageBox(_T("字段不能为空"),_T("提示"));
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
	// TODO: 在此添加控件通知处理程序代码
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

	// TODO:  在此更改 DC 的任何属性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
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
		GetDlgItem(IDC_BUT_TJ2)->SetWindowText(_T("退出登录"));
		m_bLongin =true;
	}
	}else{
		m_csName = _T("");
		m_csSelectName = _T("");
		GetDlgItem(IDC_BUT_TJ2)->SetWindowText(_T("用户登录"));
		m_bLongin =false;
	}
}

void CMyDbDlg::OnBnClickedButSy2()
{
	if ( m_csName.GetLength()==0)
	{
		MessageBox(_T("参数错误"),_T("提示"));
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
			MessageBox(_T("没有记录"),_T("提示"));
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
