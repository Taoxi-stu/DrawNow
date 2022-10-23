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
	m_PenSize = 5;

}

CSetting::~CSetting()
{
}

void CSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_DlgStrPenSize);

	DDX_Control(pDX, IDC_COMBO1, m_ListDrawType);
}


BEGIN_MESSAGE_MAP(CSetting, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSetting::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CSetting::OnBnClickedCancel)
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







void CSetting::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CSetting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_ListDrawType.SetCurSel(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
