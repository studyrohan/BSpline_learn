﻿
// test2View.h: Ctest2View 类的接口
//

#pragma once
#include "CCube.h"
#include "CTransform3.h"


class Ctest2View : public CView
{
protected: // 仅从序列化创建
	Ctest2View() noexcept;
	DECLARE_DYNCREATE(Ctest2View)

// 特性
public:
	Ctest2Doc* GetDocument() const;

// 操作
public:
public:
	void DoubleBuffer(CDC* pDC);//双缓冲
	void DrawObject(CDC* pDC);
private:
	CCube cube;
	double alpha;
	double beta;
	bool bplay;
	CTransform3 transform;

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
	virtual ~Ctest2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void On173();
	afx_msg void OnIdrToolbar1();
};

#ifndef _DEBUG  // test2View.cpp 中的调试版本
inline Ctest2Doc* Ctest2View::GetDocument() const
   { return reinterpret_cast<Ctest2Doc*>(m_pDocument); }
#endif

