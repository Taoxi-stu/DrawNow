
// DrawNowView.h: CDrawNowView 类的接口
//

#pragma once
#include "CSetting.h"

class CDrawNowView : public CView
{
protected: // 仅从序列化创建
	CDrawNowView() noexcept;
	DECLARE_DYNCREATE(CDrawNowView)

// 特性
public:
	CDrawNowDoc* GetDocument() const;

// 操作
public:
	CPen * m_Pen;
	int m_PenSize;//画笔粗细
	COLORREF m_PenColor, m_BrushColor;//笔刷颜色。填充颜色
	CPoint m_PointBegin, m_PointEnd;//绘图起点，绘图终点
	CPoint m_PointPolyOrigin;
	BOOL m_PolyInitFlag;
	enum class DrawType {
		Point, LineSegment, Circle, Rectangle, Polygen, Ellips, FreeFrom
	}m_DrawType;
	CSetting* m_CDlgSet;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDrawNowView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSetting();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // DrawNowView.cpp 中的调试版本
inline CDrawNowDoc* CDrawNowView::GetDocument() const
   { return reinterpret_cast<CDrawNowDoc*>(m_pDocument); }
#endif

