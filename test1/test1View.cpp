
// test1View.cpp: Ctest1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "test1.h"
#endif

#include "test1Doc.h"
#include "test1View.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest1View

IMPLEMENT_DYNCREATE(Ctest1View, CView)

BEGIN_MESSAGE_MAP(Ctest1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Ctest1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_COMMAND(ID_GRAPH_ANIMATION, &Ctest1View::OnGraphAnimation)
END_MESSAGE_MAP()

// Ctest1View 构造/析构

Ctest1View::Ctest1View() noexcept
{
	// TODO: 在此处添加构造代码
	CPoint pnt[5];
	pnt[0].x = -400;
	pnt[0].y = -200;
	pnt[1].x = -200;
	pnt[1].y = 100;
	pnt[2].x = 200;
	pnt[2].y = 200;
	pnt[3].x = 300;
	pnt[3].y = -200;
	pnt[4].x = 600;
	pnt[4].y = 150;
	bezier.ReadPoint(pnt, 4);
	for (int i = 0; i < 5; i++)
	{
		brick[i].ReadPoint();
	}
	transform[0].SetMatrix(brick[1].P, 4);
	transform[0].Translate(50, 100);
	transform[1].SetMatrix(brick[2].P, 4);
	transform[1].Translate(50, 100);
	transform[1].Rotate(90);

	transform[2].SetMatrix(brick[3].P, 4);
	transform[2].Rotate(45);

	transform[3].SetMatrix(brick[4].P, 4);
	transform[3].Scale(0.5, 0.25);


	
	{
		CP2 pnt[4];
		pnt[0].x = -400;
		pnt[0].y = -200;
		pnt[1].x = -200;
		pnt[1].y = 100;
		pnt[2].x = 200;
		pnt[2].y = 200;
		pnt[3].x = 300;
		pnt[3].y = -200;
		cubicBezierCurve.ReadPoint(pnt);
	}

	{
		bPlay = false;
		
		ellipse.ReadPoint();
		transform1.SetMatrix(ellipse.p, 12);
		int a = 200, b = 100;
		transform1.Scale(a, b);
	}
}

Ctest1View::~Ctest1View()
{
}

BOOL Ctest1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctest1View 绘图
void Ctest1View::OnDraw(CDC* pDC)
{
	Ctest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	//bezier.Draw(pDC);
	//bezier.DrawControlPolygon(pDC);

	for (int i = 0; i < 5; i++)
	{
		brick[i].Draw(pDC);
	}
	double a{ 1 }, b{ 0 };
	double* c;
	CString str = CString ("size of double *:") + CString(std::to_string(sizeof(c)).c_str());
	pDC->TextOut(50, 42, str);

	cubicBezierCurve.Draw(pDC);
	cubicBezierCurve.DrawControlPolygon(pDC);

	DoubleBuffer(pDC);
}


// Ctest1View 打印


void Ctest1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Ctest1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Ctest1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Ctest1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void Ctest1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Ctest1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Ctest1View 诊断

#ifdef _DEBUG
void Ctest1View::AssertValid() const
{
	CView::AssertValid();
}

void Ctest1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest1Doc* Ctest1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest1Doc)));
	return (Ctest1Doc*)m_pDocument;
}

void Ctest1View::DoubleBuffer(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	CDC memDC;//声明内存DC
	memDC.CreateCompatibleDC(pDC);//创建一个与显示DC兼容的内存DC
	CBitmap newBitMap, *pOldBitMap;//定义一个位图，保证每一个像素的颜色
	newBitMap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());//创建兼容内存位图，黑色的
	pOldBitMap = memDC.SelectObject(&newBitMap);//将兼容位图选入内存区
	memDC.FillSolidRect(rect, pDC->GetBkColor());//设置客户区背景色
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);

	memDC.SetMapMode(MM_ANISOTROPIC);
	memDC.SetWindowExt(rect.Width(), rect.Height());
	memDC.SetViewportExt(rect.Width(), -rect.Height());
	memDC.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	DrawObject(&memDC);//向内存缓冲区中绘制图形
	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, -rect.Width() / 2, -rect.Height() / 2, SRCCOPY);
	memDC.SelectObject(pOldBitMap);
	newBitMap.DeleteObject();
	memDC.DeleteDC();
}

void Ctest1View::DrawObject(CDC* pDC)
{
	pDC->MoveTo(-10, 0);
	pDC->LineTo(10, 0);
	pDC->MoveTo(0, -10);
	pDC->LineTo(0, 10);
	ellipse.Draw(pDC);
}

#endif //_DEBUG


// Ctest1View 消息处理程序


void Ctest1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	double beta = 5;
	transform1.Rotate(beta);
	Invalidate(FALSE);//重新刷新客户区
	CView::OnTimer(nIDEvent);
}


void Ctest1View::OnGraphAnimation()
{
	// TODO: 在此添加命令处理程序代码
	bPlay = !bPlay;
	if (bPlay)
	{
		SetTimer(1, 100, NULL);//100毫秒调用一次
	}
	else
	{
		KillTimer(1);
	}
}
