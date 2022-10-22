
// DrawNowView.cpp: CDrawNowView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DrawNow.h"
#endif

#include "DrawNowDoc.h"
#include "DrawNowView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawNowView

IMPLEMENT_DYNCREATE(CDrawNowView, CView)

BEGIN_MESSAGE_MAP(CDrawNowView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDrawNowView 构造/析构

CDrawNowView::CDrawNowView() noexcept
{
	// TODO: 在此处添加构造代码

}

CDrawNowView::~CDrawNowView()
{
}

BOOL CDrawNowView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawNowView 绘图

void CDrawNowView::OnDraw(CDC* /*pDC*/)
{
	CDrawNowDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDrawNowView 打印

BOOL CDrawNowView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawNowView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawNowView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDrawNowView 诊断

#ifdef _DEBUG
void CDrawNowView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawNowView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawNowDoc* CDrawNowView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawNowDoc)));
	return (CDrawNowDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawNowView 消息处理程序
