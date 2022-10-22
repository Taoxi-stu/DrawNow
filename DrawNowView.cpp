
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

#include "Resource.h"
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
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CDrawNowView 构造/析构

CDrawNowView::CDrawNowView() noexcept
{
	// TODO: 在此处添加构造代码

	m_PenSize = 1;
	m_PenColor = RGB(0, 0, 0);
	m_BrushColor = RGB(0, 0, 0);
	m_PointBegin = CPoint(0, 0);
	m_PointEnd = CPoint(0, 0);
	m_DrawType = DrawType::Rectangle;

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


void CDrawNowView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_PointBegin = m_PointEnd = point;
	CClientDC dc(this);
	switch (m_DrawType)  {
	case DrawType::Point :
	case DrawType::LineSegment:
	case DrawType::Rectangle:
		dc.MoveTo(m_PointBegin);
		dc.LineTo(point);
		break;
	}

	CView::OnLButtonDown(nFlags, point);
}


void CDrawNowView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	switch (m_DrawType) {
	case DrawType::Point:
		break;
	case DrawType::LineSegment:
		dc.SetROP2(R2_COPYPEN); // 异或的方式清除上次画笔
		dc.MoveTo(m_PointBegin);
		dc.LineTo(point);
		break;
	case DrawType::Rectangle: {
		dc.SetROP2(R2_COPYPEN); // 异或的方式清除上次画笔
		CRect rectTmp2(m_PointBegin, point);
		dc.Rectangle(rectTmp2);
		break;
	}
	default:
		break;
	}

	CView::OnLButtonUp(nFlags, point);
}


void CDrawNowView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	if (nFlags & MK_LBUTTON) {
		switch (m_DrawType) {
		case DrawType::LineSegment:
			dc.SetROP2(R2_NOTXORPEN); // 异或的方式清除上次画笔
			dc.MoveTo(m_PointBegin);
			dc.LineTo(m_PointEnd);
			// 画本次图形
			dc.MoveTo(m_PointBegin);
			dc.LineTo(point);
			m_PointEnd = point;
			break;
		case DrawType::Rectangle: {
			dc.SetROP2(R2_NOTXORPEN); // 异或的方式清除上次画笔
			dc.MoveTo(m_PointBegin);
			CRect rectTmp1(m_PointBegin, m_PointEnd);
			dc.Rectangle(rectTmp1);
			// 画本次图形
			//dc.SetROP2(R2_COPYPEN);
			CRect rectTmp2(m_PointBegin, point);
			dc.Rectangle(rectTmp2);
			m_PointEnd = point;
			break;
		}
		default:
			break;
		}
	}

	CView::OnMouseMove(nFlags, point);
}
