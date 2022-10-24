#pragma once
#include "afxdialogex.h"


// CSetting 对话框

class CSetting : public CDialogEx
{
	DECLARE_DYNAMIC(CSetting)

public:
	CSetting(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSetting();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Setting };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_DlgStrPenSize;
	int m_PenSize;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox m_ListDrawType;
	virtual BOOL OnInitDialog();
	CComboBox m_ListPenStyle;
	CMFCColorButton m_ListPenColor;
};
