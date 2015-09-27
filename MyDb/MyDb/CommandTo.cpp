// CommandTo.cpp : 实现文件
//

#include "stdafx.h"
#include "MyDb.h"
#include "CommandTo.h"


// CCommandTo 对话框

IMPLEMENT_DYNAMIC(CCommandTo, CDialog)

CCommandTo::CCommandTo(CWnd* pParent /*=NULL*/)
	: CDialog(CCommandTo::IDD, pParent)
{

}

CCommandTo::~CCommandTo()
{
}

void CCommandTo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Cmmand);
}


BEGIN_MESSAGE_MAP(CCommandTo, CDialog)
	ON_BN_CLICKED(IDOK, &CCommandTo::OnBnClickedOk)
END_MESSAGE_MAP()


// CCommandTo 消息处理程序

void CCommandTo::OnBnClickedOk()
{
	UpdateData();
	OnOK();
}
