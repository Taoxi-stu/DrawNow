// CSetting.cpp: 实现文件
//

#include "pch.h"
#include "DrawNow.h"
#include "afxdialogex.h"
#include "CSetting.h"


// CSetting 对话框

IMPLEMENT_DYNAMIC(CSetting, CDialogEx)

CSetting::CSetting(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Setting, pParent)
	, m_DlgStrPenSize(_T(""))
{

}

CSetting::~CSetting()
{
}

void CSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_DlgStrPenSize);

	m_PenSize = _ttoi(m_DlgStrPenSize);
}


BEGIN_MESSAGE_MAP(CSetting, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSetting::OnBnClickedOk)
END_MESSAGE_MAP()


// CSetting 消息处理程序


void CSetting::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	DestroyWindow();
	CDialogEx::OnOK();
	

}
