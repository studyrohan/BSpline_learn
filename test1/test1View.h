﻿
// test1View.h: Ctest1View 类的接口
//

#pragma once
#include "Cbezier.h"
#include "CBrick.h"
#include "CTransform2.h"
#include "CCubicBezierCurve.h"
#include "Ellipse.h"


class Ctest1View : public CView
{
protected: // 仅从序列化创建
	Ctest1View() noexcept;
	DECLARE_DYNCREATE(Ctest1View)

// 特性
public:
	Ctest1Doc* GetDocument() const;

// 操作
public:
	void DoubleBuffer(CDC* pDC);//双缓冲
	void DrawObject(CDC* pDC);



private:
	Cbezier bezier;
	CBrick brick[5];
	CTransform2 transform[5];
	CCubicBezierCurve cubicBezierCurve;

protected:
	CEllipse ellipse;
	CTransform2 transform1;
	bool bPlay;
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
	virtual ~Ctest1View();
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
	afx_msg void OnGraphAnimation();
};

#ifndef _DEBUG  // test1View.cpp 中的调试版本
inline Ctest1Doc* Ctest1View::GetDocument() const
   { return reinterpret_cast<Ctest1Doc*>(m_pDocument); }
#endif

