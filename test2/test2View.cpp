
// test2View.cpp: Ctest2View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "test2.h"
#endif

#include "test2Doc.h"
#include "test2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest2View

IMPLEMENT_DYNCREATE(Ctest2View, CView)

BEGIN_MESSAGE_MAP(Ctest2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Ctest2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_COMMAND(173, &Ctest2View::On173)
	ON_COMMAND(IDR_TOOLBAR1, &Ctest2View::OnIdrToolbar1)
END_MESSAGE_MAP()

// Ctest2View 构造/析构

Ctest2View::Ctest2View() noexcept
{
	// TODO: 在此处添加构造代码
	alpha = 0, beta = 0;
	bplay = false;
	cube.ReadVertex();
	cube.ReadFacet();

	transform.SetMatrix(cube.GetPtArrayName(), 8);
	int nEdge = 500;
	transform.Scale(nEdge);
	transform.Translate(-nEdge / 2, -nEdge / 2, -nEdge / 2);

}

Ctest2View::~Ctest2View()
{
}

BOOL Ctest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctest2View 绘图

void Ctest2View::OnDraw(CDC* pDC)
{
	Ctest2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	DoubleBuffer(pDC);
	// TODO: 在此处为本机数据添加绘制代码
}


// Ctest2View 打印


void Ctest2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Ctest2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Ctest2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Ctest2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void Ctest2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Ctest2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Ctest2View 诊断

#ifdef _DEBUG
void Ctest2View::AssertValid() const
{
	CView::AssertValid();
}

void Ctest2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest2Doc* Ctest2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest2Doc)));
	return (Ctest2Doc*)m_pDocument;
}

void Ctest2View::DoubleBuffer(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	CDC memDC;//声明内存DC
	memDC.CreateCompatibleDC(pDC);//创建一个与显示DC兼容的内存DC
	CBitmap newBitMap, * pOldBitMap;//定义一个位图，保证每一个像素的颜色
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

void Ctest2View::DrawObject(CDC* pDC)
{
	cube.Draw(pDC);
}

#endif //_DEBUG


// Ctest2View 消息处理程序


void Ctest2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	alpha = 5;
	beta = 5;
	transform.RotateX(alpha);
	transform.RotateY(beta);
	Invalidate(FALSE);
	CView::OnTimer(nIDEvent);
}


void Ctest2View::On173()
{
	// TODO: 在此添加命令处理程序代码
	SetTimer(1, 100, nullptr);
}


void Ctest2View::OnIdrToolbar1()
{
	SetTimer(1, 100, nullptr);
	// TODO: 在此添加命令处理程序代码
}
