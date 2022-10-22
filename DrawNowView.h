
// DrawNowView.h: CDrawNowView 类的接口
//

#pragma once


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
};

#ifndef _DEBUG  // DrawNowView.cpp 中的调试版本
inline CDrawNowDoc* CDrawNowView::GetDocument() const
   { return reinterpret_cast<CDrawNowDoc*>(m_pDocument); }
#endif

