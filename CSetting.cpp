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
	m_DrawType.AddString(_T("123"));

	m_DrawType.AddString(_T("汉字"));

	m_DrawType.AddString(_T("English"));

	m_DrawType.AddString(_T("!@#$%^&*()"));

}

CSetting::~CSetting()
{
}

void CSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_DlgStrPenSize);

	DDX_Control(pDX, IDC_LIST1, m_DrawType);
}


BEGIN_MESSAGE_MAP(CSetting, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSetting::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CSetting::OnBnClickedCancel)
//	ON_EN_CHANGE(IDC_EDIT1, &CSetting::OnEnChangeEdit1)
ON_EN_CHANGE(IDC_EDIT1, &CSetting::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CSetting 消息处理程序


void CSetting::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CDialogEx::OnOK();
	//this->DestroyWindow();
	

}


void CSetting::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}




void CSetting::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
